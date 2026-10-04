# 0888. Fair Candy Swap《公平的糖果交換》

- **Difficulty**: Easy
- **Tags**: array, hash-table, binary-search, sorting
- **題目連結**: https://leetcode.com/problems/fair-candy-swap/
- **程式碼**: [`888_fair-candy-swap.c`](./888_fair-candy-swap.c) — 社群解答（repo akib-islam-coder_leetcodesolutions），已通過編譯+官方示例執行驗證

## 題目說明（中文）

Alice 與 Bob 分別持有若干糖果盒，兩人的糖果總數不同。兩人各交換一盒後必須使總數相等；回傳 Alice 應交出的盒子糖果數與 Bob 應交出的盒子糖果數，且保證至少有一組答案。

**思路**：程式先計算兩人的總和並以雜湊表記錄 Bob 擁有的盒子大小。接著逐一嘗試 Alice 交出的盒子，依交換後的總數差推得 Bob 應交出的大小，再以雜湊表查找。

## Problem Statement (English)

Alice and Bob have a different total number of candies. You are given two integer arrays aliceSizes and bobSizes where aliceSizes[i] is the number of candies of the ith box of candy that Alice has and bobSizes[j] is the number of candies of the jth box of candy that Bob has.
Since they are friends, they would like to exchange one candy box each so that after the exchange, they both have the same total amount of candy. The total amount of candy a person has is the sum of the number of candies in each box they have.
Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange. If there are multiple answers, you may return any one of them. It is guaranteed that at least one answer exists.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: aliceSizes = [1,1], bobSizes = [2,2]
Output: [1,2]

Input: aliceSizes = [1,2], bobSizes = [2,3]
Output: [1,2]

Input: aliceSizes = [2], bobSizes = [1,3]
Output: [2,3]
```

## 限制 Constraints

1 <= aliceSizes.length, bobSizes.length <= 104
1 <= aliceSizes[i], bobSizes[j] <= 105
Alice and Bob have a different total number of candies.
There will be at least one valid answer for the given input.

## 官方 C 函式簽名 Signature

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    
}
```
