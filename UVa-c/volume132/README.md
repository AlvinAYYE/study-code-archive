# UVa Volume 132

本卷收錄 6 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-13216_problem-with-a-ridiculously-long-name"></a>
### UVa 13216 — Problem with a ridiculously long name...／名字長得離譜的問題

- 原始碼：[13216_problem-with-a-ridiculously-long-name.c](13216_problem-with-a-ridiculously-long-name.c)
- 演算法：模冪週期、大數字串（Modular Arithmetic）

**English description:**

The exponent `N` may be too large for an integer type. For each decimal exponent string, output the last two digits of `66^N`, including a leading zero when needed, by using the repeating pattern modulo 100.

**中文詳細描述：**

每組輸入是可能極長的十進位指數字串 `N`，要求輸出 `66^N` 的最後兩位，必要時保留前導零。`N=0` 與 `N=1` 分別處理，其餘次方在模 100 下以 5 為週期，只需讀取指數末位即可選出答案。

<a id="uva-13216_problem-with-a-ridiculously-long-name-pr"></a>

### UVa 13216 — Problem with a Ridiculously Long Name／66的N次方末兩位數規律

- 原始碼：[13216_problem-with-a-ridiculously-long-name-pr.c](13216_problem-with-a-ridiculously-long-name-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, number-theory

**English description:** Compute the last two digits of 66^n for huge n.

**中文詳細描述：** 求 66^n 的最後兩位數字 (n 為超大整數)。

**English approach:** Base cases: 66^0 = 01 (or 1), 66^1 = 66. For n >= 2, last two digits have period 5: 56, 96, 36, 76, 16...

**中文解題思路：** 同餘週期規律：66^0=1, 66^1=66。當 n >= 2 時末兩位數以 5 為週期循環：56, 96, 36, 76, 16。 ==========================================================================


<a id="uva-13271_brick-walls"></a>

### UVa 13271 — Brick Walls／磚牆六角網格最短步數走訪

- 原始碼：[13271_brick-walls.c](13271_brick-walls.c)
- 難度：UVa Star 2
- 演算法：geometry, math, shortest-path

**English description:** Compute shortest path distance between two bricks on a staggered brick wall (honeycomb grid equivalent).

**中文詳細描述：** 在錯位排列的磚塊牆面上移動，求從起始磚塊走到目標磚塊所需的最少跳躍步數。

**English approach:** Map brick grid to hexagonal coordinates. Distance formula considers alternating parity of connections.

**中文解題思路：** 將交錯磚牆轉換為六角座標系，計算垂直與水平位移差，依奇偶交替可跨越性推導閉形式最短步數。 ==========================================================================


<a id="uva-13275_leap-birthdays"></a>
### UVa 13275 — Leap Birthdays／閏日生日

- 原始碼：[13275_leap-birthdays.c](13275_leap-birthdays.c)
- 演算法：閏年計數、日期判斷（Math, Calendar）

**English description:**

Each case gives a birth date and a future year `Q`. Count how many birthdays can be celebrated after the birth year through `Q`; ordinary dates occur yearly, while February 29 occurs only in leap years.

**中文詳細描述：**

每組輸入給出生的日、月、年與目標年份 `Q`，要統計出生年之後到 `Q` 為止能慶祝幾次生日。一般日期每年一次，答案為年份差；若生日是 2 月 29 日，則只計算區間內符合公曆規則的閏年，最後依案例格式輸出次數。

<a id="uva-13275_leap-birthdays-pr"></a>

### UVa 13275 — Leap Birthdays／閏年閏日生日次數計算 (2月29日)

- 原始碼：[13275_leap-birthdays-pr.c](13275_leap-birthdays-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, simulation

**English description:** Count how many real birthdays a person born on Feb 29 has celebrated between birth year and year Y.

**中文詳細描述：** 計算出生於 2 月 29 日 (閏年閏日) 的人在出生年到目標年份 Y 之間，實際過過幾次生日 (閏年計數)。

**English approach:** For Feb 29 birth, birthday occurs only in leap years (year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)).

**中文解題思路：** 若生日非 2 月 29 則每年過一次；若為 2 月 29 則遍歷出生年+1 到目標年，累加期間的閏年次數。 ==========================================================================


<a id="uva-13279_divisors-factorial-powers"></a>

### UVa 13279 — Divisors／超階乘因數總個數取模

- 原始碼：[13279_divisors-factorial-powers.c](13279_divisors-factorial-powers.c)
- 難度：UVa Star 2
- 演算法：math, number-theory, prime-sieve

**English description:** Compute number of divisors of product_{k=1}^N k! modulo 100,000,007.

**中文詳細描述：** 計算超級階乘 1! * 2! * ... * N! 的正因數個數，結果對 100,000,007 取模。

**English approach:** Count cumulative prime exponent sums using Legendre formula. Tau(P) = prod(exp_p + 1) mod 100000007.

**中文解題思路：** 質數篩預處理質數表，計算各質數在各階乘中出現次數前綴和的累加值，因數個數公式 prod(e_i + 1) 取模。 ==========================================================================
