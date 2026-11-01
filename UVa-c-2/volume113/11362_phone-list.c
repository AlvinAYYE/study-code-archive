/*
 * ==========================================================================
 * UVa 11362 - Phone List
 * Title-CN: 電話號碼簿前綴無衝突檢驗
 * Difficulty: UVa Star 2
 * Tags: string, sorting
 * URL: https://onlinejudge.org/external/113/11362.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine whether a list of phone numbers is consistent, meaning no phone number is a prefix of another.
 *
 * [中文] 題目說明:
 *     檢驗電話號碼列表是否合法一致：任一電話號碼均不可為其他號碼的前綴。
 *
 * [EN] Approach:
 *     Sort phone number strings lexicographically. A number can only be a prefix of its immediate successor in sorted order.
 * [中文] 思路:
 *     將電話號碼字串按字典序排序，若存在前綴衝突，則前綴字串必然緊鄰出現在較長字串的前一個位置。
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

static int cmp_str(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int solve_uva11362(int n, char phones[][20]) {
    qsort(phones, n, sizeof(phones[0]), cmp_str);
    for (int i = 0; i < n - 1; i++) {
        int len = strlen(phones[i]);
        if (strncmp(phones[i], phones[i + 1], len) == 0) return 0; // conflict
    }
    return 1;
}

int main(void) {

    char p1[3][20] = {"911", "97625999", "91125426"};
    int ok = !solve_uva11362(3, p1);
    printf("%s: UVa 11362 - Phone List\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
