/*
 * ==========================================================================
 * UVa 10879 - Code Refactoring
 * Title-CN: 程式重構分解 (尋找兩組相異因數分解)
 * Difficulty: UVa Star 1
 * Tags: math, number-theory
 * URL: https://onlinejudge.org/external/108/10879.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given integer N with at least 16 divisors, find two distinct factorizations: N = A * B = C * D.
 *
 * [中文] 題目說明:
 *     給定含有至少 16 個因數的整數 N，尋找兩組相異的因數乘積對：N = A * B = C * D。
 *
 * [EN] Approach:
 *     Trial division from 2 upward: find first factor A, then next factor C. Output N = A * (N/A) = C * (N/C).
 * [中文] 思路:
 *     從 2 開始試除找出前兩個能整除 N 的因數 A 與 C，直接輸出兩組相異因數乘積。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve_uva10879(int n, int *a, int *b, int *c, int *d) {
    int found = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (found == 0) { *a = i; *b = n / i; found = 1; }
            else { *c = i; *d = n / i; break; }
        }
    }
}

int main(void) {

    int a, b, c, d;
    solve_uva10879(120, &a, &b, &c, &d);
    int ok = (a * b == 120 && c * d == 120 && a != c);
    printf("%s: UVa 10879 - Code Refactoring\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
