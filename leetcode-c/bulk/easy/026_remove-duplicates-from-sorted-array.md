# 0026. Remove Duplicates from Sorted Array《刪除排序陣列中的重複項》

- **Difficulty**: Easy
- **Tags**: array, two-pointers
- **題目連結**: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
- **程式碼**: [`026_remove-duplicates-from-sorted-array.c`](./026_remove-duplicates-from-sorted-array.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非遞減排序的整數陣列 nums，原地刪除重複值，使每個相異元素只出現一次且相對順序不變。回傳相異元素數 k，並使 nums 前 k 個位置為這些相異元素。

**思路**：程式以 i 指向最後寫入的相異元素、j 掃描後續元素。當 nums[j] 與 nums[i] 不同時，將 j 的值寫到下一個 i 位置，最後回傳 i+1。

## Problem Statement (English)

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Custom Judge:
The judge will test your solution with the following code:
If all assertions pass, then your solution will be accepted.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

## 限制 Constraints

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

## 官方 C 函式簽名 Signature

```c
int removeDuplicates(int* nums, int numsSize) {
    
}
```
