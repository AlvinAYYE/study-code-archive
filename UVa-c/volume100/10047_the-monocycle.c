/*
 * ==========================================================================
 * UVa 10047 - The Monocycle
 * Title-CN: 單輪車迷宮
 * Difficulty: UVa Star 2
 * Tags: graph, bfs, shortest-path
 * URL: https://onlinejudge.org/external/100/10047.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Shortest time for a monocycle (4 directions, 5 wheel colors) to reach target in green color.
 *
 * [中文] 題目說明:
 *     單輪車前進 1 格需 1 秒且輪子轉動換下一種顏色（共有 5 種顏色）；轉向 90 度需 1 秒。
 *     求抵達終點且輪子剛好轉到綠色（初始顏色）的最少秒數。
 *
 * [EN] Approach:
 *     BFS on state space (row, col, direction, color).
 * [中文] 思路:
 *     狀態空間 BFS：狀態定義為 (r, c, dir, color)，共 row * col * 4 * 5 種狀態。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 25
#define MAX_COLS 25
#define DIRECTION_COUNT 4
#define COLOR_COUNT 5
#define MAX_STATES (MAX_ROWS * MAX_COLS * DIRECTION_COUNT * COLOR_COUNT)

typedef struct {
    short row;
    short column;
    unsigned char direction;
    unsigned char color;
} State;

int solve_uva10047(int rows, int columns,
                   const char grid[MAX_ROWS][MAX_COLS + 1]) {
    static int distance[MAX_ROWS][MAX_COLS][DIRECTION_COUNT][COLOR_COUNT];
    State queue[MAX_STATES];
    int start_row = -1;
    int start_column = -1;
    int target_row = -1;
    int target_column = -1;
    int head = 0;
    int tail = 0;
    const int row_delta[DIRECTION_COUNT] = {-1, 0, 1, 0};
    const int column_delta[DIRECTION_COUNT] = {0, 1, 0, -1};

    memset(distance, -1, sizeof(distance));
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (grid[row][column] == 'S') {
                start_row = row;
                start_column = column;
            } else if (grid[row][column] == 'T') {
                target_row = row;
                target_column = column;
            }
        }
    }

    if (start_row < 0 || target_row < 0) {
        return -1;
    }

    distance[start_row][start_column][0][0] = 0;
    queue[tail++] = (State){(short)start_row, (short)start_column, 0, 0};

    while (head < tail) {
        State current = queue[head++];
        int current_distance =
            distance[current.row][current.column][current.direction][current.color];

        if (current.row == target_row && current.column == target_column &&
            current.color == 0) {
            return current_distance;
        }

        for (int turn = -1; turn <= 1; turn += 2) {
            int next_direction = (current.direction + turn + DIRECTION_COUNT) %
                                 DIRECTION_COUNT;

            if (distance[current.row][current.column][next_direction]
                        [current.color] == -1) {
                distance[current.row][current.column][next_direction]
                        [current.color] = current_distance + 1;
                queue[tail++] =
                    (State){current.row, current.column,
                            (unsigned char)next_direction, current.color};
            }
        }

        {
            int next_row = current.row + row_delta[current.direction];
            int next_column = current.column + column_delta[current.direction];
            int next_color = (current.color + 1) % COLOR_COUNT;

            if (next_row >= 0 && next_row < rows && next_column >= 0 &&
                next_column < columns && grid[next_row][next_column] != '#' &&
                distance[next_row][next_column][current.direction][next_color] == -1) {
                distance[next_row][next_column][current.direction][next_color] =
                    current_distance + 1;
                queue[tail++] =
                    (State){(short)next_row, (short)next_column,
                            current.direction, (unsigned char)next_color};
            }
        }
    }

    return -1;
}

int main(void) {
    int rows;
    int columns;
    int case_number = 1;

    while (scanf("%d %d", &rows, &columns) == 2 && (rows != 0 || columns != 0)) {
        char grid[MAX_ROWS][MAX_COLS + 1];
        int result;

        for (int row = 0; row < rows; ++row) {
            (void)scanf("%25s", grid[row]);
        }
        result = solve_uva10047(rows, columns, grid);

        if (case_number > 1) {
            putchar('\n');
        }
        printf("Case #%d\n", case_number++);
        if (result >= 0) {
            printf("minimum time = %d sec\n", result);
        } else {
            puts("destination not reachable");
        }
    }
    return 0;
}
