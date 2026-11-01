# UVa Volume 113

本卷收錄 21 份 C 解答，涵蓋 20 個 UVa 題號，以下依題號排序。

<a id="uva-11300_spreading-the-wealth"></a>

### UVa 11300 — Spreading the Wealth／財富分配

- 原始碼：[11300_spreading-the-wealth.c](11300_spreading-the-wealth.c)
- 難度：Medium
- 演算法：greedy, math, median

**English description:** People sitting in a circle each have some gold coins. Find the minimum total amount of transferred coins to make everyone's gold equal.

**中文詳細描述：** 圍成一圈的人各自擁有若干金幣，求使每個人金幣數量相等的最少轉移金幣總量。

**English approach:** Formulate as |x1| + |x1 - C1| + |x1 - C2| + ... Total cost is minimized when x1 is the median of prefix imbalances C.

**中文解題思路：** 轉換為數學式 sum(|x1 - C_i|)，當 x1 取 C 序列的中位數時轉移總量最小。 ==========================================================================


<a id="uva-11313_gourmet_games"></a>

### UVa 11313 — Gourmet Games／美食大賽淘汰賽輪數

- 原始碼：[11313_gourmet_games.c](11313_gourmet_games.c)
- 難度：Easy
- 演算法：math, simulation

**English description:** Given n contestants and m contestants participating in each game with 1 winner, determine total games to find a champion, or report if impossible.

**中文詳細描述：** 給定 n 名選手，每場比賽由 m 人參賽且產生 1 名勝者（淘汰 m-1 人），求決出冠軍所需的總場數，若無法決出則回傳 -1。

**English approach:** In each match m-1 contestants are eliminated. Total to eliminate is n-1. If (n-1) % (m-1) == 0, rounds = (n-1)/(m-1), else impossible.

**中文解題思路：** 每場比賽淘汰 m-1 人，總共需淘汰 n-1 人。若 (n-1) % (m-1) == 0 則答案為 (n-1)/(m-1)，否則無法完成淘汰。 ==========================================================================


<a id="uva-11321_sort-sort-and-sort"></a>

### UVa 11321 — Sort! Sort!! and Sort!!!／奇偶模數複合自訂排序演算法

- 原始碼：[11321_sort-sort-and-sort.c](11321_sort-sort-and-sort.c)
- 難度：UVa Star 2
- 演算法：sorting

**English description:** Sort integers by modulo M ascending. For ties: odd before even; if both odd, larger first; if both even, smaller first.

**中文詳細描述：** 按數字除以 M 的餘數升序排列；若餘數相同：奇數排在偶數前；若同為奇數則較大者在先；若同為偶數則較小者在先。

**English approach:** Custom qsort comparator implementing the multi-layer modulus and parity precedence rules.

**中文解題思路：** 實作自訂排序比較器：先按 % M 比較，同餘數則按奇偶優先級、奇數降序、偶數升序細緻排序。 ==========================================================================


<a id="uva-11332_summing-digits"></a>
### UVa 11332 — Summing Digits／數字加總

- 原始碼：[11332_summing-digits.c](11332_summing-digits.c)
- 演算法：數位根（Digital Root）

**English description:**

For every positive integer until the terminating zero, repeatedly replace the value by the sum of its decimal digits until only one digit remains. Output that final digit.

**中文詳細描述：**

逐筆讀入正整數直到 0，將一個數的十進位各位相加；若結果仍有多位數，就繼續做同樣操作，直到只剩一位。輸出最後的數位根，也可用模 9 的公式直接求得。

<a id="uva-11332_summing-digits-pr"></a>

### UVa 11332 — Summing Digits／數根計算 (反覆數位求和)

- 原始碼：[11332_summing-digits-pr.c](11332_summing-digits-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Repeatedly sum digits of integer n until a single-digit integer is produced (digital root).

**中文詳細描述：** 反覆將整數的各位十進位數字相加，直到最後得到個位數為止 (數根，等價於九餘數同餘定理)。

**English approach:** Digital root formula: 1 + (n - 1) % 9 for n > 0.

**中文解題思路：** 數根公式：若 n > 0 且可被 9 整除則為 9，其餘為 n % 9 (即 1 + (n - 1) % 9)。 ==========================================================================


<a id="uva-11340_newspaper"></a>

### UVa 11340 — Newspaper／報紙字元計費總額計算

- 原始碼：[11340_newspaper.c](11340_newspaper.c)
- 難度：UVa Star 1
- 演算法：string, hash

**English description:** Given price per character for K paid characters, calculate total cost of an article in dollars and cents.

**中文詳細描述：** 給定 K 個指定字元的計費單價 (以美分為單位)，計算整篇新聞報導所有字元的總報酬金額。

**English approach:** Maintain a direct-mapped lookup table table[256]. Scan each character of the text, accumulate cents, and format as dollars.

**中文解題思路：** 建立 256 大小的直接映射查找表，掃描文章字元流累加美分總值，最後轉換為美元與美分。 ==========================================================================


<a id="uva-11342_three-square"></a>

### UVa 11342 — Three-square／三平方和定理

- 原始碼：[11342_three-square.c](11342_three-square.c)
- 難度：Easy
- 演算法：math, number-theory, brute-force

**English description:** Find three non-negative integers a <= b <= c such that a^2 + b^2 + c^2 = K.

**中文詳細描述：** 求三個非負整數 a <= b <= c 使得 a^2 + b^2 + c^2 = K（三平方和）。

**English approach:** Precompute square lookup. Iterate a from 0 up to sqrt(K/3), b from a up to sqrt((K - a^2)/2), and check if K - a^2 - b^2 is a square.

**中文解題思路：** 雙重迴圈枚舉 a 與 b，驗證餘數 c^2 = K - a^2 - b^2 是否為完全平方數且 c >= b。 ==========================================================================


<a id="uva-11344_the-huge-one"></a>

### UVa 11344 — The Huge One／超大整數多整除性檢測

- 原始碼：[11344_the-huge-one.c](11344_the-huge-one.c)
- 難度：UVa Star 1
- 演算法：math, big-integer

**English description:** Determine if a huge integer M (up to 1000 digits) is divisible by all numbers in a given set S.

**中文詳細描述：** 給定一個長達 1000 位數的超大整數 M，檢驗其是否能被集合 S 中的所有整數整除。

**English approach:** For each divisor d in S, compute M % d using modular arithmetic on digits: rem = (rem * 10 + digit) % d.

**中文解題思路：** 高精度取模運算：對集合中每個因數 d，逐位計算 rem = (rem * 10 + d_i) % d。若所有 rem 皆為 0 則為 Wonderful。 ==========================================================================


<a id="uva-11349_symmetric-matrix"></a>
### UVa 11349 — Symmetric Matrix／對稱矩陣

- 原始碼：[11349_symmetric-matrix.c](11349_symmetric-matrix.c)
- 演算法：二維陣列、中心對稱（2D Array）

**English description:**

For each square matrix, decide whether every element is non-negative and equals the element mirrored through the matrix center. Output the case number and whether the matrix is symmetric.

**中文詳細描述：**

每組輸入是一個方陣。題目所稱的對稱是以矩陣中心旋轉 180 度後不變，因此每個 `a[i][j]` 必須等於 `a[n-1-i][n-1-j]`，且所有元素皆不可為負；最後依案例格式輸出是否對稱。

<a id="uva-11352_crazy_king"></a>

### UVa 11352 — Crazy King／瘋狂國王 (閃避騎士的最短步數)

- 原始碼：[11352_crazy_king.c](11352_crazy_king.c)
- 難度：Medium
- 演算法：graph, bfs, chess

**English description:** Find the minimum King moves from A to B on a chessboard avoiding enemy knights 'Z' and their attacked squares.

**中文詳細描述：** 在有敵方騎士 'Z' 的棋盤上，求國王從 'A' 走到 'B' 的最少步數，且不得踩到騎士及其攻擊格。

**English approach:** Mark knight attacked squares as blocked (except 'A' and 'B'). Run 8-directional BFS from 'A' to 'B'.

**中文解題思路：** 先標記所有騎士能攻擊到的格子為障礙物（但不得阻擋起點 A 與終點 B），再使用 8 方向 BFS 求最短路徑步數。 ==========================================================================


<a id="uva-11360_have-fun-with-matrices"></a>

### UVa 11360 — Have Fun with Matrices／矩陣變換趣味遊戲

- 原始碼：[11360_have-fun-with-matrices.c](11360_have-fun-with-matrices.c)
- 難度：Easy
- 演算法：matrix-simulation

**English description:** Perform row swaps, col swaps, transpose, and inc/dec modulo 10 on an N x N digit matrix.

**中文詳細描述：** 對 N x N 數字矩陣執行行交換、列交換、轉置、全體加減 1 (模 10) 等操作。

**English approach:** Simulate the operations step by step directly on the matrix.

**中文解題思路：** 直接在二維陣列上模擬各操作：row a b、col a b、transpose、inc 及 dec（模 10 循環）。 ==========================================================================


<a id="uva-11362_phone-list"></a>

### UVa 11362 — Phone List／電話號碼簿前綴無衝突檢驗

- 原始碼：[11362_phone-list.c](11362_phone-list.c)
- 難度：UVa Star 2
- 演算法：string, sorting

**English description:** Determine whether a list of phone numbers is consistent, meaning no phone number is a prefix of another.

**中文詳細描述：** 檢驗電話號碼列表是否合法一致：任一電話號碼均不可為其他號碼的前綴。

**English approach:** Sort phone number strings lexicographically. A number can only be a prefix of its immediate successor in sorted order.

**中文解題思路：** 將電話號碼字串按字典序排序，若存在前綴衝突，則前綴字串必然緊鄰出現在較長字串的前一個位置。 ==========================================================================


<a id="uva-11364_parking"></a>

### UVa 11364 — Parking／最佳停車地點走動距離最小化

- 原始碼：[11364_parking.c](11364_parking.c)
- 難度：UVa Star 1
- 演算法：math, greedy

**English description:** Find minimum total walking distance to visit all shops along a street and return to car.

**中文詳細描述：** 在街道一維座標軸上停車，走遍所有商店後回到停車處，求最少總步行距離 (2 * (max - min))。

**English approach:** Regardless of parking location inside the span, optimal round trip distance is always 2 * (max_pos - min_pos).

**中文解題思路：** 閉區間遍歷性質：無論車停在兩端之間何處，來回拜訪所有點並回到原處的最短總距離恆等於 2 * (最大座標 - 最小座標)。 ==========================================================================


<a id="uva-11367_full-tank"></a>

### UVa 11367 — Full Tank?／滿油出發？ (帶油量狀態的最短路Dijkstra)

- 原始碼：[11367_full-tank.c](11367_full-tank.c)
- 難度：Hard
- 演算法：graph, dijkstra, shortest-path

**English description:** Find minimum fuel cost to travel between two cities with a fuel tank capacity C, where each city has its own fuel price per liter.

**中文詳細描述：** 給定油箱容量 C 與各城市每升油價，求從起點城市前往終點城市的最小燃油花費。

**English approach:** Priority queue state (cost, city, fuel). Transitions: buy 1 liter of fuel at current city (if fuel < C), or travel along an edge (if fuel >= distance).

**中文解題思路：** 以 (花費, 城市, 當前油量) 建立狀態圖 Dijkstra：每次可選擇在原地加 1 升油，或消耗油量沿邊行駛至相鄰城市。 ==========================================================================


<a id="uva-11369_shopaholic"></a>

### UVa 11369 — Shopaholic／購物狂買三送一折扣金額最大化

- 原始碼：[11369_shopaholic.c](11369_shopaholic.c)
- 難度：UVa Star 1
- 演算法：greedy, sorting

**English description:** Buy 3 items, get the cheapest free. Maximize total discount by grouping items greedily.

**中文詳細描述：** 商場優惠買三件免一件 (免費贈送三件中最便宜者)，求將所購物品適當分組下能獲得之最大折扣總金額。

**English approach:** Sort item prices in descending order. Take every 3rd item (index 2, 5, 8...) into discount sum.

**中文解題思路：** 將物品價格由大到小排序，每三件一組，選取每組中最便宜的第 3 件 (索引 2, 5, 8...) 累計折扣金額。 ==========================================================================


<a id="uva-11371_number-theory-for-newbies"></a>

### UVa 11371 — Number Theory for Newbies／新手數論 (最大排列與最小排列之差)

- 原始碼：[11371_number-theory-for-newbies.c](11371_number-theory-for-newbies.c)
- 難度：Easy
- 演算法：math, sorting, string

**English description:** Given an integer n, form the largest number by permuting its digits, and the smallest number (no leading zero). Subtract them and check divisibility by 9.

**中文詳細描述：** 將整數 n 的數位重新排列組成最大整數與最小整數（不可有前導 0），求兩者之差及其除以 9 的商數。

**English approach:** Sort digits descending for max, ascending for min (swap first non-zero to front if leading zero). Result is always divisible by 9.

**中文解題思路：** 數位降序排序得最大數；數位升序（若有前導 0 則與首個非 0 交換）得最小數，相減並除以 9。 ==========================================================================


<a id="uva-11384_help-is-needed-for-dexter"></a>

### UVa 11384 — Help is needed for Dexter／德克斯特的減半消除

- 原始碼：[11384_help-is-needed-for-dexter.c](11384_help-is-needed-for-dexter.c)
- 難度：Easy
- 演算法：math, binary, recursion

**English description:** Given a set of numbers 1..N, subtract an integer X from any subset in one move. Find minimum moves to reduce all to 0.

**中文詳細描述：** 對集合 {1, 2, ..., N} 每次可選任意子集減去相同正整數 X，求使所有數變為 0 的最少操作次數。

**English approach:** Optimal strategy repeatedly halves the range: f(N) = f(N / 2) + 1 = floor(log2(N)) + 1.

**中文解題思路：** 最優策略每次減去中間值將區間折半：f(N) = f(N/2) + 1，故最少次數恰好為 floor(log2(N)) + 1 位元長度。 ==========================================================================


<a id="uva-11385_da-vinci-code"></a>

### UVa 11385 — Da Vinci Code／達文西密碼 (費氏數列下標解密)

- 原始碼：[11385_da-vinci-code.c](11385_da-vinci-code.c)
- 難度：Easy
- 演算法：math, fibonacci, string

**English description:** Given Fibonacci numbers and an encrypted uppercase string, place each character into the 1-based output string at position corresponding to the index of its Fibonacci number.

**中文詳細描述：** 給定一組費氏數列與大寫英文字串，將各字母放入以其費氏數列項數為下標的輸出字串中，其餘位置填空格。

**English approach:** Precompute first 45 Fibonacci numbers. Map given Fibonacci values to their indices, and place corresponding letters into output array.

**中文解題思路：** 預先計算前 45 項費氏數列建立數值到項數索引的映射，將字母填入對應下標位置，末尾空白截斷。 ==========================================================================


<a id="uva-11388_gcd-lcm"></a>

### UVa 11388 — GCD LCM／已知最大公因數與最小公倍數反求二數

- 原始碼：[11388_gcd-lcm.c](11388_gcd-lcm.c)
- 難度：UVa Star 1
- 演算法：math, number-theory

**English description:** Given G and L, find two positive integers a <= b such that gcd(a, b) = G and lcm(a, b) = L.

**中文詳細描述：** 已知兩整數的 gcd 為 G、lcm 為 L，求滿足條件的最小 a 與相應的 b (若無解輸出 -1)。

**English approach:** Solution exists iff L % G == 0. If so, a = G and b = L is always a valid minimal solution.

**中文解題思路：** 數論性質：解存在的充分必要條件為 L 可被 G 整除。若整除，直接取 a = G 且 b = L 即為最優解，否則無解。 ==========================================================================


<a id="uva-11389_the-bus-driver-problem"></a>

### UVa 11389 — The Bus Driver Problem／公車司機加班費最佳排班化

- 原始碼：[11389_the-bus-driver-problem.c](11389_the-bus-driver-problem.c)
- 難度：UVa Star 1
- 演算法：greedy, sorting

**English description:** Pair n morning routes and n evening routes to minimize total overtime pay (rate R per hour exceeding d).

**中文詳細描述：** 將 n 條上午路線與 n 條下午路線進行配對，使所有司機超時工作 (超過 d 小時部分每小時給予 R 元加班費) 的總支出達到最小。

**English approach:** Sort morning routes ascending and evening routes descending. Pair morning[i] with evening[i].

**中文解題思路：** 貪婪法：將早班路線升序排列、晚班路線降序排列進行對應相加，累加各司機超出 d 的超時時數乘以費率 R。 ==========================================================================


<a id="uva-11396_claw-decomposition"></a>

### UVa 11396 — Claw Decomposition／爪圖分解 (二分圖判定)

- 原始碼：[11396_claw-decomposition.c](11396_claw-decomposition.c)
- 難度：Medium
- 演算法：graph, bipartite-check, 2-coloring

**English description:** Determine if a 3-regular graph can be decomposed into claw graphs (K_{1,3}).

**中文詳細描述：** 判斷一個 3-正則圖是否能分解為爪圖 (K_{1,3})。由定理知當且僅當圖為二分圖時可分解。

**English approach:** A 3-regular graph is claw-decomposable if and only if it is bipartite. Use BFS/DFS 2-coloring to check.

**中文解題思路：** 根據圖論定理，3-正則圖能分解為爪圖的充要條件是該圖為二分圖。使用 BFS 進行二染色判定即可。 ==========================================================================
