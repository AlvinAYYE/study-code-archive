# 0080. Remove Duplicates from Sorted Array II《刪除排序陣列中的重複項 II》

- **Difficulty**: Medium
- **Tags**: array, two-pointers
- **題目連結**: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
- **程式碼**: [`080_remove-duplicates-from-sorted-array-ii.c`](./080_remove-duplicates-from-sorted-array-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定非遞減排序陣列 nums，原地刪除多餘重複元素，使每個不同值至多保留兩次，且需保持原有相對順序。將結果寫入 nums 前 k 個位置並回傳 k，k 之後的內容不拘。不得配置另一個陣列，額外空間必須為 O(1)。

**思路**：用寫入指針 i 與讀取指針 j 掃描；只有 nums[j] 不等於已寫入結果倒數第二個元素 nums[i-2] 時才寫入。如此每個值最多留下兩個。

## Problem Statement (English)

Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
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

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

## 限制 Constraints

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

## 官方 C 函式簽名 Signature

```c
int removeDuplicates(int* nums, int numsSize) {
    
}
```
