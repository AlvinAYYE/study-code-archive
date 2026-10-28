/*
 * Title-CN: 最小好進制
 * LeetCode 483. Smallest Good Base
 *
 * 題意翻譯：給定一個大於 2 的整數 n（以十進位字串提供），找最小的進制 k，
 * 使 n 在 k 進位表示時每一位都是 1。回傳 k 的十進位字串。
 *
 * 範例：n = "13"，回傳 "3"，因為 13 = 1 + 3 + 3^2。
 * 說明：也可以用進制 12 寫成 "11"，但進制 3 更小。
 *
 * 限制：3 <= n <= 10^18。
 *
 * 解題思路：若表示有 m+1 個 1，就有 n = 1+k+k^2+...+k^m。先從可能的最大項數
 * （最多約 60 項）往下試。固定項數後，左側會隨 k 增加而增加，因此對 k 做二分搜尋。
 * 計算等比和時，每次乘法和加法前先檢查是否會超過 n，避免整數溢位。
 * 項數越多時找到的進制通常越小，所以第一個找到的答案就是最小好進制。
 *
 * 複雜度：O((log n)^3)，最多 O(log n) 種項數，每種二分搜尋 O(log n) 次，
 * 每次計算等比和 O(log n)；額外空間 O(1)。
 * LeetCode 介面：保留 smallestGoodBase；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int compareGeometricSum(unsigned long long base, int exponent,
                               unsigned long long target) {
    unsigned long long sum = 1;
    unsigned long long term = 1;
    for (int power = 1; power <= exponent; ++power) {
        if (term > target / base) return 1;
        term *= base;
        if (term > target - sum) return 1;
        sum += term;
    }
    return sum == target ? 0 : -1;
}

char *smallestGoodBase(char *n) {
    unsigned long long target = strtoull(n, NULL, 10);

    /* n <= 10^18，若 k >= 2，超過 60 次方項數一定已大於 n。 */
    for (int exponent = 60; exponent >= 1; --exponent) {
        unsigned long long low = 2;
        unsigned long long high = target - 1;
        while (low <= high) {
            unsigned long long base = low + (high - low) / 2;
            int comparison = compareGeometricSum(base, exponent, target);
            if (comparison == 0) {
                char *answer = malloc(32);
                if (answer == NULL) return NULL;
                snprintf(answer, 32, "%llu", base);
                return answer;
            }
            if (comparison < 0) low = base + 1;
            else high = base - 1;
        }
    }
    return NULL; /* 依題目條件一定存在解：進制 n-1 可表示成 11。 */
}

static unsigned long long bruteSmallestBase(unsigned long long target) {
    for (unsigned long long base = 2; base < target; ++base) {
        unsigned long long sum = 1;
        unsigned long long term = 1;
        while (term <= target / base) {
            term *= base;
            if (term > target - sum) break;
            sum += term;
            if (sum == target) return base;
        }
    }
    return target - 1;
}

int main(void) {
    char thirteen[] = "13";
    char three[] = "3";
    char large[] = "1000000000000000000";
    char *answer = smallestGoodBase(thirteen);
    assert(answer != NULL && answer[0] == '3' && answer[1] == '\0');
    free(answer);
    answer = smallestGoodBase(three);
    assert(answer != NULL && answer[0] == '2' && answer[1] == '\0');
    free(answer);
    answer = smallestGoodBase(large);
    assert(answer != NULL && strcmp(answer, "999999999999999999") == 0);
    free(answer);

    for (unsigned long long value = 3; value <= 500; ++value) {
        char input[32];
        snprintf(input, sizeof(input), "%llu", value);
        answer = smallestGoodBase(input);
        assert(answer != NULL && strtoull(answer, NULL, 10) == bruteSmallestBase(value));
        free(answer);
    }
    return 0;
}
