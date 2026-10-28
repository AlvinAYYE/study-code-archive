# UVa Volume 109

本卷共收錄 7 題 C 題目檔，以下依題號排序。

<a id="uva-10908_largest-square"></a>
### UVa 10908 — Largest Square／最大正方形

- 原始碼：[10908_largest-square.c](10908_largest-square.c)
- 演算法：二維陣列、中心擴張（2D Array, Simulation）

**English description:**

Given a character grid and several center coordinates, find for each query the largest odd-sided square centered there whose cells all equal the center character. Output the side length for every query.

**中文詳細描述：**

每組輸入包含一個字元矩陣與多個中心座標。對每個查詢，要找以該點為中心且所有格子都和中心字元相同的最大正方形；由半徑 0 向外逐圈檢查邊界，最後輸出其奇數邊長。

<a id="uva-10922_2-the-9s"></a>
### UVa 10922 — 2 the 9s／9 的階數

- 原始碼：[10922_2-the-9s.c](10922_2-the-9s.c)
- 演算法：數位和、整除性（Number Theory）

**English description:**

For each possibly very long decimal integer, determine whether it is a multiple of 9. If so, repeatedly sum decimal digits until reaching 9 and output how many digit-sum applications were required; otherwise report that it is not a multiple of 9.

**中文詳細描述：**

逐筆讀入可能很長的十進位整數，直到終止值。先以各位數字和判斷是否能被 9 整除；若可以，就反覆計算數字和直到得到 9，並輸出這個 9 的階數，否則輸出它不是 9 的倍數。

<a id="uva-10924_prime-words"></a>
### UVa 10924 — Prime Words／質數單字

- 原始碼：[10924_prime-words.c](10924_prime-words.c)
- 演算法：字元映射、質數判定（String, Prime Test）

**English description:**

Map lowercase letters to 1 through 26 and uppercase letters to 27 through 52. Sum the values in each input word, test the sum for primality under the problem's convention that 1 is prime, and output the classification.

**中文詳細描述：**

每行輸入一個英文字，將小寫 `a` 到 `z` 映射為 1 到 26，大寫 `A` 到 `Z` 映射為 27 到 52。加總所有字母值後判斷是否為質數；依題目定義 1 也算質數，最後輸出是否為 prime word。

<a id="uva-10929_you-can-say-11"></a>
### UVa 10929 — You can say 11／你可以說 11

- 原始碼：[10929_you-can-say-11.c](10929_you-can-say-11.c)
- 演算法：11 的整除規則（Number Theory, Divisibility）

**English description:**

Read decimal integers that may be too long for built-in numeric types. For each value, use the alternating sum of its digits to decide divisibility by 11, and output the required divisibility sentence.

**中文詳細描述：**

逐筆讀入可能超過內建整數範圍的十進位字串，直到終止值。把奇數位置與偶數位置的數字分別加總並取差；若差能被 11 整除，原數也能被 11 整除，最後按指定句型輸出判定。

<a id="uva-10931_parity"></a>
### UVa 10931 — Parity／位元同位值

- 原始碼：[10931_parity.c](10931_parity.c)
- 演算法：二進位轉換、位元計數（Base Conversion, Bit Count）

**English description:**

For every positive integer until the terminating zero, convert it to binary and count the number of one bits. Output the binary representation and its parity count in the prescribed format.

**中文詳細描述：**

逐筆讀入正整數直到 0，將每個數反覆除以 2 取得其二進位表示，同時計算其中位元 1 的個數。最後依題目格式輸出二進位字串及其 parity 值。

<a id="uva-10943_how-do-you-add"></a>
### UVa 10943 — How do you add?／你要怎麼加？

- 原始碼：[10943_how-do-you-add.c](10943_how-do-you-add.c)
- 演算法：動態規劃、組合數（Dynamic Programming, Combinatorics）

**English description:**

Given `N` and `K`, count the ordered ways to express `N` as the sum of exactly `K` non-negative integers. Output the count modulo 1,000,000 for each pair.

**中文詳細描述：**

每筆輸入給出 `N` 與 `K`，要計算把 `N` 表示成恰好 `K` 個非負整數有序相加的方式數；不同排列視為不同方式。以動態規劃累積各總和與項數的答案，最後輸出對 1,000,000 取餘數的結果。

<a id="uva-10954_add-all"></a>
### UVa 10954 — Add All／全部相加

- 原始碼：[10954_add-all.c](10954_add-all.c)
- 演算法：貪心、最小堆（Greedy, Min Heap）

**English description:**

The input gives numbers that must be combined until one value remains. Combining two values costs their sum and inserts that sum back; choose the order that minimizes the total cost and output that minimum.

**中文詳細描述：**

每組輸入有多個數字，每次選兩個相加，該次成本是兩數之和，並把和放回集合，直到只剩一個數。要讓所有中間成本總和最小，因此每次從最小堆取出最小的兩個數合併，最後輸出累計成本。
