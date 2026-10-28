/*
 * LeetCode 617. Merge Two Binary Trees
 * Title-CN: 合併二元樹
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/merge-two-binary-trees/
 *
 * [題目翻譯]
 * 給定兩棵二元樹。從兩棵樹的根開始合併：若兩個位置都有節點，
 * 新節點的值是兩者相加；若只有一棵樹有節點，就直接使用那個節點。
 * 回傳合併後的樹根。
 *
 * [範例]
 * root1 = [1,3,2,5]、root2 = [2,1,3,null,4,null,7]，結果為
 * [3,4,5,5,4,null,7]。若 root1=[1]、root2=[1,2]，結果為 [2,2]。
 *
 * [限制]
 * 兩棵樹合計節點數量不超過 2000；-10^4 <= Node.val <= 10^4。
 *
 * [解題思路]
 * 同時看兩棵樹的同一個位置。若其中一邊為空，就回傳另一邊；若兩邊
 * 都有節點，將 root1 的值加上 root2，並遞迴合併左右孩子。這樣可重用
 * 已有節點，不必複製整棵樹。重疊節點數為 k 時，時間 O(k)，遞迴空間 O(h)。
 */
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* ---------- LeetCode submission / 提交區 ---------- */
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL) {
        return root2;
    }
    if (root2 == NULL) {
        return root1;
    }

    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
/* ---------- end submission ---------- */

int main(void) {
    struct TreeNode a5 = {5, NULL, NULL};
    struct TreeNode a3 = {3, &a5, NULL};
    struct TreeNode a2 = {2, NULL, NULL};
    struct TreeNode root1 = {1, &a3, &a2};

    struct TreeNode b4 = {4, NULL, NULL};
    struct TreeNode b1 = {1, NULL, &b4};
    struct TreeNode b7 = {7, NULL, NULL};
    struct TreeNode b3 = {3, NULL, &b7};
    struct TreeNode root2 = {2, &b1, &b3};

    struct TreeNode* result = mergeTrees(&root1, &root2);
    int ok = result == &root1 && root1.val == 3 && root1.left->val == 4 &&
             root1.right->val == 5 && root1.left->right->val == 4 &&
             root1.right->right->val == 7;

    struct TreeNode only = {9, NULL, NULL};
    ok = ok && mergeTrees(NULL, &only) == &only && mergeTrees(&only, NULL) == &only;
    printf("%s: 617 merge-two-binary-trees\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
