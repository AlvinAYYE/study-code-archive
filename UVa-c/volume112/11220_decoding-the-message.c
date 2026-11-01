/*
 * ==========================================================================
 * UVa 11220 - Decoding the message.
 * Title-CN: 破譯密碼訊息 (單字第k字母拼接)
 * Difficulty: Easy
 * Tags: String, Parsing
 * URL: https://onlinejudge.org/external/112/11220.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Decode hidden message from a sentence: the i-th word contributes its i-th character (1-based) if word is long enough.
 *
 * [中文] 題目說明:
 *     從句子中破譯隱藏文字：每句話中的第 i 個有效單字貢獻其第 i 個字母（下標從 1 起算），單字長度不足則跳過且下標不增加。
 *
 * [EN] Approach:
 *     Tokenize sentence into words. Track target char index k (starts at 1). If word length >= k, append word[k-1] to decoded message and increment k.
 * [中文] 思路:
 *     將句子拆詞，維護當前字元下標 k=1，若當前單字長度 >= k，則提取第 k 個字母加入解碼結果並將 k 加 1。
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

void decode_msg_11220(int word_cnt, const char words[][20], char *out) {
    int k = 1, o_idx = 0;
    for (int i = 0; i < word_cnt; i++) {
        if ((int)strlen(words[i]) >= k) {
            out[o_idx++] = words[i][k - 1];
            k++;
        }
    }
    out[o_idx] = '\0';
}

int main(void) {

    char w[3][20] = {"my", "dear", "friend"}; // m(1st), e(2nd), i(3rd) -> "mei"
    char out[10];
    decode_msg_11220(3, w, out);
    int ok = (strcmp(out, "mei") == 0);
    printf("%s: UVa 11220 - Decoding the message.\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
