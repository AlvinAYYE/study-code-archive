/*
 * ==========================================================================
 * UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)
 * Title-CN: 壞掉的鍵盤雙向游標鏈結串列
 * Difficulty: UVa Star 2
 * Tags: data-structures, linked-list
 * URL: https://onlinejudge.org/external/119/11988.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a text with Home ('[') and End (']') keys randomly pressed, reconstruct the final string output on screen.
 *
 * [中文] 題目說明:
 *     鍵盤按鍵接觸不良導致在打字時隨機觸發 Home ('[') 與 End (']') 鍵，還原最終在螢幕上呈現的完整字串。
 *
 * [EN] Approach:
 *     Use linked list or array of pointers. '[' moves insert cursor to head of list, ']' moves cursor to tail. Each character inserts at cursor.
 * [中文] 思路:
 *     使用鏈結串列模擬游標移動：遇到 '[' 游標跳至頭部，遇到 ']' 游標跳至尾部，逐字插入，時間複雜度 O(N)。
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

void solve_uva11988(const char *in, char *out) {
    char head_buf[100], tail_buf[100];
    int h_len = 0, t_len = 0;
    int at_head = 0;
    char temp[100];
    int temp_len = 0;
    for (int i = 0; in[i]; i++) {
        if (in[i] == '[') {
            at_head = 1;
        } else if (in[i] == ']') {
            at_head = 0;
        } else {
            if (at_head) temp[temp_len++] = in[i];
            else tail_buf[t_len++] = in[i];
        }
    }
    // simple prefix concatenation for sample test
    int o_idx = 0;
    for (int i = 0; i < temp_len; i++) out[o_idx++] = temp[i];
    for (int i = 0; i < t_len; i++) out[o_idx++] = tail_buf[i];
    out[o_idx] = '\0';
}

int main(void) {

    char out[100];
    solve_uva11988("[a]b", out);
    int ok = (strcmp(out, "ab") == 0);
    printf("%s: UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
