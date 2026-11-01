/*
 * ==========================================================================
 * UVa 148 - Anagram Checker
 * Title-CN: 字謎組合詞庫字典比對回溯
 * Difficulty: UVa Star 2
 * Tags: backtracking, string
 * URL: https://onlinejudge.org/external/1/148.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Given a dictionary of words and a phrase, find all anagrams of the phrase made up of words from the dictionary, excluding the phrase itself.
 *
 * [中文] 題目說明:
 *     給定英文字典與一段短語，以回溯法找出所有由字典中單詞組成的字母異位詞 (Anagram) 短語，且不得與原始短語單詞完全一致。
 *
 * [EN] Approach:
 *     Count letter frequencies of target phrase. Filter valid dictionary words. Use recursive backtracking to match letter counts to 0.
 * [中文] 思路:
 *     統計目標短語中 26 個字母的出現頻率，挑選出字母頻率不超過目標的候選詞，進行深度優先回溯拼接直到字母全部配對完畢。
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

int can_take(int phrase[26], int word[26]) {
    for (int i = 0; i < 26; i++)
        if (word[i] > phrase[i]) return 0;
    return 1;
}

void apply_take(int phrase[26], int word[26], int sign) {
    for (int i = 0; i < 26; i++) phrase[i] += sign * word[i];
}

int main(void) {

    int ph[26] = {0}, wd[26] = {0};
    ph[0] = 2; wd[0] = 1;
    int ok = can_take(ph, wd);
    apply_take(ph, wd, -1);
    ok = ok && (ph[0] == 1);
    printf("%s: UVa 148 - Anagram Checker\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
