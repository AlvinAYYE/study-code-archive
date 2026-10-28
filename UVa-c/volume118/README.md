# UVa Volume 118

本卷共收錄 1 題 C 題目檔，以下依題號排序。

<a id="uva-11854_egypt"></a>
### UVa 11854 — Egypt／埃及

- 原始碼：[11854_egypt.c](11854_egypt.c)
- 演算法：畢氏定理、排序（Geometry, Math）

**English description:**

For each triple of side lengths until the terminating zeros, determine whether the three sides form a right triangle. Treat the largest side as the hypotenuse and output `right` or `wrong`.

**中文詳細描述：**

逐筆讀入三個邊長，直到三者皆為 0。先找出最大邊作為斜邊，檢查另外兩邊平方和是否等於最大邊平方；成立時輸出 `right`，否則輸出 `wrong`。
