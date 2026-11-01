# UVa Volume 013

本卷收錄 4 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-1316_supermarket"></a>

### UVa 1316 — Supermarket／超市促銷排程 (貪心並查集時間槽)

- 原始碼：[1316_supermarket.c](1316_supermarket.c)
- 難度：Medium
- 演算法：greedy, disjoint-set-union, priority-queue

**English description:** Schedule products with profits and deadlines (each takes 1 unit of time) to maximize total profit.

**中文詳細描述：** 每件商品有銷售利潤與截止期限（每單位時間只能售出一件商品），求最大獲利總額。

**English approach:** Sort products by profit descending. Use DSU to find the latest available free time slot <= deadline for each product.

**中文解題思路：** 貪心法：商品依利潤降序排序，用並查集維護小於等於截止期限的最晚可用時間槽，成功佔位則獲取利潤。 ==========================================================================


<a id="uva-1339_ancient-cipher"></a>

### UVa 1339 — Ancient Cipher／古代密碼字母置換與排列判定

- 原始碼：[1339_ancient-cipher.c](1339_ancient-cipher.c)
- 難度：UVa Star 1
- 演算法：string, sorting

**English description:** Determine if string A can be transformed into string B by a combination of letter substitution bijection and character permutation.

**中文詳細描述：** 判定字串 A 是否能透過字母單射置換與字母順序重排轉換為字串 B (字元各自出現頻率集合相同)。

**English approach:** Count character frequencies in A and B (arrays of size 26). Sort both frequency arrays; return 1 if identical, else 0.

**中文解題思路：** 統計字串中 26 個字母出現頻率，將頻率數組排序後，若頻率分佈完全一致則可以轉換。 ==========================================================================


<a id="uva-1368_dna-consensus-string"></a>

### UVa 1368 — DNA Consensus String／DNA 共識字串

- 原始碼：[1368_dna-consensus-string.c](1368_dna-consensus-string.c)
- 演算法：逐欄頻率統計、貪婪（string, greedy, Hamming distance）

**English description:** Each test case contains `m` DNA strings of equal length `n`. Construct a consensus string that minimizes the sum of Hamming distances to all input strings by choosing a most frequent nucleotide in every column; resolve frequency ties in lexicographic order `A`, `C`, `G`, `T`. Print the consensus followed by the minimum total distance.

**中文詳細描述：** 每組輸入 `m` 條等長為 `n` 的 DNA 序列。對每個字元位置分別統計 `A`、`C`、`G`、`T` 次數，選擇出現最多的鹼基可使該欄與所有序列不同的數量最少；若同頻則依 `A < C < G < T` 取字典序最小者。輸出組成的共識字串，以及它和所有輸入序列的漢明距離總和。

<a id="uva-1395_slim_spanning_tree"></a>

### UVa 1395 — Slim Spanning Tree／苗條生成樹 (最小化極差)

- 原始碼：[1395_slim_spanning_tree.c](1395_slim_spanning_tree.c)
- 難度：Medium
- 演算法：graph, mst, kruskal, two-pointers

**English description:** Find a spanning tree that minimizes the difference between the maximum and minimum edge weights.

**中文詳細描述：** 在給定的無向連通圖中，求一棵生成樹使得最大邊權與最小邊權之差最小。

**English approach:** Sort edges by weight. For each possible starting edge, run Kruskal's to find spanning tree and record difference.

**中文解題思路：** 將邊按權重由小到大排序。枚舉每一條邊作為生成樹的最小邊，使用 Kruskal 尋找生成樹，記錄差值的最小值。 ==========================================================================
