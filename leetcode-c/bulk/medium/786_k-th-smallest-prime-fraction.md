# 0786. K-th Smallest Prime Fraction《第 K 小的質數分數》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, binary-search, sorting, heap-(priority-queue
- **題目連結**: https://leetcode.com/problems/k-th-smallest-prime-fraction/
- **程式碼**: [`786_k-th-smallest-prime-fraction.c`](./786_k-th-smallest-prime-fraction.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定嚴格遞增且元素為 1 與質數的陣列 arr，考慮所有 i < j 的分數 arr[i] / arr[j]。回傳第 k 小分數的分子與分母；arr 長度最多為 1000。

**思路**：最小堆先放入每個分子搭配最大分母的分數；每次取出最小分數後將該分子的分母索引左移並重新入堆，取第 K 次彈出的分數。

## Problem Statement (English)

You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.

Input: arr = [1,7], k = 1
Output: [1,7]
```

## 限制 Constraints

2  0.
All the numbers of arr are unique and sorted in strictly increasing order.
1 <= k <= arr.length * (arr.length - 1) / 2

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
    
}
```
