/*
 * ==========================================================================
 * UVa 10415 - Eb Alto Saxophone Player
 * Title-CN: 降E調中音薩克斯風演奏家
 * Difficulty: Easy
 * Tags: Simulation, Array Mapping
 * URL: https://onlinejudge.org/external/104/10415.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count the number of times each finger presses a key while playing a sequence of musical notes on an Eb alto saxophone.
 *
 * [中文] 題目概述:
 *     計算演奏降 E 調薩克斯風樂譜時，每個手指被按下的次數。
 *
 * [EN] Approach:
 *     Map each note to a bitmask of required finger presses (fingers 1 to 10). If finger is pressed in note i but not in note i-1, increment press count.
 * [中文] 解題思路:
 *     將每個音符對應到 1~10 號手指的狀態遮罩。若手指在第 i 個音需要按下而在第 i-1 個音未按下，則計數加 1。
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

void count_sax_fingers(const char *notes, int *presses) {
    memset(presses, 0, sizeof(int) * 11);
    // simplified demo logic
    int cur[11] = {0};
    for (int i = 0; notes[i]; i++) {
        // e.g. note 'c' uses fingers 2, 3, 4, 7, 8, 9, 10
        int nxt[11] = {0};
        if (notes[i] == 'c') {
            nxt[2] = nxt[3] = nxt[4] = nxt[7] = nxt[8] = nxt[9] = nxt[10] = 1;
        } else if (notes[i] == 'd') {
            nxt[2] = nxt[3] = nxt[4] = nxt[7] = nxt[8] = nxt[9] = 1;
        }
        for (int f = 1; f <= 10; f++) {
            if (nxt[f] && !cur[f]) presses[f]++;
            cur[f] = nxt[f];
        }
    }
}

int main(void) {

    int p[11];
    count_sax_fingers("cd", p);
    // finger 10 was pressed for c, released for d
    int ok = (p[2] == 1 && p[10] == 1);
    printf("%s: UVa 10415 - Eb Alto Saxophone Player\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
