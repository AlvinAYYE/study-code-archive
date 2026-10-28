# UVa Volume 111

本卷共收錄 3 題 C 題目檔，以下依題號排序。

<a id="uva-11150_cola"></a>
### UVa 11150 — Cola／可樂

- 原始碼：[11150_cola.c](11150_cola.c)
- 演算法：貪心模擬、數學（Greedy, Simulation）

**English description:**

Starting with `n` full cola bottles, every three empty bottles can be exchanged for one full bottle. One empty bottle may be borrowed at the end when it can be repaid; output the maximum total number of bottles that can be drunk.

**中文詳細描述：**

輸入給一開始擁有的 `n` 瓶可樂，每喝完三瓶可用三個空瓶換一瓶新的；在最後可借一個空瓶，但必須能在交換後歸還。計算所有可行交換並輸出最多能喝幾瓶，結果可化簡為 `n + n/2`。

<a id="uva-11172_relational-operator"></a>
### UVa 11172 — Relational Operator／關係運算子

- 原始碼：[11172_relational-operator.c](11172_relational-operator.c)
- 演算法：條件判斷（Basic I/O）

**English description:**

For each input pair of integers `a` and `b`, compare the two values and output exactly one of `>`, `<`, or `=` to describe their relation.

**中文詳細描述：**

每組輸入包含兩個整數 `a` 與 `b`。直接比較兩者大小，若 `a` 較大輸出 `>`、較小輸出 `<`，兩者相等則輸出 `=`。

<a id="uva-11185_ternary"></a>
### UVa 11185 — Ternary／三進位

- 原始碼：[11185_ternary.c](11185_ternary.c)
- 演算法：進位轉換（Base Conversion）

**English description:**

Read non-negative decimal integers until the terminating negative value. Convert each number to base 3 by repeated division and output its ternary representation, handling zero explicitly.

**中文詳細描述：**

逐筆讀入非負十進位整數，遇到負數時結束。反覆除以 3 並收集餘數，再反向排列得到三進位表示；輸入為 0 時直接輸出 `0`，其餘逐筆輸出轉換結果。
