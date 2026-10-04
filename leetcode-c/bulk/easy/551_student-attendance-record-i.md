# 0551. Student Attendance Record I《學生出席紀錄 I》

- **Difficulty**: Easy
- **Tags**: string
- **題目連結**: https://leetcode.com/problems/student-attendance-record-i/
- **程式碼**: [`551_student-attendance-record-i.c`](./551_student-attendance-record-i.c) — 社群解答（repo DimitrisJim_leetcode_solutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定學生的出席字串，A、L、P 分別表示缺席、遲到與到場。只有缺席少於 2 次且從未連續遲到 3 天以上時，學生才符合獎勵資格。

**思路**：一次掃描紀錄缺席次數與連續 L 的長度；缺席達 2 次或連續遲到達 3 次立即回傳 false。

## Problem Statement (English)

You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:
The student is eligible for an attendance award if they meet both of the following criteria:
Return true if the student is eligible for an attendance award, or false otherwise.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: s = "PPALLP"
Output: true
Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.

Input: s = "PPALLL"
Output: false
Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.
```

## 限制 Constraints

1 <= s.length <= 1000
s[i] is either 'A', 'L', or 'P'.

## 官方 C 函式簽名 Signature

```c
bool checkRecord(char* s) {
    
}
```
