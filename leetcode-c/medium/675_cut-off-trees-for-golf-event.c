/*
 * LeetCode 675. Cut Off Trees for Golf Event（高爾夫活動砍樹）
 *
 * 題意（繁體中文）：
 *   森林以 m x n 矩陣表示：0 是不能通過的障礙物，1 是空地，大於 1 的數字
 *   表示樹的高度。從左上角 (0,0) 出發，只能上下左右走動，且必須依樹高由
 *   矮到高砍完所有樹。砍下樹後該格會變成空地 1。請回傳走到所有樹並砍完
 *   所需的最少步數；若有樹無法到達，回傳 -1。題目保證至少有一棵樹，且樹高
 *   互不相同。
 *
 * 範例：
 *   1. [[1,2,3],[0,0,4],[7,6,5]]，回傳 6。
 *   2. [[1,2,3],[0,0,0],[7,6,5]]，回傳 -1，底排被障礙隔開。
 *   3. [[2,3,4],[0,0,5],[8,7,6]]，回傳 6；起點本身是第一棵樹，砍它不用移動。
 *
 * 限制：1 <= m,n <= 50；0 <= forest[i][j] <= 10^9；樹高互不相同。
 *
 * 解題步驟：
 *   1. 收集所有樹的位置與高度，依高度由小到大排序。
 *   2. 從目前所在位置到下一棵樹做一次廣度優先搜尋。BFS 在無權重格子圖上
 *      能找到最少步數；只有值為 0 的格子不能進入。
 *   3. 若搜尋不到目標，回傳 -1；否則把距離加進總步數，並將目前位置移到
 *      剛砍完的樹，繼續處理下一棵。樹格砍後仍可走，因此都視為可通行格。
 *
 * 複雜度：T 為樹數、V=m*n；排序 O(T log T)，每棵樹做一次 BFS，時間
 *   O(T*V)，額外空間 O(V)。
 * LeetCode C API：int cutOffTree(int** forest, int forestSize, int* forestColSize)
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 2500

typedef struct {
    int height;
    int row;
    int column;
} Tree;

static int compareTrees(const void *left, const void *right) {
    const Tree *a = (const Tree *)left;
    const Tree *b = (const Tree *)right;
    return (a->height > b->height) - (a->height < b->height);
}

static int shortestPath(int **forest, int rows, int columns,
                        int startRow, int startColumn,
                        int targetRow, int targetColumn) {
    int distance[MAX_CELLS];
    int queue[MAX_CELLS];
    int cellCount = rows * columns;
    for (int i = 0; i < cellCount; ++i) distance[i] = -1;

    int start = startRow * columns + startColumn;
    int target = targetRow * columns + targetColumn;
    if (forest[startRow][startColumn] == 0 || forest[targetRow][targetColumn] == 0)
        return -1;
    int head = 0, tail = 0;
    queue[tail++] = start;
    distance[start] = 0;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    while (head < tail) {
        int cell = queue[head++];
        if (cell == target) return distance[cell];
        int row = cell / columns;
        int column = cell % columns;
        for (int direction = 0; direction < 4; ++direction) {
            int nextRow = row + dr[direction];
            int nextColumn = column + dc[direction];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 ||
                nextColumn >= columns || forest[nextRow][nextColumn] == 0)
                continue;
            int nextCell = nextRow * columns + nextColumn;
            if (distance[nextCell] != -1) continue;
            distance[nextCell] = distance[cell] + 1;
            queue[tail++] = nextCell;
        }
    }
    return -1;
}

int cutOffTree(int **forest, int forestSize, int *forestColSize) {
    if (forest == NULL || forestSize <= 0 || forestColSize == NULL) return -1;
    int rows = forestSize;
    int columns = forestColSize[0];
    Tree trees[MAX_CELLS];
    int treeCount = 0;
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (forest[row][column] > 1) {
                trees[treeCount++] = (Tree){forest[row][column], row, column};
            }
        }
    }
    qsort(trees, (size_t)treeCount, sizeof *trees, compareTrees);

    int currentRow = 0, currentColumn = 0;
    int totalSteps = 0;
    for (int i = 0; i < treeCount; ++i) {
        int distance = shortestPath(forest, rows, columns,
                                    currentRow, currentColumn,
                                    trees[i].row, trees[i].column);
        if (distance < 0) return -1;
        totalSteps += distance;
        currentRow = trees[i].row;
        currentColumn = trees[i].column;
    }
    return totalSteps;
}

int main(void) {
    int a0[] = {1, 2, 3}, a1[] = {0, 0, 4}, a2[] = {7, 6, 5};
    int *forest1[] = {a0, a1, a2};
    int columns1[] = {3, 3, 3};
    int b0[] = {1, 2, 3}, b1[] = {0, 0, 0}, b2[] = {7, 6, 5};
    int *forest2[] = {b0, b1, b2};
    int columns2[] = {3, 3, 3};
    int c0[] = {2, 3, 4}, c1[] = {0, 0, 5}, c2[] = {8, 7, 6};
    int *forest3[] = {c0, c1, c2};
    int columns3[] = {3, 3, 3};
    int d0[] = {0, 2};
    int *forest4[] = {d0};
    int columns4[] = {2};
    int passed = cutOffTree(forest1, 3, columns1) == 6 &&
                 cutOffTree(forest2, 3, columns2) == -1 &&
                 cutOffTree(forest3, 3, columns3) == 6 &&
                 cutOffTree(forest4, 1, columns4) == -1;
    puts(passed ? "PASS: 675 cut-off-trees-for-golf-event"
                : "FAIL: 675 cut-off-trees-for-golf-event");
    return passed ? 0 : 1;
}
