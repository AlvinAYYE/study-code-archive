# UVa Volume 125

本卷共收錄 3 題 C 題目檔，以下依題號排序。

<a id="uva-12577_hajj-e-akbar"></a>
### UVa 12577 — Hajj-e-Akbar／大朝覲

- 原始碼：[12577_hajj-e-akbar.c](12577_hajj-e-akbar.c)
- 演算法：字串比對（String）

**English description:**

Read pilgrimage names until `*`. Output `Hajj-e-Akbar` for `Hajj` and `Hajj-e-Asghar` for `Umrah`, including the required case numbering.

**中文詳細描述：**

逐行讀入朝覲類型，遇到 `*` 結束。若輸入為 `Hajj`，輸出 `Hajj-e-Akbar`；若為 `Umrah`，輸出 `Hajj-e-Asghar`，並依題目格式加上案例編號。

<a id="uva-12578_10-6-2"></a>
### UVa 12578 — 10:6:2／10:6:2 國旗面積

- 原始碼：[12578_10-6-2.c](12578_10-6-2.c)
- 演算法：平面幾何、面積公式（Geometry, Math）

**English description:**

Given the length `L` of the Bangladesh flag, use width `0.6L` and red-circle radius `0.2L`. Output the area of the red circle and the remaining green rectangle area with the required precision.

**中文詳細描述：**

每組輸入給孟加拉國旗長度 `L`，旗寬為 `0.6L`，中央紅圓半徑為 `0.2L`。以圓面積公式求紅色部分，再用整個長方形面積扣除紅圓得到綠色部分，依指定精度輸出兩個面積。

<a id="uva-12592_slogan-learning-of-princess"></a>
### UVa 12592 — Slogan Learning of Princess／公主學口號

- 原始碼：[12592_slogan-learning-of-princess.c](12592_slogan-learning-of-princess.c)
- 演算法：字串映射、查表（String, Map）

**English description:**

The input first provides slogan pairs, each consisting of a first line and its matching response line. For every later query containing a first line, output the associated response exactly.

**中文詳細描述：**

輸入先給多組口號，每組由上句與對應下句各占一行，再給若干查詢。對每個查詢上句，要從已建立的對照表找出相應下句並完整輸出
