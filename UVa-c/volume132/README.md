# UVa Volume 132

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-13216_problem-with-a-ridiculously-long-name"></a>
### UVa 13216 — Problem with a ridiculously long name...／名字長得離譜的問題

- 原始碼：[13216_problem-with-a-ridiculously-long-name.c](13216_problem-with-a-ridiculously-long-name.c)
- 演算法：模冪週期、大數字串（Modular Arithmetic）

**English description:**

The exponent `N` may be too large for an integer type. For each decimal exponent string, output the last two digits of `66^N`, including a leading zero when needed, by using the repeating pattern modulo 100.

**中文詳細描述：**

每組輸入是可能極長的十進位指數字串 `N`，要求輸出 `66^N` 的最後兩位，必要時保留前導零。`N=0` 與 `N=1` 分別處理，其餘次方在模 100 下以 5 為週期，只需讀取指數末位即可選出答案。

<a id="uva-13275_leap-birthdays"></a>
### UVa 13275 — Leap Birthdays／閏日生日

- 原始碼：[13275_leap-birthdays.c](13275_leap-birthdays.c)
- 演算法：閏年計數、日期判斷（Math, Calendar）

**English description:**

Each case gives a birth date and a future year `Q`. Count how many birthdays can be celebrated after the birth year through `Q`; ordinary dates occur yearly, while February 29 occurs only in leap years.

**中文詳細描述：**

每組輸入給出生的日、月、年與目標年份 `Q`，要統計出生年之後到 `Q` 為止能慶祝幾次生日。一般日期每年一次，答案為年份差；若生日是 2 月 29 日，則只計算區間內符合公曆規則的閏年，最後依案例格式輸出次數。
