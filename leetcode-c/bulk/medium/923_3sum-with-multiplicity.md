# 0923. 3Sum With Multiplicity《三數之和的多重性》

- **Difficulty**: Medium
- **Tags**: array, hash-table, two-pointers, sorting, counting
- **題目連結**: https://leetcode.com/problems/3sum-with-multiplicity/
- **程式碼**: [`923_3sum-with-multiplicity.c`](./923_3sum-with-multiplicity.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 arr 與整數 target，計算滿足 i < j < k 且 arr[i] + arr[j] + arr[k] = target 的三元組數量。答案可能很大，請對 10⁹ + 7 取模後回傳。

**思路**：排序後取出不同數值與其頻率，枚舉前兩個遞增值並由 target 算出第三值。對每種合法三值組合，依重複情形用組合數從頻率中計算可選索引數。

## Problem Statement (English)

Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
As the answer can be very large, return it modulo 109 + 7.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.

Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.

Input: arr = [2,1,3], target = 6
Output: 1
Explanation: (1, 2, 3) occured one time in the array so we return 1.
```

## 限制 Constraints

3 <= arr.length <= 3000
0 <= arr[i] <= 100
0 <= target <= 300

## 官方 C 函式簽名 Signature

```c
int threeSumMulti(int* arr, int arrSize, int target) {
    
}
```
