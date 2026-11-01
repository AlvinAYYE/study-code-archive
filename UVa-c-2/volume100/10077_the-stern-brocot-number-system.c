/*
 * ==========================================================================
 * UVa 10077 - The Stern-Brocot Number System
 * Title-CN: Stern-Brocot 樹二分查找路徑
 * Difficulty: UVa Star 2
 * Tags: binary-search, math
 * URL: https://onlinejudge.org/external/100/10077.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Find the path of Left ('L') and Right ('R') branch choices in the Stern-Brocot tree to reach a given fraction M/N.
 *
 * [中文] 題目說明:
 *     給定最簡真分數或假分數 M/N，求出在 Stern-Brocot 二元樹中自根節點 1/1 到達該分數的左右分支出路徑 (L/R 字串)。
 *
 * [EN] Approach:
 *     Binary search on mediants (a+c)/(b+d). If target < mediant, output 'L' and update right boundary; else output 'R'.
 * [中文] 思路:
 *     利用中間分數 (a+c)/(b+d) 進行二分搜尋：目標較小則輸出 'L' 並更新右邊界，目標較大則輸出 'R' 並更新左邊界。
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

void solve_uva10077(long long m, long long n, char *out) {
    long long al = 0, bl = 1, ar = 1, br = 0;
    int idx = 0;
    while (1) {
        long long am = al + ar, bm = bl + br;
        if (m == am && n == bm) break;
        if (m * bm < am * n) {
            out[idx++] = 'L';
            ar = am; br = bm;
        } else {
            out[idx++] = 'R';
            al = am; bl = bm;
        }
    }
    out[idx] = '\0';
}

int main(void) {

    char path[100];
    solve_uva10077(5, 7, path);
    int ok = (strcmp(path, "LRRL") == 0);
    printf("%s: UVa 10077 - The Stern-Brocot Number System\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
