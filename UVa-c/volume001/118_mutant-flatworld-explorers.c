/*
 * ==========================================================================
 * UVa 118 - Mutant Flatworld Explorers
 * Title-CN: 異變的扁平世界探險家
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: simulation, grid
 * URL: https://onlinejudge.org/external/1/118.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Simulate grid robot exploration with scents dropped on edge falls.
 *
 * [中文] 題目說明:
 *     模擬網格上的機器人前進與轉彎，若掉出邊界留下標記。
 *
 * [EN] Approach: Direction vectors with scent matrix.
 * [中文] 思路: 用 dx, dy 陣列控制 4 個方向移動，維護掉落標記防止重複掉落。
 * ==========================================================================
 */
#include <stdio.h>

static const int dx[4] = {0, 1, 0, -1}; /* N, E, S, W */
static const int dy[4] = {1, 0, -1, 0};
static const char dirs[4] = {'N', 'E', 'S', 'W'};

static int direction_index(char direction) {
    int i;
    for (i = 0; i < 4; i++) {
        if (dirs[i] == direction) {
            return i;
        }
    }
    return 0;
}

void solve_uva118(FILE *in, FILE *out) {
    unsigned char scent[51][51] = {{0}};
    int maximum_x;
    int maximum_y;
    int x;
    int y;
    char facing;

    if (fscanf(in, "%d %d", &maximum_x, &maximum_y) != 2) {
        return;
    }

    while (fscanf(in, "%d %d %c", &x, &y, &facing) == 3) {
        char instructions[1024];
        int direction = direction_index(facing);
        int lost = 0;
        int i;

        if (fscanf(in, "%1023s", instructions) != 1) {
            break;
        }

        for (i = 0; instructions[i] != '\0' && !lost; i++) {
            if (instructions[i] == 'L') {
                direction = (direction + 3) % 4;
            } else if (instructions[i] == 'R') {
                direction = (direction + 1) % 4;
            } else if (instructions[i] == 'F') {
                int next_x = x + dx[direction];
                int next_y = y + dy[direction];

                if (next_x < 0 || next_x > maximum_x || next_y < 0 || next_y > maximum_y) {
                    if (x >= 0 && x <= 50 && y >= 0 && y <= 50 && scent[x][y]) {
                        continue;
                    }
                    if (x >= 0 && x <= 50 && y >= 0 && y <= 50) {
                        scent[x][y] = 1;
                    }
                    lost = 1;
                } else {
                    x = next_x;
                    y = next_y;
                }
            }
        }

        fprintf(out, "%d %d %c%s\n", x, y, dirs[direction], lost ? " LOST" : "");
    }
}

int main(void) {
    solve_uva118(stdin, stdout);
    return 0;
}
