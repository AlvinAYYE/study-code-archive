/*
 * LeetCode 99. Recover Binary Search Tree／復原二元搜尋樹
 * 題目（繁體中文）
 *   一棵二元搜尋樹中，恰有兩個節點的值被交換。請只交換回這兩個值，
 *   修復樹並保留原有的節點與左右連結。題目保證只有一種答案。
 *
 * 例子
 *       3             2
 *      / \           / \
 *     1   4   →     1   4
 *        /             /
 *       2             3
 *
 * 解題思路
 *   1. 二元搜尋樹做中序走訪時，節點值應由小到大排列。
 *   2. 逐個比較目前節點與前一個節點；若前者較大，就找到一處順序錯亂。
 *   3. 第一次錯亂時，較大的前一節點是第一個錯置值；每次錯亂都更新
 *      較小的目前節點，最後它就是第二個錯置值。
 *   4. 走訪完交換兩值。時間 O(n)，遞迴額外空間 O(h)，h 為樹高。
 *
 * LeetCode 已提供 TreeNode 定義；提交時保留提交區即可。
 */
#include <stdio.h>

struct TreeNode { int val; struct TreeNode *left; struct TreeNode *right; };

/* ---------- LeetCode submission / 提交區 ---------- */
static void findSwappedNodes(struct TreeNode *node, struct TreeNode **previous,
                             struct TreeNode **first, struct TreeNode **second) {
    if (node == NULL) return;
    findSwappedNodes(node->left, previous, first, second);
    if (*previous != NULL && (*previous)->val > node->val) {
        if (*first == NULL) *first = *previous;
        *second = node;
    }
    *previous = node;
    findSwappedNodes(node->right, previous, first, second);
}

void recoverTree(struct TreeNode *root) {
    struct TreeNode *previous = NULL;
    struct TreeNode *first = NULL;
    struct TreeNode *second = NULL;
    findSwappedNodes(root, &previous, &first, &second);
    if (first != NULL && second != NULL) {
        int value = first->val;
        first->val = second->val;
        second->val = value;
    }
}
/* ---------- end submission ---------- */

static int isStrictlyIncreasing(struct TreeNode *node, int *previous, int *hasPrevious) {
    if (node == NULL) return 1;
    if (!isStrictlyIncreasing(node->left, previous, hasPrevious)) return 0;
    if (*hasPrevious && node->val <= *previous) return 0;
    *previous = node->val;
    *hasPrevious = 1;
    return isStrictlyIncreasing(node->right, previous, hasPrevious);
}

int main(void) {
    struct TreeNode node2 = {2, NULL, NULL};
    struct TreeNode node4 = {4, &node2, NULL};
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode root = {3, &node1, &node4};
    int previous = 0, hasPrevious = 0;
    recoverTree(&root);
    if (!isStrictlyIncreasing(&root, &previous, &hasPrevious) ||
        root.val != 2 || node2.val != 3) {
        puts("FAIL: 099 recover-bst");
        return 1;
    }
    puts("PASS: 099 recover-bst");
    return 0;
}
