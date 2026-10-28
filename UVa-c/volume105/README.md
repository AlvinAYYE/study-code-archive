# UVa Volume 105

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-10550_combination-lock"></a>
### UVa 10550 — Combination Lock／密碼鎖

- 原始碼：[10550_combination-lock.c](10550_combination-lock.c)
- 演算法：環狀距離、模擬（Math, Simulation）

**English description:**

The input gives the initial dial position and three combination numbers on a 40-mark lock. Following the required clockwise and counterclockwise turns, calculate and output the total angle through which the dial rotates.

**中文詳細描述：**

每筆輸入包含 40 格密碼鎖的起始位置與三個密碼數字。依規則先順時針轉兩整圈到第一個數字，再逆時針轉一整圈到第二個數字，最後順時針到第三個數字；每格為 9 度，輸出總旋轉角度。

<a id="uva-10591_happy-number"></a>
### UVa 10591 — Happy Number／快樂數

- 原始碼：[10591_happy-number.c](10591_happy-number.c)
- 演算法：數位運算、循環偵測（Simulation, Cycle Detection）

**English description:**

For each input integer, repeatedly replace it with the sum of the squares of its decimal digits. If the process reaches 1 the number is happy; if it enters a cycle it is unhappy. Output the classification for each case.

**中文詳細描述：**

每組輸入給一個整數，反覆將它替換成各十進位數字平方的總和。若過程最後到達 1，便是快樂數；若進入不含 1 的循環則不是，程式以到達 1 或 4 判定終止，並輸出每組的分類結果。
