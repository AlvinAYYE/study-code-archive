/*
 * Title-CN: 尋找重複子樹
 * LeetCode 652. Find Duplicate Subtrees
 *
 * 題意翻譯：給定一棵二元樹，找出所有出現至少兩次的子樹。兩棵子樹只有在
 * 節點值與左右子樹結構都完全相同時才算重複。每種重複子樹只回傳一個根節點。
 *
 * 範例：樹 [1,2,3,4,null,2,4,null,null,4] 中，值為 2 的子樹與值為 4 的
 * 葉節點各重複一次，因此回傳這兩種子樹的根。
 *
 * 限制：節點數為 1 到 10000；節點值介於 -200 到 200。
 *
 * 解題思路：後序走訪每個節點，先取得左右子樹的唯一編號，再把「節點值、左編號、
 * 右編號」當作此子樹的特徵放進雜湊表。相同特徵代表完全相同的子樹。當某特徵
 * 第 2 次出現時加入答案；第 3 次以後不再重複加入。
 *
 * 複雜度：雜湊平均下時間 O(n)，空間 O(n)。
 * LeetCode 介面：保留 findDuplicateSubtrees；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define TABLE_SIZE 32768

typedef struct {
    int value;
    int leftId;
    int rightId;
    int id;
    int count;
    bool used;
} Entry;

typedef struct {
    Entry table[TABLE_SIZE];
    struct TreeNode **duplicates;
    int duplicateCount;
    int nextId;
} SearchContext;

static uint64_t tupleHash(int value, int leftId, int rightId) {
    uint64_t hash = (uint32_t)value;
    hash = (hash ^ ((uint64_t)(uint32_t)leftId + UINT64_C(0x9e3779b9)
                    + (hash << 6) + (hash >> 2)));
    hash = (hash ^ ((uint64_t)(uint32_t)rightId + UINT64_C(0x9e3779b9)
                    + (hash << 6) + (hash >> 2)));
    return hash;
}

static int internSubtree(SearchContext *context, struct TreeNode *node,
                         int leftId, int rightId) {
    size_t slot = (size_t)tupleHash(node->val, leftId, rightId) & (TABLE_SIZE - 1);
    while (context->table[slot].used) {
        Entry *entry = &context->table[slot];
        if (entry->value == node->val && entry->leftId == leftId
            && entry->rightId == rightId) {
            ++entry->count;
            if (entry->count == 2) context->duplicates[context->duplicateCount++] = node;
            return entry->id;
        }
        slot = (slot + 1) & (TABLE_SIZE - 1);
    }

    Entry *entry = &context->table[slot];
    entry->used = true;
    entry->value = node->val;
    entry->leftId = leftId;
    entry->rightId = rightId;
    entry->id = context->nextId++;
    entry->count = 1;
    return entry->id;
}

static int identify(struct TreeNode *node, SearchContext *context) {
    if (node == NULL) return 0;
    int leftId = identify(node->left, context);
    int rightId = identify(node->right, context);
    return internSubtree(context, node, leftId, rightId);
}

struct TreeNode **findDuplicateSubtrees(struct TreeNode *root, int *returnSize) {
    *returnSize = 0;
    SearchContext *context = calloc(1, sizeof(*context));
    if (context == NULL) return NULL;
    context->duplicates = malloc(10000 * sizeof(*context->duplicates));
    if (context->duplicates == NULL) {
        free(context);
        return NULL;
    }
    context->nextId = 1; /* 0 表示空子樹。 */
    identify(root, context);

    struct TreeNode **answer = context->duplicates;
    *returnSize = context->duplicateCount;
    free(context);
    return answer;
}

static struct TreeNode *newNode(int value) {
    struct TreeNode *node = malloc(sizeof(*node));
    assert(node != NULL);
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->right = newNode(4);
    root->right->left->left = newNode(4);

    int count = 0;
    struct TreeNode **duplicates = findDuplicateSubtrees(root, &count);
    assert(duplicates != NULL && count == 2);
    int foundTwo = 0;
    int foundFour = 0;
    for (int i = 0; i < count; ++i) {
        if (duplicates[i]->val == 2) foundTwo = 1;
        if (duplicates[i]->val == 4) foundFour = 1;
    }
    assert(foundTwo && foundFour);
    free(duplicates);
    freeTree(root);
    return 0;
}
