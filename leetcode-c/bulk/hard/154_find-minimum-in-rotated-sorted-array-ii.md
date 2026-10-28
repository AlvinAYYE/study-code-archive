# 0154. 尋找旋轉排序陣列中的最小值 II（Find Minimum in Rotated Sorted Array II）

- **難度**：Hard
- **標籤**：陣列、二分搜尋
- **題目連結**：[LeetCode 154](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)
- **解答檔案**：[154_find-minimum-in-rotated-sorted-array-ii.c](./154_find-minimum-in-rotated-sorted-array-ii.c)

## 題目完整翻譯

長度為 `n` 的陣列原本依遞增順序排列，之後被旋轉 1 到 `n` 次。旋轉一次是把最後一個元素移到最前面。陣列可能有重複值。

給定旋轉後的陣列 `nums`，請回傳其中最小的元素。請盡可能減少操作次數。

## 範例

```text
輸入：nums = [1,3,5]
輸出：1

輸入：nums = [2,2,2,0,1]
輸出：0
```

## 限制

- `n == nums.length`
- `1 <= n <= 5000`
- `-5000 <= nums[i] <= 5000`
- `nums` 原本遞增，旋轉後仍保留這個循環排序關係；值可以重複。

## 解題思路

1. 用左右界 `left`、`right` 保留可能含有最小值的範圍，取中間位置 `mid`。
2. 若 `nums[mid] > nums[right]`，最小值必在 `mid` 右側，把 `left` 移到 `mid + 1`。
3. 若 `nums[mid] < nums[right]`，最小值在 `mid` 或左側，把 `right` 移到 `mid`。
4. 若兩者相等，無法判斷最小值在哪一側，但可以安全地排除最右端的一個重複值，令 `right--`。
5. 左右界相遇時，該位置就是最小值。

重複值可能讓每次只能排除一個元素，所以最壞情況會退化成線性掃描。

## 複雜度

- 一般情況時間：`O(log n)`；大量重複值時最壞 `O(n)`。
- 額外空間：`O(1)`。

## C 函式介面

```c
int findMin(int* nums, int numsSize);
```
