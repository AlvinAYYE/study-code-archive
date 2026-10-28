/*
 * ==========================================================================
 * UVa 488 - Triangle Wave
 * Title-CN: 三角波形輸出
 * Difficulty: UVa Star 1
 * Tags: simulation
 * ==========================================================================
 * [EN] Problem: Print triangle waves given amplitude and frequency.
 * [中文] 題目說明: 給定振幅與頻率，輸出由數字構成的三角形波形。
 * [EN] Approach: Nested loops from 1..A then A-1..1 repeated F times.
 * [中文] 思路: 雙重迴圈上升與下降輸出數字。
 * ==========================================================================
 */
#include <stdio.h>

static void print_row(FILE *out, int value) {
    int i;
    for (i = 0; i < value; i++) {
        fputc('0' + value, out);
    }
    fputc('\n', out);
}

void solve_uva488(FILE *in, FILE *out) {
    int test_cases;
    int test_case;
    int first_wave = 1;

    if (fscanf(in, "%d", &test_cases) != 1) {
        return;
    }
    for (test_case = 0; test_case < test_cases; test_case++) {
        int amplitude;
        int frequency;
        int wave;

        if (fscanf(in, "%d %d", &amplitude, &frequency) != 2) {
            return;
        }
        for (wave = 0; wave < frequency; wave++) {
            int value;
            if (!first_wave) {
                fputc('\n', out);
            }
            first_wave = 0;
            for (value = 1; value <= amplitude; value++) {
                print_row(out, value);
            }
            for (value = amplitude - 1; value >= 1; value--) {
                print_row(out, value);
            }
        }
    }
}

int main(void) {
    solve_uva488(stdin, stdout);
    return 0;
}
