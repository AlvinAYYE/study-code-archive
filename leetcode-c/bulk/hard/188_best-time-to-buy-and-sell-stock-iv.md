# 0188. 買賣股票的最佳時機 IV（Best Time to Buy and Sell Stock IV）

- **難度**：Hard
- **標籤**：陣列、動態規劃
- **題目連結**：[LeetCode 188](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)
- **解答檔案**：[188_best-time-to-buy-and-sell-stock-iv.c](./188_best-time-to-buy-and-sell-stock-iv.c)

## 題目完整翻譯

給定股價陣列 `prices`，`prices[i]` 是第 `i` 天的股價，另給定整數 `k`。請回傳最多完成 `k` 筆交易時可以得到的最大利潤。

一筆交易包含一次買入和之後的一次賣出。必須先賣出目前持有的股票，才能再次買入；不能同時持有多筆交易。

## 範例

```text
輸入：k = 2, prices = [2,4,1]
輸出：2
說明：第 1 天以 2 買入，第 2 天以 4 賣出，獲利 2。

輸入：k = 2, prices = [3,2,6,5,0,3]
輸出：7
說明：以 2 買入、6 賣出獲利 4；再以 0 買入、3 賣出獲利 3。
```

## 限制

- `1 <= k <= 100`
- `1 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

## 解題思路

1. `buy[t]` 記錄完成至多 `t` 次賣出前、目前持有股票時的最佳資產狀態；`sell[t]` 記錄完成 `t` 次交易後的最佳利潤。
2. 每天依股價更新：可以沿用前一天的狀態，也可以用 `sell[t] - price` 買入，或用 `buy[t-1] + price` 賣出。
3. 若 `k >= prices.length / 2`，交易次數已不構成限制；只要把每一段上漲的相鄰差額加起來即可。
4. 回傳完成最多 `k` 次交易後的最大利潤。

## 複雜度

- 時間：一般情況 `O(nk)`；交易次數不構成限制時為 `O(n)`。
- 額外空間：`O(k)`。

## C 函式介面

```c
int maxProfit(int k, int* prices, int pricesSize);
```
