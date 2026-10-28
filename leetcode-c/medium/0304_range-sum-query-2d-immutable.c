/*
 * Title-CN: 二維區域和查詢（不可修改）
 * LeetCode 304. Range Sum Query 2D - Immutable
 *
 * 題目翻譯：給定一個不會修改的整數矩陣，之後會多次詢問矩形區域的總和。
 * 每次給左上角 (row1, col1) 與右下角 (row2, col2)，回傳包含四條邊界的所有格子總和。
 *
 * 例子：矩陣 [[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],
 * [4,1,0,1,7],[1,0,3,0,5]]，查詢 (2,1) 到 (4,3) 的答案是 8。
 *
 * 限制：矩陣最多 200 x 200，元素介於 -10000 到 10000，最多查詢 10000 次。
 *
 * 解題步驟：
 *   1. 建立 prefix[r][c]，代表矩陣左上角到 (r-1,c-1) 的總和；多一列和一欄 0，方便處理邊界。
 *   2. 每個前綴格由「上方 + 左方 - 左上重複部分 + 目前矩陣值」算出。
 *   3. 查詢時取右下前綴，減去矩形上方與左方，再加回被重複減掉的左上角。
 *
 * 複雜度：建立前綴表 O(mn)，每次查詢 O(1)，額外空間 O(mn)。
 *
 * LeetCode 提交區：保留 NumMatrix 與三個函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int *prefix;
} NumMatrix;

static int prefixAt(const NumMatrix *obj, int row, int col) {
    return obj->prefix[row * (obj->cols + 1) + col];
}

NumMatrix *numMatrixCreate(int **matrix, int matrixSize, int *matrixColSize) {
    NumMatrix *obj = malloc(sizeof(*obj));
    if (obj == NULL) {
        return NULL;
    }
    obj->rows = matrixSize;
    obj->cols = matrixSize == 0 ? 0 : matrixColSize[0];

    size_t cells = (size_t)(obj->rows + 1) * (size_t)(obj->cols + 1);
    obj->prefix = calloc(cells, sizeof(*obj->prefix));
    if (obj->prefix == NULL) {
        free(obj);
        return NULL;
    }

    for (int row = 1; row <= obj->rows; ++row) {
        for (int col = 1; col <= obj->cols; ++col) {
            int index = row * (obj->cols + 1) + col;
            obj->prefix[index] = matrix[row - 1][col - 1]
                                 + prefixAt(obj, row - 1, col)
                                 + prefixAt(obj, row, col - 1)
                                 - prefixAt(obj, row - 1, col - 1);
        }
    }
    return obj;
}

int numMatrixSumRegion(NumMatrix *obj, int row1, int col1, int row2, int col2) {
    return prefixAt(obj, row2 + 1, col2 + 1)
           - prefixAt(obj, row1, col2 + 1)
           - prefixAt(obj, row2 + 1, col1)
           + prefixAt(obj, row1, col1);
}

void numMatrixFree(NumMatrix *obj) {
    if (obj != NULL) {
        free(obj->prefix);
        free(obj);
    }
}

int main(void) {
    int row0[] = {3, 0, 1, 4, 2};
    int row1[] = {5, 6, 3, 2, 1};
    int row2[] = {1, 2, 0, 1, 5};
    int row3[] = {4, 1, 0, 1, 7};
    int row4[] = {1, 0, 3, 0, 5};
    int *matrix[] = {row0, row1, row2, row3, row4};
    int columns[] = {5, 5, 5, 5, 5};
    NumMatrix *obj = numMatrixCreate(matrix, 5, columns);
    assert(obj != NULL);
    assert(numMatrixSumRegion(obj, 2, 1, 4, 3) == 8);
    assert(numMatrixSumRegion(obj, 1, 1, 2, 2) == 11);
    assert(numMatrixSumRegion(obj, 1, 2, 2, 4) == 12);
    numMatrixFree(obj);
    return 0;
}
