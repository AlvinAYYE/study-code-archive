/*
 * ==========================================================================
 * UVa 12195 - Jingle Composing
 * Title-CN: 小調作曲小節拍數驗證
 * Difficulty: UVa Star 1
 * Tags: simulation, string
 * URL: https://onlinejudge.org/external/121/12195.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count number of measures in musical composition where note duration fractions sum up to exactly 1 whole note (64/64).
 *
 * [中文] 題目說明:
 *     檢驗樂譜字串中音符拍數加總恰好等於 1 個全音符 (64/64 拍) 的完整小節數量。
 *
 * [EN] Approach:
 *     Map notes to 64ths: W=64, H=32, Q=16, E=8, S=4, T=2, X=1. Sum measures delimited by '/', count sums == 64.
 * [中文] 思路:
 *     將音符時值通分為 64 分音符整數：W=64, H=32, Q=16, E=8, S=4, T=2, X=1。以 '/' 分割小節，統計拍數和恰為 64 的小節數。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int note_val_12195(char c) {
    if (c == 'W') return 64;
    if (c == 'H') return 32;
    if (c == 'Q') return 16;
    if (c == 'E') return 8;
    if (c == 'S') return 4;
    if (c == 'T') return 2;
    if (c == 'X') return 1;
    return 0;
}

int main(void) {

    int ok = (note_val_12195('W') == 64) && (note_val_12195('H') + note_val_12195('H') == 64);
    printf("%s: UVa 12195 - Jingle Composing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
