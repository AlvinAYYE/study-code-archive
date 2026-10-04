# 0220. Contains Duplicate III《存在重複元素 III》

- **Difficulty**: Hard
- **Tags**: array, sliding-window, sorting, bucket-sort, ordered-set
- **題目連結**: https://leetcode.com/problems/contains-duplicate-iii/
- **程式碼**: [`220_contains-duplicate-iii.c`](./220_contains-duplicate-iii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 nums、indexDiff 與 valueDiff，找出兩個不同索引 i、j。其索引差絕對值須不大於 indexDiff，且對應數值差絕對值須不大於 valueDiff；存在即回傳 true。

**思路**：將數值與索引配對並按數值排序，對每個元素向後枚舉仍在 valueDiff 範圍內的元素。若其中任何一對的索引差不超過 k，便回傳 true。

## Problem Statement (English)

You are given an integer array nums and two integers indexDiff and valueDiff.
Find a pair of indices (i, j) such that:
Return true if such pair exists or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0

Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
Output: false
Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
```

## 限制 Constraints

2 <= nums.length <= 105
-109 <= nums[i] <= 109
1 <= indexDiff <= nums.length
0 <= valueDiff <= 109

## 官方 C 函式簽名 Signature

```c
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff) {
    
}
```
