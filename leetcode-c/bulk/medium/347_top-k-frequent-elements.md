# 0347. Top K Frequent Elements《前 K 個高頻元素》

- **Difficulty**: Medium
- **Tags**: array, hash-table, divide-and-conquer, sorting, heap-(priority-queue, bucket-sort, counting, quickselect
- **題目連結**: https://leetcode.com/problems/top-k-frequent-elements/
- **程式碼**: [`347_top-k-frequent-elements.c`](./347_top-k-frequent-elements.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定整數陣列 nums 與整數 k，回傳出現頻率最高的 k 個元素，順序不限。答案保證唯一，且演算法的時間複雜度必須優於 O(n log n)。

**思路**：先用自製雜湊表統計每個數值的次數，再將各桶索引建成最大堆，連續取出堆頂 k 次。

## Problem Statement (English)

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Example 2:
Constraints:
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## 範例 Examples

```text
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]
```

## 限制 Constraints

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
}
```
