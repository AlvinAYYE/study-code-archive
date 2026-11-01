/*
 * ==========================================================================
 * UVa 10346 - Peter's Smokes
 * Title-CN: 彼得的香菸 (菸蒂兌換模擬)
 * Difficulty: UVa Star 1
 * Tags: math, simulation
 * URL: https://onlinejudge.org/external/103/10346.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Peter has n cigarettes. He can exchange k cigarette butts for 1 new cigarette. Find total cigarettes smoked.
 *
 * [中文] 題目說明:
 *     彼得有 n 支香菸，每抽完一支產生一個菸蒂。每收集 k 個菸蒂可兌換 1 支新香菸，求彼得總共能抽多少支菸。
 *
 * [EN] Approach:
 *     Loop simulation: total += n, butts = n. In each step, new_cigs = butts / k, butts = butts % k + new_cigs.
 * [中文] 思路:
 *     模擬兌換流程：只要菸蒂數 butts >= k，兌換新菸 new_c = butts / k，累加抽菸總數，更新剩餘菸蒂 butts % k + new_c。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long solve_uva10346(long long n, long long k) {
    long long total = n, butts = n;
    while (butts >= k) {
        long long new_c = butts / k;
        total += new_c;
        butts = (butts % k) + new_c;
    }
    return total;
}

int main(void) {

    int ok = (solve_uva10346(4, 3) == 5) && (solve_uva10346(10, 3) == 14);
    printf("%s: UVa 10346 - Peter's Smokes\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
