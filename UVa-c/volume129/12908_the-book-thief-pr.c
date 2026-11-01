/*
 * ==========================================================================
 * UVa 12908 - The book thief
 * Title-CN: 偷書賊漏頁還原 (等差級數求和定位)
 * Difficulty: UVa Star 1
 * Tags: math, binary-search
 * URL: https://onlinejudge.org/external/129/12908.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given sum s with one page omitted, find the omitted page number and total pages n: n*(n+1)/2 > s.
 *
 * [中文] 題目說明:
 *     書本頁碼為 1 到 n，漏算了一頁導致總和為 s。求被漏掉的頁碼與整本書的總頁數 n。
 *
 * [EN] Approach:
 *     Find smallest n such that total = n*(n+1)/2 > s. Omitted page = total - s.
 * [中文] 思路:
 *     二分或根號求滿足 n*(n+1)/2 > s 的最小整數 n。漏掉的頁碼即為三角形數與當前和的差值：total - s。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <math.h>

void solve_uva12908(long long s, int *missing_page, int *total_pages) {
    long long n = (long long)ceil((-1.0 + sqrt(1.0 + 8.0 * (s + 1))) / 2.0);
    long long tot = n * (n + 1) / 2;
    if (tot == s) { n++; tot = n * (n + 1) / 2; }
    *missing_page = (int)(tot - s);
    *total_pages = (int)n;
}

int main(void) {

    int m, t;
    solve_uva12908(4, &m, &t); /* 1+2+3 = 6 -> omitted 2, total 3 */
    int ok = (m == 2 && t == 3);
    printf("%s: UVa 12908 - The book thief\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
