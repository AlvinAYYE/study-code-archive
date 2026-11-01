# UVa Volume 115

本卷收錄 26 份 C 解答，涵蓋 25 個 UVa 題號，以下依題號排序。

<a id="uva-11503_virtual-friends"></a>

### UVa 11503 — Virtual Friends／虛擬交友網路好友圈規模

- 原始碼：[11503_virtual-friends.c](11503_virtual-friends.c)
- 難度：UVa Star 2
- 演算法：graph, dsu

**English description:** When two people become friends, merge their friend networks and output the total size of their combined network.

**中文詳細描述：** 每當兩人建立好友關係時，合併雙方的朋友圈，並即時輸出該好友圈所包含的總人數。

**English approach:** Disjoint-Set Union with size tracking (size[root]). Return size[find(u)] after union.

**中文解題思路：** 帶權並查集 (DSU)：維護每個連通分量的大小 size[root]，每次合併兩集合代表元時將大小相加並回傳新集合大小。 ==========================================================================


<a id="uva-11504_dominos"></a>

### UVa 11504 — Dominos／骨牌骨牌推倒強連通縮點入度

- 原始碼：[11504_dominos.c](11504_dominos.c)
- 難度：UVa Star 2
- 演算法：graph, scc, tarjan

**English description:** Find the minimum number of dominos you must knock over by hand to knock down all dominos.

**中文詳細描述：** 在帶有骨牌骨牌推倒關係的有向圖中，求最少需手動推倒幾張骨牌才能使所有骨牌全部倒下 (SCC 縮點後入度為 0 的個數)。

**English approach:** Find strongly connected components (SCC). Build component DAG and count number of components with in-degree 0.

**中文解題思路：** 以 Tarjan 或 Kosaraju 求強連通分量 (SCC)，將分量縮點構建有向無環圖 (DAG)，統計入度為 0 的連通分量數量。 ==========================================================================


<a id="uva-11506_angry_programmer"></a>

### UVa 11506 — Angry Programmer／憤怒的程式設計師 (頂點割與最小割)

- 原始碼：[11506_angry_programmer.c](11506_angry_programmer.c)
- 難度：Hard
- 演算法：network-flow, min-cut, vertex-splitting

**English description:** Disconnect boss's computer from server by destroying minimum total cost of machines and wires.

**中文詳細描述：** 破壞電腦與電纜以切斷老闆電腦與伺服器的連線，求所需的最小破壞成本總和。

**English approach:** Model as Min-Cut (Max-Flow): split intermediate vertex u into u_in and u_out with capacity cost[u]. Edges have wire capacities. Source is 1, sink is M.

**中文解題思路：** 轉化為最小割問題：拆點法將中間節點 u 拆成 u_in 與 u_out，中間連邊容量為電腦成本 cost[u]，電纜連接為容量為電纜成本的雙向邊，求最大流。 ==========================================================================


<a id="uva-11507_bender-b-rodriguez-problem"></a>

### UVa 11507 — Bender B. Rodriguez Problem／班德 3D 空間折彎鐵絲方向模擬

- 原始碼：[11507_bender-b-rodriguez-problem.c](11507_bender-b-rodriguez-problem.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Track the pointing direction (+x, -x, +y, -y, +z, -z) of a flexible wire as it is bent at sequential unit positions.

**中文詳細描述：** 鐵絲初始朝向 +x，依序施加繞軸旋轉折彎指令 (+y, -y, +z, -z)，求鐵絲頂端最終的空間朝向代碼。

**English approach:** Direction state machine: maintain current direction (+x, -x, +y, -y, +z, -z). Update direction on valid non-'No' bends.

**中文解題思路：** 以方向狀態機維護當前朝向：遇到 +y/-y/+z/-z 時依據三維旋轉變換更新朝向代碼，遇 'No' 則維持原方向。 ==========================================================================


<a id="uva-11512_gattaca"></a>

### UVa 11512 — GATTACA／基因序列最長重複子串 (後綴數組/雜湊)

- 原始碼：[11512_gattaca.c](11512_gattaca.c)
- 難度：Medium
- 演算法：string, suffix-array, lcp, hash

**English description:** Find the longest repeated substring in a DNA sequence, its number of occurrences, and break ties lexicographically.

**中文詳細描述：** 求 DNA 序列中長度最長且至少出現兩次的重複子串及其出現次數（若有多個取字典序最小者）。

**English approach:** Suffix array with LCP (Longest Common Prefix) array. Maximum LCP value gives the longest repeated substring.

**中文解題思路：** 後綴數組與相鄰後綴的最長公共前綴 (LCP) 數組，最大 LCP 即為最長重複子串長度，掃描統計出現次數。 ==========================================================================


<a id="uva-11517_exact-change"></a>

### UVa 11517 — Exact Change／精準找零超額付款與硬幣枚數最小化

- 原始碼：[11517_exact-change.c](11517_exact-change.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming

**English description:** Given price P and n coin denominations, pay an amount >= P minimizing the overpaid amount, and minimizing the number of coins used.

**中文詳細描述：** 給定商品價格 P 與手頭上的 n 枚硬幣面額，付出大於等於 P 的最小金額，並在金額最小時使用最少數量的硬幣。

**English approach:** 0/1 Knapsack DP: dp[v] stores minimum coins needed to form exact amount v. Scan from P upwards to find smallest reachable amount.

**中文解題思路：** 0/1 背包動態規劃：dp[v] 記錄剛好湊出金額 v 所需之最少硬幣數，自 P 向上尋找第一個 dp[v] < INF 之金額。 ==========================================================================


<a id="uva-11518_dominos-2"></a>

### UVa 11518 — Dominos 2／骨牌二部手動擊倒連鎖反應 DFS

- 原始碼：[11518_dominos-2.c](11518_dominos-2.c)
- 難度：UVa Star 1
- 演算法：graph, dfs

**English description:** Given directed domino knocking relationships, find total dominos that fall after a set of specific dominos are manually knocked over.

**中文詳細描述：** 給定骨牌推倒有向圖與手動推倒的骨牌編號列表，求因連鎖反應最終倒下的骨牌總張數。

**English approach:** Standard Depth-First Search: from each manually pushed domino, run DFS marking visited dominos. Count all visited dominos.

**中文解題思路：** 多源深度優先搜尋：對所有手動推倒的骨牌發動 DFS，將倒下的骨牌標記為已訪問，最後統計訪問標記總數。 ==========================================================================


<a id="uva-11520_fill-the-square"></a>

### UVa 11520 — Fill the Square／填滿方格 (貪心網格著色)

- 原始碼：[11520_fill-the-square.c](11520_fill-the-square.c)
- 難度：Easy
- 演算法：greedy, grid

**English description:** Fill empty cells of an N x N grid with uppercase letters such that no two adjacent cells share the same letter, lexicographically smallest.

**中文詳細描述：** 用大寫英文字母填滿 N x N 網格中未填的 '.' 格子，相鄰格字母不可相同，且字典序最小。

**English approach:** Traverse row by row, column by column. For each '.', try 'A', 'B', 'C', ... and pick the first letter not matching any 4-neighbor.

**中文解題思路：** 依字典序由上至下、由左至右遍歷，對每個 '.' 依序嘗試 'A', 'B', 'C'... 挑選與相鄰四格皆不重複的最小字母。 ==========================================================================


<a id="uva-11526_h-n"></a>

### UVa 11526 — H(n)／除法向下取整分塊求和加速

- 原始碼：[11526_h-n.c](11526_h-n.c)
- 難度：UVa Star 2
- 演算法：math

**English description:** Compute H(n) = sum_{i=1}^n floor(n / i) in O(sqrt(n)) time for n up to 2^31 - 1.

**中文詳細描述：** 高效計算 H(n) = sum_{i=1}^n floor(n / i)，利用整數分塊 (數論分塊) 於 O(sqrt(n)) 時間內求和。

**English approach:** Square root chunking: values floor(n/i) = v occur for range of i from l to r = n / v. Add (r - l + 1) * v.

**中文解題思路：** 利用商數相同區間的分塊性質：當 floor(n/i) = v 時，其連續右邊界為 r = n / v，整塊累加 (r - l + 1) * v。 ==========================================================================


<a id="uva-11530_sms-typing"></a>

### UVa 11530 — SMS Typing／手機簡訊按鍵次數統計

- 原始碼：[11530_sms-typing.c](11530_sms-typing.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Calculate the total number of keystrokes required to type a message on an old mobile phone with 12 keys.

**中文詳細描述：** 計算在九宮格功能性手機上輸入指定簡訊文字所需的按鍵總次數。

**English approach:** Precompute the keystrokes needed for each character 'a'-'z' and space (' ': 1, 'a': 1, 'b': 2, 'c': 3, 's': 4, 'z': 4). Sum over string.

**中文解題思路：** 建立 26 個字母與空白鍵的按鍵次數對照表 (如 's' 與 'z' 為 4 次)，逐字累加簡訊字串所需之按鍵總數。 ==========================================================================


<a id="uva-11538_chess-queen"></a>

### UVa 11538 — Chess Queen／西洋棋皇后攻擊對數

- 原始碼：[11538_chess-queen.c](11538_chess-queen.c)
- 難度：Easy
- 演算法：math, combinatorics

**English description:** Count the number of pairs of squares on an M x N chessboard where two queens can attack each other (same row, column, or diagonal).

**中文詳細描述：** 計算在 M x N 棋盤上擺放兩顆皇后使其互相攻擊（同行、同列或同對角線）的格子對數總量。

**English approach:** Rows: M * N*(N-1). Cols: N * M*(M-1). Diagonals: sum over diagonals length L: 2 * L*(L-1). Combine into closed form formula.

**中文解題思路：** 同行互攻對數為 M * N*(N-1)，同列為 N * M*(M-1)，對角線分為兩端遞增與中間平行等長段推導出 closed-form 公式求總和。 ==========================================================================


<a id="uva-11541_decoding"></a>

### UVa 11541 — Decoding／行程長度編碼字串解碼

- 原始碼：[11541_decoding.c](11541_decoding.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Decode run-length encoded string consisting of letters followed by repeat counts (e.g. A3B4 -> AAABBBB).

**中文詳細描述：** 將簡化的行程長度壓縮字串 (如 A3B4C2) 還原解碼為原始完整字串 (AAABBBBCC)。

**English approach:** Scan string: read letter, parse integer repeat count k, append k copies of the letter to the output buffer.

**中文解題思路：** 依序掃描字串：提取字母與緊隨其後的整數計數 k，將該字母重複填入緩衝區 k 次。 ==========================================================================


<a id="uva-11547_automatic-answer"></a>
### UVa 11547 — Automatic Answer／自動答案

- 原始碼：[11547_automatic-answer.c](11547_automatic-answer.c)
- 演算法：算術運算、數位擷取（Math）

**English description:**

For each integer `n`, apply the fixed sequence of arithmetic operations specified by the problem. Take the absolute value of the result's tens digit and output that digit.

**中文詳細描述：**

每組輸入一個整數 `n`，依題目給定順序執行乘、加、除與減法。運算完成後取其十位數的絕對值，也就是先除以 10 再對 10 取餘數，輸出該單一數字。

<a id="uva-11547_automatic-answer-pr"></a>

### UVa 11547 — Automatic Answer／自動解答十位數數字提取

- 原始碼：[11547_automatic-answer-pr.c](11547_automatic-answer-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math

**English description:** Follow arithmetic steps on n: (((n*567/9 + 7492)*235/47 - 498)/10) % 10. Output absolute value of tens digit.

**中文詳細描述：** 依照算術題順序計算：將 n 乘以 567，除以 9，加上 7492，乘以 235，除以 47，減去 498，求十位數數字的絕對值。

**English approach:** Algebraic simplification: ((n * 63 + 7492) * 5 - 498). Divide by 10 and take abs(res % 10).

**中文解題思路：** 簡化運算：計算 ans = (n * 63 + 7492) * 5 - 498，除以 10 後對 10 取餘數並取絕對值得到十位數數字。 ==========================================================================


<a id="uva-11549_calculator-conundrum"></a>

### UVa 11549 — Calculator Conundrum／計算機難題 (平方取中法與Floyd判圈)

- 原始碼：[11549_calculator-conundrum.c](11549_calculator-conundrum.c)
- 難度：Medium
- 演算法：floyd-cycle, simulation, math

**English description:** Simulate repeated squaring and keeping first n digits on an n-digit calculator. Find the maximum value that appears before looping.

**中文詳細描述：** 在 n 位數計算機上重複執行「平方並保留前 n 位數」，求進入循環前出現過的最大數值。

**English approach:** Floyd's cycle detection algorithm (tortoise and hare). Track global maximum value encountered along the trajectory.

**中文解題思路：** 以 Floyd 判圈演算法（快慢指針）檢測偽隨機數循環，沿途更新並記錄軌跡上出現過的最大數字。 ==========================================================================


<a id="uva-11553_grid-game"></a>

### UVa 11553 — Grid Game／網格博弈 (極小化極大全排列)

- 原始碼：[11553_grid-game.c](11553_grid-game.c)
- 難度：Easy
- 演算法：game-theory, minimax, permutations

**English description:** Alice chooses rows and Bob chooses columns in an n x n grid. Find Alice's guaranteed payoff under Bob's optimal play.

**中文詳細描述：** 在 n x n 網格中，Alice 選列、Bob 選行，求 Bob 採取最優策略下 Alice 能保證獲得的最大糖果數。

**English approach:** Since Bob knows Alice's choices, Bob will pick the column permutation that minimizes Alice's sum. Alice picks the row order that maximizes this minimum. Check all n! permutations.

**中文解題思路：** 博弈論極小化極大：列舉所有列到行的雙射全排列，Bob 必然選擇總和最小的行排列，Alice 尋找最優策略。 ==========================================================================


<a id="uva-11559_event-planning"></a>

### UVa 11559 — Event Planning／活動策劃預算與飯店住宿容納

- 原始碼：[11559_event-planning.c](11559_event-planning.c)
- 難度：UVa Star 1
- 演算法：simulation, greedy

**English description:** Find the minimum cost hotel that can accommodate N participants in any available weekend within budget B.

**中文詳細描述：** 在預算 B 內，從多家飯店各週末空房數中找出能容納 N 位參加者且總花費最低之住宿方案。

**English approach:** For each hotel, if any weekend has available beds >= N, calculate cost N * price. Take minimum cost <= B.

**中文解題思路：** 遍歷所有飯店，若某週末空床數 >= N，則計算總費用 N * 單價，在預算 B 內取花費最小者。 ==========================================================================


<a id="uva-11561_getting_gold"></a>

### UVa 11561 — Getting Gold／迷宮採金 (避開陷阱微風感應)

- 原始碼：[11561_getting_gold.c](11561_getting_gold.c)
- 難度：Medium
- 演算法：graph, dfs, bfs, simulation

**English description:** Find the maximum gold a player can collect starting at 'P' without risking falling into a trap 'T'.

**中文詳細描述：** 玩家在迷宮中採集金幣 'G'，若當前格四相鄰處有陷阱 'T' 則會感覺到微風而不敢前進，求能安全取得的最大金幣數。

**English approach:** DFS exploration: collect gold at current cell. If any neighbor has trap 'T', do not expand neighbors.

**中文解題思路：** DFS/BFS 遍歷：到達新格子若有金幣則計數；若相鄰四格存在陷阱 'T' 則停止由此格向外擴展。 ==========================================================================


<a id="uva-11565_simple-equations"></a>

### UVa 11565 — Simple Equations／三元二次方程整數解窮舉搜尋

- 原始碼：[11565_simple-equations.c](11565_simple-equations.c)
- 難度：UVa Star 2
- 演算法：brute-force, math

**English description:** Find distinct integers x < y < z satisfying x + y + z = A, x*y*z = B, and x^2 + y^2 + z^2 = C.

**中文詳細描述：** 尋找相異整數解 x < y < z 滿足聯立方程：x + y + z = A、xyz = B 與 x^2 + y^2 + z^2 = C。

**English approach:** Enumerate x in [-100, 100] and y in [x+1, 100]. Then z = A - x - y. Verify xyz == B and sum of squares == C.

**中文解題思路：** 由於 x^2 <= C 且 C <= 10000，x 與 y 的範圍在 [-100, 100] 內，雙重迴圈枚舉 x 與 y，計算 z 並驗證其餘兩等式。 ==========================================================================


<a id="uva-11572_unique-snowflakes"></a>

### UVa 11572 — Unique Snowflakes／最長相異雪花連續序列

- 原始碼：[11572_unique-snowflakes.c](11572_unique-snowflakes.c)
- 難度：UVa Star 2
- 演算法：two-pointers, hash

**English description:** Find the length of the longest contiguous subsegment of snowflakes with all unique IDs.

**中文詳細描述：** 給定一連串雪花編號序列，找出其中不包含任意重複編號雪花的最長連續子區間長度。

**English approach:** Sliding window / two pointers with a hash table tracking the last seen index of each snowflake ID.

**中文解題思路：** 滑動視窗雙指針法：以雜湊表記錄每個雪花編號上次出現的位置，左指針動態跳躍收縮視窗，時間複雜度 O(N)。 ==========================================================================


<a id="uva-11577_letter-frequency"></a>

### UVa 11577 — Letter Frequency／字母最高頻率統計 (不分大小寫)

- 原始碼：[11577_letter-frequency.c](11577_letter-frequency.c)
- 難度：UVa Star 1
- 演算法：string, simulation

**English description:** Count case-insensitive frequency of letters in text. Output letters with highest frequency in alphabetical order.

**中文詳細描述：** 統計文字中英文字母出現頻率 (不分大小寫)，將出現次數達到最高峰的所有字母按字典序輸出。

**English approach:** Count letter frequencies using 26-element array. Find max frequency, then print all letters achieving that max.

**中文解題思路：** 陣列統計 26 個字母出現次數，找出最大頻率 max_freq，二次掃描將所有次數等於 max_freq 的小寫字母印出。 ==========================================================================


<a id="uva-11581_grid-successors"></a>

### UVa 11581 — Grid Successors／網格後繼運算 (有限元週期與收斂步數)

- 原始碼：[11581_grid-successors.c](11581_grid-successors.c)
- 難度：Easy
- 演算法：simulation, matrix, floyd-cycle

**English description:** Apply cell transition f(g)[i][j] = sum of 4 neighbors mod 2 until grid is all zeros. Find index of last non-zero step.

**中文詳細描述：** 對 3x3 網格反覆執行相鄰 4 格之和取模 2 的變換，求全 0 網格出現前的最大步數索引（初態即為全 0 則為 -1）。

**English approach:** Simulate f(g) iteratively. All initial states converge to all 0s in at most 10 steps.

**中文解題思路：** 迭代模擬鄰居異或和變換，檢查網格是否全為 0，至多 10 步內必收斂至全 0。 ==========================================================================


<a id="uva-11584_partitioning-by-palindromes"></a>
### UVa 11584 — Partitioning by Palindromes／回文分割

- 原始碼：[11584_partitioning-by-palindromes.c](11584_partitioning-by-palindromes.c)
- 演算法：回文預處理、動態規劃（Palindrome, Dynamic Programming）

**English description:**

For each input string, partition all characters into contiguous palindromic substrings while minimizing the number of parts. Output that minimum partition count.

**中文詳細描述：**

每組輸入一個字串，需要把整串切成若干連續片段，且每個片段都必須是回文。先預處理每個區間是否為回文，再令動態規劃記錄各前綴的最少片段數，輸出覆蓋完整字串的最小分割數。

<a id="uva-11586_train-tracks"></a>

### UVa 11586 — Train Tracks／玩具火車軌道公母接頭閉合環路

- 原始碼：[11586_train-tracks.c](11586_train-tracks.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Determine if toy train track pieces (with 'M' and 'F' male/female connectors) can form a single closed loop containing > 1 piece.

**中文詳細描述：** 判定由 'M' (公) 與 'F' (母) 接頭組成的玩具鐵軌零件是否能閉合成一個大於 1 節的封閉環路 (需 M 與 F 總數完全相等且大於 1 節)。

**English approach:** Count total 'M' and 'F' characters. A closed loop is possible if and only if count(M) == count(F) and total pieces > 1.

**中文解題思路：** 統計字串中 'M' 與 'F' 的總個數，可成環的充要條件為 M 與 F 數量相等且總鐵軌節數大於 1。 ==========================================================================


<a id="uva-11588_image-coding"></a>

### UVa 11588 — Image Coding／影像編碼字元計數

- 原始碼：[11588_image-coding.c](11588_image-coding.c)
- 難度：Easy
- 演算法：sorting, frequency-count

**English description:** Find the minimum bytes required to encode an R x C pixel image where most frequent pixel colors take M bytes and others take N bytes.

**中文詳細描述：** 給定 R x C 像素圖像，出現頻率最高的顏色佔用 M 位元組，其餘顏色佔用 N 位元組，求編碼所需的最小位元組數。

**English approach:** Count frequency of each letter. Find maximum frequency max_f. Total = (count_max_f * max_f * M) + (remaining_pixels * N).

**中文解題思路：** 統計 26 個字母頻率，求最高頻率 max_f 及具有該最高頻率的顏色種類數 k，總位元組 = k * max_f * M + (R*C - k * max_f) * N。 ==========================================================================


<a id="uva-11597_spanning-subtree"></a>

### UVa 11597 — Spanning Subtree／生成子樹 (完全圖的邊不相交生成樹數量)

- 原始碼：[11597_spanning-subtree.c](11597_spanning-subtree.c)
- 難度：Easy
- 演算法：math, graph-theory

**English description:** Find the maximum number of edge-disjoint spanning trees in a complete graph K_n.

**中文詳細描述：** 求在 n 個頂點的完全圖 K_n 中，最多可以包含多少個邊不相交的生成樹。

**English approach:** A complete graph K_n has n*(n-1)/2 edges. Each spanning tree has n-1 edges. Max edge-disjoint spanning trees = (n*(n-1)/2) / (n-1) = n / 2.

**中文解題思路：** 完全圖共有 n*(n-1)/2 條邊，每棵生成樹需 n-1 條邊，故最多有 floor(n / 2) 棵邊不相交生成樹。 ==========================================================================
