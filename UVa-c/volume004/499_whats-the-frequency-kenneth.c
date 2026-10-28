/*
 * ==========================================================================
 * UVa 499 - What's The Frequency, Kenneth?
 * Title-CN: 出現頻率最高字母統計
 * Difficulty: UVa Star 1
 * Tags: string, sorting
 * ==========================================================================
 * [EN] Problem: Find uppercase and lowercase letters with maximum frequency.
 * [中文] 題目說明: 統計字串中出現最多次數的英文字母，依 A-Z, a-z 順序輸出。
 * [EN] Approach: Array count[256], find max count, print letters with max count.
 * [中文] 思路: 統計頻率求最大值，依序印出達到最大值的字母。
 * ==========================================================================
 */
#include <stdio.h>
#include <ctype.h>

static void print_frequencies(FILE *out, const int counts[256]) {
    int maximum = 0;
    int ch;

    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (counts[ch] > maximum) {
            maximum = counts[ch];
        }
    }
    for (ch = 'a'; ch <= 'z'; ch++) {
        if (counts[ch] > maximum) {
            maximum = counts[ch];
        }
    }
    if (maximum > 0) {
        for (ch = 'A'; ch <= 'Z'; ch++) {
            if (counts[ch] == maximum) {
                fputc(ch, out);
            }
        }
        for (ch = 'a'; ch <= 'z'; ch++) {
            if (counts[ch] == maximum) {
                fputc(ch, out);
            }
        }
    }
    fprintf(out, " %d\n", maximum);
}

void solve_uva499(FILE *in, FILE *out) {
    int counts[256] = {0};
    int have_input = 0;
    int ch;

    while ((ch = fgetc(in)) != EOF) {
        if (ch == '\n') {
            print_frequencies(out, counts);
            for (ch = 0; ch < 256; ch++) {
                counts[ch] = 0;
            }
            have_input = 0;
        } else if (ch != '\r') {
            if (isalpha((unsigned char)ch)) {
                counts[(unsigned char)ch]++;
            }
            have_input = 1;
        }
    }
    if (have_input) {
        print_frequencies(out, counts);
    }
}

int main(void) {
    solve_uva499(stdin, stdout);
    return 0;
}
