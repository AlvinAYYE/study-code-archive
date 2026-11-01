/*
 * ==========================================================================
 * UVa 735 - Dart-a-Mania
 * Title-CN: 飛鏢大狂熱 (3鏢得分組合與排列)
 * Difficulty: Easy
 * Tags: Brute Force, Math, Combinatorics
 * URL: https://onlinejudge.org/external/7/735.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the number of combinations and permutations of 3 dart throws (scores 1..20 single/double/triple, bullseye 50, or miss 0) that sum to score S.
 *
 * [中文] 題目說明:
 *     投擲 3 支飛鏢，得分為 1~20 的 1/2/3 倍、外紅心 50 或脫靶 0 分，求總分恰好為 S 的相異得分組合數與排列數。
 *
 * [EN] Approach:
 *     Generate sorted list of distinct single-dart scores (43 values). Triple loops over all scores. Count combinations (i <= j <= k) and corresponding permutations.
 * [中文] 思路:
 *     收集所有 43 種單鏢得分值並排序，三重迴圈枚舉 (i <= j <= k) 滿足三鏢和為 S 的組合，並根據三數相同/兩數相同/三數相異累計排列數。
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

void dart_mania(int s, int *comb, int *perm) {
    int scores[65], s_cnt = 0;
    bool seen[65] = {false};
    scores[s_cnt++] = 0; seen[0] = true;
    scores[s_cnt++] = 50; seen[50] = true;
    for (int i = 1; i <= 20; i++) {
        for (int m = 1; m <= 3; m++) {
            int sc = i * m;
            if (!seen[sc]) { seen[sc] = true; scores[s_cnt++] = sc; }
        }
    }
    // sort
    for (int i = 0; i < s_cnt - 1; i++)
        for (int j = i + 1; j < s_cnt; j++)
            if (scores[i] > scores[j]) { int t = scores[i]; scores[i] = scores[j]; scores[j] = t; }
    *comb = 0; *perm = 0;
    for (int i = 0; i < s_cnt; i++) {
        for (int j = i; j < s_cnt; j++) {
            for (int k = j; k < s_cnt; k++) {
                if (scores[i] + scores[j] + scores[k] == s) {
                    (*comb)++;
                    if (scores[i] == scores[j] && scores[j] == scores[k]) *perm += 1;
                    else if (scores[i] == scores[j] || scores[j] == scores[k] || scores[i] == scores[k]) *perm += 3;
                    else *perm += 6;
                }
            }
        }
    }
}

int main(void) {

    int c, p;
    dart_mania(180, &c, &p); // 60 + 60 + 60
    int ok = (c == 1 && p == 1);
    printf("%s: UVa 735 - Dart-a-Mania\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
