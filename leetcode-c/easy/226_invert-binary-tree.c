/*
 * LeetCode 226. Invert Binary Tree
 * Title-CN: 翻轉二元樹
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/invert-binary-tree/
 *
 * [題目翻譯]
 * 給定一棵二元樹的根節點，將每個節點的左右子樹互換，並回傳根節點。
 *
 * [範例]
 * 輸入 [4,2,7,1,3,6,9]，輸出 [4,7,2,9,6,3,1]。
 * 輸入 [2,1,3]，輸出 [2,3,1]；空樹輸出空樹。
 *
 * [限制]
 * 節點數量為 0 到 100；-100 <= Node.val <= 100。
 *
 * [解題思路]
 * 每個節點只要交換 left 與 right，再對交換後的兩棵子樹做相同工作。
 * 遞迴遇到空節點就停止。每個節點只處理一次，所以時間 O(n)，
 * 遞迴堆疊最多 O(h)，h 是樹高。
 */
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* ---------- LeetCode submission / 提交區 ---------- */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    /* 先交換當前節點的左右孩子，再遞迴翻轉兩邊。 */
    struct TreeNode* temporary = root->left;
    root->left = root->right;
    root->right = temporary;

    invertTree(root->left);
    invertTree(root->right);
    return root;
}
/* ---------- end submission ---------- */

int main(void) {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n2 = {2, &n1, &n3};
    struct TreeNode n6 = {6, NULL, NULL};
    struct TreeNode n9 = {9, NULL, NULL};
    struct TreeNode n7 = {7, &n6, &n9};
    struct TreeNode root = {4, &n2, &n7};

    struct TreeNode* result = invertTree(&root);
    int ok = result == &root && root.left == &n7 && root.right == &n2 &&
             n7.left == &n9 && n7.right == &n6 && n2.left == &n3 && n2.right == &n1 &&
             invertTree(NULL) == NULL;
    printf("%s: 226 invert-binary-tree\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
