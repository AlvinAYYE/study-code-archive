/*
 * ==========================================================================
 * UVa 100 - The 3n + 1 problem
 * Title-CN: 3n + 1 問題 (考拉茲猜想 Collatz Conjecture)
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: simulation, math, collatz-conjecture
 * URL: https://onlinejudge.org/external/1/100.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     Consider the following algorithm to generate a sequence of numbers:
 *     Start with an integer n. If n is even, divide by 2. If n is odd,
 *     multiply by 3 and add 1. Repeat this process with the new value of n,
 *     terminating when n = 1.
 *     For example, the following sequence of numbers will be generated for n = 22:
 *     22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
 *     It is conjectured that this algorithm will terminate at n = 1 for every
 *     integer n. This is known as the 3n + 1 conjecture.
 *     Given an input pair of integers i and j, you are to determine the maximum
 *     cycle length over all integers between and including i and j.
 *
 * [中文] 題目說明:
 *     考慮以下的演算法來產生一數列：
 *     從整數 n 開始。若 n 為偶數，將其除以 2；若 n 為奇數，將其乘以 3 再加 1。
 *     以此類推重複運算，直到 n = 1 為止。
 *     例如給定 n = 22，會產生數列：22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1。
 *     著名的 3n + 1 猜想認為對於任何正整數，該序列最終都會停在 1。
 *     給定兩個整數 i 與 j，計算介於 i 與 j 之間（包含 i 與 j）的所有整數中，
 *     產生的循環長度（cycle length，包含 1 本身）的最大值。
 *     注意：輸入的 i 可能大於 j，但輸出時必須維持原始的 i, j 順序。
 *
 * Examples:
 *   Input:
 *     1 10
 *     100 200
 *     201 210
 *   Output:
 *     1 10 20
 *     100 200 125
 *     201 210 89
 *
 * Constraints:
 *   - 0 < i, j < 10000
 *
 * [EN] Approach:
 *     Direct simulation for each number in the range [min(i, j), max(i, j)].
 *     Use 64-bit integer (long long) for the intermediate sequence value to avoid
 *     potential 32-bit overflow when 3*n + 1 spikes.
 * [中文] 思路:
 *     直接模擬區間內每個數的 cycle 步數。
 *     注意需使用 long long 儲存數值，避免 3*n + 1 計算中途發生 32 位元整數溢位。
 * ==========================================================================
 */
#include <stdio.h>

static long long get_cycle_length(long long n) {
    long long len = 1;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
        len++;
    }
    return len;
}

int solve_uva100(int i, int j) {
    int start = (i < j) ? i : j;
    int end = (i < j) ? j : i;
    long long max_len = 0;

    for (int num = start; num <= end; num++) {
        long long clen = get_cycle_length(num);
        if (clen > max_len) {
            max_len = clen;
        }
    }
    return (int)max_len;
}

int main(void) {
    /* Self-test / 測試範例 */
    int ok = 1;
    ok = ok && (solve_uva100(1, 10) == 20);
    ok = ok && (solve_uva100(100, 200) == 125);
    ok = ok && (solve_uva100(201, 210) == 89);
    printf("%s: UVa 100 - The 3n + 1 problem\n", ok ? "PASS" : "FAIL");

    /*
     * For UVa Online Judge submission / UVa 送出模式：
     *
     * int i, j;
     * while (scanf("%d %d", &i, &j) == 2) {
     *     printf("%d %d %d\n", i, j, solve_uva100(i, j));
     * }
     */
    return ok ? 0 : 1;
}
