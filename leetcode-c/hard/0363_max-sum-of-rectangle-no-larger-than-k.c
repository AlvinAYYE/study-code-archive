/*
 * LeetCode 363. Max Sum of Rectangle No Larger Than K
 * （不大於 K 的最大矩形和）
 *
 * 題意（繁體中文）：
 *   給定含正負整數的矩陣與整數 k，請找出一個非空矩形區域，使其元素總和
 *   不大於 k，並讓總和盡可能大。回傳該最大總和。
 *
 * 範例：
 *   1. matrix=[[1,0,1],[0,-2,3]], k=2，回傳 2；例如選取 [[0,1],[-2,3]]。
 *   2. matrix=[[2,2,-1]], k=3，回傳 3。
 *
 * 限制：矩陣列數與欄數皆為 1..100；每格介於 -100..100；-10^5 <= k <= 10^5。
 *
 * 解題步驟：
 *   1. 固定矩形的上下邊（或左右邊），把夾住的每一欄（或每一列）加總，
 *      將二維問題轉成一維的「不大於 k 的最大子陣列和」。沿較短的矩陣邊
 *      枚舉邊界組合，減少計算次數。
 *   2. 對一維數列建立前綴和。若目前前綴是 sum，先前前綴 p 必須滿足
 *      p >= sum-k，才能讓區間和 sum-p 不大於 k；其中最小的合法 p 會給出
 *      最大的區間和。
 *   3. 用排序陣列保存已看過的前綴和，二分搜尋符合條件的第一個值，再插入
 *      目前前綴。陣列長度最多 100，插入位移成本很小。
 *
 * 複雜度：令 q=min(m,n)、p=max(m,n)，時間 O(q^2*p^2)，額外空間 O(p)。
 *   在 p<=100 時，排序前綴陣列提供簡單且足夠快的實作。
 * LeetCode C API：
 * int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k)
 */
#include <limits.h>
#include <stdio.h>
#include <string.h>

static int lowerBound(const int *values, int size, int target) {
    int low = 0, high = size;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (values[middle] < target) low = middle + 1;
        else high = middle;
    }
    return low;
}

static int maxSubarrayAtMostK(const int *values, int length, int k) {
    int prefixes[101];
    int prefixCount = 1;
    prefixes[0] = 0;
    int sum = 0;
    int best = INT_MIN;

    for (int i = 0; i < length; ++i) {
        sum += values[i];
        int index = lowerBound(prefixes, prefixCount, sum - k);
        if (index < prefixCount) {
            int candidate = sum - prefixes[index];
            if (candidate > best) best = candidate;
        }

        int insertion = lowerBound(prefixes, prefixCount, sum);
        memmove(prefixes + insertion + 1, prefixes + insertion,
                (size_t)(prefixCount - insertion) * sizeof *prefixes);
        prefixes[insertion] = sum;
        ++prefixCount;
    }
    return best;
}

int maxSumSubmatrix(int **matrix, int matrixSize, int *matrixColSize, int k) {
    int rows = matrixSize;
    int columns = matrixColSize[0];
    int best = INT_MIN;

    if (rows <= columns) {
        int compressed[100];
        for (int top = 0; top < rows; ++top) {
            memset(compressed, 0, (size_t)columns * sizeof *compressed);
            for (int bottom = top; bottom < rows; ++bottom) {
                for (int column = 0; column < columns; ++column)
                    compressed[column] += matrix[bottom][column];
                int candidate = maxSubarrayAtMostK(compressed, columns, k);
                if (candidate > best) best = candidate;
                if (best == k) return best;
            }
        }
    } else {
        int compressed[100];
        for (int left = 0; left < columns; ++left) {
            memset(compressed, 0, (size_t)rows * sizeof *compressed);
            for (int right = left; right < columns; ++right) {
                for (int row = 0; row < rows; ++row)
                    compressed[row] += matrix[row][right];
                int candidate = maxSubarrayAtMostK(compressed, rows, k);
                if (candidate > best) best = candidate;
                if (best == k) return best;
            }
        }
    }
    return best;
}

int main(void) {
    int a0[] = {1, 0, 1}, a1[] = {0, -2, 3};
    int *matrix1[] = {a0, a1};
    int columns1[] = {3, 3};
    int b0[] = {2, 2, -1};
    int *matrix2[] = {b0};
    int columns2[] = {3};
    int c0[] = {-5, -4}, c1[] = {-3, -2};
    int *matrix3[] = {c0, c1};
    int columns3[] = {2, 2};
    int passed = maxSumSubmatrix(matrix1, 2, columns1, 2) == 2 &&
                 maxSumSubmatrix(matrix2, 1, columns2, 3) == 3 &&
                 maxSumSubmatrix(matrix3, 2, columns3, -2) == -2;
    puts(passed ? "PASS: 363 max-sum-of-rectangle-no-larger-than-k"
                : "FAIL: 363 max-sum-of-rectangle-no-larger-than-k");
    return passed ? 0 : 1;
}
