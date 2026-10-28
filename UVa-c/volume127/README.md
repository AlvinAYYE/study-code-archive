# UVa Volume 127

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-12700_banglawash"></a>
### UVa 12700 — Banglawash／孟加拉橫掃

- 原始碼：[12700_banglawash.c](12700_banglawash.c)
- 演算法：字元計數、分類判斷（String, Simulation）

**English description:**

Each test case gives a string of cricket match results: Bangladesh wins, opponent wins, ties, or abandoned games. Count each result type and output the series classification required by the problem.

**中文詳細描述：**

每組輸入是一串板球賽果字元，分別表示孟加拉獲勝、對手獲勝、平手或比賽取消。需要統計各類次數，再依條件輸出 `BANGLAWASH`、`WHITEWASH`、`BANGLADESH`、`WWW`、`DRAW` 或 `ABANDONED`

<a id="uva-12709_falling-ants"></a>
### UVa 12709 — Falling Ants／掉落的螞蟻

- 原始碼：[12709_falling-ants.c](12709_falling-ants.c)
- 演算法：最大值篩選、體積計算（Linear Scan, Math）

**English description:**

Each ant is associated with a rectangular block having length, width, and height. Select the block with the greatest height; when heights tie, select the greatest volume, then output that block's volume.

**中文詳細描述：**

每組輸入列出多個長方體的長、寬、高，螞蟻從較高處落下會有較大的加速度。先選高度最大的長方體；若最高者有多個，再選體積 `長×寬×高` 最大者，最後輸出該體積。
