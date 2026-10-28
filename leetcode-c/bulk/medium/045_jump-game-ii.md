# 0045. Jump Game II｜跳躍遊戲 II

- **難度**：中等
- **標籤**：陣列、貪心、動態規劃
- **題目連結**：[LeetCode 0045](https://leetcode.com/problems/jump-game-ii/)
- **C 程式**：[045_jump-game-ii.c](./045_jump-game-ii.c)

## 題目說明

給定從索引 0 開始的非負整數陣列 `nums`。位於索引 `i` 時，最多可往前跳 `nums[i]` 格。回傳抵達最後索引所需的最少跳躍次數。題目保證一定到得了終點。

## 範例

```text
輸入：nums = [2,3,1,1,4]
輸出：2
說明：從索引 0 跳到 1，再從 1 跳到最後的索引 4。

輸入：nums = [2,3,0,1,4]
輸出：2
```

## 限制

- `1 <= nums.length <= 10^4`。
- `0 <= nums[i] <= 1000`。
- 保證可到達最後一個索引。

## 解題步驟

1. `currentEnd` 表示目前這一跳能到達的範圍右界；`farthest` 表示從這段範圍內所有位置再跳一步，最遠能到哪裡。
2. 從左向右掃描目前範圍，用 `i + nums[i]` 更新 `farthest`。
3. 當掃到 `currentEnd`，代表這一跳的選擇範圍已看完，跳躍次數加一，並把 `currentEnd` 更新成 `farthest`。
4. 若新的範圍已包含最後索引即可停止。

## 複雜度

- 時間：`O(n)`，每個索引最多掃描一次。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int jump(int* nums, int numsSize);
```
