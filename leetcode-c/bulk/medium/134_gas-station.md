# 0134. Gas Station《加油站》

- **Difficulty**: Medium
- **Tags**: array, greedy
- **題目連結**: https://leetcode.com/problems/gas-station/
- **程式碼**: [`134_gas-station.c`](./134_gas-station.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

圓環路線上有 n 個加油站，第 i 站可取得 gas[i] 單位汽油，走到下一站需消耗 cost[i] 單位。汽車油箱容量無限，從某站以空油箱出發。若能順時針繞行一圈，回傳起始站索引；否則回傳 -1，且若解存在則保證唯一。n 介於 1 至 10^5，gas 與 cost 的各元素介於 0 至 10^4。

**思路**：以首尾雙指針維護圓環中的候選區間與油量；油量不足就向前擴展起點，否則向後擴展終點，最後依總油量判斷候選起點是否可行。

## Problem Statement (English)

There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
```

## 限制 Constraints

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104
The input is generated such that the answer is unique.

## 官方 C 函式簽名 Signature

```c
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    
}
```
