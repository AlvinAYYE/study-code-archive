# 0777. Swap Adjacent in LR String《LR 字串中的相鄰交換》

- **Difficulty**: Medium
- **Tags**: two-pointers, string
- **題目連結**: https://leetcode.com/problems/swap-adjacent-in-lr-string/
- **程式碼**: [`777_swap-adjacent-in-lr-string.c`](./777_swap-adjacent-in-lr-string.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

start 與 result 等長，且只含 L、R、X；每一步只能將 XL 換為 LX，或將 RX 換為 XR。判斷是否能經由任意次操作把 start 轉為 result。

**思路**：雙指針分別略過兩字串中的 X，要求其餘 L、R 的相對序列一致；同時檢查 L 只能向左移、R 只能向右移的索引限制。

## Problem Statement (English)

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string result, return True if and only if there exists a sequence of moves to transform start to result.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: start = "RXXLRXRXL", result = "XRLXXRRLX"
Output: true
Explanation: We can transform start to result following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Input: start = "X", result = "L"
Output: false
```

## 限制 Constraints

1 <= start.length <= 104
start.length == result.length
Both start and result will only consist of characters in 'L', 'R', and 'X'.

## 官方 C 函式簽名 Signature

```c
bool canTransform(char* start, char* result) {
    
}
```
