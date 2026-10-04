# 0799. Champagne Tower《香檳塔》

- **Difficulty**: Medium
- **Tags**: dynamic-programming
- **題目連結**: https://leetcode.com/problems/champagne-tower/
- **程式碼**: [`799_champagne-tower.c`](./799_champagne-tower.c) — 社群解答（repo ourhouchmohamed97_LeetCode_in_C），已通過編譯+官方示例執行驗證

## 題目說明（中文）

香檳杯依金字塔排列，每杯容量為 1 杯；滿出的液體會平均流到下一列左右兩杯。倒入 poured 杯香檳後，回傳第 query_row 列第 query_glass 杯的滿度，列與杯索引皆從 0 起算且列數小於 100。

**思路**：以二維陣列模擬每杯收到的總量，將超過 1 的部分各分一半流向下一列兩杯，最後把查詢杯的量截為最多 1。

## Problem Statement (English)

We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.
Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)
For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.
Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is (both i and j are 0-indexed.)
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: poured = 1, query_row = 1, query_glass = 1
Output: 0.00000
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.

Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.

Input: poured = 100000009, query_row = 33, query_glass = 17
Output: 1.00000
```

## 限制 Constraints

0 <= poured <= 109
0 <= query_glass <= query_row < 100

## 官方 C 函式簽名 Signature

```c
double champagneTower(int poured, int query_row, int query_glass){

}
```
