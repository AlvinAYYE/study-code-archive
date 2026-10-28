# 0128. Longest Consecutive Sequence｜最長連續序列

- **難度**：中等
- **標籤**：陣列、雜湊表
- **題目連結**：[LeetCode 0128](https://leetcode.com/problems/longest-consecutive-sequence/)
- **C 程式**：[128_longest-consecutive-sequence.c](./128_longest-consecutive-sequence.c)

## 題目說明

給定未排序整數陣列 `nums`，找出其中最長的連續整數序列長度。序列中的數字可以原本不相鄰，例如 `[1,3,2,4]` 有長度 4 的連續序列。解法必須達到 `O(n)` 時間。

## 範例

```text
輸入：nums = [100,4,200,1,3,2]
輸出：4
說明：最長序列是 [1,2,3,4]。

輸入：nums = [0,3,7,2,5,8,4,6,0,1]
輸出：9

輸入：nums = [1,0,1,2]
輸出：3
```

## 限制

- `0 <= nums.length <= 10^5`。
- `-10^9 <= nums[i] <= 10^9`。

## 解題步驟

1. 把所有數字放進雜湊集合，讓「某個值是否存在」能在平均 `O(1)` 時間內查詢；重複值只存一次。
2. 只從序列起點開始計數：若 `value - 1` 也在集合裡，`value` 就不是起點，跳過。
3. 對每個起點反覆查詢下一個值是否存在，直到序列中斷，得到該段長度。
4. 用最大長度記錄答案。每個數字至多被起點判斷或延伸掃描一次。

## 複雜度

- 平均時間：`O(n)`，雜湊集合插入與查詢為平均 `O(1)`。
- 額外空間：`O(n)`，保存不同數字的雜湊集合。

## LeetCode C 函式簽名

```c
int longestConsecutive(int* nums, int numsSize);
```
