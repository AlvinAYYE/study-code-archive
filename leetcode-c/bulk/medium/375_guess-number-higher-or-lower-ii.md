# 0375. Guess Number Higher or Lower II《猜數字大小 II》

- **Difficulty**: Medium
- **Tags**: math, dynamic-programming, game-theory
- **題目連結**: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
- **程式碼**: [`375_guess-number-higher-or-lower-ii.c`](./375_guess-number-higher-or-lower-ii.c) — 社群解答（repo vli02_leetcode），已通過編譯+官方示例執行驗證

## 題目說明（中文）

在 1 到 n 的猜數字遊戲中，猜錯數字 x 時必須支付 x 元，並會得知目標較高或較低。請回傳無論目標為何，都能保證猜中的最少準備金額。

**思路**：對每個區間以記憶化遞迴枚舉首次猜測 x，代價為 x 加上左右子區間較大的最壞代價，並取其中最小值。

## Problem Statement (English)

We are playing the Guessing Game. The game will work as follows:
Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: n = 10
Output: 16
Explanation: The winning strategy is as follows:
- The range is [1,10]. Guess 7.
    - If this is my number, your total is $0. Otherwise, you pay $7.
    - If my number is higher, the range is [8,10]. Guess 9.
        - If this is my number, your total is $7. Otherwise, you pay $9.
        - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
        - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
    - If my number is lower, the range is [1,6]. Guess 3.
        - If this is my number, your total is $7. Otherwise, you pay $3.
        - If my number is higher, the range is [4,6]. Guess 5.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
            - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
        - If my number is lower, the range is [1,2]. Guess 1.
            - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
            - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.

Input: n = 1
Output: 0
Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.

Input: n = 2
Output: 1
Explanation: There are two possible numbers, 1 and 2.
- Guess 1.
    - If this is my number, your total is $0. Otherwise, you pay $1.
    - If my number is higher, it must be 2. Guess 2. Your total is $1.
The worst case is that you pay $1.
```

## 限制 Constraints

1 <= n <= 200

## 官方 C 函式簽名 Signature

```c
int getMoneyAmount(int n) {
    
}
```
