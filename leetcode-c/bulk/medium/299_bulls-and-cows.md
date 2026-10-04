# 0299. Bulls and Cows《猜數字遊戲》

- **Difficulty**: Medium
- **Tags**: hash-table, string, counting
- **題目連結**: https://leetcode.com/problems/bulls-and-cows/
- **程式碼**: [`299_bulls-and-cows.c`](./299_bulls-and-cows.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

給定祕密數字 secret 與猜測 guess，位置與數字都相同的位數稱為公牛（bull），數字相同但位置不同的位數稱為母牛（cow）。兩字串可含重複數字，請以 "xAyB" 格式回傳公牛數 x 與母牛數 y。

**思路**：同時統計兩個字串的 0 到 9 出現次數並計算同位置相等的公牛數。各數字計數的較小值總和是共同數字數，扣掉公牛數即為母牛數。

## Problem Statement (English)

You are playing the Bulls and Cows game with your friend.
You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.
The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"

Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
```

## 限制 Constraints

1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret and guess consist of digits only.

## 官方 C 函式簽名 Signature

```c
char* getHint(char* secret, char* guess) {
    
}
```
