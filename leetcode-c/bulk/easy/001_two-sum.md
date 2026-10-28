# 0001. Two Sum《兩數之和》

- **難度**：Easy
- **標籤**：array、hash-table
- **題目連結**：https://leetcode.com/problems/two-sum/
- **程式碼**：[`001_two-sum.c`](./001_two-sum.c)

## 題目說明

給定整數陣列 `nums` 與整數 `target`，找出兩個相加等於 `target` 的元素，並回傳它們的索引。每筆輸入恰好有一組答案，不可重複使用同一個元素；兩個索引的回傳順序不限。

## 範例

```text
輸入：nums = [2,7,11,15], target = 9
輸出：[0,1]
說明：nums[0] + nums[1] = 2 + 7 = 9。

輸入：nums = [3,2,4], target = 6
輸出：[1,2]

輸入：nums = [3,3], target = 6
輸出：[0,1]
```

## 限制

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- 恰好存在一組有效答案。

## 直觀解題思路

1. 走到 `nums[i]` 時，需要的另一個數是 `target - nums[i]`。
2. 先到雜湊表查這個補數；若已出現，表中的索引與 `i` 就是答案。
3. 若未出現，再把 `nums[i]` 與索引 `i` 存入雜湊表。先查再存可避免同一元素被使用兩次，也能處理 `[3,3]`。
4. 程式用線性探測處理雜湊碰撞。

- 平均時間複雜度：`O(n)`
- 額外空間複雜度：`O(n)`

## 官方 C 函式簽名

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
```
