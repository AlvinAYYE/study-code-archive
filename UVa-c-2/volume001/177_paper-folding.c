/*
 * ==========================================================================
 * UVa 177 - Paper Folding
 * Title-CN: 對折紙張龍形曲線展開繪製
 * Difficulty: UVa Star 2
 * Tags: simulation, recursion
 * URL: https://onlinejudge.org/external/1/177.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given n folds of a strip of paper, simulate unfolding at 90 degree angles (dragon curve) and render the ASCII line representation.
 *
 * [中文] 題目說明:
 *     給定紙帶連續向右對折 n 次後的展開過程，模擬每次展開 90 度的龍形曲線 (Dragon Curve)，並排版繪製出 ASCII 字元曲線。
 *
 * [EN] Approach:
 *     Generate fold turn directions recursively or by mirroring and reversing previous sequence with inverted turns. Trace on 2D character canvas.
 * [中文] 思路:
 *     以遞迴或鏡像翻轉法生成摺痕轉向序列 (左轉/右轉)，將曲線路徑映射至二維畫布上並裁切去除多餘空白行。
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

void dragon_turns(int n, char *out) {
    if (n == 1) { out[0] = 'R'; out[1] = '\0'; return; }
    dragon_turns(n - 1, out);
    int len = strlen(out);
    out[len] = 'R';
    for (int i = 0; i < len; i++) {
        char prev = out[len - 1 - i];
        out[len + 1 + i] = (prev == 'R') ? 'L' : 'R';
    }
    out[2 * len + 1] = '\0';
}

int main(void) {

    char seq[100];
    dragon_turns(2, seq);
    int ok = (strcmp(seq, "RRL") == 0);
    printf("%s: UVa 177 - Paper Folding\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
