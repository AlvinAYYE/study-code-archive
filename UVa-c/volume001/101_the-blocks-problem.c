/*
 * ==========================================================================
 * UVa 101 - The Blocks Problem
 * Title-CN: 積木問題
 * Difficulty: UVa Star 2
 * Tags: simulation, data-structures
 * ==========================================================================
 * [EN] Problem: Simulate robotic arm moving blocks with move/onto, move/over, pile/onto, pile/over.
 * [中文] 題目說明: 模擬機器手臂堆疊積木（move/pile 與 onto/over 四種組合指令）。
 * [EN] Approach: 2D array representation of block stacks. Position lookup array for O(1) locate.
 * [中文] 思路: 二維陣列模擬每疊積木，以 pos 陣列記錄每個積木所在柱與高度。
 * ==========================================================================
 */
#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 25

static int stacks[MAX_BLOCKS][MAX_BLOCKS];
static int heights[MAX_BLOCKS];
static int pile_of[MAX_BLOCKS];

static int block_height(int block) {
    int pile = pile_of[block];
    int i;

    for (i = 0; i < heights[pile]; i++) {
        if (stacks[pile][i] == block) {
            return i;
        }
    }
    return -1;
}

static void return_above(int block) {
    int pile = pile_of[block];
    int height = block_height(block);

    while (heights[pile] > height + 1) {
        int moved = stacks[pile][--heights[pile]];
        stacks[moved][0] = moved;
        heights[moved] = 1;
        pile_of[moved] = moved;
    }
}

static void move_pile(int block, int destination) {
    int source = pile_of[block];
    int start = block_height(block);
    int i;

    for (i = start; i < heights[source]; i++) {
        int moved = stacks[source][i];
        stacks[destination][heights[destination]++] = moved;
        pile_of[moved] = destination;
    }
    heights[source] = start;
}

void solve_uva101(FILE *in, FILE *out) {
    int n;
    int i;
    char action[8];

    if (fscanf(in, "%d", &n) != 1 || n < 0 || n > MAX_BLOCKS) {
        return;
    }

    for (i = 0; i < n; i++) {
        stacks[i][0] = i;
        heights[i] = 1;
        pile_of[i] = i;
    }

    while (fscanf(in, "%7s", action) == 1 && strcmp(action, "quit") != 0) {
        char placement[8];
        int a;
        int b;

        if (fscanf(in, "%d %7s %d", &a, placement, &b) != 3) {
            break;
        }
        if (a < 0 || a >= n || b < 0 || b >= n || a == b || pile_of[a] == pile_of[b]) {
            continue;
        }

        if (strcmp(action, "move") == 0) {
            return_above(a);
        }
        if (strcmp(placement, "onto") == 0) {
            return_above(b);
        }
        move_pile(a, pile_of[b]);
    }

    for (i = 0; i < n; i++) {
        int j;
        fprintf(out, "%d:", i);
        for (j = 0; j < heights[i]; j++) {
            fprintf(out, " %d", stacks[i][j]);
        }
        fputc('\n', out);
    }
}

int main(void) {
    solve_uva101(stdin, stdout);
    return 0;
}
