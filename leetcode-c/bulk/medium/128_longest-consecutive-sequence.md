# 0128. Longest Consecutive Sequence《最長連續序列》

- **Difficulty**: Medium
- **Tags**: array, hash-table, union-find
- **題目連結**: https://leetcode.com/problems/longest-consecutive-sequence/
- **程式碼**: [`128_longest-consecutive-sequence.c`](./128_longest-consecutive-sequence.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定未排序整數陣列 nums，回傳其中最長連續整數序列的長度。解法必須在 O(n) 時間內完成。nums 長度介於 0 至 10^5，元素值介於 -10^9 至 10^9。

**思路**：以自製雜湊表去重並記錄每段連續序列端點的長度；插入新值時合併其左右相鄰段，並更新兩端與最大長度。

## Problem Statement (English)

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Input: nums = [1,0,1,2]
Output: 3
```

## 限制 Constraints

0 <= nums.length <= 105
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
int longestConsecutive(int* nums, int numsSize) {
    
}
```
