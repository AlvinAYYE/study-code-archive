# 0875. Koko Eating Bananas《珂珂吃香蕉》

- **Difficulty**: Medium
- **Tags**: array, binary-search
- **題目連結**: https://leetcode.com/problems/koko-eating-bananas/
- **程式碼**: [`875_koko-eating-bananas.c`](./875_koko-eating-bananas.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

珂珂有多堆香蕉，必須在 h 小時內吃完；每小時可選一堆吃最多 k 根，若該堆不足 k 則該小時只吃完那一堆。回傳能及時吃完的最小整數速度 k。

**思路**：程式對速度 1 到 10⁹ 進行二分搜尋。對候選速度累加每堆所需的向上取整小時數，依是否超過 h 縮小搜尋區間。

## Problem Statement (English)

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: piles = [3,6,7,11], h = 8
Output: 4

Input: piles = [30,11,23,4,20], h = 5
Output: 30

Input: piles = [30,11,23,4,20], h = 6
Output: 23
```

## 限制 Constraints

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

## 官方 C 函式簽名 Signature

```c
int minEatingSpeed(int* piles, int pilesSize, int h) {
    
}
```
