/*
 * LeetCode 0667. Beautiful Arrangement II（優美排列 II）
 * Difficulty: Medium
 * 題意：請建立一個由 1 到 n 組成的排列，使相鄰元素差的絕對值恰好有 k 種不同結果。回傳任何一個符合條件的排列。
 * 範例：
 *   1. 輸入：n = 3，k = 1；輸出：[1,2,3]。相鄰差只有 1 種。
 *   2. 輸入：n = 3，k = 2；輸出：[1,3,2]。相鄰差為 2 和 1。
 * 限制：
 *   - 1 <= k < n <= 10^4
 * 解法：
 *   1. 先從低端和高端交錯取值，產生大的、小的差值。
 *   2. 從低端開始取 k+1 個數，每一步交替取目前最小值和最大值。這會產生 k 種不同的相鄰差。
 *   3. 剩下未使用的數字依序遞增放入，新增的相鄰差都等於 1，不會增加其他差值種類。
 *   4. 回傳這個由 1 到 n 各用一次的排列。
 * 複雜度：時間 O(n)，額外空間 O(n)（回傳陣列）。
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ---- community solution ---- */
int* constructArray(int n, int k, int* returnSize) {
    int *answer = (int *)malloc(sizeof(int) * (size_t)n);
    if (answer == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int low = 1;
    int high = k + 1;
    int position = 0;

    // 交替從兩端取值，形成 k 個不同的相鄰差。
    for (int step = 0; step <= k; step++) {
        if (step % 2 == 0) {
            answer[position++] = low++;
        } else {
            answer[position++] = high--;
        }
    }
    // 前 k+1 個數已涵蓋 1 到 k+1；剩下的數由小到大接在後面，
    // 後續相鄰差都只是 1，不會新增不同差值。
    for (int value = k + 2; value <= n; value++) {
        answer[position++] = value;
    }

    *returnSize = n;
    return answer;
}

/* ---- generated tests ---- */
static bool checkConstructedArray(int n, int k) {
    int size = 0;
    int *values = constructArray(n, k, &size);
    if (values == NULL || size != n) {
        free(values);
        return false;
    }

    bool seenValue[10001] = {false};
    bool seenDifference[10001] = {false};
    int distinctDifferences = 0;
    bool valid = true;
    for (int i = 0; i < n; i++) {
        if (values[i] < 1 || values[i] > n || seenValue[values[i]]) {
            valid = false;
        } else {
            seenValue[values[i]] = true;
        }
        if (i > 0) {
            int difference = values[i] - values[i - 1];
            if (difference < 0) {
                difference = -difference;
            }
            if (!seenDifference[difference]) {
                seenDifference[difference] = true;
                distinctDifferences++;
            }
        }
    }
    free(values);
    return valid && distinctDifferences == k;
}

int main(void) {
    bool passed = checkConstructedArray(3, 1) &&
                  checkConstructedArray(3, 2) &&
                  checkConstructedArray(8, 5);
    printf("%s: 0667 constructArray tests=3\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
