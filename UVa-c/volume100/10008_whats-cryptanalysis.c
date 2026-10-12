/*
 * ==========================================================================
 * UVa 10008 - What's Cryptanalysis?
 * Title-CN: 什麼是密碼分析？ (字母頻率統計排序)
 * Difficulty: UVa Star 1 / CPE 49 顆星精選題
 * Tags: string, frequency-counting, sorting
 * URL: https://onlinejudge.org/external/100/10008.pdf
 * ==========================================================================
 * [EN] Problem Statement:
 *     Cryptanalysis is the process of deciphering coded messages without being
 *     told the key. One common technique is frequency analysis of letters.
 *     Given several lines of text, count the frequency of each uppercase letter.
 *     Print the letters and their frequencies in decreasing order of frequency.
 *     If frequencies are equal, print in alphabetical order.
 *
 * [中文] 題目說明:
 *     密碼分析是指在不知道密鑰的情況下破解加密訊息的過程。
 *     其中一種常見技巧是字母出現頻率分析。
 *     給定多行英文文字，統計每個英文字母出現的頻率（不分大小寫，統計為大寫）。
 *     依頻率由高到低輸出字母與出現次數。
 *     若頻率相同，則按英文字母先後順序（A 到 Z）輸出。
 *
 * Examples:
 *   Input:
 *     3
 *     This is a test.
 *     Count me 1 2 3 4 5.
 *     Lorem ipsum dolor sit amet.
 *   Output:
 *     T 6
 *     S 5
 *     E 4
 *     ...
 *
 * [EN] Approach:
 *     Use an array of 26 letters with frequency counter.
 *     Sort primarily by frequency descending, secondarily by character ascending.
 * [中文] 思路:
 *     使用長度為 26 的陣列記錄各字母次數。
 *     排序規則：次數多者優先（降冪），次數相同則依字母順序（升冪）。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char letter;
    int count;
} Freq;

static int cmp_freq(const void *a, const void *b) {
    const Freq *fa = (const Freq *)a;
    const Freq *fb = (const Freq *)b;
    if (fa->count != fb->count) {
        return fb->count - fa->count; /* 降序 / Descending */
    }
    return fa->letter - fb->letter;   /* 升序 / Ascending */
}

void solve_uva10008_from_text(const char *text, Freq *results, int *resultCount) {
    Freq freq[26];
    for (int i = 0; i < 26; i++) {
        freq[i].letter = (char)('A' + i);
        freq[i].count = 0;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha((unsigned char)ch)) {
            char upper = (char)toupper((unsigned char)ch);
            freq[upper - 'A'].count++;
        }
    }

    qsort(freq, 26, sizeof(Freq), cmp_freq);

    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i].count > 0) {
            results[count++] = freq[i];
        }
    }
    *resultCount = count;
}

int main(void) {
    const char *sample = "This is a test.\nCount me 1 2 3 4 5.\n";
    Freq results[26];
    int count = 0;
    solve_uva10008_from_text(sample, results, &count);

    /* Test checks: 'T' is most frequent (4 times), then 'S' (3 times) */
    int ok = (count > 0 && results[0].letter == 'T' && results[0].count == 4);
    printf("%s: UVa 10008 - What's Cryptanalysis?\n", ok ? "PASS" : "FAIL");

    /*
     * For UVa Online Judge submission / UVa 送出模式：
     *
     * int n;
     * char line[1005];
     * if (scanf("%d\n", &n) == 1) {
     *     int counts[26] = {0};
     *     while (n-- && fgets(line, sizeof(line), stdin)) {
     *         for (int i = 0; line[i]; i++) {
     *             if (isalpha((unsigned char)line[i])) {
     *                 counts[toupper((unsigned char)line[i]) - 'A']++;
     *             }
     *         }
     *     }
     *     Freq freq[26];
     *     for (int i = 0; i < 26; i++) {
     *         freq[i].letter = 'A' + i;
     *         freq[i].count = counts[i];
     *     }
     *     qsort(freq, 26, sizeof(Freq), cmp_freq);
     *     for (int i = 0; i < 26; i++) {
     *         if (freq[i].count > 0) printf("%c %d\n", freq[i].letter, freq[i].count);
     *     }
     * }
     */
    return ok ? 0 : 1;
}
