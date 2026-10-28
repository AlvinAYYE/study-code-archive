/*
 * Title-CN: 產生各字元出現奇數次的字串
 * LeetCode 1374. Generate a String With Characters That Have Odd Counts
 *
 * 題意完整翻譯：
 *   給定整數 n，回傳一個長度為 n 的字串，使字串中的每種字元都恰好出現奇數次。字串只能包含小寫英文字母；若有多種答案，回傳任意一種。
 *
 * 範例：
 *   1. n = 4，可回傳 pppz：p 出現 3 次、z 出現 1 次。
 *   2. n = 2，可回傳 xy：兩個字元各出現 1 次。
 *   3. n = 7，可回傳 holasss。
 *
 * 限制：
 *   - 1 <= n <= 500
 *
 * 解題步驟：
 *   1. 若 n 是奇數，讓字母 a 重複 n 次；它出現奇數次。
 *   2. 若 n 是偶數，讓 a 出現 n - 1 次，再放一個 b；n - 1 和 1 都是奇數。
 *   3. 最後加上字串結尾的 \0。
 *
 * 複雜度：
 *   時間：O(n)，寫入字串中的每個字元一次。
 *   空間：O(n)，配置長度 n + 1 的回傳字串。
 *
 * LeetCode C API：
 *   char* generateTheString(int n);
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* generateTheString(int n) {
    char* answer = (char*)malloc((size_t)n + 1);
    int aCount = (n % 2 == 1) ? n : n - 1;
    int i;

    for (i = 0; i < aCount; ++i) {
        answer[i] = 'a';
    }
    if (n % 2 == 0) {
        answer[n - 1] = 'b';
    }
    answer[n] = '\0';

    return answer;
}

int main(void) {
    int n;
    for (n = 1; n <= 20; ++n) {
        char* text = generateTheString(n);
        int counts[26] = {0};
        int i;
        assert((int)strlen(text) == n);
        for (i = 0; text[i] != '\0'; ++i) {
            ++counts[text[i] - 'a'];
        }
        for (i = 0; i < 26; ++i) {
            assert(counts[i] == 0 || counts[i] % 2 == 1);
        }
        free(text);
    }
    puts("PASS 1374 generateTheString");
    return 0;
}
