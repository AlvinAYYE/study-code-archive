# LeetCode 0215. Kth Largest Element in an Array

Title-CN: 陣列中的第 K 大元素

## 題目

給定整數陣列 nums 和整數 k，請找出排序後的第 k 大元素。這裡的第 k 大是按位置計算，重複值也會各自占一個位置。

## 範例

1. 輸入：nums = [3,2,1,5,6,4]，k = 2；輸出：5。
2. 輸入：nums = [3,2,3,1,2,4,5,5,6]，k = 4；輸出：4。

## 限制

- 1 <= k <= nums.length <= 10^5
- -10^4 <= nums[i] <= 10^4

## 解題思路

1. 將陣列由大到小排序。
2. 排序後索引 0 是最大值，所以第 k 大位於索引 k-1。
3. 直接回傳該位置的值。

## 複雜度

時間 O(n log n)，額外空間依 qsort 實作而定；排序會改動輸入陣列。

## C 函式簽名

int findKthLargest(int* nums, int numsSize, int k)
