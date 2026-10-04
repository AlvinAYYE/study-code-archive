# 0945. Minimum Increment to Make Array Unique《使陣列元素互不相同的最少遞增次數》

- **Difficulty**: Medium
- **Tags**: array, greedy, sorting, counting
- **題目連結**: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
- **程式碼**: [`945_minimum-increment-to-make-array-unique.c`](./945_minimum-increment-to-make-array-unique.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，每次操作可選一個索引並將 nums[i] 增加 1。請回傳使所有元素值皆互不相同所需的最少操作次數；測資保證答案可放入 32 位元整數。

**思路**：以計數陣列找出重複值，將多出的副本依值放入佇列；由小到大掃描空缺值，依序把最早的重複值補到空缺並累計增加量。

## Problem Statement (English)

You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
Return the minimum number of moves to make every value in nums unique.
The test cases are generated so that the answer fits in a 32-bit integer.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].

Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown that it is impossible for the array to have all unique values with 5 or less moves.
```

## 限制 Constraints

1 <= nums.length <= 105
0 <= nums[i] <= 105

## 官方 C 函式簽名 Signature

```c
int minIncrementForUnique(int* nums, int numsSize) {
    
}
```
