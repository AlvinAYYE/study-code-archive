/*
 * Title-CN: 重複疊加字串匹配
 * LeetCode 686. Repeated String Match
 *
 * 題意翻譯：給定字串 a 和 b，只能把 a 整段重複接在一起。請回傳最少重複幾次後，
 * b 才會成為結果字串的子字串；若永遠無法做到，回傳 -1。
 *
 * 範例：a = "abcd"、b = "cdabcdab"，重複 3 次後包含 b，回傳 3。
 *
 * 限制：a、b 長度為 1 到 10^4，只含小寫英文字母。
 *
 * 解題思路：先把 a 重複到總長度至少和 b 一樣，檢查是否包含 b。若沒有，再多接
 * 一份 a；因為 b 最多只會跨過一次重複接合處，這次檢查後即可確定有沒有答案。
 *
 * 複雜度：建字串 O(|b|+|a|)，搜尋依標準函式約 O(|a|*|b|) 最壞；空間 O(|a|+|b|)。
 * LeetCode 介面：保留 repeatedStringMatch；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int repeatedStringMatch(char *a, char *b) {
    size_t aLength = strlen(a);
    size_t bLength = strlen(b);
    size_t capacity = bLength + 2 * aLength + 1;
    char *repeated = malloc(capacity);
    if (repeated == NULL) return -1;

    size_t length = 0;
    int repeats = 0;
    while (length < bLength) {
        memcpy(repeated + length, a, aLength);
        length += aLength;
        ++repeats;
    }
    repeated[length] = '\0';
    if (strstr(repeated, b) != NULL) {
        free(repeated);
        return repeats;
    }

    memcpy(repeated + length, a, aLength);
    length += aLength;
    repeated[length] = '\0';
    int answer = strstr(repeated, b) != NULL ? repeats + 1 : -1;
    free(repeated);
    return answer;
}

int main(void) {
    char a1[] = "abcd";
    char b1[] = "cdabcdab";
    char a2[] = "a";
    char b2[] = "aa";
    char a3[] = "abc";
    char b3[] = "wxyz";
    assert(repeatedStringMatch(a1, b1) == 3);
    assert(repeatedStringMatch(a2, b2) == 2);
    assert(repeatedStringMatch(a3, b3) == -1);
    return 0;
}
