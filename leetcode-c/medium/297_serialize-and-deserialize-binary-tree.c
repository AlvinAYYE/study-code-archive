/*
 * LeetCode 297. Serialize and Deserialize Binary Tree／二元樹序列化與反序列化
 *
 * 題目（繁體中文）
 *   設計兩個函式：serialize 把二元樹轉成字串，deserialize 再從字串還原出
 *   相同的樹。只要兩個函式能互相還原即可，字串格式可以自行設計。
 *
 * 範例 1：root=[1,2,3,null,null,4,5]，序列化再還原後仍是同一棵樹。
 * 範例 2：root=[]，序列化為空樹標記，再反序列化得到 NULL。
 * 本解法使用前序字串，例如 `1,2,#,#,3,4,#,#,5,#,#,`；`#` 表示空子樹。
 * 限制：節點數 0..10^4；-1000 <= Node.val <= 1000。
 *
 * 解題步驟：
 *   1. 序列化時依「根、左、右」順序走訪；空指標也輸出 `#`，因此左右子樹
 *      的邊界資訊不會遺失。用動態字串緩衝區逐一加入數字或空標記。
 *   2. 反序列化時依序讀取 token。第一個 token 是根，接著每個非空節點依序
 *      取得左、右子節點 token；遇到 `#` 就保留 NULL。
 *   3. 反序列化使用佇列逐層接上節點，避免樹很斜時遞迴過深。
 *   兩個函式各處理每個節點與空指標一次，時間 O(n)，額外空間 O(n)，
 *   不含序列化字串及還原樹本身所需的輸出空間。
 *
 * LeetCode C API：char* serialize(struct TreeNode* root)；
 * struct TreeNode* deserialize(char* data)。回傳字串與節點由呼叫端持有。
 * 下方 TreeNode 定義與 main 僅供本機測試。
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

static int pushNode(struct TreeNode ***stack, size_t *size, size_t *capacity,
                    struct TreeNode *node) {
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

static int pushSlot(struct TreeNode ***slots, size_t *size, size_t *capacity,
                    struct TreeNode **slot) {
    if (*size == *capacity) {
        size_t newCapacity = *capacity == 0 ? 16 : *capacity * 2;
        if (newCapacity < *capacity || newCapacity > SIZE_MAX / sizeof **slots)
            return 0;
        struct TreeNode ***grown = (struct TreeNode ***)realloc(
            *slots, newCapacity * sizeof **slots);
        if (grown == NULL) return 0;
        *slots = grown;
        *capacity = newCapacity;
    }
    (*slots)[(*size)++] = slot;
    return 1;
}

/* ---------- LeetCode submission / 提交區 ---------- */
char *serialize(struct TreeNode *root) {
    StringBuilder builder = {NULL, 0, 0};
    struct TreeNode **stack = NULL;
    size_t stackSize = 0, stackCapacity = 0;
    if (!pushNode(&stack, &stackSize, &stackCapacity, root)) return NULL;

    int success = 1;
    while (stackSize > 0 && success) {
        struct TreeNode *node = stack[--stackSize];
        if (node == NULL) {
            success = appendText(&builder, "#", 1) &&
                      appendText(&builder, ",", 1);
            continue;
        }

        char number[32];
        int length = snprintf(number, sizeof number, "%d,", node->val);
        if (length < 0 || (size_t)length >= sizeof number ||
            !appendText(&builder, number, (size_t)length)) {
            success = 0;
            break;
        }
        /* 先壓右子樹，再壓左子樹，堆疊取出時才會是根、左、右。 */
        success = pushNode(&stack, &stackSize, &stackCapacity, node->right) &&
                  pushNode(&stack, &stackSize, &stackCapacity, node->left);
    }
    free(stack);
    if (!success) {
        free(builder.data);
        return NULL;
    }
    return builder.data;
}

static int readToken(const char **cursor, int *isNull, int *value) {
    const char *position = *cursor;
    if (*position == '\0') return 0;
    if (*position == '#') {
        *isNull = 1;
        ++position;
    } else {
        char *end = NULL;
        long parsed = strtol(position, &end, 10);
        if (end == position || parsed < -1000 || parsed > 1000) return 0;
        *isNull = 0;
        *value = (int)parsed;
        position = end;
    }
    if (*position == ',') ++position;
    else if (*position != '\0') return 0;
    *cursor = position;
    return 1;
}

static struct TreeNode *newTreeNode(int value) {
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof *node);
    if (node == NULL) return NULL;
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* ---------- LeetCode submission / 提交區 ---------- */
struct TreeNode *deserialize(char *data) {
    if (data == NULL || *data == '\0') return NULL;
    const char *cursor = data;
    struct TreeNode *root = NULL;
    struct TreeNode ***slots = NULL;
    struct TreeNode **allocated = NULL;
    size_t slotSize = 0, slotCapacity = 0;
    size_t allocatedSize = 0, allocatedCapacity = 0;
    int valid = pushSlot(&slots, &slotSize, &slotCapacity, &root);

    while (slotSize > 0 && valid) {
        struct TreeNode **slot = slots[--slotSize];
        int isNull, value;
        if (!readToken(&cursor, &isNull, &value)) {
            valid = 0;
            break;
        }
        if (isNull) {
            *slot = NULL;
            continue;
        }

        /* 先確保兩個陣列有空間，再建立節點，失敗時能完整回收。 */
        if (slotSize > SIZE_MAX - 2 || slotSize + 2 > slotCapacity) {
            size_t newCapacity = slotCapacity == 0 ? 16 : slotCapacity;
            while (newCapacity < slotSize + 2) {
                if (newCapacity > SIZE_MAX / 2 / sizeof *slots) {
                    valid = 0;
                    break;
                }
                newCapacity *= 2;
            }
            if (!valid || newCapacity > SIZE_MAX / sizeof *slots) {
                valid = 0;
                break;
            }
            struct TreeNode ***grown = (struct TreeNode ***)realloc(
                slots, newCapacity * sizeof *slots);
            if (grown == NULL) {
                valid = 0;
                break;
            }
            slots = grown;
            slotCapacity = newCapacity;
        }
        if (allocatedSize == allocatedCapacity) {
            size_t newCapacity = allocatedCapacity == 0 ? 16 : allocatedCapacity * 2;
            if (newCapacity < allocatedCapacity ||
                newCapacity > SIZE_MAX / sizeof *allocated) {
                valid = 0;
                break;
            }
            struct TreeNode **grown = (struct TreeNode **)realloc(
                allocated, newCapacity * sizeof *allocated);
            if (grown == NULL) {
                valid = 0;
                break;
            }
            allocated = grown;
            allocatedCapacity = newCapacity;
        }

        struct TreeNode *node = newTreeNode(value);
        if (node == NULL) {
            valid = 0;
            break;
        }
        *slot = node;
        allocated[allocatedSize++] = node;
        slots[slotSize++] = &node->right;
        slots[slotSize++] = &node->left;
    }
    if (*cursor != '\0') valid = 0;

    free(slots);
    if (!valid) {
        /* 記錄表包含每個建立過的節點，失敗時可逐一釋放而不遞迴。 */
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

static int treesEqual(const struct TreeNode *first, const struct TreeNode *second) {
    if (first == NULL || second == NULL) return first == second;
    return first->val == second->val &&
           treesEqual(first->left, second->left) &&
           treesEqual(first->right, second->right);
}

int main(void) {
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n5 = {5, NULL, NULL};
    struct TreeNode n2 = {2, NULL, NULL};
    struct TreeNode n3 = {3, &n4, &n5};
    struct TreeNode root = {1, &n2, &n3};

    char *data = serialize(&root);
    struct TreeNode *copy = deserialize(data);
    char *again = serialize(copy);
    int passed = data != NULL && copy != NULL && again != NULL &&
                 strcmp(data, "1,2,#,#,3,4,#,#,5,#,#,") == 0 &&
                 strcmp(data, again) == 0 && treesEqual(&root, copy);
    free(data);
    free(again);
    freeTree(copy);

    data = serialize(NULL);
    copy = deserialize(data);
    passed = passed && data != NULL && strcmp(data, "#,") == 0 && copy == NULL;
    free(data);

    puts(passed ? "PASS: 297 serialize-deserialize-binary-tree"
                : "FAIL: 297 serialize-deserialize-binary-tree");
    return passed ? 0 : 1;
}
