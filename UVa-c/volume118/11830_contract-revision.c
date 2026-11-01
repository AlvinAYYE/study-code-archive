/*
 * ==========================================================================
 * UVa 11830 - Contract Revision
 * Title-CN: 合約修訂 (過濾故障數位字元)
 * Difficulty: Easy
 * Tags: String, Simulation
 * URL: https://onlinejudge.org/external/118/11830.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A typewriter's digit key D is broken and does not type. Given digit D and original contract number string N, output the resulting number (stripping leading zeros).
 *
 * [中文] 題目說明:
 *     打字機的某個數字鍵 D 故障無法印出，給定故障鍵 D 與原合約數字 N，輸出修訂後的數值（去除前導 0，若全被刪除則為 0）。
 *
 * [EN] Approach:
 *     Filter out char D from string N. Remove leading zeros. If empty, output '0'.
 * [中文] 思路:
 *     過濾掉字串中的所有字元 D，去除前導零；若字串為空則輸出 '0'。
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

void revise_contract(char d, const char *n, char *out) {
    char buf[105];
    int len = 0;
    for (int i = 0; n[i]; i++) {
        if (n[i] != d) buf[len++] = n[i];
    }
    buf[len] = '\0';
    int p = 0;
    while (p < len && buf[p] == '0') p++;
    if (p == len) strcpy(out, "0");
    else strcpy(out, buf + p);
}

int main(void) {

    char out[105];
    revise_contract('5', "5000000", out);
    int ok = (strcmp(out, "0") == 0);
    revise_contract('3', "12345", out);
    ok = ok && (strcmp(out, "1245") == 0);
    printf("%s: UVa 11830 - Contract Revision\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
