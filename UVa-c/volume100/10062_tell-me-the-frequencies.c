/*
 * ==========================================================================
 * UVa 10062 - Tell me the frequencies!
 * Title-CN: 告訴我頻率！
 * Difficulty: UVa Star 1 / CPE 49 顆星必考題
 * Tags: string, sorting, ascii
 * URL: https://onlinejudge.org/external/100/10062.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Count character frequencies in input line. Sort by frequency ascending;
 *     if tied, by ASCII value descending.
 *
 * [中文] 題目說明:
 *     統計每行字元出現頻率。按出現頻率遞增排序；若頻率相同則按 ASCII 碼遞減排序。
 *
 * [EN] Approach: Count ASCII 0-255 frequencies, sort with qsort.
 * [中文] 思路: 頻率為主要鍵(升序)，ASCII碼為次要鍵(降序)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ascii;
    int freq;
} Item;

static int cmp(const void *a, const void *b) {
    const Item *ia = (const Item *)a;
    const Item *ib = (const Item *)b;
    if (ia->freq != ib->freq) return ia->freq - ib->freq;
    return ib->ascii - ia->ascii;
}

int solve_uva10062(const char *str, Item *out) {
    int count[256] = {0};
    for (int i = 0; str[i]; i++) count[(unsigned char)str[i]]++;
    int total = 0;
    for (int i = 32; i < 128; i++) {
        if (count[i] > 0) {
            out[total].ascii = i;
            out[total].freq = count[i];
            total++;
        }
    }
    qsort(out, (size_t)total, sizeof(Item), cmp);
    return total;
}

int main(void) {
    Item out[128];
    int n = solve_uva10062("AAABBC", out);
    int ok = (n == 3 && out[0].ascii == 'C' && out[0].freq == 1 &&
              out[1].ascii == 'B' && out[1].freq == 2 &&
              out[2].ascii == 'A' && out[2].freq == 3);
    printf("%s: UVa 10062 - Tell me the frequencies!\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
