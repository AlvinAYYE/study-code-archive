/*
 * Title-CN: 建立四叉樹
 * LeetCode 427. Construct Quad Tree
 *
 * 題意翻譯：給定一個邊長為 2 的冪次方、只含 0 和 1 的正方形矩陣，
 * 請建立四叉樹。若某區域全部相同，就用一個葉節點表示；否則把它切成
 * 左上、右上、左下、右下四塊，並以四個子節點表示。
 *
 * 範例：矩陣 [[0,1],[1,0]] 不能用單一葉節點表示，因此根節點有四個葉子，
 * 四個葉子的值依序為 0、1、1、0。
 *
 * 限制：矩陣邊長為 1 到 64，且是 2 的冪；每格只會是 0 或 1。
 *
 * 解題思路：檢查目前正方形區域是否全為同一值。若是，就建立葉節點；
 * 若不是，將邊長對半，對四個象限遞迴建立子樹。切分直到每區只剩一格。
 *
 * 複雜度：最壞情況 O(n^2 log n)（每層檢查區域格子）；遞迴與輸出樹空間 O(n^2)。
 * LeetCode 介面：保留 construct；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    bool val;
    bool isLeaf;
    struct Node *topLeft;
    struct Node *topRight;
    struct Node *bottomLeft;
    struct Node *bottomRight;
};

static struct Node *newNode(bool value, bool isLeaf) {
    struct Node *node = malloc(sizeof(*node));
    if (node == NULL) return NULL;
    node->val = value;
    node->isLeaf = isLeaf;
    node->topLeft = node->topRight = NULL;
    node->bottomLeft = node->bottomRight = NULL;
    return node;
}

static void freeTree(struct Node *node) {
    if (node == NULL) return;
    freeTree(node->topLeft);
    freeTree(node->topRight);
    freeTree(node->bottomLeft);
    freeTree(node->bottomRight);
    free(node);
}

static struct Node *build(int **grid, int row, int col, int size) {
    int first = grid[row][col];
    bool uniform = true;
    for (int r = row; r < row + size && uniform; ++r) {
        for (int c = col; c < col + size; ++c) {
            if (grid[r][c] != first) {
                uniform = false;
                break;
            }
        }
    }
    if (uniform) return newNode(first != 0, true);

    struct Node *node = newNode(false, false);
    if (node == NULL) return NULL;
    int half = size / 2;
    node->topLeft = build(grid, row, col, half);
    node->topRight = build(grid, row, col + half, half);
    node->bottomLeft = build(grid, row + half, col, half);
    node->bottomRight = build(grid, row + half, col + half, half);
    if (node->topLeft == NULL || node->topRight == NULL
        || node->bottomLeft == NULL || node->bottomRight == NULL) {
        freeTree(node);
        return NULL;
    }
    return node;
}

struct Node *construct(int **grid, int gridSize, int *gridColSize) {
    (void)gridColSize;
    if (grid == NULL || gridSize <= 0) return NULL;
    return build(grid, 0, 0, gridSize);
}

int main(void) {
    int row0[] = {0, 1, 1, 1};
    int row1[] = {1, 0, 1, 1};
    int row2[] = {1, 1, 0, 1};
    int row3[] = {1, 1, 1, 0};
    int *grid[] = {row0, row1, row2, row3};
    int columns[] = {4, 4, 4, 4};
    struct Node *root = construct(grid, 4, columns);
    assert(root != NULL && !root->isLeaf);
    assert(root->topLeft != NULL && !root->topLeft->isLeaf);
    assert(root->topRight->isLeaf && root->topRight->val);
    assert(root->bottomLeft->isLeaf && root->bottomLeft->val);
    assert(root->bottomRight != NULL && !root->bottomRight->isLeaf);
    freeTree(root);

    int uniform0[] = {0, 0};
    int uniform1[] = {0, 0};
    int *uniformGrid[] = {uniform0, uniform1};
    root = construct(uniformGrid, 2, columns);
    assert(root != NULL && root->isLeaf && !root->val);
    freeTree(root);
    return 0;
}
