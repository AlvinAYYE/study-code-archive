# 0496. Next Greater Element I《下一個更大元素 I》

- **Difficulty**: Easy
- **Tags**: array, hash-table, stack, monotonic-stack
- **題目連結**: https://leetcode.com/problems/next-greater-element-i/
- **程式碼**: [`496_next-greater-element-i.c`](./496_next-greater-element-i.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

nums1 與 nums2 的元素皆不重複，且 nums1 是 nums2 的子集。對 nums1 每個元素，在 nums2 找到其右側第一個更大的元素；不存在則為 -1。依 nums1 原順序回傳答案。

**思路**：程式以雜湊表記錄 nums1 各值的答案位置，並由左至右掃描 nums2。遞減堆疊中的較小值遇到目前值時出棧，若在雜湊表中便更新答案。

## Problem Statement (English)

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
```

## 限制 Constraints

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
}
```
