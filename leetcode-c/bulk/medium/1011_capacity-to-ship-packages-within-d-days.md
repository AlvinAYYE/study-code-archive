# 1011. Capacity To Ship Packages Within D Days｜在 D 天內送達包裹的最低運載量

- **難度**：中等
- **標籤**：陣列、二分搜尋
- **題目連結**：[LeetCode 1011](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
- **C 程式**：[1011_capacity-to-ship-packages-within-d-days.c](./1011_capacity-to-ship-packages-within-d-days.c)

## 題目說明

輸送帶上有依序排列的包裹，重量存在 `weights` 中。貨船每天按原順序裝載包裹，不能超過當天的載重上限，也不能跳過前面的包裹先載後面的包裹。給定期限 `days`，請回傳能在期限內運完所有包裹的最小船舶載重。

## 範例

```text
輸入：weights = [1,2,3,4,5,6,7,8,9,10], days = 5
輸出：15
說明：載重 15 可分成每天 [1,2,3,4,5]、[6,7]、[8]、[9]、[10]。

輸入：weights = [3,2,2,4,1,4], days = 3
輸出：6

輸入：weights = [1,2,3,1,1], days = 4
輸出：3
```

## 限制

- `1 <= days <= weights.length <= 5 × 10^4`。
- `1 <= weights[i] <= 500`。

## 解題步驟

1. 載重下界是最重的單件包裹，否則它無法裝船；上界是全部重量總和，足以一天運完。
2. 對候選載重 `capacity`，從第一件包裹開始依序裝載；若再加入下一件會超重，就開始新的一天。
3. 計算候選載重需要幾天。若天數不超過 `days`，代表載重可行，嘗試更小的載重；否則提高載重。
4. 對可行區間做二分搜尋，最後的左界就是最小可行載重。

## 複雜度

- 時間：`O(n × log(sum(weights)))`，每次二分都線性檢查包裹。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int shipWithinDays(int* weights, int weightsSize, int days);
```
