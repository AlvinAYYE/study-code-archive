/*
 * LeetCode 2784. Check if Array Is Good
 * Title-CN: 檢查陣列是否良好
 * Difficulty: Easy
 * URL: https://leetcode.com/problems/check-if-array-is-good/
 *
 * [中文] 題目說明
 *     若陣列是 base[n] 的任意排列，就稱為 good，其中
 *     base[n] = [1,2,...,n-1,n,n]，長度為 n+1。也就是 1 到 n-1 各出現
 *     一次，最大值 n 恰好出現兩次。給定 nums，判斷它是否 good。
 *
 * [中文] 範例
 *     1. nums = [2,1,3]，輸出 false；最大值 3 時應有 4 個元素。
 *     2. nums = [1,3,3,2]，輸出 true，這是 base[3] 的排列。
 *     3. nums = [1,1]，輸出 true，這是 base[1]。
 *     4. nums = [3,4,4,1,2,1]，輸出 false；最大值 4 時應有 5 個元素。
 *
 * [中文] 限制
 *     - 1 <= nums.length <= 100。
 *     - 1 <= nums[i] <= 200。
 *
 * [中文] 解題步驟
 *     1. 找出陣列最大值 n；若陣列長度不是 n+1，立即回傳 false。
 *     2. 統計每個數字的次數，確認 1 到 n-1 各出現一次，n 出現兩次。
 *     3. 全部符合才是 good。時間 O(n + 200)，額外空間 O(200)。
 *
 * LeetCode C 函式簽名：bool isGood(int* nums, int numsSize)
 */
#include <stdio.h>
#include <stdbool.h>

bool isGood(int *nums, int numsSize) {
    int count[201] = {0};
    int largest = 0, i;
    for (i = 0; i < numsSize; ++i) {
        ++count[nums[i]];
        if (nums[i] > largest) largest = nums[i];
    }
    if (numsSize != largest + 1 || count[largest] != 2) return false;
    for (i = 1; i < largest; ++i) {
        if (count[i] != 1) return false;
    }
    return true;
}

int main(void) {
    int ok = 1;
    int a[] = {2, 1, 3}, b[] = {1, 3, 3, 2};
    int c[] = {1, 1}, d[] = {3, 4, 4, 1, 2, 1};
    ok = ok && !isGood(a, 3);
    ok = ok && isGood(b, 4);
    ok = ok && isGood(c, 2);
    ok = ok && !isGood(d, 6);
    printf("%s: 2784 check-if-array-is-good\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
