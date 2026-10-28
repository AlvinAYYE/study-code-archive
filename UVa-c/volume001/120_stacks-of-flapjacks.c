/*
 * ==========================================================================
 * UVa 120 - Stacks of Flapjacks
 * Title-CN: 煎餅堆排序
 * Difficulty: UVa Star 2
 * Tags: sorting, simulation, greedy
 * ==========================================================================
 * [EN] Problem: Sort pancake stack using spatula flips from any position to top.
 * [中文] 題目說明: 使用鍋鏟翻轉煎餅堆（只能將某位置以上的所有煎餅翻轉），由小到大排序煎餅堆。
 * [EN] Approach: Greedy pancake sort: find max unsorted pancake, flip to top, then flip to destination.
 * [中文] 思路: 貪婪法由大到小定位：先將未定位最大者翻到頂端，再整體翻至目標底端。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

static void flip(int *arr, int k) {
    int l = 0, r = k;
    while (l < r) {
        int t = arr[l]; arr[l] = arr[r]; arr[r] = t;
        l++; r--;
    }
}

void solve_uva120(FILE *in, FILE *out) {
    char line[4096];

    while (fgets(line, sizeof(line), in) != NULL) {
        int pancakes[64];
        int count = 0;
        char *cursor = line;
        int i;

        while (*cursor != '\0') {
            char *end;
            long value = strtol(cursor, &end, 10);
            if (end == cursor) {
                cursor++;
            } else {
                if (count < (int)(sizeof(pancakes) / sizeof(pancakes[0]))) {
                    pancakes[count++] = (int)value;
                }
                cursor = end;
            }
        }
        if (count == 0) {
            continue;
        }

        for (i = 0; i < count; i++) {
            if (i > 0) {
                fputc(' ', out);
            }
            fprintf(out, "%d", pancakes[i]);
        }
        fputc('\n', out);

        for (i = count - 1; i > 0; i--) {
            int maximum_index = 0;
            int j;
            for (j = 1; j <= i; j++) {
                if (pancakes[j] > pancakes[maximum_index]) {
                    maximum_index = j;
                }
            }
            if (maximum_index == i) {
                continue;
            }
            if (maximum_index != 0) {
                flip(pancakes, maximum_index);
                fprintf(out, "%d ", count - maximum_index);
            }
            flip(pancakes, i);
            fprintf(out, "%d ", count - i);
        }
        fputs("0\n", out);
    }
}

int main(void) {
    solve_uva120(stdin, stdout);
    return 0;
}
