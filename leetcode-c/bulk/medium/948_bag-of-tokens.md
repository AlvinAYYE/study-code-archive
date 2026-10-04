# 0948. Bag of Tokens《代幣背包》

- **Difficulty**: Medium
- **Tags**: array, two-pointers, greedy, sorting
- **題目連結**: https://leetcode.com/problems/bag-of-tokens/
- **程式碼**: [`948_bag-of-tokens.c`](./948_bag-of-tokens.c) — 社群解答（repo kenjin_Awesome-LC-Cracker），已通過編譯+官方示例執行驗證

## 題目說明（中文）

初始有 power 點能量與 0 分，並有尚未使用的代幣陣列 tokens。每枚代幣可正面使用：能量至少為其值時扣除能量並加 1 分；或反面使用：分數至少為 1 時扣 1 分並增加該值能量，同一代幣不能兩種都用。請回傳可得到的最大分數。

**思路**：先排序代幣並以首尾雙指針貪心處理：能量足夠就花最小代幣換分數，不足時若有分數且不只剩一枚，就賣最大代幣換能量。

## Problem Statement (English)

You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] denotes the value of tokeni.
Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):
Return the maximum possible score you can achieve after playing any number of tokens.
Example 1:
Example 2:
Example 3:
Constraints:

## 範例 Examples

```text
Input: tokens = [100], power = 50
Output: 0
Explanation : Since your score is 0 initially, you cannot play the token face-down. You also cannot play it face-up since your power ( 50 ) is less than tokens[0] ( 100 ).

Input: tokens = [200,100], power = 150
Output: 1
Explanation: Play token 1 ( 100 ) face-up, reducing your power to 50 and increasing your score to 1 .
There is no need to play token 0 , since you cannot play it face-up to add to your score. The maximum score achievable is 1 .

Input: tokens = [100,200,300,400], power = 200
Output: 2
Explanation: Play the tokens in this order to get a score of 2 :
The maximum score achievable is 2 .
```

## 限制 Constraints

0 <= tokens.length <= 1000
0 <= tokens[i], power < 104

## 官方 C 函式簽名 Signature

```c
int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    
}
```
