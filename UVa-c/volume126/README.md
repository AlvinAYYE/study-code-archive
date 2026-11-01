# UVa Volume 126

本卷收錄 10 份 C 解答，涵蓋 8 個 UVa 題號，以下依題號排序。

<a id="uva-12602_nice-licence-plates"></a>
### UVa 12602 — Nice Licence Plates／漂亮車牌

- 原始碼：[12602_nice-licence-plates.c](12602_nice-licence-plates.c)
- 演算法：字串解析、26 進位（String, Math）

**English description:**

Each plate has the form `LLL-DDDD`. Interpret the three letters as a base-26 value with `A = 0`, compare it with the four-digit decimal value, and output `nice` when the absolute difference is at most 100; otherwise output `not nice`.

**中文詳細描述：**

每組輸入是一個 `LLL-DDDD` 格式的車牌。將前三個英文字母以 `A=0` 解讀成 26 進位數，再與後四位十進位數字比較；兩者差的絕對值不超過 100 時輸出 `nice`，否則輸出 `not nice`。

<a id="uva-12602_nice-licence-plates-pr"></a>

### UVa 12602 — Nice Licence Plates／好車牌判定 (26進位英文字母與數字差值)

- 原始碼：[12602_nice-licence-plates-pr.c](12602_nice-licence-plates-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, string, base-conversion

**English description:** Plate 'LLL-DDDD' is nice if absolute difference between base-26 value of letters and decimal digits is <= 100.

**中文詳細描述：** 車牌格式為 3 個字母接 4 個數字。字母視為 26 進位數，若其值與 4 位數十進位值的絕對差 <= 100 則為好車牌。

**English approach:** Base-26 value = (c0-'A')*676 + (c1-'A')*26 + (c2-'A'). Check abs(base26 - digits) <= 100.

**中文解題思路：** 將前 3 個大寫字母按 26 進位轉為十進位數值，與後 4 位十進位整數相減取絕對值，小於等於 100 輸出 nice，否則 not nice。 ==========================================================================


<a id="uva-12611_beautiful-flag"></a>

### UVa 12611 — Beautiful Flag／美麗的孟加拉國旗坐標計算

- 原始碼：[12611_beautiful-flag.c](12611_beautiful-flag.c)
- 難度：Easy
- 演算法：geometry, math

**English description:** Given the radius of the red circle in a Bangladesh flag, compute the coordinates of the rectangular flag corners centered relative to the circle.

**中文詳細描述：** 給定孟加拉國旗中紅色圓的半徑 R，計算國旗四個頂點的相對坐標（圓心位於原點 (0, 0)）。

**English approach:** Dimensions: Length L = 5*R, Width W = 3*R. Circle center is at 45% of length from left: left = -0.45*L = -2.25*R, right = 0.55*L = 2.75*R, y = +/- 1.5*R.

**中文解題思路：** 依國旗比例：長度 L = 5*R，寬度 W = 3*R。圓心距左側 45%，故左 x = -2.25*R，右 x = 2.75*R，上 y = 1.5*R，下 y = -1.5*R。 ==========================================================================


<a id="uva-12626_i-love-pizza"></a>

### UVa 12626 — I Love Pizza／MARGARITA 披薩字母配料製作上限

- 原始碼：[12626_i-love-pizza.c](12626_i-love-pizza.c)
- 難度：UVa Star 1
- 演算法：string, greedy

**English description:** Count maximum 'MARGARITA' pizzas that can be made from letters in string (M:1, A:3, R:2, G:1, I:1, T:1).

**中文詳細描述：** 製作一個 MARGARITA 披薩需要字母：M:1, A:3, R:2, G:1, I:1, T:1。給定字母庫，求最多可製作多少個完整披薩。

**English approach:** Tally letter counts. Max pizzas = min(M/1, A/3, R/2, G/1, I/1, T/1).

**中文解題思路：** 統計字串中各字母數量，依配方除以所需份數取瓶頸最小值：min(M, A/3, R/2, G, I, T)。 ==========================================================================


<a id="uva-12646_zero-or-one"></a>

### UVa 12646 — Zero or One／零與一抓獨特者 (三人猜拳獨贏)

- 原始碼：[12646_zero-or-one.c](12646_zero-or-one.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Three players output 0 or 1. Output winner 'A', 'B', 'C' if one player chose differently, or '*' if draw.

**中文詳細描述：** 三人各自出 0 或 1。若恰有一人出的數字與另外兩人不同，則該人獲勝；若三人皆同則為平局 '*'。

**English approach:** Conditional check: if A != B and A != C output A; if B != A and B != C output B; if C != A and C != B output C; else *.

**中文解題思路：** 判斷分支：若某人的數字與另外兩人皆不同則該人獲勝，若三人出相同數字則輸出 '*'。 ==========================================================================


<a id="uva-12650_dangerous-dive"></a>
### UVa 12650 — Dangerous Dive／危險潛水

- 原始碼：[12650_dangerous-dive.c](12650_dangerous-dive.c)
- 演算法：布林標記、缺項搜尋（Array, Simulation）

**English description:**

The input gives `N` divers numbered from 1 to `N`, followed by the identifiers of the `R` divers who returned. Output all missing identifiers in increasing order, or `*` if everyone returned.

**中文詳細描述：**

每組輸入表示共有編號 1 到 `N` 的潛水員，接著列出已返回的 `R` 人編號。用布林陣列標記返回者，依編號遞增輸出所有未返回的人；若全部返回，則輸出 `*`。

<a id="uva-12650_dangerous-dive-pr"></a>

### UVa 12650 — Dangerous Dive／危險潛水失蹤名單比對

- 原始碼：[12650_dangerous-dive-pr.c](12650_dangerous-dive-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, array

**English description:** N volunteers went diving, R returned with listed IDs. Output IDs of missing divers in ascending order or '*' if all returned.

**中文詳細描述：** N 名潛水員出任務，R 名志工安全返回。輸出未生還者 (未在返回名單中) 的編號由小到大排列；全員生還輸出 '*'。

**English approach:** Boolean array of size N+1. Mark returned IDs. Output all unmarked IDs.

**中文解題思路：** 布林陣列標記返回者編號。若 R == N 輸出 '*'；否則由 1 到 N 巡訪輸出所有未標記的失蹤者編號。 ==========================================================================


<a id="uva-12657_boxes-in-a-line"></a>

### UVa 12657 — Boxes in a Line／排成一行的盒子 (雙向鏈結串列與整體翻轉標記)

- 原始碼：[12657_boxes-in-a-line.c](12657_boxes-in-a-line.c)
- 難度：Medium
- 演算法：data-structures, doubly-linked-list

**English description:** Simulate operations on N boxes in a line: move X left/right of Y, swap X and Y, reverse the entire line. Output sum of odd-positioned boxes.

**中文詳細描述：** 模擬 N 個箱子的排列操作：將 X 移至 Y 左側/右側、交換 X 與 Y、將全列翻轉。求奇數位置箱子編號總和。

**English approach:** Doubly linked list with a global reverse flag. If reversed, 'left' acts as 'right' and vice versa. Reconnect pointers in O(1).

**中文解題思路：** 使用雙向鏈結串列陣列與全域翻轉標記，所有移動與交換均在 O(1) 內完成指標重連，最後遍歷奇數項累加求和。 ==========================================================================


<a id="uva-12694_meeting-room-arrangement"></a>

### UVa 12694 — Meeting Room Arrangement／會議室排程最大場數 (貪婪區間排程)

- 原始碼：[12694_meeting-room-arrangement.c](12694_meeting-room-arrangement.c)
- 難度：UVa Star 1
- 演算法：greedy, sorting, interval-scheduling

**English description:** Find maximum number of non-overlapping meetings that can be scheduled in a single meeting room.

**中文詳細描述：** 在單一會議室中，求最多可容納的互不重疊會議場數 (經典貪婪區間排程演算法，按結束時間由早到晚排序)。

**English approach:** Classic interval scheduling: sort meetings by finish time. Greedily select next meeting whose start time >= current finish.

**中文解題思路：** 依會議結束時間升序排序。貪婪挑選結束時間最早且開始時間不早於前一場結束時間的會議，場數最大化。 ==========================================================================


<a id="uva-12696_cabin-baggage"></a>
### UVa 12696 — Cabin Baggage／隨身行李

- 原始碼：[12696_cabin-baggage.c](12696_cabin-baggage.c)
- 演算法：複合條件判斷（Simulation）

**English description:**

For each bag, determine acceptance from its length, width, depth, and weight. Weight must not exceed 7.0, and either all individual dimension limits must hold or the three dimensions must sum to at most 125; output each decision and the total accepted count.

**中文詳細描述：**

每件行李輸入長、寬、深與重量。重量必須不超過 7.0，尺寸則需同時符合長不超過 56、寬不超過 45、深不超過 25，或三邊總和不超過 125；逐件輸出是否合格，最後再輸出通過總數。
