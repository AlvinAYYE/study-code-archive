/*
 * ==========================================================================
 * UVa 10507 - Waking up brain
 * Title-CN: 大腦喚醒過程
 * Difficulty: Medium
 * Tags: Graph, Simulation, BFS
 * URL: https://onlinejudge.org/external/105/10507.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Direct stimulation wakes up 3 areas. A dormant area wakes up if connected to at least 3 awake areas. Find years to awaken all areas.
 *
 * [中文] 題目說明:
 *     直接刺激喚醒 3 個腦區。未醒腦區若連接至少 3 個已醒腦區則一年後甦醒，求全部甦醒所需年數。
 *
 * [EN] Approach:
 *     Simulate round by round: find all dormant areas connected to >= 3 awake areas, awaken them simultaneously. Stop when none wake up.
 * [中文] 思路:
 *     逐輪模擬：找出所有與 >= 3 個已醒腦區相連的休眠區，同步喚醒。若無法再喚醒則結束並檢查是否全部甦醒。
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

int wake_brain(int total, int adj[26][26], int *awake) {
    int years = 0;
    int awake_count = 0;
    for (int i = 0; i < 26; i++) if (awake[i]) awake_count++;
    while (awake_count < total) {
        int to_wake[26] = {0};
        int newly_woken = 0;
        for (int i = 0; i < 26; i++) {
            if (!awake[i]) {
                int conn = 0;
                for (int j = 0; j < 26; j++) {
                    if (adj[i][j] && awake[j]) conn++;
                }
                if (conn >= 3) { to_wake[i] = 1; newly_woken++; }
            }
        }
        if (newly_woken == 0) return -1; // brain never wakes up
        for (int i = 0; i < 26; i++) if (to_wake[i]) awake[i] = 1;
        awake_count += newly_woken;
        years++;
    }
    return years;
}

int main(void) {

    int adj[26][26] = {0}, awake[26] = {0};
    awake[0] = awake[1] = awake[2] = 1; // A, B, C awake
    adj[3][0] = adj[0][3] = 1; // D connected to A, B, C
    adj[3][1] = adj[1][3] = 1;
    adj[3][2] = adj[2][3] = 1;
    int yrs = wake_brain(4, adj, awake);
    int ok = (yrs == 1);
    printf("%s: UVa 10507 - Waking up brain\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
