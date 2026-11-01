/*
 * ==========================================================================
 * UVa 556 - Amazing
 * Title-CN: 走迷宮 (右手摸牆法則步數統計)
 * Difficulty: Medium
 * Tags: Simulation, Maze, Grid
 * URL: https://onlinejudge.org/external/5/556.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate a robot traversing a maze following the right-hand wall rule until returning to start.
 *
 * [中文] 題目描述:
 *     模擬機器人以右手貼牆法則在迷宮中行走直到返回起點與初始朝向，統計各空格被拜訪的次數分佈。
 *
 * [EN] Approach:
 *     Robot starts at bottom-left facing East. Turn right if wall absent on right, otherwise move straight or turn left.
 *
 * [中文] 解題思維:
 *     機器人初始在左下角面朝東，優先嘗試向右轉，若右方有牆則嘗試前進，受阻則左轉，統計 0..4 次拜訪格數。
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

static const int dr556[] = {0, -1, 0, 1}; // 0: East, 1: North, 2: West, 3: South
static const int dc556[] = {1, 0, -1, 0};

void solve_amazing(int R, int C, const char maze[55][55], int hist[5]) {
    int visits[55][55];
    memset(visits, 0, sizeof(visits));
    memset(hist, 0, sizeof(int) * 5);

    int r = R - 1, c = 0, d = 0; // East
    int sr = r, sc = c;

    do {
        // Try turning right first: (d + 3) % 4
        int rd = (d + 3) % 4;
        int rr = r + dr556[rd], rc = c + dc556[rd];
        if (rr >= 0 && rr < R && rc >= 0 && rc < C && maze[rr][rc] == '0') {
            d = rd;
            r = rr; c = rc;
            visits[r][c]++;
        } else {
            // Try going straight
            int fr = r + dr556[d], fc = c + dc556[d];
            if (fr >= 0 && fr < R && fc >= 0 && fc < C && maze[fr][fc] == '0') {
                r = fr; c = fc;
                visits[r][c]++;
            } else {
                // Turn left
                d = (d + 1) % 4;
            }
        }
    } while (!(r == sr && c == sc && d == 0));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == '0') {
                int v = visits[i][j];
                if (v < 5) hist[v]++;
            }
        }
    }
}

int main(void) {

    char m[55][55] = {
        "00",
        "00"
    };
    int hist[5];
    solve_amazing(2, 2, m, hist);
    // Simple 2x2 loop visits all 4 cells
    int ok = (hist[0] == 0);
    printf("%s: UVa 556 - Amazing\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
