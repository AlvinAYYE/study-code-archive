/*
 * Title-CN: 修剪二元搜尋樹
 * LeetCode 669. Trim a Binary Search Tree
 *
 * 題意翻譯：給定二元搜尋樹的根節點以及範圍 [low, high]，移除所有值不在範圍內
 * 的節點，並回傳修剪後的根。修剪後仍須保持二元搜尋樹性質。
 *
 * 範例：root = [3,0,4,null,2,null,null,1]、low = 1、high = 3，回傳
 * [3,2,null,1]。
 *
 * 限制：節點數為 1 到 10^4；節點值介於 0 到 10^4；low <= high。
 *
 * 解題思路：利用 BST 的大小順序跳過整棵不可能符合的子樹。若根值小於 low，
 * 根和左子樹都太小，只需修剪右子樹；若根值大於 high，根和右子樹都太大，
 * 只需修剪左子樹。根值在範圍內時，分別修剪左右子樹並保留根。
 *
 * 複雜度：時間 O(n)，最壞拜訪每個節點；遞迴空間 O(h)，h 為樹高。
 * LeetCode 介面：保留 trimBST；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *trimBST(struct TreeNode *root, int low, int high) {
    if (root == NULL) return NULL;
    if (root->val < low) return trimBST(root->right, low, high);
    if (root->val > high) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
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
    struct TreeNode *root = newNode(3);
    root->left = newNode(0);
    root->right = newNode(4);
    root->left->right = newNode(2);
    root->left->right->left = newNode(1);
    struct TreeNode *removedLeft = root->left;
    struct TreeNode *removedRight = root->right;

    root = trimBST(root, 1, 3);
    assert(root->val == 3 && root->left->val == 2);
    assert(root->left->left->val == 1 && root->right == NULL);
    free(removedLeft);  /* 其右子樹已接回答案，不可連同子樹一起釋放。 */
    free(removedRight);
    freeTree(root);
    assert(trimBST(NULL, 0, 1) == NULL);
    return 0;
}
