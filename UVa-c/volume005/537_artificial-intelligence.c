/*
 * ==========================================================================
 * UVa 537 - Artificial Intelligence?
 * Title-CN: 物理功率、電壓、電流計算
 * Difficulty: UVa Star 1
 * Tags: string, parsing, physics
 * ==========================================================================
 * [EN] Problem: Parse two quantities among P (power), U (voltage), I (current), and compute the third via P = U*I.
 * [中文] 題目說明: 解析文本中的 P, U, I 三項物理量中的兩項，由 P = U * I 求出第三項。
 * [EN] Approach: String parsing with prefix multipliers (m, k, M).
 * [中文] 思路: 提取帶有單位（W, V, A）的數值與乘數後計算求解。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int read_quantity(const char *line, char symbol, double *value) {
    char pattern[3] = {symbol, '=', '\0'};
    const char *position = strstr(line, pattern);
    char *end;
    double multiplier = 1.0;

    if (position == NULL) {
        return 0;
    }

    *value = strtod(position + 2, &end);
    if (*end == 'm') {
        multiplier = 1e-3;
    } else if (*end == 'k') {
        multiplier = 1e3;
    } else if (*end == 'M') {
        multiplier = 1e6;
    }
    *value *= multiplier;
    return 1;
}

void solve_uva537(FILE *input, FILE *output) {
    int cases;
    char line[4096];

    if (fscanf(input, "%d", &cases) != 1) {
        return;
    }
    (void)fgets(line, sizeof(line), input);

    for (int case_number = 1; case_number <= cases; ++case_number) {
        double p = 0.0;
        double u = 0.0;
        double i = 0.0;
        int has_p;
        int has_u;
        int has_i;

        if (fgets(line, sizeof(line), input) == NULL) {
            break;
        }
        has_p = read_quantity(line, 'P', &p);
        has_u = read_quantity(line, 'U', &u);
        has_i = read_quantity(line, 'I', &i);

        fprintf(output, "Problem #%d\n", case_number);
        if (!has_p && has_u && has_i) {
            fprintf(output, "P=%.2fW\n\n", u * i);
        } else if (!has_u && has_p && has_i) {
            fprintf(output, "U=%.2fV\n\n", p / i);
        } else if (!has_i && has_p && has_u) {
            fprintf(output, "I=%.2fA\n\n", p / u);
        }
    }
}

int main(void) {
    solve_uva537(stdin, stdout);
    return 0;
}
