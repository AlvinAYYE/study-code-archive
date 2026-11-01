/*
 * ==========================================================================
 * UVa 1584 - Circular Sequence
 * Title-CN: 環狀 DNA 序列最小字典序表示法
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/15/1584.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a circular DNA sequence of length N, find its lexicographically smallest representation among all N cyclic rotations.
 *
 * [中文] 題目說明:
 *     環狀 DNA 序列由 A, C, G, T 組成，長度為 N，求其在所有 N 種循環旋轉切點下的最小字典序字串。
 *
 * [EN] Approach:
 *     Compare all N circular shifts in O(N^2) time or Booth's algorithm. Retain the minimal string.
 * [中文] 思路:
 *     枚舉全部 N 個起始切點位置，逐一比較循環位移子字串，保留並輸出字典序最小者。
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

void solve_uva1584(const char *dna, char *out) {
    int n = strlen(dna);
    int best = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c1 = dna[(i + j) % n], c2 = dna[(best + j) % n];
            if (c1 != c2) {
                if (c1 < c2) best = i;
                break;
            }
        }
    }
    for (int j = 0; j < n; j++) out[j] = dna[(best + j) % n];
    out[n] = '\0';
}

int main(void) {

    char b[50];
    solve_uva1584("CTCC", b); // "CCCT"
    int ok = (strcmp(b, "CCCT") == 0);
    printf("%s: UVa 1584 - Circular Sequence\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
