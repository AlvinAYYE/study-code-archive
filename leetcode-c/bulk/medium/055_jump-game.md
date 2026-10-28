# 0055. Jump Game｜跳躍遊戲

- **難度**：中等
- **標籤**：陣列、動態規劃、貪心
- **題目連結**：[LeetCode 0055](https://leetcode.com/problems/jump-game/)
- **C 程式**：[055_jump-game.c](./055_jump-game.c)

## 題目說明

給定非負整數陣列 `nums`。一開始位於索引 0；`nums[i]` 表示從索引 `i` 最多能往前跳幾格。若能到達最後一個索引，回傳 `true`，否則回傳 `false`。

## 範例

```text
輸入：nums = [2,3,1,1,4]
輸出：true
說明：從索引 0 跳到 1，再從 1 跳 3 格到終點。

輸入：nums = [3,2,1,0,4]
輸出：false
說明：最多只能到索引 3，而該位置的跳躍長度是 0，無法前進。
```

## 限制

- `1 <= nums.length <= 10^4`。
- `0 <= nums[i] <= 10^5`。

## 解題步驟

1. 用 `farthest` 記錄目前已知能到達的最遠索引，起始值為 0。
2. 從左到右檢查每個索引 `i`；只有 `i <= farthest` 時，該位置才真的走得到。
3. 若能到達 `i`，就用 `i + nums[i]` 更新 `farthest`。
4. 若 `farthest` 到達最後索引，回傳 `true`；若掃描位置已超出 `farthest`，中間有無法跨越的缺口，回傳 `false`。

## 複雜度

- 時間：`O(n)`，每個索引最多檢查一次。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
bool canJump(int* nums, int numsSize);
```
