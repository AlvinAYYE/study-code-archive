/*
 * ==========================================================================
 * UVa 616 - Coconuts, Revisited
 * Title-CN: 椰子難題 (整數整除模擬)
 * Difficulty: Easy
 * Tags: Math, Simulation
 * URL: https://onlinejudge.org/external/6/616.pdf
 * ==========================================================================
 * [EN] Problem:
 *     N men and 1 monkey divide coconuts: each person divides remaining into N parts, gives 1 to monkey, hides his part. Morning division leaves 0 for monkey.
 *
 * [中文] 題目說明:
 *     N 個人與 1 隻猴子分椰子：每人各自將椰子等分 N 堆給猴子 1 顆並藏起 1 堆，隔天早晨恰好能等分給 N 人（猴子分得 0 顆），求最大人數 N。
 *
 * [EN] Approach:
 *     Try candidate number of people p downwards from ceil(sqrt(N)) down to 2. Simulate p divisions then 1 final division.
 * [中文] 思路:
 *     自 sqrt(total) + 1 向下枚舉人數 p，模擬 p 輪「減 1 後整除 p 且拿走 1/p」，隔日再整除 p，若皆合法即為最大人數。
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

int find_coconut_people(int total) {
    for (int p = 10; p >= 2; p--) {
        int cur = total;
        bool ok = true;
        for (int i = 0; i < p; i++) {
            if (cur % p != 1) { ok = false; break; }
            cur -= 1 + (cur / p);
        }
        if (ok && cur % p == 0) return p;
    }
    return -1;
}

int main(void) {

    int p = find_coconut_people(25);
    int ok = (p == 3);
    printf("%s: UVa 616 - Coconuts, Revisited\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
