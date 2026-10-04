# 0421. Maximum XOR of Two Numbers in an Array《陣列中兩數的最大異或值》

- **Difficulty**: Medium
- **Tags**: array, hash-table, bit-manipulation, trie
- **題目連結**: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
- **程式碼**: [`421_maximum-xor-of-two-numbers-in-an-array.c`](./421_maximum-xor-of-two-numbers-in-an-array.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，找出任意 nums[i] 與 nums[j] 的位元異或值中最大者，其中 0 ≤ i ≤ j < n。陣列元素皆為非負且不超過 2^31 - 1。

**思路**：從最高位元起原地依該位元將數列分割成 0、1 兩組，優先遞迴配對不同位元的兩組以取得較大的異或值。若某位元不能形成有效分割，便繼續檢查更低位元。

## Problem Statement (English)

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
```

## 限制 Constraints

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int findMaximumXOR(int* nums, int numsSize){

}
```
