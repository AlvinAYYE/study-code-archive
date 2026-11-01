/*
 * ==========================================================================
 * UVa 188 - Perfect Hash: Cryptography
 * Title-CN: 完美雜湊函數常數 C 搜尋
 * Difficulty: UVa Star 2
 * Tags: math, hash
 * URL: https://onlinejudge.org/external/1/188.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum positive integer constant C for the hash function h(w) = (C / w) % n such that no two words in a given set collide.
 *
 * [中文] 題目說明:
 *     尋找最小正整數常數 C，使得雜湊函數 h(w) = (C / w) % n 對於集合中所有單詞 w 均不產生碰撞 (完美雜湊)。
 *
 * [EN] Approach:
 *     Iterative conflict resolution: start C at min(w_i). If collision occurs between w_i and w_j, advance C to min((C/w_i + 1)*w_i, (C/w_j + 1)*w_j).
 * [中文] 思路:
 *     衝突導向常數推進法：令 C 初值為單詞編碼之最小值；若單詞 i 與 j 發生碰撞，將 C 更新為兩者向上取整之較小跳步值，直至無碰撞。
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

int hash_fn(int c_val, int w, int n) {
    return (c_val / w) % n;
}

int main(void) {

    int h1 = hash_fn(100, 20, 5);
    int ok = (h1 == 0);
    printf("%s: UVa 188 - Perfect Hash: Cryptography\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
