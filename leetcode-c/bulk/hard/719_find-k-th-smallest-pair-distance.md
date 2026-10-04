# 0719. Find K-th Smallest Pair Distance《找出第 K 小的數對距離》

- **Difficulty**: Hard
- **Tags**: array, two-pointers, binary-search, sorting
- **題目連結**: https://leetcode.com/problems/find-k-th-smallest-pair-distance/
- **程式碼**: [`719_find-k-th-smallest-pair-distance.c`](./719_find-k-th-smallest-pair-distance.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

整數對 a、b 的距離定義為其絕對差。給定 nums 與 k，請在所有 i < j 的數對距離中回傳第 k 小的距離。

**思路**：先排序陣列，對可能距離做二分搜尋；每個中點以雙指針計算距離不超過它的數對數量。依計數是否小於 k 縮小搜尋範圍。

## Problem Statement (English)

The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Input: nums = [1,1,1], k = 2
Output: 0

Input: nums = [1,6,1], k = 3
Output: 5
```

## 限制 Constraints

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2

## 官方 C 函式簽名 Signature

```c
int smallestDistancePair(int* nums, int numsSize, int k) {
    
}
```
