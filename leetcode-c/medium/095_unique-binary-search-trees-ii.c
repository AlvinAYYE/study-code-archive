/*
 * LeetCode 95. Unique Binary Search Trees II／不同的二元搜尋樹 II
 * 題目（繁體中文）
 *   給定 n，使用 1 到 n 各一次，列出所有「結構不同」的二元搜尋樹。
 *   二元搜尋樹的左子樹值較小、右子樹值較大；回傳順序不限。1 ≤ n ≤ 8。
 *
 * 例子
 *   n=1 → 只有根節點 1 的一棵樹。
 *   n=3 → 共 5 棵：根可為 1、2、3；每種根值再配上所有合法左右子樹。
 *
 * 解題思路
 *   1. 對目前值範圍 [left, right]，逐一嘗試每個值 rootValue 當根。
 *   2. 小於根的值只能放左子樹，大於根的值只能放右子樹。
 *   3. 遞迴列出左右兩邊的所有樹，再將每一棵左樹與每一棵右樹配對。
 *   4. 每個配對建立一個新根；複製子樹，確保回傳的不同樹不共用可變節點。
 *   樹的數量是第 n 個 Catalan 數；產生輸出約需 O(Cn×n) 時間與空間。
 *
 * LeetCode 已提供 TreeNode 定義；提交時保留 stdlib.h 與提交區即可。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode { int val; struct TreeNode *left; struct TreeNode *right; };

/* ---------- LeetCode submission / 提交區 ---------- */
static struct TreeNode *copyTree(struct TreeNode *root) {
    if (root == NULL) return NULL;
    struct TreeNode *copy = (struct TreeNode *)malloc(sizeof *copy);
    if (copy == NULL) return NULL;
    copy->val = root->val;
    copy->left = copyTree(root->left);
    copy->right = copyTree(root->right);
    return copy;
}

static void freeTreeList(struct TreeNode **trees, int count) {
    for (int i = 0; i < count; i++) {
        struct TreeNode *stack[32];
        int top = 0;
        if (trees[i] != NULL) stack[top++] = trees[i];
        while (top > 0) {
            struct TreeNode *node = stack[--top];
            if (node->left != NULL) stack[top++] = node->left;
            if (node->right != NULL) stack[top++] = node->right;
            free(node);
        }
    }
}

static struct TreeNode **treesForRange(int left, int right, int *count) {
    struct TreeNode **trees;
    int capacity;
    *count = 0;

    if (left > right) {
        trees = (struct TreeNode **)malloc(sizeof *trees);
        if (trees != NULL) {
            trees[0] = NULL;   /* 空範圍代表一種選擇：空樹 */
            *count = 1;
        }
        return trees;
    }

    capacity = 4;
    trees = (struct TreeNode **)malloc((size_t)capacity * sizeof *trees);
    if (trees == NULL) return NULL;

    for (int rootValue = left; rootValue <= right; rootValue++) {
        int leftCount, rightCount;
        struct TreeNode **leftTrees = treesForRange(left, rootValue - 1, &leftCount);
        struct TreeNode **rightTrees = treesForRange(rootValue + 1, right, &rightCount);
        if (leftTrees == NULL || rightTrees == NULL) {
            free(leftTrees);
            free(rightTrees);
            freeTreeList(trees, *count);
            free(trees);
            return NULL;
        }

        for (int i = 0; i < leftCount; i++) {
            for (int j = 0; j < rightCount; j++) {
                if (*count == capacity) {
                    capacity *= 2;
                    struct TreeNode **grown = (struct TreeNode **)realloc(
                        trees, (size_t)capacity * sizeof *trees);
                    if (grown == NULL) {
                        freeTreeList(leftTrees, leftCount);
                        freeTreeList(rightTrees, rightCount);
                        free(leftTrees);
                        free(rightTrees);
                        freeTreeList(trees, *count);
                        free(trees);
                        return NULL;
                    }
                    trees = grown;
                }
                struct TreeNode *root = (struct TreeNode *)malloc(sizeof *root);
                if (root == NULL) continue;
                root->val = rootValue;
                root->left = copyTree(leftTrees[i]);
                root->right = copyTree(rightTrees[j]);
                trees[(*count)++] = root;
            }
        }

        freeTreeList(leftTrees, leftCount);
        freeTreeList(rightTrees, rightCount);
        free(leftTrees);
        free(rightTrees);
    }
    return trees;
}

struct TreeNode **generateTrees(int n, int *returnSize) {
    return treesForRange(1, n, returnSize);
}
/* ---------- end submission ---------- */

static void serialize(struct TreeNode *root, char *buffer, int *position) {
    if (root == NULL) {
        *position += sprintf(buffer + *position, "#,");
        return;
    }
    *position += sprintf(buffer + *position, "%d,", root->val);
    serialize(root->left, buffer, position);
    serialize(root->right, buffer, position);
}

static int inorderIsOneToN(struct TreeNode *root, int *next, int n) {
    if (root == NULL) return 1;
    if (!inorderIsOneToN(root->left, next, n)) return 0;
    if (root->val != (*next)++) return 0;
    return inorderIsOneToN(root->right, next, n);
}

static void releaseTree(struct TreeNode *root) {
    if (root == NULL) return;
    releaseTree(root->left);
    releaseTree(root->right);
    free(root);
}

int main(void) {
    int count = 0;
    struct TreeNode **trees = generateTrees(3, &count);
    char signatures[5][64];
    if (trees == NULL || count != 5) {
        puts("FAIL: 095 expected five trees");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        int next = 1, position = 0;
        if (!inorderIsOneToN(trees[i], &next, 3) || next != 4) {
            puts("FAIL: 095 invalid search tree");
            return 1;
        }
        serialize(trees[i], signatures[i], &position);
        for (int j = 0; j < i; j++) {
            if (strcmp(signatures[i], signatures[j]) == 0) {
                puts("FAIL: 095 duplicate structure");
                return 1;
            }
        }
    }
    for (int i = 0; i < count; i++) releaseTree(trees[i]);
    free(trees);
    puts("PASS: 095 unique-binary-search-trees-ii");
    return 0;
}
