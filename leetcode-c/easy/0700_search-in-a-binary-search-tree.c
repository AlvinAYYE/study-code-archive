/*
 * LeetCode 0700. Search in a Binary Search Tree《搜尋二元搜尋樹》
 * 難度：Easy；標籤：樹、二元搜尋樹、二分搜尋
 * 題目連結：https://leetcode.com/problems/search-in-a-binary-search-tree/
 *
 * 題目說明：
 * 給定二元搜尋樹的根節點 root 和整數 val。找到值等於 val 的節點後，回傳
 * 以該節點為根的整個子樹；若找不到則回傳空指標。二元搜尋樹中，左子樹的值
 * 小於目前節點，右子樹的值大於目前節點。
 *
 * 範例：
 * 1. root = [4,2,7,1,3]，val = 2，回傳以 2 為根的子樹 [2,1,3]。
 * 2. root = [4,2,7,1,3]，val = 5，找不到 5，回傳空樹 []。
 *
 * 限制：節點數介於 1 到 5000；1 <= Node.val, val <= 10^7；root 保證是二元搜尋樹。
 *
 * 解題思路：
 * 1. 從根節點開始檢查目前值。
 * 2. 相等時目前節點就是答案，直接回傳它，不必複製子樹。
 * 3. val 較小就只往左找；val 較大就只往右找，因為 BST 的排序性質保證答案
 *    不可能在另一側。
 * 4. 指標走到空節點表示整條可能路徑都找過，回傳 NULL。
 *
 * 複雜度：時間 O(h)，h 為樹高；額外空間 O(1)。
 */
#include <assert.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    while (root && root->val != val) {
        /* BST 左小右大，只需進入可能含有目標的一側。 */
        root = val < root->val ? root->left : root->right;
    }
    return root;
}

int main(void) {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n2 = {2, &n1, &n3};
    struct TreeNode n7 = {7, NULL, NULL};
    struct TreeNode root = {4, &n2, &n7};

    assert(searchBST(&root, 2) == &n2);
    assert(searchBST(&root, 2)->left == &n1);
    assert(searchBST(&root, 2)->right == &n3);
    assert(searchBST(&root, 5) == NULL);

    puts("PASS 0700 searchBST");
    return 0;
}
