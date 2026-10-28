/*
 * LeetCode 103. Binary Tree Zigzag Level Order Traversal／二元樹之字形層序遍歷
 * 題目（繁體中文）
 *   給定二元樹根節點，逐層回傳節點值；第一層由左到右，第二層由右到左，
 *   之後每層交替方向。空樹回傳空結果。
 *
 * 例子
 *         3
 *        / \
 *       9  20
 *          / \
 *         15  7
 *   回傳 [[3], [20,9], [15,7]]。
 *
 * 解題思路
 *   1. 用佇列做一般的廣度優先搜尋，一次取出同一層的所有節點。
 *   2. 每層仍按左子、右子的順序放入佇列，確保下一層走訪正確。
 *   3. 寫入本層答案時，偶數層從陣列左端填，奇數層從右端填。
 *      走訪每個節點一次，時間 O(n)，佇列與回傳結果共需 O(n) 空間。
 *
 * LeetCode 已提供 TreeNode 定義；提交時保留 stdlib.h 與提交區即可。
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode { int val; struct TreeNode *left; struct TreeNode *right; };

/* ---------- LeetCode submission / 提交區 ---------- */
static int countNodes(struct TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int **zigzagLevelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (root == NULL) return NULL;

    int nodeCount = countNodes(root);
    int **levels = (int **)malloc((size_t)nodeCount * sizeof *levels);
    int *columnSizes = (int *)malloc((size_t)nodeCount * sizeof *columnSizes);
    struct TreeNode **queue = (struct TreeNode **)malloc((size_t)nodeCount * sizeof *queue);
    if (levels == NULL || columnSizes == NULL || queue == NULL) {
        free(levels);
        free(columnSizes);
        free(queue);
        return NULL;
    }

    int head = 0, tail = 0, level = 0;
    queue[tail++] = root;
    while (head < tail) {
        int levelSize = tail - head;
        int *values = (int *)malloc((size_t)levelSize * sizeof *values);
        if (values == NULL) break;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *node = queue[head++];
            int index = (level % 2 == 0) ? i : levelSize - 1 - i;
            values[index] = node->val;
            if (node->left != NULL) queue[tail++] = node->left;
            if (node->right != NULL) queue[tail++] = node->right;
        }
        levels[level] = values;
        columnSizes[level] = levelSize;
        level++;
    }

    free(queue);
    *returnSize = level;
    *returnColumnSizes = columnSizes;
    return levels;
}
/* ---------- end submission ---------- */

int main(void) {
    struct TreeNode left = {9, NULL, NULL};
    struct TreeNode fifteen = {15, NULL, NULL}, seven = {7, NULL, NULL};
    struct TreeNode right = {20, &fifteen, &seven};
    struct TreeNode root = {3, &left, &right};
    int count = 0, *widths = NULL;
    int **actual = zigzagLevelOrder(&root, &count, &widths);
    int ok = actual != NULL && count == 3 && widths[0] == 1 && widths[1] == 2 &&
             widths[2] == 2 && actual[0][0] == 3 && actual[1][0] == 20 &&
             actual[1][1] == 9 && actual[2][0] == 15 && actual[2][1] == 7;
    for (int i = 0; i < count; i++) free(actual[i]);
    free(actual);
    free(widths);
    if (!ok) {
        puts("FAIL: 103 zigzag-level-order");
        return 1;
    }
    puts("PASS: 103 zigzag-level-order");
    return 0;
}
