/*
 * ==========================================================================
 * UVa 1586 - Molar mass
 * Title-CN: 化學分子量莫耳質量計算
 * Difficulty: UVa Star 1
 * Tags: string, parsing
 * URL: https://onlinejudge.org/external/15/1586.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Compute molar mass of chemical formula consisting of C (12.01), H (1.008), O (16.00), and N (14.01) with optional multi-digit integer counts.
 *
 * [中文] 題目說明:
 *     給定僅含 C (12.01)、H (1.008)、O (16.00) 與 N (14.01) 的化學分子式，計算其莫耳質量 (分子量)。
 *
 * [EN] Approach:
 *     Scan characters: when letter is encountered, parse subsequent digits (defaulting to 1 if none). Multiply and sum weights.
 * [中文] 思路:
 *     掃描分子式，遇到元素符號後解析其後續連續數字作為原子個數 (無數字則預設為 1)，乘以原子量並累加。
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

double atom_weight(char c) {
    if (c == 'C') return 12.01;
    if (c == 'H') return 1.008;
    if (c == 'O') return 16.00;
    if (c == 'N') return 14.01;
    return 0.0;
}

double solve_uva1586(const char *formula) {
    double total = 0.0;
    int len = strlen(formula);
    for (int i = 0; i < len; ) {
        char atom = formula[i++];
        int count = 0;
        while (i < len && isdigit(formula[i])) {
            count = count * 10 + (formula[i++] - '0');
        }
        if (count == 0) count = 1;
        total += atom_weight(atom) * count;
    }
    return total;
}

int main(void) {

    double m = solve_uva1586("C6H5OH");
    int ok = (fabs(m - 94.108) < 1e-2);
    printf("%s: UVa 1586 - Molar mass\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
