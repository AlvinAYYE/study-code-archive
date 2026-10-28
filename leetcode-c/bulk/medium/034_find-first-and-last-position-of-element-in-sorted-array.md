# 0034. Find First and Last Position of Element in Sorted Array｜在排序陣列中尋找元素的第一與最後位置

- **難度**：中等
- **標籤**：陣列、二分搜尋
- **題目連結**：[LeetCode 0034](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- **C 程式**：[034_find-first-and-last-position-of-element-in-sorted-array.c](./034_find-first-and-last-position-of-element-in-sorted-array.c)

## 題目說明

給定一個由小到大排列（允許重複值）的陣列 `nums` 和目標值 `target`，回傳 `target` 第一次與最後一次出現的索引。若找不到，回傳 `[-1,-1]`。時間複雜度需為 `O(log n)`。

## 範例

```text
輸入：nums = [5,7,7,8,8,10], target = 8
輸出：[3,4]

輸入：nums = [5,7,7,8,8,10], target = 6
輸出：[-1,-1]

輸入：nums = [], target = 0
輸出：[-1,-1]
```

## 限制

- `0 <= nums.length <= 10^5`。
- `-10^9 <= nums[i] <= 10^9`。
- `nums` 是非遞減排序陣列。
- `-10^9 <= target <= 10^9`。

## 解題步驟

1. 寫一個 `lowerBound` 二分搜尋，找第一個大於或等於 `target` 的位置。
2. 若該位置已超出陣列，或該值不等於 `target`，答案就是 `[-1,-1]`。
3. 再找第一個大於 `target` 的位置；它前一格就是最後一次出現的位置。
4. 回傳兩個索引。兩次二分搜尋都只保留半邊範圍。

## 複雜度

- 時間：`O(log n)`，做兩次二分搜尋。
- 額外空間：`O(1)`，只配置題目要求的兩個整數答案。

## LeetCode C 函式簽名

```c
int* searchRange(int* nums, int numsSize, int target, int* returnSize);
```

回傳陣列由函式配置，`returnSize` 設為 2。
