/*
 * Title-CN: 輸出二元樹
 * LeetCode 655. Print Binary Tree
 *
 * 題意翻譯：把二元樹排成文字矩陣。若樹高是 h，矩陣有 h 列、2^h-1 欄；
 * 根放在第一列中央，每個左子樹放到左半區中央，右子樹放到右半區中央，
 * 空位置填空字串中的空格。
 *
 * 範例：樹 [1,2] 輸出兩列：第一列 " 1 "，第二列 "2  "。
 *
 * 限制：樹高不超過 10；節點值介於 -99 到 99。
 *
 * 解題思路：先計算樹高，配置 h x (2^h-1) 的空白字元矩陣。遞迴時把目前節點放在
 * 所屬欄位區間的中央，再將左子樹交給左半欄位、右子樹交給右半欄位。
 *
 * 複雜度：時間與輸出空間 O(h*2^h)，矩陣本身就有這麼多格。
 * LeetCode 介面：保留 printTree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int treeHeight(struct TreeNode *root) {
    if (root == NULL) return 0;
    int left = treeHeight(root->left);
    int right = treeHeight(root->right);
    return 1 + (left > right ? left : right);
}

static void placeNodes(char **matrix, struct TreeNode *node,
                       int row, int left, int right) {
    if (node == NULL || left > right) return;
    int middle = left + (right - left) / 2;
    char text[16];
    int length = snprintf(text, sizeof(text), "%d", node->val);
    int start = middle - (length - 1) / 2;
    memcpy(matrix[row] + start, text, (size_t)length);
    placeNodes(matrix, node->left, row + 1, left, middle - 1);
    placeNodes(matrix, node->right, row + 1, middle + 1, right);
}

char **printTree(struct TreeNode *root, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    int height = treeHeight(root);
    if (height == 0) return NULL;
    int width = (1 << height) - 1;

    char **matrix = malloc((size_t)height * sizeof(*matrix));
    int *columns = malloc((size_t)height * sizeof(*columns));
    if (matrix == NULL || columns == NULL) {
        free(matrix);
        free(columns);
        return NULL;
    }
    for (int row = 0; row < height; ++row) {
        matrix[row] = malloc((size_t)width + 1);
        if (matrix[row] == NULL) {
            for (int prior = 0; prior < row; ++prior) free(matrix[prior]);
            free(matrix);
            free(columns);
            return NULL;
        }
        memset(matrix[row], ' ', (size_t)width);
        matrix[row][width] = '\0';
        columns[row] = width;
    }
    placeNodes(matrix, root, 0, 0, width - 1);
    *returnSize = height;
    *returnColumnSizes = columns;
    return matrix;
}

static struct TreeNode *newNode(int value) {
    struct TreeNode *node = malloc(sizeof(*node));
    assert(node != NULL);
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

int main(void) {
    struct TreeNode *root = newNode(1);
    root->left = newNode(2);
    int rows = 0;
    int *columns = NULL;
    char **matrix = printTree(root, &rows, &columns);
    assert(rows == 2 && columns[0] == 3 && columns[1] == 3);
    assert(strcmp(matrix[0], " 1 ") == 0);
    assert(strcmp(matrix[1], "2  ") == 0);
    for (int i = 0; i < rows; ++i) free(matrix[i]);
    free(matrix);
    free(columns);
    free(root->left);
    free(root);
    return 0;
}
