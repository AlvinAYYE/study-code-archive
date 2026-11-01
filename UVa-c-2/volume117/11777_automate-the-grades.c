/*
 * ==========================================================================
 * UVa 11777 - Automate the Grades
 * Title-CN: 學生成績自動評等系統
 * Difficulty: UVa Star 1
 * Tags: basics, math
 * URL: https://onlinejudge.org/external/117/11777.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate total grade from Term 1 (20), Term 2 (20), Final (30), Attendance (10), and average of best 2 out of 3 quizzes (20). Output letter grade A-F.
 *
 * [中文] 題目說明:
 *     根據兩次期中考 (各佔20%)、期末考 (30%)、出席率 (10%) 與三次隨堂測驗取最高兩次平均 (20%) 計算學期總分並判定等第 (A/B/C/D/F)。
 *
 * [EN] Approach:
 *     Find sum of highest 2 quiz scores and divide by 2. Add all components and categorize into letter grade.
 * [中文] 思路:
 *     三次隨堂小考取最高兩次相加除以二，加上其餘項求得百分制總分，依照 90/80/70/60 分數線判定等第代碼。
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

char solve_uva11777(int t1, int t2, int fin, int att, int q1, int q2, int q3) {
    int q_sum = q1 + q2 + q3;
    int min_q = q1 < q2 ? (q1 < q3 ? q1 : q3) : (q2 < q3 ? q2 : q3);
    int quiz_avg = (q_sum - min_q) / 2;
    int total = t1 + t2 + fin + att + quiz_avg;
    if (total >= 90) return 'A';
    if (total >= 80) return 'B';
    if (total >= 70) return 'C';
    if (total >= 60) return 'D';
    return 'F';
}

int main(void) {

    char g = solve_uva11777(15, 18, 25, 8, 15, 12, 18);
    int ok = (g == 'B');
    printf("%s: UVa 11777 - Automate the Grades\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
