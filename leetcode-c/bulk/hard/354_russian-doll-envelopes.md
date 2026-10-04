# 0354. Russian Doll Envelopes《俄羅斯套娃信封問題》

- **Difficulty**: Hard
- **Tags**: array, binary-search, dynamic-programming, sorting
- **題目連結**: https://leetcode.com/problems/russian-doll-envelopes/
- **程式碼**: [`354_russian-doll-envelopes.c`](./354_russian-doll-envelopes.c) — 社群解答（repo begeekmyfriend_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定信封陣列 envelopes，其中 envelopes[i] = [wi, hi] 表示信封的寬與高。只有當一個信封的寬和高都嚴格大於另一個信封時才能將其套入；不可旋轉信封，請回傳最多可套入的信封數。

**思路**：先依寬度遞增、高度遞減排序，接著對高度做嚴格遞增子序列的耐心排序，透過二分搜尋維護各長度的最小結尾高度。

## Problem Statement (English)

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
```

## 限制 Constraints

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105

## 官方 C 函式簽名 Signature

```c
int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    
}
```
