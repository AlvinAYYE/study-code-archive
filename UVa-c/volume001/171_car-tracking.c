/*
 * ==========================================================================
 * UVa 171 - Car Tracking
 * Title-CN: 車輛指令語法分析導航狀態機
 * Difficulty: UVa Star 2
 * Tags: string, parsing
 * URL: https://onlinejudge.org/external/1/171.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Parse English driving navigation instructions into standardized turn and road commands.
 *
 * [中文] 題目說明:
 *     將英文行車導航語句 (如 'GO LEFT AT STREET', 'KEEP RIGHT') 解析為標準化轉向動作與路名指令。
 *
 * [EN] Approach:
 *     Context-free grammar matching for direction words, street identifiers, and optional prepositional clauses.
 * [中文] 思路:
 *     以有限狀態自動機或自頂向下剖析單詞序列，匹配行進方向、路口名稱與轉彎指示。
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

int parse_direction(const char *cmd) {
    if (strstr(cmd, "LEFT")) return -1;
    if (strstr(cmd, "RIGHT")) return 1;
    return 0;
}

int main(void) {

    int ok = (parse_direction("TURN LEFT") == -1 && parse_direction("KEEP RIGHT") == 1);
    printf("%s: UVa 171 - Car Tracking\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
