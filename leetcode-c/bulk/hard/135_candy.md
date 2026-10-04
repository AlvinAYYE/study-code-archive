# 0135. Candy《分發糖果》

- **Difficulty**: Hard
- **Tags**: array, greedy
- **題目連結**: https://leetcode.com/problems/candy/
- **程式碼**: [`135_candy.c`](./135_candy.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有 n 個排成一列的孩子，ratings[i] 表示第 i 個孩子的評分。每個孩子至少要拿一顆糖，且評分高於相鄰孩子者必須拿到更多糖。請回傳符合規則所需的最少糖果總數。n 介於 1 至 2×10^4，評分介於 0 至 2×10^4。

**思路**：先由左到右配置以滿足左鄰居的遞增關係，再由右到左補強較高評分者的糖果數並加總。

## Problem Statement (English)

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Return the minimum number of candies you need to have to distribute the candies to the children.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
```

## 限制 Constraints

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104

## 官方 C 函式簽名 Signature

```c
int candy(int* ratings, int ratingsSize) {
    
}
```
