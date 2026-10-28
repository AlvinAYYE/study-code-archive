# UVa Volume 003

本卷收錄 5 個 C 題目檔，依 UVa 題號排序。

<a id="uva-350_pseudo-random-numbers"></a>

### UVa 350 — Pseudo-Random Numbers／偽隨機數生成週期

- 原始碼：[350_pseudo-random-numbers.c](350_pseudo-random-numbers.c)
- 演算法：循環偵測、模擬（cycle detection, simulation）

**English description:** A linear congruential generator produces `x(next) = (Z × x + I) mod M` from an initial value `L`. For each quadruple `Z I M L`, determine the length of the repeating cycle and print it with the case number. Four zeroes terminate the input.

**中文詳細描述：** 每筆輸入乘數 `Z`、增量 `I`、模數 `M` 與初值 `L`，依 `下一項 = (Z × 當前項 + I) mod M` 產生序列。記錄每個值第一次出現的步數，某值再次出現時，兩次步數差就是循環節長度；輸出案例編號與長度，四個 0 結束。

<a id="uva-357_let-me-count-the-ways"></a>

### UVa 357 — Let Me Count The Ways／算算有多少種方法

- 原始碼：[357_let-me-count-the-ways.c](357_let-me-count-the-ways.c)
- 演算法：完全背包動態規劃（dynamic programming, coin change）

**English description:** For each amount in cents, count the unordered ways to make exactly that amount using unlimited U.S. coins of 1, 5, 10, 25, and 50 cents. Print the grammatically correct singular or plural sentence with the computed count.

**中文詳細描述：** 每行輸入一個以分為單位的金額，可不限枚數使用 1、5、10、25、50 分硬幣，計算組合而非排列的找零方法數。以完全背包依硬幣順序更新方法數，逐筆輸出答案，並依答案是否為 1 選用題目指定的單複數句型。

<a id="uva-374_big-mod"></a>

### UVa 374 — Big Mod／大數快速冪模運算

- 原始碼：[374_big-mod.c](374_big-mod.c)
- 演算法：二進位快速冪（number theory, modular exponentiation）

**English description:** Repeatedly read integers `B`, `P`, and `M`, and compute `B^P mod M` without constructing the enormous power itself. Print one modular result for each input triple.

**中文詳細描述：** 每組輸入底數 `B`、指數 `P` 與模數 `M`，要求輸出 `B^P mod M`。利用指數的二進位分解反覆平方，每當目前位元為 1 就把該冪乘入答案，所有乘法過程立即取模，因此不用真的建立龐大的 `B^P`。

<a id="uva-382_perfection"></a>

### UVa 382 — Perfection／完美數、虧數與盈數判定

- 原始碼：[382_perfection.c](382_perfection.c)
- 演算法：因數枚舉、數論分類（number theory, divisors）

**English description:** For each positive integer, sum all of its proper positive divisors. Classify the number as `PERFECT` when the sum equals it, `DEFICIENT` when the sum is smaller, or `ABUNDANT` when the sum is larger, and print the classifications in the required report format. Input ends with zero.

**中文詳細描述：** 逐筆讀入正整數，列舉並加總其所有不含自身的正因數。因數和等於原數時分類為 `PERFECT`，小於原數為 `DEFICIENT`，大於原數為 `ABUNDANT`；依題目規定先後印出報表標頭、每個數的對齊結果與結尾，輸入 0 時停止。

<a id="uva-389_basically-speaking"></a>

### UVa 389 — Basically Speaking／基本進位制轉換

- 原始碼：[389_basically-speaking.c](389_basically-speaking.c)
- 演算法：進位制轉換（math, base conversion）

**English description:** Each input line contains a numeral, its source base, and its target base. Convert digits `0–9` and `A–F` through their numeric value, then right-align the target representation in a field of width seven. Print `ERROR` instead if the converted representation needs more than seven characters.

**中文詳細描述：** 每行輸入一個數字字串、原進位與目標進位，進位範圍使用 `0`–`9`、`A`–`F` 表示數字。先依原進位解析數值，再除以目標進位取得輸出字串；結果在寬度 7 的欄位中靠右輸出，若轉換後超過 7 個字元則輸出 `ERROR`。
