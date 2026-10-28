# 0081. Search in Rotated Sorted Array II｜搜尋旋轉排序陣列 II

- **難度**：中等
- **標籤**：陣列、二分搜尋
- **題目連結**：[LeetCode 0081](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
- **C 程式**：[081_search-in-rotated-sorted-array-ii.c](./081_search-in-rotated-sorted-array-ii.c)

## 題目說明

原本非遞減排序的陣列 `nums` 在某個位置旋轉過，且可能有重複值。給定 `target`，若它存在於陣列中回傳 `true`，否則回傳 `false`。例如 `[0,1,2,4,4,4,5,6,6,7]` 可以旋轉成 `[4,5,6,6,7,0,1,2,4,4]`。

## 範例

```text
輸入：nums = [2,5,6,0,0,1,2], target = 0
輸出：true

輸入：nums = [2,5,6,0,0,1,2], target = 3
輸出：false
```

## 限制

- `1 <= nums.length <= 5000`。
- `-10^4 <= nums[i], target <= 10^4`。
- `nums` 是非遞減陣列旋轉後的結果。

## 解題步驟

1. 用 `left` 和 `right` 維持尚未搜尋的範圍，反覆檢查中間值。
2. 中間值等於目標就成功。若 `nums[left]`、`nums[mid]`、`nums[right]` 三者相同，無法判斷哪一側有序，安全地把左右界各縮一格。
3. 否則至少一半是正常排序的：先判斷左半是否有序，再看目標是否落在左半範圍；若沒有，就搜尋另一半。右半有序時用相同方式判斷。
4. 重複值可能讓每次只能排除一格，所以最差情況會退化成線性搜尋。

## 複雜度

- 平均時間：`O(log n)`；最差時間：`O(n)`，大量重複值可能無法一次排除半邊。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
bool search(int* nums, int numsSize, int target);
```
