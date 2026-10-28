/*
 * LeetCode 0792. Number of Matching Subsequences（符合子序列條件的字串數）
 * 題意：給定字串 s 和 words，計算有多少個 words[i] 可由 s 刪除部分字元、保持原順序後得到。
 * 範例：s="abcde", words=["a","bb","acd","ace"] -> 3（a、acd、ace）。
 * 限制：|s|<=5*10^4；words<=5000；每個 word 長度<=50；只含小寫英文字母。
 * 解法：預先為 s 的每個位置與字母建立「下一次出現位置」表。逐字掃描 word 時直接跳到下一個符合字元。
 * 複雜度：設 n=|s|、T 為 words 字元總數；時間 O(26n+T)，空間 O(26n)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- community solution ---- */
int numMatchingSubseq(char* s, char** words, int wordsSize) {
    int length = (int)strlen(s);
    int (*nextPosition)[26] = (int (*)[26])malloc(
        sizeof(*nextPosition) * (size_t)(length + 1));
    if (nextPosition == NULL) {
        return 0;
    }

    for (int letter = 0; letter < 26; letter++) {
        nextPosition[length][letter] = -1;
    }
    for (int index = length - 1; index >= 0; index--) {
        memcpy(nextPosition[index], nextPosition[index + 1],
               sizeof(nextPosition[index]));
        nextPosition[index][s[index] - 'a'] = index;
    }

    int matches = 0;
    for (int wordIndex = 0; wordIndex < wordsSize; wordIndex++) {
        int position = 0;
        bool isSubsequence = true;
        for (int i = 0; words[wordIndex][i] != '\0'; i++) {
            int found = nextPosition[position][words[wordIndex][i] - 'a'];
            if (found == -1) {
                isSubsequence = false;
                break;
            }
            position = found + 1;
        }
        if (isSubsequence) {
            matches++;
        }
    }

    free(nextPosition);
    return matches;
}

/* ---- generated tests ---- */
int main(void) {
    char firstText[] = "abcde";
    char *firstWords[] = {"a", "bb", "acd", "ace"};
    char secondText[] = "dsahjpjauf";
    char *secondWords[] = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    char thirdText[] = "aaaa";
    char *thirdWords[] = {"a", "aa", "aaa", "aaaa", "aaaaa"};
    bool passed = numMatchingSubseq(firstText, firstWords, 4) == 3 &&
                  numMatchingSubseq(secondText, secondWords, 4) == 2 &&
                  numMatchingSubseq(thirdText, thirdWords, 5) == 4;
    printf("%s: 0792 numMatchingSubseq tests=3\n",
           passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
