# 0027. Remove Element《移除元素》

- **Difficulty**: Easy
- **Tags**: array, two-pointers
- **題目連結**: https://leetcode.com/problems/remove-element/
- **程式碼**: [`027_remove-element.c`](./027_remove-element.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與值 val，原地移除所有等於 val 的元素，並回傳不等於 val 的元素數 k。元素順序可改變，且 nums 前 k 個位置必須都是保留元素。

**思路**：程式先找到第一個等於 val 的位置，之後掃描陣列並將所有不等於 val 的元素依序覆寫到該位置起。寫入指標最後的位置即為保留元素數量。

## Problem Statement (English)

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
Custom Judge:
The judge will test your solution with the following code:
If all assertions pass, then your solution will be accepted.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

## 限制 Constraints

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

## 官方 C 函式簽名 Signature

```c
int removeElement(int* nums, int numsSize, int val) {
    
}
```
