# 0135. Candy《分發糖果》

- **Difficulty**: Hard
- **Tags**: array, greedy
- **題目連結**: https://leetcode.com/problems/candy/
- **程式碼**: [`135_candy.c`](./135_candy.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有 `n` 個排成一列的孩子，`ratings[i]` 表示第 `i` 個孩子的評分。每個孩子至少要拿一顆糖；評分高於相鄰孩子者必須拿到更多糖。請回傳符合規則所需的最少糖果總數。

## 解題思路

1. 每個孩子先至少分到一顆糖。
2. 從左往右掃描；若 `ratings[i] > ratings[i-1]`，令 `candies[i]` 比左鄰居多一顆，否則維持一顆。這一趟滿足所有「高於左鄰居」的限制。
3. 再從右往左掃描；若目前評分高於右鄰居，但糖果沒有更多，就補成右鄰居加一顆。保留較大值可避免破壞第一趟已滿足的限制。
4. 第二趟同步累加每個孩子最後的糖果數，即得到最少總數。

演算法做兩次線性掃描，時間複雜度為 `O(n)`，糖果陣列使用 `O(n)` 額外空間。

## Problem Statement (English)

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Return the minimum number of candies you need to have to distribute the candies to the children.
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：ratings = [1,0,2]
輸出：5
說明：依序分配 [2,1,2] 顆糖即可滿足規則。

輸入：ratings = [1,2,2]
輸出：4
說明：可分配 [1,2,1]；相同評分之間不要求糖果數相同或遞增。
```

## 限制

- `n == ratings.length`
- `1 <= n <= 2 * 10^4`
- `0 <= ratings[i] <= 2 * 10^4`

## 官方 C 函式簽名 Signature

```c
int candy(int* ratings, int ratingsSize) {
    
}
```
