# 0060. Permutation Sequence《第 k 個排列》

- **Difficulty**: Hard
- **Tags**: math, recursion
- **題目連結**: https://leetcode.com/problems/permutation-sequence/
- **程式碼**: [`060_permutation-sequence.c`](./060_permutation-sequence.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

集合 `[1,2,3,...,n]` 共有 `n!` 個不同排列。將所有排列依字典順序從 1 開始編號，給定 `n` 與 `k`，請回傳第 `k` 個排列所組成的字串。

## 解題思路

1. 固定第一位後，其餘 `n-1` 個數字共有 `(n-1)!` 種排列，因此全部排列可依第一位分成大小相同的區塊。
2. 先將 `k` 減一改為從 0 起算；`k/(n-1)!` 就是目前應選的可用數字索引。
3. 選定數字後，從候選陣列移除它，再以 `k` 對區塊大小取餘數。
4. 反覆縮小階乘區塊，直到剩下最後兩個數字；剩餘的 `k` 只會決定原順序或相反順序。
5. `n == 1` 時唯一答案就是 `"1"`。

每一位選完後都可能搬移候選陣列，時間複雜度為 `O(n^2)`，額外空間為 `O(n)`。

## Problem Statement (English)

The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
Given n and k, return the kth permutation sequence.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：n = 3, k = 3
輸出："213"

輸入：n = 4, k = 9
輸出："2314"

輸入：n = 3, k = 1
輸出："123"
```

## 限制

- `1 <= n <= 9`
- `1 <= k <= n!`

## 官方 C 函式簽名 Signature

```c
char* getPermutation(int n, int k) {
    
}
```
