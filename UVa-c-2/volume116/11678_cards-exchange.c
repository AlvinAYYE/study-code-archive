/*
 * ==========================================================================
 * UVa 11678 - Cards' Exchange
 * Title-CN: 卡片交換 (不重複集合差集比較)
 * Difficulty: Easy
 * Tags: Set Operations, Simulation
 * URL: https://onlinejudge.org/external/116/11678.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Alice and Betty have collections of cards. They want to trade cards such that each receives cards they do not yet own. Find maximum number of traded cards.
 *
 * [中文] 題目描述:
 *     兩位小朋友各自收集卡片，希望進行一對一交換互補彼此沒有的卡片，求最多能公平交換幾張卡片。
 *
 * [EN] Approach:
 *     Remove duplicates to get unique sets A and B. Count unique cards in A not in B, and in B not in A. Answer is min(|A - B|, |B - A|).
 *
 * [中文] 解題思維:
 *     去重轉為集合 A 與 B，統計 A 中有而 B 沒有的卡片數及 B 中有而 A 沒有的卡片數，兩者取較小值即為最大交換張數。
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

int max_card_trades(int na, const int *a, int nb, const int *b) {
    bool has_a[1005] = {false}, has_b[1005] = {false};
    for (int i = 0; i < na; i++) has_a[a[i]] = true;
    for (int i = 0; i < nb; i++) has_b[b[i]] = true;
    int only_a = 0, only_b = 0;
    for (int i = 1; i <= 1000; i++) {
        if (has_a[i] && !has_b[i]) only_a++;
        if (has_b[i] && !has_a[i]) only_b++;
    }
    return (only_a < only_b ? only_a : only_b);
}

int main(void) {

    int a[] = {1, 1, 2, 3}, b[] = {2, 2, 2, 5};
    int trades = max_card_trades(4, a, 4, b); // A has {1,3} not in B; B has {5} not in A -> min(2, 1) = 1
    int ok = (trades == 1);
    printf("%s: UVa 11678 - Cards' Exchange\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
