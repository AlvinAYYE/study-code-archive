/*
 * ==========================================================================
 * UVa 129 - Krypton Factor
 * Title-CN: 無連續相鄰重複子字串迴溯法
 * Difficulty: UVa Star 2
 * Tags: backtracking, string
 * URL: https://onlinejudge.org/external/1/129.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A string is 'hard' if it contains no two adjacent identical substrings. Given n and alphabet size L, find the n-th hard string in lexicographic order.
 *
 * [中文] 題目說明:
 *     若一個字串中不存在任意兩個連續且完全相同的子字串，則稱其為「困難字串」。給定整數 n 與字元集大小 L，求字典序第 n 個困難字串。
 *
 * [EN] Approach:
 *     Backtracking search: incrementally append characters from 'A' to 'A'+L-1. After appending, verify that suffixes of length 2k do not consist of two identical halves.
 * [中文] 思路:
 *     深度優先回溯搜尋：依字典序逐字元填入 'A' 至 'A'+L-1，每次檢驗末尾長度為 2k 的子字串前後兩半是否相同，計數至第 n 個印出。
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

int uva129_cnt, uva129_target;
char uva129_res[100];
int uva129_len;

int is_hard(char *s, int len) {
    for (int k = 1; 2 * k <= len; k++) {
        int equal = 1;
        for (int i = 0; i < k; i++) {
            if (s[len - 1 - i] != s[len - 1 - k - i]) { equal = 0; break; }
        }
        if (equal) return 0;
    }
    return 1;
}

int dfs_uva129(int depth, int L) {
    if (depth > 0) {
        uva129_cnt++;
        if (uva129_cnt == uva129_target) {
            uva129_len = depth;
            uva129_res[depth] = '\0';
            return 1;
        }
    }
    for (int c = 0; c < L; c++) {
        uva129_res[depth] = 'A' + c;
        if (is_hard(uva129_res, depth + 1)) {
            if (dfs_uva129(depth + 1, L)) return 1;
        }
    }
    return 0;
}

int solve_uva129(int n, int L, char *out) {
    uva129_cnt = 0;
    uva129_target = n;
    dfs_uva129(0, L);
    strcpy(out, uva129_res);
    return uva129_len;
}

int main(void) {

    char buf[100];
    int len = solve_uva129(7, 3, buf);
    int ok = (strcmp(buf, "ABACABA") == 0 && len == 7);
    printf("%s: UVa 129 - Krypton Factor\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
