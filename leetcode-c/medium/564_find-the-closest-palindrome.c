/*
 * LeetCode 564. Find the Closest Palindrome（尋找最近的回文數）
 *
 * 題意（繁體中文）：
 *   給定一個不含前導零的正整數字串 n，請找出與它不同、距離最近的回文整數，
 *   並以字串回傳。距離是兩數相減的絕對值；若最近的候選有平手，回傳較小者。
 *
 * 範例：
 *   1. n="123"，回傳 "121"。
 *   2. n="1"，回傳 "0"。0 和 2 距離相同，因此選較小的 0。
 *   3. n="10"，回傳 "9"。9 和 11 都只差 1，平手時選較小的 9。
 *
 * 限制：1 <= n.length <= 18；只含數字且沒有前導零；1 <= n <= 10^18-1。
 *
 * 解題步驟：
 *   1. 回文數左半部決定右半部，所以只需嘗試原數左半部的三種值：本身、少
 *      1、多 1，將每個左半部鏡射成回文候選。
 *   2. 另外加入位數邊界候選：小一位數中最大的回文，以及大一位數中最小的
 *      回文。這能涵蓋像 1000 附近的 999、1001 等答案。
 *   3. 排除原數本身，比較其餘候選與原數的距離；距離較小者勝，平手取數值
 *      較小者。最後配置字串並回傳，呼叫端負責釋放。
 *
 * 複雜度：位數為 d，時間 O(d)，額外空間 O(d)；只建立固定數量候選。
 * LeetCode C API：char* nearestPalindromic(char* n)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long powerOfTen(int exponent) {
    long long value = 1;
    for (int i = 0; i < exponent; ++i) value *= 10;
    return value;
}

static long long makePalindrome(long long prefix, int originalLength) {
    char prefixDigits[32];
    char palindrome[40];
    snprintf(prefixDigits, sizeof prefixDigits, "%lld", prefix);
    int prefixLength = (int)strlen(prefixDigits);
    memcpy(palindrome, prefixDigits, (size_t)prefixLength);
    int length = prefixLength;

    /* 奇數位時，左半部最後一位是中間位，不再重複附加。 */
    int i = prefixLength - 1 - (originalLength % 2);
    for (; i >= 0; --i) palindrome[length++] = prefixDigits[i];
    palindrome[length] = '\0';
    return strtoll(palindrome, NULL, 10);
}

char *nearestPalindromic(char *n) {
    if (n == NULL) return NULL;
    int length = (int)strlen(n);
    long long original = strtoll(n, NULL, 10);
    int prefixLength = (length + 1) / 2;
    char prefixText[32];
    memcpy(prefixText, n, (size_t)prefixLength);
    prefixText[prefixLength] = '\0';
    long long prefix = strtoll(prefixText, NULL, 10);

    long long best = -1;
    long long bestDistance = 0;

    /* 位數改變時的兩個邊界回文，例如 1000 附近的 999 與 1001。 */
    long long edgeCandidates[2] = {
        powerOfTen(length - 1) - 1,
        powerOfTen(length) + 1
    };
    for (int i = 0; i < 2; ++i) {
        long long candidate = edgeCandidates[i];
        if (candidate == original) continue;
        long long distance = candidate > original ? candidate - original
                                                   : original - candidate;
        if (best == -1 || distance < bestDistance ||
            (distance == bestDistance && candidate < best)) {
            best = candidate;
            bestDistance = distance;
        }
    }

    for (int delta = -1; delta <= 1; ++delta) {
        long long adjustedPrefix = prefix + delta;
        if (adjustedPrefix < 0) continue;
        long long candidate = makePalindrome(adjustedPrefix, length);
        if (candidate == original) continue;
        long long distance = candidate > original ? candidate - original
                                                   : original - candidate;
        if (best == -1 || distance < bestDistance ||
            (distance == bestDistance && candidate < best)) {
            best = candidate;
            bestDistance = distance;
        }
    }

    char formatted[32];
    snprintf(formatted, sizeof formatted, "%lld", best);
    size_t answerLength = strlen(formatted);
    char *answer = (char *)malloc(answerLength + 1);
    if (answer == NULL) return NULL;
    memcpy(answer, formatted, answerLength + 1);
    return answer;
}

int main(void) {
    char input1[] = "123", input2[] = "1", input3[] = "10";
    char input4[] = "1000", input5[] = "99";
    char *answer1 = nearestPalindromic(input1);
    char *answer2 = nearestPalindromic(input2);
    char *answer3 = nearestPalindromic(input3);
    char *answer4 = nearestPalindromic(input4);
    char *answer5 = nearestPalindromic(input5);
    int passed = answer1 != NULL && strcmp(answer1, "121") == 0 &&
                 answer2 != NULL && strcmp(answer2, "0") == 0 &&
                 answer3 != NULL && strcmp(answer3, "9") == 0 &&
                 answer4 != NULL && strcmp(answer4, "999") == 0 &&
                 answer5 != NULL && strcmp(answer5, "101") == 0;
    free(answer1);
    free(answer2);
    free(answer3);
    free(answer4);
    free(answer5);
    puts(passed ? "PASS: 564 find-the-closest-palindrome"
                : "FAIL: 564 find-the-closest-palindrome");
    return passed ? 0 : 1;
}
