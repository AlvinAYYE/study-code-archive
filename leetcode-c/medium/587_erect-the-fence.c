/*
 * LeetCode 587. Erect the Fence（安裝圍欄）
 *
 * 題意（繁體中文）：
 *   給定花園裡每棵樹的位置 trees[i]=[x_i,y_i]。請用最短的繩子圍住整座花園，
 *   並回傳剛好位於圍欄外框上的所有樹座標，回傳順序不限。位於外框邊上的樹
 *   也必須回傳；被圍在內部的樹不用回傳。
 *
 * 範例：
 *   1. [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]，回傳外框上的五點：
 *      [1,1]、[2,0]、[4,2]、[3,3]、[2,4]；[2,2] 在內部。
 *   2. [[1,2],[2,2],[4,2]]，三點共線，三棵樹都位於圍欄邊界上。
 *
 * 限制：1 <= trees.length <= 3000；每個位置有兩個座標；0 <= x,y <= 100；
 *   所有座標互不相同。
 *
 * 解題步驟：
 *   1. 依 x、再依 y 將座標排序。凸包外框可分成下半部與上半部。
 *   2. 由左至右建立下半部，再由右至左建立上半部。若新點讓轉向變成順時針，
 *      就移除上一個點；共線時保留，這樣外框邊上的中間樹也會留下。
 *   3. 合併兩半部後去掉重複座標。配置 LeetCode 要求的二維回傳陣列與每列
 *      長度陣列；呼叫端負責釋放所有配置的記憶體。
 *
 * 複雜度：排序 O(n log n)，建立外框 O(n)，去除重複點 O(n^2)；整體 O(n^2)，
 *   額外空間 O(n)。n <= 3000 時，去重的簡單比較足以使用。
 * LeetCode C API：
 * int** outerTrees(int** trees, int treesSize, int* treesColSize,
 *                  int* returnSize, int** returnColumnSizes)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

static int comparePoints(const void *left, const void *right) {
    const Point *a = (const Point *)left;
    const Point *b = (const Point *)right;
    if (a->x != b->x) return a->x < b->x ? -1 : 1;
    if (a->y != b->y) return a->y < b->y ? -1 : 1;
    return 0;
}

static long long cross(Point origin, Point a, Point b) {
    return (long long)(a.x - origin.x) * (b.y - origin.y) -
           (long long)(a.y - origin.y) * (b.x - origin.x);
}

int **outerTrees(int **trees, int treesSize, int *treesColSize,
                 int *returnSize, int **returnColumnSizes) {
    (void)treesColSize; /* 題目保證每個輸入座標都有兩個整數。 */
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (treesSize <= 0) return NULL;

    int n = treesSize;
    Point *points = (Point *)malloc((size_t)n * sizeof *points);
    Point *hull = (Point *)malloc((size_t)(2 * n) * sizeof *hull);
    if (points == NULL || hull == NULL) {
        free(points);
        free(hull);
        return NULL;
    }
    for (int i = 0; i < n; ++i) {
        points[i].x = trees[i][0];
        points[i].y = trees[i][1];
    }
    qsort(points, (size_t)n, sizeof *points, comparePoints);

    int hullSize = 0;
    for (int i = 0; i < n; ++i) {
        while (hullSize >= 2 &&
               cross(hull[hullSize - 2], hull[hullSize - 1], points[i]) < 0)
            --hullSize;
        hull[hullSize++] = points[i];
    }

    int lowerSize = hullSize;
    for (int i = n - 2; i >= 0; --i) {
        while (hullSize >= lowerSize + 1 &&
               cross(hull[hullSize - 2], hull[hullSize - 1], points[i]) < 0)
            --hullSize;
        hull[hullSize++] = points[i];
    }
    if (hullSize > 1) --hullSize; /* 移除最後重複的起點。 */

    /* 共線輸入可能讓上下半部都包含中間點，原地保留唯一座標。 */
    int uniqueSize = 0;
    for (int i = 0; i < hullSize; ++i) {
        int seen = 0;
        for (int j = 0; j < uniqueSize; ++j) {
            if (hull[j].x == hull[i].x && hull[j].y == hull[i].y) {
                seen = 1;
                break;
            }
        }
        if (!seen) hull[uniqueSize++] = hull[i];
    }

    int **answer = (int **)malloc((size_t)uniqueSize * sizeof *answer);
    int *columnSizes = (int *)malloc((size_t)uniqueSize * sizeof *columnSizes);
    if (answer == NULL || columnSizes == NULL) {
        free(answer);
        free(columnSizes);
        free(points);
        free(hull);
        return NULL;
    }
    int allocatedRows = 0;
    for (int i = 0; i < uniqueSize; ++i) {
        answer[i] = (int *)malloc(2 * sizeof *answer[i]);
        if (answer[i] == NULL) {
            for (int j = 0; j < allocatedRows; ++j) free(answer[j]);
            free(answer);
            free(columnSizes);
            free(points);
            free(hull);
            return NULL;
        }
        answer[i][0] = hull[i].x;
        answer[i][1] = hull[i].y;
        columnSizes[i] = 2;
        ++allocatedRows;
    }

    free(points);
    free(hull);
    *returnSize = uniqueSize;
    *returnColumnSizes = columnSizes;
    return answer;
}

static int containsPoint(int **points, int count, int x, int y) {
    for (int i = 0; i < count; ++i)
        if (points[i][0] == x && points[i][1] == y) return 1;
    return 0;
}

static void freeAnswer(int **answer, int count, int *columnSizes) {
    for (int i = 0; i < count; ++i) free(answer[i]);
    free(answer);
    free(columnSizes);
}

int main(void) {
    int a0[] = {1, 1}, a1[] = {2, 2}, a2[] = {2, 0};
    int a3[] = {2, 4}, a4[] = {3, 3}, a5[] = {4, 2};
    int *trees1[] = {a0, a1, a2, a3, a4, a5};
    int columns1[] = {2, 2, 2, 2, 2, 2};
    int returnSize1 = 0, *returnColumns1 = NULL;
    int **answer1 = outerTrees(trees1, 6, columns1, &returnSize1, &returnColumns1);
    int passed = answer1 != NULL && returnSize1 == 5 &&
                 containsPoint(answer1, returnSize1, 1, 1) &&
                 containsPoint(answer1, returnSize1, 2, 0) &&
                 containsPoint(answer1, returnSize1, 4, 2) &&
                 containsPoint(answer1, returnSize1, 3, 3) &&
                 containsPoint(answer1, returnSize1, 2, 4) &&
                 !containsPoint(answer1, returnSize1, 2, 2);
    if (answer1 != NULL) freeAnswer(answer1, returnSize1, returnColumns1);

    int b0[] = {1, 2}, b1[] = {2, 2}, b2[] = {4, 2};
    int *trees2[] = {b0, b1, b2};
    int columns2[] = {2, 2, 2};
    int returnSize2 = 0, *returnColumns2 = NULL;
    int **answer2 = outerTrees(trees2, 3, columns2, &returnSize2, &returnColumns2);
    passed = passed && answer2 != NULL && returnSize2 == 3 &&
             containsPoint(answer2, returnSize2, 1, 2) &&
             containsPoint(answer2, returnSize2, 2, 2) &&
             containsPoint(answer2, returnSize2, 4, 2);
    if (answer2 != NULL) freeAnswer(answer2, returnSize2, returnColumns2);

    puts(passed ? "PASS: 587 erect-the-fence" : "FAIL: 587 erect-the-fence");
    return passed ? 0 : 1;
}
