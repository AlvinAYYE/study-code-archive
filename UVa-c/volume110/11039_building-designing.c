/*
 * ==========================================================================
 * UVa 11039 - Building designing
 * Title-CN: 大樓設計
 * Difficulty: Easy
 * Tags: Greedy, Sorting
 * URL: https://onlinejudge.org/external/110/11039.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Construct a tower of maximum floors with alternating colors (positive = blue, negative = red) of strictly decreasing absolute sizes.
 *
 * [中文] 題目說明:
 *     用大小遞減且紅藍兩色交替的樓層（正數為藍，負數為紅）堆疊出最高的大樓。
 *
 * [EN] Approach:
 *     Sort floors by absolute value descending. Greedily take floor if its color sign differs from previous chosen floor.
 * [中文] 思路:
 *     將所有樓層按絕對值降序排序，貪心挑選與上一層顏色符號相反的樓層，計算最多樓層數。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

int cmp_abs_desc(const void *a, const void *b) {
    int va = abs(*(int*)a), vb = abs(*(int*)b);
    return vb - va;
}
int max_building_floors(int n, int *floors) {
    if (n == 0) return 0;
    qsort(floors, n, sizeof(int), cmp_abs_desc);
    int count = 1;
    int last_sign = (floors[0] > 0 ? 1 : -1);
    for (int i = 1; i < n; i++) {
        int cur_sign = (floors[i] > 0 ? 1 : -1);
        if (cur_sign != last_sign) {
            count++;
            last_sign = cur_sign;
        }
    }
    return count;
}

int main(void) {

    int f[] = {1, 2, -3, 4, -5};
    int ok = (max_building_floors(5, f) == 4); // -5, 4, -3, 2 (or 1)
    printf("%s: UVa 11039 - Building designing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
