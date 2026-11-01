/*
 * ==========================================================================
 * UVa 300 - Maya Calendar
 * Title-CN: 瑪雅曆法轉換
 * Difficulty: Easy
 * Tags: Math, Simulation, Calendar
 * URL: https://onlinejudge.org/external/3/300.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Convert dates from the Haab solar calendar (365 days) to the Tzolkin religious calendar (260 days).
 *
 * [中文] 題目概述:
 *     將日期由 365 天的哈布曆 (Haab) 轉換為 260 天的卓爾金曆 (Tzolkin)。
 *
 * [EN] Approach:
 *     Compute total days = year * 365 + month_index * 20 + day. Then Tzolkin year = total / 260, number = (total % 13) + 1, name = name_list[total % 20].
 * [中文] 解題思路:
 *     先算出從曆元起的總天數，再以 260 模算求得卓爾金曆年份、(total%13)+1 數字及 total%20 守護神名稱。
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

const char *tzolkin_names[] = {
    "imix", "ik", "akbal", "kan", "chicchan",
    "cimi", "manik", "lamat", "muluk", "ok",
    "chuen", "eb", "ben", "ix", "mem",
    "cib", "caban", "eznab", "canac", "ahau"
};

void haab_to_tzolkin(int day, int month_idx, int year, int *t_num, char *t_name, int *t_yr) {
    long long total = (long long)year * 365 + month_idx * 20 + day;
    *t_yr = total / 260;
    *t_num = (total % 13) + 1;
    strcpy(t_name, tzolkin_names[total % 20]);
}

int main(void) {

    int num, yr;
    char name[20];
    haab_to_tzolkin(10, 0, 0, &num, name, &yr); // day 10 -> total 10
    int ok = (num == 11 && strcmp(name, "chuen") == 0 && yr == 0);
    printf("%s: UVa 300 - Maya Calendar\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
