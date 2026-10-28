# 0004. Median of Two Sorted Arrays《尋找兩個排序陣列的中位數》

- **Difficulty**: Hard
- **Tags**: array, binary-search, divide-and-conquer
- **題目連結**: https://leetcode.com/problems/median-of-two-sorted-arrays/
- **程式碼**: [`004_median-of-two-sorted-arrays.c`](./004_median-of-two-sorted-arrays.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定兩個長度分別為 `m` 與 `n`、皆依非遞減順序排列的整數陣列 `nums1` 與 `nums2`，請回傳兩個陣列合併後的中位數。題目要求整體時間複雜度為 `O(log(m+n))`。

## 解題思路

1. 不必真的合併兩個陣列；只要各選一個切口，讓切口左側合計包含總元素數的一半。
2. 固定較短陣列的切口後，另一個切口也隨之確定。比較兩個切口左右的四個邊界值，即可判斷切口應向左或向右移。
3. 當兩邊左半的最大值都不大於另一邊右半的最小值時，代表分割正確。
4. 總長度為奇數時取右半最小值；為偶數時取左半最大值與右半最小值的平均。
5. 若較短陣列為空，直接從另一個陣列的中央取中位數。

目前程式從中點逐格調整較短陣列的切口，時間複雜度為 `O(min(m,n))`，額外空間為 `O(1)`。

## Problem Statement (English)

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:
Example 2:
Constraints:

## 範例

```text
輸入：nums1 = [1,3], nums2 = [2]
輸出：2.00000
說明：合併後為 [1,2,3]，中位數是 2。

輸入：nums1 = [1,2], nums2 = [3,4]
輸出：2.50000
說明：合併後為 [1,2,3,4]，中位數是 (2+3)/2 = 2.5。
```

## 限制

- `nums1.length == m`，`nums2.length == n`
- `0 <= m, n <= 1000`
- `1 <= m+n <= 2000`，兩個陣列不會同時為空
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

## 官方 C 函式簽名 Signature

```c
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
}
```
