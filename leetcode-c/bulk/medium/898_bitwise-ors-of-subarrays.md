# 0898. Bitwise ORs of Subarrays《子陣列的按位或》

- **Difficulty**: Medium
- **Tags**: array, dynamic-programming, bit-manipulation
- **題目連結**: https://leetcode.com/problems/bitwise-ors-of-subarrays/
- **程式碼**: [`898_bitwise-ors-of-subarrays.c`](./898_bitwise-ors-of-subarrays.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 arr，計算所有非空連續子陣列的按位或結果中，有多少個相異值。單一元素子陣列的按位或即為該元素本身。

**思路**：程式維護所有以目前位置結尾之子陣列的相異 OR 值，將前一輪每個值與新元素 OR 後去重。另以全域雜湊表記錄所有出現過的結果並累加其數量。

## Problem Statement (English)

Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.

Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
```

## 限制 Constraints

1 <= arr.length <= 5 * 104
0 <= arr[i] <= 109

## 官方 C 函式簽名 Signature

```c
int subarrayBitwiseORs(int* arr, int arrSize) {
    
}
```
