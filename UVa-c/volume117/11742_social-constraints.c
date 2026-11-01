/*
 * ==========================================================================
 * UVa 11742 - Social Constraints
 * Title-CN: 社交距離約束排列計數
 * Difficulty: Easy
 * Tags: Permutations, Brute Force
 * URL: https://onlinejudge.org/external/117/11742.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count permutations of n teenagers sitting in a row such that all distance constraints (|pos(a) - pos(b)| <= c or >= -c) are met.
 *
 * [中文] 題目說明:
 *     求 n 個青少年排成一排的座位排列數，使其同時滿足所有正負距離約束條件。
 *
 * [EN] Approach:
 *     Since n <= 8, generate all n! permutations (at most 40,320) and check all m constraints for each.
 * [中文] 思路:
 *     由於 n <= 8，直接枚舉全排列（最多 40320 種），逐一驗證是否符合各限制條件並計數。
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

int count_seating_arrangements(int n, int m, const int constraints[][3]) {
    int p[8];
    for (int i = 0; i < n; i++) p[i] = i;
    int valid = 0;
    // factorial simulation
    int total = 1;
    for (int i = 1; i <= n; i++) total *= i;
    for (int it = 0; it < total; it++) {
        // next permutation logic simplified for test
        bool ok = true;
        for (int c = 0; c < m; c++) {
            int a = constraints[c][0], b = constraints[c][1], dist = constraints[c][2];
            int pos_a = -1, pos_b = -1;
            for (int i = 0; i < n; i++) {
                if (p[i] == a) pos_a = i;
                if (p[i] == b) pos_b = i;
            }
            int d = abs(pos_a - pos_b);
            if (dist > 0 && d > dist) { ok = false; break; }
            if (dist < 0 && d < -dist) { ok = false; break; }
        }
        if (ok) valid++;
        // simple next perm
        int i = n - 2;
        while (i >= 0 && p[i] >= p[i + 1]) i--;
        if (i < 0) break;
        int j = n - 1;
        while (p[j] <= p[i]) j--;
        int t = p[i]; p[i] = p[j]; p[j] = t;
        for (int l = i + 1, r = n - 1; l < r; l++, r--) {
            t = p[l]; p[l] = p[r]; p[r] = t;
        }
    }
    return valid;
}

int main(void) {

    int c[1][3] = {{0, 1, 1}}; // 0 and 1 must be adjacent
    int cnt = count_seating_arrangements(3, 1, c); // [0,1,2], [1,0,2], [2,0,1], [2,1,0] -> 4
    int ok = (cnt == 4);
    printf("%s: UVa 11742 - Social Constraints\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
