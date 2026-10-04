# 0315. Count of Smaller Numbers After Self《計算右側較小元素的數量》

- **Difficulty**: Hard
- **Tags**: array, binary-search, divide-and-conquer, binary-indexed-tree, segment-tree, merge-sort, ordered-set
- **題目連結**: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
- **程式碼**: [`315_count-of-smaller-numbers-after-self.c`](./315_count-of-smaller-numbers-after-self.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums，請回傳 counts，其中 counts[i] 是 nums[i] 右側嚴格小於 nums[i] 的元素數量。結果陣列須與輸入陣列等長。

**思路**：從右至左把元素插入二元搜尋樹；每個節點記錄左子樹數量與重複次數。插入時累加經過節點的左子樹與重複數，便得到目前元素右側較小元素的數量。

## Problem Statement (English)

Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Input: nums = [-1]
Output: [0]

Input: nums = [-1,-1]
Output: [0,0]
```

## 限制 Constraints

1 <= nums.length <= 105
-104 <= nums[i] <= 104

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    
}
```
