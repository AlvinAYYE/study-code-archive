/*
 * LeetCode 114. Flatten Binary Tree to Linked List
 * 繁中題名：將二元樹展平成鏈結串列
 * 題目：將二元樹原地改成一條鏈結串列：使用原本的 TreeNode，沿 right 指標
 *       連接節點，所有 left 指標設為 NULL，節點順序須符合前序走訪。
 *
 * 範例 1：root=[1,2,5,3,4,null,6]，展平後為
 *         [1,null,2,null,3,null,4,null,5,null,6]。
 * 範例 2：root=[]，輸出 []；範例 3：root=[0]，輸出 [0]。
 * 限制：節點數介於 0 到 2000；-100 <= Node.val <= 100。
 *
 * 解題步驟（Morris 式原地接線）：
 *   1. 由目前節點 current 開始；若它沒有左子樹，直接往 right 前進。
 *   2. 若有左子樹，沿左子樹的 right 指標找到最右端節點 predecessor。
 *   3. 把 current 原本的右子樹接到 predecessor 右邊，再把左子樹搬到 right，
 *      並將 left 清空。
 *   4. 往 right 繼續，直到走完整條展平後的鏈結。
 *   每次只改樹內指標，額外空間 O(1)；時間 O(n)。
 *
 * LeetCode 提供 TreeNode 型別；此檔案中的定義與 main 僅供本機測試。
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* ---------- LeetCode submission / 提交區 ---------- */
void flatten(struct TreeNode *root) {
    struct TreeNode *current = root;

    while (current != NULL) {
        if (current->left != NULL) {
            struct TreeNode *predecessor = current->left;

            /* 左子樹最右端接到原右子樹，才不會遺失任何節點。 */
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }
            predecessor->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
/* ---------- end submission ---------- */

static int checkPreorderChain(struct TreeNode *root,
                              const int *expected, int expectedSize) {
    int index = 0;
    while (root != NULL) {
        if (index >= expectedSize || root->val != expected[index] ||
            root->left != NULL) {
            return 0;
        }
        ++index;
        root = root->right;
    }
    return index == expectedSize;
}

int main(void) {
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n4 = {4, NULL, NULL};
    struct TreeNode n2 = {2, &n3, &n4};
    struct TreeNode n6 = {6, NULL, NULL};
    struct TreeNode n5 = {5, NULL, &n6};
    struct TreeNode root = {1, &n2, &n5};
    int expected[] = {1, 2, 3, 4, 5, 6};
    int singleExpected[] = {0};
    struct TreeNode single = {0, NULL, NULL};

    flatten(&root);
    int passed = checkPreorderChain(&root, expected, 6);
    flatten(&single);
    passed = passed && checkPreorderChain(&single, singleExpected, 1);
    flatten(NULL);

    puts(passed ? "PASS: 114 flatten-binary-tree-to-linked-list"
                : "FAIL: 114 flatten-binary-tree-to-linked-list");
    return passed ? 0 : 1;
}
