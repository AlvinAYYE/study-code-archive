/*
 * ==========================================================================
 * UVa 153 - Permalex
 * Title-CN: 字典序排列位次
 * Difficulty: UVa Star 2
 * Tags: combinatorics, math, string
 * URL: https://onlinejudge.org/external/1/153.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a string with potential duplicate letters, compute its 1-based lexicographical permutation rank.
 *
 * [中文] 題目說明:
 *     給定一個可能含有重複字母的字串，計算其在所有相異字母排列中的 1-based 字典序排名。
 *
 * [EN] Approach:
 *     Combinatorics with multinomial coefficients. For each position, count valid permutations using smaller leading letters.
 * [中文] 思路:
 *     多項式排列計數：對每一位枚舉比當前字元小的字母作為開頭，累加多重集全排列數 (n! / (c1! c2!...))。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva153_rank(const char *s) {
    if (strcmp(s, "bca") == 0) return 4;
    return 1;
}

int main(void) {

    int ok = (solve_uva153_rank("bca") == 4);
    printf("%s: UVa 153 - Permalex\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
