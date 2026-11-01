/*
 * ==========================================================================
 * UVa 11286 - Conformity
 * Title-CN: 選課組合人氣從眾指數統計
 * Difficulty: UVa Star 1
 * Tags: sorting, hash
 * URL: https://onlinejudge.org/external/112/11286.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given course combinations of 5 courses for N students, find the total number of students enrolled in the most popular combination(s).
 *
 * [中文] 題目說明:
 *     給定 N 名學生每人選修的 5 門課程編號，找出最受歡迎選課組合中的總修課學生人數。
 *
 * [EN] Approach:
 *     Sort each student's 5 courses. Group identical sorted 5-tuples and count frequencies. Sum counts of combinations matching maximum frequency.
 * [中文] 思路:
 *     將每位學生的 5 門課排序，統計各組合出現之次數，找出最大頻率後，將所有達到此最大頻率的組合學生數加總。
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

int solve_uva11286_pair_count(int *freqs, int num_combos) {
    int max_f = 0;
    for (int i = 0; i < num_combos; i++) if (freqs[i] > max_f) max_f = freqs[i];
    int total = 0;
    for (int i = 0; i < num_combos; i++) if (freqs[i] == max_f) total += freqs[i];
    return total;
}

int main(void) {

    int f[] = {2, 2, 1};
    int ok = (solve_uva11286_pair_count(f, 3) == 4);
    printf("%s: UVa 11286 - Conformity\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
