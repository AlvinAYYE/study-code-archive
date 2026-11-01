# UVa Volume 004

本卷收錄 65 份 C 解答，涵蓋 58 個 UVa 題號，以下依題號排序。

<a id="uva-400_unix-ls"></a>

### UVa 400 — Unix ls／Unix 檔案列表多欄排版

- 原始碼：[400_unix-ls.c](400_unix-ls.c)
- 難度：UVa Star 2
- 演算法：string, sorting, formatting

**English description:** Format list of filenames into column-major order across 60-character terminal width like Unix ls command.

**中文詳細描述：** 模擬 Unix 'ls' 指令：將檔名依字典序排序，在 60 字元寬度限制下計算最多欄位數並以由上而下、由左至右排版。

**English approach:** Sort filenames alphabetically. Find max length L. Number of columns C = 1 + (60 - L) / (L + 2). Rows R = ceil(N / C).

**中文解題思路：** 字串字典序排序，找出最長檔名長度 L。計算最大欄數 C = 1 + (60 - L) / (L + 2)，列數 R = (N + C - 1) / C 依直行印出。 ==========================================================================


<a id="uva-401_palindromes"></a>

### UVa 401 — Palindromes／回文與鏡像字串判定

- 原始碼：[401_palindromes.c](401_palindromes.c)
- 演算法：字串比對、鏡像映射（string, simulation）

**English description:** For every input string, independently test whether it reads the same backward and whether reversing it while replacing each character by its defined mirror yields the original. Print one of four classifications: regular palindrome, mirrored string, mirrored palindrome, or neither.

**中文詳細描述：** 每行輸入一個只含題目允許字元的字串。第一項檢查左右反讀是否相同，第二項利用字元鏡像對照表，判斷把字串反轉並逐字鏡射後是否仍相同。依兩項布林結果輸出普通回文、鏡像字串、鏡像回文或兩者皆非的指定句子。

<a id="uva-406_prime-cuts"></a>

### UVa 406 — Prime Cuts／質數序列居中切割截取

- 原始碼：[406_prime-cuts.c](406_prime-cuts.c)
- 難度：UVa Star 1
- 演算法：math, prime-sieve

**English description:** List all primes <= N (counting 1 as a prime). Output 2C (or 2C-1) primes centered in the list.

**中文詳細描述：** 列出小於等於 N 的質數 (本題將 1 視為質數)。若質數總數為偶數則從正中央截取 2C 個，為奇數則截取 2C-1 個。

**English approach:** Sieve of Eratosthenes up to 1000. Find center indices and output slice.

**中文解題思路：** 埃拉托斯特尼質數篩法預處理 (含 1)。若總數小於截取長度則輸出全部，否則計算中央起訖索引印出區間。 ==========================================================================


<a id="uva-408_uniform-generator"></a>

### UVa 408 — Uniform Generator／均勻隨機產生器 (互質判定 GCD)

- 原始碼：[408_uniform-generator.c](408_uniform-generator.c)
- 難度：UVa Star 1
- 演算法：math, number-theory, gcd

**English description:** Determine if step size STEP and modulus MOD generate all integers 0..MOD-1 via seed = (seed + STEP) % MOD.

**中文詳細描述：** 判定線性同餘產生器 step 與 mod 能否生成 0 到 mod-1 的所有整數 (即 gcd(step, mod) == 1 則為 Good Choice)。

**English approach:** By number theory, the sequence generates full period iff gcd(step, mod) == 1.

**中文解題思路：** 由數論同餘理論可知，循環產生完整週期的充分必要條件為 gcd(step, mod) == 1。 ==========================================================================


<a id="uva-409_excuses-excuses"></a>

### UVa 409 — Excuses Excuses／最爛藉口關鍵字子字串統計比對

- 原始碼：[409_excuses-excuses.c](409_excuses-excuses.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Given K keywords and E excuse sentences, count keyword occurrences in each excuse and print excuses with the maximum frequency.

**中文詳細描述：** 給定 K 個關鍵字與 E 句藉口，統計每句藉口中關鍵字出現之總次數，輸出包含最多關鍵字的最爛藉口句子。

**English approach:** Tokenize excuse sentences into lowercase alphabetic words. Count matches against the keyword list and output excuses matching max count.

**中文解題思路：** 將藉口句子按非字母字元切割為單詞並轉小寫，統計包含關鍵字之個數，印出得分最高者。 ==========================================================================


<a id="uva-410_station-balance"></a>

### UVa 410 — Station Balance／太空站重力配平

- 原始碼：[410_station-balance.c](410_station-balance.c)
- 難度：Medium
- 演算法：greedy, sorting

**English description:** Place S specimens into C centrifuge chambers (at most 2 specimens per chamber) to minimize imbalance relative to average weight.

**中文詳細描述：** 將 S 個樣本放入 C 個離心機室（每室最多 2 個樣本），求使各室重量與平均值之差絕對值總和最小的配平方案。

**English approach:** Pad array with zeros to 2C elements. Sort ascending. Pair element i with element 2C - 1 - i. Compute imbalance sum.

**中文解題思路：** 補 0 至 2C 個元素後升序排序，第 i 個與第 2C-1-i 個配對放入同一室，貪心法保證總不平衡度最小。 ==========================================================================


<a id="uva-412_pi"></a>

### UVa 412 — Pi／由互質機率估算圓周率 Pi

- 原始碼：[412_pi.c](412_pi.c)
- 難度：UVa Star 1
- 演算法：math, number-theory, probability

**English description:** Given a set of integers, estimate pi using probability of randomly chosen pair being coprime (P = 6 / pi^2).

**中文詳細描述：** 給定一組整數，計算任選兩數互質的機率 P，並利用蒙地卡羅數論公式 P = 6 / pi^2 估算圓周率 pi 的近似值。

**English approach:** Count all pairs (i, j) with gcd(a[i], a[j]) == 1. Then pi approx = sqrt(6 * total_pairs / coprime_pairs).

**中文解題思路：** 雙重迴圈枚舉所有數對計算最大公因數，統計互質數對數量，帶入公式 sqrt(6.0 * total / coprime) 求解。 ==========================================================================


<a id="uva-413_up_and_down_sequences"></a>

### UVa 413 — Up and Down Sequences／上升與下降序列平均長度

- 原始碼：[413_up_and_down_sequences.c](413_up_and_down_sequences.c)
- 難度：Easy
- 演算法：simulation, array

**English description:** Calculate the average length of consecutive strictly upward and downward runs in a sequence.

**中文詳細描述：** 統計整數序列中上升序列與下降序列的平均長度（平坦段延續先前的趨勢）。

**English approach:** Scan adjacent differences. If equal, inherit current direction. Count transitions to tally runs and lengths.

**中文解題思路：** 遍歷相鄰差值，相等時繼承先前走勢，在方向改變時統計上升與下降的區段數與總長度，計算平均值。 ==========================================================================


<a id="uva-414_machined-surfaces"></a>

### UVa 414 — Machined Surfaces／精密機械加工表面間隙計數

- 原始碼：[414_machined-surfaces.c](414_machined-surfaces.c)
- 難度：UVa Star 1
- 演算法：simulation, string

**English description:** Count remaining empty spaces when two 25-character wide machined blocks slide together until they touch.

**中文詳細描述：** 兩塊帶有凹凸齒槽 (字元 'X') 的機械表面向中間滑動直到最先接觸，計算接合後剩餘的空隙 (空白字元) 總數。

**English approach:** Count spaces in each row. The row with minimum spaces will touch first. Sum (spaces[row] - min_spaces).

**中文解題思路：** 統計每列的空格數。兩表面合攏時由空格最少的列率先頂住，總剩餘間隙即每列空格數減去全域最小空格數的總和。 ==========================================================================


<a id="uva-417_word-index"></a>

### UVa 417 — Word Index／字母嚴格遞增單字編號索引

- 原始碼：[417_word-index.c](417_word-index.c)
- 難度：UVa Star 2
- 演算法：combinatorics, math, bfs

**English description:** Assign 1-based index to all words with strictly increasing letters: a..z (1-26), ab..yz (27-351), etc.

**中文詳細描述：** 對所有字母嚴格遞增的字詞編號 (a..z 為 1..26，ab..yz 接著編號)，求給定合法單詞的唯一索引編號 (不合法回傳 0)。

**English approach:** Combinatorics C(n, k) prefix sum calculation or BFS queue generation up to length 5.

**中文解題思路：** 利用組合數 C(26, k) 統計小於當前長度的單詞數，再以組合數前綴和計算同長度中小於當前單詞的數量。 ==========================================================================


<a id="uva-422_word-search-wonder"></a>

### UVa 422 — Word-Search Wonder／字詞搜尋奇蹟 (8方向單字搜索)

- 原始碼：[422_word-search-wonder.c](422_word-search-wonder.c)
- 難度：Easy
- 演算法：string, grid-search

**English description:** Find starting and ending coordinates of words in an N x N letter grid in any of the 8 straight directions.

**中文詳細描述：** 在 N x N 字母網格中沿 8 個直角或對角線方向搜索單字，求起點與終點坐標。

**English approach:** Check all grid starting points (r, c) and 8 directions (dr, dc). Match word characters in order.

**中文解題思路：** 遍歷每個網格點 (r, c) 作為起點，嘗試 8 個方向逐字匹配，成功則記錄起點與終點坐標。 ==========================================================================


<a id="uva-423_mpi-maelstrom"></a>

### UVa 423 — MPI Maelstrom／MPI 訊息廣播全源最短傳遞時間

- 原始碼：[423_mpi-maelstrom.c](423_mpi-maelstrom.c)
- 難度：UVa Star 2
- 演算法：graph, dijkstra, floyd-warshall

**English description:** Find the minimum time to broadcast a message from processor 1 to all other processors in an MPI network (maximum shortest path).

**中文詳細描述：** 在處理器通訊網路中，求將廣播訊息自 1 號處理器傳送至其餘所有處理器所需的最短時間 (即單源最短路徑中的最大值)。

**English approach:** Run Dijkstra's algorithm from node 1. Answer is max(dist[v]) for all v.

**中文解題思路：** 以 1 號節點為起點執行 Dijkstra 最短路徑演算法，所有節點中距離最大者即為整網廣播完成之最短時間。 ==========================================================================


<a id="uva-424_integer-inquiry"></a>

### UVa 424 — Integer Inquiry／超長大數整數連加

- 原始碼：[424_integer-inquiry.c](424_integer-inquiry.c)
- 難度：UVa Star 1
- 演算法：math, big-integer

**English description:** Sum a sequence of positive integers up to 100 digits each, terminated by '0'.

**中文詳細描述：** 計算一系列長達 100 位數的正整數總和，直到輸入為 '0' 結束 (大數高精度加法)。

**English approach:** Simulate column-addition from least significant digit with carry propagation.

**中文解題思路：** 以整數陣列儲存大數的每一位，由低位到高位逐位相加並處理進位運算。 ==========================================================================


<a id="uva-429_word-transformation"></a>

### UVa 429 — Word Transformation／單字變換最短梯路 BFS

- 原始碼：[429_word-transformation.c](429_word-transformation.c)
- 難度：UVa Star 2
- 演算法：graph, bfs, string

**English description:** Find minimum transformations to change start word to target word, changing one letter at a time through words in the dictionary.

**中文詳細描述：** 在單字庫中每次僅允許改變一個字母，求由起始單字變換至目標單字的最少變換步數 (單字梯 BFS 最短路)。

**English approach:** Construct graph where words of equal length differing by exactly 1 character share an edge. Run BFS from start to target.

**中文解題思路：** 同長度且恰好差一個字母的單字間連邊，自起點單字啟動廣度優先搜尋 (BFS) 求至終點單字之最短步數。 ==========================================================================


<a id="uva-435_block-voting"></a>

### UVa 435 — Block Voting／投票集團權力指數 (班茨哈夫指數)

- 原始碼：[435_block-voting.c](435_block-voting.c)
- 難度：UVa Star 2
- 演算法：math, subset-sum, combinatorics

**English description:** Compute Banzhaf Power Index for each party: number of winning coalitions where party is a critical swing voter.

**中文詳細描述：** 計算各黨派的班茨哈夫權力指數：該黨在所有過半數聯盟中，扣除其票數即變為不過半的關鍵搖擺次數。

**English approach:** Subset sum dynamic programming or brute-force bitmask (P <= 20). Check whether sum without party is in [majority - v, majority - 1].

**中文解題思路：** 因黨派數 P <= 20，可以位元列舉或動態規劃背包求其餘黨派的票數組合，若票數落在 [過半-v, 過半-1] 則為關鍵票。 ==========================================================================


<a id="uva-436_arbitrage-ii"></a>

### UVa 436 — Arbitrage (II)／套匯 II (貨幣乘積正環Floyd-Warshall)

- 原始碼：[436_arbitrage-ii.c](436_arbitrage-ii.c)
- 難度：Medium
- 演算法：graph, floyd-warshall, shortest-path

**English description:** Determine if an arbitrage opportunity exists in a currency exchange market (a sequence of trades that starts and ends at the same currency with net gain > 1).

**中文詳細描述：** 判斷外匯市場中是否存在套匯套利機會（透過一系列貨幣兌換回到原貨幣後價值嚴格大於 1）。

**English approach:** Floyd-Warshall for maximum product: dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]). Arbitrage exists if dist[i][i] > 1.0 for any currency i.

**中文解題思路：** 變形 Floyd-Warshall 求最大匯率連乘積：dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j])，檢查是否存在 dist[i][i] > 1.0。 ==========================================================================


<a id="uva-437_the-tower-of-babylon"></a>

### UVa 437 — The Tower of Babylon／巴比倫塔 (3D 疊積木最長路 DP)

- 原始碼：[437_the-tower-of-babylon.c](437_the-tower-of-babylon.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, dag, lis

**English description:** Given n types of 3D blocks (unlimited supply), stack blocks such that base dimensions strictly decrease. Find max tower height.

**中文詳細描述：** 給定 n 種 3D 長方體積木 (每種無限個)，各積木可任意方向擺放。底面長寬皆須嚴格遞減，求塔的最大高度。

**English approach:** Each block type produces up to 6 distinct base orientations. Sort by base area and compute DAG longest path / LIS DP.

**中文解題思路：** 每種積木枚舉 3 種不同的擺放高度 (或 6 種旋轉)。依底面尺寸排序後，以 LIS 動態規劃轉移求最大總高度。 ==========================================================================


<a id="uva-438_the-circumference-of-the-circle"></a>

### UVa 438 — The Circumference of the Circle／三角形外接圓周長

- 原始碼：[438_the-circumference-of-the-circle.c](438_the-circumference-of-the-circle.c)
- 演算法：平面幾何、海龍公式（geometry, circumcircle）

**English description:** Each case provides the Cartesian coordinates of three non-collinear points. Determine the circumference of the unique circle passing through all three points and print it to two decimal places.

**中文詳細描述：** 每筆輸入三個不共線平面點的座標，三點可形成唯一的外接圓。先由點距求三角形三邊，使用海龍公式求面積，再以 `R = abc/(4A)` 得到半徑並計算 `2πR`；每筆輸出圓周長至小數點後兩位。

<a id="uva-439_knight-moves"></a>

### UVa 439 — Knight Moves／西洋棋騎士最短步數

- 原始碼：[439_knight-moves.c](439_knight-moves.c)
- 演算法：廣度優先搜尋（graph, BFS, shortest path）

**English description:** Given two algebraic square names on a standard 8 × 8 chessboard, find the minimum number of legal knight moves from the first square to the second. Print the original square names and the distance in the required sentence.

**中文詳細描述：** 每筆輸入兩個棋盤位置，例如 `a1` 與 `h8`。把 8 × 8 棋盤視為無權圖，每格可連到騎士八種「日」字走法仍在棋盤內的位置，以 BFS 從起點找最短距離；輸出原起終點與最少移動步數。

<a id="uva-440_eeny-meeny-moo"></a>

### UVa 440 — Eeny Meeny Moo／點名斷電模擬 (特定城市最後淘汰)

- 原始碼：[440_eeny-meeny-moo.c](440_eeny-meeny-moo.c)
- 難度：UVa Star 1
- 演算法：simulation, josephus

**English description:** Find smallest step m such that in Josephus elimination starting at 1, city 2 is the very last one eliminated.

**中文詳細描述：** 求最小間隔 m 使得約瑟夫環從 1 號開始斷電淘汰時，2 號城市恰好是最後一個被斷電的 (存活至最後)。

**English approach:** City 1 is immediately eliminated first. Simulate Josephus on remaining n-1 cities for m = 2, 3, ... until survivor is 2.

**中文解題思路：** 1 號首先出圈，對剩下的 n-1 個城市模擬約瑟夫過程，由 m = 2 開始遞增嘗試，直到最後留下的城市為 2。 ==========================================================================


<a id="uva-441_lotto"></a>

### UVa 441 — Lotto／樂透彩券 6 個數字組合列舉

- 原始碼：[441_lotto.c](441_lotto.c)
- 難度：UVa Star 1
- 演算法：brute-force, combinatorics

**English description:** Given k sorted numbers (k > 6), print all combinations of 6 numbers in lexicographical order.

**中文詳細描述：** 從給定的 k 個排序好的整數中 (6 < k < 13)，依字典序列舉輸出所有 6 個數字的樂透組合 (C(k, 6))。

**English approach:** 6 nested for-loops iterating over strictly increasing indices i < j < k < l < m < n.

**中文解題思路：** 最簡單高效的方式是撰寫 6 層巢狀迴圈枚舉嚴格遞增的下標，直接由小到大輸出每種組合。 ==========================================================================


<a id="uva-442_matrix-chain-multiplication"></a>

### UVa 442 — Matrix Chain Multiplication／矩陣乘法運算次數堆疊計算

- 原始碼：[442_matrix-chain-multiplication.c](442_matrix-chain-multiplication.c)
- 難度：UVa Star 1
- 演算法：stack, parsing, data-structures

**English description:** Given matrix dimensions and parenthesized expression, evaluate total scalar multiplications or output 'error'.

**中文詳細描述：** 給定各矩陣維度與含括號的乘法表達式，以堆疊模擬運算，計算純量乘法總次數；若維度不合則輸出 error。

**English approach:** Use a stack of matrices (rows, cols). On letter, push matrix. On ')', pop two matrices, check dimension match, accumulate cost, push result.

**中文解題思路：** 使用堆疊結構：遇到字母將矩陣壓棧；遇到右括號彈出兩矩陣，檢查內維度是否匹配並累加乘法次數，將結果矩陣壓回堆疊。 ==========================================================================


<a id="uva-443_humble-numbers"></a>

### UVa 443 — Humble Numbers／卑微數 (只含 2, 3, 5, 7 質因數之數)

- 原始碼：[443_humble-numbers.c](443_humble-numbers.c)
- 難度：UVa Star 1
- 演算法：math, dynamic-programming, priority-queue

**English description:** Find n-th humble number (numbers whose only prime factors are 2, 3, 5, 7) for n <= 5842.

**中文詳細描述：** 求第 n 個卑微數 (質因數僅含 2, 3, 5, 7 的整數，第 1 個為 1，n <= 5842)。

**English approach:** Four-pointer dynamic programming: next humble number is min(2*h[p2], 3*h[p3], 5*h[p5], 7*h[p7]). Advance matching pointers.

**中文解題思路：** 四指標動態規劃：維護 p2, p3, p5, p7 指標，下一個卑微數取四者乘積最小值，並將達成最小值的指標前移去重。 ==========================================================================


<a id="uva-444_encoder-and-decoder"></a>

### UVa 444 — Encoder and Decoder／ASCII 數值倒轉編碼與解碼

- 原始碼：[444_encoder-and-decoder.c](444_encoder-and-decoder.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Encode text by converting chars to ASCII numbers and reversing string, or decode reversed ASCII sequence back to text.

**中文詳細描述：** 編碼將字元轉為 ASCII 碼後整串倒轉；解碼將倒轉的數字字串還原為 ASCII 字元 (注意有 2 位數與 3 位數 ASCII 碼)。

**English approach:** If input starts with digit, process numbers in reverse (length 2 or 3). Otherwise convert char to ASCII, reverse digits.

**中文解題思路：** 判斷開頭若為數字則反向切出 2 位數 (65..99) 或 3 位數 (100..122) 轉成字元；若為文字則將各字元 ASCII 倒序輸出。 ==========================================================================


<a id="uva-445_marvelous-mazes"></a>

### UVa 445 — Marvelous Mazes／奇妙的迷宮解碼繪圖

- 原始碼：[445_marvelous-mazes.c](445_marvelous-mazes.c)
- 演算法：游程解碼、字串模擬（string, run-length decoding）

**English description:** Decode a compact maze description. Consecutive digits contribute their values to a repetition count; the following character is printed that many times, with `b` representing a blank. An exclamation mark or an input newline starts a new output line.

**中文詳細描述：** 輸入以數字和字元壓縮表示迷宮。連續數字不是一個多位數，而是把每個數字值相加作為下一個圖形字元的重複次數；`b` 要畫成空白，`!` 與原輸入換行都表示另起一列。逐字解碼後輸出完整迷宮圖案。

<a id="uva-445_marvelous-mazes-pr"></a>

### UVa 445 — Marvelous Mazes／奇妙的迷宮解碼繪圖

- 原始碼：[445_marvelous-mazes-pr.c](445_marvelous-mazes-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, simulation

**English description:** Decode maze format: consecutive digits sum to frequency of next character ('b' is space, '!' is newline).

**中文詳細描述：** 迷宮輸出解碼：連續數字累加為後續字元的重複次數，'b' 代表空格，'!' 代表換行。

**English approach:** Accumulate digit sum, repeat character printing.

**中文解題思路：** 累加連續數字和，遇到非數字字元則重複輸出對應次數。 ==========================================================================


<a id="uva-446_kibbles-bits"></a>

### UVa 446 — Kibbles n Bits n Bits n Bits／十六進位轉十三位元二進位運算

- 原始碼：[446_kibbles-bits.c](446_kibbles-bits.c)
- 難度：UVa Star 1
- 演算法：bit-manipulation, base-conversion, formatting

**English description:** Given hex expression 'A + B' or 'A - B', print 13-bit binary of A, operator, 13-bit binary of B, and decimal result.

**中文詳細描述：** 給定十六進位運算式 (如 '0x1A + 0x2')，格式化輸出 13 位元二進位、運算子與十進位計算結果。

**English approach:** Parse hex with %x. Format integers into 13-bit binary with leading zeros using bitwise checks (1 << bit).

**中文解題思路：** 利用 %x 讀入數值，位元運算由第 12 位元往下檢查 (val & (1 << i)) 輸出 13 位二進位字串並計算加減結果。 ==========================================================================


<a id="uva-450_little-black-book"></a>

### UVa 450 — Little Black Book／黑皮通訊錄名冊解析

- 原始碼：[450_little-black-book.c](450_little-black-book.c)
- 難度：Easy
- 演算法：string, parsing, sorting

**English description:** Parse employee information lines separated by commas grouped by department. Sort alphabetically by last name and print mailing cards.

**中文詳細描述：** 解析按部門分組的員工通訊錄資料（以逗號分隔各欄位），按姓氏 (Last Name) 字典序排序並輸出格式化名冊。

**English approach:** Split fields by commas: Title, First, Last, Address, HomePhone, WorkPhone, CampusBox. Sort records by Last Name, print output format.

**中文解題思路：** 以逗號切割各欄位取得員工資訊並附加所屬部門名稱，按姓氏進行結構體排序後格式化輸出。 ==========================================================================


<a id="uva-454_anagrams"></a>

### UVa 454 — Anagrams／字謎對 (忽略空白排序對齊)

- 原始碼：[454_anagrams.c](454_anagrams.c)
- 難度：Easy
- 演算法：string, sorting, hash

**English description:** Given a list of words or phrases, find all pairs that are anagrams of each other (ignoring spaces).

**中文詳細描述：** 在字詞列表中找出所有互為重組字謎（忽略所有空白符號）的詞對並按字典序輸出。

**English approach:** Extract letters from each phrase, sort letters alphabetically to create signature. Phrases with identical signatures are anagrams.

**中文解題思路：** 濾除空格後將字母排序生成特徵字串，特徵相同的短語即互為重組字謎對。 ==========================================================================


<a id="uva-455_periodic-strings"></a>

### UVa 455 — Periodic Strings／週期字串最小週期

- 原始碼：[455_periodic-strings.c](455_periodic-strings.c)
- 難度：UVa Star 1
- 演算法：string, brute-force, kmp

**English description:** Find length of smallest repeating period substring that forms the entire string.

**中文詳細描述：** 找出能連續重複拼接構成原字串的最小週期子字串長度。

**English approach:** Try period length L from 1 to N. If N % L == 0, check if s[i] == s[i % L] for all i. First valid L is answer.

**中文解題思路：** 由 1 到 N 枚舉週期長度 L。若 N 可被 L 整除，驗證每個字元是否皆滿足 s[i] == s[i % L]，首個合法者即為最小週期。 ==========================================================================


<a id="uva-457_linear-cellular-automata"></a>

### UVa 457 — Linear Cellular Automata／一維細胞自動機模擬

- 原始碼：[457_linear-cellular-automata.c](457_linear-cellular-automata.c)
- 難度：UVa Star 1
- 演算法：simulation, array

**English description:** Simulate 1D cellular automaton across 40 dishes for 50 days based on DNA rule mapping neighbor sum (0-3) to next state.

**中文詳細描述：** 模擬 40 個培養皿在 50 天內的細胞密度繁衍變化：下一代狀態由相鄰三個培養皿當前密度和透過 DNA 規則映射更新。

**English approach:** Array simulation: next[i] = DNA[cur[i-1] + cur[i] + cur[i+1]]. Render densities (0: ' ', 1: '.', 2: 'x', 3: 'W').

**中文解題思路：** 維護長度 42 的陣列 (含邊界)，每天依照 sum = cur[i-1] + cur[i] + cur[i+1] 查表 DNA[sum] 更新並轉成指定字元印出。 ==========================================================================


<a id="uva-458_the-decoder"></a>

### UVa 458 — The Decoder／簡易解碼器

- 原始碼：[458_the-decoder.c](458_the-decoder.c)
- 演算法：逐字元轉換（string, basic I/O）

**English description:** Read the encoded text until end of file. Decode each non-newline character by subtracting 7 from its ASCII value, while preserving line boundaries, and print the resulting plaintext.

**中文詳細描述：** 輸入是持續到檔案結尾的加密文字，每個可見字元的編碼值都比原字元大 7。程式逐字讀取，將非換行字元的 ASCII 值減 7 後輸出，換行原樣保留，從而還原完整明文。

<a id="uva-458_the-decoder-pr"></a>

### UVa 458 — The Decoder／簡易解碼器

- 原始碼：[458_the-decoder-pr.c](458_the-decoder-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, basic-io

**English description:** Decode by subtracting 7 from ASCII value of each character.

**中文詳細描述：** 簡易字元解碼：將每個字元的 ASCII 碼減去 7。

**English approach:** putchar(c - 7) for all non-newline characters.

**中文解題思路：** 逐字元讀入輸出 c - 7。 ==========================================================================


<a id="uva-459_graph-connectivity"></a>

### UVa 459 — Graph Connectivity／無向圖連通分量計數

- 原始碼：[459_graph-connectivity.c](459_graph-connectivity.c)
- 難度：UVa Star 2
- 演算法：graph, dsu, dfs

**English description:** Given maximal node label up to 'Z' and list of undirected edges, find the number of connected components in the graph.

**中文詳細描述：** 給定圖中最大節點標籤 (至多為 'Z') 與無向邊列表，計算圖中連通分量的個數。

**English approach:** Disjoint-Set Union (DSU): initialize N disjoint sets, union endpoints for each edge, count distinct root representatives.

**中文解題思路：** 使用並查集 (DSU) 維護連通關係：將每條邊兩端點合併，最後統計相異集合代表元之總數。 ==========================================================================


<a id="uva-460_overlapping-rectangles"></a>

### UVa 460 — Overlapping Rectangles／重疊矩形面積計算

- 原始碼：[460_overlapping-rectangles.c](460_overlapping-rectangles.c)
- 難度：Easy
- 演算法：geometry

**English description:** Given two axis-aligned rectangles, determine if their intersection is a valid rectangle with positive area, and find its coordinates.

**中文詳細描述：** 給定兩個與坐標軸平行的矩形，判斷其交集是否為具有正面積的合法矩形，並求其左下與右上座標。

**English approach:** Intersection: x_ll = max(x1_ll, x2_ll), y_ll = max(y1_ll, y2_ll), x_ur = min(x1_ur, x2_ur), y_ur = min(y1_ur, y2_ur). Area positive if x_ll < x_ur and y_ll < y_ur.

**中文解題思路：** 交集矩形邊界為左下座標取 max，右上座標取 min；若 x_ll < x_ur 且 y_ll < y_ur 則存在重疊矩形。 ==========================================================================


<a id="uva-462_bridge-hand-evaluator"></a>

### UVa 462 — Bridge Hand Evaluator／橋牌手牌估值

- 原始碼：[462_bridge-hand-evaluator.c](462_bridge-hand-evaluator.c)
- 難度：Medium
- 演算法：simulation, rule-based

**English description:** Evaluate a 13-card bridge hand according to standard Goren point-count rules and determine the correct opening bid.

**中文詳細描述：** 依據標準高倫 (Goren) 橋牌點力計算規則評估 13 張手牌並決定叫牌策略。

**English approach:** Count high card points (A=4, K=3, Q=2, J=1). Subtract for unprotected honors. Add distribution points. Check suit stopping for No Trump.

**中文解題思路：** 計算大牌點（A=4, K=3, Q=2, J=1），扣除未被保護的大牌點，計算長套分配點，判斷四花色阻擋決定是否開叫無王。 ==========================================================================


<a id="uva-465_overflow"></a>

### UVa 465 — Overflow／32位元整數運算溢位檢測

- 原始碼：[465_overflow.c](465_overflow.c)
- 難度：UVa Star 1
- 演算法：math, big-integer, parsing

**English description:** Determine if either operand or the result of 'A + B' or 'A * B' overflows 32-bit signed integer (2147483647).

**中文詳細描述：** 檢測運算式 'A + B' 或 'A * B' 的運算元或運算結果是否超出 32 位元有號整數最大值 (2^31 - 1 = 2147483647)。

**English approach:** Read operands as double or BigInt. Compare each operand and result with 2147483647.0.

**中文解題思路：** 使用 double 讀取超長數值 (浮點數尾數範圍可輕鬆判斷是否大於 2147483647)，分別檢查第一數、第二數與計算結果。 ==========================================================================


<a id="uva-466_mirror-mirror"></a>

### UVa 466 — Mirror, Mirror／魔鏡魔鏡 (圖案旋轉與反射判定)

- 原始碼：[466_mirror-mirror.c](466_mirror-mirror.c)
- 難度：Easy
- 演算法：matrix-simulation, geometry

**English description:** Determine the transformation (preservation, 90/180/270 rotation, reflection, reflected rotation) that maps pattern A to pattern B.

**中文詳細描述：** 判定將圖形 A 變換為圖形 B 的幾何操作（保持不變、旋轉 90/180/270 度、垂直反射、反射後旋轉）。

**English approach:** Try tests in priority order: identity, rot90, rot180, rot270, reflect vertically, and reflected rot90/rot180/rot270.

**中文解題思路：** 依題目順序比對：保持不變、旋轉 90/180/270 度、垂直反射、反射後旋轉 90/180/270 度，返回最優先符合的操作代碼。 ==========================================================================


<a id="uva-469_wetlands-of-florida"></a>

### UVa 469 — Wetlands of Florida／佛羅里達濕地漫水填充水域面積

- 原始碼：[469_wetlands-of-florida.c](469_wetlands-of-florida.c)
- 難度：UVa Star 2
- 演算法：graph, flood-fill

**English description:** Given a grid of 'W' (water) and 'L' (land), answer queries asking for the area of the 8-connected water component containing (r, c).

**中文詳細描述：** 給定由水域 'W' 與陸地 'L' 組成的網格，查詢包含指定座標 (r, c) 的八方向連通水域總面積。

**English approach:** 8-directional DFS flood fill starting at (r, c). Count visited 'W' cells in the component.

**中文解題思路：** 自查詢點 (r, c) 出發執行八方向 DFS 漫水填充，走訪並計數該連通塊內所有的水域格子數目。 ==========================================================================


<a id="uva-471_magic-numbers"></a>

### UVa 471 — Magic Numbers／神奇數字 (無重複數位整除商)

- 原始碼：[471_magic-numbers.c](471_magic-numbers.c)
- 難度：Easy
- 演算法：math, brute-force

**English description:** Find all pairs (s1, s2) such that s1 / s2 = N, where both s1 and s2 have all distinct digits.

**中文詳細描述：** 求所有滿足 s1 / s2 = N 且 s1 與 s2 各自數位均無重複出現的整數對 (s1, s2)。

**English approach:** Iterate s2 starting from 1. If s2 has repeated digits, skip. s1 = s2 * N; stop when s1 > 9876543210. Check if s1 has distinct digits.

**中文解題思路：** 枚舉 s2 = 1, 2, ...，檢查 s2 是否無重複數位；計算 s1 = s2 * N，若 s1 超出十位數則終止，檢查 s1 是否亦無重複數位。 ==========================================================================


<a id="uva-474_heads-tails-probability"></a>

### UVa 474 — Heads / Tails Probability／連續拋硬幣機率 (科學記號表示)

- 原始碼：[474_heads-tails-probability.c](474_heads-tails-probability.c)
- 難度：Easy
- 演算法：math, logarithms

**English description:** Calculate 2^(-n) in scientific notation: 2^(-n) = a * 10^(-b) where 1 <= a < 10.

**中文詳細描述：** 將拋擲 n 次硬幣均為正面的機率 2^(-n) 表示為 a * 10^(-b) 的科學記號形式。

**English approach:** Let x = -n * log10(2). Then b = floor(-x) + 1 = ceil(n * log10(2)), a = 10^(x + b).

**中文解題思路：** 取對數 x = -n * log10(2)，則指數 b = ceil(n * log10(2))，係數 a = 10^(x + b)。 ==========================================================================


<a id="uva-476_points-in-figures"></a>

### UVa 476 — Points in Figures: Rectangles／點是否落在矩形內

- 原始碼：[476_points-in-figures.c](476_points-in-figures.c)
- 演算法：幾何、矩形內部判定（geometry, point containment）

**English description:** Read up to ten axis-aligned rectangles, then test each point until the sentinel point `(9999.9, 9999.9)`. Report every rectangle containing each point; points on rectangle borders are considered outside.

**中文詳細描述：** 先讀取至多十個矩形，每個矩形以左上角與右下角座標表示，直到 `*` 結束圖形輸入。接著逐點檢查，直到讀到 `(9999.9, 9999.9)`；若點嚴格位於某矩形內部，就輸出該點與矩形編號，邊界上的點不算包含。若沒有任何矩形包含該點，輸出題目指定的未包含訊息。

<a id="uva-476_points-in-figures-rectangles-pr"></a>

### UVa 476 — Points in Figures: Rectangles／點在矩形內部幾何判定

- 原始碼：[476_points-in-figures-rectangles-pr.c](476_points-in-figures-rectangles-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：geometry

**English description:** Given up to 10 rectangles, determine which rectangles contain given query points (strictly inside, not on border).

**中文詳細描述：** 給定最多 10 個矩形，判定輸入的各點嚴格位於哪些矩形內部 (不包含邊界)。

**English approach:** Bounding box check: x1 < px < x2 and y2 < py < y1.

**中文解題思路：** 直接幾何條件判斷：px 介於左上角與右下角的 x 座標之間，py 介於兩者 y 座標之間。 ==========================================================================


<a id="uva-477_points-in-figures-rectangles-and-circles"></a>

### UVa 477 — Points in Figures: Rectangles and Circles／點在矩形與圓形內部判定

- 原始碼：[477_points-in-figures-rectangles-and-circles.c](477_points-in-figures-rectangles-and-circles.c)
- 難度：UVa Star 1
- 演算法：geometry

**English description:** Determine whether query points fall strictly inside rectangles or circles.

**中文詳細描述：** 給定矩形與圓形圖形集合，判定點是否嚴格落在各圖形內部 (圓形使用距離平方判定)。

**English approach:** For rectangle: bounding box check. For circle: (px - cx)^2 + (py - cy)^2 < r^2.

**中文解題思路：** 矩形檢查座標區間；圓形計算點與圓心的歐幾里得距離平方是否小於半徑平方。 ==========================================================================


<a id="uva-478_points-in-figures-rectangles-circles-triangles"></a>

### UVa 478 — Points in Figures: Rectangles, Circles, Triangles／點在幾何圖形判定 (矩形、圓形、三角形)

- 原始碼：[478_points-in-figures-rectangles-circles-triangles.c](478_points-in-figures-rectangles-circles-triangles.c)
- 難度：UVa Star 2
- 演算法：geometry

**English description:** Given a collection of rectangles, circles, and triangles, determine which figures contain a query 2D point (x, y).

**中文詳細描述：** 給定包含矩形、圓形與三角形的二維圖形集合，判定指定查詢點落於哪些圖形的內部。

**English approach:** Check box bounds for rectangles, Euclidean distance squared < R^2 for circles, and cross-product sign consistency for triangles.

**中文解題思路：** 矩形檢驗座標邊界，圓形檢驗與圓心距離平方小於半徑平方，三角形以同向叉積檢驗點是否落在三條邊內側。 ==========================================================================


<a id="uva-481_what-goes-up"></a>

### UVa 481 — What Goes Up／最長嚴格遞增子序列 (O(N log N) LIS 與路徑還原)

- 原始碼：[481_what-goes-up.c](481_what-goes-up.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, lis, binary-search

**English description:** Find the length and actual sequence of the Longest Increasing Subsequence (LIS) in O(N log N) time.

**中文詳細描述：** 在 O(N log N) 時間內求最長嚴格遞增子序列的長度，並輸出最後出現的最優完整子序列。

**English approach:** Patience sorting / binary search on tails array. Maintain parent pointers to reconstruct the exact sequence.

**中文解題思路：** 維護 tails 陣列結合二分搜尋 lower_bound，維護前驅索引 parent 陣列，回溯輸出最長遞增子序列。 ==========================================================================


<a id="uva-482_permutation-arrays"></a>

### UVa 482 — Permutation Arrays／排列陣列還原

- 原始碼：[482_permutation-arrays.c](482_permutation-arrays.c)
- 演算法：索引映射、陣列置換（array, permutation）

**English description:** Each test case contains a line of one-based destination indices and a matching line of data strings. Place the i-th data item at the position specified by the i-th index, then print the reordered items one per line, separating test cases with a blank line.

**中文詳細描述：** 每組輸入有兩列等長資料：第一列是從 1 開始的位置索引，第二列是要排列的字串或數值文字。第 `i` 個資料應放到第 `index[i]` 個輸出位置，完成映射後依位置逐行輸出；不同測試案例之間依題意留空行。

<a id="uva-482_permutation-arrays-pr"></a>

### UVa 482 — Permutation Arrays／排列陣列還原

- 原始碼：[482_permutation-arrays-pr.c](482_permutation-arrays-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：sorting, array

**English description:** Permute array elements according to given 1-based index mapping.

**中文詳細描述：** 依據給定的 1-indexed 位置索引將資料元素重新排回正確位置。

**English approach:** Place value i into output[index[i] - 1].

**中文解題思路：** 陣列置換映射。 ==========================================================================


<a id="uva-483_word-scramble"></a>

### UVa 483 — Word Scramble／單字字元原地反轉

- 原始碼：[483_word-scramble.c](483_word-scramble.c)
- 演算法：字串掃描、區間反轉（string, two pointers）

**English description:** Read text line by line and reverse the characters within each whitespace-delimited word. Keep the words in their original order and preserve the separating spaces and line breaks.

**中文詳細描述：** 輸入包含多行文字，以空白和換行作為單字邊界。對每個單字只反轉其內部字元，不改變單字順序，也不移動原本的分隔空白與換行；處理後逐行輸出轉換結果。

<a id="uva-484_the-department-of-redundancy-department"></a>

### UVa 484 — The Department of Redundancy Department／數字頻率統計 (保持首次出現順序)

- 原始碼：[484_the-department-of-redundancy-department.c](484_the-department-of-redundancy-department.c)
- 難度：UVa Star 1
- 演算法：hash-table, array, frequency

**English description:** Count frequency of each integer in the input stream, outputting numbers in the order of their first appearance.

**中文詳細描述：** 統計整數序列中每個相異數字出現的次數，並嚴格按照數字第一次出現的先後順序輸出。

**English approach:** Store distinct numbers in an array in order of arrival, increment frequency count via linear scan or hash table.

**中文解題思路：** 維護相異數字列表與對應出現次數，新數字加入清單末尾，重複數字累計頻率，最後依序輸出。 ==========================================================================


<a id="uva-485_pascals-triangle-of-death"></a>

### UVa 485 — Pascal's Triangle of Death／帕斯卡三角形之死 (大數溢位展開)

- 原始碼：[485_pascals-triangle-of-death.c](485_pascals-triangle-of-death.c)
- 難度：Easy
- 演算法：big-integer, math, pascal-triangle

**English description:** Generate Pascal's triangle until an entry exceeds 10^60.

**中文詳細描述：** 生成帕斯卡三角形，直到出現超過 10^60 的大整數為止。

**English approach:** Row by row generation using Pascal's identity C(n, k) = C(n-1, k-1) + C(n-1, k) with big integers.

**中文解題思路：** 利用帕斯卡加法遞推公式逐行計算高精度大數數值，直至數值位數超過 60 位。 ==========================================================================


<a id="uva-486_english-number-translator"></a>

### UVa 486 — English-Number Translator／英語數字單詞轉整數

- 原始碼：[486_english-number-translator.c](486_english-number-translator.c)
- 難度：Medium
- 演算法：string, parsing, math

**English description:** Convert an English text phrase representing a signed integer between -999,999,999 and 999,999,999 into its numeric value.

**中文詳細描述：** 將英語單字表述的整數轉換為十進位數字數值（範圍 -999,999,999 至 999,999,999）。

**English approach:** Parse word by word: handle 'negative' prefix; multiply by 100 on 'hundred'; multiply accumulated chunk by 1,000 / 1,000,000 on 'thousand' / 'million'.

**中文解題思路：** 逐詞解析：負號標記，遇 'hundred' 當前塊乘 100，遇 'thousand' 或 'million' 結算當前塊乘上權重並累加至總數值。 ==========================================================================


<a id="uva-488_triangle-wave"></a>

### UVa 488 — Triangle Wave／三角波形輸出

- 原始碼：[488_triangle-wave.c](488_triangle-wave.c)
- 演算法：巢狀迴圈輸出模擬（simulation, pattern printing）

**English description:** For each test case, an amplitude and a frequency describe a numeric wave. One wave rises from line 1 through the amplitude and then falls back to 1; line `i` consists of digit `i` repeated `i` times. Print the wave the requested number of times with the specified blank-line separation.

**中文詳細描述：** 每組輸入振幅 `A` 與頻率 `F`。單一波形從第 1 層上升到第 `A` 層，再下降回第 1 層；第 `i` 層輸出 `i` 共 `i` 次。將完整波形重複 `F` 次，並依題目格式在波形及測試案例之間加入空白行。

<a id="uva-488_triangle-wave-pr"></a>

### UVa 488 — Triangle Wave／三角波形輸出

- 原始碼：[488_triangle-wave-pr.c](488_triangle-wave-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation

**English description:** Print triangle waves given amplitude and frequency.

**中文詳細描述：** 給定振幅與頻率，輸出由數字構成的三角形波形。

**English approach:** Nested loops from 1..A then A-1..1 repeated F times.

**中文解題思路：** 雙重迴圈上升與下降輸出數字。 ==========================================================================


<a id="uva-489_hangman-judge"></a>

### UVa 489 — Hangman Judge／吊死鬼猜單字裁判

- 原始碼：[489_hangman-judge.c](489_hangman-judge.c)
- 難度：UVa Star 1
- 演算法：simulation, string

**English description:** Simulate Hangman word game: player wins if all distinct letters guessed, loses if 7 wrong strokes accumulated.

**中文詳細描述：** 模擬吊死鬼猜字遊戲：7 次猜錯機會。在累計 7 次錯誤前猜出所有相異字母則勝；累積 7 次錯則負；中途放棄判定未結束。

**English approach:** Track guessed letters. Correct guess decrements unique letter count; wrong new guess increments stroke count. Stop on win/loss.

**中文解題思路：** 標記已猜字母避免重複扣分。猜中相異字母則剩餘需猜數減 1，猜錯則錯誤計數加 1，達 7 次立即判負。 ==========================================================================


<a id="uva-490_rotating-sentences"></a>

### UVa 490 — Rotating Sentences／句子順時針旋轉 90 度輸出

- 原始碼：[490_rotating-sentences.c](490_rotating-sentences.c)
- 演算法：二維字元陣列（string, matrix rotation）

**English description:** Read all input lines as rows of a character grid, padding shorter lines conceptually with spaces. Rotate the complete collection 90 degrees clockwise and print it, so each output row is one original column read from the last input line upward.

**中文詳細描述：** 將直到檔案結尾的每一行文字存成二維字元陣列，各列長度可不同，缺少的位置視為空白。以最長輸入列為輸出行數，對每個欄位從最後一列往第一列讀取，即得到順時針旋轉 90 度的結果；必要空白也要保留。

<a id="uva-490_rotating-sentences-pr"></a>

### UVa 490 — Rotating Sentences／句子順時針旋轉 90 度輸出

- 原始碼：[490_rotating-sentences-pr.c](490_rotating-sentences-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, 2d-array

**English description:** Rotate sentences clockwise by 90 degrees.

**中文詳細描述：** 將多行輸入字串順時針旋轉 90 度輸出。

**English approach:** Store in 2D char array, print column by column from last line to first.

**中文解題思路：** 二維陣列存儲，按最大長度逐列由最後一行向前輸出。 ==========================================================================


<a id="uva-492_pig-latin"></a>

### UVa 492 — Pig-Latin／兒童黑話轉換 (Pig-Latin)

- 原始碼：[492_pig-latin.c](492_pig-latin.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Convert text to Pig-Latin: if word starts with vowel, append 'ay'; if consonant, move first letter to end and append 'ay'.

**中文詳細描述：** 依規則轉換兒童黑話：母音 (a,e,i,o,u) 開頭單字末尾加 'ay'；子音開頭單字將首字母移至字尾再加 'ay'。

**English approach:** Scan characters: identify words with isalpha(). Apply prefix movement logic based on whether first char is vowel.

**中文解題思路：** 逐字元掃描，以 isalpha() 分辨單字與非單字。判斷字首是否為母音，子音將首字元移至末端後串接 'ay'。 ==========================================================================


<a id="uva-494_kindergarten-counting-game"></a>

### UVa 494 — Kindergarten Counting Game／幼稚園單字計數

- 原始碼：[494_kindergarten-counting-game.c](494_kindergarten-counting-game.c)
- 演算法：有限狀態掃描（string, state machine）

**English description:** For each input line, count words defined as maximal consecutive sequences of alphabetic letters. Digits, punctuation, and whitespace all separate words. Print one count per line.

**中文詳細描述：** 每行文字各自計算單字數；單字定義為一段最長的連續英文字母，數字、標點及空白都視為分隔符。掃描時在「非單字」轉入「字母中」的瞬間加一，最後每個輸入行輸出一個計數。

<a id="uva-495_fibonacci-freeze"></a>

### UVa 495 — Fibonacci Freeze／大數費氏數列 (F(5000))

- 原始碼：[495_fibonacci-freeze.c](495_fibonacci-freeze.c)
- 難度：UVa Star 1
- 演算法：math, big-integer, dynamic-programming

**English description:** Compute n-th Fibonacci number for n <= 5000 using high-precision arithmetic.

**中文詳細描述：** 計算第 n 個費氏數 (F(0)=0, F(1)=1, ..., F(5000))，使用高精度大數陣列預先遞迴建表。

**English approach:** Precompute first 5000 Fibonacci numbers using BigInt addition in base 10 (or base 10^9).

**中文解題思路：** 大數加法預處理：利用一維大數陣列模擬 F(n) = F(n-1) + F(n-2) 連續遞推至 5000 項。 ==========================================================================


<a id="uva-496_simply-subsets"></a>

### UVa 496 — Simply Subsets／集合關係判定 (子集、真子集、互斥、重疊)

- 原始碼：[496_simply-subsets.c](496_simply-subsets.c)
- 難度：UVa Star 1
- 演算法：set, simulation

**English description:** Determine relationship between sets A and B: 'A equals B', 'A is a proper subset of B', 'B is proper subset', 'disjoint', or 'overlap'.

**中文詳細描述：** 判定集合 A 與 B 的五種文氏圖關係：完全相等、A為B真子集、B為A真子集、互斥不相交或部分重疊相交。

**English approach:** Calculate size of intersection |A ∩ B|. Compare with |A| and |B| to determine exact set relationship.

**中文解題思路：** 統計交集大小 inter。若 inter == |A| == |B| 則相等；inter == |A| 則 A 為子集；inter == 0 則互斥，其餘為相交重疊。 ==========================================================================


<a id="uva-497_strategic-defense-initiative"></a>

### UVa 497 — Strategic Defense Initiative／戰略防禦倡議 (最長遞增子序列路徑還原)

- 原始碼：[497_strategic-defense-initiative.c](497_strategic-defense-initiative.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, lis

**English description:** Find maximum number of missile targets that can be hit (strictly increasing altitudes) and output path.

**中文詳細描述：** 求依序攔截高度嚴格遞增的最多飛彈數量，並輸出還原出的具體飛彈高度序列 (LIS DP 與路徑還原)。

**English approach:** Classic LIS DP with parent array tracking previous missile index for backtracking.

**中文解題思路：** 經典 LIS 動態規劃，以 parent 陣列記錄前驅飛彈下標，最後自最大 LIS 結尾遞迴回溯印出答案。 ==========================================================================


<a id="uva-498_polly-the-polynomial"></a>

### UVa 498 — Polly the Polynomial／多項式霍納法則快速求值

- 原始碼：[498_polly-the-polynomial.c](498_polly-the-polynomial.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Given polynomial coefficients c_n, c_{n-1}, ..., c_0 and an array of values x, evaluate P(x) at each x using Horner's rule.

**中文詳細描述：** 給定多項式係數與若干個整數 x，利用霍納法則 (Horner's rule) 快速求出多項式在各 x 處的函數值 P(x)。

**English approach:** Horner's method: res = res * x + c[i] iteratively from highest degree to constant term.

**中文解題思路：** 霍納計算法：令初始值為最高次係數，每次乘上 x 並加上下一項係數，時間複雜度 O(N)。 ==========================================================================


<a id="uva-499_whats-the-frequency-kenneth"></a>

### UVa 499 — What's The Frequency, Kenneth?／出現頻率最高字母統計

- 原始碼：[499_whats-the-frequency-kenneth.c](499_whats-the-frequency-kenneth.c)
- 演算法：字元頻率統計（string, counting）

**English description:** For each input line, count uppercase and lowercase English letters separately, ignoring all other characters. Print every letter tied for the highest positive frequency in ASCII order, followed by that frequency.

**中文詳細描述：** 對每一輸入行分別統計 `A`–`Z` 與 `a`–`z` 的出現次數，大小寫視為不同字元，其他內容不計。找出該行最高頻率，依大寫在前、小寫在後的字元順序輸出所有並列字母，再輸出最高次數。

<a id="uva-499_whats-the-frequency-kenneth-pr"></a>

### UVa 499 — What's The Frequency, Kenneth?／出現頻率最高字母統計

- 原始碼：[499_whats-the-frequency-kenneth-pr.c](499_whats-the-frequency-kenneth-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, sorting

**English description:** Find uppercase and lowercase letters with maximum frequency.

**中文詳細描述：** 統計字串中出現最多次數的英文字母，依 A-Z, a-z 順序輸出。

**English approach:** Array count[256], find max count, print letters with max count.

**中文解題思路：** 統計頻率求最大值，依序印出達到最大值的字母。 ==========================================================================
