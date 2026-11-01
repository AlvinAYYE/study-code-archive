# UVa Volume 128

本卷收錄 5 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-12820_cool-word"></a>
### UVa 12820 — Cool Word／酷單字

- 原始碼：[12820_cool-word.c](12820_cool-word.c)
- 演算法：字元頻率、唯一性檢查（String, Frequency Counting）

**English description:**

A word is cool when it contains at least two distinct letters and no two used letters have the same frequency. For each case, test every input word, count the cool ones, and output the case total.

**中文詳細描述：**

一個單字若至少包含兩種不同字母，而且每種已出現字母的出現次數彼此都不同，就稱為 cool word。每組輸入逐字統計 26 個字母頻率、檢查頻率是否重複，最後輸出該組符合條件的單字數。

<a id="uva-12820_cool-word-pr"></a>

### UVa 12820 — Cool Word／酷單字 (字母相異頻率計數)

- 原始碼：[12820_cool-word-pr.c](12820_cool-word-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, hash-table

**English description:** A word is cool if it has at least 2 distinct letters and all letter frequencies are pairwise distinct.

**中文詳細描述：** 酷單字定義：至少含有 2 種相異字母，且所有出現字母的頻率兩兩互不相同。

**English approach:** Count letter frequencies. Check >= 2 distinct letters and ensure no two frequencies are equal.

**中文解題思路：** 陣列統計字母出現頻率，檢查字母種數 >= 2，並用標記陣列確認所有非零頻率互不相同。 ==========================================================================


<a id="uva-12854_automated_checking_machine"></a>

### UVa 12854 — Automated Checking Machine／自動接頭匹配檢驗

- 原始碼：[12854_automated_checking_machine.c](12854_automated_checking_machine.c)
- 難度：Easy
- 演算法：implementation, bitwise

**English description:** Determine if two 5-pin connectors are complementary (every position has exactly one pin and one hole).

**中文詳細描述：** 判斷兩組 5 插針連接器是否互補匹配（每個位置剛好一個是凸針 1，另一個是凹孔 0）。

**English approach:** Check if a[i] ^ b[i] == 1 for all i from 0 to 4.

**中文解題思路：** 檢查五個插腳位置是否滿足 a[i] ^ b[i] == 1 (即 a[i] + b[i] == 1)。 ==========================================================================


<a id="uva-12894_perfect-flag"></a>

### UVa 12894 — Perfect Flag／完美國旗尺寸與圓心座標檢驗

- 原始碼：[12894_perfect-flag.c](12894_perfect-flag.c)
- 難度：UVa Star 1
- 演算法：geometry

**English description:** Check if rectangle and circle conform to Bangladesh flag standard (length=10k, width=6k, radius=2k, center at 45% length).

**中文詳細描述：** 檢驗孟加拉國旗規格：長寬比 10:6，半徑為長度的 1/5，圓心 x 座標位於長度 45% 處、y 座標位於寬度正中央。

**English approach:** Verify L = x2 - x1, W = y2 - y1. Check 6*L == 10*W, 5*R == L, 20*(cx - x1) == 9*L, 2*(cy - y1) == W.

**中文解題思路：** 精確整數交叉相乘檢驗：長寬是否滿足 6*L == 10*W，半徑 5*R == L，圓心 x 偏移 20*dx == 9*L，圓心 y 偏移 2*dy == W。 ==========================================================================


<a id="uva-12895_armstrong-number"></a>

### UVa 12895 — Armstrong Number／阿姆斯壯數判定 (各數位 N 次方和)

- 原始碼：[12895_armstrong-number.c](12895_armstrong-number.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Determine if integer is Armstrong number (sum of each digit raised to power of number of digits equals original number).

**中文詳細描述：** 判定整數是否為阿姆斯壯數 (即每位數字的 d 次方之和等於原數，其中 d 為總位數)。

**English approach:** Extract digits. Let d be number of digits. Compute sum_{i} digit_i^d and compare with original number.

**中文解題思路：** 解析數位得到總位數 d，計算每個數位的 d 次方累加和，若總和等於原數則判定為 Armstrong 數。 ==========================================================================
