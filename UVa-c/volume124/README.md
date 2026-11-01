# UVa Volume 124

本卷收錄 10 份 C 解答，涵蓋 8 個 UVa 題號，以下依題號排序。

<a id="uva-12403_save-setu"></a>
### UVa 12403 — Save Setu／拯救 Setu

- 原始碼：[12403_save-setu.c](12403_save-setu.c)
- 演算法：累加模擬（Simulation）

**English description:**

Process a sequence of commands. A `donate K` command adds `K` to the current fund, while a `report` command asks for the current total; output the total for every report.

**中文詳細描述：**

輸入包含一連串指令，基金初始為 0。遇到 `donate K` 時把金額 `K` 加入累計總額；遇到 `report` 時輸出目前累積的捐款金額，依序處理所有指令。

<a id="uva-12403_save-setu-pr"></a>

### UVa 12403 — Save Setu／拯救西圖難民基金帳戶模擬

- 原始碼：[12403_save-setu-pr.c](12403_save-setu-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation

**English description:** Simulate bank operations: 'donate K' deposits money, 'report' prints current total balance.

**中文詳細描述：** 模擬愛心基金會帳戶操作：'donate K' 存入 K 元捐款，'report' 查詢並印出當前累積總金額。

**English approach:** Maintain total balance variable. Accumulate on 'donate', print on 'report'.

**中文解題思路：** 維護長整數變數累計捐款總額，收到 donate 指令增加餘額，收到 report 印出當前累積值。 ==========================================================================


<a id="uva-12405_scarecrow"></a>

### UVa 12405 — Scarecrow／稻草人農田覆蓋貪婪佈置

- 原始碼：[12405_scarecrow.c](12405_scarecrow.c)
- 難度：UVa Star 1
- 演算法：greedy

**English description:** Given a field string of '.' (crops) and '#' (infertility), place minimum scarecrows (each covers i-1, i, i+1) to protect all crops.

**中文詳細描述：** 給定由農作物 '.' 與貧瘠土地 '#' 組成的農田，每個稻草人可覆蓋其自身及左右各一格，求保護所有農作物所需的最少稻草人數目。

**English approach:** Greedy scan from left to right: upon encountering a '.', place a scarecrow at i + 1 (covering i, i+1, i+2) and advance index by 3.

**中文解題思路：** 貪婪法從左至右掃描：遇到未覆蓋的農作物 '.'，在 i+1 處放置稻草人並一口氣跳過 3 格 (i+3)。 ==========================================================================


<a id="uva-12442_forwarding-emails"></a>

### UVa 12442 — Forwarding Emails／轉寄電子郵件

- 原始碼：[12442_forwarding-emails.c](12442_forwarding-emails.c)
- 難度：Medium
- 演算法：graph, dfs, strongly-connected-components

**English description:** Each person forwards email to exactly one other person. Find the person who can reach the maximum number of recipients.

**中文詳細描述：** 每個人都只會將郵件轉寄給特定一人，求誰發起郵件能傳遞給最多的人。

**English approach:** Since each node has out-degree 1, the graph is a collection of functional graphs (trees rooted on cycles). Use DFS with memoization.

**中文解題思路：** 每個節點出度皆為 1，全圖由基環樹森林構成。使用帶記憶化的 DFS 計算每個點可抵達的節點數。 ==========================================================================


<a id="uva-12455_bars"></a>

### UVa 12455 — Bars／金屬條湊整長度子集和背包

- 原始碼：[12455_bars.c](12455_bars.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming

**English description:** Given target length N and a set of p metal bars, determine if a subset of bars can be welded together to form length exactly N.

**中文詳細描述：** 給定目標長度 N 與 p 根金屬條的長度，判定是否能挑選若干根金屬條剛好拼湊成總長度 N (子集和背包問題)。

**English approach:** Standard 0/1 knapsack subset sum boolean array dp[0..N].

**中文解題思路：** 標準 0/1 背包子集和演算法：dp[j] 表示長度 j 是否可達，由後向前更新轉移。 ==========================================================================


<a id="uva-12459_bees-ancestors"></a>

### UVa 12459 — Bees' ancestors／蜜蜂的祖先

- 原始碼：[12459_bees-ancestors.c](12459_bees-ancestors.c)
- 難度：Easy
- 演算法：math, fibonacci

**English description:** A male bee has only 1 parent (mother), while a female bee has 2 parents (father and mother). Find the number of ancestors of a male bee in the n-th generation back.

**中文詳細描述：** 雄蜂只有 1 個親代（母親），雌蜂有 2 個親代（父親與母親）。求一隻雄蜂在倒數第 n 代祖先的總數。

**English approach:** The sequence of total ancestors in generation n corresponds to the Fibonacci sequence: F(1)=1, F(2)=2, F(3)=3, F(4)=5, ...

**中文解題思路：** 第 n 代祖先數恰好為費氏數列：F(1)=1, F(2)=2, F(3)=3, F(4)=5, ... ==========================================================================


<a id="uva-12461_airplane"></a>

### UVa 12461 — Airplane／飛機乘客入座機率

- 原始碼：[12461_airplane.c](12461_airplane.c)
- 難度：Easy
- 演算法：math, probability

**English description:** First passenger loses boarding pass and picks random seat. Each subsequent passenger sits in assigned seat if free, else picks random seat. Find probability last passenger sits in own seat.

**中文詳細描述：** 第一位乘客登機證遺失隨機入座，後續乘客若自己座位空著則坐自己位置否則隨機挑位，求最後一名乘客坐到自己座位的機率。

**English approach:** Classic puzzle: the answer is always 1/2 for any n >= 2.

**中文解題思路：** 經典機率問題：不論總人數 n 為多少 (n >= 2)，最後一名乘客坐到自己座位的機率恆為 1/2。 ==========================================================================


<a id="uva-12468_zapping"></a>
### UVa 12468 — Zapping／轉台

- 原始碼：[12468_zapping.c](12468_zapping.c)
- 演算法：環狀距離（Math）

**English description:**

Television channels are numbered 0 through 99 in a cycle. For each starting and target channel until the terminating pair, output the minimum number of up or down button presses needed to reach the target.

**中文詳細描述：**

電視頻道編號為 0 到 99，按到端點後會環狀接回另一端。每筆輸入給目前頻道與目標頻道，直到終止資料；比較直接距離 `|a-b|` 與繞回距離 `100-|a-b|`，輸出較小的按鍵次數。

<a id="uva-12468_zapping-pr"></a>

### UVa 12468 — Zapping／電視遙控器選台最少按鍵次數

- 原始碼：[12468_zapping-pr.c](12468_zapping-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Compute minimum button presses to switch from channel a to channel b on a 100-channel TV (0..99 circular).

**中文詳細描述：** 在 100 個頻道 (0 到 99 環形相連) 的電視中由頻道 a 切換至 b，求上鍵或下鍵的最少按壓次數。

**English approach:** Direct difference and wraparound difference: min(abs(a - b), 100 - abs(a - b)).

**中文解題思路：** 環形最短距離：計算直接距離 abs(a - b) 與跨越 0 號頻道的距離 100 - abs(a - b) 的最小值。 ==========================================================================


<a id="uva-12478_hardest-problem-ever-easy"></a>

### UVa 12478 — Hardest Problem Ever (Easy)／史上最難題目之解答常數輸出

- 原始碼：[12478_hardest-problem-ever-easy.c](12478_hardest-problem-ever-easy.c)
- 難度：UVa Star 1
- 演算法：basics

**English description:** Find the only grid-hidden name that appears twice in the given word grid. Output the name directly.

**中文詳細描述：** 找出題目九宮格單詞網格中唯一出現過兩次的名字並直接印出解答 (KABIR)。

**English approach:** Print 'KABIR' directly as per problem definition.

**中文解題思路：** 依據題意分析直接回傳常數字串 "KABIR"。 ==========================================================================
