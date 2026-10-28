/*
 * LeetCode 235. Lowest Common Ancestor of a Binary Search Tree
 * Title-CN: 二元搜尋樹的最近共同祖先
 *
 * 題意：給定二元搜尋樹 root，以及樹中兩個不同節點 p、q，找出它們的最近共同祖先。
 * 祖先可包含節點自己；最近共同祖先是同時位於 p、q 往上路徑中的最低節點。
 *
 * 範例：
 * 1. root=[6,2,8,0,4,7,9,null,null,3,5]，p=2、q=8，回傳節點 6。
 * 2. 同一棵樹，p=2、q=4，回傳節點 2，因為節點可視為自己的後代。
 * 3. root=[2,1]，p=2、q=1，回傳節點 2。
 *
 * 限制：節點數 2 到 10^5；-10^9 <= Node.val <= 10^9；值皆不同；p、q 不同且都存在於樹中。
 *
 * 解題思路：利用二元搜尋樹左小右大的特性。若 p、q 都小於目前節點，最近共同祖先在左子樹；
 * 若都大於目前節點，就在右子樹。若兩者分居兩側，或其中一個就是目前節點，目前節點即為答案。
 *
 * 複雜度：時間 O(h)，只沿樹高 h 向下走；額外空間 O(1)。
 */
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* LeetCode 提交函式 */
struct TreeNode *lowestCommonAncestor(struct TreeNode *root,
                                      struct TreeNode *p,
                                      struct TreeNode *q) {
    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

int main(void) {
    struct TreeNode n0 = {0, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n5 = {5, NULL, NULL};
    struct TreeNode n4 = {4, &n3, &n5};
    struct TreeNode n2 = {2, &n0, &n4};
    struct TreeNode n7 = {7, NULL, NULL};
    struct TreeNode n9 = {9, NULL, NULL};
    struct TreeNode n8 = {8, &n7, &n9};
    struct TreeNode root = {6, &n2, &n8};

    int passed = lowestCommonAncestor(&root, &n2, &n8) == &root;
    passed = passed && lowestCommonAncestor(&root, &n2, &n4) == &n2;

    puts(passed ? "PASS: 235 lowest-common-ancestor-of-a-binary-search-tree"
                : "FAIL: 235 lowest-common-ancestor-of-a-binary-search-tree");
    return passed ? 0 : 1;
}
