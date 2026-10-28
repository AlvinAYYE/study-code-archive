/*
 * LeetCode 107. Binary Tree Level Order Traversal II
 * 繁中題名：二元樹的由下而上層序走訪
 * 題目：給定二元樹根節點，從最底層開始由左至右逐層回傳節點值，
 *       最後一層才是根節點所在的第一層。空樹回傳空陣列。
 *
 * 範例 1：root=[3,9,20,null,null,15,7]，輸出 [[15,7],[9,20],[3]]。
 * 範例 2：root=[1]，輸出 [[1]]。
 * 範例 3：root=[]，輸出 []。
 * 限制：節點數介於 0 到 2000；-1000 <= Node.val <= 1000。
 *
 * 解題步驟：
 *   1. 用佇列進行廣度優先搜尋，照一般層序由上到下走訪。
 *   2. 每輪先記下目前佇列長度，這個數字就是本層節點數；只取出這些節點，
 *      並把它們的左右子節點加到佇列尾端。
 *   3. 依序把每層值存入答案，走訪完成後反轉各層的指標與欄數，即得到由下而上。
 *   時間 O(n)，佇列與回傳結果空間 O(n)。
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

static int countNodes(const struct TreeNode *root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

/* ---------- LeetCode submission / 提交區 ---------- */
int **levelOrderBottom(struct TreeNode *root, int *returnSize,
                       int **returnColumnSizes) {
    int nodeCount, levelCount = 0;
    int **levels;
    int *columnSizes;
    struct TreeNode **queue;
    int head = 0, tail = 0;

    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (root == NULL) return NULL;

    nodeCount = countNodes(root);
    levels = (int **)malloc((size_t)nodeCount * sizeof *levels);
    columnSizes = (int *)malloc((size_t)nodeCount * sizeof *columnSizes);
    queue = (struct TreeNode **)malloc((size_t)nodeCount * sizeof *queue);
    if (levels == NULL || columnSizes == NULL || queue == NULL) {
        free(levels);
        free(columnSizes);
        free(queue);
        return NULL;
    }

    queue[tail++] = root;
    while (head < tail) {
        int levelSize = tail - head;
        int *row = (int *)malloc((size_t)levelSize * sizeof *row);
        if (row == NULL) {
            for (int i = 0; i < levelCount; ++i) free(levels[i]);
            free(levels);
            free(columnSizes);
            free(queue);
            return NULL;
        }

        /* 固定本層大小，只處理本輪開始時已在佇列中的節點。 */
        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode *node = queue[head++];
            row[i] = node->val;
            if (node->left != NULL) queue[tail++] = node->left;
            if (node->right != NULL) queue[tail++] = node->right;
        }
        levels[levelCount] = row;
        columnSizes[levelCount] = levelSize;
        ++levelCount;
    }
    free(queue);

    /* BFS 得到上到下的層；將列順序反轉即可符合題目要求。 */
    for (int left = 0, right = levelCount - 1; left < right; ++left, --right) {
        int *row = levels[left];
        int width = columnSizes[left];
        levels[left] = levels[right];
        levels[right] = row;
        columnSizes[left] = columnSizes[right];
        columnSizes[right] = width;
    }

    *returnSize = levelCount;
    *returnColumnSizes = columnSizes;
    return levels;
}
/* ---------- end submission ---------- */

static void freeResult(int **levels, int levelCount, int *columnSizes) {
    if (levels != NULL) {
        for (int i = 0; i < levelCount; ++i) free(levels[i]);
    }
    free(levels);
    free(columnSizes);
}

static int rowEquals(const int *actual, int actualSize,
                     const int *expected, int expectedSize) {
    if (actualSize != expectedSize) return 0;
    for (int i = 0; i < actualSize; ++i) {
        if (actual[i] != expected[i]) return 0;
    }
    return 1;
}

int main(void) {
    struct TreeNode n9 = {9, NULL, NULL};
    struct TreeNode n15 = {15, NULL, NULL};
    struct TreeNode n7 = {7, NULL, NULL};
    struct TreeNode n20 = {20, &n15, &n7};
    struct TreeNode root = {3, &n9, &n20};
    int expected0[] = {15, 7};
    int expected1[] = {9, 20};
    int expected2[] = {3};
    int returnSize = 0, *columns = NULL;
    int **levels = levelOrderBottom(&root, &returnSize, &columns);
    int passed = levels != NULL && returnSize == 3 &&
                 rowEquals(levels[0], columns[0], expected0, 2) &&
                 rowEquals(levels[1], columns[1], expected1, 2) &&
                 rowEquals(levels[2], columns[2], expected2, 1);
    freeResult(levels, returnSize, columns);

    struct TreeNode single = {1, NULL, NULL};
    returnSize = 0;
    columns = NULL;
    levels = levelOrderBottom(&single, &returnSize, &columns);
    int expectedSingle[] = {1};
    passed = passed && levels != NULL && returnSize == 1 &&
             rowEquals(levels[0], columns[0], expectedSingle, 1);
    freeResult(levels, returnSize, columns);

    returnSize = -1;
    columns = NULL;
    levels = levelOrderBottom(NULL, &returnSize, &columns);
    passed = passed && levels == NULL && returnSize == 0 && columns == NULL;
    freeResult(levels, returnSize, columns);

    puts(passed ? "PASS: 107 binary-tree-level-order-traversal-ii"
                : "FAIL: 107 binary-tree-level-order-traversal-ii");
    return passed ? 0 : 1;
}
