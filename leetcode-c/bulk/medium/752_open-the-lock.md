# 0752. Open the Lock《打開轉盤鎖》

- **Difficulty**: Medium
- **Tags**: array, hash-table, string, breadth-first-search
- **題目連結**: https://leetcode.com/problems/open-the-lock/
- **程式碼**: [`752_open-the-lock.c`](./752_open-the-lock.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

四位轉盤鎖從 0000 開始，每次可將任一位向上或向下轉一格，且 9 與 0 可循環相接。給定無法通過的 deadends 與目標 target，求到達 target 的最少轉動次數；若起點或路徑受死鎖限制而無法到達則回傳 -1。

**思路**：以 BFS 從 0000 展開狀態，對每個轉盤位置產生加一與減一共八個鄰居。四維標記表同時記錄死鎖與已拜訪狀態，首次抵達目標的層數就是最少轉動數。

## Problem Statement (English)

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.
```

## 限制 Constraints

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.

## 官方 C 函式簽名 Signature

```c
int openLock(char** deadends, int deadendsSize, char* target) {
    
}
```
