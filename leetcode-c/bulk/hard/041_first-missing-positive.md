# 0041. First Missing Positive《缺失的第一個正數》

- **Difficulty**: Hard
- **Tags**: array, hash-table
- **題目連結**: https://leetcode.com/problems/first-missing-positive/
- **程式碼**: [`041_first-missing-positive.c`](./041_first-missing-positive.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定未排序整數陣列 `nums`，請回傳陣列中未出現的最小正整數。演算法必須在 `O(n)` 時間與 `O(1)` 額外空間內完成。

## 解題思路

1. 長度為 `n` 的陣列若包含 `1..n`，答案就是 `n+1`；因此負數、0 與大於 `n` 的值不影響答案。
2. 直接把原陣列當作雜湊表：數字 `x` 應放在索引 `x-1`。
3. 掃描每個位置。若目前正數可放入陣列範圍，且目的地不是相同值，就持續交換，直到目前值無效或已經就位。相同值檢查可避免重複數字造成無限循環。
4. 再由左到右找第一個 `nums[i] != i+1` 的位置，答案就是 `i+1`；若全部相符，回傳 `n+1`。

每個有效數字最多被放到正確位置一次，時間複雜度為 `O(n)`，額外空間為 `O(1)`。

## Problem Statement (English)

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例

```text
輸入：nums = [1,2,0]
輸出：3
說明：1、2 都存在，因此第一個缺少的正整數是 3。

輸入：nums = [3,4,-1,1]
輸出：2
說明：1 存在，但 2 不存在。

輸入：nums = [7,8,9,11,12]
輸出：1
說明：最小正整數 1 不存在。
```

## 限制

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

## 官方 C 函式簽名 Signature

```c
int firstMissingPositive(int* nums, int numsSize) {
    
}
```
