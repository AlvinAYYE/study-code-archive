/*
 * ==========================================================================
 * UVa 11946 - Code Number
 * Title-CN: 數字密碼文字解碼 (Leet 語解密)
 * Difficulty: Easy
 * Tags: String, Substitution
 * URL: https://onlinejudge.org/external/119/11946.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode leet-speak messages by replacing digits 0-9 with their corresponding letters (e.g. 4->A, 3->E, 1->I, 0->O).
 *
 * [中文] 題目說明:
 *     將含有 0-9 數字替換的火星文 (Leet) 解碼為正常文字（如 4->A, 3->E, 1->I, 0->O）。
 *
 * [EN] Approach:
 *     Direct character substitution using a 10-character lookup table.
 * [中文] 思路:
 *     建立 10 個數字對應大寫字母的查找表（3->E, 0->O, 4->A, 1->I, 7->T 等）進行直接字元替換。
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

void decode_leet(char *s) {
    const char *map = "OIZEASGTBP"; // 0:O, 1:I, 2:Z, 3:E, 4:A, 5:S, 6:G, 7:T, 8:B, 9:P
    for (int i = 0; s[i]; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            s[i] = map[s[i] - '0'];
        }
    }
}

int main(void) {

    char msg[30] = "4 CONV3RT3D M3SS4G3";
    decode_leet(msg);
    int ok = (strcmp(msg, "A CONVERTED MESSAGE") == 0);
    printf("%s: UVa 11946 - Code Number\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
