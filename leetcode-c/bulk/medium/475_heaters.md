# 0475. Heaters《供暖器》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, binary-search, sorting
- **題目連結**: https://leetcode.com/problems/heaters/
- **程式碼**: [`475_heaters.c`](./475_heaters.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定水平線上所有房屋與供暖器的位置，所有供暖器必須使用相同的供暖半徑。回傳能覆蓋全部房屋的最小半徑。

**思路**：程式先排序房屋與供暖器，隨房屋由左到右掃描時將供暖器指標移到較近的下一台。所有房屋到最近供暖器距離的最大值就是答案。

## Problem Statement (English)

Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
Every house can be warmed, as long as the house is within the heater's warm radius range.
Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
Notice that all the heaters follow your radius standard, and the warm radius will the same.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: houses = [1,2,3], heaters = [2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

Input: houses = [1,2,3,4], heaters = [1,4]
Output: 1
Explanation: The two heaters were placed at positions 1 and 4. We need to use a radius 1 standard, then all the houses can be warmed.

Input: houses = [1,5], heaters = [2]
Output: 3
```

## 限制 Constraints

1 <= houses.length, heaters.length <= 3 * 104
1 <= houses[i], heaters[i] <= 109

## 官方 C 函式簽名 Signature

```c
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    
}
```
