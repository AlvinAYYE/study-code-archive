/*
 * Title-CN: 至少重複 k 次的最長子字串
 * LeetCode 395. Longest Substring with At Least K Repeating Characters
 *
 * 題目翻譯：給定只含小寫英文字母的字串 s 與整數 k，找出最長子字串，
 * 使其中每一種出現的字母都至少出現 k 次。若沒有符合條件的非空子字串，回傳 0。
 *
 * 例子：s="aaabb"、k=3，答案是 3（"aaa"）；s="ababbc"、k=2，答案是 5（"ababb"）。
 *
 * 限制：字串長度最多 10000，k 最多 100000。
 *
 * 解題步驟：字母種類只有 26 種，因此枚舉視窗中「不同字母數」的目標值 1 到 26。
 * 對每個目標值用滑動視窗：右端加入字母，若不同字母超過目標就移動左端縮小；
 * 同時追蹤有幾種字母已出現至少 k 次。當不同字母數與目標相同，且每種都達到 k 次，
 * 目前視窗就是符合條件的候選答案。
 *
 * 複雜度：枚舉 26 種目標，每種情況左右端各走訪字串一次，時間 O(26n)=O(n)；
 * 計數陣列大小固定，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 longestSubstring 函式；main() 僅供本機測試。
 */

#include <assert.h>

int longestSubstring(char *s, int k) {
    int length = 0;
    while (s[length] != '\0') {
        ++length;
    }

    int longest = 0;
    for (int targetUnique = 1; targetUnique <= 26; ++targetUnique) {
        int counts[26] = {0};
        int left = 0;
        int unique = 0;
        int repeatedEnough = 0;

        for (int right = 0; right < length; ++right) {
            int added = s[right] - 'a';
            if (counts[added] == 0) {
                ++unique;
            }
            ++counts[added];
            if (counts[added] == k) {
                ++repeatedEnough;
            }

            while (unique > targetUnique) {
                int removed = s[left++] - 'a';
                if (counts[removed] == k) {
                    --repeatedEnough;
                }
                --counts[removed];
                if (counts[removed] == 0) {
                    --unique;
                }
            }

            if (unique == targetUnique && repeatedEnough == targetUnique) {
                int windowLength = right - left + 1;
                if (windowLength > longest) {
                    longest = windowLength;
                }
            }
        }
    }
    return longest;
}

int main(void) {
    char example1[] = "aaabb";
    char example2[] = "ababbc";
    char allLetters[] = "abc";
    assert(longestSubstring(example1, 3) == 3);
    assert(longestSubstring(example2, 2) == 5);
    assert(longestSubstring(allLetters, 4) == 0);
    return 0;
}
