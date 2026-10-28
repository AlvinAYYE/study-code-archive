# UVa Volume 001

本卷收錄 13 個 C 題目檔，依 UVa 題號排序。

<a id="uva-100_the-3n-plus-1-problem"></a>

### UVa 100 — The 3n + 1 Problem／3n + 1 問題（考拉茲猜想）

- 原始碼：[100_the-3n-plus-1-problem.c](100_the-3n-plus-1-problem.c)
- 演算法：逐項模擬、數學（simulation, Collatz sequence）

**English description:** Given two integers `i` and `j`, examine every integer in the inclusive interval between them. Repeatedly replace an even value by half of itself and an odd value by `3n + 1`, count the terms through 1, and output the original pair followed by the largest cycle length found.

**中文詳細描述：** 每行輸入兩個整數 `i`、`j`；對兩者之間（含端點）的每個整數產生考拉茲數列：偶數除以 2，奇數變成 `3n + 1`，直到 1 為止。計算各數列包含起點與 1 的項數，輸出原始順序的 `i j`，以及區間內最大的循環長度。

<a id="uva-101_the-blocks-problem"></a>

### UVa 101 — The Blocks Problem／積木問題

- 原始碼：[101_the-blocks-problem.c](101_the-blocks-problem.c)
- 演算法：資料結構模擬（simulation, stacks）

**English description:** Start with block `i` alone at position `i`. Process `move` or `pile` commands combined with `onto` or `over`: blocks above selected blocks may be returned home, and either one block or an entire pile is transferred. Ignore commands involving blocks already in the same stack, stop at `quit`, and print every final stack.

**中文詳細描述：** 輸入積木數量後，每塊編號 `i` 的積木一開始單獨放在第 `i` 疊。依序執行 `move/pile` 與 `onto/over` 組成的四種指令；其中可能先把目標上方積木送回原位，再搬動單塊或整段積木。兩塊已在同一疊時忽略該指令，讀到 `quit` 後輸出每個位置的最終堆疊。

<a id="uva-102_ecological-bin-packing"></a>

### UVa 102 — Ecological Bin Packing／生態回收桶

- 原始碼：[102_ecological-bin-packing.c](102_ecological-bin-packing.c)
- 演算法：全排列枚舉、貪婪比較（brute force, permutation）

**English description:** Each input case gives the counts of brown, green, and clear bottles in three bins. Assign one distinct color to each bin and move all bottles of the other colors out. Output the three-letter assignment requiring the fewest moves, choosing the lexicographically earliest assignment on a tie, followed by the move count.

**中文詳細描述：** 每筆輸入給出三個箱子中棕色、綠色、透明瓶子的數量。要讓每個箱子只保留一種顏色且三色各占一箱，計算六種顏色排列所需搬走的瓶子數。輸出搬移次數最少的三字母配置與次數；若同樣少，取字典序最前的配置。

<a id="uva-105_the-skyline-problem"></a>

### UVa 105 — The Skyline Problem／天際線輪廓問題

- 原始碼：[105_the-skyline-problem.c](105_the-skyline-problem.c)
- 演算法：座標高度掃描（simulation, sweep by coordinates）

**English description:** Buildings are supplied as triples `(L, H, R)` describing their left coordinate, height, and right coordinate. Combine all buildings and output the critical x-coordinates where the visible maximum height changes, alternating each coordinate with its new skyline height and ending when the height returns to zero.

**中文詳細描述：** 輸入若干棟以左界 `L`、高度 `H`、右界 `R` 表示的建築。對每個水平座標取所有覆蓋建築的最大高度，找出整體輪廓高度發生變化的位置。輸出一連串「座標、新高度」關鍵點，最後包含天際線降回 0 的位置。

<a id="uva-108_maximum-sum"></a>

### UVa 108 — Maximum Sum／最大二維子矩陣和

- 原始碼：[108_maximum-sum.c](108_maximum-sum.c)
- 演算法：動態規劃、二維 Kadane（dynamic programming, 2D Kadane）

**English description:** Given an `N × N` integer matrix, choose a nonempty axis-aligned rectangular submatrix whose entries have the greatest possible sum. Output that maximum sum, including the correct negative value when every matrix entry is negative.

**中文詳細描述：** 輸入一個 `N × N` 整數矩陣，從中選擇非空且邊界平行於矩陣的矩形區域，使區域內元素總和最大。程式枚舉上下邊界、將各欄壓成一維後套用最大子陣列演算法，最後輸出最大總和；全為負數時也要保留正確的負值答案。

<a id="uva-113_power-of-cryptography"></a>

### UVa 113 — Power of Cryptography／密碼學的威力

- 原始碼：[113_power-of-cryptography.c](113_power-of-cryptography.c)
- 演算法：數學、浮點開根取整（math, nth root）

**English description:** For each pair `n` and `p`, the input guarantees that `p = k^n` for an integer `k`. Recover and output `k`, even though the decimal representation of `p` may be very large.

**中文詳細描述：** 每筆輸入先給指數 `n`，再給一個很大的整數 `p`，並保證存在整數 `k` 使 `p = k^n`。題目要求反推出這個整數底數；實作以浮點數計算 `n` 次方根並四捨五入，逐筆輸出 `k`。

<a id="uva-118_mutant-flatworld-explorers"></a>

### UVa 118 — Mutant Flatworld Explorers／異變的扁平世界探險家

- 原始碼：[118_mutant-flatworld-explorers.c](118_mutant-flatworld-explorers.c)
- 演算法：網格模擬、方向向量（simulation, grid）

**English description:** A rectangular world and a sequence of robots are given. Each robot starts at a coordinate and orientation, then follows left turns, right turns, and forward moves. A robot that steps beyond the border is lost and leaves a scent at its last valid position; later robots ignore a forward command that would fall from the same scented edge. Print each robot's final state and whether it was lost.

**中文詳細描述：** 先輸入矩形世界的右上邊界，接著逐一給定機器人的起點、朝向與由 `L`、`R`、`F` 組成的指令。機器人若向前走出邊界便在最後合法位置留下氣味並標為 `LOST`；之後其他機器人在同一位置、同一掉落方向會忽略該前進指令。輸出每台機器人的最終座標、方向及是否失蹤。

<a id="uva-119_greedy-gift-givers"></a>

### UVa 119 — Greedy Gift Givers／貪婪的送禮者

- 原始碼：[119_greedy-gift-givers.c](119_greedy-gift-givers.c)
- 演算法：字串查表、收支模擬（simulation, name lookup）

**English description:** A group of named friends exchanges gifts. For each giver, divide the stated amount equally among the listed recipients; any indivisible remainder stays with the giver. Output every person's net gain or loss in the same order in which the names were introduced.

**中文詳細描述：** 每組資料先給人數與依序出現的姓名，再描述每位送禮者準備的金額及收禮名單。金額以整數平均分給收禮者，不能整除的餘額由送禮者保留；沒有人可送時也不扣款。累計每人的收入減支出，最後按原姓名順序輸出淨收支。

<a id="uva-120_stacks-of-flapjacks"></a>

### UVa 120 — Stacks of Flapjacks／煎餅堆排序

- 原始碼：[120_stacks-of-flapjacks.c](120_stacks-of-flapjacks.c)
- 演算法：煎餅排序、貪婪模擬（sorting, pancake sort）

**English description:** Each input line lists pancake diameters from the top of a stack to the bottom. A flip inserts a spatula at some depth and reverses all pancakes above it. Echo the original stack, then output a sequence of flip positions that sorts it with the largest pancake at the bottom, terminated by `0`.

**中文詳細描述：** 每行輸入一疊煎餅的直徑，順序由頂端到最底端。一次操作可選擇某個深度，將其上方整段煎餅反轉；程式反覆把尚未定位的最大煎餅先翻到頂端，再翻到目前底部。先原樣輸入該列，再輸出完成排序的翻轉位置序列，並以 `0` 結束。

<a id="uva-136_ugly-numbers"></a>

### UVa 136 — Ugly Numbers／醜數

- 原始碼：[136_ugly-numbers.c](136_ugly-numbers.c)
- 演算法：動態規劃、三指標（dynamic programming, three pointers）

**English description:** Ugly numbers are positive integers whose only prime factors are 2, 3, and 5, with 1 included as the first ugly number. Generate the sequence in increasing order and print the fixed requested value: the 1500th ugly number.

**中文詳細描述：** 醜數定義為質因數只可能含 2、3、5 的正整數，並把 1 視為第一個醜數。本題沒有一般資料輸入；程式用三個指標合併乘 2、乘 3、乘 5 形成的遞增序列，去除重複值後輸出第 1500 個醜數。

<a id="uva-146_id-codes"></a>

### UVa 146 — ID Codes／識別碼字典序下一個排列

- 原始碼：[146_id-codes.c](146_id-codes.c)
- 演算法：字串、下一個排列（string, next permutation）

**English description:** For each identifier string, find the smallest permutation of its characters that is lexicographically greater than the input. Print that immediate successor, or print `No Successor` when the input is already the greatest permutation. Input ends at `#`.

**中文詳細描述：** 每行輸入一個識別碼字串，要求用相同字元重新排列，找出字典序中緊接在原字串之後的排列。由右向左找可增加的位置、交換後反轉後綴；若原字串已是最大排列則輸出 `No Successor`。讀到 `#` 時結束。

<a id="uva-151_power-crisis"></a>

### UVa 151 — Power Crisis／電力危機

- 原始碼：[151_power-crisis.c](151_power-crisis.c)
- 演算法：約瑟夫環模擬（simulation, Josephus problem）

**English description:** Regions numbered `1` through `N` are switched off in a cyclic elimination process. Region 1 must be removed first, and every `m`-th remaining region is then removed. For each `N`, find the smallest positive `m` that leaves region 13 as the final powered region; input ends with zero.

**中文詳細描述：** 對每個輸入的地區數 `N`，編號 1 的地區先停電，之後在仍有電的地區間循環計數，每數到第 `m` 個便使其停電。枚舉正整數 `m` 並模擬約瑟夫淘汰過程，找出讓第 13 區最後才停電的最小 `m`；輸入 0 結束，逐筆輸出答案。

<a id="uva-160_factors-and-factorials"></a>

### UVa 160 — Factors and Factorials／階乘的質因數分解

- 原始碼：[160_factors-and-factorials.c](160_factors-and-factorials.c)
- 演算法：質因數計數、勒讓德公式（number theory, Legendre's formula）

**English description:** For each positive integer `N`, express `N!` by listing the exponent of every prime not exceeding `N`, in ascending prime order and in the required aligned format. Input terminates with zero.

**中文詳細描述：** 每筆輸入正整數 `N`，要將 `N!` 分解成質數冪乘積，並依質數由小到大列出每個指數。對質數 `p` 累加 `⌊N/p⌋ + ⌊N/p²⌋ + …` 即得其在階乘中的次數；按照題目欄寬格式輸出，輸入 0 時結束。
