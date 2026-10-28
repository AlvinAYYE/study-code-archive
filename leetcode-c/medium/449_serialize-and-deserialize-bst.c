/*
 * LeetCode 449. Serialize and Deserialize BST／序列化與反序列化二元搜尋樹
 *
 * 題目（繁體中文）
 *   設計 serialize 與 deserialize，讓二元搜尋樹能轉成字串並從字串還原成
 *   原本的樹。編碼格式可自行決定，並希望字串盡量精簡。
 *
 * 範例 1：root=[2,1,3]，編碼可為 "2,1,3"；解碼後仍是根 2、左子 1、右子 3。
 * 範例 2：root=[]，編碼為空字串，解碼得到 NULL。
 * 限制：節點數 0..10^4；節點值 0..10^4；輸入保證是二元搜尋樹。
 *
 * 解題步驟：
 *   1. 利用 BST 的性質，只輸出前序走訪的節點值，不必另外記錄空子樹標記。
 *   2. 解碼時，前序第一個值是根；用堆疊記錄目前尚可接收右子樹的祖先。
 *   3. 新值小於堆疊頂端時，它是該節點的左子樹；若新值較大，就彈出較小的
 *      祖先，接到最後彈出的祖先右側，再把新節點放入堆疊。
 *   4. 序列化與反序列化都以迭代方式走訪，避免高度達 10^4 的斜樹造成遞迴過深。
 *   時間 O(n)，額外空間 O(n)（走訪堆疊與解碼節點記錄）；編碼字串 O(n)。
 *
 * LeetCode C API：char* serialize(struct TreeNode* root)；
 * struct TreeNode* deserialize(char* data)。回傳字串與樹由呼叫端釋放。
 * 本檔中的 TreeNode 定義與 main 僅供本機測試。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} StringBuilder;

static int appendText(StringBuilder *builder, const char *text, size_t length) {
    if (length > SIZE_MAX - builder->length - 1) return 0;
    size_t needed = builder->length + length + 1;
    if (needed > builder->capacity) {
        size_t newCapacity = builder->capacity == 0 ? 64 : builder->capacity;
        while (newCapacity < needed) {
            if (newCapacity > SIZE_MAX / 2) {
                newCapacity = needed;
                break;
            }
            newCapacity *= 2;
        }
        char *grown = (char *)realloc(builder->data, newCapacity);
        if (grown == NULL) return 0;
        builder->data = grown;
        builder->capacity = newCapacity;
    }
    memcpy(builder->data + builder->length, text, length);
    builder->length += length;
    builder->data[builder->length] = '\0';
    return 1;
}

static int pushTreeNode(struct TreeNode ***stack, size_t *size,
                        size_t *capacity, struct TreeNode *node) {
    if (*size == *capacity) {
        size_t newCapacity = *capacity == 0 ? 16 : *capacity * 2;
        if (newCapacity < *capacity || newCapacity > SIZE_MAX / sizeof **stack)
            return 0;
        struct TreeNode **grown = (struct TreeNode **)realloc(
            *stack, newCapacity * sizeof **stack);
        if (grown == NULL) return 0;
        *stack = grown;
        *capacity = newCapacity;
    }
    (*stack)[(*size)++] = node;
    return 1;
}

/* ---------- LeetCode submission / 提交區 ---------- */
char *serialize(struct TreeNode *root) {
    StringBuilder builder = {NULL, 0, 0};
    if (root == NULL) {
        char *empty = (char *)malloc(1);
        if (empty != NULL) empty[0] = '\0';
        return empty;
    }

    struct TreeNode **stack = NULL;
    size_t stackSize = 0, stackCapacity = 0;
    if (!pushTreeNode(&stack, &stackSize, &stackCapacity, root)) return NULL;
    int success = 1;
    while (stackSize > 0 && success) {
        struct TreeNode *node = stack[--stackSize];
        char token[32];
        int length = snprintf(token, sizeof token, "%d,", node->val);
        if (length < 0 || (size_t)length >= sizeof token ||
            !appendText(&builder, token, (size_t)length)) {
            success = 0;
            break;
        }
        /* 空子樹不需要編碼；LIFO 先處理左子樹，所以先壓入右子樹。 */
        if (node->right != NULL)
            success = pushTreeNode(&stack, &stackSize, &stackCapacity, node->right);
        if (success && node->left != NULL)
            success = pushTreeNode(&stack, &stackSize, &stackCapacity, node->left);
    }
    free(stack);
    if (!success) {
        free(builder.data);
        return NULL;
    }
    /* 最後一個逗號不是必要資料，移除以縮短編碼。 */
    if (builder.length > 0) builder.data[--builder.length] = '\0';
    return builder.data;
}

static struct TreeNode *newTreeNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof *node);
    if (node == NULL) return NULL;
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode *deserialize(char *data) {
    if (data == NULL || *data == '\0') return NULL;
    size_t nodeCount = 1;
    for (const char *p = data; *p != '\0'; ++p) {
        if (*p == ',') ++nodeCount;
    }
    /* 本函式產生的字串沒有尾端逗號；也接受常見的尾端逗號格式。 */
    size_t length = strlen(data);
    if (length > 0 && data[length - 1] == ',') --nodeCount;
    if (nodeCount == 0 || nodeCount > SIZE_MAX / sizeof(struct TreeNode *))
        return NULL;

    struct TreeNode **stack = (struct TreeNode **)malloc(
        nodeCount * sizeof *stack);
    struct TreeNode **allocated = (struct TreeNode **)malloc(
        nodeCount * sizeof *allocated);
    if (stack == NULL || allocated == NULL) {
        free(stack);
        free(allocated);
        return NULL;
    }

    const char *cursor = data;
    size_t stackSize = 0, allocatedSize = 0;
    struct TreeNode *root = NULL;
    int valid = 1;
    for (size_t i = 0; i < nodeCount; ++i) {
        char *end = NULL;
        long parsed = strtol(cursor, &end, 10);
        if (end == cursor || parsed < 0 || parsed > 10000 ||
            (*end != ',' && *end != '\0')) {
            valid = 0;
            break;
        }
        if (*end == ',') {
            cursor = end + 1;
        } else {
            cursor = end;
            if (i + 1 != nodeCount) valid = 0;
        }
        if (!valid) break;

        struct TreeNode *node = newTreeNode((int)parsed);
        if (node == NULL) {
            valid = 0;
            break;
        }
        allocated[allocatedSize++] = node;
        if (i == 0) {
            root = node;
        } else if (node->val < stack[stackSize - 1]->val) {
            stack[stackSize - 1]->left = node;
        } else {
            struct TreeNode *parent = NULL;
            while (stackSize > 0 && node->val > stack[stackSize - 1]->val)
                parent = stack[--stackSize];
            if (parent == NULL) {
                valid = 0;
                break;
            }
            parent->right = node;
        }
        if (stackSize >= nodeCount) {
            valid = 0;
            break;
        }
        stack[stackSize++] = node;
    }
    if (*cursor != '\0') valid = 0;

    free(stack);
    if (!valid) {
        /* 紀錄表含所有已配置節點，錯誤輸入時逐一回收，不依賴樹遞迴。 */
        for (size_t i = 0; i < allocatedSize; ++i) free(allocated[i]);
        free(allocated);
        return NULL;
    }
    free(allocated);
    return root;
}
/* ---------- end submission ---------- */

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

static int sameTree(const struct TreeNode *a, const struct TreeNode *b) {
    if (a == NULL || b == NULL) return a == b;
    return a->val == b->val && sameTree(a->left, b->left) &&
           sameTree(a->right, b->right);
}

int main(void) {
    struct TreeNode left = {1, NULL, NULL};
    struct TreeNode right = {3, NULL, NULL};
    struct TreeNode root = {2, &left, &right};
    char *encoded = serialize(&root);
    struct TreeNode *decoded = deserialize(encoded);
    char *again = serialize(decoded);
    int passed = encoded != NULL && decoded != NULL && again != NULL &&
                 strcmp(encoded, "2,1,3") == 0 && strcmp(encoded, again) == 0 &&
                 sameTree(&root, decoded);
    free(encoded);
    free(again);
    freeTree(decoded);

    encoded = serialize(NULL);
    decoded = deserialize(encoded);
    passed = passed && encoded != NULL && strcmp(encoded, "") == 0 &&
             decoded == NULL;
    free(encoded);

    puts(passed ? "PASS: 449 serialize-deserialize-bst"
                : "FAIL: 449 serialize-deserialize-bst");
    return passed ? 0 : 1;
}
