# 0162. Find Peak Element｜尋找峰值

- **難度**：中等
- **標籤**：陣列、二分搜尋
- **題目連結**：[LeetCode 0162](https://leetcode.com/problems/find-peak-element/)
- **C 程式**：[162_find-peak-element.c](./162_find-peak-element.c)

## 題目說明

峰值是嚴格大於相鄰元素的元素。給定整數陣列 `nums`，回傳任一個峰值的索引。可以把陣列外的兩個值想成負無限大，因此首尾元素也可能是峰值。題目保證相鄰元素不相等，並要求 `O(log n)` 時間。

## 範例

```text
輸入：nums = [1,2,3,1]
輸出：2
說明：索引 2 的值 3 大於左右相鄰值。

輸入：nums = [1,2,1,3,5,6,4]
輸出：1 或 5
說明：值 2 和值 6 都是峰值。
```

## 限制

- `1 <= nums.length <= 1000`。
- `-2^31 <= nums[i] <= 2^31 - 1`。
- 相鄰元素不相等。

## 解題步驟

1. 在 `left` 到 `right` 範圍內二分搜尋，查看中間元素與右邊元素的斜率。
2. 若 `nums[mid] > nums[mid + 1]`，表示往右已在下坡；左側一定有峰值，保留 `mid` 到左半部。
3. 若 `nums[mid] < nums[mid + 1]`，表示往右上坡；右側一定有峰值，搜尋 `mid + 1` 到 `right`。
4. 範圍縮到一個索引時，它就是峰值。陣列邊界依題意視為相鄰負無限大。

## 複雜度

- 時間：`O(log n)`。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int findPeakElement(int* nums, int numsSize);
```
