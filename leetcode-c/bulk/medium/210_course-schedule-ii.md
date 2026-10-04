# 0210. Course Schedule II《課程表 II》

- **Difficulty**: Medium
- **Tags**: depth-first-search, breadth-first-search, graph, topological-sort
- **題目連結**: https://leetcode.com/problems/course-schedule-ii/
- **程式碼**: [`210_course-schedule-ii.c`](./210_course-schedule-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

共有 numCourses 門編號課程，先修關係 [a, b] 表示必須先完成 b 才能修 a。請回傳任一可完成全部課程的修習順序；若存在循環而無法完成，回傳空陣列。

**思路**：程式以鄰接矩陣與入度陣列建圖，從所有入度為零的課程做 DFS，走訪時遞減後繼入度並在歸零時遞迴加入，最後僅在輸出數量等於課程數時保留結果。

## Problem Statement (English)

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Input: numCourses = 1, prerequisites = []
Output: [0]
```

## 限制 Constraints

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    
}
```
