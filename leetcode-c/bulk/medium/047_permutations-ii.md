# 0047. Permutations II｜全排列 II

- **難度**：中等
- **標籤**：陣列、回溯、排序
- **題目連結**：[LeetCode 0047](https://leetcode.com/problems/permutations-ii/)
- **C 程式**：[047_permutations-ii.c](./047_permutations-ii.c)

## 題目說明

給定可能含有重複值的整數陣列 `nums`，回傳所有不同排列，排列順序不限。相同的排列只能出現一次。

## 範例

```text
輸入：nums = [1,1,2]
輸出：[[1,1,2],[1,2,1],[2,1,1]]

輸入：nums = [1,2,3]
輸出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

## 限制

- `1 <= nums.length <= 8`。
- `-10 <= nums[i] <= 10`。

## 解題步驟

1. 先排序陣列，讓相同數字相鄰；`used[i]` 表示該索引的數字是否已放進目前排列。
2. 每一層依序嘗試未使用的數字。
3. 若 `nums[i] == nums[i - 1]`，且前一個相同數字尚未在本層路徑中使用，就跳過目前的 `nums[i]`。這會避免相同值互換索引造成重複排列。
4. 路徑長度到 `numsSize` 時，複製並輸出該排列；回溯時取消使用標記。

## 複雜度

- 時間：與不同排列數及每個排列長度成正比，最壞為 `O(n × n!)`。
- 額外空間：`O(n)` 遞迴路徑與使用標記，不含答案。

## LeetCode C 函式簽名

```c
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
```
