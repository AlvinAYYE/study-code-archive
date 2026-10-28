/*
 * Title-CN: 把二元搜尋樹轉換成累加樹
 * LeetCode 538. Convert BST to Greater Tree
 *
 * 題意翻譯：給定一棵二元搜尋樹，把每個節點的值改成「原樹中大於或等於
 * 該值的所有節點值總和」，並回傳修改後的根節點。
 *
 * 範例：root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]，
 * 回傳 [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]。
 * 說明：從大到小累加：8、7+8=15、6+15=21……，每個節點都加上之前看過的值。
 *
 * 限制：樹中節點數為 0 到 10000；節點值為 -10000 到 10000；所有節點值唯一。
 *
 * 解題思路：二元搜尋樹的反向中序走訪（右、根、左）會依值由大到小拜訪。
 * 維護累加總和，每到一個節點就把它的原值加進總和，再用總和取代節點值。
 *
 * 複雜度：時間 O(n)，每個節點拜訪一次；遞迴堆疊 O(h)，h 為樹高。
 * LeetCode 介面：保留 convertBST；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void convertReverseInorder(struct TreeNode *node, int *sum) {
    if (node == NULL) return;
    convertReverseInorder(node->right, sum);
    *sum += node->val;
    node->val = *sum;
    convertReverseInorder(node->left, sum);
}

struct TreeNode *convertBST(struct TreeNode *root) {
    int sum = 0;
    convertReverseInorder(root, &sum);
    return root;
}

static struct TreeNode *newNode(int value) {
    struct TreeNode *node = malloc(sizeof(*node));
    assert(node != NULL);
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main(void) {
    struct TreeNode *root = newNode(4);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(0);
    root->left->right = newNode(2);
    root->left->right->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

    convertBST(root);
    assert(root->val == 30);
    assert(root->left->val == 36 && root->left->left->val == 36);
    assert(root->left->right->val == 35 && root->left->right->right->val == 33);
    assert(root->right->val == 21 && root->right->left->val == 26);
    assert(root->right->right->val == 15 && root->right->right->right->val == 8);

    free(root->left->left);
    free(root->left->right->right);
    free(root->left->right);
    free(root->left);
    free(root->right->left);
    free(root->right->right->right);
    free(root->right->right);
    free(root->right);
    free(root);
    assert(convertBST(NULL) == NULL);
    return 0;
}
