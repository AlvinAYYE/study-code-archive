/*
 * ==========================================================================
 * UVa 10790 - How Many Points of Intersection?
 * Title-CN: 有多少個交點？
 * Difficulty: Easy
 * Tags: Math, Combinatorics
 * URL: https://onlinejudge.org/external/107/10790.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given two parallel lines with a and b points respectively, every point on line 1 is connected to every point on line 2. Find the number of intersection points inside.
 *
 * [中文] 題目概述:
 *     兩條平行線上分別有 a 與 b 個點，線上每個點都與另一條線上的所有點相連，求兩線段之間內部交點的總數。
 *
 * [EN] Approach:
 *     Any 2 points on line 1 and 2 points on line 2 uniquely determine 1 internal intersection: C(a,2) * C(b,2).
 * [中文] 解題思路:
 *     在第一條線選取 2 個點，第二條線選取 2 個點，兩兩交叉剛好產生 1 個內部交點：C(a,2) * C(b,2)。
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

long long count_intersections(long long a, long long b) {
    return (a * (a - 1) / 2) * (b * (b - 1) / 2);
}

int main(void) {

    int ok = (count_intersections(2, 2) == 1) && (count_intersections(2, 3) == 3);
    printf("%s: UVa 10790 - How Many Points of Intersection?\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
