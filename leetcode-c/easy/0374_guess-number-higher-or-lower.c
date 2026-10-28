/*
 * LeetCode 0374. Guess Number Higher or Lower《猜數字大小》
 * 難度：Easy；標籤：二分搜尋、互動式 API
 * 題目連結：https://leetcode.com/problems/guess-number-higher-or-lower/
 *
 * 題目說明：
 * 遊戲從 1 到 n 中選出一個數字。呼叫平台提供的 guess(num) API 後：若猜得
 * 太大回傳 -1，猜得太小回傳 1，猜中則回傳 0。請找出被選中的數字。
 *
 * 範例：
 * 1. n = 10，答案是 6，回傳 6。
 * 2. n = 1，答案是 1，回傳 1。
 * 3. n = 2，答案是 1，回傳 1。
 *
 * 限制：1 <= n <= 2^31 - 1；1 <= pick <= n。
 *
 * 解題思路：
 * 1. 候選範圍一開始是 [1, n]，每次猜中間值 mid。
 * 2. guess(mid) 回傳 0 時，mid 就是答案。
 * 3. 回傳 1 表示答案更大，將左界改成 mid + 1；回傳 -1 表示答案更小，
 *    將右界改成 mid - 1。
 * 4. 每次都排除約一半候選值，直到猜中。中點公式避免兩端相加造成溢位。
 *
 * 複雜度：O(log n) 次 API 呼叫，額外空間 O(1)。
 */
#include <assert.h>
#include <limits.h>
#include <stdio.h>

/* ===== LeetCode 提交函式：平台會提供 guess API ===== */
#ifndef LEETCODE_SUBMISSION
int guess(int num);
#endif

int guessNumber(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = guess(mid);
        if (result == 0) return mid;
        if (result > 0) left = mid + 1;  /* 答案比猜的數字大。 */
        else right = mid - 1;            /* 答案比猜的數字小。 */
    }
    return -1; /* 題目保證 pick 在範圍內，此處只作防護。 */
}

/* ===== 以下為本地測試；提交時只需提交上方 guessNumber ===== */
#ifndef LEETCODE_SUBMISSION
static int localPick;

int guess(int num) {
    if (num == localPick) return 0;
    return num < localPick ? 1 : -1;
}

int main(void) {
    localPick = 6;
    assert(guessNumber(10) == 6);
    localPick = 1;
    assert(guessNumber(1) == 1);
    localPick = 1;
    assert(guessNumber(2) == 1);
    localPick = INT_MAX;
    assert(guessNumber(INT_MAX) == INT_MAX);

    puts("PASS 0374 guessNumber");
    return 0;
}
#endif
