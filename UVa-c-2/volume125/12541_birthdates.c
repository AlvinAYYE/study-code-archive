/*
 * ==========================================================================
 * UVa 12541 - Birthdates
 * Title-CN: 出生日期排序
 * Difficulty: Easy
 * Tags: Sorting, Simulation
 * URL: https://onlinejudge.org/external/125/12541.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a list of people with their birth dates, identify the youngest and oldest persons.
 *
 * [中文] 題目說明:
 *     給定一群人的姓名與出生年月日，找出年齡最年輕（出生日期最晚）與最年長（出生日期最早）的人。
 *
 * [EN] Approach:
 *     Convert day, month, year into comparable integer date: year * 10000 + month * 100 + day. Find min and max.
 * [中文] 思路:
 *     將年月日組合成 year * 10000 + month * 100 + day 數值，取最大值為最年輕，最小值為最年長。
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

void find_youngest_oldest(int n, const char names[10][20], const int d[], const int m[], const int y[], char *youngest, char *oldest) {
    int min_val = 99999999, max_val = -1;
    int idx_old = 0, idx_young = 0;
    for (int i = 0; i < n; i++) {
        int val = y[i] * 10000 + m[i] * 100 + d[i];
        if (val < min_val) { min_val = val; idx_old = i; }
        if (val > max_val) { max_val = val; idx_young = i; }
    }
    strcpy(oldest, names[idx_old]);
    strcpy(youngest, names[idx_young]);
}

int main(void) {

    char names[3][20] = {"Alice", "Bob", "Charlie"};
    int d[] = {1, 15, 20}, m[] = {1, 5, 1}, y[] = {1990, 1995, 1990};
    char y_name[20], o_name[20];
    find_youngest_oldest(3, names, d, m, y, y_name, o_name);
    int ok = (strcmp(y_name, "Bob") == 0 && strcmp(o_name, "Alice") == 0);
    printf("%s: UVa 12541 - Birthdates\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
