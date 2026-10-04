# 0474. Ones and Zeroes《一和零》

- **Difficulty**: Medium
- **Tags**: array, string, dynamic-programming
- **題目連結**: https://leetcode.com/problems/ones-and-zeroes/
- **程式碼**: [`474_ones-and-zeroes.c`](./474_ones-and-zeroes.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定二進位字串陣列 strs，以及 0 的上限 m 與 1 的上限 n。請找出所選字串合計不超過兩個上限時，能選出的最大子集合大小。

**思路**：先計算每個字串含有的 0 與 1，再做二維 0/1 背包動態規劃。容量倒序更新，確保每個字串最多只能選一次。

## Problem Statement (English)

You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
```

## 限制 Constraints

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] consists only of digits '0' and '1'.
1 <= m, n <= 100

## 官方 C 函式簽名 Signature

```c
int findMaxForm(char** strs, int strsSize, int m, int n) {
    
}
```
