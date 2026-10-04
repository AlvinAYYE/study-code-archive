# 0274. H-Index《H 指數》

- **Difficulty**: Medium
- **Tags**: array, sorting, counting-sort
- **題目連結**: https://leetcode.com/problems/h-index/
- **程式碼**: [`274_h-index.c`](./274_h-index.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定 citations，其中 citations[i] 是研究者第 i 篇論文的引用數，求其 H 指數。H 指數為最大的 h，使至少有 h 篇論文各自至少被引用 h 次。

**思路**：建立大小為論文數加一的計數桶，將超過論文數的引用數歸入最後一桶。從高引用數往下累加論文篇數，首次滿足累計篇數不小於索引的位置即為答案。

## Problem Statement (English)

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

Input: citations = [1,3,1]
Output: 1
```

## 限制 Constraints

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int hIndex(int* citations, int citationsSize) {
    
}
```
