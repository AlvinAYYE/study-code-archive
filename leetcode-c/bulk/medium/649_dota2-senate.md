# 0649. Dota2 Senate《Dota2 參議院》

- **Difficulty**: Medium
- **Tags**: string, greedy, queue
- **題目連結**: https://leetcode.com/problems/dota2-senate/
- **程式碼**: [`649_dota2-senate.c`](./649_dota2-senate.c) — 社群解答（repo Senthil455_Leetcode-Code），已通過編譯+官方示例執行驗證

## 題目說明（中文）

參議員依原順序分屬 Radiant 或 Dire，會一輪輪行使權利，已被禁止者會被跳過。每位仍有權利的參議員都採對己方最有利的策略，可禁止一名對方日後投票，或在只剩己方時宣布勝利。預測最後獲勝的陣營。

**思路**：以環狀佇列反覆處理參議員，並分別記錄兩方尚待生效的禁令數。未被禁的人會對敵方增加禁令並重新排到隊尾，直到其中一方人數歸零。

## Problem Statement (English)

In the world of Dota2, there are two parties: the Radiant and the Dire.
The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:
Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.
The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.
Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".
Example 1:
Example 2:
Constraints:

## 範例 Examples

```text
Input: senate = "RD"
Output: "Radiant"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.

Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
```

## 限制 Constraints

n == senate.length
1 <= n <= 104
senate[i] is either 'R' or 'D'.

## 官方 C 函式簽名 Signature

```c
char* predictPartyVictory(char* senate) {
    
}
```
