# 0275. H-Index II《H 指數 II》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/h-index-ii/
- **程式碼**: [`275_h-index-ii.c`](./275_h-index-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定已依非遞減順序排序的 citations，求研究者的 H 指數。H 指數是至少有 h 篇論文各自至少被引用 h 次時的最大 h，題目要求對數時間演算法。

**思路**：此程式從陣列尾端線性掃描，第 i 次檢查第 i+1 大引用數是否至少為 i+1。持續符合時更新 h，首次不符合便停止。

## Problem Statement (English)

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in non-descending order, return the researcher's h-index.
According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
You must write an algorithm that runs in logarithmic time.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: citations = [0,1,3,5,6]
Output: 3
Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had received 0, 1, 3, 5, 6 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Input: citations = [1,2,100]
Output: 2
```

## 限制 Constraints

n == citations.length
1 <= n <= 105
0 <= citations[i] <= 1000
citations is sorted in ascending order.

## 官方 C 函式簽名 Signature

```c
int hIndex(int* citations, int citationsSize) {
    
}
```
