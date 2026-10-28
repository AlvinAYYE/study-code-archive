/*
 * Title-CN: 二元樹剪枝
 * LeetCode 814. Binary Tree Pruning
 *
 * 題意翻譯：給定一棵只包含 0 和 1 的二元樹。請刪除所有「子樹裡完全沒有 1」的
 * 節點，並回傳剪枝後的樹根。刪除節點後，其餘節點仍維持原本的左右子樹關係。
 *
 * 範例 1：樹 [1,null,0,0,1]，輸出 [1,null,0,null,1]。最底下左側的 0 子樹沒有 1，
 *         所以被刪除；右側的 0 因為還有值為 1 的子節點而保留。
 * 範例 2：樹 [1,0,1,0,0,0,1]，輸出 [1,null,1,null,1]。
 *
 * 限制：節點數量介於 1 到 200；每個節點值只能是 0 或 1。
 *
 * 解題思路：從下往上做後序走訪，先剪好左右子樹，再決定目前節點是否保留。若目前
 * 節點值是 1，保留；若值是 0，但剪完後仍有左或右子樹，代表下面還有 1，也保留；
 * 若值是 0 且左右子樹都為空，整棵子樹都沒有 1，回傳空指標。每個節點只拜訪一次，
 * 時間 O(n)，遞迴空間 O(h)，h 是樹高。
 *
 * LeetCode C 介面：修改並回傳原樹的根；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *prune(struct TreeNode *root) {
    if (root == NULL) return NULL;

    root->left = prune(root->left);
    root->right = prune(root->right);
    if (root->val == 0 && root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    return root;
}

struct TreeNode *pruneTree(struct TreeNode *root) {
    return prune(root);
}

static struct TreeNode *makeNode(int value, struct TreeNode *left,
                                 struct TreeNode *right) {
    struct TreeNode *node = malloc(sizeof(*node));
    assert(node != NULL);
    node->val = value;
    node->left = left;
    node->right = right;
    return node;
}

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *example1 = makeNode(
        1, NULL, makeNode(0, makeNode(0, NULL, NULL), makeNode(1, NULL, NULL)));
    struct TreeNode *result1 = pruneTree(example1);
    assert(result1 == example1);
    assert(result1->val == 1 && result1->left == NULL);
    assert(result1->right->val == 0 && result1->right->left == NULL);
    assert(result1->right->right->val == 1);
    freeTree(result1);

    assert(pruneTree(makeNode(0, makeNode(0, NULL, NULL), NULL)) == NULL);

    {
        struct TreeNode *example3 = makeNode(
            1, makeNode(0, NULL, NULL), makeNode(1, NULL, NULL));
        struct TreeNode *result3 = pruneTree(example3);
        assert(result3->left == NULL);
        assert(result3->right != NULL && result3->right->val == 1);
        freeTree(result3);
    }
    return 0;
}
