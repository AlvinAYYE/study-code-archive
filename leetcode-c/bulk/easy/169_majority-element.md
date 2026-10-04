# 0169. Majority Element《多數元素》

- **Difficulty**: Easy
- **Tags**: array, hash-table, divide-and-conquer, sorting, counting
- **題目連結**: https://leetcode.com/problems/majority-element/
- **程式碼**: [`169_majority-element.c`](./169_majority-element.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定大小為 n 的整數陣列，請回傳出現次數超過 ⌊n / 2⌋ 的元素。題目保證多數元素一定存在。

**思路**：採 Boyer-Moore 投票法，維護候選值與計數；不同值抵銷計數，計數歸零時改選目前元素為候選者。

## Problem Statement (English)

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [3,2,3]
Output: 3

Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

## 限制 Constraints

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109

## 官方 C 函式簽名 Signature

```c
int majorityElement(int* nums, int numsSize) {
    
}
```
