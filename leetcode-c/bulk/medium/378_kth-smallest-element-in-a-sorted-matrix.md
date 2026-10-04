# 0378. Kth Smallest Element in a Sorted Matrix《有序矩陣中第 K 小的元素》

- **Difficulty**: Medium
- **Tags**: array, binary-search, sorting, heap-(priority-queue, matrix
- **題目連結**: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
- **程式碼**: [`378_kth-smallest-element-in-a-sorted-matrix.c`](./378_kth-smallest-element-in-a-sorted-matrix.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 n x n 矩陣，所有列與行皆以非遞減順序排列，回傳整體排序後第 k 小的元素。此處是第 k 個元素而非第 k 個相異元素，且額外記憶體複雜度須優於 O(n^2)。

**思路**：在矩陣最小值與最大值之間二分答案值；每次逐列掃描並計算不大於中值的元素數量，據此縮小範圍。

## Problem Statement (English)

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with a memory complexity better than O(n2).
Example 1:
Example 2:
Constraints:
Follow up:

## 範例 Examples

```text
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Input: matrix = [[-5]], k = 1
Output: -5
```

## 限制 Constraints

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2

## 官方 C 函式簽名 Signature

```c
int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    
}
```
