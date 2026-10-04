# 0506. Relative Ranks《相對名次》

- **Difficulty**: Easy
- **Tags**: array, sorting, heap-(priority-queue
- **題目連結**: https://leetcode.com/problems/relative-ranks/
- **程式碼**: [`506_relative-ranks.c`](./506_relative-ranks.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定各選手的唯一分數 score，分數最高者為第 1 名，依此決定所有名次。前 3 名分別以 Gold、Silver、Bronze Medal 表示，其餘以名次數字字串表示。依原選手順序回傳名次陣列。

**思路**：程式建立最大堆依分數由高到低取出選手，並用雜湊表把分數對應回原索引。依彈出次序填入前三名獎牌或一般名次，即可保留原輸入順序。

## Problem Statement (English)

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
Return an array answer of size n where answer[i] is the rank of the ith athlete.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
```

## 限制 Constraints

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    
}
```
