# 0458. Poor Pigs《可憐的小豬》

- **Difficulty**: Hard
- **Tags**: math, dynamic-programming, combinatorics
- **題目連結**: https://leetcode.com/problems/poor-pigs/
- **程式碼**: [`458_poor-pigs.c`](./458_poor-pigs.c) — 社群解答（repo tongtzeho_LeetCode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

有 buckets 桶液體且恰有一桶有毒，喝到毒液的豬會在 minutesToDie 分鐘後死亡。你可在 minutesToTest 的時限內分輪餵食並觀察結果，以判定毒桶。回傳保證找出毒桶所需的最少豬隻數。

**思路**：每隻豬有「各測試輪死亡」或「存活」共 minutesToTest / minutesToDie + 1 種可辨識狀態。程式以對數計算最小豬數，使狀態組合數至少涵蓋所有桶子。

## Problem Statement (English)

There are buckets buckets of liquid, where exactly one of the buckets is poisonous. To figure out which one is poisonous, you feed some number of (poor) pigs the liquid to see whether they will die or not. Unfortunately, you only have minutesToTest minutes to determine which bucket is poisonous.
You can feed the pigs according to these steps:
Given buckets, minutesToDie, and minutesToTest, return the minimum number of pigs needed to figure out which bucket is poisonous within the allotted time.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: buckets = 4, minutesToDie = 15, minutesToTest = 15
Output: 2
Explanation: We can determine the poisonous bucket as follows:
At time 0, feed the first pig buckets 1 and 2, and feed the second pig buckets 2 and 3.
At time 15, there are 4 possible outcomes:
- If only the first pig dies, then bucket 1 must be poisonous.
- If only the second pig dies, then bucket 3 must be poisonous.
- If both pigs die, then bucket 2 must be poisonous.
- If neither pig dies, then bucket 4 must be poisonous.

Input: buckets = 4, minutesToDie = 15, minutesToTest = 30
Output: 2
Explanation: We can determine the poisonous bucket as follows:
At time 0, feed the first pig bucket 1, and feed the second pig bucket 2.
At time 15, there are 2 possible outcomes:
- If either pig dies, then the poisonous bucket is the one it was fed.
- If neither pig dies, then feed the first pig bucket 3, and feed the second pig bucket 4.
At time 30, one of the two pigs must die, and the poisonous bucket is the one it was fed.
```

## 限制 Constraints

1 <= buckets <= 1000
1 <= minutesToDie <= minutesToTest <= 100

## 官方 C 函式簽名 Signature

```c
int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    
}
```
