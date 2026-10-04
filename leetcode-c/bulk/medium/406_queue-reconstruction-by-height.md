# 0406. Queue Reconstruction by Height《依身高重建佇列》

- **Difficulty**: Medium
- **Tags**: array, binary-indexed-tree, segment-tree, sorting
- **題目連結**: https://leetcode.com/problems/queue-reconstruction-by-height/
- **程式碼**: [`406_queue-reconstruction-by-height.c`](./406_queue-reconstruction-by-height.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定未排序的人員陣列 people，其中 [h, k] 表示身高為 h，且前方恰有 k 位身高至少為 h 的人。請重建並回傳符合所有 k 條件的佇列；保證答案存在。

**思路**：先依身高由高到低排序，同身高則依 k 由小到大排序。依序將每人插入結果陣列的 k 位置，並把原位置及其後元素向右推移。

## Problem Statement (English)

You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
```

## 限制 Constraints

1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.

## 官方 C 函式簽名 Signature

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes) {
    
}
```
