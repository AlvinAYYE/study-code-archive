/*
 * ==========================================================================
 * UVa 384 - Slurmys
 * Title-CN: 外星字串文法解析 (Slump, Slimp, Slurpy)
 * Difficulty: Medium
 * Tags: String, Grammar, Parsing
 * URL: https://onlinejudge.org/external/3/384.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a string is a Slurpy, which consists of a Slimp followed by a Slump.
 *
 * [中文] 題目描述:
 *     解析特定外星文法：判斷字串是否為 Slurpy（由一個 Slimp 後接一個 Slump 組成）。
 *
 * [EN] Approach:
 *     Recursively check Slump and Slimp grammar rules according to the specification.
 *
 * [中文] 解題思維:
 *     根據 Slump 和 Slimp 的形式文法定義，分別編寫遞歸解析函數判斷前綴與後綴。
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

static int check_slump(const char *s, int start, int end) {
    if (start >= end) return 0;
    if (s[start] != 'D' && s[start] != 'E') return 0;
    int i = start + 1;
    if (i >= end || s[i] != 'F') return 0;
    while (i < end && s[i] == 'F') i++;
    if (i == end) return 0;
    if (s[i] == 'G' && i == end - 1) return 1;
    return check_slump(s, i, end);
}

static int check_slimp(const char *s, int start, int end) {
    int len = end - start;
    if (len < 2 || s[start] != 'A') return 0;
    if (len == 2 && s[start + 1] == 'H') return 1;
    if (s[end - 1] != 'C') return 0;
    if (s[start + 1] == 'B') {
        return check_slimp(s, start + 2, end - 1);
    }
    return check_slump(s, start + 1, end - 1);
}

int is_slurpy(const char *s) {
    int len = (int)strlen(s);
    for (int i = 2; i < len; i++) {
        if (check_slimp(s, 0, i) && check_slump(s, i, len)) return 1;
    }
    return 0;
}

int main(void) {

    int ok = is_slurpy("AHDFG") &&
             is_slurpy("ADFGCDFG") &&
             !is_slurpy("ABCDEFG");
    printf("%s: UVa 384 - Slurmys\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
