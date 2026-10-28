# 0033. Search in Rotated Sorted Array｜搜尋旋轉排序陣列

- **難度**：中等
- **標籤**：陣列、二分搜尋
- **題目連結**：[LeetCode 0033](https://leetcode.com/problems/search-in-rotated-sorted-array/)
- **C 程式**：[033_search-in-rotated-sorted-array.c](./033_search-in-rotated-sorted-array.c)

## 題目說明

給定一個原本由小到大排序、元素互不相同的陣列。它可能在某個位置被旋轉，例如 `[0,1,2,4,5,6,7]` 旋轉後成為 `[4,5,6,7,0,1,2]`。請回傳 `target` 的索引；若不存在，回傳 `-1`。演算法需達到 `O(log n)` 時間。

## 範例

```text
輸入：nums = [4,5,6,7,0,1,2], target = 0
輸出：4

輸入：nums = [4,5,6,7,0,1,2], target = 3
輸出：-1

輸入：nums = [1], target = 0
輸出：-1
```

## 限制

- `1 <= nums.length <= 5000`。
- `-10^4 <= nums[i] <= 10^4`。
- `nums` 中的值互不相同，且為旋轉後的遞增陣列。
- `-10^4 <= target <= 10^4`。

## 解題步驟

1. 用 `left`、`right` 表示目前尚未排除的範圍，每輪計算中間索引 `mid`。
2. 若 `nums[mid] == target`，直接回傳 `mid`。
3. 因為陣列只有一個旋轉點，`left` 到 `mid` 或 `mid` 到 `right` 必有一側仍然遞增。用兩端值判斷哪一側有序。
4. 若 `target` 位於有序側的值域，就保留那一側；否則搜尋另一側。範圍每輪減半。
5. `left > right` 表示目標不存在，回傳 `-1`。

## 複雜度

- 時間：`O(log n)`，每次將搜尋範圍減半。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int search(int* nums, int numsSize, int target);
```
