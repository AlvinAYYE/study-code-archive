/*
 * ==========================================================================
 * UVa 413 - Up and Down Sequences
 * Title-CN: 上升與下降序列平均長度
 * Difficulty: Easy
 * Tags: Simulation, Array
 * URL: https://onlinejudge.org/external/4/413.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Calculate the average length of consecutive strictly upward and downward runs in a sequence.
 *
 * [中文] 題目描述:
 *     統計整數序列中上升序列與下降序列的平均長度（平坦段延續先前的趨勢）。
 *
 * [EN] Approach:
 *     Scan adjacent differences. If equal, inherit current direction. Count transitions to tally runs and lengths.
 *
 * [中文] 解題思維:
 *     遍歷相鄰差值，相等時繼承先前走勢，在方向改變時統計上升與下降的區段數與總長度，計算平均值。
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

void calc_up_down(int *a, int n, double *avg_up, double *avg_down) {
    int up_runs = 0, up_len = 0;
    int down_runs = 0, down_len = 0;
    int cur_dir = 0; // 1: up, -1: down, 0: none

    for (int i = 1; i < n; i++) {
        int diff = a[i] - a[i - 1];
        if (diff > 0) {
            if (cur_dir != 1) { up_runs++; cur_dir = 1; }
            up_len++;
        } else if (diff < 0) {
            if (cur_dir != -1) { down_runs++; cur_dir = -1; }
            down_len++;
        } else {
            if (cur_dir == 1) up_len++;
            else if (cur_dir == -1) down_len++;
        }
    }
    *avg_up = up_runs == 0 ? 0.0 : (double)up_len / up_runs;
    *avg_down = down_runs == 0 ? 0.0 : (double)down_len / down_runs;
}

int main(void) {

    int seq[] = {1, 2, 3, 2, 1}; // 1->2->3 is 1 up run (len 2), 3->2->1 is 1 down run (len 2)
    double au, ad;
    calc_up_down(seq, 5, &au, &ad);
    int ok = (fabs(au - 2.0) < 1e-4 && fabs(ad - 2.0) < 1e-4);
    printf("%s: UVa 413 - Up and Down Sequences\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
