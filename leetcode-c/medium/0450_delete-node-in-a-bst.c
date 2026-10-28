/*
 * Title-CN: 刪除二元搜尋樹中的節點
 * LeetCode 450. Delete Node in a BST
 *
 * 題目翻譯：給定二元搜尋樹 root 和一個 key，刪除值等於 key 的節點，並回傳刪除後的樹根。
 * 二元搜尋樹的規則是左子樹值較小、右子樹值較大。
 *
 * 例子：root = [5,3,6,2,4,null,7]、key = 3，結果可表示為 [5,4,6,2,null,null,7]。
 *
 * 限制：樹最多 10000 個節點，節點值不重複，輸入本身是有效的二元搜尋樹。
 *
 * 解題步驟：
 *   1. 依 BST 規則比較 key 與目前節點，往左或往右遞迴找目標。
 *   2. 目標沒有左子樹或沒有右子樹時，用存在的那一邊取代目標。
 *   3. 若左右子樹都存在，找右子樹中最小的節點（中序後繼）來取代目標值，
 *      再從右子樹刪掉那個後繼節點，維持 BST 順序。
 *
 * 複雜度：走訪樹高 h 個節點，時間 O(h)，遞迴空間 O(h)；平衡時 h=O(log n)，最壞 O(n)。
 *
 * LeetCode 提交區：保留 TreeNode 定義與 deleteNode 函式；main() 僅供本機測試。
 */

#include <assert.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *deleteNode(struct TreeNode *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else if (root->left == NULL) {
        return root->right;
    } else if (root->right == NULL) {
        return root->left;
    } else {
        struct TreeNode *successor = root->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }
        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val);
    }
    return root;
}

int main(void) {
    struct TreeNode nodes[6] = {0};
    nodes[0] = (struct TreeNode){5, &nodes[1], &nodes[2]};
    nodes[1] = (struct TreeNode){3, &nodes[3], &nodes[4]};
    nodes[2] = (struct TreeNode){6, NULL, &nodes[5]};
    nodes[3] = (struct TreeNode){2, NULL, NULL};
    nodes[4] = (struct TreeNode){4, NULL, NULL};
    nodes[5] = (struct TreeNode){7, NULL, NULL};

    struct TreeNode *root = deleteNode(&nodes[0], 3);
    assert(root == &nodes[0]);
    assert(root->left->val == 4);
    assert(root->left->left == &nodes[3]);
    assert(root->left->right == NULL);
    assert(deleteNode(root, 42) == root);

    root = deleteNode(root, 5);
    assert(root->val == 6);
    assert(root->left->val == 4);
    assert(root->right == &nodes[5]);
    return 0;
}
