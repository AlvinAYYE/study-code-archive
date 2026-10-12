/*
 * ==========================================================================
 * UVa 10370 - Above Average
 * Title-CN: 高於平均成績百分比
 * Difficulty: UVa Star 1
 * Tags: math, array
 * URL: https://onlinejudge.org/external/103/10370.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate percentage of students whose grades are strictly above class average.
 *
 * [中文] 題目說明:
 *     計算全班成績嚴格高於平均分數的學生百分比，四捨五入至小數點後三位。
 *
 * [EN] Approach: Compute sum and average, count grades > avg, output count / n * 100.0.
 * [中文] 思路: 算出總分與平均值，統計高於平均人數並計算百分比。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

double solve_uva10370(int n, const int *scores) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += scores[i];
    double avg = (double)sum / n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (scores[i] > avg) count++;
    }
    return (double)count * 100.0 / n;
}

int main(void) {
    int s1[5] = {50, 50, 70, 80, 100}; /* avg = 70. 80 and 100 are > 70 -> 2/5 = 40% */
    double pct = solve_uva10370(5, s1);
    int ok = (fabs(pct - 40.0) < 1e-4);
    printf("%s: UVa 10370 - Above Average\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
