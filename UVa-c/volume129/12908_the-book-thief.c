/*
 * ==========================================================================
 * UVa 12908 - The book thief
 * Title-CN: 偷書賊
 * Difficulty: UVa Star 1
 * Tags: math
 * ==========================================================================
 * [EN] Problem: Given sum S of page numbers with one page missing, find missing page and total page count N.
 * [中文] 題目說明: 總共 N 頁的書漏掉 1 頁，給定剩餘頁碼總和 S，求漏掉的頁碼與總頁數 N。
 * [EN] Approach: Find smallest N such that N*(N+1)/2 > S. Missing page is N*(N+1)/2 - S.
 * [中文] 思路: 三角數大於 S 的最小 N 即為總頁數，差值即為漏掉的頁碼。
 * ==========================================================================
 */
#include <stdio.h>
#include <math.h>

void solve_uva12908(long long s, long long *missing, long long *total_pages) {
    long long n = (long long)floor(sqrt(2.0 * s));
    while (n * (n + 1) / 2 <= s) n++;
    *total_pages = n;
    *missing = n * (n + 1) / 2 - s;
}

int main(void) {
    long long m, n;
    solve_uva12908(4, &m, &n); /* 1+2+3 = 6, 6 - 4 = 2, total 3 pages */
    int ok = (m == 2 && n == 3);
    printf("%s: UVa 12908 - The book thief\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
