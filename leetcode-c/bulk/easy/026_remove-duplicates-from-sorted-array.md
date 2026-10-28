# 0026. Remove Duplicates from Sorted Array《刪除排序陣列中的重複項》

- **難度**：Easy
- **標籤**：array、two-pointers
- **題目連結**：https://leetcode.com/problems/remove-duplicates-from-sorted-array/
- **程式碼**：[`026_remove-duplicates-from-sorted-array.c`](./026_remove-duplicates-from-sorted-array.c)

## 題目說明

給定按非遞減順序排列的整數陣列 `nums`，原地移除重複值，使每個相異元素只出現一次且相對順序不變。回傳相異元素數量 `k`，並讓 `nums` 前 `k` 個位置依序存放這些元素；索引 `k` 之後的內容不列入答案。

## 範例

```text
輸入：nums = [1,1,2]
輸出：2, nums = [1,2,_]
說明：回傳 k = 2，前兩個元素為 1、2；底線處內容不限。

輸入：nums = [0,0,1,1,1,2,2,3,3,4]
輸出：5, nums = [0,1,2,3,4,_,_,_,_,_]
說明：回傳 k = 5，前五個元素為 0、1、2、3、4。
```

## 限制

- `1 <= nums.length <= 3 * 10^4`
- `-100 <= nums[i] <= 100`
- `nums` 已按非遞減順序排列。

## 直觀解題思路

1. 排序陣列的相同值必定相鄰，因此可用兩個指標原地整理。
2. `i` 指向已整理區最後一個相異值，`j` 掃描後續元素。
3. 當 `nums[j] != nums[i]`，將這個新值寫到 `nums[++i]`。
4. 掃描完成後，索引 0 到 `i` 都是相異值，因此回傳 `i + 1`。

- 時間複雜度：`O(n)`
- 額外空間複雜度：`O(1)`

## 官方 C 函式簽名

```c
int removeDuplicates(int* nums, int numsSize);
```
