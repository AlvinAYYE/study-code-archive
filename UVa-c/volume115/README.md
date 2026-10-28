# UVa Volume 115

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-11547_automatic-answer"></a>
### UVa 11547 — Automatic Answer／自動答案

- 原始碼：[11547_automatic-answer.c](11547_automatic-answer.c)
- 演算法：算術運算、數位擷取（Math）

**English description:**

For each integer `n`, apply the fixed sequence of arithmetic operations specified by the problem. Take the absolute value of the result's tens digit and output that digit.

**中文詳細描述：**

每組輸入一個整數 `n`，依題目給定順序執行乘、加、除與減法。運算完成後取其十位數的絕對值，也就是先除以 10 再對 10 取餘數，輸出該單一數字。

<a id="uva-11584_partitioning-by-palindromes"></a>
### UVa 11584 — Partitioning by Palindromes／回文分割

- 原始碼：[11584_partitioning-by-palindromes.c](11584_partitioning-by-palindromes.c)
- 演算法：回文預處理、動態規劃（Palindrome, Dynamic Programming）

**English description:**

For each input string, partition all characters into contiguous palindromic substrings while minimizing the number of parts. Output that minimum partition count.

**中文詳細描述：**

每組輸入一個字串，需要把整串切成若干連續片段，且每個片段都必須是回文。先預處理每個區間是否為回文，再令動態規劃記錄各前綴的最少片段數，輸出覆蓋完整字串的最小分割數。
