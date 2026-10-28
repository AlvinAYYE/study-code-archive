# UVa Volume 113

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-11332_summing-digits"></a>
### UVa 11332 — Summing Digits／數字加總

- 原始碼：[11332_summing-digits.c](11332_summing-digits.c)
- 演算法：數位根（Digital Root）

**English description:**

For every positive integer until the terminating zero, repeatedly replace the value by the sum of its decimal digits until only one digit remains. Output that final digit.

**中文詳細描述：**

逐筆讀入正整數直到 0，將一個數的十進位各位相加；若結果仍有多位數，就繼續做同樣操作，直到只剩一位。輸出最後的數位根，也可用模 9 的公式直接求得。

<a id="uva-11349_symmetric-matrix"></a>
### UVa 11349 — Symmetric Matrix／對稱矩陣

- 原始碼：[11349_symmetric-matrix.c](11349_symmetric-matrix.c)
- 演算法：二維陣列、中心對稱（2D Array）

**English description:**

For each square matrix, decide whether every element is non-negative and equals the element mirrored through the matrix center. Output the case number and whether the matrix is symmetric.

**中文詳細描述：**

每組輸入是一個方陣。題目所稱的對稱是以矩陣中心旋轉 180 度後不變，因此每個 `a[i][j]` 必須等於 `a[n-1-i][n-1-j]`，且所有元素皆不可為負；最後依案例格式輸出是否對稱。
