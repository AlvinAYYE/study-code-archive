# 0849. Maximize Distance to Closest Person《到最近人的最大距離》

- **Difficulty**: Medium
- **Tags**: array
- **題目連結**: https://leetcode.com/problems/maximize-distance-to-closest-person/
- **程式碼**: [`849_maximize-distance-to-closest-person.c`](./849_maximize-distance-to-closest-person.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

seats 陣列中 1 表示已有人入座、0 表示空位，且至少各有一個。選擇一個空位，使自己到最近已坐下者的距離盡可能大，並回傳該最大距離。

**思路**：程式計算每段連續空位的長度。開頭或結尾的空位段可直接取其長度，中間空位段則取長度的一半向上取整，並保留最大值。

## Problem Statement (English)

You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
There is at least one empty seat, and at least one person sitting.
Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.
Return that maximum distance to the closest person.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

Input: seats = [0,1]
Output: 1
```

## 限制 Constraints

2 <= seats.length <= 2 * 104
seats[i] is 0 or 1.
At least one seat is empty.
At least one seat is occupied.

## 官方 C 函式簽名 Signature

```c
int maxDistToClosest(int* seats, int seatsSize) {
    
}
```
