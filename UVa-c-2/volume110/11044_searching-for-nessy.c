/*
 * ==========================================================================
 * UVa 11044 - Searching for Nessy
 * Title-CN: 搜尋尼斯水怪 (聲納雷達網格覆蓋)
 * Difficulty: UVa Star 1
 * Tags: math
 * URL: https://onlinejudge.org/external/110/11044.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Cover an n x m grid with 3 x 3 sonars avoiding edges. Find minimum sonars needed.
 *
 * [中文] 題目說明:
 *     在 n x m 的湖泊網格中安裝 3x3 聲納 (邊界一圈不需覆蓋)，求覆蓋全湖所需的最少聲納數量。
 *
 * [EN] Approach:
 *     Formula: (n / 3) * (m / 3).
 * [中文] 思路:
 *     網格整除覆蓋公式：有效內部區域為 (n-2)x(m-2)，每個聲納能監控 3x3，最少所需數量為 (n / 3) * (m / 3)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva11044(int n, int m) {
    return (n / 3) * (m / 3);
}

int main(void) {

    int ok = (solve_uva11044(6, 6) == 4) && (solve_uva11044(8, 8) == 4);
    printf("%s: UVa 11044 - Searching for Nessy\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
