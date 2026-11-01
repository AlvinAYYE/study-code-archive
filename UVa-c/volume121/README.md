# UVa Volume 121

本卷收錄 9 份 C 解答，涵蓋 9 個 UVa 題號，以下依題號排序。

<a id="uva-12100_printer-queue"></a>

### UVa 12100 — Printer Queue／印表機佇列優先級排程完成時間

- 原始碼：[12100_printer-queue.c](12100_printer-queue.c)
- 難度：UVa Star 2
- 演算法：data-structures, queue, simulation

**English description:** Simulate printer job queue where higher priority jobs print first. Calculate minutes until target job at initial index m is printed.

**中文詳細描述：** 模擬具有優先級的印表機工作佇列 (佇列中若存在更高優先級工作則移至隊底)，求初始位於索引 m 的工作被列印的耗時 (分鐘)。

**English approach:** FIFO circular queue tracking (priority, is_target) pairs. If current has lower priority than any queued job, re-enqueue; else print and increment minute counter.

**中文解題思路：** 以環形佇列維護各工作之優先級與目標標記，若佇列後方存在更高優先級則移至隊尾，否則列印出隊並累計分鐘數。 ==========================================================================


<a id="uva-12136_schedule-of-a-married-man"></a>

### UVa 12136 — Schedule of a Married Man／已婚男人的時間表 (時間區間重疊判斷)

- 原始碼：[12136_schedule-of-a-married-man.c](12136_schedule-of-a-married-man.c)
- 難度：Easy
- 演算法：simulation, interval-collision

**English description:** Determine if a wife's meeting schedule and a husband's meeting schedule overlap in time.

**中文詳細描述：** 判斷妻子安排的約會時間區間與丈夫的會議時間區間是否存在時間重疊衝突。

**English approach:** Convert times HH:MM into minutes from midnight: start_min = HH * 60 + MM. Two intervals [s1, e1] and [s2, e2] overlap iff s1 <= e2 && s2 <= e1.

**中文解題思路：** 將時間轉為當日分鐘數，閉區間 [s1, e1] 與 [s2, e2] 重疊的充要條件為 s1 <= e2 且 s2 <= e1。 ==========================================================================


<a id="uva-12148_electricity"></a>

### UVa 12148 — Electricity／電力度數計算 (連續相鄰天)

- 原始碼：[12148_electricity.c](12148_electricity.c)
- 難度：Easy
- 演算法：simulation, calendar, date

**English description:** Given dates and electricity meter readings, find the total consumption and number of days for consecutive calendar day readings.

**中文詳細描述：** 給定日期與電表讀數列表，計算所有連續相鄰日（日期相差恰好 1 天）的用電量總和與天數。

**English approach:** Check if (D2, M2, Y2) is exactly the day after (D1, M1, Y1). If so, accumulate consumption difference.

**中文解題思路：** 判斷相鄰兩筆紀錄是否恰好隔 1 天（處理閏年與跨月跨年），若符合則累加用電差額與天數。 ==========================================================================


<a id="uva-12149_feynman"></a>
### UVa 12149 — Feynman／費曼

- 原始碼：[12149_feynman.c](12149_feynman.c)
- 演算法：平方和公式（Math）

**English description:**

For each positive `N` until the terminating zero, count all axis-aligned squares of every possible size in an `N × N` grid of unit squares. Output the total count.

**中文詳細描述：**

逐筆讀入正整數 `N` 直到 0。對一個由單位正方形組成的 `N × N` 方格，要計算其中所有不同大小、邊與網格平行的正方形總數；答案為 `1²+2²+…+N²`，輸出其公式計算結果。

<a id="uva-12150_pole-position"></a>

### UVa 12150 — Pole Position／桿位還原 (賽車起始排位模擬)

- 原始碼：[12150_pole-position.c](12150_pole-position.c)
- 難度：Easy
- 演算法：simulation, array

**English description:** Given final positions of race cars and their change in position relative to starting grid, reconstruct the initial starting grid order, or report -1 if invalid.

**中文詳細描述：** 給定賽車終點排名及每輛車相對於起始排位的排名升降幅度，還原初始發車排位；若有衝突或越界則輸出 -1。

**English approach:** For each car i with position change P: initial pos = i + P. Verify 0 <= initial pos < N and no two cars claim the same starting spot.

**中文解題思路：** 第 i 位賽車的名次變化為 P，則初始位置必為 i + P。檢查該位置是否落在 [0, N-1] 內且無兩車重疊佔用同一發車格。 ==========================================================================


<a id="uva-12157_tariff-plan"></a>

### UVa 12157 — Tariff Plan／通話費率方案最佳選擇比較

- 原始碼：[12157_tariff-plan.c](12157_tariff-plan.c)
- 難度：UVa Star 1
- 演算法：basics, math

**English description:** Compare Mile plan (10 cents every 30s) and Juice plan (15 cents every 60s) for a list of call durations. Output cheaper plan name and cost.

**中文詳細描述：** 比較 Mile 方案 (每 30 秒 10 美分) 與 Juice 方案 (每 60 秒 15 美分) 在多通電話通話時間下的總話費，輸出最划算的方案名稱與金額。

**English approach:** For duration D, Mile cost = (D / 30 + 1) * 10; Juice cost = (D / 60 + 1) * 15. Sum over calls and compare.

**中文解題思路：** 單次通話 D 秒，Mile 費用為 (D/30 + 1)*10，Juice 費用為 (D/60 + 1)*15，累加比較何者較低或並列。 ==========================================================================


<a id="uva-12160_unlock-the-lock"></a>

### UVa 12160 — Unlock the Lock／密碼鎖解鎖 (模10000最短路BFS)

- 原始碼：[12160_unlock-the-lock.c](12160_unlock-the-lock.c)
- 難度：Easy
- 演算法：graph, bfs, shortest-path

**English description:** Given a 4-digit lock current code L and unlock code U, press R available buttons (each adds a value modulo 10000). Find minimum button presses.

**中文詳細描述：** 四位數密碼鎖初態為 L，目標為 U，有 R 個可按的加法按鈕（每次相加模 10000），求最少按鍵次數。

**English approach:** BFS on state space 0..9999. dist array initialized to -1. Expand by (cur + button[i]) % 10000.

**中文解題思路：** 在 0~9999 狀態空間上進行標準 BFS：每次嘗試所有按鈕值相加並取模 10000，求到達終點 U 的最少步數。 ==========================================================================


<a id="uva-12192_grapevine"></a>

### UVa 12192 — Grapevine／葡萄園中最大符合高度區間正方形

- 原始碼：[12192_grapevine.c](12192_grapevine.c)
- 難度：Medium
- 演算法：binary-search, 2d-matrix

**English description:** Find the maximum side length of a square subgrid where all elements are within [L, U] in a row/col sorted matrix.

**中文詳細描述：** 在每列每行均非遞減的二維高度矩陣中，求數值均在 [L, U] 之間的最大正方形子網格邊長。

**English approach:** For each row, binary search the first column >= L. Then check if square of side (ans + 1) fits within U along the diagonal.

**中文解題思路：** 對每一列二分搜尋第一個 >= L 的欄位 c，若對角線上的位置 (r+ans, c+ans) <= U 則嘗試擴展最大邊長。 ==========================================================================


<a id="uva-12195_jingle-composing"></a>

### UVa 12195 — Jingle Composing／小調作曲小節拍數驗證

- 原始碼：[12195_jingle-composing.c](12195_jingle-composing.c)
- 難度：UVa Star 1
- 演算法：simulation, string

**English description:** Count number of measures in musical composition where note duration fractions sum up to exactly 1 whole note (64/64).

**中文詳細描述：** 檢驗樂譜字串中音符拍數加總恰好等於 1 個全音符 (64/64 拍) 的完整小節數量。

**English approach:** Map notes to 64ths: W=64, H=32, Q=16, E=8, S=4, T=2, X=1. Sum measures delimited by '/', count sums == 64.

**中文解題思路：** 將音符時值通分為 64 分音符整數：W=64, H=32, Q=16, E=8, S=4, T=2, X=1。以 '/' 分割小節，統計拍數和恰為 64 的小節數。 ==========================================================================
