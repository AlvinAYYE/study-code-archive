/*
 * LeetCode 0764. Largest Plus Sign（最大加號標誌）
 * 題意：n*n 網格原本全是 1，mines 指定位置改成 0；求只含 1 的最大軸對齊加號階數。
 *       階數 k 表示中心是 1，向上下左右各延伸 k-1 格也都是 1；沒有加號回傳 0。
 * 範例：n=5、mine=[4,2] -> 2；n=1、mine=[0,0] -> 0。
 * 限制：1 <= n <= 500；mine 數量 <= 5000；座標均在網格內且不重複。
 * 解法：每格保存四個方向連續 1 的最短長度；由上、下、左、右各掃一次取最小值。
 * 複雜度：時間 O(n^2 + minesSize)，空間 O(n^2)。
 */
#include <stdio.h>
#include <stdlib.h>

static int smaller(int first, int second) {
    return first < second ? first : second;
}

/* ---- community solution ---- */
int orderOfLargestPlusSign(int n, int** mines, int minesSize,
                           int* minesColSize) {
    (void)minesColSize;
    int *arms = (int *)malloc(sizeof(int) * (size_t)n * (size_t)n);
    if (arms == NULL) {
        return 0;
    }
    for (int cell = 0; cell < n * n; cell++) {
        arms[cell] = 1;
    }
    for (int i = 0; i < minesSize; i++) {
        arms[mines[i][0] * n + mines[i][1]] = 0;
    }

    for (int row = 0; row < n; row++) {
        int run = 0;
        for (int col = 0; col < n; col++) {
            int cell = row * n + col;
            run = arms[cell] == 0 ? 0 : run + 1;
            arms[cell] = smaller(arms[cell], run);
        }
        run = 0;
        for (int col = n - 1; col >= 0; col--) {
            int cell = row * n + col;
            run = arms[cell] == 0 ? 0 : run + 1;
            arms[cell] = smaller(arms[cell], run);
        }
    }
    for (int col = 0; col < n; col++) {
        int run = 0;
        for (int row = 0; row < n; row++) {
            int cell = row * n + col;
            run = arms[cell] == 0 ? 0 : run + 1;
            arms[cell] = smaller(arms[cell], run);
        }
        run = 0;
        for (int row = n - 1; row >= 0; row--) {
            int cell = row * n + col;
            run = arms[cell] == 0 ? 0 : run + 1;
            arms[cell] = smaller(arms[cell], run);
        }
    }

    int answer = 0;
    for (int cell = 0; cell < n * n; cell++) {
        answer = arms[cell] > answer ? arms[cell] : answer;
    }
    free(arms);
    return answer;
}

/* ---- generated tests ---- */
int main(void) {
    int mineOne[] = {4, 2};
    int *minesOne[] = {mineOne};
    int columnsOne[] = {2};
    int mineTwo[] = {0, 0};
    int *minesTwo[] = {mineTwo};
    int columnsTwo[] = {2};
    bool passed = orderOfLargestPlusSign(5, minesOne, 1, columnsOne) == 2 &&
                  orderOfLargestPlusSign(1, minesTwo, 1, columnsTwo) == 0 &&
                  orderOfLargestPlusSign(2, minesOne, 0, NULL) == 1;
    printf("%s: 0764 orderOfLargestPlusSign tests=3\n",
           passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
