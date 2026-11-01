/*
 * ==========================================================================
 * UVa 11078 - Open Credit System
 * Title-CN: 學長學弟成績最大差值單調掃描
 * Difficulty: UVa Star 1
 * Tags: greedy, array
 * URL: https://onlinejudge.org/external/110/11078.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given scores of N students in seniority order, find the maximum difference A[i] - A[j] where senior student i precedes junior student j (i < j).
 *
 * [中文] 題目說明:
 *     依年級高低依序給定 N 位學生的成績，求學長與學弟之間的最大分數差值 A[i] - A[j] (其中 i < j)。
 *
 * [EN] Approach:
 *     Single pass: maintain max_so_far of A[0..j-1], and update max_diff = max(max_diff, max_so_far - A[j]). Time complexity O(N).
 * [中文] 思路:
 *     單次遍歷：維護前綴最大值 max_so_far，動態以 max_so_far - A[j] 更新全局最大差值，時間複雜度 O(N)。
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

int solve_uva11078(int n, int *a) {
    int max_so_far = a[0];
    int max_diff = -1e9;
    for (int j = 1; j < n; j++) {
        int diff = max_so_far - a[j];
        if (diff > max_diff) max_diff = diff;
        if (a[j] > max_so_far) max_so_far = a[j];
    }
    return max_diff;
}

int main(void) {

    int a[] = {10, 5, 20, 2};
    int diff = solve_uva11078(4, a); // 20 - 2 = 18
    int ok = (diff == 18);
    printf("%s: UVa 11078 - Open Credit System\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
