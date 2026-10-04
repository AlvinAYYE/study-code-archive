# 0930. Binary Subarrays With Sum《和相同的二進位子陣列》

- **Difficulty**: Medium
- **Tags**: array, hash-table, sliding-window, prefix-sum
- **題目連結**: https://leetcode.com/problems/binary-subarrays-with-sum/
- **程式碼**: [`930_binary-subarrays-with-sum.c`](./930_binary-subarrays-with-sum.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二進位陣列 nums 與整數 goal，請計算元素總和恰為 goal 的非空連續子陣列數量。子陣列必須是原陣列中的連續區段。

**思路**：使用前綴和及其出現次數表；掃描到目前前綴和時，先累加先前值為「目前和減 goal」的次數，再記錄目前和。

## Problem Statement (English)

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
```

## 限制 Constraints

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length

## 官方 C 函式簽名 Signature

```c
int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    
}
```
