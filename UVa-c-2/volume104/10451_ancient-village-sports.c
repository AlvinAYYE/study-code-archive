/*
 * ==========================================================================
 * UVa 10451 - Ancient Village Sports
 * Title-CN: 古代村莊運動 (正多邊形外接圓與內切圓面積差)
 * Difficulty: Easy
 * Tags: Geometry, Math
 * URL: https://onlinejudge.org/external/104/10451.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given number of sides n and area A of a regular polygon, compute the spectator area (circumcircle - polygon) and officials area (polygon - incircle).
 *
 * [中文] 題目說明:
 *     給定正 n 邊形的邊數與面積 A，求外接圓與多邊形面積差（觀眾區）以及多邊形與內切圓面積差（官員區）。
 *
 * [EN] Approach:
 *     Formulas: A = 0.5 * n * R^2 * sin(2*pi/n) gives circumradius R; inradius r = R * cos(pi/n). Circumcircle = pi * R^2, Incircle = pi * r^2.
 * [中文] 思路:
 *     由多邊形面積求外接圓半徑 R 與內切圓半徑 r = R * cos(pi/n)，進而求出兩面積差。
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

void village_sports_areas(int n, double A, double *spectator, double *official) {
    double pi = 2.0 * acos(0.0);
    double theta = pi / n;
    double R2 = (2.0 * A) / (n * sin(2.0 * theta));
    double r2 = R2 * cos(theta) * cos(theta);
    double circum_area = pi * R2;
    double incircle_area = pi * r2;
    *spectator = circum_area - A;
    *official = A - incircle_area;
}

int main(void) {

    double spec, off;
    village_sports_areas(3, 100.0, &spec, &off);
    int ok = (spec > 0.0 && off > 0.0);
    printf("%s: UVa 10451 - Ancient Village Sports\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
