# 0153. Find Minimum in Rotated Sorted Array｜尋找旋轉排序陣列中的最小值

- **難度**：中等
- **標籤**：陣列、二分搜尋
- **題目連結**：[LeetCode 0153](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
- **C 程式**：[153_find-minimum-in-rotated-sorted-array.c](./153_find-minimum-in-rotated-sorted-array.c)

## 題目說明

原本嚴格遞增的陣列被向右旋轉過，且所有數字互不相同。請找出其中最小的元素，並使用 `O(log n)` 時間。向右旋轉一次會把最後一個元素移到最前面。

## 範例

```text
輸入：nums = [3,4,5,1,2]
輸出：1

輸入：nums = [4,5,6,7,0,1,2]
輸出：0

輸入：nums = [11,13,15,17]
輸出：11
```

## 限制

- `1 <= nums.length <= 5000`。
- `-5000 <= nums[i] <= 5000`。
- 所有元素互不相同，且陣列是排序後旋轉的結果。

## 解題步驟

1. 用 `left`、`right` 標記目前可能包含最小值的範圍。
2. 取中間位置 `middle`，將 `nums[middle]` 和右端 `nums[right]` 比較。
3. 若中間值大於右端，最小值一定在中間右側，令 `left = middle + 1`。
4. 否則最小值在中間或左側，令 `right = middle`。
5. 範圍縮到只剩一個位置時，該位置就是最小值。

## 複雜度

- 時間：`O(log n)`，每輪將搜尋範圍縮小一半。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int findMin(int* nums, int numsSize);
```
