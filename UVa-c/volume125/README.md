# UVa Volume 125

本卷收錄 15 份 C 解答，涵蓋 12 個 UVa 題號，以下依題號排序。

<a id="uva-12502_three-families"></a>

### UVa 12502 — Three Families／三戶人家花園打掃補貼工資分攤

- 原始碼：[12502_three-families.c](12502_three-families.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Family A works x hours and Family B works y hours for common garden. Family C pays z dollars. Calculate Family A's fair share of money.

**中文詳細描述：** 三家合用花園由 A 家工作 x 小時、B 家工作 y 小時，C 家因未出力補貼 z 元，求 A 家應分得之合理報酬金額。

**English approach:** Total hours is x + y. Each family owes (x+y)/3 hours. A's extra hours: x - (x+y)/3 = (2x - y)/3. Share = z * (2x - y) / (x + y).

**中文解題思路：** 平均每家應負擔 (x+y)/3 小時，A 戶超額付出 x - (x+y)/3 = (2x - y)/3，故 A 戶應得金額為 z * (2x - y) / (x + y)。 ==========================================================================


<a id="uva-12503_robot-instructions"></a>

### UVa 12503 — Robot Instructions／機器人移動指令歷史回溯

- 原始碼：[12503_robot-instructions.c](12503_robot-instructions.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** A robot moves along a line. Instructions are 'LEFT', 'RIGHT', or 'SAME AS i' (repeating instruction i). Find final coordinate.

**中文詳細描述：** 機器人在一維數線上移動，指令可能為 LEFT (-1)、RIGHT (+1) 或 SAME AS i (重複第 i 個指令的動作)。求最後停在的座標位置。

**English approach:** Store delta for each instruction 1..N. If instruction references past step i, copy delta[i]. Sum all deltas.

**中文解題思路：** 以陣列儲存各步指令造成的位移值 (+1 或 -1)，遇到 SAME AS i 則直接複製第 i 步之位移，最後加總全部位移。 ==========================================================================


<a id="uva-12504_updating_a_dictionary"></a>

### UVa 12504 — Updating a Dictionary／字典更新日誌比對

- 原始碼：[12504_updating_a_dictionary.c](12504_updating_a_dictionary.c)
- 難度：Easy
- 演算法：string, map, parsing

**English description:** Compare an old and new key-value dictionary and output keys that were added (+), removed (-), or modified (*).

**中文詳細描述：** 比對舊字典與新字典，列出新增的鍵 (+)、刪除的鍵 (-) 與數值改變的鍵 (*)。

**English approach:** Parse key-value pairs into arrays. Sort keys and compare to detect additions, deletions, and value mutations.

**中文解題思路：** 解析鍵值字串，將鍵值對存入結構體排序後比對，分類輸出新增、刪除及修改之鍵名。 ==========================================================================


<a id="uva-12527_different-digits"></a>

### UVa 12527 — Different Digits／無重複數字計數

- 原始碼：[12527_different-digits.c](12527_different-digits.c)
- 難度：Easy
- 演算法：math, simulation

**English description:** Count the number of integers in range [N, M] that have all distinct digits.

**中文詳細描述：** 計算區間 [N, M] 內所有十進位數位互不相同的整數數量。

**English approach:** Check each integer in [N, M] by marking visited digits using a bitmask or frequency array.

**中文解題思路：** 逐一檢查區間 [N, M] 的每個數，用遮罩檢查各個數字是否出現過多於一次。 ==========================================================================


<a id="uva-12531_hours-and-minutes"></a>

### UVa 12531 — Hours and Minutes／時針與分針夾角判定

- 原始碼：[12531_hours-and-minutes.c](12531_hours-and-minutes.c)
- 難度：Easy
- 演算法：math, clock-angle

**English description:** Determine if a given angle A (0 <= A <= 180) can ever be formed between the hour hand and minute hand of a clock (discrete 6-degree steps).

**中文詳細描述：** 判斷 0 到 180 度的某個夾角 A 是否可能出現在標準時鐘的時針與分針之間。

**English approach:** Every minute, the minute hand moves 6 degrees and the hour hand moves 0.5 degrees. Difference is always a multiple of 6 degrees iff A % 6 == 0.

**中文解題思路：** 每分鐘分針走 6 度，時針在分鐘整點下夾角必為 6 度的整數倍，故當且僅當 A % 6 == 0 時成立。 ==========================================================================


<a id="uva-12532_interval-product"></a>

### UVa 12532 — Interval Product／區間乘積正負號線段樹 / 樹狀陣列

- 原始碼：[12532_interval-product.c](12532_interval-product.c)
- 難度：UVa Star 2
- 演算法：data-structures, segment-tree

**English description:** Support point update 'C I V' and range product sign query 'P I J' (+, -, or 0) on an array of integers.

**中文詳細描述：** 維護整數陣列，支援單點修改數值與區間乘積正負號查詢 (輸出 '+', '-' 或 '0')。

**English approach:** Map elements to sign (+1, -1, 0). Maintain Segment Tree or BIT of zeroes and negative numbers.

**中文解題思路：** 將每個數壓縮為正負符號 (+1, -1, 0)：若區間內含 0 則乘積為 0；否則由負數個數之奇偶性決定為 '-' 或 '+'。 ==========================================================================


<a id="uva-12541_birthdates"></a>

### UVa 12541 — Birthdates／出生日期排序

- 原始碼：[12541_birthdates.c](12541_birthdates.c)
- 難度：Easy
- 演算法：sorting, simulation

**English description:** Given a list of people with their birth dates, identify the youngest and oldest persons.

**中文詳細描述：** 給定一群人的姓名與出生年月日，找出年齡最年輕（出生日期最晚）與最年長（出生日期最早）的人。

**English approach:** Convert day, month, year into comparable integer date: year * 10000 + month * 100 + day. Find min and max.

**中文解題思路：** 將年月日組合成 year * 10000 + month * 100 + day 數值，取最大值為最年輕，最小值為最年長。 ==========================================================================


<a id="uva-12554_a-special-happy-birthday-song"></a>

### UVa 12554 — A Special Happy Birthday Song／生日快樂歌歌詞輪唱循環指派

- 原始碼：[12554_a-special-happy-birthday-song.c](12554_a-special-happy-birthday-song.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** N people sing the 16-word Happy Birthday song in turn. Ensure everyone sings at least once and the entire song is completed in whole rounds.

**中文詳細描述：** N 個人輪流朗唱 16 個單詞的生日快樂歌歌詞，確保每個人至少唱過一次且最後一首歌必須完整唱完 16 句。

**English approach:** Total words sung is the smallest multiple of 16 that is >= N. Print name[i % N] with song[i % 16].

**中文解題思路：** 總唱誦詞數為大於等於 N 之最小 16 的倍數，使用迴圈將 name[i % N] 與歌詞詞彙 song[i % 16] 配對印出。 ==========================================================================


<a id="uva-12563_jin_ge_jin_qu_hao"></a>

### UVa 12563 — Jin Ge Jin Qu hao／勁歌金曲 (雙目標 0-1 背包問題)

- 原始碼：[12563_jin_ge_jin_qu_hao.c](12563_jin_ge_jin_qu_hao.c)
- 難度：Medium
- 演算法：dynamic-programming, knapsack

**English description:** Maximize the number of KTV songs sung before time limit t runs out, then maximize total time sung (adding 678s song at end).

**中文詳細描述：** 在 KTV 剩餘時間 t 之前點播歌曲，優先最大化演唱歌曲數，其次最大化總時間，最後加上一首 678 秒的《勁歌金曲》。

**English approach:** 0-1 Knapsack with capacity (t - 1): maximize (count, time). Final answer is (count + 1, time + 678).

**中文解題思路：** 容量為 t - 1 的 0-1 背包：以 (歌曲數, 耗費時間) 為狀態最大化，最後結果累加 1 首歌曲與 678 秒《勁歌金曲》。 ==========================================================================


<a id="uva-12577_hajj-e-akbar"></a>
### UVa 12577 — Hajj-e-Akbar／大朝覲

- 原始碼：[12577_hajj-e-akbar.c](12577_hajj-e-akbar.c)
- 演算法：字串比對（String）

**English description:**

Read pilgrimage names until `*`. Output `Hajj-e-Akbar` for `Hajj` and `Hajj-e-Asghar` for `Umrah`, including the required case numbering.

**中文詳細描述：**

逐行讀入朝覲類型，遇到 `*` 結束。若輸入為 `Hajj`，輸出 `Hajj-e-Akbar`；若為 `Umrah`，輸出 `Hajj-e-Asghar`，並依題目格式加上案例編號。

<a id="uva-12577_hajj-e-akbar-pr"></a>

### UVa 12577 — Hajj-e-Akbar／朝覲名稱映射

- 原始碼：[12577_hajj-e-akbar-pr.c](12577_hajj-e-akbar-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, simulation

**English description:** Map Islamic pilgrimage type: 'Hajj' -> 'Hajj-e-Akbar', 'Umrah' -> 'Hajj-e-Asghar'.

**中文詳細描述：** 依輸入名稱映射伊斯蘭朝覲儀式：'Hajj' 輸出 'Hajj-e-Akbar'，'Umrah' 輸出 'Hajj-e-Asghar'。

**English approach:** String comparison with 'Hajj'.

**中文解題思路：** 字串比對：若為 "Hajj" 輸出 "Hajj-e-Akbar"，否則輸出 "Hajj-e-Asghar"。 ==========================================================================


<a id="uva-12578_10-6-2"></a>
### UVa 12578 — 10:6:2／10:6:2 國旗面積

- 原始碼：[12578_10-6-2.c](12578_10-6-2.c)
- 演算法：平面幾何、面積公式（Geometry, Math）

**English description:**

Given the length `L` of the Bangladesh flag, use width `0.6L` and red-circle radius `0.2L`. Output the area of the red circle and the remaining green rectangle area with the required precision.

**中文詳細描述：**

每組輸入給孟加拉國旗長度 `L`，旗寬為 `0.6L`，中央紅圓半徑為 `0.2L`。以圓面積公式求紅色部分，再用整個長方形面積扣除紅圓得到綠色部分，依指定精度輸出兩個面積。

<a id="uva-12578_10-6-2-pr"></a>

### UVa 12578 — 10:6:2／孟加拉國旗紅綠面積幾何計算

- 原始碼：[12578_10-6-2-pr.c](12578_10-6-2-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：geometry, math

**English description:** Given length L of 10:6 flag with circle radius L/5, compute area of red circle and green rectangle background.

**中文詳細描述：** 孟加拉國旗長寬半徑比例為 10:6:2。給定長度 L，寬度為 0.6L，半徑為 0.2L，求紅色圓形面積與綠色背景面積。

**English approach:** Radius r = L * 0.2, width W = L * 0.6. Red = pi * r^2. Green = L * W - Red.

**中文解題思路：** 依固定幾何比例計算：半徑 r = L / 5，寬度 W = 6*L / 10。紅色面積為 pi * r^2，綠色面積為矩形總面積扣除紅圓面積。 ==========================================================================


<a id="uva-12592_slogan-learning-of-princess"></a>
### UVa 12592 — Slogan Learning of Princess／公主學口號

- 原始碼：[12592_slogan-learning-of-princess.c](12592_slogan-learning-of-princess.c)
- 演算法：字串映射、查表（String, Map）

**English description:**

The input first provides slogan pairs, each consisting of a first line and its matching response line. For every later query containing a first line, output the associated response exactly.

**中文詳細描述：**

輸入先給多組口號，每組由上句與對應下句各占一行，再給若干查詢。對每個查詢上句，要從已建立的對照表找出相應下句並完整輸出

<a id="uva-12592_slogan-learning-of-princess-pr"></a>

### UVa 12592 — Slogan Learning of Princess／公主的口號配對

- 原始碼：[12592_slogan-learning-of-princess-pr.c](12592_slogan-learning-of-princess-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, hash-table

**English description:** Given slogan pairs (line 1, line 2), output matching line 2 when queried with line 1.

**中文詳細描述：** 建立口號上下句對應表，輸入上句查詢時輸出相應的下句口號。

**English approach:** Linear string array lookup.

**中文解題思路：** 陣列記錄口號配對，字串比對查詢輸出。 ==========================================================================
