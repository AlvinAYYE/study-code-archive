/*
 * ==========================================================================
 * UVa 11530 - SMS Typing
 * Title-CN: 手機簡訊按鍵次數統計
 * Difficulty: UVa Star 1
 * Tags: string
 * URL: https://onlinejudge.org/external/115/11530.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate the total number of keystrokes required to type a message on an old mobile phone with 12 keys.
 *
 * [中文] 題目說明:
 *     計算在九宮格功能性手機上輸入指定簡訊文字所需的按鍵總次數。
 *
 * [EN] Approach:
 *     Precompute the keystrokes needed for each character 'a'-'z' and space (' ': 1, 'a': 1, 'b': 2, 'c': 3, 's': 4, 'z': 4). Sum over string.
 * [中文] 思路:
 *     建立 26 個字母與空白鍵的按鍵次數對照表 (如 's' 與 'z' 為 4 次)，逐字累加簡訊字串所需之按鍵總數。
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

int solve_uva11530(const char *s) {
    int keys[26] = {
        1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4
    };
    int total = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') total += 1;
        else if (s[i] >= 'a' && s[i] <= 'z') total += keys[s[i] - 'a'];
    }
    return total;
}

int main(void) {

    int res = solve_uva11530("welcome to uva");
    int ok = (res > 0 && solve_uva11530("a") == 1 && solve_uva11530("b") == 2);
    printf("%s: UVa 11530 - SMS Typing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
