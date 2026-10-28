# UVa Volume 002

本卷收錄 5 個 C 題目檔，依 UVa 題號排序。

<a id="uva-256_quirksome-squares"></a>

### UVa 256 — Quirksome Squares／古怪平方數

- 原始碼：[256_quirksome-squares.c](256_quirksome-squares.c)
- 演算法：枚舉、平方數性質（brute force, math）

**English description:** For each requested even width `d`, list every `d`-digit, zero-padded number that can be split into two equal-width halves such that the square of the sum of those halves equals the original number. Preserve leading zeroes in the output.

**中文詳細描述：** 每筆輸入一個偶數位數 `d`，把候選數以固定 `d` 位（可含前導 0）分成等長左右兩半。若「左半值＋右半值」的平方恰好等於原數，就依數值遞增輸出。實作枚舉半部和並驗證平方拆分，輸出時補足固定寬度。

<a id="uva-264_count-on-cantor"></a>

### UVa 264 — Count on Cantor／康托爾數列

- 原始碼：[264_count-on-cantor.c](264_count-on-cantor.c)
- 演算法：三角數定位、數學（math, diagonal enumeration）

**English description:** Positive fractions are enumerated along alternating diagonals of the numerator-denominator grid. Given a one-based term number `N`, locate its diagonal using triangular numbers, account for the zigzag direction, and print the fraction at that position.

**中文詳細描述：** 康托爾數列沿分子、分母網格的斜對角線以交錯方向排列正分數。輸入第 `N` 項的編號後，以三角數找出它所在的對角線及線內位移，再依該層奇偶決定方向，輸出 `TERM N IS 分子/分母`。

<a id="uva-271_simply-syntax"></a>

### UVa 271 — Simply Syntax／簡單語法檢驗

- 原始碼：[271_simply-syntax.c](271_simply-syntax.c)
- 演算法：前綴文法解析、堆疊計數（parsing, stack）

**English description:** Determine whether each input string is exactly one valid sentence in a prefix grammar: `p` through `z` are atomic sentences, `N` takes one sentence, and each of `C`, `D`, `E`, and `I` takes two sentences. Print `YES` only when the entire string forms one sentence; otherwise print `NO`.

**中文詳細描述：** 每行是一個前綴表示式；小寫 `p` 到 `z` 本身是合法句子，`N` 後須接一個合法句子，而 `C`、`D`、`E`、`I` 後各須接兩個合法句子。由右向左統計目前可組成的完整句子，只有整行恰好合成一個句子時輸出 `YES`，否則輸出 `NO`。

<a id="uva-272_tex-quotes"></a>

### UVa 272 — TeX Quotes／TeX 雙引號替換

- 原始碼：[272_tex-quotes.c](272_tex-quotes.c)
- 演算法：字元流模擬（string, simulation）

**English description:** Read an arbitrary text stream and replace ordinary double quote characters in alternating order: an opening quote becomes two backticks and a closing quote becomes two apostrophes. Copy every other character, including line breaks, unchanged.

**中文詳細描述：** 輸入是可跨多行的文字，逐字元掃描其中的一般雙引號 `"`。每對引號的第一個改成 TeX 左引號的兩個反引號，第二個改成兩個單引號，之後持續交替；其餘字元與換行完全照原樣輸出。

<a id="uva-299_train-swapping"></a>

### UVa 299 — Train Swapping／火車車廂調度

- 原始碼：[299_train-swapping.c](299_train-swapping.c)
- 演算法：逆序對、氣泡排序（sorting, inversion count）

**English description:** Each test case gives the order of train cars. Only adjacent cars may be swapped, so the minimum number of swaps needed to put them in increasing order equals the number of inversions. Output that count in the required sentence for every case.

**中文詳細描述：** 每筆測試給出車廂數量與目前排列，調度時一次只能交換相鄰車廂，目標是排成遞增順序。以氣泡排序實際計數交換，等價於統計原排列的逆序對數；每組輸出 `Optimal train swapping takes S swaps.`。
