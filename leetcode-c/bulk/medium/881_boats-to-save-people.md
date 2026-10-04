# 0881. Boats to Save People《救生艇》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, greedy, sorting
- **題目連結**: https://leetcode.com/problems/boats-to-save-people/
- **程式碼**: [`881_boats-to-save-people.c`](./881_boats-to-save-people.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

每艘船承重上限為 limit，且同時最多載兩人；people[i] 是第 i 人的體重。計算載運所有人所需的最少船數。

**思路**：程式先將體重排序，再用首尾雙指標處理最輕與最重的人。每次必定讓最重者上船；若能與最輕者合載便一併移動左指標。

## Problem Statement (English)

You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Return the minimum number of boats to carry every given person.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
```

## 限制 Constraints

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104

## 官方 C 函式簽名 Signature

```c
int numRescueBoats(int* people, int peopleSize, int limit) {
    
}
```
