# UVa Volume 100 題目索引

本卷收錄 73 份 C 解答，涵蓋 62 個 UVa 題號，以下依題號排序。 UVa 10069 保留一維與二維 DP 兩種解法。

<a id="uva-10000_longest-paths"></a>
### UVa 10000 — Longest Paths／最長路徑

- 原始碼：[10000_longest-paths.c](10000_longest-paths.c)
- 演算法：有向無環圖、記憶化深度優先搜尋、動態規劃（DAG, DFS, Dynamic Programming）

**English description:** Given a directed graph and a starting vertex, determine the greatest number of edges on a path beginning there. If several longest paths end at different vertices, report the smallest ending vertex number together with the path length.

**中文詳細描述：** 輸入一張有向圖及指定起點；任務是找出由起點出發可走到的最長路徑。程式以記憶化 DFS 計算每個頂點往後的最佳長度與終點，長度相同時選編號較小的終點，最後輸出最長距離及終點。

<a id="uva-10001_garden-of-eden"></a>

### UVa 10001 — Garden of Eden／伊甸園 (一維細胞自動機前驅狀態判定)

- 原始碼：[10001_garden-of-eden.c](10001_garden-of-eden.c)
- 難度：Medium
- 演算法：backtracking, cellular-automata

**English description:** Determine if a circular 1D cellular automaton configuration is reachable from some ancestor state, or if it is an unreachable 'Garden of Eden' state.

**中文詳細描述：** 判斷一維循環細胞自動機的當前狀態是否具備前驅狀態（若無前驅狀態則為「伊甸園狀態」）。

**English approach:** Backtrack 3-cell neighborhood transitions around the circle of length N. Fix states of cells 0 and 1, match circularly.

**中文解題思路：** 環狀回溯搜尋：枚舉細胞 0 與 1 的前驅狀態，沿環逐位根據 Wolfram 規則驗證是否能首尾閉合拼接。 ==========================================================================


<a id="uva-10002_center_of_masses"></a>

### UVa 10002 — Center of Masses／凸多邊形質心計算

- 原始碼：[10002_center_of_masses.c](10002_center_of_masses.c)
- 難度：Medium
- 演算法：geometry, centroid, polygon-area

**English description:** Find the center of mass (centroid) of a uniform planar convex polygon.

**中文詳細描述：** 求均勻凸多邊形平面薄片的質心（重心）坐標。

**English approach:** Sort vertices counter-clockwise (Convex Hull), then compute polygon area and weighted centroid coordinates using standard polygon formulas.

**中文解題思路：** 先求凸包以取得逆時針頂點順序，再利用多邊形有向面積與質心積分公式求解 Cx 與 Cy。 ==========================================================================


<a id="uva-10003_cutting-sticks"></a>
### UVa 10003 — Cutting Sticks／切割木棍

- 原始碼：[10003_cutting-sticks.c](10003_cutting-sticks.c)
- 演算法：區間動態規劃（Interval DP）

**English description:** A stick of a given length must be cut at specified positions. Each cut costs the length of the current segment being cut, so the goal is to choose the cutting order that minimizes the total cost.

**中文詳細描述：** 輸入木棍總長與所有必須切割的位置；同一組切點因執行順序不同，切割當下的區段長度也不同。程式以兩切點間的區間作為狀態，枚舉最後或第一個切點並合併左右成本，輸出完成全部切割的最小總成本。

<a id="uva-10004_bicoloring"></a>
### UVa 10004 — Bicoloring／雙色著色

- 原始碼：[10004_bicoloring.c](10004_bicoloring.c)
- 演算法：圖形走訪、廣度優先搜尋、二分圖判定（BFS, Bipartite Graph）

**English description:** Given an undirected graph, decide whether its vertices can be colored with two colors so that every edge joins vertices of different colors. The result states whether the graph is bicolorable.

**中文詳細描述：** 輸入無向圖的頂點與邊；任務是判斷能否只用兩種顏色，使每條邊的兩端顏色都不同。程式從起點做 BFS，替未著色鄰點配置相反顏色；若遇到同色相鄰頂點便判定失敗，最後輸出是否可雙色著色。

<a id="uva-10006_carmichael-numbers"></a>
### UVa 10006 — Carmichael Numbers／卡邁克爾數

- 原始碼：[10006_carmichael-numbers.c](10006_carmichael-numbers.c)
- 演算法：數論、質數判定、快速模冪（Number Theory, Modular Exponentiation）

**English description:** For each input integer, determine whether it is a composite Carmichael number, meaning that it satisfies a^n congruent to a modulo n for every integer a between 2 and n-1.

**中文詳細描述：** 輸入若干整數；題目要求判斷每個數是否為卡邁克爾數。程式先排除質數，再對候選底數使用快速模冪驗證費馬型同餘式；全部成立才輸出卡邁克爾數的判定，否則視為一般數。

<a id="uva-10007_count-the-trees"></a>

### UVa 10007 — Count the Trees／計算二元樹數量

- 原始碼：[10007_count-the-trees.c](10007_count-the-trees.c)
- 難度：Medium
- 演算法：math, catalan-numbers, big-integer

**English description:** Find the number of completely labeled binary search trees with n distinct keys: n! * C_n = (2n)! / (n + 1)!.

**中文詳細描述：** 求含 n 個不同節點的標號二元樹總數，計算公式為 n! * 卡特蘭數 C_n = (2n)! / (n+1)!。

**English approach:** Total labeled binary trees = n! * Catalan(n) = (2n)! / (n + 1)!.

**中文解題思路：** n 個節點的二元樹形態有 C_n 種，節點填入 1..n 標號有 n! 種排列，故總數為 C_n * n!。 ==========================================================================


<a id="uva-10008_whats-cryptanalysis"></a>
### UVa 10008 — What's Cryptanalysis?／什麼是密碼分析？

- 原始碼：[10008_whats-cryptanalysis.c](10008_whats-cryptanalysis.c)
- 演算法：字元統計、多鍵排序（Frequency Counting, Sorting）

**English description:** Read several lines of text, count letters without regard to case, and print every letter that appears. Letters are ordered by decreasing frequency and then alphabetically when counts tie.

**中文詳細描述：** 輸入多行英文文字；忽略大小寫後統計 A 到 Z 各字母出現次數。輸出時先按次數由多至少排列，次數相同則按字母順序排列，且只列出實際出現過的字母。

<a id="uva-10009_all-roads-lead-where"></a>
### UVa 10009 — All Roads Lead Where?／條條大路通何方？

- 原始碼：[10009_all-roads-lead-where.c](10009_all-roads-lead-where.c)
- 演算法：樹、父節點追蹤、最低共同祖先（Tree, LCA）

**English description:** Given roads that form a tree and pairs of cities, print the unique route between each requested pair. City initials are concatenated in the order in which the route visits them.

**中文詳細描述：** 輸入構成樹狀結構的城市道路，以及多組起訖城市查詢；因圖為樹，每組城市間只有一條簡單路徑。程式分別向父節點回溯以找出共同祖先，再串接上行與下行路徑，輸出依序經過的城市代號。

<a id="uva-10010_wheres-waldorf"></a>
### UVa 10010 — Where's Waldorf?／沃爾多在哪裡？

- 原始碼：[10010_wheres-waldorf.c](10010_wheres-waldorf.c)
- 演算法：二維陣列、八方向字串搜尋（Grid Search, String Matching）

**English description:** Search a letter grid for each query word in any of the eight straight directions, ignoring letter case. Report the row and column of the first character of the earliest matching occurrence.

**中文詳細描述：** 輸入一個字母方格與多個查詢單字；每個單字可沿水平、垂直或斜向共八個方向出現，配對時不分大小寫。程式依列、欄順序嘗試每個起點與方向，輸出最先找到之單字首字母的一基底座標。

<a id="uva-10012_how-big-is-it"></a>
### UVa 10012 — How Big Is It?／到底有多大？

- 原始碼：[10012_how-big-is-it.c](10012_how-big-is-it.c)
- 演算法：排列回溯、圓形幾何（Backtracking, Geometry）

**English description:** Arrange circles of given radii inside a horizontal rectangular container so that they rest without overlapping. Find the ordering and placements that minimize the required container width.

**中文詳細描述：** 輸入多個圓的半徑；任務是決定圓的排列順序與水平位置，使圓彼此不重疊且包住所有圓的矩形寬度最小。完整作法會以切圓幾何計算合法中心距離，再枚舉不同排列取最小寬度

<a id="uva-10012_how-big-is-it-pr"></a>

### UVa 10012 — How Big Is It?／圓形排列最小外接矩形寬度

- 原始碼：[10012_how-big-is-it-pr.c](10012_how-big-is-it-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：geometry, backtracking, math

**English description:** Given n circles, order them on a line to minimize horizontal enclosing box width.

**中文詳細描述：** 將 n 個不同半徑的圓放在水平線上相切排列，求最小的外接矩形寬度。

**English approach:** Backtracking permutation (n <= 8). Position x_i = max(r_i, max_j(x_j + 2*sqrt(r_i * r_j))).

**中文解題思路：** 回溯枚舉圓的排列，相切圓中心距離為 2*sqrt(r_i*r_j)。 ==========================================================================


<a id="uva-10013_super-long-sums"></a>
### UVa 10013 — Super Long Sums／超長整數相加

- 原始碼：[10013_super-long-sums.c](10013_super-long-sums.c)
- 演算法：大整數、逐位加法（Big Integer, Simulation）

**English description:** Two extremely long nonnegative integers are supplied as pairs of corresponding decimal digits. Add them exactly and print the complete decimal sum.

**中文詳細描述：** 輸入兩個長度很大的非負整數，各位數以成對數字由最高位到最低位給出。程式先保存每一位的和，再從最低位向左處理進位，最後輸出不能用一般整數型別直接容納的完整十進位結果。

<a id="uva-10014_simple-calculations"></a>
### UVa 10014 — Simple Calculations／簡單計算

- 原始碼：[10014_simple-calculations.c](10014_simple-calculations.c)
- 演算法：代數推導、線性遞迴（Algebra, Recurrence）

**English description:** A sequence satisfies a second-order relation involving known constants c_i, while its two boundary values are given. Compute and print the first unknown term a_1.

**中文詳細描述：** 輸入序列長度、兩端值 a_0 與 a_{n+1}，以及各項常數 c_i；序列須滿足題目給定的二階關係式。程式將所有等式加權整理成 a_1 的封閉公式，計算後依題目格式輸出第一個未知項。

<a id="uva-10015_josephs-cousin"></a>
### UVa 10015 — Joseph's Cousin／約瑟夫的表親

- 原始碼：[10015_josephs-cousin.c](10015_josephs-cousin.c)
- 演算法：約瑟夫問題、質數篩、模擬（Josephus, Prime Sieve）

**English description:** People stand in a circle and are removed one by one, using successive prime numbers as the step sizes. For each population size, determine the position of the final survivor.

**中文詳細描述：** 輸入圓圈中的人數；淘汰過程依序使用第 1、2、3 個質數等作為每輪步長。程式先產生所需質數，再以約瑟夫問題的索引遞推或模擬更新存活位置，輸出最後留下者的編號。

<a id="uva-10018_reverse-and-add"></a>
### UVa 10018 — Reverse and Add／反轉再相加

- 原始碼：[10018_reverse-and-add.c](10018_reverse-and-add.c)
- 演算法：數字反轉、迭代模擬、回文判定（Simulation, Palindrome）

**English description:** Starting with an integer, repeatedly reverse its decimal digits and add the reversed value to the current number. Report how many iterations are needed to obtain a palindrome and the resulting palindrome.

**中文詳細描述：** 輸入整數後，反轉其十進位數字並與原數相加，再對新數重複相同步驟。程式每輪檢查結果是否為回文，最後輸出迭代次數與首次得到的回文數。

<a id="uva-10019_funny-encryption-method"></a>
### UVa 10019 — Funny Encryption Method／有趣的加密方法

- 原始碼：[10019_funny-encryption-method.c](10019_funny-encryption-method.c)
- 演算法：位元計數、進位表示（Bit Manipulation, Base Conversion）

**English description:** For each decimal integer N, count the one bits in N's ordinary binary representation and in the binary value obtained when N's decimal digits are interpreted as hexadecimal digits. Print both counts.

**中文詳細描述：** 輸入十進位整數 N；第一個答案是 N 直接轉為二進位後的 1 位元數，第二個答案則先把 N 的十進位字串當作十六進位表示，再統計該值的 1 位元數。程式以位元消去法計數並輸出兩個結果。

<a id="uva-10020_minimal-coverage"></a>
### UVa 10020 — Minimal Coverage／最少區間覆蓋

- 原始碼：[10020_minimal-coverage.c](10020_minimal-coverage.c)
- 演算法：貪心、區間排序（Greedy, Interval Covering）

**English description:** From a collection of intervals, choose the smallest subset whose union completely covers [0, M]. Print the selected intervals, or report that no complete cover exists.

**中文詳細描述：** 輸入目標區間 [0, M] 與一批候選線段；任務是使用最少線段完整覆蓋目標。程式先依左端點排序，在目前已覆蓋位置之前可起始的線段中，每次選右端延伸最遠者；若中途無法前進便輸出無解，否則輸出數量與選中的線段。

<a id="uva-10023_square-root"></a>
### UVa 10023 — Square Root／平方根

- 原始碼：[10023_square-root.c](10023_square-root.c)
- 演算法：高精度整數、直式開平方（Big Integer, Longhand Square Root）

**English description:** Given a nonnegative integer too large for built-in numeric types, compute its exact integer square root and print the decimal result.

**中文詳細描述：** 輸入位數很長的非負整數；任務是求其精確整數平方根，不能依賴一般固定寬度型別。完整作法可用十進位大整數搭配直式開平方逐段決定答案數字

<a id="uva-10023_square-root-pr"></a>

### UVa 10023 — Square root／大整數開平方根

- 原始碼：[10023_square-root-pr.c](10023_square-root-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：math, big-integer

**English description:** Compute integer square root of a number up to 1000 digits.

**中文詳細描述：** 大數開根號（可達 1000 位數），求精確整數根。

**English approach:** High-precision manual long division square root extraction.

**中文解題思路：** 手算直式開平方法。 ==========================================================================


<a id="uva-10025_the-1-2--n-=-k-problem"></a>
### UVa 10025 — The 1 2 ... n = k Problem／1、2、…、n 等於 k 問題

- 原始碼：[10025_the-1-2--n-=-k-problem.c](10025_the-1-2--n-=-k-problem.c)
- 演算法：數學、奇偶性、貪心搜尋（Math, Parity）

**English description:** Find the smallest n for which signs can be assigned to 1, 2, ..., n so that their signed sum equals a given integer k.

**中文詳細描述：** 輸入整數 k；要找最小 n，使 1 到 n 的每個數前可選正號或負號，且總和恰為 k。程式取 |k|，逐步累加三角形數，直到總和不小於 k 且兩者差為偶數，輸出此時的最小 n。

<a id="uva-10026_shoemakers-problem"></a>
### UVa 10026 — Shoemaker's Problem／鞋匠問題

- 原始碼：[10026_shoemakers-problem.c](10026_shoemakers-problem.c)
- 演算法：貪心交換論證、自訂排序（Greedy, Sorting）

**English description:** Each job has a processing time and a fine charged for every day it remains unfinished. Order all jobs to minimize the total fine, breaking equivalent choices by original job number.

**中文詳細描述：** 輸入多項工作，每項包含完成所需天數與每日延誤罰金。任務是安排工作順序，使累積罰金最小；程式以交叉乘積比較工作時間與罰金比率，避免浮點誤差，若優先順序相同則依原編號，最後輸出工作次序。

<a id="uva-10029_edit-step-ladders"></a>
### UVa 10029 — Edit Step Ladders／編輯階梯

- 原始碼：[10029_edit-step-ladders.c](10029_edit-step-ladders.c)
- 演算法：字串動態規劃、字典查找（Dynamic Programming, String）

**English description:** From a lexicographically ordered dictionary, find the longest ladder in which every next word is later in dictionary order and differs from its predecessor by one insertion, deletion, or replacement.

**中文詳細描述：** 輸入依字典序排列的單字；若後一個單字可由前一個單字經一次插入、刪除或替換得到，就能接在階梯後。完整作法會對每個單字查找所有可能的先驅並做動態規劃，輸出可形成的最長階梯長度

<a id="uva-10029_edit-step-ladders-pr"></a>

### UVa 10029 — Edit Step Ladders／編輯距離階梯

- 原始碼：[10029_edit-step-ladders-pr.c](10029_edit-step-ladders-pr.c)
- 難度：UVa Star 3
- 解答版本：PR 同題替代實作
- 演算法：dynamic-programming, string

**English description:** Find longest sequence of words where each word is formed from the previous by 1 edit operation and words are in lexicographical order.

**中文詳細描述：** 求最長單字階梯長度。階梯中後一個單字比前一個單字字典序大，且編輯距離恰為 1（增、刪、改單一字元）。

**English approach:** DP with hash table or binary search lookup on preceding words.

**中文解題思路：** 動態規劃。對當前單字枚舉其前驅可能的變形單字，查詢歷史最大 DP 值轉移。 ==========================================================================


<a id="uva-10032_tug-of-war"></a>
### UVa 10032 — Tug of War／拔河

- 原始碼：[10032_tug-of-war.c](10032_tug-of-war.c)
- 演算法：0/1 背包、位元集合動態規劃（Knapsack, Bitset DP）

**English description:** Split people into two teams whose sizes differ by at most one and whose total weights are as close as possible. Print the two team weights in increasing order.

**中文詳細描述：** 輸入每位成員的體重；必須分成兩隊，人數相同或只差一人，並讓總體重差最小。程式以重量為索引、以位元表示可用人數的 0/1 背包狀態，從總重一半向下找符合隊伍人數的最佳重量，輸出兩隊總重。

<a id="uva-10033_interpreter"></a>
### UVa 10033 — Interpreter／直譯器

- 原始碼：[10033_interpreter.c](10033_interpreter.c)
- 演算法：指令集模擬（Simulation）

**English description:** Execute a program for a small decimal virtual machine with ten registers and one thousand memory cells. Stop on instruction 100 and report the number of instructions executed, including the halt.

**中文詳細描述：** 輸入一串三位數機器指令並載入記憶體；各百位數操作碼會設定、加乘、載入、儲存或條件跳躍，所有暫存器運算依規則取模。程式逐步取指、解碼與執行，遇到 100 停機，輸出執行過的指令總數。

<a id="uva-10034_freckles"></a>
### UVa 10034 — Freckles／雀斑

- 原始碼：[10034_freckles.c](10034_freckles.c)
- 演算法：最小生成樹、歐幾里得距離、Prim 演算法（MST, Prim）

**English description:** Given points in the plane, connect all of them with line segments using the minimum possible total length. Print the weight of the Euclidean minimum spanning tree.

**中文詳細描述：** 輸入平面上各點座標；任務是用線段把所有點連成同一連通網路，並使墨線總長最小。程式把任兩點的歐幾里得距離視為邊權，以 Prim 演算法建立最小生成樹，輸出其總長度。

<a id="uva-10035_primary-arithmetic"></a>
### UVa 10035 — Primary Arithmetic／基礎算術

- 原始碼：[10035_primary-arithmetic.c](10035_primary-arithmetic.c)
- 演算法：逐位加法模擬（Digit Simulation）

**English description:** For each pair of nonnegative decimal integers, count how many carry operations occur in ordinary right-to-left addition. Print a grammatically appropriate message for zero, one, or multiple carries.

**中文詳細描述：** 輸入多組非負整數，直到終止資料；任務是計算直式加法中發生幾次進位。程式由個位數起逐位相加並帶入上一位進位，累計和達到十的次數，再依 0、1 或多次輸出相應訊息。

<a id="uva-10036_divisibility"></a>
### UVa 10036 — Divisibility／整除性

- 原始碼：[10036_divisibility.c](10036_divisibility.c)
- 演算法：餘數動態規劃（Remainder DP）

**English description:** Insert either a plus or a minus sign before each number in a sequence and decide whether some resulting signed sum is divisible by K.

**中文詳細描述：** 輸入整數序列與除數 K；每加入一個數時可選擇加或減，題目要求判斷是否存在使最終總和可被 K 整除的配置。程式只保留各階段可達的模 K 餘數，轉移到加、減兩種新餘數，最後輸出可整除或不可整除。

<a id="uva-10037_bridge"></a>
### UVa 10037 — Bridge／過橋

- 原始碼：[10037_bridge.c](10037_bridge.c)
- 演算法：貪心、排序（Greedy, Sorting）

**English description:** People with different crossing times must all cross a bridge at night using one flashlight, with at most two people crossing together. Find the minimum total time and a corresponding crossing plan.

**中文詳細描述：** 輸入每個人的過橋時間；每次最多兩人同行且手電筒必須被帶回，同行耗時取較慢者。程式先排序，反覆比較「最快者分別護送」與「兩位最快者接力」兩種搬運最慢兩人的策略，得到並輸出最小總時間與過橋步驟。

<a id="uva-10038_jolly-jumpers"></a>
### UVa 10038 — Jolly Jumpers／快樂跳躍者

- 原始碼：[10038_jolly-jumpers.c](10038_jolly-jumpers.c)
- 演算法：陣列標記、相鄰差模擬（Array, Simulation）

**English description:** A sequence of length n is jolly when the absolute differences of consecutive values contain every integer from 1 through n-1 exactly once. Classify each input sequence.

**中文詳細描述：** 每筆輸入先給序列長度 n 與 n 個整數；計算相鄰元素差的絕對值後，若 1 到 n-1 全部恰好出現一次，便是 Jolly。程式用布林陣列記錄差值，遇到越界或重複即可判定失敗，最後輸出分類結果。

<a id="uva-10041_vitos-family"></a>
### UVa 10041 — Vito's Family／維托的家族

- 原始碼：[10041_vitos-family.c](10041_vitos-family.c)
- 演算法：排序、中位數、絕對距離（Median, Sorting）

**English description:** Given the street numbers where Vito's relatives live, choose a street for Vito that minimizes the sum of walking distances to all relatives. Print that minimum total distance.

**中文詳細描述：** 輸入親戚住所的街道號碼；維托要選一個住址，使到所有親戚家的距離總和最小。程式將街道號碼排序並取中位數作為最佳位置，再加總各住所與中位數的絕對差，輸出最小總距離。

<a id="uva-10042_smith-numbers"></a>
### UVa 10042 — Smith Numbers／史密斯數

- 原始碼：[10042_smith-numbers.c](10042_smith-numbers.c)
- 演算法：質因數分解、數位和（Prime Factorization, Number Theory）

**English description:** A Smith number is composite and has a digit sum equal to the sum of the digits in its prime factorization, counting repeated factors. For each input, find the smallest Smith number larger than it.

**中文詳細描述：** 輸入整數 n；要從 n+1 起尋找最小史密斯數。程式排除質數，對候選數做質因數分解並保留重複因子，比較候選數本身的數位和與所有質因數的數位和；相等時輸出該候選數。

<a id="uva-10044_erdos-numbers"></a>
### UVa 10044 — Erdos Numbers／厄多斯數

- 原始碼：[10044_erdos-numbers.c](10044_erdos-numbers.c)
- 演算法：合作圖建模、廣度優先搜尋（Graph, BFS）

**English description:** Build a coauthorship graph from paper author lists. For every queried author, print the length of the shortest collaboration chain from Erdos, or infinity when no such chain exists.

**中文詳細描述：** 輸入多篇論文的作者名單與查詢作者；同一篇論文的作者彼此建立合作邊。完整作法以 Erdos 為起點做 BFS，得到每位作者的最短合作層數；查詢時輸出作者名稱與厄多斯數，無法連通則輸出 infinity。

<a id="uva-10044_erdos-numbers-pr"></a>

### UVa 10044 — Erdos Numbers／艾狄胥數

- 原始碼：[10044_erdos-numbers-pr.c](10044_erdos-numbers-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：graph, bfs, string

**English description:** Compute Erdos numbers (shortest collaboration distance from Paul Erdos).

**中文詳細描述：** 建立作者合作無向圖，計算由 Erdos 起算的 BFS 最短距離。

**English approach:** Graph construction from paper author lists + BFS from Erdos.

**中文解題思路：** 論文作者建立圖節點與邊，從 Erdos 跑 BFS 標記距離。 ==========================================================================


<a id="uva-10047_the-monocycle"></a>
### UVa 10047 — The Monocycle／獨輪車

- 原始碼：[10047_the-monocycle.c](10047_the-monocycle.c)
- 演算法：擴充狀態廣度優先搜尋（State-space BFS）

**English description:** Move a monocycle through a blocked grid. It may turn or move forward, its wheel color advances after each forward move, and it must reach the target showing green; find the minimum time or report impossibility.

**中文詳細描述：** 輸入含障礙、起點與終點的網格；獨輪車每秒可左轉、右轉或前進，前進時輪面顏色會在五色間循環。完整作法把位置、朝向與顏色一起當成 BFS 狀態，尋找抵達終點且顯示綠色的最短時間

<a id="uva-10047_the-monocycle-pr"></a>

### UVa 10047 — The Monocycle／單輪車迷宮

- 原始碼：[10047_the-monocycle-pr.c](10047_the-monocycle-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：graph, bfs, shortest-path

**English description:** Shortest time for a monocycle (4 directions, 5 wheel colors) to reach target in green color.

**中文詳細描述：** 單輪車前進 1 格需 1 秒且輪子轉動換下一種顏色（共有 5 種顏色）；轉向 90 度需 1 秒。 求抵達終點且輪子剛好轉到綠色（初始顏色）的最少秒數。

**English approach:** BFS on state space (row, col, direction, color).

**中文解題思路：** 狀態空間 BFS：狀態定義為 (r, c, dir, color)，共 row * col * 4 * 5 種狀態。 ==========================================================================


<a id="uva-10048_audiophobia"></a>
### UVa 10048 — Audiophobia／恐聲症

- 原始碼：[10048_audiophobia.c](10048_audiophobia.c)
- 演算法：最小化最大邊、Floyd–Warshall（Minimax Path）

**English description:** Roads have sound levels. For each pair of cities, find a route whose loudest road is as quiet as possible, and print that minimum possible maximum level or state that no path exists.

**中文詳細描述：** 輸入城市、道路及每條道路的噪音值，再給多組起訖查詢；路徑代價定義為途中最大邊權，目標是讓此最大值最小。程式以 Floyd–Warshall 的 minimax 轉移預先計算所有城市對，查詢時輸出最佳噪音值或 no path。

<a id="uva-10049_self-describing-sequence"></a>

### UVa 10049 — Self-describing Sequence／自描述序列 (Golomb 序列)

- 原始碼：[10049_self-describing-sequence.c](10049_self-describing-sequence.c)
- 難度：Medium
- 演算法：math, binary-search, dp

**English description:** Compute the n-th value in Golomb's self-describing sequence where f(n) is the number of times n appears in the sequence.

**中文詳細描述：** 計算 Golomb 自描述序列中的第 n 項數值 f(n)（f(n) 為 n 在序列中出現的次數）。

**English approach:** Precompute prefix sums of Golomb numbers and use binary search to locate n.

**中文解題思路：** 預先計算 Golomb 序列的前綴和邊界陣列，再使用二分搜尋找出 n 所處的區間值。 ==========================================================================


<a id="uva-10050_hartals"></a>
### UVa 10050 — Hartals／罷工

- 原始碼：[10050_hartals.c](10050_hartals.c)
- 演算法：日期模擬、布林標記（Simulation）

**English description:** Political parties call strikes at fixed day intervals during a period of N days. Count lost working days, excluding Fridays and Saturdays and counting overlapping strikes only once.

**中文詳細描述：** 輸入模擬天數與各政黨的罷工週期；每逢週期倍數便罷工，但週五、週六本來就不是工作日，不能列入損失。程式標記所有有效罷工日，重疊日期只算一次，最後輸出損失的工作天數。

<a id="uva-10051_tower-of-cubes"></a>

### UVa 10051 — Tower of Cubes／立方體堆高塔 (最大加權LIS/DAG最長路)

- 原始碼：[10051_tower-of-cubes.c](10051_tower-of-cubes.c)
- 難度：Medium
- 演算法：dp, dag-longest-path

**English description:** Stack cubes of decreasing index such that the bottom face of the upper cube has the same color as the top face of the lower cube. Maximize height.

**中文詳細描述：** 依索引遞減的順序疊放立方體，使得上層方塊底面顏色等於下層方塊頂面顏色，求最大堆疊高度。

**English approach:** Each cube has 6 possible orientations (bottom face chosen from 6 faces, top is opposite). DP state dp[cube][orientation] = max height ending with this state.

**中文解題思路：** 每個立方體有 6 種朝向（底面選定則頂面固定為對面），動態規劃在 DAG 上求最長路徑並回溯朝向與方塊編號。 ==========================================================================


<a id="uva-10054_the-necklace"></a>
### UVa 10054 — The Necklace／項鍊

- 原始碼：[10054_the-necklace.c](10054_the-necklace.c)
- 演算法：歐拉迴路、Hierholzer 演算法（Eulerian Circuit）

**English description:** Each bead has two colored ends. Arrange all beads in a closed necklace so touching ends have equal colors, or report that no arrangement using every bead exists.

**中文詳細描述：** 輸入多顆珠子兩端的顏色；每種顏色視為頂點、珠子視為無向邊，必須把所有珠子恰用一次並首尾相接。完整作法須檢查度數與連通條件，再建立歐拉迴路並按順序輸出相接顏色

<a id="uva-10054_the-necklace-pr"></a>

### UVa 10054 — The Necklace／項鍊問題

- 原始碼：[10054_the-necklace-pr.c](10054_the-necklace-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：graph, eulerian-tour

**English description:** Connect beads into a necklace such that adjacent half-beads have the same color (Eulerian Tour).

**中文詳細描述：** 每顆珠子兩端有顏色（邊），求串成一條封閉項鍊且相鄰兩半顏色相同（等價於無向圖歐拉迴路）。

**English approach:** Check all vertex degrees are even and connected. Hierholzer's algorithm for Euler tour.

**中文解題思路：** 檢驗所有頂點度數為偶數且連通，使用 Hierholzer 演算法構造歐拉迴路。 ==========================================================================


<a id="uva-10055_hashmat-the-brave-warrior"></a>
### UVa 10055 — Hashmat the Brave Warrior／勇士哈希馬特

- 原始碼：[10055_hashmat-the-brave-warrior.c](10055_hashmat-the-brave-warrior.c)
- 演算法：大範圍整數、絕對差（64-bit Integer）

**English description:** For every pair of army sizes, print the absolute difference between the two values. Input continues until end of file.

**中文詳細描述：** 每行輸入兩支軍隊的人數，資料讀到檔案結尾；任務是計算兩者相差多少。程式使用足以容納題目數值的整數型別，取兩數差的絕對值並逐行輸出。

<a id="uva-10056_what-is-the-probability"></a>
### UVa 10056 — What is the Probability?／機率是多少？

- 原始碼：[10056_what-is-the-probability.c](10056_what-is-the-probability.c)
- 演算法：等比級數、機率（Probability, Geometric Series）

**English description:** N players repeatedly take turns, and each attempt succeeds independently with probability p. Compute the probability that a specified player is the first winner.

**中文詳細描述：** 輸入玩家數 N、每次嘗試成功率 p，以及指定玩家的順序；所有人輪流嘗試，第一位成功者獲勝，若一輪全失敗便重新開始。程式把指定玩家在每輪輪到前所需失敗與重複整輪的機率寫成等比級數，輸出其最終勝率。

<a id="uva-10056_what-is-the-probability-pr"></a>

### UVa 10056 — What is the Probability?／誰會先擲出成功？(幾何分佈無窮等比級數)

- 原始碼：[10056_what-is-the-probability-pr.c](10056_what-is-the-probability-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, probability

**English description:** N players take turns rolling a die with success probability p. Find probability that player I is the first to succeed.

**中文詳細描述：** N 位玩家依序輪流擲骰子，每人成功機率為 p。求第 I 位玩家是全場第一個擲出成功的機率。

**English approach:** Geometric series: P = (1-p)^{I-1} * p / (1 - (1-p)^N). Handle p = 0 edge case.

**中文解題思路：** 無窮等比級數求和公式：P = p * q^(I-1) / (1 - q^N)，其中 q = 1 - p。若 p 接近 0 則機率為 0.0000。 ==========================================================================


<a id="uva-10057_a-mid-summer-nights-dream"></a>
### UVa 10057 — A Mid-Summer Night's Dream／仲夏夜之夢

- 原始碼：[10057_a-mid-summer-nights-dream.c](10057_a-mid-summer-nights-dream.c)
- 演算法：排序、中位數區間（Median）

**English description:** For a multiset of integers, characterize every integer A that minimizes the sum of absolute differences. Print the smallest such A, the number of input values lying in the optimal interval, and the number of integer choices for A.

**中文詳細描述：** 輸入一組整數；任務是找使所有 |X_i-A| 總和最小的整數 A。排序後，奇數筆資料只有中位數最佳，偶數筆則兩個中位數之間的所有整數都最佳；程式輸出最小最佳值、落在最佳區間內的輸入值數量，以及可選 A 的整數個數。

<a id="uva-10061_how-many-zeros-and-how-many-digits"></a>
### UVa 10061 — How Many Zeros and How Many Digits?／有幾個尾零與幾位數？

- 原始碼：[10061_how-many-zeros-and-how-many-digits.c](10061_how-many-zeros-and-how-many-digits.c)
- 演算法：質因數指數、勒讓德公式、對數（Legendre Formula, Logarithm）

**English description:** For N! represented in base B, compute the number of trailing zero digits and the total number of digits. Print both values for each pair N and B.

**中文詳細描述：** 輸入 N 與進位基底 B；要計算 N! 在 B 進位表示下末尾有幾個零，以及總共有幾位。程式分解 B 的質因數並用勒讓德公式找 N! 中各因子的數量，尾零取可組成 B 的最少組數；位數則由對數和求得並輸出兩值。

<a id="uva-10061_how-many-zeros-and-how-many-digits-pr"></a>

### UVa 10061 — How many zeros and how many digits／N! 在 B 進位下的末尾零與位數

- 原始碼：[10061_how-many-zeros-and-how-many-digits-pr.c](10061_how-many-zeros-and-how-many-digits-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：math, number-theory, logarithms

**English description:** Compute number of trailing zeros and total digits of N! represented in base B.

**中文詳細描述：** 計算大數階乘 N! 在 B 進位下的末尾連續零的個數，以及其在 B 進位下的總位數長度。

**English approach:** Zeros: Legendre formula on prime factors of B. Digits: floor(sum_{k=1}^N log_B(k)) + 1.

**中文解題思路：** 末尾零由 B 的質因數分解各因數在 N! 中的冪次除以其在 B 中的指數取最小值；總位數由以 B 為底的對數和加 1 求解。 ==========================================================================


<a id="uva-10062_tell-me-the-frequencies"></a>
### UVa 10062 — Tell Me the Frequencies!／告訴我頻率！

- 原始碼：[10062_tell-me-the-frequencies.c](10062_tell-me-the-frequencies.c)
- 演算法：ASCII 次數統計、多鍵排序（Frequency Counting, Sorting）

**English description:** For each input line, count the frequency of every character. Print ASCII codes by increasing frequency and, for equal frequencies, by decreasing ASCII code.

**中文詳細描述：** 輸入多行文字，每行獨立統計各 ASCII 字元出現次數。輸出只列出出現過的字元代碼與次數，先按次數由少到多，次數相同時按 ASCII 碼由大到小排列，測資間依格式留空行。

<a id="uva-10063_knuths_permutation"></a>

### UVa 10063 — Knuth's Permutation／高德納全排列產生法

- 原始碼：[10063_knuths_permutation.c](10063_knuths_permutation.c)
- 難度：Easy
- 演算法：recursion, permutations

**English description:** Generate all permutations of a string by successively inserting each character into all possible positions.

**中文詳細描述：** 依照高德納算法，依序將字串中的每個字元插入到目前排列的所有可能位置，輸出全排列。

**English approach:** Recursive insertion: start with 1-char prefix, insert 2nd char at index 0 and 1, then 3rd char at 0, 1, 2, etc.

**中文解題思路：** 遞歸插入：從首字元開始，下一字元分別插入前綴的各個位置，直到長度達到原字串長度。 ==========================================================================


<a id="uva-10065_useless-tile-packers"></a>

### UVa 10065 — Useless Tile Packers／無用瓷磚包裝 (多邊形與凸包面積浪費率)

- 原始碼：[10065_useless-tile-packers.c](10065_useless-tile-packers.c)
- 難度：Medium
- 演算法：geometry, convex-hull, polygon-area

**English description:** Calculate percentage of wasted space when packing a polygon tile into a container shaped as its convex hull.

**中文詳細描述：** 計算將任意形狀的瓷磚放入其凸包形狀的包裝盒時，所浪費空間的百分比 ((凸包面積 - 瓷磚面積) / 凸包面積 * 100%)。

**English approach:** Compute tile polygon area using shoelace formula. Find convex hull using Graham scan / Monotone chain, compute hull area, return (A_hull - A_tile) / A_hull * 100%.

**中文解題思路：** 以鞋帶公式求原多邊形面積，求其凸包並計算凸包面積，兩者之差除以凸包面積即為浪費百分比。 ==========================================================================


<a id="uva-10066_the-twin-towers"></a>
### UVa 10066 — The Twin Towers／雙塔

- 原始碼：[10066_the-twin-towers.c](10066_the-twin-towers.c)
- 演算法：最長共同子序列、動態規劃（LCS, Dynamic Programming）

**English description:** Two towers are represented by sequences of tile types. Find the maximum number of tiles that can be kept in the same relative order in both towers.

**中文詳細描述：** 輸入兩座塔由下而上或依序排列的磁磚編號；任務是在不改變各自相對順序下，找出兩序列可共同保留的最大磁磚數。程式建立經典 LCS 二維 DP，輸出每組案例的最大共同子序列長度。

<a id="uva-10067_playing-with-wheels"></a>

### UVa 10067 — Playing with Wheels／數字轉輪密碼鎖避障最短步數 BFS

- 原始碼：[10067_playing-with-wheels.c](10067_playing-with-wheels.c)
- 難度：UVa Star 2
- 演算法：graph, bfs

**English description:** Find the minimum button presses to reach target 4-digit wheel configuration from initial, avoiding forbidden states.

**中文詳細描述：** 四位數字轉輪每步可將任一位往上或往下轉動一格 (0-9 循環)，求避開所有禁手狀態到達目標密碼之最少步數。

**English approach:** Breadth-First Search on state graph of 10000 configurations. Each configuration has 8 transitions (+1 and -1 on each of 4 dials).

**中文解題思路：** 在 10000 個狀態空間上執行 BFS：每個狀態有 8 種轉動後繼狀態，以陣列標記禁手與走訪步數。 ==========================================================================


<a id="uva-10069_distinct-subsequences-bigint"></a>
### UVa 10069 — Distinct Subsequences／不同子序列

- 原始碼：[10069_distinct-subsequences-bigint.c](10069_distinct-subsequences-bigint.c)
- 演算法：子序列計數、大整數動態規劃（Big Integer DP）

**English description:** Count the number of ways a target string appears as a subsequence of a source string. Because the count can exceed ordinary integer ranges, additions must preserve arbitrary precision.

**中文詳細描述：** 輸入來源字串與目標字串；可從來源刪除任意字元但不可改變剩餘順序，任務是計算得到目標的不同選取方式。完整作法需以一維滾動 DP 更新各目標前綴的計數，並用大整數加法保存與輸出答案

<a id="uva-10069_distinct-subsequences-bigint-pr"></a>

### UVa 10069 — Distinct Subsequences (BigInt)／不同子序列大數 DP

- 原始碼：[10069_distinct-subsequences-bigint-pr.c](10069_distinct-subsequences-bigint-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：dynamic-programming, big-integer

**English description:** Number of occurrences of T as a subsequence in S with big integer.

**中文詳細描述：** 大整數計算字串 T 在 S 中作為子序列出現的相異次數。

**English approach:** 1D rolling array DP with big integer addition.

**中文解題思路：** 滾動陣列 DP，轉移時進行高精度大數加法。 ==========================================================================


<a id="uva-10069_dp_distinct-subsequences"></a>
### UVa 10069 — Distinct Subsequences／不同子序列計數（雙層 DP 版）

- 原始碼：[10069_dp_distinct-subsequences.c](10069_dp_distinct-subsequences.c)
- 演算法：字串動態規劃、子序列計數（Dynamic Programming, Subsequence Counting）

**English description:** Count how many distinct ways a target string can be obtained as a subsequence of a source string while preserving character order. Dynamic programming accumulates counts for prefixes of both strings.

**中文詳細描述：** 輸入來源字串 S 與目標字串 T；任務是計算從 S 刪除若干字元且保留相對順序後，能形成 T 的方法數。以兩字串前綴建立二維計數 DP：不選取來源字元時沿用上一列計數，字元相同時再加上匹配前一個目標前綴的方法數。答案可能超過內建整數範圍，需以大整數加法保存並輸出。

<a id="uva-10070_leap-year-or-not-leap-year-and"></a>
### UVa 10070 — Leap Year or Not Leap Year and...／閏年、平年，還有……

- 原始碼：[10070_leap-year-or-not-leap-year-and.c](10070_leap-year-or-not-leap-year-and.c)
- 演算法：大整數字串取模、整除判定（Big Integer, Divisibility）

**English description:** Classify very large year numbers as leap years, huluculu festival years, and bulukulu festival years according to their divisibility rules. Print all applicable labels or the ordinary-year message.

**中文詳細描述：** 輸入可能超出整數型別的年份字串；依西曆規則判斷閏年，並檢查是否符合 huluculu 與 bulukulu 節慶年的整除條件。一個年份可能同時有多種標記；程式對字串逐位取模後輸出所有成立類別，皆不成立則輸出普通年。

<a id="uva-10071_back-to-high-school-physics"></a>
### UVa 10071 — Back to High School Physics／重返高中物理

- 原始碼：[10071_back-to-high-school-physics.c](10071_back-to-high-school-physics.c)
- 演算法：等加速度公式（Math, Physics）

**English description:** Given the velocity v at time t for a symmetric constant-acceleration motion setup, compute the displacement over the corresponding interval 2t as 2vt.

**中文詳細描述：** 每行輸入速度 v 與時間 t；依題目所描述的等加速度關係，要求從對稱時間區間得到位移。程式直接套用 S = 2vt，使用整數運算並逐行輸出位移。

<a id="uva-10074_take-the-land"></a>
### UVa 10074 — Take the Land／攻占土地

- 原始碼：[10074_take-the-land.c](10074_take-the-land.c)
- 演算法：最大零矩形、直方圖、單調堆疊（Histogram, Monotonic Stack）

**English description:** Given a binary matrix, find the largest axis-aligned rectangular area containing only zero-valued cells and print its area.

**中文詳細描述：** 輸入由 0 與 1 組成的矩陣；要找完全由 0 構成、邊與矩陣平行的最大矩形。程式逐列累積每欄連續零的高度，把每列轉成最大直方圖矩形問題並以單調堆疊求解，最後輸出全域最大面積。

<a id="uva-10077_the-stern-brocot-number-system"></a>

### UVa 10077 — The Stern-Brocot Number System／Stern-Brocot 樹二分查找路徑

- 原始碼：[10077_the-stern-brocot-number-system.c](10077_the-stern-brocot-number-system.c)
- 難度：UVa Star 2
- 演算法：binary-search, math

**English description:** Find the path of Left ('L') and Right ('R') branch choices in the Stern-Brocot tree to reach a given fraction M/N.

**中文詳細描述：** 給定最簡真分數或假分數 M/N，求出在 Stern-Brocot 二元樹中自根節點 1/1 到達該分數的左右分支出路徑 (L/R 字串)。

**English approach:** Binary search on mediants (a+c)/(b+d). If target < mediant, output 'L' and update right boundary; else output 'R'.

**中文解題思路：** 利用中間分數 (a+c)/(b+d) 進行二分搜尋：目標較小則輸出 'L' 並更新右邊界，目標較大則輸出 'R' 並更新左邊界。 ==========================================================================


<a id="uva-10078_the-art-gallery"></a>

### UVa 10078 — The Art Gallery／美術館警戒盲點 (多邊形凸性判定)

- 原始碼：[10078_the-art-gallery.c](10078_the-art-gallery.c)
- 難度：Medium
- 演算法：geometry, convex-polygon, cross-product

**English description:** Determine if a polygon representing an art gallery has critical points (not completely convex).

**中文詳細描述：** 判定表示美術館平面的多邊形是否不是嚴格凸多邊形（即是否存在視覺盲點的臨界點）。

**English approach:** Calculate cross products of consecutive directed edges (p_{i+1} - p_i) x (p_{i+2} - p_{i+1}). If any sign change occurs, it is non-convex.

**中文解題思路：** 計算相鄰邊的二維向量叉積，若所有叉積同號則為凸多邊形（無盲點）；若出現不同符號則非凸（存在盲點）。 ==========================================================================


<a id="uva-10079_pizza-cutting"></a>
### UVa 10079 — Pizza Cutting／切披薩

- 原始碼：[10079_pizza-cutting.c](10079_pizza-cutting.c)
- 演算法：組合數學、封閉公式（Combinatorics）

**English description:** Determine the maximum number of regions into which a pizza can be divided by N straight cuts, assuming cuts are placed optimally.

**中文詳細描述：** 輸入直線切割次數 N；每條新切線若與先前切線在披薩內各自相交且沒有三線共點，就能新增最多區塊。程式使用最大區塊數公式 N(N+1)/2+1，以寬整數計算並輸出答案。

<a id="uva-10080_gopher-ii"></a>

### UVa 10080 — Gopher II／地鼠進洞 II

- 原始碼：[10080_gopher-ii.c](10080_gopher-ii.c)
- 難度：Medium
- 演算法：graph, bipartite-matching, max-flow

**English description:** Find the minimum number of gophers that can be caught by a hawk before reaching gopher holes within time limit.

**中文詳細描述：** 在老鷹捕食前，每隻地鼠在時間限制內只能進入距離允許的洞，求最少會被抓幾隻地鼠（即總地鼠數減去最大二分匹配數）。

**English approach:** Model as Maximum Bipartite Matching between gophers and holes where edge exists if dist <= s * v. Answer = n - max_matching.

**中文解題思路：** 以匈牙利演算法求地鼠與洞穴的最大二分圖匹配，答案即為地鼠總數減去最大匹配數。 ==========================================================================


<a id="uva-10081_tight-words"></a>

### UVa 10081 — Tight Words／緊湊單詞機率 (相鄰數位差不超過1的DP)

- 原始碼：[10081_tight-words.c](10081_tight-words.c)
- 難度：Easy
- 演算法：dp, probability

**English description:** A word of length n on alphabet {0..k} is tight if adjacent digits differ by at most 1. Find percentage of tight words.

**中文詳細描述：** 長度為 n 且字母取自 {0..k} 的單詞中，若相鄰數字差值絕對值不超過 1 則稱為緊湊單詞，求緊湊單詞所佔百分比。

**English approach:** DP state dp[len][digit] = probability ending in digit. dp[len][d] = (dp[len-1][d-1] + dp[len-1][d] + dp[len-1][d+1]) / (k + 1).

**中文解題思路：** 機率動態規劃：dp[len][d] 表示當前末尾為 d 的機率，由上一長度相差不超過 1 的數位轉移除以 (k+1)。 ==========================================================================


<a id="uva-10082_wertyu"></a>
### UVa 10082 — WERTYU／鍵盤錯位解碼

- 原始碼：[10082_wertyu.c](10082_wertyu.c)
- 演算法：鍵盤映射、字串轉換（String Mapping）

**English description:** A typist's hands were shifted one key to the right on a QWERTY keyboard. Decode each input character by replacing it with the key immediately to its left, preserving spaces and line breaks.

**中文詳細描述：** 輸入因手指在 QWERTY 鍵盤上向右錯一格而打出的文字；每個可見按鍵都應替換成鍵盤排列中左邊相鄰的按鍵。程式在固定鍵盤字串中查找並映射字元，空白與換行照原格式輸出。

<a id="uva-10083_division"></a>
### UVa 10083 — Division／除法

- 原始碼：[10083_division.c](10083_division.c)
- 演算法：數論、對數位數估計（Number Theory, Logarithm）

**English description:** For given t, a, and b, determine whether (t^a - 1) / (t^b - 1) is an integer with fewer than 100 decimal digits, and print the value or the required diagnostic message.

**中文詳細描述：** 輸入 t、a、b，考察幾何級數形式 (t^a-1)/(t^b-1)。程式先以 a 是否可被 b 整除判斷結果是否為整數，再用對數估計位數是否達到 100；只有通過條件才計算並輸出值，否則輸出題目指定訊息。

<a id="uva-10090_marbles"></a>

### UVa 10090 — Marbles／彈珠

- 原始碼：[10090_marbles.c](10090_marbles.c)
- 難度：Medium
- 演算法：math, extended-gcd, diophantine-equation

**English description:** Pack n marbles into two types of boxes (box 1 holds n1 cost c1; box 2 holds n2 cost c2) with minimum total cost.

**中文詳細描述：** 將 n 顆彈珠裝入兩種盒子中（盒子 1 容量 n1 費用 c1，盒子 2 容量 n2 費用 c2），求總費用最小的裝盒方案。

**English approach:** Solve linear Diophantine equation n1*m1 + n2*m2 = n using Extended Euclidean Algorithm, and optimize cost along parameter t.

**中文解題思路：** 利用擴展歐幾里得演算法求解不定方程 n1*m1 + n2*m2 = n，並沿整數參數 t 尋找最小成本。 ==========================================================================


<a id="uva-10092_the-problem-with-the-problem-setter"></a>

### UVa 10092 — The Problem with the Problem Setter／出題者的難題 (最大流/二分匹配題庫分類)

- 原始碼：[10092_the-problem-with-the-problem-setter.c](10092_the-problem-with-the-problem-setter.c)
- 難度：Medium
- 演算法：network-flow, dinic, bipartite-matching

**English description:** Assign available problems to categories matching each category's required count, where each problem can only belong to one category.

**中文詳細描述：** 將題庫中的題目分配給各競賽類別並滿足各類別所需的題目數量，每道題最多只能分配給一個類別。

**English approach:** Bipartite matching / max flow: Source -> problems (cap 1), problem -> category (cap 1), category -> Sink (cap req[c]). Check if max_flow == total_needed.

**中文解題思路：** 最大流建模：源點連題目（容量 1），題目連所屬類別（容量 1），類別連匯點（容量為需求數），判斷最大流是否等於總需求題目數。 ==========================================================================


<a id="uva-10093_an-easy-problem"></a>
### UVa 10093 — An Easy Problem!／一個簡單問題！

- 原始碼：[10093_an-easy-problem.c](10093_an-easy-problem.c)
- 演算法：進位制、數位和整除性（Base Conversion, Number Theory）

**English description:** Given a number written with digits 0-9, A-Z, and a-z, find the smallest base from 2 through 62 in which the represented value is divisible by base minus one, or report that no base works.

**中文詳細描述：** 輸入使用數字與大小寫英文字母表示的數字字串；每個字元對應 0 至 61，因此候選基底必須大於最大數位值。利用一個數對 base-1 的餘數等於數位和餘數，程式由最小合法基底逐一檢查並輸出第一個成功者，皆失敗則輸出不可能訊息。

<a id="uva-10098_generating-fast"></a>
### UVa 10098 — Generating Fast, Sorted Permutation／快速產生排序排列

- 原始碼：[10098_generating-fast.c](10098_generating-fast.c)
- 演算法：全排列、下一排列（Permutation, Next Permutation）

**English description:** Generate every distinct permutation of each input string in lexicographic order, including correct handling of repeated characters.

**中文詳細描述：** 輸入多個字串；每個字串都要列出所有不重複排列，並按字典序輸出。程式先排序字元得到最小排列，再反覆尋找右側遞減區、交換樞紐與下一個較大字元並反轉後綴，以 next permutation 依序產生結果。

<a id="uva-10099_the-tourist-guide"></a>
### UVa 10099 — The Tourist Guide／觀光導遊

- 原始碼：[10099_the-tourist-guide.c](10099_the-tourist-guide.c)
- 演算法：最大瓶頸路徑、Floyd–Warshall（Widest Path）

**English description:** Roads between cities have passenger capacities. Find a route maximizing the minimum road capacity, reserve one seat for the guide, and compute the minimum trips needed to carry all tourists.

**中文詳細描述：** 輸入城市道路及每條道路的載客上限，再給起點、終點與旅客人數。程式用 max-min Floyd–Warshall 求兩地間瓶頸容量最大的路徑；每車須保留一個導遊座位，因此以容量減一後向上取整，輸出最少趟數。

<a id="uva-10099_the-tourist-guide-pr"></a>

### UVa 10099 — The Tourist Guide／導遊帶團運載 (瓶頸容量路徑與最少趟數)

- 原始碼：[10099_the-tourist-guide-pr.c](10099_the-tourist-guide-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：graph, floyd-warshall, shortest-path

**English description:** Find path maximizing bus capacity minus 1 (guide seat), and find minimum trips to transport total tourists.

**中文詳細描述：** 求兩景點間巴士載客量最大的路徑 (需扣除 1 位導遊座位)，並計算運送總遊客數所需的最少來回趟數。

**English approach:** Floyd-Warshall maximin path. Trips needed = ceil(tourists / (max_cap - 1)).

**中文解題思路：** 以 Floyd-Warshall 求最大瓶頸容量 C，單趟有效載客人數為 C - 1，最少趟數為 (總遊客數 + C - 2) / (C - 1)。 ==========================================================================
