/*
 * Title-CN: 刪除字元後字典中最長的單字
 * LeetCode 524. Longest Word in Dictionary through Deleting
 *
 * 題目翻譯：給定字串 s 和字典 dictionary。若能從 s 刪除一些字元（也可以不刪），
 * 且不改變其餘字元順序得到單字，就稱該單字可由 s 組成。回傳可組成的最長單字；
 * 長度相同時回傳字典序較小者；若沒有則回傳空字串。
 *
 * 例子：s="abpcplea"、dictionary=["ale","apple","monkey","plea"]，答案是 "apple"。
 *
 * 限制：s 最多 1000 個字元；字典最多 1000 個單字；內容皆為小寫英文字母。
 *
 * 解題步驟：逐一檢查字典單字是否為 s 的子序列。用兩個索引往右掃描：
 * s 的字元與單字目前字元相同時，就讓單字索引前進；單字索引走到結尾代表匹配成功。
 * 在成功的單字中，保留較長者；長度相同時保留字典序較小者。
 *
 * 複雜度：最多檢查字典總字元數與 s，時間 O(D * |s|)，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 findLongestWord 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <string.h>

static bool isSubsequence(const char *s, const char *word) {
    int sIndex = 0;
    int wordIndex = 0;
    int sLength = (int)strlen(s);
    int wordLength = (int)strlen(word);
    while (sIndex < sLength && wordIndex < wordLength) {
        if (s[sIndex] == word[wordIndex]) {
            ++wordIndex;
        }
        ++sIndex;
    }
    return wordIndex == wordLength;
}

char *findLongestWord(char *s, char **dictionary, int dictionarySize) {
    char *best = "";
    for (int i = 0; i < dictionarySize; ++i) {
        char *word = dictionary[i];
        size_t wordLength = strlen(word);
        size_t bestLength = strlen(best);
        if (isSubsequence(s, word)
            && (wordLength > bestLength
                || (wordLength == bestLength && strcmp(word, best) < 0))) {
            best = word;
        }
    }
    return best;
}

int main(void) {
    char s1[] = "abpcplea";
    char word0[] = "ale";
    char word1[] = "apple";
    char word2[] = "monkey";
    char word3[] = "plea";
    char *dictionary1[] = {word0, word1, word2, word3};
    assert(strcmp(findLongestWord(s1, dictionary1, 4), "apple") == 0);

    char s2[] = "abpcplea";
    char a[] = "a";
    char b[] = "b";
    char c[] = "c";
    char *dictionary2[] = {b, c, a};
    assert(strcmp(findLongestWord(s2, dictionary2, 3), "a") == 0);
    return 0;
}
