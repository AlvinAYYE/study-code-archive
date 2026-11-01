# UVa Volume 127

本卷收錄 6 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-12700_banglawash"></a>
### UVa 12700 — Banglawash／孟加拉橫掃

- 原始碼：[12700_banglawash.c](12700_banglawash.c)
- 演算法：字元計數、分類判斷（String, Simulation）

**English description:**

Each test case gives a string of cricket match results: Bangladesh wins, opponent wins, ties, or abandoned games. Count each result type and output the series classification required by the problem.

**中文詳細描述：**

每組輸入是一串板球賽果字元，分別表示孟加拉獲勝、對手獲勝、平手或比賽取消。需要統計各類次數，再依條件輸出 `BANGLAWASH`、`WHITEWASH`、`BANGLADESH`、`WWW`、`DRAW` 或 `ABANDONED`

<a id="uva-12700_banglawash-pr"></a>

### UVa 12700 — Banglawash／板球系列賽戰績判定

- 原始碼：[12700_banglawash-pr.c](12700_banglawash-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, string

**English description:** Tally match results ('B', 'W', 'T', 'A') and determine verdict: BANGLAWASH, WHITEWASH, BANGLADESH, WWW, DRAW, ABANDONED.

**中文詳細描述：** 統計板球賽事結果 (B孟加拉勝, W客隊勝, T平局, A腰斬)，輸出 BANGLAWASH (主隊橫掃全勝) 等評判結果。

**English approach:** Count occurrences of B, W, T, A. Check conditions for whitewash (all matches won with no loss) and majority winners.

**中文解題思路：** 累計各比賽結果字元頻率，依題目優先序判定主隊全勝橫掃、客隊全勝、主隊勝場多、客隊勝場多、平手或全部腰斬。 ==========================================================================


<a id="uva-12704_little-masters"></a>

### UVa 12704 — Little Masters／小大師 (圓內點到圓周最短與最長距離)

- 原始碼：[12704_little-masters.c](12704_little-masters.c)
- 難度：Easy
- 演算法：geometry, math

**English description:** Given a point (x, y) strictly inside a circle of radius r centered at the origin, find the shortest and longest distances to the circle boundary.

**中文詳細描述：** 給定以原點為圓心、半徑為 r 的圓內一點 (x, y)，求該點到圓周的最短與最長距離。

**English approach:** Distance from origin d = sqrt(x^2 + y^2). Shortest distance = r - d, longest distance = r + d.

**中文解題思路：** 點到原點距離 d = sqrt(x^2 + y^2)。到圓周的最短距離為 r - d，最長距離為 r + d。 ==========================================================================


<a id="uva-12709_falling-ants"></a>
### UVa 12709 — Falling Ants／掉落的螞蟻

- 原始碼：[12709_falling-ants.c](12709_falling-ants.c)
- 演算法：最大值篩選、體積計算（Linear Scan, Math）

**English description:**

Each ant is associated with a rectangular block having length, width, and height. Select the block with the greatest height; when heights tie, select the greatest volume, then output that block's volume.

**中文詳細描述：**

每組輸入列出多個長方體的長、寬、高，螞蟻從較高處落下會有較大的加速度。先選高度最大的長方體；若最高者有多個，再選體積 `長×寬×高` 最大者，最後輸出該體積。

<a id="uva-12709_falling-ants-pr"></a>

### UVa 12709 — Falling Ants／下落螞蟻加速度最大重力判定

- 原始碼：[12709_falling-ants-pr.c](12709_falling-ants-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：physics, math, sorting

**English description:** Downward acceleration is maximized when height H is highest (lowest air resistance). Among max H, maximize volume L*W*H.

**中文詳細描述：** 下落加速度在高度 H 最大時達到極大值。在 H 最大時，求長寬高乘積 (體積 L*W*H) 最大的螞蟻體積。

**English approach:** Physics formula simplifies to picking max H. Tie-breaker is max volume L * W * H.

**中文解題思路：** 由空氣阻力公式推導可知下落速度極大值完全由高度 H 決定。先篩選最大 H，再取體積 L*W*H 最大值。 ==========================================================================


<a id="uva-12798_handball"></a>

### UVa 12798 — Handball／手球每場皆有進球球員計數

- 原始碼：[12798_handball.c](12798_handball.c)
- 難度：UVa Star 1
- 演算法：simulation, 2d-grid

**English description:** Count how many players scored at least one goal in every single match of the season.

**中文詳細描述：** 統計整季所有場次中，每一場皆至少攻入 1 球的全勤進球球員總人數。

**English approach:** For each player row, verify that all match scores are > 0. Increment count.

**中文解題思路：** 檢查每位球員的比賽得分陣列：若該列所有數值皆大於 0 則符合條件，累加符合全勤進球球員人數。 ==========================================================================
