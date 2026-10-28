# UVa Volume 130

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-13012_identifying-tea"></a>
### UVa 13012 — Identifying tea／辨識茶葉

- 原始碼：[13012_identifying-tea.c](13012_identifying-tea.c)
- 演算法：線性計數（Simulation）

**English description:**

The input gives the correct tea type followed by five contestants' guesses. Count how many guesses equal the correct type and output that count.

**中文詳細描述：**

每筆輸入先給正確的茶葉種類編號，再給五位參賽者各自的猜測。逐一比較猜測與正確編號，統計相同者的人數並輸出。

<a id="uva-13034_solve-everything"></a>
### UVa 13034 — Solve Everything :-)／解決所有問題

- 原始碼：[13034_solve-everything.c](13034_solve-everything.c)
- 演算法：全稱條件檢查（Simulation）

**English description:**

Read the solved-count values for all 13 contest problems. Output `Yes` only when every value is positive, indicating that every problem was solved at least once; otherwise output `No`.

**中文詳細描述：**

輸入 13 個整數，分別表示比賽中每題被解出的次數。只有當 13 個值全都大於 0，也就是每題至少有人解出時輸出 `Yes`；只要存在 0 就輸出 `No`。
