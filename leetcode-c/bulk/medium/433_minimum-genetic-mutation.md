# 0433. Minimum Genetic Mutation《最小基因突變》

- **Difficulty**: Medium
- **Tags**: hash-table, string, breadth-first-search
- **題目連結**: https://leetcode.com/problems/minimum-genetic-mutation/
- **程式碼**: [`433_minimum-genetic-mutation.c`](./433_minimum-genetic-mutation.c) — 社群解答（repo Senthil455_Leetcode-Code），已通過編譯+官方示例執行驗證

## 題目說明（中文）

基因字串長度固定為 8，且只含 A、C、G、T；一次突變只能改變一個字元。給定起始基因、目標基因與有效基因庫，求到達目標所需的最少突變次數；每一步突變後的基因都必須在基因庫中，起始基因則不一定在庫內。無法到達時回傳 -1。

**思路**：以 BFS 從起始基因逐層擴展，尋找尚未訪問且恰好相差一個字元的基因庫項目。佇列節點一併保存步數，首次取到目標基因時即為最少突變數。

## Problem Statement (English)

A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
Note that the starting point is assumed to be valid, so it might not be included in the bank.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
```

## 限制 Constraints

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

## 官方 C 函式簽名 Signature

```c
int minMutation(char* startGene, char* endGene, char** bank, int bankSize) {
    
}
```
