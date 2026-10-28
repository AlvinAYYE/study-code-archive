# 0122. Best Time to Buy and Sell Stock II｜買賣股票的最佳時機 II

- **難度**：中等
- **標籤**：陣列、動態規劃、貪心
- **題目連結**：[LeetCode 0122](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
- **C 程式**：[122_best-time-to-buy-and-sell-stock-ii.c](./122_best-time-to-buy-and-sell-stock-ii.c)

## 題目說明

給定每天的股票價格 `prices`。你可以不限次數買賣，但任何時候最多持有一股；賣出後才能再次買進。請回傳能取得的最大利潤。買進和賣出可以發生在同一天。

## 範例

```text
輸入：prices = [7,1,5,3,6,4]
輸出：7
說明：1 買、5 賣賺 4；3 買、6 賣賺 3，合計 7。

輸入：prices = [1,2,3,4,5]
輸出：4

輸入：prices = [7,6,4,3,1]
輸出：0
```

## 限制

- `1 <= prices.length <= 3 × 10^4`。
- `0 <= prices[i] <= 10^4`。

## 解題步驟

1. 只要某一天比前一天貴，就可以把這段上漲算進利潤。
2. 逐日比較 `prices[i]` 和 `prices[i - 1]`；若差值為正，就加到總利潤。
3. 這等同於在每段連續上漲中低買高賣，也等同於把每段上漲拆成相鄰日的收益相加。
4. 價格下跌時不交易，因此不會降低已取得的利潤。

## 複雜度

- 時間：`O(n)`，掃描價格一次。
- 額外空間：`O(1)`。

## LeetCode C 函式簽名

```c
int maxProfit(int* prices, int pricesSize);
```
