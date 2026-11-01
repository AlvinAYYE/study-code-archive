/*
 * ==========================================================================
 * UVa 11849 - CD
 * Title-CN: CD 光碟共同擁有重複計數
 * Difficulty: UVa Star 1
 * Tags: two-pointers, sorting
 * URL: https://onlinejudge.org/external/118/11849.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Jack and Jill each have sorted catalogs of CD catalog numbers. Count how many CDs they both own.
 *
 * [中文] 題目說明:
 *     Jack 和 Jill 各自擁有一批按遞增順序排列的 CD 光碟編號，統計兩人共同擁有的 CD 數量。
 *
 * [EN] Approach:
 *     Two pointers traversing both sorted arrays in O(N + M) time. If equal, increment count and advance both pointers.
 * [中文] 思路:
 *     雙指針同步掃描兩已排序陣列：數值相等則計數加一並同時前進，否則推進較小元素之指針，時間複雜度 O(N+M)。
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

int solve_uva11849(int n, int *jack, int m, int *jill) {
    int i = 0, j = 0, common = 0;
    while (i < n && j < m) {
        if (jack[i] == jill[j]) { common++; i++; j++; }
        else if (jack[i] < jill[j]) i++;
        else j++;
    }
    return common;
}

int main(void) {

    int a[] = {1, 2, 3};
    int b[] = {2, 3, 4};
    int res = solve_uva11849(3, a, 3, b);
    int ok = (res == 2);
    printf("%s: UVa 11849 - CD\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
