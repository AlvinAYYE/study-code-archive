# UVa Volume 107

本卷共收錄 2 題 C 題目檔，以下依題號排序。

<a id="uva-10783_odd-sum"></a>
### UVa 10783 — Odd Sum／奇數和

- 原始碼：[10783_odd-sum.c](10783_odd-sum.c)
- 演算法：區間加總（Math）

**English description:**

For each test case, the input gives two endpoints `a` and `b`. Sum every odd integer in the inclusive interval and output the result with its case number.

**中文詳細描述：**

每組輸入給出區間端點 `a` 與 `b`，需要把閉區間內所有奇數相加。先把起點調整到第一個奇數，再每次增加 2 累加至終點，最後連同案例編號輸出總和。

<a id="uva-10784_diagonal"></a>
### UVa 10784 — Diagonal／對角線

- 原始碼：[10784_diagonal.c](10784_diagonal.c)
- 演算法：組合計數、二次方程（Math）

**English description:**

Given a required number `N` of diagonals, find and output the smallest number of vertices of a polygon that can have at least `N` diagonals. The diagonal count for `n` vertices is `n(n-3)/2`.

**中文詳細描述：**

輸入給出所需的對角線數 `N`，要找出至少能產生 `N` 條對角線的多邊形最少頂點數。利用 `n` 邊形對角線數為 `n(n-3)/2`，解不等式後向上取整，並依案例格式輸出答案。
