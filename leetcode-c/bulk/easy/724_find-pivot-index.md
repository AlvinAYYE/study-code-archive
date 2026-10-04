# 0724. Find Pivot Index《尋找樞紐索引》

- **Difficulty**: Easy
- **Tags**: array, prefix-sum
- **題目連結**: https://leetcode.com/problems/find-pivot-index/
- **程式碼**: [`724_find-pivot-index.c`](./724_find-pivot-index.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

陣列的樞紐索引是指其左側所有元素總和等於右側所有元素總和的位置，邊界外側的總和視為 0。請回傳最左邊的樞紐索引；若不存在則回傳 -1。

**思路**：先計算全陣列總和，掃描時將目前元素移出右側總和，與已累積的左側總和比較。第一次相等的位置即為答案。

## Problem Statement (English)

Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
Example 1:
Example 2:
Example 3:
Constraints:
Note: This question is the same as 1991: https://leetcode.com/problems/find-the-middle-index-in-array/

## 範例 Examples

```text
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
```

## 限制 Constraints

1 <= nums.length <= 104
-1000 <= nums[i] <= 1000

## 官方 C 函式簽名 Signature

```c
int pivotIndex(int* nums, int numsSize) {
    
}
```
