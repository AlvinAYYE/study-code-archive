# UVa Volume 128

本卷共收錄 1 題 C 題目檔，以下依題號排序。

<a id="uva-12820_cool-word"></a>
### UVa 12820 — Cool Word／酷單字

- 原始碼：[12820_cool-word.c](12820_cool-word.c)
- 演算法：字元頻率、唯一性檢查（String, Frequency Counting）

**English description:**

A word is cool when it contains at least two distinct letters and no two used letters have the same frequency. For each case, test every input word, count the cool ones, and output the case total.

**中文詳細描述：**

一個單字若至少包含兩種不同字母，而且每種已出現字母的出現次數彼此都不同，就稱為 cool word。每組輸入逐字統計 26 個字母頻率、檢查頻率是否重複，最後輸出該組符合條件的單字數。
