# 0035. Search Insert Position《搜尋插入位置》

- **難度**：Easy
- **標籤**：array、binary-search
- **題目連結**：https://leetcode.com/problems/search-insert-position/
- **程式碼**：[`035_search-insert-position.c`](./035_search-insert-position.c)

## 題目說明

給定嚴格遞增且元素互異的整數陣列 `nums` 與目標值 `target`。若 `target` 已存在，回傳其索引；否則回傳將它插入後仍能維持排序的位置。演算法必須達到 `O(log n)` 時間。

## 範例

```text
輸入：nums = [1,3,5,6], target = 5
輸出：2

輸入：nums = [1,3,5,6], target = 2
輸出：1

輸入：nums = [1,3,5,6], target = 7
輸出：4
```

## 限制

- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` 的元素互異且按嚴格遞增順序排列。
- `-10^4 <= target <= 10^4`

## 直觀解題思路

1. 用 `head`、`tail` 表示尚待搜尋的閉區間，以中點 `mid` 與 `target` 比較。
2. 中點值較小就捨棄左半部；中點值較大就捨棄右半部；相等時直接回傳 `mid`。
3. 找不到時，`head` 會停在第一個大於 `target` 的位置，也就是插入索引。

- 時間複雜度：`O(log n)`
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
int searchInsert(int* nums, int numsSize, int target);
```
