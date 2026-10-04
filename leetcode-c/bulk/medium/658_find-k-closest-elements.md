# 0658. Find K Closest Elements《找到 K 個最接近的元素》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, binary-search, sliding-window, sorting, heap-(priority-queue
- **題目連結**: https://leetcode.com/problems/find-k-closest-elements/
- **程式碼**: [`658_find-k-closest-elements.c`](./658_find-k-closest-elements.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定遞增排序陣列、整數 k 與 x，回傳陣列中最接近 x 的 k 個整數，且結果仍須遞增排序。距離較小者較接近；若距離相同，數值較小者較接近。

**思路**：先以二分搜尋找出最接近 x 的位置，再從該位置向左右擴展長度為 k 的區間。兩端距離相等時優先取左側，最後直接複製連續區間。

## Problem Statement (English)

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
An integer a is closer to x than an integer b if:
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Input: arr = [1,1,2,3,4,5], k = 4, x = -1
Output: [1,1,2,3]
```

## 限制 Constraints

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    
}
```
