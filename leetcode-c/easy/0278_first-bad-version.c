/*
 * LeetCode 0278. First Bad Version《第一個錯誤的版本》
 * 難度：Easy；標籤：二分搜尋、互動式 API
 * 題目連結：https://leetcode.com/problems/first-bad-version/
 *
 * 題目說明：
 * 產品有版本 1 到 n。某個版本開始品質檢查失敗，而且從那一版之後的
 * 所有版本都會失敗。平台提供 isBadVersion(version) API，回傳指定版本
 * 是否為錯誤版本。請找出最早的錯誤版本，並盡量減少 API 呼叫次數。
 *
 * 範例：
 * 1. n = 5，第一個錯誤版本是 4，回傳 4。
 *    查詢 3 得到正常、查詢 5 得到錯誤、查詢 4 得到錯誤，因此答案是 4。
 * 2. n = 1，第一個錯誤版本是 1，回傳 1。
 *
 * 限制：1 <= bad <= n <= 2^31 - 1。
 *
 * 解題思路：
 * 1. 目前答案一定在 [1, n]，取中間版本 mid 並呼叫 API。
 * 2. 若 mid 是錯誤版本，第一個錯誤版本只可能是 mid 或更早，令右界為 mid。
 * 3. 若 mid 正常，第一個錯誤版本必定在 mid 之後，令左界為 mid + 1。
 * 4. 左右界相遇時就是第一個錯誤版本。中點寫成 left + (right-left)/2，
 *    避免 left + right 溢位。
 *
 * 複雜度：O(log n) 次 API 呼叫，額外空間 O(1)。
 */
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/* ===== LeetCode 提交函式：平台會提供 isBadVersion API ===== */
#ifndef LEETCODE_SUBMISSION
bool isBadVersion(int version);
#endif

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid;       /* mid 可能就是答案，保留它。 */
        } else {
            left = mid + 1;    /* mid 正常，答案一定更大。 */
        }
    }
    return left;
}

/* ===== 以下為本地測試；提交時只需提交上方 firstBadVersion ===== */
#ifndef LEETCODE_SUBMISSION
static int localFirstBad;

bool isBadVersion(int version) {
    return version >= localFirstBad;
}

int main(void) {
    localFirstBad = 4;
    assert(firstBadVersion(5) == 4);

    localFirstBad = 1;
    assert(firstBadVersion(1) == 1);

    localFirstBad = INT_MAX;
    assert(firstBadVersion(INT_MAX) == INT_MAX);

    puts("PASS 0278 firstBadVersion");
    return 0;
}
#endif
