/*
 * LeetCode 0897. Increasing Order Search Tree《遞增順序搜尋樹》
 * 難度：Easy；標籤：樹、深度優先搜尋、二元搜尋樹、中序走訪
 * 題目連結：https://leetcode.com/problems/increasing-order-search-tree/
 *
 * 題目說明：
 * 給定一棵二元搜尋樹，依中序順序重新接回原本的節點，使最左邊的節點成為新根，
 * 每個節點都沒有左子節點，而且只用右子指標連到下一個節點。回傳新樹根節點。
 *
 * 範例：
 * 1. root = [5,3,6,2,4,null,8,1,null,null,null,7,9]，重接後的值依序為
 *    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9，所有左子節點皆為空。
 * 2. root = [5,1,7]，重接後為 1 -> 5 -> 7。
 *
 * 限制：節點數介於 1 到 100；0 <= Node.val <= 1000。
 *
 * 解題思路：
 * 1. 二元搜尋樹的中序走訪會依遞增順序取出節點。
 * 2. 遞迴先走訪左子樹，將目前節點的 left 清空，並把它接到目前結果鏈的尾端。
 * 3. 再走訪右子樹。用 dummy 假節點簡化接鏈，最後回傳 dummy->right。
 * 4. 只重新使用原節點，不建立新的樹節點。
 *
 * 複雜度：時間 O(n)，每個節點走訪一次；遞迴堆疊額外使用 O(h)，h 為樹高。
 */
#include <assert.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static void appendInorder(struct TreeNode *node, struct TreeNode **tail) {
    struct TreeNode *left;
    struct TreeNode *right;

    if (!node) return;
    left = node->left;
    right = node->right;

    appendInorder(left, tail);
    node->left = NULL;
    (*tail)->right = node;
    *tail = node;
    appendInorder(right, tail);
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    struct TreeNode dummy = {0, NULL, NULL};
    struct TreeNode *tail = &dummy;

    appendInorder(root, &tail);
    tail->right = NULL;
    return dummy.right;
}

static void checkChain(struct TreeNode *root, const int *values, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        assert(root != NULL);
        assert(root->val == values[i]);
        assert(root->left == NULL);
        root = root->right;
    }
    assert(root == NULL);
}

int main(void) {
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n2 = {2, &n1, NULL};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n3 = {3, &n2, &n4};
    struct TreeNode n7 = {7, NULL, NULL};
    struct TreeNode n9 = {9, NULL, NULL};
    struct TreeNode n8 = {8, &n7, &n9};
    struct TreeNode n6 = {6, NULL, &n8};
    struct TreeNode root = {5, &n3, &n6};
    const int expected1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    checkChain(increasingBST(&root), expected1, 9);

    {
        struct TreeNode one = {1, NULL, NULL};
        struct TreeNode seven = {7, NULL, NULL};
        struct TreeNode smallRoot = {5, &one, &seven};
        const int expected2[] = {1, 5, 7};
        checkChain(increasingBST(&smallRoot), expected2, 3);
    }

    puts("PASS 0897 increasingBST");
    return 0;
}
