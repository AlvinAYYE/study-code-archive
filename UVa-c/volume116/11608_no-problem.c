/*
 * ==========================================================================
 * UVa 11608 - No Problem
 * Title-CN: 題庫題目產出與競賽出題供給檢驗
 * Difficulty: UVa Star 1
 * Tags: simulation
 * URL: https://onlinejudge.org/external/116/11608.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given initial problems in stock S and arrays of 12 months' problems created and required for contests, determine if each contest can be held.
 *
 * [中文] 題目說明:
 *     初始題庫有 S 題，給定一年 12 個月每個月新增產出的題目數與該月競賽所需題目數，判定每個月是否均能如期舉辦競賽。
 *
 * [EN] Approach:
 *     For month i: if stock >= req[i], print 'No problem! :D' and stock -= req[i], else print 'No problem. :('; then stock += created[i].
 * [中文] 思路:
 *     模擬每月出題：若題庫存量 >= 該月需求則扣減庫存並舉辦，否則跳過扣款；月末再將該月新產生的題目加入題庫庫存。
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

void solve_uva11608(int init_stock, int *created, int *needed, int *can_hold) {
    int stock = init_stock;
    for (int i = 0; i < 12; i++) {
        if (stock >= needed[i]) {
            can_hold[i] = 1;
            stock -= needed[i];
        } else {
            can_hold[i] = 0;
        }
        stock += created[i];
    }
}

int main(void) {

    int c[12] = {1, 2}, n[12] = {5, 3};
    int h[12];
    solve_uva11608(5, c, n, h); // Month 0: stock=5 >= 5 -> OK, stock=0+1=1. Month 1: 1 < 3 -> NO
    int ok = (h[0] == 1 && h[1] == 0);
    printf("%s: UVa 11608 - No Problem\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
