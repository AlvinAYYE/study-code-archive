/*
 * Title-CN: 最大二元樹
 * LeetCode 654. Maximum Binary Tree
 *
 * 題意翻譯：給定一個沒有重複值的整數陣列，依規則建立二元樹：區間最大值成為
 * 根節點，最大值左側子陣列建立左子樹，右側子陣列建立右子樹。回傳樹根。
 *
 * 範例：[3,2,1,6,0,5] 的最大值 6 是根；左側 [3,2,1] 建成左子樹，右側 [0,5]
 * 建成右子樹。
 *
 * 限制：陣列長度為 1 到 1000；數值互不相同，介於 0 到 1000。
 *
 * 解題思路：對目前子陣列找最大值，把它建成根；再對最大值左右兩邊遞迴做相同事。
 * 區間為空時回傳 NULL。
 *
 * 複雜度：每層掃描目前區間找最大值；平均 O(n log n)，最壞 O(n^2)；
 * 遞迴堆疊 O(n)。
 * LeetCode 介面：保留 constructMaximumBinaryTree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *build(int *nums, int left, int right) {
    if (left >= right) return NULL;
    int maximumIndex = left;
    for (int i = left + 1; i < right; ++i) {
        if (nums[i] > nums[maximumIndex]) maximumIndex = i;
    }

    struct TreeNode *root = malloc(sizeof(*root));
    if (root == NULL) return NULL;
    root->val = nums[maximumIndex];
    root->left = build(nums, left, maximumIndex);
    root->right = build(nums, maximumIndex + 1, right);
    return root;
}

struct TreeNode *constructMaximumBinaryTree(int *nums, int numsSize) {
    return build(nums, 0, numsSize);
}

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    int nums[] = {3, 2, 1, 6, 0, 5};
    struct TreeNode *root = constructMaximumBinaryTree(nums, 6);
    assert(root != NULL && root->val == 6);
    assert(root->left->val == 3 && root->left->right->val == 2);
    assert(root->left->right->right->val == 1);
    assert(root->right->val == 5 && root->right->left->val == 0);
    freeTree(root);
    return 0;
}
