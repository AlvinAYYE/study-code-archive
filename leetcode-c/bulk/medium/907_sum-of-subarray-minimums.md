# 0907. Sum of Subarray Minimums《子陣列最小值之和》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/sum-of-subarray-minimums/
- **程式碼**: [`907_sum-of-subarray-minimums.c`](./907_sum-of-subarray-minimums.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 arr，對每個非空連續子陣列取其最小值並加總。由於結果可能很大，回傳結果對 10⁹+7 取模後的值。

**思路**：程式使用單調遞增索引堆疊，計算每個位置作為結尾時所有子陣列最小值的總和。遇到較小或相等元素便彈出堆疊，利用前一個較小元素與距離更新貢獻，再累加到答案。

## Problem Statement (English)

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Input: arr = [11,81,94,43,3]
Output: 444
```

## 限制 Constraints

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104

## 官方 C 函式簽名 Signature

```c
int sumSubarrayMins(int* arr, int arrSize) {
    
}
```
