# UVa Volume 013

本卷收錄 1 個 C 題目檔，依 UVa 題號排序。

<a id="uva-1368_dna-consensus-string"></a>

### UVa 1368 — DNA Consensus String／DNA 共識字串

- 原始碼：[1368_dna-consensus-string.c](1368_dna-consensus-string.c)
- 演算法：逐欄頻率統計、貪婪（string, greedy, Hamming distance）

**English description:** Each test case contains `m` DNA strings of equal length `n`. Construct a consensus string that minimizes the sum of Hamming distances to all input strings by choosing a most frequent nucleotide in every column; resolve frequency ties in lexicographic order `A`, `C`, `G`, `T`. Print the consensus followed by the minimum total distance.

**中文詳細描述：** 每組輸入 `m` 條等長為 `n` 的 DNA 序列。對每個字元位置分別統計 `A`、`C`、`G`、`T` 次數，選擇出現最多的鹼基可使該欄與所有序列不同的數量最少；若同頻則依 `A < C < G < T` 取字典序最小者。輸出組成的共識字串，以及它和所有輸入序列的漢明距離總和。
