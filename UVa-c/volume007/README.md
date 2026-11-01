# UVa Volume 007 題目索引

本卷收錄 27 份 C 解答，涵蓋 27 個 UVa 題號，以下依題號排序。

<a id="uva-700_date_bugs"></a>

### UVa 700 — Date Bugs／千年蟲日期還原 (同餘模擬)

- 原始碼：[700_date_bugs.c](700_date_bugs.c)
- 難度：Medium
- 演算法：math, chinese-remainder, simulation

**English description:** Find the actual year given multiple computers each with a year-display bug that cycles every (b - a) years.

**中文詳細描述：** 給定多台有日期漏洞的電腦顯示年份與循環週期，求所有電腦能吻合顯示的最早實際年份（< 10000）。

**English approach:** Simulate forward starting from the earliest valid year of the computer with largest period.

**中文解題思路：** 以週期最大或首台電腦為基準，逐步按週期跳躍檢查是否同時滿足其他所有電腦的同餘條件。 ==========================================================================


<a id="uva-701_the-archeologists-dilemma"></a>

### UVa 701 — The Archeologists' Dilemma／考古學家的難題

- 原始碼：[701_the-archeologists-dilemma.c](701_the-archeologists-dilemma.c)
- 難度：Medium
- 演算法：math, logarithms

**English description:** Find the smallest power of 2 whose decimal representation starts with N, and has more than double the number of digits of N.

**中文詳細描述：** 求最小的 2 的冪次方，其十進位表示以 N 開頭，且總位數嚴格大於 N 的位數的兩倍。

**English approach:** Let k be total digits (k >= 2*len(N)+1). Check if range [log2(N) + k*log2(10), log2(N+1) + k*log2(10)] contains an integer E.

**中文解題思路：** 設總位數為 k（k >= 2*len(N)+1），利用對數區間 [log2(N) + k*log2(10), log2(N+1) + k*log2(10)] 判斷是否有整數指數 E。 ==========================================================================


<a id="uva-705_slash-maze"></a>

### UVa 705 — Slash Maze／斜線迷宮迴圈與迷宮路徑

- 原始碼：[705_slash-maze.c](705_slash-maze.c)
- 難度：Medium
- 演算法：dfs, flood-fill, graph-cycle

**English description:** In a maze made of '/' and '\' characters, find the number of closed cycles and the maximum cycle length.

**中文詳細描述：** 在由 '/' 與 '\' 斜線構成的迷宮中，求閉合環路數量及最長環路長度。

**English approach:** Enlarge each cell to 3x3 grid (slash drawn with 3 cells). Run flood fill: non-boundary connected component of 0s forms a cycle.

**中文解題思路：** 將每個斜線放大為 3x3 網格表示，進行 DFS 洪水填充著色，凡未接觸外邊界的連通塊即構成環路，長度除以 3 即為迷宮步數。 ==========================================================================


<a id="uva-706_lc-display"></a>

### UVa 706 — LC-Display／液晶數位顯示器排版 (7段 LCD 模擬)

- 原始碼：[706_lc-display.c](706_lc-display.c)
- 難度：UVa Star 1
- 演算法：simulation, formatting, string

**English description:** Render digits in LCD 7-segment style using '-' and '|' with scale factor s.

**中文詳細描述：** 依放大倍率 s 將十進位數字模擬為 7 段液晶電子手錶風格的數位字元圖案輸出。

**English approach:** 7 horizontal/vertical segments per digit. Construct 2s+3 rows and (s+2)*len columns grid.

**中文解題思路：** 將每個數字的 7 條線段編碼，依倍率 s 計算高度 2s+3 與單字寬度 s+2 逐行填入 '-' 與 '|'。 ==========================================================================


<a id="uva-712_s-trees"></a>

### UVa 712 — S-Trees／布林決策樹 (S-樹)

- 原始碼：[712_s-trees.c](712_s-trees.c)
- 難度：Easy
- 演算法：binary-tree, bit-manipulation

**English description:** Simulate evaluation on a fully balanced boolean decision tree (S-tree) given variable assignment vectors.

**中文詳細描述：** 給定變數排列順序與各賦值向量，在完全平衡的布林決策樹上沿左右子樹遍歷求葉節點結果值。

**English approach:** Compute binary index of leaf node: each variable x_i in order determines whether to take the left branch (0) or right branch (1).

**中文解題思路：** 依變數順序取出賦值 0 或 1 作為二進位位的權重，組合出葉節點的下標直接取得輸出值。 ==========================================================================


<a id="uva-713_adding-reversed-numbers"></a>

### UVa 713 — Adding Reversed Numbers／反向數字大數相加

- 原始碼：[713_adding-reversed-numbers.c](713_adding-reversed-numbers.c)
- 難度：UVa Star 1
- 演算法：math, big-integer, string

**English description:** Reverse digits of two numbers, sum them up, and output the reversed sum (ignoring leading zeros).

**中文詳細描述：** 將兩個大數反向翻轉後相加，再將相加結果翻轉輸出 (忽略結果的前導 0)。

**English approach:** Because input is already reversed from least significant digit, standard big-integer addition from index 0 directly computes the reversed sum.

**中文解題思路：** 由於輸入的數字已是反轉格式，剛好可直接從下標 0 (最低位) 進行大數相加並去除前導零。 ==========================================================================


<a id="uva-714_copying-books"></a>

### UVa 714 — Copying Books／抄書員最大頁數極小化二分搜尋

- 原始碼：[714_copying-books.c](714_copying-books.c)
- 難度：UVa Star 2
- 演算法：binary-search, greedy

**English description:** Divide M books across K scribes to minimize the maximum total pages assigned to any scribe (preserving original order).

**中文詳細描述：** 將 M 本書分派給 K 位抄書員在連續段落抄寫，求所有抄書員中最大抄書頁數總和的極小值 (二分搜尋 + 貪婪劃分)。

**English approach:** Binary search on maximum page limit in [max(pages), sum(pages)]. Greedily allocate books backwards from scribe K to scribe 1.

**中文解題思路：** 在 [最大單本頁數, 總頁數] 範圍內二分搜尋上限值，貪婪地從後向前為每位抄書員配置不超過上限的書籍數量。 ==========================================================================


<a id="uva-719_glass-beads"></a>

### UVa 719 — Glass Beads／玻璃珠項鍊 (最小循環表示法)

- 原始碼：[719_glass-beads.c](719_glass-beads.c)
- 難度：Medium
- 演算法：string, minimum-representation

**English description:** Find the 1-based starting position of the lexicographically smallest cyclic shift of a circular string.

**中文詳細描述：** 求環形字串所有循環同構中字典序最小的起始切割位置（最小循環表示法，Booth 演算法）。

**English approach:** Dual pointers Booth's algorithm in O(N) or doubled string comparison.

**中文解題思路：** 經典最小表示法：雙指針 i, j, k 比較 s[i+k] 與 s[j+k]，跳躍淘汰較大者，O(N) 找出最小循環位置。 ==========================================================================


<a id="uva-725_division"></a>

### UVa 725 — Division／五位數除法全數字排列搜尋

- 原始碼：[725_division.c](725_division.c)
- 難度：UVa Star 1
- 演算法：brute-force, math

**English description:** Find all pairs of 5-digit numbers abcde / fghij = N using digits 0..9 exactly once.

**中文詳細描述：** 求所有滿足 abcde / fghij = N 且十個數字 0 到 9 恰好各用一次的五位數商數配對。

**English approach:** Enumerate denominator fghij from 01234 to 98765 / N. Compute abcde = fghij * N. Check if all 10 digits are distinct via bitmask.

**中文解題思路：** 枚舉分母 fghij (1234 到 98765/N)，算出分子 abcde = fghij * N，以位元遮罩判定兩數 10 個位數是否互異不重複。 ==========================================================================


<a id="uva-727_equation"></a>

### UVa 727 — Equation／中序表達式轉後序表達式 (調車場演算法 Shunting Yard)

- 原始碼：[727_equation.c](727_equation.c)
- 難度：UVa Star 1
- 演算法：stack, parsing, shunting-yard

**English description:** Convert infix arithmetic expression with + - * / and parentheses to postfix notation.

**中文詳細描述：** 使用堆疊將含有加減乘除與括號的中序算術表達式轉換為後序 (波蘭倒置) 表達式。

**English approach:** Dijkstra's Shunting-yard algorithm: operators popped to output based on precedence (* / > + -).

**中文解題思路：** 調車場演算法：數字直接輸出；運算子依優先順序彈棧；左括號入棧；右括號彈出直到匹配左括號。 ==========================================================================


<a id="uva-729_the-hamming-distance-problem"></a>

### UVa 729 — The Hamming Distance Problem／指定漢明距離二進位字串生成

- 原始碼：[729_the-hamming-distance-problem.c](729_the-hamming-distance-problem.c)
- 難度：UVa Star 1
- 演算法：bit-manipulation, combinatorics, backtracking

**English description:** Generate all N-bit binary strings containing exactly H ones in ascending lexicographical order.

**中文詳細描述：** 長度為 N 的二進位字串中恰含有 H 個 1，按字典序由小到大輸出所有相異字串 (C(N, H))。

**English approach:** Backtracking recursion: try placing '0' then '1' at each bit if remaining ones count permits.

**中文解題思路：** 回溯遞迴構造長度為 N 的字串，先遞迴補 0 再遞迴補 1，自然保證生成的二進位字串符合升序字典序。 ==========================================================================


<a id="uva-732_anagrams-by-stack"></a>

### UVa 732 — Anagrams by Stack／堆疊重組字謎

- 原始碼：[732_anagrams-by-stack.c](732_anagrams-by-stack.c)
- 難度：Medium
- 演算法：backtracking, stack

**English description:** Find all sequences of push ('i') and pop ('o') operations that transform source word into target word via stack.

**中文詳細描述：** 求所有透過堆疊 push ('i') 與 pop ('o') 操作將來源單字轉換為目標單字的操作序列（按字典序輸出）。

**English approach:** DFS backtrack tracking input pointer, stack content, matched output length, and operation history. Prioritize 'i' over 'o' for lexicographical order.

**中文解題思路：** 深度優先回溯搜尋：維護輸入字元指標、當前堆疊與已匹配字元數，優先嘗試 'i' 再嘗試 'o' 生成字典序序列。 ==========================================================================


<a id="uva-735_dart-a-mania"></a>

### UVa 735 — Dart-a-Mania／飛鏢大狂熱 (3鏢得分組合與排列)

- 原始碼：[735_dart-a-mania.c](735_dart-a-mania.c)
- 難度：Easy
- 演算法：brute-force, math, combinatorics

**English description:** Find the number of combinations and permutations of 3 dart throws (scores 1..20 single/double/triple, bullseye 50, or miss 0) that sum to score S.

**中文詳細描述：** 投擲 3 支飛鏢，得分為 1~20 的 1/2/3 倍、外紅心 50 或脫靶 0 分，求總分恰好為 S 的相異得分組合數與排列數。

**English approach:** Generate sorted list of distinct single-dart scores (43 values). Triple loops over all scores. Count combinations (i <= j <= k) and corresponding permutations.

**中文解題思路：** 收集所有 43 種單鏢得分值並排序，三重迴圈枚舉 (i <= j <= k) 滿足三鏢和為 S 的組合，並根據三數相同/兩數相同/三數相異累計排列數。 ==========================================================================


<a id="uva-739_soundex-indexing"></a>

### UVa 739 — Soundex Indexing／聲學索引編碼

- 原始碼：[739_soundex-indexing.c](739_soundex-indexing.c)
- 難度：Easy
- 演算法：string, soundex

**English description:** Encode a surname using the Soundex system (letter followed by 3 digits, padding with zeros, omitting vowels, collapsing duplicates).

**中文詳細描述：** 使用 Soundex 聲學編碼系統將姓氏轉換為 1 個首字母與 3 位數字的編碼（母音不編碼，相鄰同碼合併，補 0 至 4 位）。

**English approach:** Keep first letter. Map rest according to Soundex rules. Skip code 0. Skip adjacent identical codes. Pad/truncate to 4 chars.

**中文解題思路：** 保留首字母，其餘字母按 Soundex 規則映射；略過代碼 0 及連續相同代碼，最後補 0 或截斷至 4 字元。 ==========================================================================


<a id="uva-740_baudot-data-communication-code"></a>

### UVa 740 — Baudot Data Communication Code／博多通信電碼解碼 (移位鍵模擬)

- 原始碼：[740_baudot-data-communication-code.c](740_baudot-data-communication-code.c)
- 難度：Easy
- 演算法：simulation, string

**English description:** Decode 5-bit Baudot teleprinter characters with downshift (lowercase/letters) and upshift (figures/symbols) mode switches.

**中文詳細描述：** 解碼 5 位元博多電碼：具有字母下檔 (Down-shift) 與符號上檔 (Up-shift) 模式切換碼。

**English approach:** Maintain shift state: downshift (0) vs upshift (1). Code 27 switches to downshift, code 31 switches to upshift. Map other codes directly.

**中文解題思路：** 維護當前上下檔狀態（代碼 27 切換下檔，代碼 31 切換上檔），依 5 位元二進位整數查表轉換為字元。 ==========================================================================


<a id="uva-748_exponentiation"></a>

### UVa 748 — Exponentiation／高精度浮點數冪次運算 (R^n)

- 原始碼：[748_exponentiation.c](748_exponentiation.c)
- 難度：UVa Star 2
- 演算法：math, big-integer, precision

**English description:** Compute exact real power R^n for positive real number R < 100.0 and integer n <= 25 without trailing zeros.

**中文詳細描述：** 計算高精度浮點數的整數次方 R^n (n <= 25)，輸出時精確保留所有有效數位，不使用科學記號並去除前導與結尾無效 0。

**English approach:** Remove decimal point and track decimals count * n. Perform BigInt multiplication, then insert decimal point and trim.

**中文解題思路：** 移除小數點轉換為純整數高精度相乘，累計小數點位數 d * n，運算完成後補入小數點並抹除末尾多餘的 0。 ==========================================================================


<a id="uva-750_8-queens-chess-problem"></a>

### UVa 750 — 8 Queens Chess Problem／定點八皇后問題 (指定起點回溯)

- 原始碼：[750_8-queens-chess-problem.c](750_8-queens-chess-problem.c)
- 難度：UVa Star 1
- 演算法：backtracking, chess

**English description:** Output all valid 8-queens board solutions where one queen is fixed at given square (r, c).

**中文詳細描述：** 在 8x8 棋盤上擺放 8 個皇后互不衝突，其中指定位置 (r, c) 已預先固定一個皇后，輸出所有合法解。

**English approach:** Standard 8-queens backtracking search across 8 columns. Force column c to place queen at row r.

**中文解題思路：** 8 列回溯擺放皇后，遇到給定的指定行時強制選擇指定列，其餘行枚舉所有無衝突位置，字典序輸出解答。 ==========================================================================


<a id="uva-755_487-3279"></a>

### UVa 755 — 487--3279／電話號碼標準化與重複統計

- 原始碼：[755_487-3279.c](755_487-3279.c)
- 難度：UVa Star 1
- 演算法：string, sorting, simulation

**English description:** Standardize phone numbers (letters to digits A..P->2..7, R..Y->7..9), find all numbers appearing > 1 time, sorted.

**中文詳細描述：** 將電話號碼英文字母轉為對應按鍵數字並去除破折號，格式化為 7 位數，統計出現 2 次以上的號碼按字典序輸出。

**English approach:** Map char to digit: (c - 'A' - (c > 'Q')) / 3 + 2. Convert to 7-digit integer, sort array and group duplicate counts.

**中文解題思路：** 依電話按鍵將字母映射為數字 0-9，存入 32 位元整數陣列快速排序，線性掃描統計出現次數大於 1 的重複號碼。 ==========================================================================


<a id="uva-756_biorhythms"></a>

### UVa 756 — Biorhythms／生物節律 (中國剩餘定理)

- 原始碼：[756_biorhythms.c](756_biorhythms.c)
- 難度：Easy
- 演算法：math, chinese-remainder-theorem

**English description:** Find the number of days until the physical (23d), emotional (28d), and intellectual (33d) cycles peak on the exact same day.

**中文詳細描述：** 體力（23天）、情緒（28天）、智力（33天）三個生物節律週期，求從給定日 d 起最快多少天後三者再次同時達到峰值。

**English approach:** Chinese Remainder Theorem: x = p mod 23, x = e mod 28, x = i mod 33. Period is 23*28*33 = 21252. Output (x - d - 1) % 21252 + 1.

**中文解題思路：** 中國剩餘定理：CRT 求解模 23, 28, 33 的同餘方程，在 (d, d + 21252] 範圍內求最小正整數解。 ==========================================================================


<a id="uva-760_dna-sequencing"></a>

### UVa 760 — DNA Sequencing／DNA 測序 (最長公共子串 LCS)

- 原始碼：[760_dna-sequencing.c](760_dna-sequencing.c)
- 難度：Medium
- 演算法：string, longest-common-substring

**English description:** Find all longest common substrings between two DNA strings, sorted alphabetically.

**中文詳細描述：** 求兩段 DNA 序列之間的所有最長公共連續子串，按字典序去重輸出；若無公共子串則輸出提示。

**English approach:** DP table dp[i][j] = common substring length ending at s1[i-1] and s2[j-1]. Track max length and collect distinct substrings of that length.

**中文解題思路：** 二維動態規劃求解最長公共子串（若 s1[i]==s2[j] 則 dp[i][j] = dp[i-1][j-1] + 1），求最大長度並去重排序提取子串。 ==========================================================================


<a id="uva-762_we-ship-cheap"></a>

### UVa 762 — We Ship Cheap／城市航線貨運最短轉機路徑 BFS

- 原始碼：[762_we-ship-cheap.c](762_we-ship-cheap.c)
- 難度：UVa Star 2
- 演算法：graph, bfs, shortest-path

**English description:** Find the route with the minimum number of flight connections between city A and city B.

**中文詳細描述：** 在城市航線網路中，找出從起點城市 A 運送至終點城市 B 所需轉機次數最少的最短飛行路徑。

**English approach:** BFS on undirected graph using city name mappings and parent pointers to reconstruct and output the path.

**中文解題思路：** 以廣度優先搜尋 (BFS) 尋找最短轉機步數，維護 parent 前驅陣列，回溯重構路徑各航段城市代碼。 ==========================================================================


<a id="uva-763_fibinary-numbers"></a>

### UVa 763 — Fibinary Numbers／斐波那契進位制 (齊肯多夫加法運算)

- 原始碼：[763_fibinary-numbers.c](763_fibinary-numbers.c)
- 難度：Medium
- 演算法：math, zeckendorf-theorem, big-integer

**English description:** Add two Zeckendorf binary numbers (fibinary numbers where no two consecutive 1s occur) and output the sum in standard fibinary form.

**中文詳細描述：** 計算兩個齊肯多夫進位制數（以費氏數為基底且無相鄰的 1）之和，並規範化為標準齊肯多夫表示法。

**English approach:** Convert to big integer and greedily extract Zeckendorf representation from largest Fibonacci number downwards, or use carry rules F(n-1)+F(n)=F(n+1).

**中文解題思路：** 將兩數轉為數值相加，再自最大的費氏數向下貪心減去以求得標準齊肯多夫（無連續 1）表示法。 ==========================================================================


<a id="uva-784_maze-exploration"></a>

### UVa 784 — Maze Exploration／迷宮探索填色 (四方向連通 DFS 塗色)

- 原始碼：[784_maze-exploration.c](784_maze-exploration.c)
- 難度：UVa Star 1
- 演算法：graph, flood-fill, dfs

**English description:** Given maze of walls, start at '*' and color all connected empty spaces with '#'.

**中文詳細描述：** 在帶有不規則圍牆的迷宮中，由起點 '*' 開始向上下左右四方向走訪，將所有可達的空白格全部塗為 '#'。

**English approach:** Standard flood fill DFS/BFS: replace empty ' ' and start '*' with '#'. Stop on wall characters.

**中文解題思路：** 四方向深度優先搜尋 (DFS) 洪水填充：遇空格與起點置換為 '#'，遇任何邊界或圍牆字元停止擴展。 ==========================================================================


<a id="uva-785_kcontour-coloring"></a>

### UVa 785 — Kooling／多標記輪廓邊界填色 (多源洪水填充)

- 原始碼：[785_kcontour-coloring.c](785_kcontour-coloring.c)
- 難度：UVa Star 1
- 演算法：graph, flood-fill, dfs

**English description:** Flood fill enclosed regions in grid with distinct marker characters matching each start point.

**中文詳細描述：** 在給定輪廓邊界的網格中，由多個相異的標記字元起點各自出發進行洪水填充，直到撞擊邊界為止。

**English approach:** Locate all marker characters (non-space, non-border). For each marker, run DFS flood fill replacing spaces with marker.

**中文解題思路：** 尋找盤面中所有非空格且非邊界牆的標記字元，分別呼叫 DFS 走訪四周可達的空格，將其全部填色為該字元。 ==========================================================================


<a id="uva-787_maximum-sub-sequence-product"></a>

### UVa 787 — Maximum Sub-sequence Product／最大連續子數組乘積

- 原始碼：[787_maximum-sub-sequence-product.c](787_maximum-sub-sequence-product.c)
- 難度：Medium
- 演算法：dp, math

**English description:** Find the maximum product of a non-empty contiguous subsequence in an integer sequence.

**中文詳細描述：** 求一個整數序列中連續非空子序列的最大乘積。

**English approach:** Maintain max_product and min_product ending at current index (as negative numbers flip signs). Track global maximum.

**中文解題思路：** 動態規劃維護以當前元素結尾的最大乘積與最小乘積（負負得正），並持續更新全局最大值。 ==========================================================================


<a id="uva-793_network-connections"></a>

### UVa 793 — Network Connections／電腦網路連線查詢 (並查集 DSU)

- 原始碼：[793_network-connections.c](793_network-connections.c)
- 難度：UVa Star 1
- 演算法：data-structures, dsu

**English description:** Given dynamic bidirectional connections between computers, answer connectivity queries and count successes/failures.

**中文詳細描述：** 動態連通性維護：在電腦兩兩連線的指令流中，查詢指定兩台電腦是否連通，統計成功與失敗的查詢次數 (並查集)。

**English approach:** Disjoint Set Union (DSU) with path compression and rank union. 'c' command unifies sets; 'q' command tests find(u) == find(v).

**中文解題思路：** 標準並查集 (DSU) 結構：路徑壓縮與按秩合併。連線操作執行 union，查詢操作判定 find_root(u) 是否等於 find_root(v)。 ==========================================================================


<a id="uva-796_critical-links"></a>

### UVa 796 — Critical Links／網路關鍵鏈路橋樑偵測

- 原始碼：[796_critical-links.c](796_critical-links.c)
- 難度：UVa Star 2
- 演算法：graph, tarjan, bridge

**English description:** Given an undirected server network, find all critical links (bridges) whose removal disconnects the graph.

**中文詳細描述：** 給定無向伺服器通訊網路，求出所有斷開後會使圖不再連通的關鍵鏈路 (橋樑，Bridges)。

**English approach:** Tarjan's bridge-finding algorithm using DFS discovery times (tin) and lowest reachable times (low). An edge (u, v) is a bridge if low[v] > tin[u].

**中文解題思路：** 使用 Tarjan DFS 走訪演算法：維護發現時間 tin 與回溯最低時間 low，若 low[v] > tin[u] 則無向邊 (u, v) 為橋樑。 ==========================================================================
