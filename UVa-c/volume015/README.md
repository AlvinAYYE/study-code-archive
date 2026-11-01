# UVa Volume 015

本卷收錄 7 份 C 解答，涵蓋 7 個 UVa 題號，以下依題號排序。

<a id="uva-1583_digit-generator"></a>

### UVa 1583 — Digit Generator／最小生成元數值逆向查找

- 原始碼：[1583_digit-generator.c](1583_digit-generator.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Find the smallest generator M such that M + sum_of_digits(M) = N, or 0 if no generator exists.

**中文詳細描述：** 若整數 M 加上其各數位之和等於 N，則稱 M 為 N 的生成元。求 N 的最小生成元，若不存在則回傳 0。

**English approach:** Since digit sum of M <= 9 * log10(N), test M from max(1, N - 9 * num_digits) up to N.

**中文解題思路：** 數位和上限為 9 * 位數，只需從 max(1, N - 9 * 位數) 向上枚舉至 N，驗證 M + digit_sum(M) 是否等於 N。 ==========================================================================


<a id="uva-1584_circular-sequence"></a>

### UVa 1584 — Circular Sequence／環狀 DNA 序列最小字典序表示法

- 原始碼：[1584_circular-sequence.c](1584_circular-sequence.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Given a circular DNA sequence of length N, find its lexicographically smallest representation among all N cyclic rotations.

**中文詳細描述：** 環狀 DNA 序列由 A, C, G, T 組成，長度為 N，求其在所有 N 種循環旋轉切點下的最小字典序字串。

**English approach:** Compare all N circular shifts in O(N^2) time or Booth's algorithm. Retain the minimal string.

**中文解題思路：** 枚舉全部 N 個起始切點位置，逐一比較循環位移子字串，保留並輸出字典序最小者。 ==========================================================================


<a id="uva-1585_score"></a>

### UVa 1585 — Score／OX 答題連續得分計算

- 原始碼：[1585_score.c](1585_score.c)
- 演算法：線性掃描、連續計數（string, simulation）

**English description:** Each test case is an `O` and `X` result string. An `O` scores one more point than the immediately preceding consecutive `O`, starting at one, while an `X` resets the streak to zero. Sum the points and print the total score for each string.

**中文詳細描述：** 輸入先給測試筆數，每筆是一串 `O` 與 `X`。連續答對時，第 1 個 `O` 得 1 分、第 2 個得 2 分，依此遞增；遇到 `X` 就把連續次數歸零，下一個 `O` 重新從 1 分開始。線性掃描並累加每次得分，逐組輸出總分。

<a id="uva-1586_molar-mass"></a>

### UVa 1586 — Molar mass／化學分子量莫耳質量計算

- 原始碼：[1586_molar-mass.c](1586_molar-mass.c)
- 難度：UVa Star 1
- 演算法：string, parsing

**English description:** Compute molar mass of chemical formula consisting of C (12.01), H (1.008), O (16.00), and N (14.01) with optional multi-digit integer counts.

**中文詳細描述：** 給定僅含 C (12.01)、H (1.008)、O (16.00) 與 N (14.01) 的化學分子式，計算其莫耳質量 (分子量)。

**English approach:** Scan characters: when letter is encountered, parse subsequent digits (defaulting to 1 if none). Multiply and sum weights.

**中文解題思路：** 掃描分子式，遇到元素符號後解析其後續連續數字作為原子個數 (無數字則預設為 1)，乘以原子量並累加。 ==========================================================================


<a id="uva-1587_box"></a>

### UVa 1587 — Box／盒子 (長方體面匹配驗證)

- 原始碼：[1587_box.c](1587_box.c)
- 難度：Easy
- 演算法：geometry, sorting

**English description:** Given 6 rectangular pallets with dimensions (w, h), determine if they can form a rectangular cuboid.

**中文詳細描述：** 給定 6 塊長方形木板的長寬尺寸，判定它們是否能拼成一個三維長方體。

**English approach:** Normalize each pallet so w <= h. Sort all 6 pallets. Must form 3 identical pairs matching cuboid dimension permutations.

**中文解題思路：** 將每塊木板長寬標準化為 w <= h 並升序排序。合法長方體必有 3 對完全相同的面，且其邊長剛好由 (x, y, z) 兩兩組合而成。 ==========================================================================


<a id="uva-1588_kickdown"></a>

### UVa 1588 — Kickdown／齒條嚙合最短總長度

- 原始碼：[1588_kickdown.c](1588_kickdown.c)
- 難度：Easy
- 演算法：string, simulation

**English description:** Two tooth strips of heights 1 and 2 must fit into a container of height 3 without teeth overlapping (tooth heights at matching positions sum to <= 3). Find min length.

**中文詳細描述：** 兩根齒高為 1 與 2 的齒條需放入高度為 3 的槽中，任何重疊位置齒高之和不可超過 3，求最小包絡長度。

**English approach:** Slide one strip relative to the other. For each offset shift, check if s1[i] - '0' + s2[i - shift] - '0' <= 3 for all overlapping positions.

**中文解題思路：** 滑動比較兩齒條的相對偏移量，檢查重疊處兩齒高之和是否均 <= 3，取重疊後總外接長度的最小值。 ==========================================================================


<a id="uva-1594_ducci-sequence"></a>

### UVa 1594 — Ducci Sequence／杜奇序列 (相鄰差循環收斂)

- 原始碼：[1594_ducci-sequence.c](1594_ducci-sequence.c)
- 難度：Easy
- 演算法：simulation, array

**English description:** Repeatedly transform n-tuple (a1..an) into (|a1-a2|, |a2-a3|, ..., |an-a1|). Determine if it reaches all zeros (ZERO) or enters a cycle (LOOP).

**中文詳細描述：** 反覆將 n 元組轉換為相鄰項差值絕對值數組，判斷是在 1000 步內變為全 0 (ZERO) 還是進入非零循環 (LOOP)。

**English approach:** Simulate step by step up to 1000 iterations. Check if all elements are zero at each step.

**中文解題思路：** 模擬最多 1000 步的相鄰差值迭代，每步檢查是否所有元素均為 0，若達到則輸出 ZERO 否則 LOOP。 ==========================================================================
