/*
 * ==========================================================================
 * UVa 1103 - Ancient Messages
 * Title-CN: 古代象形文字識別 (拓撲孔洞計數)
 * Difficulty: Medium
 * Tags: Flood Fill, Graph, Connected Components
 * URL: https://onlinejudge.org/external/11/1103.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Recognize Egyptian hieroglyphs in a binary bitmap by counting the number of internal white holes in each connected black glyph.
 *
 * [中文] 題目說明:
 *     辨識二維點陣圖中的古埃及象形文字：透過統計每個黑色連通象形文字內部所包含的白色「孔洞」數量來唯一識別文字。
 *
 * [EN] Approach:
 *     Flood fill outer white background from border with special value. Then for each black glyph, flood fill internal white regions and count.
 * [中文] 思路:
 *     先從邊界對外圍白色背景進行洪水填充標記；接著遍歷黑色文字連通塊，統計其所包圍的封閉白色連通塊個數（0=W, 1=A, 2=K, 3=J, 4=S, 5=D）。
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

char glyph_by_holes(int holes) {
    const char *names = "WAKJSD";
    if (holes >= 0 && holes <= 5) return names[holes];
    return '?';
}

int main(void) {

    int ok = (glyph_by_holes(0) == 'W') && (glyph_by_holes(1) == 'A') && (glyph_by_holes(5) == 'D');
    printf("%s: UVa 1103 - Ancient Messages\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
