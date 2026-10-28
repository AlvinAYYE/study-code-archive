/*
 * Title-CN: 最長特殊序列 II
 * LeetCode 522. Longest Uncommon Subsequence II
 *
 * 題目翻譯：給定字串陣列，找出其中一個最長的特殊序列。特殊序列是某個字串的
 * 子序列，但不能是陣列中其他任何字串的子序列。若不存在，回傳 -1。
 *
 * 例子：["aba","cdc","eae"] 的答案是 3，因為三個字串都不是其他字串的子序列。
 * ["aaa","aaa","aa"] 的答案是 -1，重複的 "aaa" 彼此都是子序列。
 *
 * 限制：字串數量最多 50；每個字串長度最多 10；內容為小寫英文字母。
 *
 * 解題步驟：逐一把每個字串當候選答案，檢查它是否為其他任一字串的子序列。
 * 若有任何一個其他字串包含它，就不是特殊序列；否則它是有效答案，保留目前最長長度。
 * 檢查子序列時只需依序掃描較長字串，匹配到候選字元就讓候選索引前進。
 *
 * 複雜度：若有 m 個字串、最長長度 L，時間 O(m^2 L)，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 findLUSlength 函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <string.h>

static bool isSubsequence(const char *candidate, const char *other) {
    int candidateIndex = 0;
    int candidateLength = (int)strlen(candidate);
    for (int i = 0; other[i] != '\0' && candidateIndex < candidateLength; ++i) {
        if (candidate[candidateIndex] == other[i]) {
            ++candidateIndex;
        }
    }
    return candidateIndex == candidateLength;
}

int findLUSlength(char **strs, int strsSize) {
    int best = -1;
    for (int i = 0; i < strsSize; ++i) {
        bool uncommon = true;
        for (int j = 0; j < strsSize; ++j) {
            if (i != j && isSubsequence(strs[i], strs[j])) {
                uncommon = false;
                break;
            }
        }
        int length = (int)strlen(strs[i]);
        if (uncommon && length > best) {
            best = length;
        }
    }
    return best;
}

int main(void) {
    char a[] = "aba";
    char b[] = "cdc";
    char c[] = "eae";
    char *example1[] = {a, b, c};
    assert(findLUSlength(example1, 3) == 3);

    char d[] = "aaa";
    char e[] = "aaa";
    char f[] = "aa";
    char *example2[] = {d, e, f};
    assert(findLUSlength(example2, 3) == -1);
    return 0;
}
