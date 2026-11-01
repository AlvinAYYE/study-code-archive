/*
 * ==========================================================================
 * UVa 1062 - Containers
 * Title-CN: 貨櫃堆疊
 * Difficulty: Medium
 * Tags: Greedy, LIS
 * URL: https://onlinejudge.org/external/10/1062.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the minimum number of container stacks required to load cargo onto ships in alphabetical order.
 *
 * [中文] 題目概述:
 *     求最少需要多少個堆疊來放置貨櫃，使得所有貨櫃能依字母順序被裝船。
 *
 * [EN] Approach:
 *     Greedily place each incoming container onto the top of the stack whose top letter is >= container letter with minimal difference; otherwise open a new stack.
 * [中文] 解題思路:
 *     貪心法：每個貨櫃放在頂部字元大於等於該貨櫃且頂部字元最小的堆疊上，若無合適堆疊則開啟新堆疊。
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

int min_container_stacks(const char *s) {
    char stacks[30];
    int num_stacks = 0;
    for (int i = 0; s[i]; i++) {
        int best_idx = -1;
        char best_top = 127;
        for (int j = 0; j < num_stacks; j++) {
            if (stacks[j] >= s[i] && stacks[j] < best_top) {
                best_top = stacks[j];
                best_idx = j;
            }
        }
        if (best_idx != -1) {
            stacks[best_idx] = s[i];
        } else {
            stacks[num_stacks++] = s[i];
        }
    }
    return num_stacks;
}

int main(void) {

    int ok = (min_container_stacks("A") == 1) && (min_container_stacks("CBACBACBACBA") == 3);
    printf("%s: UVa 1062 - Containers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
