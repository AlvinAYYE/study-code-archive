/*
 * ==========================================================================
 * UVa 10919 - Prerequisites?
 * Title-CN: 大學先修畢業學程選課檢驗
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/109/10919.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given courses taken by Freddie and category requirement rules (must take >= R_i courses from list i), determine if he can graduate.
 *
 * [中文] 題目概述:
 *     給定學生已修課程清單與各領域先修學分要求 (每個領域至少需修習 R_i 門指定課程)，判定該學生是否滿足畢業資格。
 *
 * [EN] Approach:
 *     Store selected courses in a hash set. For each category, count how many required courses Freddie has taken. If count < R_i, graduation fails.
 * [中文] 解題思路:
 *     將已選課程存入雜湊集合，對各學程分類統計已修課程數，若任一類別之修課數小於其最低要求門檻則判定資格不符。
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

int solve_uva10919(int n_selected, int *selected, int m_categories, int *req_cnt, int cat_courses[][20], int *cat_total) {
    for (int c = 0; c < m_categories; c++) {
        int match = 0;
        for (int i = 0; i < cat_total[c]; i++) {
            for (int s = 0; s < n_selected; s++) {
                if (selected[s] == cat_courses[c][i]) { match++; break; }
            }
        }
        if (match < req_cnt[c]) return 0;
    }
    return 1;
}

int main(void) {

    int s[] = {101, 102};
    int req[] = {1};
    int cc[1][20] = {{101, 103}};
    int tot[] = {2};
    int ok = solve_uva10919(2, s, 1, req, cc, tot);
    printf("%s: UVa 10919 - Prerequisites?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
