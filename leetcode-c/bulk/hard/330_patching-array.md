# 0330. Patching Array《修補陣列》

- **Difficulty**: Hard
- **Tags**: array, greedy
- **題目連結**: https://leetcode.com/problems/patching-array/
- **程式碼**: [`330_patching-array.c`](./330_patching-array.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定已排序正整數陣列 nums 與整數 n，可在陣列中加入元素，使 [1, n] 內每個數都能表示為部分元素的總和。請回傳所需加入元素數量的最小值。

**思路**：以 miss 維護目前無法湊出的最小正數。若下一個原始數不超過 miss，就把它納入並擴大可覆蓋範圍；否則補上 miss 本身，使覆蓋上限加倍並計數。

## Problem Statement (English)

Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] inclusive can be formed by the sum of some elements in the array.
Return the minimum number of patches required.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: nums = [1,3], n = 6
Output: 1
Explanation:
Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Input: nums = [1,5,10], n = 20
Output: 2
Explanation: The two patches can be [2, 4].

Input: nums = [1,2,2], n = 5
Output: 0
```

## 限制 Constraints

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums is sorted in ascending order.
1 <= n <= 231 - 1

## 官方 C 函式簽名 Signature

```c
int minPatches(int* nums, int numsSize, int n) {
    
}
```
