# UVa Volume 104

本卷共收錄 5 題 C 題目檔，以下依題號排序。

<a id="uva-10409_die-game"></a>
### UVa 10409 — Die Game／骰子遊戲

- 原始碼：[10409_die-game.c](10409_die-game.c)
- 演算法：狀態模擬（Simulation）

**English description:**

A standard die starts with known face values and receives a sequence of north, south, east, or west roll commands. Simulate every roll and output the value on the top face after all commands.

**中文詳細描述：**

輸入先給出擲動次數，再依序給出骰子向北、南、東或西滾動的指令；骰子的初始六面配置固定。逐次更新頂面、底面與四個側面，最後輸出所有指令執行完後的頂面點數。

<a id="uva-10420_list-of-conquests"></a>
### UVa 10420 — List of Conquests／征服名單

- 原始碼：[10420_list-of-conquests.c](10420_list-of-conquests.c)
- 演算法：字串解析、排序、頻率統計（String, Sorting）

**English description:**

Each input line begins with a country name followed by a person's name. Count how many lines belong to each country, then output every country and its count in alphabetical order.

**中文詳細描述：**

每筆輸入資料的第一個單字是國家名稱，後方則是人名。需要統計各國出現的人數，把國名依字典順序排列，並逐行輸出國名及對應的出現次數。

<a id="uva-10469_to-carry-or-not-to-carry"></a>
### UVa 10469 — To Carry or not to Carry／要不要進位

- 原始碼：[10469_to-carry-or-not-to-carry.c](10469_to-carry-or-not-to-carry.c)
- 演算法：位元運算（Bit Manipulation, XOR）

**English description:**

For each pair of non-negative integers, add their binary representations without carrying between bit positions. Output the resulting integer, which is exactly the bitwise exclusive OR of the two inputs.

**中文詳細描述：**

每筆輸入包含兩個非負整數，要把它們視為二進位數相加，但任何位元都不產生進位。各位的結果等同兩數做 XOR，計算後以十進位輸出所得整數。

<a id="uva-10473_simple-base-conversion"></a>
### UVa 10473 — Simple Base Conversion／簡易進位轉換

- 原始碼：[10473_simple-base-conversion.c](10473_simple-base-conversion.c)
- 演算法：字串解析、進位轉換（String, Base Conversion）

**English description:**

Read numbers until the terminating input. A value prefixed by `0x` is hexadecimal and must be printed in decimal; any other value is decimal and must be printed in uppercase hexadecimal with the `0x` prefix.

**中文詳細描述：**

逐筆讀入數字直到終止值。若字串以 `0x` 開頭，就把十六進位值轉成十進位輸出；否則把輸入視為十進位，轉成大寫十六進位並加上 `0x` 前綴後輸出。

<a id="uva-10499_the-land-of-justice"></a>
### UVa 10499 — The Land of Justice／正義之地

- 原始碼：[10499_the-land-of-justice.c](10499_the-land-of-justice.c)
- 演算法：數學公式（Math）

**English description:**

For each given number `n` of pieces, determine the percentage increase in surface area caused by cutting a sphere into that many parts. Output zero for the single-piece case; otherwise output `25 × n` percent.

**中文詳細描述：**

輸入給出球體被切成的份數 `n`，要計算切割後表面積相對原表面積增加的百分比。當只有一份時沒有切割，輸出 `0%`；其餘情況依推導結果輸出 `25 × n%`。
