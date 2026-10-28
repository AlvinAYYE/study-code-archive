# UVa Volume 006

本卷收錄 6 個 C 題目檔，依 UVa 題號排序。

<a id="uva-621_secret-research"></a>

### UVa 621 — Secret Research／秘密實驗結果加密辨識

- 原始碼：[621_secret-research.c](621_secret-research.c)
- 演算法：字串模式比對（string, pattern matching）

**English description:** Each decimal-looking result string belongs to one of four experiment classes. Print `+` for the exact values `1`, `4`, or `78`; `-` for strings ending in `35`; `*` for strings beginning with `9` and ending in `4`; and `?` for strings beginning with `190`.

**中文詳細描述：** 輸入先給測試筆數，再逐行給一個結果字串。若字串恰為 `1`、`4`、`78`，輸出 `+`；若末兩字元是 `35`，輸出 `-`；若首字元為 `9` 且末字元為 `4`，輸出 `*`；若以 `190` 開頭則輸出 `?`。每筆只輸出一個分類符號。

<a id="uva-623_500"></a>

### UVa 623 — 500!／500 階乘大數乘法

- 原始碼：[623_500.c](623_500.c)
- 演算法：高精度整數乘法（big integer, factorial）

**English description:** For each input `N`, print the exact decimal value of `N!` in the format `N!` followed by the number on the next line. Because the result exceeds built-in integer types, store decimal digits in an array and multiply the big integer by each successive factor.

**中文詳細描述：** 每行輸入 `N`，要完整輸出 `N!` 的所有十進位位數，格式為先印 `N!`，下一行印結果。內建整數不足以容納答案，因此以陣列保存各位數，從 2 到 `N` 逐次做大數乘法並處理進位；每筆資料都輸出精確值。

<a id="uva-673_parentheses-balance"></a>

### UVa 673 — Parentheses Balance／括號平衡檢驗

- 原始碼：[673_parentheses-balance.c](673_parentheses-balance.c)
- 演算法：堆疊（stack, string）

**English description:** For each line containing parentheses `()` and brackets `[]`, determine whether every opening symbol is closed by the correct type in proper nesting order. The empty string is balanced. Print `Yes` for a balanced line and `No` otherwise.

**中文詳細描述：** 輸入先給測試行數，每行由小括號與中括號構成，也可能是空字串。遇到左括號便推入堆疊；遇到右括號時必須與堆疊頂端種類相同才能配對。若發生不符、提早關閉，或掃描結束仍有未關閉括號就輸出 `No`，全部正確則輸出 `Yes`。

<a id="uva-674_coin-change"></a>

### UVa 674 — Coin Change／找零錢問題

- 原始碼：[674_coin-change.c](674_coin-change.c)
- 演算法：完全背包動態規劃（dynamic programming, coin change）

**English description:** For every input amount, count the unordered combinations of unlimited 1, 5, 10, 25, and 50 cent coins that sum exactly to it. Precompute a one-dimensional unbounded-knapsack table and print the count for each amount.

**中文詳細描述：** 每行輸入一個以分為單位的金額，可任意使用面額 1、5、10、25、50 分硬幣，求剛好湊成該金額的組合數；硬幣選取順序不同不算新方法。依面額由外到內更新 `dp[j] += dp[j-coin]`，預先建立所有答案後逐行輸出計數。

<a id="uva-686_goldbachs-conjecture-ii"></a>

### UVa 686 — Goldbach's Conjecture (II)／哥德巴赫猜想拆分對數計數

- 原始碼：[686_goldbachs-conjecture-ii.c](686_goldbachs-conjecture-ii.c)
- 演算法：埃拉托斯特尼篩法、質數對枚舉（number theory, prime sieve）

**English description:** For each even integer, count the distinct unordered pairs of primes whose sum equals that integer. Enumerate only the first prime up to half the target so each pair is counted once, and print the count. Input ends with zero.

**中文詳細描述：** 每筆輸入一個偶數，計算有多少組質數 `p1 ≤ p2` 滿足 `p1 + p2 = 輸入值`。先篩出所需範圍內的質數，再只枚舉不超過目標一半的 `p1`，檢查另一項是否為質數，從而避免正反順序重複計數；逐筆輸出對數，輸入 0 結束。

<a id="uva-694_the-collatz-sequence"></a>

### UVa 694 — The Collatz Sequence／考拉茲數列上限項數統計

- 原始碼：[694_the-collatz-sequence.c](694_the-collatz-sequence.c)
- 演算法：考拉茲數列模擬（simulation, math）

**English description:** Starting from positive integer `A`, repeatedly halve even values and replace odd values by `3A + 1`. Count terms beginning with the initial value, stopping before a term would exceed limit `L` or after reaching 1. Print the case number, original values, and term count; a pair of negative values terminates input.

**中文詳細描述：** 每組輸入起始正整數 `A` 與上限 `L`。從 `A` 起，偶數除以 2、奇數變成 `3A+1`，並計算未超過 `L` 的序列項數；起始值算一項，若到達 1 即停止，下一項超過上限則不列入。依案例格式輸出原始 `A`、`L` 與項數，負值終止資料。
