/*
 * ==========================================================================
 * UVa 10370 - Above Average
 * Title-CN: 超越平均人數百分比
 * Difficulty: UVa Star 1
 * Tags: math, array
 * URL: https://onlinejudge.org/external/103/10370.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate percentage of students in class whose scores are strictly above class average.
 *
 * [中文] 題目說明:
 *     計算班級中成績嚴格高於班級平均分數的學生人數百分比 (輸出保留 3 位小數)。
 *
 * [EN] Approach:
 *     Compute mean score. Count scores > mean. Percentage = count * 100.0 / N.
 * [中文] 思路:
 *     一次迴圈求總分與平均值，二次迴圈統計嚴格大於平均值的人數，計算百分比。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double solve_uva10370(int n, const int *scores) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += scores[i];
    double avg = (double)sum / n;
    int above = 0;
    for (int i = 0; i < n; i++) if (scores[i] > avg) above++;
    return (above * 100.0) / n;
}

int main(void) {

    int s[5] = {50, 50, 70, 80, 100};
    double p = solve_uva10370(5, s);
    int ok = (fabs(p - 40.0) < 1e-4);
    printf("%s: UVa 10370 - Above Average\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
