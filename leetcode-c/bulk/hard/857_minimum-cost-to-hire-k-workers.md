# 0857. Minimum Cost to Hire K Workers《雇用 K 名工人的最低成本》

- **Difficulty**: Hard
- **Tags**: array, greedy, sorting, heap-(priority-queue
- **題目連結**: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
- **程式碼**: [`857_minimum-cost-to-hire-k-workers.c`](./857_minimum-cost-to-hire-k-workers.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

每名工人有品質 quality 與最低期望薪資 wage，必須恰好雇用 k 人。受雇者薪資須依品質成比例，且每人不得低於其最低期望薪資；回傳符合條件的最小總成本，允許 10⁻⁵ 誤差。

**思路**：程式依 wage/quality 比率遞增排序，將目前可用工人的品質加入集合。集合超過 K 人時線性移除最大的品質，並以目前比率乘上 K 人品質總和更新最小成本。

## Problem Statement (English)

There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.
We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
```

## 限制 Constraints

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104

## 官方 C 函式簽名 Signature

```c
double mincostToHireWorkers(int* quality, int qualitySize, int* wage, int wageSize, int k) {
    
}
```
