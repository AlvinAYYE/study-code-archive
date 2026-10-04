# 0952. Largest Component Size by Common Factor《按公因數連通的最大元件大小》

- **Difficulty**: Hard
- **Tags**: array, hash-table, math, union-find, number-theory
- **題目連結**: https://leetcode.com/problems/largest-component-size-by-common-factor/
- **程式碼**: [`952_largest-component-size-by-common-factor.c`](./952_largest-component-size-by-common-factor.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定互不相同的正整數陣列 nums，將每個數字視為圖中的節點。若兩數的最大公因數大於 1，兩節點之間便有一條邊。請回傳圖中最大連通元件的大小。

**思路**：程式枚舉每個數字的因數，透過並查集把數字與其因數及互補因數合併；最後依各數字所屬根節點統計元件計數並取最大值。

## Problem Statement (English)

You are given an integer array of unique positive integers nums. Consider the following graph:
Return the size of the largest connected component in the graph.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [4,6,15,35]
Output: 4

Input: nums = [20,50,9,63]
Output: 2

Input: nums = [2,3,6,7,4,12,21,39]
Output: 8
```

## 限制 Constraints

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 105
All the values of nums are unique.

## 官方 C 函式簽名 Signature

```c
int largestComponentSize(int* nums, int numsSize) {
    
}
```
