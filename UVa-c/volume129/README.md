# UVa Volume 129

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-12908_the-book-thief"></a>
### UVa 12908 — The book thief／偷書賊

- 原始碼：[12908_the-book-thief.c](12908_the-book-thief.c)
- 演算法：三角數、反推搜尋（Math）

**English description:**

The sum of page numbers from 1 through an unknown final page is known after one page has been removed. Given the remaining sum `S`, determine the missing page number and the book's final page, then output both.

**中文詳細描述：**

一本書的頁碼從 1 連續到未知的最後一頁，其中有一頁被撕走，輸入只給剩餘頁碼總和 `S`。找出最小的 `N` 使三角數 `N(N+1)/2` 大於 `S`，兩者差即為遺失頁碼，最後輸出遺失頁與總頁數 `N`。

<a id="uva-12918_lucky-tracker"></a>
### UVa 12918 — Lucky Tracker／幸運追蹤者

- 原始碼：[12918_lucky-tracker.c](12918_lucky-tracker.c)
- 演算法：等差級數（Math）

**English description:**

Given `n` keys and `m` doors, with enough doors for all keys, compute the maximum number of failed trials that can occur before every key is matched to a door. Output the result for each case.

**中文詳細描述：**

每組輸入給 `n` 把鑰匙與 `m` 扇門，且門數足以讓每把鑰匙找到配對。最壞情況下，各把鑰匙可能依次失敗 `m-1、m-2、…、m-n` 次；將這段等差數列加總，輸出最大失敗嘗試次數。
