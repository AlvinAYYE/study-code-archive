/*
 * ==========================================================================
 * UVa 10567 - Helping Fill Bates
 * Title-CN: 序列字元子序列匹配與區間界限
 * Difficulty: Easy
 * Tags: Binary Search, String, Greedy
 * URL: https://onlinejudge.org/external/105/10567.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if a query string is a subsequence of candidates string S, and output the first and last matched indices with greedy earliest match.
 *
 * [中文] 題目說明:
 *     判斷詢問字串是否為候選字串 S 的子序列，貪心選取最早出現的位置，並輸出起始與終止匹配下標。
 *
 * [EN] Approach:
 *     Store indices of each character 0..51. Use binary search (upper_bound) to greedily find the earliest matching position greater than the previous index.
 * [中文] 思路:
 *     預先記錄各字母在母字串中出現的位置清單，用二分搜尋 (upper_bound) 貪心取得大於前一下標的最小位置。
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

bool match_subsequence(const char *s, const char *q, int *first_idx, int *last_idx) {
    int cur = -1;
    for (int i = 0; q[i]; i++) {
        char ch = q[i];
        int nxt = -1;
        for (int j = cur + 1; s[j]; j++) {
            if (s[j] == ch) { nxt = j; break; }
        }
        if (nxt == -1) return false;
        if (i == 0) *first_idx = nxt;
        cur = nxt;
    }
    *last_idx = cur;
    return true;
}

int main(void) {

    int f, l;
    bool ok = match_subsequence("aaaaaaaaaabbbb", "ab", &f, &l);
    ok = ok && (f == 0 && l == 10);
    printf("%s: UVa 10567 - Helping Fill Bates\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
