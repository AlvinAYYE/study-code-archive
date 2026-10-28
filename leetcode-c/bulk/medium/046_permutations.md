# 0046. Permutations｜全排列

- **難度**：中等
- **標籤**：陣列、回溯
- **題目連結**：[LeetCode 0046](https://leetcode.com/problems/permutations/)
- **C 程式**：[046_permutations.c](./046_permutations.c)

## 題目說明

給定一組互不相同的整數 `nums`，回傳所有可能的排列，順序不限。

## 範例

```text
輸入：nums = [1,2,3]
輸出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

輸入：nums = [0,1]
輸出：[[0,1],[1,0]]

輸入：nums = [1]
輸出：[[1]]
```

## 限制

- `1 <= nums.length <= 6`。
- `-10 <= nums[i] <= 10`。
- `nums` 中的整數互不相同。

## 解題步驟

1. `path` 保存目前排好的前幾個數，`used[i]` 表示 `nums[i]` 是否已放進 `path`。
2. 每一層從頭檢查陣列，挑一個尚未使用的數放到下一格。
3. 遞迴填完後，把 `used[i]` 還原成未使用，讓其他排列也能選它。
4. `path` 長度等於 `numsSize` 時，複製整條路徑到答案。

## 複雜度

- 時間：`O(n × n!)`，共有 `n!` 種排列，每種複製 `n` 個數。
- 額外空間：`O(n)` 遞迴路徑與使用標記，不含答案。

## LeetCode C 函式簽名

```c
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
```
