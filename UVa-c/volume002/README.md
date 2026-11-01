# UVa Volume 002

本卷收錄 30 份 C 解答，涵蓋 30 個 UVa 題號，以下依題號排序。

<a id="uva-200_rare-order"></a>

### UVa 200 — Rare Order／古文字母表順序還原 (拓撲排序)

- 原始碼：[200_rare-order.c](200_rare-order.c)
- 難度：UVa Star 1
- 演算法：graph, topological-sort, string

**English description:** Given a sorted list of words in an alien alphabet, reconstruct the alphabetical order of the letters.

**中文詳細描述：** 給定依照外星字典序排列的單字列表，還原其字母表各字元的絕對前後順序 (拓撲排序)。

**English approach:** Compare adjacent words to find first differing character (u -> v directed edge). Run topological sort / DFS on DAG.

**中文解題思路：** 兩兩比對相鄰單字的第一個相異字元建立有向圖邊 u -> v，計算入度以 Kahn 演算法或 DFS 完成拓撲排序。 ==========================================================================


<a id="uva-201_squares"></a>

### UVa 201 — Squares／正方形計數 (網格點連線幾何)

- 原始碼：[201_squares.c](201_squares.c)
- 難度：UVa Star 2
- 演算法：geometry, simulation, grid

**English description:** Given horizontal and vertical segments between n x n points, count how many squares of each size k exist.

**中文詳細描述：** 在 n x n 的點陣圖中給定水平與垂直連接線段，統計所有邊長為 k 的封閉正方形總數。

**English approach:** Precompute right and down continuous segment lengths from each point. Check 4 corners for each size k.

**中文解題思路：** 預先計算每個點向右與向下的連續邊長長度。枚舉左上角點 (r, c) 與邊長 k，若四邊皆存在長度至少為 k 則計數 +1。 ==========================================================================


<a id="uva-202_repeating-decimals"></a>

### UVa 202 — Repeating Decimals／循環小數與循環節長度

- 原始碼：[202_repeating-decimals.c](202_repeating-decimals.c)
- 難度：UVa Star 2
- 演算法：math, simulation, cycle-detection

**English description:** Given fraction a/b, find its decimal representation, mark repeating cycle with brackets, and output cycle length.

**中文詳細描述：** 給定分數 a/b，計算其十進位小數表示法，以括號標註循環節並輸出循環節長度。

**English approach:** Long division simulation. Store remainder positions in an array. When a remainder repeats, cycle starts there.

**中文解題思路：** 模擬長除法除算過程，以陣列記錄每個餘數第一次出現的商數位元位置，餘數重複出現處即為循環節起始。 ==========================================================================


<a id="uva-208_firetruck"></a>

### UVa 208 — Firetruck／消防車出動路徑 (DFS 回溯與連通性剪枝)

- 原始碼：[208_firetruck.c](208_firetruck.c)
- 難度：UVa Star 2
- 演算法：graph, dfs, backtracking, pruning

**English description:** Find all simple paths from fire station 1 to destination k in ascending order.

**中文詳細描述：** 尋找從 1 號消防站出發抵達火災地點 k 的所有相異簡單路徑，並按頂點字典序由小到大輸出。

**English approach:** Pre-check reachability from destination using BFS/DSU. DFS with backtracking in sorted vertex order.

**中文解題思路：** 先以 BFS/並查集反向檢查目的地連通性進行剪枝，再以 DFS 按頂點編號由小到大搜尋輸出路徑。 ==========================================================================


<a id="uva-213_message-decoding"></a>

### UVa 213 — Message Decoding／二進位編碼解碼

- 原始碼：[213_message-decoding.c](213_message-decoding.c)
- 難度：Medium
- 演算法：string, bit-manipulation, decoding

**English description:** Decode a binary message where headers define characters corresponding to binary codes of increasing length (0, 1; 00, 01, 10; etc.).

**中文詳細描述：** 解碼二進位訊息：首行標頭依長度對應二進位碼（長度 1: 0；長度 2: 00, 01, 10；長度 3: 000..110，全 1 為長度終止符）。

**English approach:** Read 3-bit length prefix L. If L == 0, terminate. Otherwise read L-bit segments until segment of all 1s. Map to header index.

**中文解題思路：** 讀取 3 位長度 L，若 L=0 則結束；否則讀取 L 位二進位碼直至全 1 結束碼，依字典序映射回標頭對應字元。 ==========================================================================


<a id="uva-216_getting-in-line"></a>

### UVa 216 — Getting in Line／電腦網路拉線總長最小化 (TSP 全排列)

- 原始碼：[216_getting-in-line.c](216_getting-in-line.c)
- 難度：UVa Star 1
- 演算法：graph, tsp, geometry, brute-force

**English description:** Given up to 8 computer coordinates, find linear cable path visiting each computer once with minimum total length.

**中文詳細描述：** 給定最多 8 台電腦的座標，求連接所有電腦的一條直線路徑使總網路線長度最小 (每段加 16 厘米緩衝)。

**English approach:** Since n <= 8, enumerate all 8! = 40320 permutations. Compute total Euclidean distance + 16 * (n - 1) and find minimum.

**中文解題思路：** 因點數 n <= 8，直接枚舉全排列計算法求最小歐幾里得距離總和，每段連接線額外增加 16 單位。 ==========================================================================


<a id="uva-218_moth_eradication"></a>

### UVa 218 — Moth Eradication／飛蛾撲滅計畫 (凸包周長)

- 原始碼：[218_moth_eradication.c](218_moth_eradication.c)
- 難度：Medium
- 演算法：geometry, convex-hull

**English description:** Find the minimum perimeter convex fence that encloses all given trap coordinates.

**中文詳細描述：** 求包圍所有陷阱坐標的最小周長凸多邊形圍欄（凸包）的頂點序列與周長。

**English approach:** Compute 2D convex hull using Andrew's monotone chain algorithm and sum distances between adjacent vertices.

**中文解題思路：** 使用 Andrew 單調鏈演算法計算 2D 點集的凸包，並累加相鄰頂點間距離求周長。 ==========================================================================


<a id="uva-227_puzzle"></a>

### UVa 227 — Puzzle／滑動拼圖操作模擬

- 原始碼：[227_puzzle.c](227_puzzle.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Simulate a 5x5 sliding letter puzzle: an empty space moves Above (A), Below (B), Left (L), or Right (R). Output final grid or illegal move flag.

**中文詳細描述：** 模擬 5x5 字母滑動拼圖：空格可向指定方向滑動 (A=上, B=下, L=左, R=右)。輸出移動後的最終盤面，或在越界時標記此拼圖無合法設定。

**English approach:** Track empty cell position (r, c). For each command, check boundary constraints and swap empty tile with adjacent tile.

**中文解題思路：** 追蹤空白格位置 (r, c)，遇到 A/B/L/R 指令時檢驗是否越界；若合法則與相鄰格子互換字元，若越界則標記非法狀態。 ==========================================================================


<a id="uva-230_borrowers"></a>

### UVa 230 — Borrowers／借書還書管理系統

- 原始碼：[230_borrowers.c](230_borrowers.c)
- 難度：Medium
- 演算法：simulation, sorting, data-structures

**English description:** Simulate library book borrowing, returning, and shelf reorganization where returned books are put back in sorted order.

**中文詳細描述：** 模擬圖書館借書、還書與上架系統，歸還的書籍依照作者及書名字典序插入書架並指示擺放位置。

**English approach:** Sort all books initially. Track book states (on shelf, borrowed, returned). On SHELVE, insert returned books in order relative to books currently on shelf.

**中文解題思路：** 將書籍按作者升序（同作者按書名升序）排序。維護借閱與歸還狀態，執行 SHELVE 時依照原排序插回書架並打印指引。 ==========================================================================


<a id="uva-231_testing-the-catcher"></a>

### UVa 231 — Testing the CATCHER／攔截飛彈 (最長不遞增子序列 LDS)

- 原始碼：[231_testing-the-catcher.c](231_testing-the-catcher.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, lis, greedy

**English description:** Given sequence of missile heights, find maximum number of missiles that can be intercepted (non-increasing heights).

**中文詳細描述：** 給定一組飛彈攔截高度序列，求飛彈攔截系統最多能攔截的飛彈數量 (最長不遞增子序列 LDS)。

**English approach:** O(N log N) or O(N^2) Longest Non-Increasing Subsequence DP.

**中文解題思路：** 標準動態規劃或貪婪二分搜尋求最長不上升子序列 (LDS)。 ==========================================================================


<a id="uva-232_crossword-answers"></a>

### UVa 232 — Crossword Answers／填字遊戲題號編號與單詞提取

- 原始碼：[232_crossword-answers.c](232_crossword-answers.c)
- 難度：UVa Star 1
- 演算法：string, 2d-grid

**English description:** Given an r x c crossword grid with black cells '*', assign clue numbers to cells that start across/down words and print all words.

**中文詳細描述：** 在包含黑格 '*' 的 r x c 填字遊戲網格中，為所有作為橫向或縱向單詞開頭的格子編定題號並依序提取單詞。

**English approach:** Number a cell if it is not '*' and (left is '*' or edge, OR above is '*' or edge). Collect horizontal and vertical words.

**中文解題思路：** 非黑格且其上方或左方為黑格/邊界之格子依序給予流水號題號，分別橫向與縱向掃描輸出單詞。 ==========================================================================


<a id="uva-245_uncompress"></a>

### UVa 245 — Uncompress／前移解壓縮 (Move-To-Front 解碼)

- 原始碼：[245_uncompress.c](245_uncompress.c)
- 難度：UVa Star 2
- 演算法：string, simulation, linked-list

**English description:** Decode text compressed with Move-To-Front word encoding: numbers represent 1-based index from list front.

**中文詳細描述：** 解碼以 Move-To-Front 演算法壓縮的文字：數字代表單詞清單從頭數來的 1-based 位置，取出後將該詞移至清單首端。

**English approach:** Simulate doubly linked list or dynamic array of strings. On number, fetch word at index and move to front; on word, push to front.

**中文解題思路：** 以串列或陣列維護最近使用過的單詞清單。讀入數字時取出對應位置單詞並前移至頭部；讀入新詞時直接插入頭部。 ==========================================================================


<a id="uva-247_calling-circles"></a>

### UVa 247 — Calling Circles／電話通話社交圈強連通分量

- 原始碼：[247_calling-circles.c](247_calling-circles.c)
- 難度：UVa Star 2
- 演算法：graph, scc, tarjan

**English description:** Given directed phone call logs between individuals, find all calling circles (strongly connected components where everyone can call everyone).

**中文詳細描述：** 給定電話通話紀錄形成的有向圖，找出所有可互相輾轉通話的「社交通話圈」(即強連通分量 SCC)。

**English approach:** Warshall's transitive closure or Tarjan's SCC algorithm. Two nodes u, v belong to the same circle if reach[u][v] and reach[v][u].

**中文解題思路：** 利用 Floyd-Warshall 求全源傳遞閉包，若節點 u 與 v 雙向可達 (reach[u][v] && reach[v][u]) 則歸入同一個通話圈。 ==========================================================================


<a id="uva-253_cube-painting"></a>

### UVa 253 — Cube painting／立方體六面著色旋轉同構判定

- 原始碼：[253_cube-painting.c](253_cube-painting.c)
- 難度：UVa Star 1
- 演算法：simulation, geometry, brute-force

**English description:** Determine if two painted cubes can be made identical through 3D rotations.

**中文詳細描述：** 判定兩個塗有顏色的正方體能否透過空間 24 種旋轉達到六面顏色完全相同。

**English approach:** Enumerate 24 valid rotations (6 choices for top face, 4 rotations around vertical axis) and compare strings.

**中文解題思路：** 枚舉立方體的 24 種空間旋轉姿態 (6 種頂面選擇，每種頂面搭配 4 種側面旋轉)，逐一比對面顏色字串。 ==========================================================================


<a id="uva-255_correct-move"></a>

### UVa 255 — Correct Move／西洋棋國王與皇后移動判定

- 原始碼：[255_correct-move.c](255_correct-move.c)
- 難度：UVa Star 2
- 演算法：simulation, chess, game-theory

**English description:** Given positions of King and Queen on 8x8 chessboard, validate queen move and determine resulting state.

**中文詳細描述：** 給定 8x8 棋盤上國王與皇后的位置，判定皇后移動是否合法，並判定後續是繼續、阻礙移動還是走投無路。

**English approach:** Step-by-step chess logic: check valid orthogonal move not jumping over king, not adjacent to king, etc.

**中文解題思路：** 依題目規範逐步驗證：皇后是否同行同列、是否越過國王、是否落於國王相鄰格，以及國王是否無合法步可走。 ==========================================================================


<a id="uva-256_quirksome-squares"></a>

### UVa 256 — Quirksome Squares／古怪平方數

- 原始碼：[256_quirksome-squares.c](256_quirksome-squares.c)
- 演算法：枚舉、平方數性質（brute force, math）

**English description:** For each requested even width `d`, list every `d`-digit, zero-padded number that can be split into two equal-width halves such that the square of the sum of those halves equals the original number. Preserve leading zeroes in the output.

**中文詳細描述：** 每筆輸入一個偶數位數 `d`，把候選數以固定 `d` 位（可含前導 0）分成等長左右兩半。若「左半值＋右半值」的平方恰好等於原數，就依數值遞增輸出。實作枚舉半部和並驗證平方拆分，輸出時補足固定寬度。

<a id="uva-259_software-allocation"></a>

### UVa 259 — Software Allocation／軟體安裝分配 (二分圖最大匹配/最大流)

- 原始碼：[259_software-allocation.c](259_software-allocation.c)
- 難度：Hard
- 演算法：network-flow, max-bipartite-matching

**English description:** Allocate applications requiring specific numbers of users to 10 computer terminals (0-9) according to compatibility.

**中文詳細描述：** 將各應用程式分配給 10 台電腦終端機 (0~9) 運行，每台終端機只能運行一個程式，求完全分配方案。

**English approach:** Bipartite matching between application instances and computers. Total applications must equal total matches (max flow = sum of requirements).

**中文解題思路：** 應用程式實例與 10 台電腦之間的二分圖最大匹配（或最大流），檢驗最大流是否等於所有應用程式需求總數。 ==========================================================================


<a id="uva-260_il-gioco-dell-x"></a>

### UVa 260 — Il Gioco dell'X／六角棋連通勝利判定 (Hex Game BFS)

- 原始碼：[260_il-gioco-dell-x.c](260_il-gioco-dell-x.c)
- 難度：UVa Star 1
- 演算法：graph, bfs, flood-fill

**English description:** Determine if Black wins (connecting top to bottom) or White wins (connecting left to right) on n x n Hex board.

**中文詳細描述：** 在 n x n 六角網格棋盤中，判定是黑棋連通頂部與底部獲勝，還是白棋連通左側與右側獲勝。

**English approach:** Flood fill BFS from all top-row black stones. If any path reaches bottom row, Black wins; otherwise White wins.

**中文解題思路：** 對第一列的所有黑棋進行 6 方向廣度優先搜尋 (BFS)，若能抵達最後一列則黑棋獲勝，否則白棋獲勝。 ==========================================================================


<a id="uva-263_number-chains"></a>

### UVa 263 — Number Chains／數字鏈 (卡布列克過程循環檢測)

- 原始碼：[263_number-chains.c](263_number-chains.c)
- 難度：UVa Star 1
- 演算法：math, simulation, sorting

**English description:** Generate chain: sort digits descending minus ascending to get next number. Stop when a number repeats.

**中文詳細描述：** 數字鏈產生規則：將數字的位數由大到小排序減去由小到大排序得到下一個數。遇到重複數字即停止並求鏈長。

**English approach:** Sort digits into descending and ascending numbers, subtract, and record seen numbers in hash or array to detect cycle.

**中文解題思路：** 利用字串將位數排序轉換為遞減與遞增整數相減，以雜湊或陣列記錄已出現的數值以檢測循環。 ==========================================================================


<a id="uva-264_count-on-cantor"></a>

### UVa 264 — Count on Cantor／康托爾數列

- 原始碼：[264_count-on-cantor.c](264_count-on-cantor.c)
- 演算法：三角數定位、數學（math, diagonal enumeration）

**English description:** Positive fractions are enumerated along alternating diagonals of the numerator-denominator grid. Given a one-based term number `N`, locate its diagonal using triangular numbers, account for the zigzag direction, and print the fraction at that position.

**中文詳細描述：** 康托爾數列沿分子、分母網格的斜對角線以交錯方向排列正分數。輸入第 `N` 項的編號後，以三角數找出它所在的對角線及線內位移，再依該層奇偶決定方向，輸出 `TERM N IS 分子/分母`。

<a id="uva-270_lining-up"></a>

### UVa 270 — Lining Up／最多共線點數 (幾何斜率枚舉)

- 原始碼：[270_lining-up.c](270_lining-up.c)
- 難度：UVa Star 2
- 演算法：geometry, math, brute-force

**English description:** Given up to 700 2D points, find maximum number of points lying on a single straight line.

**中文詳細描述：** 給定平面上最多 700 個點，求能位在同一條直線上的最大點數。

**English approach:** For each point i, compute slopes to all other points j, sort slopes and find maximum frequency.

**中文解題思路：** 對每個基準點 i 計算與其他點的斜率 (以化簡分數表示)，排序斜率統計出現頻率的最大值。 ==========================================================================


<a id="uva-271_simply-syntax"></a>

### UVa 271 — Simply Syntax／簡單語法檢驗

- 原始碼：[271_simply-syntax.c](271_simply-syntax.c)
- 演算法：前綴文法解析、堆疊計數（parsing, stack）

**English description:** Determine whether each input string is exactly one valid sentence in a prefix grammar: `p` through `z` are atomic sentences, `N` takes one sentence, and each of `C`, `D`, `E`, and `I` takes two sentences. Print `YES` only when the entire string forms one sentence; otherwise print `NO`.

**中文詳細描述：** 每行是一個前綴表示式；小寫 `p` 到 `z` 本身是合法句子，`N` 後須接一個合法句子，而 `C`、`D`、`E`、`I` 後各須接兩個合法句子。由右向左統計目前可組成的完整句子，只有整行恰好合成一個句子時輸出 `YES`，否則輸出 `NO`。

<a id="uva-272_tex-quotes"></a>

### UVa 272 — TeX Quotes／TeX 雙引號替換

- 原始碼：[272_tex-quotes.c](272_tex-quotes.c)
- 演算法：字元流模擬（string, simulation）

**English description:** Read an arbitrary text stream and replace ordinary double quote characters in alternating order: an opening quote becomes two backticks and a closing quote becomes two apostrophes. Copy every other character, including line breaks, unchanged.

**中文詳細描述：** 輸入是可跨多行的文字，逐字元掃描其中的一般雙引號 `"`。每對引號的第一個改成 TeX 左引號的兩個反引號，第二個改成兩個單引號，之後持續交替；其餘字元與換行完全照原樣輸出。

<a id="uva-275_expanding-fractions"></a>

### UVa 275 — Expanding Fractions／分數循環小數展開與週期計算

- 原始碼：[275_expanding-fractions.c](275_expanding-fractions.c)
- 難度：UVa Star 2
- 演算法：math, simulation

**English description:** Given numerator and denominator of a fraction in (0, 1), compute its decimal expansion. Determine whether it terminates or repeats, and if it repeats, find the length of the recurring cycle.

**中文詳細描述：** 給定介於 (0, 1) 的真分數分子與分母，計算其十進位小數展開。 判斷該小數為有限小數或循環小數；若為循環小數，求其循環節長度。

**English approach:** Simulate long division. Maintain an array recording the step at which each remainder was first seen. If remainder becomes 0, expansion terminates. If a remainder reappears, cycle length is current step minus previous step.

**中文解題思路：** 長除法模擬：以陣列記錄每個餘數首次出現的小數位數。 若餘數變為 0 則為有限小數；若同一餘數再次出現，則循環節長度為當前位數減去該餘數上次出現之位數。 ==========================================================================


<a id="uva-278_chess"></a>

### UVa 278 — Chess／西洋棋棋盤最大獨立放置數

- 原始碼：[278_chess.c](278_chess.c)
- 難度：UVa Star 1
- 演算法：math, chess, greedy

**English description:** Find maximum number of non-attacking pieces of given type (Rook, Knight, Queen, King) on m x n board.

**中文詳細描述：** 求在 m x n 棋盤上互不攻擊的城堡、騎士、皇后或國王的最大擺放數量。

**English approach:** Math formulas: Rook: min(m, n); Knight: (m*n + 1)/2; King: ((m+1)/2) * ((n+1)/2); Queen: min(m, n).

**中文解題思路：** 數學公式：城堡為 min(m, n)；騎士為 (m*n + 1)/2；國王為 ((m+1)/2) * ((n+1)/2)；皇后為 min(m, n)。 ==========================================================================


<a id="uva-280_vertex"></a>

### UVa 280 — Vertex／頂點可達性 (有向圖 DFS 走訪)

- 原始碼：[280_vertex.c](280_vertex.c)
- 難度：UVa Star 1
- 演算法：graph, dfs, bfs, reachability

**English description:** Given directed graph, find all vertices not reachable from a given starting vertex via length >= 1 paths.

**中文詳細描述：** 在有向圖中，求從指定頂點出發無法透過長度大於等於 1 的路徑抵達的所有頂點個數與列表。

**English approach:** Standard DFS/BFS starting from neighbors of u (path length must be >= 1). Count unvisited nodes.

**中文解題思路：** 從起點的鄰接節點出發進行 DFS 走訪 (長度必須至少為 1)，統計未被標記造訪的節點總數。 ==========================================================================


<a id="uva-291_the-house-of-santa-claus"></a>

### UVa 291 — The House Of Santa Claus／聖誕老人之屋 (歐拉一筆畫全路徑枚舉)

- 原始碼：[291_the-house-of-santa-claus.c](291_the-house-of-santa-claus.c)
- 難度：UVa Star 1
- 演算法：graph, eulerian-path, backtracking

**English description:** Print all 1-stroke drawing paths of Santa Claus House starting from vertex 1 traversing all 8 edges in numerical order.

**中文詳細描述：** 由頂點 1 出發，以一筆畫走遍聖誕老人之屋的 8 條邊，輸出所有合法的歐拉路徑編號。

**English approach:** Backtracking DFS with edge-visited marks. 8 steps complete a valid Eulerian trail.

**中文解題思路：** 回溯搜尋：以陣列標記無向邊是否已走過，遞迴深度達到 8 步即為合法路徑，由小到大枚舉頂點自動保證字典序。 ==========================================================================


<a id="uva-294_divisors"></a>

### UVa 294 — Divisors／區間最多正因數之數

- 原始碼：[294_divisors.c](294_divisors.c)
- 難度：UVa Star 1
- 演算法：math, number-theory, prime-factorization

**English description:** Find the integer between L and U with the maximum number of divisors.

**中文詳細描述：** 找出區間 [L, U] 之中正因數數量最多的整數及其因數總數。

**English approach:** Precompute primes up to sqrt(10^9) = 31622. Prime factorization gives tau(n) = prod(e_i + 1).

**中文解題思路：** 質數篩預處理至 31622。對區間內整數質因數分解，利用公式 (e1 + 1)(e2 + 1)... 計算正因數個數求最大值。 ==========================================================================


<a id="uva-297_quadtrees"></a>

### UVa 297 — Quadtrees／四元樹像素聯集面積

- 原始碼：[297_quadtrees.c](297_quadtrees.c)
- 難度：UVa Star 2
- 演算法：tree, recursion, geometry

**English description:** Merge two 32x32 image quadtrees (p, e, f) and calculate the total number of black pixels.

**中文詳細描述：** 給定兩棵 32x32 點陣圖的四元樹前序編碼，合併兩樹並計算聯集中黑色像素點 (f) 的總數量。

**English approach:** Recursive quadtree parsing into 32x32 array, marking black pixels. Sum black pixels at the end.

**中文解題思路：** 前序遍歷遞迴填色：若為 'f' 則將對應區域填滿黑像素，若為 'p' 則遞迴劃分為 4 個子象限。合併計算黑像素個數。 ==========================================================================


<a id="uva-299_train-swapping"></a>

### UVa 299 — Train Swapping／火車車廂調度

- 原始碼：[299_train-swapping.c](299_train-swapping.c)
- 演算法：逆序對、氣泡排序（sorting, inversion count）

**English description:** Each test case gives the order of train cars. Only adjacent cars may be swapped, so the minimum number of swaps needed to put them in increasing order equals the number of inversions. Output that count in the required sentence for every case.

**中文詳細描述：** 每筆測試給出車廂數量與目前排列，調度時一次只能交換相鄰車廂，目標是排成遞增順序。以氣泡排序實際計數交換，等價於統計原排列的逆序對數；每組輸出 `Optimal train swapping takes S swaps.`。
