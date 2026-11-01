/*
 * ==========================================================================
 * UVa 10132 - File Fragmentation
 * Title-CN: 檔案碎片拼接還原原始位元字串
 * Difficulty: UVa Star 2
 * Tags: string, brute-force
 * URL: https://onlinejudge.org/external/101/10132.pdf
 * ==========================================================================
 * [EN] Problem:
 *     A file was fragmented into 2N pieces (each file split into 2 fragments). Find the original bit pattern that can be formed by pairing all fragments.
 *
 * [中文] 題目概述:
 *     原始二進位檔案被切為 2 塊，共收集到 2N 個碎片，找出能將所有碎片兩兩配對成功還原的原始位元字串。
 *
 * [EN] Approach:
 *     Total original length = sum(len) / N. Pair the shortest fragment with all matching longest fragments to form candidate original strings, then verify consistency.
 * [中文] 解題思路:
 *     原始檔案長度為總碎片長度除以 N。將最短碎片與最長碎片拼接形成候選字串，驗證其是否能完整配對所有碎片。
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

int can_pair_all(int n_frags, char frags[][30], const char *target) {
    int vis[30] = {0};
    int tlen = strlen(target);
    for (int i = 0; i < n_frags; i++) {
        if (vis[i]) continue;
        int matched = 0;
        for (int j = i + 1; j < n_frags; j++) {
            if (!vis[j] && strlen(frags[i]) + strlen(frags[j]) == tlen) {
                char comb1[60], comb2[60];
                sprintf(comb1, "%s%s", frags[i], frags[j]);
                sprintf(comb2, "%s%s", frags[j], frags[i]);
                if (strcmp(comb1, target) == 0 || strcmp(comb2, target) == 0) {
                    vis[i] = 1; vis[j] = 1;
                    matched = 1;
                    break;
                }
            }
        }
        if (!matched) return 0;
    }
    return 1;
}

int main(void) {

    char f[4][30] = {"0", "11", "01", "1"};
    int ok = can_pair_all(4, f, "011");
    printf("%s: UVa 10132 - File Fragmentation\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
