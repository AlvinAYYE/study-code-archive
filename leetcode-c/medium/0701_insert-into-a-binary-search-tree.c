/*
 * Title-CN: 將數值插入二元搜尋樹
 * LeetCode 701. Insert into a Binary Search Tree
 *
 * 題意翻譯：給定一棵二元搜尋樹的根節點和一個新值，依照 BST 規則插入該值，
 * 並回傳根節點。輸入值不會與樹中既有值重複。
 *
 * 範例：在 [4,2,7,1,3] 插入 5，5 會成為 7 的左子節點。
 *
 * 限制：節點數為 0 到 10^4；節點值介於 0 到 10^8；新值不重複。
 *
 * 解題思路：從根開始比較新值與目前節點。較小就往左，較大就往右；遇到空位置時，
 * 建立新節點並接上。遞迴回傳子樹根，讓每層父節點更新正確的連結。
 *
 * 複雜度：時間 O(h)，額外遞迴空間 O(h)，h 為樹高。
 * LeetCode 介面：保留 insertIntoBST；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insertIntoBST(struct TreeNode *root, int val) {
    if (root == NULL) {
        struct TreeNode *node = malloc(sizeof(*node));
        if (node == NULL) return NULL;
        node->val = val;
        node->left = node->right = NULL;
        return node;
    }
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
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
    struct TreeNode *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root = insertIntoBST(root, 5);
    assert(root->right->left != NULL && root->right->left->val == 5);
    assert(root->val == 4 && root->left->val == 2 && root->right->val == 7);
    freeTree(root);
    return 0;
}
