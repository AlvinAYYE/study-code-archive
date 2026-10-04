# 0630. Course Schedule III《課程表 III》

- **Difficulty**: Hard
- **Tags**: array, greedy, sorting, heap-(priority-queue
- **題目連結**: https://leetcode.com/problems/course-schedule-iii/
- **程式碼**: [`630_course-schedule-iii.c`](./630_course-schedule-iii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

每門課以持續天數與最晚完成日表示，必須從第 1 天開始安排，且不能同時修讀多門課。選出的每門課都須在最晚完成日當天或之前結束，求最多可修的課程數量。

**思路**：先依最晚完成日排序，逐門加入目前選擇並累計總天數。程式以排序陣列模擬最大堆，若超過期限就移除已選課程中最長的一門。

## Problem Statement (English)

There are n different online courses numbered from 1 to n. You are given an array courses where courses[i] = [durationi, lastDayi] indicate that the ith course should be taken continuously for durationi days and must be finished before or on lastDayi.
You will start on the 1st day and you cannot take two or more courses simultaneously.
Return the maximum number of courses that you can take.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.

Input: courses = [[1,2]]
Output: 1

Input: courses = [[3,2],[4,3]]
Output: 0
```

## 限制 Constraints

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104

## 官方 C 函式簽名 Signature

```c
int scheduleCourse(int** courses, int coursesSize, int* coursesColSize) {
    
}
```
