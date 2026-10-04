# 0239. Sliding Window Maximum《滑動視窗最大值》

- **Difficulty**: Hard
- **Tags**: array, queue, sliding-window, heap-(priority-queue, monotonic-queue
- **題目連結**: https://leetcode.com/problems/sliding-window-maximum/
- **程式碼**: [`239_sliding-window-maximum.c`](./239_sliding-window-maximum.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與大小為 k 的滑動視窗，視窗每次向右移動一格。回傳每個視窗中的最大值。

**思路**：先計算第一個視窗最大值；之後若新進元素更大便直接更新。若離開元素正是前一最大值則重新掃描該視窗，否則沿用前一最大值。

## Problem Statement (English)

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Input: nums = [1], k = 1
Output: [1]
```

## 限制 Constraints

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    
}
```
