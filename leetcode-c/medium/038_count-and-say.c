/*
 * LeetCode 38. Count and Say／外觀數列
 * 題目（繁體中文）
 *   第 1 項是字串 "1"。之後每一項都「唸出」上一項連續相同數字的
 *   個數與數字，例如 "21" 是「一個 2、一個 1」，下一項就是 "1211"。
 *   給定 1 ≤ n ≤ 30，回傳第 n 項字串。
 *
 * 例子
 *   n=1 → "1"
 *   n=4 → "1211"：第 2 項 "11"、第 3 項 "21"、第 4 項 "1211"。
 *   n=5 → "111221"："1211" 可分成一個 1、一個 2、兩個 1。
 *
 * 解題思路
 *   1. 從 "1" 開始，重複 n-1 次。
 *   2. 每次掃描上一項，把連續相同數字切成一組。
 *   3. 對每組先寫入「個數」，再寫入「那個數字」，組合成下一項。
 *   4. 第 n 項長度若為 L，轉換一次需 O(L) 時間、O(L) 空間；
 *      全程時間為各項長度之和。回傳字串由呼叫者釋放。
 *
 * LeetCode 提交時保留 include 與「提交區」即可。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
char *countAndSay(int n) {
    char *current = (char *)malloc(2);
    if (current == NULL) return NULL;
    current[0] = '1';
    current[1] = '\0';

    for (int term = 2; term <= n; term++) {
        size_t length = strlen(current);
        /* 每組輸出至多是「長度個數 + 1 個數字」；總量不超過 2*length。 */
        char *next = (char *)malloc(length * 2 + 1);
        if (next == NULL) {
            free(current);
            return NULL;
        }

        size_t output = 0;
        for (size_t start = 0; start < length;) {
            size_t end = start + 1;
            while (end < length && current[end] == current[start]) end++;

            output += (size_t)sprintf(next + output, "%zu", end - start);
            next[output++] = current[start];
            start = end;
        }
        next[output] = '\0';
        free(current);
        current = next;
    }
    return current;
}
/* ---------- end submission ---------- */

int main(void) {
    const char *expected[] = {"1", "11", "21", "1211", "111221", "312211"};
    for (int n = 1; n <= 6; n++) {
        char *actual = countAndSay(n);
        int ok = actual != NULL && strcmp(actual, expected[n - 1]) == 0;
        free(actual);
        if (!ok) {
            printf("FAIL: 038 n=%d\n", n);
            return 1;
        }
    }
    puts("PASS: 038 count-and-say");
    return 0;
}
