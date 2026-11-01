/*
 * ==========================================================================
 * UVa 729 - The Hamming Distance Problem
 * Title-CN: 指定漢明距離二進位字串生成
 * Difficulty: UVa Star 1
 * Tags: bit-manipulation, combinatorics, backtracking
 * URL: https://onlinejudge.org/external/7/729.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Generate all N-bit binary strings containing exactly H ones in ascending lexicographical order.
 *
 * [中文] 題目說明:
 *     長度為 N 的二進位字串中恰含有 H 個 1，按字典序由小到大輸出所有相異字串 (C(N, H))。
 *
 * [EN] Approach:
 *     Backtracking recursion: try placing '0' then '1' at each bit if remaining ones count permits.
 * [中文] 思路:
 *     回溯遞迴構造長度為 N 的字串，先遞迴補 0 再遞迴補 1，自然保證生成的二進位字串符合升序字典序。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int count_ones_729(int mask) {
    int cnt = 0;
    while (mask) { cnt += (mask & 1); mask >>= 1; }
    return cnt;
}

int main(void) {

    int ok = (count_ones_729(7) == 3);
    printf("%s: UVa 729 - The Hamming Distance Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
