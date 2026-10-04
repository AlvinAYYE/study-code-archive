# 0605. Can Place Flowers《種花問題》

- **Difficulty**: Easy
- **Tags**: array, greedy
- **題目連結**: https://leetcode.com/problems/can-place-flowers/
- **程式碼**: [`605_can-place-flowers.c`](./605_can-place-flowers.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

花圃陣列中 0 代表空位、1 代表已種花，且相鄰位置不可同時種花。判斷是否能在不違反相鄰限制下，再種下至少 n 朵花。原本的花圃也保證沒有相鄰的花。

**思路**：掃描既有花朵之間的空位區段，依可用間隔直接累加可新增的花數。程式以 -2 與花圃長度加 1 作為兩端哨兵，統一處理開頭和結尾的空位。

## Problem Statement (English)

You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
```

## 限制 Constraints

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length

## 官方 C 函式簽名 Signature

```c
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    
}
```
