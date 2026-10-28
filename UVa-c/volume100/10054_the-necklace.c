/*
 * ==========================================================================
 * UVa 10054 - The Necklace
 * Title-CN: 項鍊問題
 * Difficulty: UVa Star 2
 * Tags: graph, eulerian-tour
 * URL: https://onlinejudge.org/external/100/10054.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Connect beads into a necklace such that adjacent half-beads have the same color (Eulerian Tour).
 *
 * [中文] 題目說明:
 *     每顆珠子兩端有顏色（邊），求串成一條封閉項鍊且相鄰兩半顏色相同（等價於無向圖歐拉迴路）。
 *
 * [EN] Approach:
 *     Check all vertex degrees are even and connected. Hierholzer's algorithm for Euler tour.
 * [中文] 思路:
 *     檢驗所有頂點度數為偶數且連通，使用 Hierholzer 演算法構造歐拉迴路。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_COUNT 51

int solve_uva10054(const int (*beads)[2], int bead_count, int (*tour)[2]) {
    int edges[COLOR_COUNT][COLOR_COUNT] = {{0}};
    int degree[COLOR_COUNT] = {0};
    int visited[COLOR_COUNT] = {0};
    int vertex_stack[COLOR_COUNT];
    int stack_size = 0;
    int start = -1;
    int *path_stack;
    int *circuit;
    int path_size = 0;
    int circuit_size = 0;

    for (int i = 0; i < bead_count; ++i) {
        int left = beads[i][0];
        int right = beads[i][1];

        if (left == right) {
            ++edges[left][right];
        } else {
            ++edges[left][right];
            ++edges[right][left];
        }
        ++degree[left];
        ++degree[right];
        start = left;
    }

    if (start < 0) {
        return 0;
    }
    for (int color = 1; color < COLOR_COUNT; ++color) {
        if (degree[color] % 2 != 0) {
            return 0;
        }
    }

    vertex_stack[stack_size++] = start;
    visited[start] = 1;
    while (stack_size > 0) {
        int current = vertex_stack[--stack_size];

        for (int next = 1; next < COLOR_COUNT; ++next) {
            if (edges[current][next] > 0 && !visited[next]) {
                visited[next] = 1;
                vertex_stack[stack_size++] = next;
            }
        }
    }
    for (int color = 1; color < COLOR_COUNT; ++color) {
        if (degree[color] > 0 && !visited[color]) {
            return 0;
        }
    }

    path_stack = malloc((size_t)(bead_count + 2) * sizeof(*path_stack));
    circuit = malloc((size_t)(bead_count + 2) * sizeof(*circuit));
    if (path_stack == NULL || circuit == NULL) {
        free(path_stack);
        free(circuit);
        return 0;
    }

    path_stack[path_size++] = start;
    while (path_size > 0) {
        int current = path_stack[path_size - 1];
        int next;

        for (next = 1; next < COLOR_COUNT; ++next) {
            if (edges[current][next] > 0) {
                break;
            }
        }
        if (next < COLOR_COUNT) {
            --edges[current][next];
            if (current != next) {
                --edges[next][current];
            }
            path_stack[path_size++] = next;
        } else {
            circuit[circuit_size++] = path_stack[--path_size];
        }
    }

    if (circuit_size != bead_count + 1) {
        free(path_stack);
        free(circuit);
        return 0;
    }
    for (int i = circuit_size - 1, edge = 0; i > 0; --i, ++edge) {
        tour[edge][0] = circuit[i];
        tour[edge][1] = circuit[i - 1];
    }

    free(path_stack);
    free(circuit);
    return 1;
}

int main(void) {
    int cases;

    if (scanf("%d", &cases) != 1) {
        return 0;
    }
    for (int case_number = 1; case_number <= cases; ++case_number) {
        int bead_count;
        int (*beads)[2];
        int (*tour)[2];
        int possible;

        if (scanf("%d", &bead_count) != 1) {
            return 0;
        }
        beads = malloc((size_t)bead_count * sizeof(*beads));
        tour = malloc((size_t)bead_count * sizeof(*tour));
        if (beads == NULL || tour == NULL) {
            free(beads);
            free(tour);
            return 1;
        }
        for (int i = 0; i < bead_count; ++i) {
            (void)scanf("%d %d", &beads[i][0], &beads[i][1]);
        }

        possible = solve_uva10054(beads, bead_count, tour);
        if (case_number > 1) {
            putchar('\n');
        }
        printf("Case #%d\n", case_number);
        if (possible) {
            for (int i = 0; i < bead_count; ++i) {
                printf("%d %d\n", tour[i][0], tour[i][1]);
            }
        } else {
            puts("some beads may be lost");
        }

        free(beads);
        free(tour);
    }
    return 0;
}
