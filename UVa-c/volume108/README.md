# UVa Volume 108

本卷共收錄 4 題 C 題目檔，以下依題號排序。

<a id="uva-10810_ultra-quicksort"></a>
### UVa 10810 — Ultra-QuickSort／超快速排序

- 原始碼：[10810_ultra-quicksort.c](10810_ultra-quicksort.c)
- 演算法：合併排序、逆序對（Merge Sort, Inversion Count）

**English description:**

For each input sequence, determine the minimum number of adjacent exchanges needed to sort it. Count inversions during merge sort and output the 64-bit total for each sequence.

**中文詳細描述：**

每組輸入是一個數列，要計算透過相鄰元素交換完成排序所需的最少交換次數。此數量等於逆序對總數，在合併排序合併左右半部時累加跨區逆序對，最後輸出可能很大的計數。

<a id="uva-10812_beat-the-spread"></a>
### UVa 10812 — Beat the Spread!／破解分差

- 原始碼：[10812_beat-the-spread.c](10812_beat-the-spread.c)
- 演算法：聯立方程、奇偶判斷（Math）

**English description:**

Each test case gives the sum `s` and absolute difference `d` of two non-negative integer scores. Recover the larger and smaller scores and output them, or output `impossible` when no valid integer pair exists.

**中文詳細描述：**

每組輸入給兩個非負整數比分的總和 `s` 與差 `d`。解聯立式得到較大值 `(s+d)/2` 與較小值 `(s-d)/2`；若 `s<d` 或奇偶性使結果不是整數，則輸出 `impossible`，否則輸出兩個比分。

<a id="uva-10815_andys-first-dictionary"></a>
### UVa 10815 — Andy's First Dictionary／安迪的第一本字典

- 原始碼：[10815_andys-first-dictionary.c](10815_andys-first-dictionary.c)
- 演算法：字串切割、排序、去重（String, Sorting）

**English description:**

Read arbitrary text, treating every maximal run of letters as a word. Convert words to lowercase, remove duplicates, sort them lexicographically, and output one distinct word per line.

**中文詳細描述：**

輸入是多行任意文字，所有連續英文字母構成一個單字，其他字元都視為分隔符。將單字轉成小寫、去除重複並按字典順序排列，最後每行輸出一個不同的單字。

<a id="uva-10878_decode-the-tape"></a>
### UVa 10878 — Decode the tape／解碼紙帶

- 原始碼：[10878_decode-the-tape.c](10878_decode-the-tape.c)
- 演算法：字元解析、二進位解碼（String, Bit Manipulation）

**English description:**

The input depicts punched paper tape between border lines. For each data row, interpret `o` positions as binary one bits and blank positions as zero bits, decode the corresponding ASCII character, and output the recovered message.

**中文詳細描述：**

輸入以文字畫出打孔紙帶，首尾邊界行不承載資料。對每一條資料列，把指定欄位中的 `o` 當作二進位 1、空白當作 0，組成 ASCII 碼後轉回字元，依序輸出完整訊息。
