# UVa Volume 129

本卷收錄 6 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-12908_the-book-thief"></a>
### UVa 12908 — The book thief／偷書賊

- 原始碼：[12908_the-book-thief.c](12908_the-book-thief.c)
- 演算法：三角數、反推搜尋（Math）

**English description:**

The sum of page numbers from 1 through an unknown final page is known after one page has been removed. Given the remaining sum `S`, determine the missing page number and the book's final page, then output both.

**中文詳細描述：**

一本書的頁碼從 1 連續到未知的最後一頁，其中有一頁被撕走，輸入只給剩餘頁碼總和 `S`。找出最小的 `N` 使三角數 `N(N+1)/2` 大於 `S`，兩者差即為遺失頁碼，最後輸出遺失頁與總頁數 `N`。

<a id="uva-12908_the-book-thief-pr"></a>

### UVa 12908 — The book thief／偷書賊漏頁還原 (等差級數求和定位)

- 原始碼：[12908_the-book-thief-pr.c](12908_the-book-thief-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, binary-search

**English description:** Given sum s with one page omitted, find the omitted page number and total pages n: n*(n+1)/2 > s.

**中文詳細描述：** 書本頁碼為 1 到 n，漏算了一頁導致總和為 s。求被漏掉的頁碼與整本書的總頁數 n。

**English approach:** Find smallest n such that total = n*(n+1)/2 > s. Omitted page = total - s.

**中文解題思路：** 二分或根號求滿足 n*(n+1)/2 > s 的最小整數 n。漏掉的頁碼即為三角形數與當前和的差值：total - s。 ==========================================================================


<a id="uva-12918_lucky-thief-pr"></a>

### UVa 12918 — Lucky Thief／幸運竊賊鑰匙嘗試次數

- 原始碼：[12918_lucky-thief-pr.c](12918_lucky-thief-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Find maximum number of failed key attempts to open n doors using m keys (n <= m).

**中文詳細描述：** 手中有 m 把鑰匙要開 n 扇門 (每扇門對應一把鑰匙)。求開完所有門最多可能嘗試失敗的總次數。

**English approach:** Formula: sum_{i=0}^{n-1} (m - 1 - i) = n*(m - 1) - n*(n - 1)/2.

**中文解題思路：** 最壞嘗試次數：第一扇門最多試 m-1 次，第二扇門試 m-2 次... 第 n 扇門試 m-n 次，等差級數求和公式求解。 ==========================================================================


<a id="uva-12918_lucky-tracker"></a>
### UVa 12918 — Lucky Tracker／幸運追蹤者

- 原始碼：[12918_lucky-tracker.c](12918_lucky-tracker.c)
- 演算法：等差級數（Math）

**English description:**

Given `n` keys and `m` doors, with enough doors for all keys, compute the maximum number of failed trials that can occur before every key is matched to a door. Output the result for each case.

**中文詳細描述：**

每組輸入給 `n` 把鑰匙與 `m` 扇門，且門數足以讓每把鑰匙找到配對。最壞情況下，各把鑰匙可能依次失敗 `m-1、m-2、…、m-n` 次；將這段等差數列加總，輸出最大失敗嘗試次數。

<a id="uva-12952_tri-du"></a>

### UVa 12952 — Tri-du／Tri-du 紙牌遊戲最優第三張牌

- 原始碼：[12952_tri-du.c](12952_tri-du.c)
- 難度：UVa Star 1
- 演算法：math, greedy

**English description:** Given two cards A and B, determine third card C to maximize probability of getting a Three-of-a-kind or Pair with highest rank.

**中文詳細描述：** 在 Tri-du 撲克遊戲中已知兩張手牌 A 與 B，挑選第三張牌 C 使牌型最優 (若 A==B 選 A 組成三條，否則選 max(A, B) 組成大對子)。

**English approach:** If A == B pick A; else pick max(A, B). Mathematically always max(A, B).

**中文解題思路：** 貪婪勝率最大化：若兩張相同則選同點數組成三條；若不同則選較大者組成較大的對子。結果恆為 max(A, B)。 ==========================================================================


<a id="uva-12996_ultimate-mango-challenge"></a>

### UVa 12996 — Ultimate Mango Challenge／終極芒果大胃王挑戰限制檢驗

- 原始碼：[12996_ultimate-mango-challenge.c](12996_ultimate-mango-challenge.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Check if total mangoes eaten <= total limit L and each type eaten <= individual type limit.

**中文詳細描述：** 檢驗大胃王選手吃芒果是否符合規則：吃下的各種類芒果不超過各自上限，且全部芒果總數不超過胃容量 L。

**English approach:** Sum total mangoes. Check sum <= L and a[i] <= limit[i] for all types i.

**中文解題思路：** 逐項比對吃芒果數量是否小於等於該種類上限，並加總驗證總量是否小於等於總限制 L。 ==========================================================================
