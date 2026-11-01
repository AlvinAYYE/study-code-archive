/*
 * ==========================================================================
 * UVa 11917 - Do Your Own Homework
 * Title-CN: 自己的作業自己寫
 * Difficulty: Easy
 * Tags: Map, Simulation, String
 * URL: https://onlinejudge.org/external/119/11917.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Sparrow must finish a homework subject. Given time to finish each subject and a deadline D, decide if he can finish on time, late, or must do his own homework.
 *
 * [中文] 題目概述:
 *     Sparrow 必須完成某科作業，給定各科所需天數與截止期限 D，判定能否準時完成、遲交完成或來不及。
 *
 * [EN] Approach:
 *     Look up required days T for the requested subject: if T <= D print 'Yesss', if T <= D+5 print 'Late', else 'Do your own homework!'.
 * [中文] 解題思路:
 *     在科目清單中查詢所需天數 T：若 T <= D 則如期完成；若 T <= D+5 則遲交；否則需自己寫。
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

int sparrow_homework(int n, const char subjects[10][20], const int *days, const char *target, int d) {
    for (int i = 0; i < n; i++) {
        if (strcmp(subjects[i], target) == 0) {
            if (days[i] <= d) return 0; // Yesss
            if (days[i] <= d + 5) return 1; // Late
            return 2; // Do your own homework!
        }
    }
    return 2;
}

int main(void) {

    char subs[10][20] = {"math", "science"};
    int d[] = {3, 7};
    int res = sparrow_homework(2, subs, d, "math", 4);
    int ok = (res == 0);
    printf("%s: UVa 11917 - Do Your Own Homework\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
