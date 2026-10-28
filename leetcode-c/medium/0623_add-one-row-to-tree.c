/*
 * Title-CN: 在二元樹中增加一列
 * LeetCode 623. Add One Row to Tree
 *
 * 題意翻譯：給定二元樹根節點、整數 val 和深度 depth，請在指定深度新增一整列
 * 值為 val 的節點。原本 depth-1 層的左子樹接到新左節點的左邊；原本右子樹接到
 * 新右節點的右邊。若 depth 為 1，則新增節點成為新根。
 *
 * 範例：在根節點 4 的下一層新增值 1，原本的左右子樹分別掛到新節點內側對應的子樹。
 *
 * 限制：節點數為 1 到 10^4；節點值介於 -10^5 到 10^5；1 <= depth <= 樹高+1。
 *
 * 解題思路：若 depth=1，就建立新根並把舊根接到左子樹。否則遞迴往下找
 * depth-1 層；到達該層時建立兩個新節點，將舊左子樹接到新左節點左側、
 * 舊右子樹接到新右節點右側。
 *
 * 複雜度：時間 O(n)，最壞拜訪整棵樹；遞迴堆疊 O(h)，h 為樹高。
 * LeetCode 介面：保留 addOneRow；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static struct TreeNode *newNode(int value) {
    struct TreeNode *node = malloc(sizeof(*node));
    if (node == NULL) return NULL;
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode *addOneRow(struct TreeNode *root, int val, int depth) {
    if (depth == 1) {
        struct TreeNode *newRoot = newNode(val);
        if (newRoot != NULL) newRoot->left = root;
        return newRoot;
    }
    if (root == NULL) return NULL;
    if (depth == 2) {
        struct TreeNode *left = newNode(val);
        struct TreeNode *right = newNode(val);
        if (left == NULL || right == NULL) {
            free(left);
            free(right);
            return root;
        }
        left->left = root->left;
        right->right = root->right;
        root->left = left;
        root->right = right;
        return root;
    }
    root->left = addOneRow(root->left, val, depth - 1);
    root->right = addOneRow(root->right, val, depth - 1);
    return root;
}

static struct TreeNode *makeNode(int value) {
    struct TreeNode *node = newNode(value);
    assert(node != NULL);
    return node;
}

static void freeTree(struct TreeNode *root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void) {
    struct TreeNode *root = makeNode(4);
    root->left = makeNode(2);
    root->right = makeNode(6);
    root->left->left = makeNode(3);
    root->left->right = makeNode(1);
    root->right->left = makeNode(5);
    root = addOneRow(root, 1, 2);
    assert(root->val == 4 && root->left->val == 1 && root->right->val == 1);
    assert(root->left->left->val == 2 && root->left->right == NULL);
    assert(root->right->left == NULL && root->right->right->val == 6);
    assert(root->left->left->left->val == 3 && root->left->left->right->val == 1);
    assert(root->right->right->left->val == 5);
    freeTree(root);

    struct TreeNode *oldRoot = makeNode(9);
    root = addOneRow(oldRoot, 5, 1);
    assert(root->val == 5 && root->left == oldRoot && root->right == NULL);
    freeTree(root);
    return 0;
}
