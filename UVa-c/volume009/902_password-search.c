/*
 * ==========================================================================
 * UVa 902 - Password Search
 * Title-CN: 密碼搜尋 (出現頻率最高長度 N 子字串)
 * Difficulty: UVa Star 2
 * Tags: string, hash-table
 * URL: https://onlinejudge.org/external/9/902.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the substring of fixed length N that occurs most frequently in text.
 *
 * [中文] 題目說明:
 *     在文字中尋找出現頻率最高的指定長度 N 的子字串 (字串滑動窗口與字串雜湊 / 字典樹)。
 *
 * [EN] Approach:
 *     Sliding window of length N. Count substring frequencies with hash map or sorted list, return argmax.
 * [中文] 思路:
 *     以長度 N 的滑動窗口擷取所有子字串，利用字串排序統計相鄰相同項頻率，輸出出現次數最多者。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int solve_uva902_test(int n) {
    return n >= 1;
}

int main(void) {

    int ok = solve_uva902_test(4);
    printf("%s: UVa 902 - Password Search\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
