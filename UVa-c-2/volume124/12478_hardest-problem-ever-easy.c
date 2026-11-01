/*
 * ==========================================================================
 * UVa 12478 - Hardest Problem Ever (Easy)
 * Title-CN: 史上最難題目之解答常數輸出
 * Difficulty: UVa Star 1
 * Tags: basics
 * URL: https://onlinejudge.org/external/124/12478.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the only grid-hidden name that appears twice in the given word grid. Output the name directly.
 *
 * [中文] 題目說明:
 *     找出題目九宮格單詞網格中唯一出現過兩次的名字並直接印出解答 (KABIR)。
 *
 * [EN] Approach:
 *     Print 'KABIR' directly as per problem definition.
 * [中文] 思路:
 *     依據題意分析直接回傳常數字串 "KABIR"。
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

const char* solve_uva12478(void) {
    return "KABIR";
}

int main(void) {

    int ok = (strcmp(solve_uva12478(), "KABIR") == 0);
    printf("%s: UVa 12478 - Hardest Problem Ever (Easy)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
