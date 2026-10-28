# UVa Volume 008

本卷收錄 1 個 C 題目檔，依 UVa 題號排序。

<a id="uva-847_a-multiplication-game"></a>

### UVa 847 — A Multiplication Game／乘法博弈遊戲

- 原始碼：[847_a-multiplication-game.c](847_a-multiplication-game.c)
- 演算法：博弈論、勝負區間（game theory, greedy strategy）

**English description:** Starting with `p = 1`, Stan and Ollie alternate, beginning with Stan, and multiply `p` by an integer from 2 through 9. The player whose move first makes `p` at least the target `n` wins. Determine and print the winner for each input target under optimal play.

**中文詳細描述：** 每筆輸入一個目標值 `n`，遊戲從 `p = 1` 開始，由 Stan 先手，兩人輪流選擇 2 到 9 的整數乘上目前的 `p`；誰先使 `p ≥ n` 就獲勝。利用雙方最佳策略的勝負區間，依序乘 9（Stan 能強制達成的上界）與 2（Ollie 能回應的上界），判斷並輸出 `Stan wins.` 或 `Ollie wins.`。
