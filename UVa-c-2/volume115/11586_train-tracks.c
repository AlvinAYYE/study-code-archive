/*
 * ==========================================================================
 * UVa 11586 - Train Tracks
 * Title-CN: 玩具火車軌道公母接頭閉合環路
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/115/11586.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Determine if toy train track pieces (with 'M' and 'F' male/female connectors) can form a single closed loop containing > 1 piece.
 *
 * [中文] 題目說明:
 *     判定由 'M' (公) 與 'F' (母) 接頭組成的玩具鐵軌零件是否能閉合成一個大於 1 節的封閉環路 (需 M 與 F 總數完全相等且大於 1 節)。
 *
 * [EN] Approach:
 *     Count total 'M' and 'F' characters. A closed loop is possible if and only if count(M) == count(F) and total pieces > 1.
 * [中文] 思路:
 *     統計字串中 'M' 與 'F' 的總個數，可成環的充要條件為 M 與 F 數量相等且總鐵軌節數大於 1。
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

int solve_uva11586(const char *tracks) {
    int m = 0, f = 0, pieces = 0;
    for (int i = 0; tracks[i]; i++) {
        if (tracks[i] == 'M') m++;
        else if (tracks[i] == 'F') f++;
        else if (tracks[i] == ' ') pieces++;
    }
    pieces++; // words count
    return (m == f && pieces > 1);
}

int main(void) {

    int ok = solve_uva11586("MF MF") && !solve_uva11586("MM FF FF");
    printf("%s: UVa 11586 - Train Tracks\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
