# UVa Volume 006

本卷收錄 35 份 C 解答，涵蓋 29 個 UVa 題號，以下依題號排序。

<a id="uva-608_counterfeit-dollar"></a>

### UVa 608 — Counterfeit Dollar／假幣辨識 (天平三次稱重邏輯推理)

- 原始碼：[608_counterfeit-dollar.c](608_counterfeit-dollar.c)
- 難度：UVa Star 2
- 演算法：logic, simulation, brute-force

**English description:** Given 3 balance scale weighings of 12 coins, deduce which coin is counterfeit and whether it is heavy or light.

**中文詳細描述：** 12 枚銀幣中恰有一枚假幣 (重量較重或較輕)。給定天平 3 次秤重記錄，推理出哪一枚是假幣且偏重或偏輕。

**English approach:** Test each of 12 coins being (Heavy or Light) = 24 hypotheses. Check which hypothesis satisfies all 3 weighings perfectly.

**中文解題思路：** 枚舉 24 種可能性 (12 種硬幣 x 2 種輕重假設)，逐一模擬 3 次天平傾斜狀態，恰好完全吻合者即為唯一解答。 ==========================================================================


<a id="uva-610_street-directions"></a>

### UVa 610 — Street Directions／街道單向化 (橋與強連通定向DFS)

- 原始碼：[610_street-directions.c](610_street-directions.c)
- 難度：Medium
- 演算法：graph, dfs, bridge, tarjan

**English description:** Convert as many two-way streets to one-way as possible while keeping all vertices reachable from one another.

**中文詳細描述：** 在保證全圖強連通的前提下，將盡可能多的雙向街道改為單向街道（非橋邊定向，橋邊保留雙向）。

**English approach:** Tarjan's bridge-finding algorithm. Direct DFS tree edges in traversal direction, back-edges towards ancestor, keep bridges bidirectional.

**中文解題思路：** Tarjan 演算法找橋：DFS 樹邊沿搜索方向定向，返祖邊沿向上方向定向，橋邊保留雙向通行。 ==========================================================================


<a id="uva-612_dna-sorting"></a>

### UVa 612 — DNA Sorting／DNA 逆序數穩定排序

- 原始碼：[612_dna-sorting.c](612_dna-sorting.c)
- 難度：UVa Star 1
- 演算法：sorting, inversion-number, string

**English description:** Sort DNA strings in ascending order of their sortedness (number of inversion pairs). Stable sort required.

**中文詳細描述：** 依照 DNA 字串的逆序數 (即未排序程度) 由小到大進行穩定排序。

**English approach:** Count inversions for each string via O(N^2) double loop. Use stable sort (mergesort or stable bubble sort).

**中文解題思路：** 雙重迴圈統計每條 DNA 字串的逆序對數量，結合原始輸入索引進行穩定排序 (相等時維持原先順序)。 ==========================================================================


<a id="uva-615_is-it-a-tree"></a>

### UVa 615 — Is It A Tree?／這是一棵樹嗎？

- 原始碼：[615_is-it-a-tree.c](615_is-it-a-tree.c)
- 難度：Medium
- 演算法：graph, tree-verification

**English description:** Determine whether a given directed graph is a rooted tree (exactly one root with in-degree 0, every other node in-degree 1, connected).

**中文詳細描述：** 判斷給定的有向圖是否為一棵有根樹（恰好一個入度為 0 的根節點，其餘節點入度均為 1，且連通無環）。

**English approach:** Check: 0 or 1 edge empty tree is valid. Max in-degree <= 1. Exactly one node with in-degree 0. Total edges == total nodes - 1.

**中文解題思路：** 空圖為樹；檢查每個節點入度不可超過 1；恰好有一個入度為 0 的根節點；邊數必等於節點數減 1 且全圖連通。 ==========================================================================


<a id="uva-616_coconuts-revisited"></a>

### UVa 616 — Coconuts, Revisited／椰子難題 (整數整除模擬)

- 原始碼：[616_coconuts-revisited.c](616_coconuts-revisited.c)
- 難度：Easy
- 演算法：math, simulation

**English description:** N men and 1 monkey divide coconuts: each person divides remaining into N parts, gives 1 to monkey, hides his part. Morning division leaves 0 for monkey.

**中文詳細描述：** N 個人與 1 隻猴子分椰子：每人各自將椰子等分 N 堆給猴子 1 顆並藏起 1 堆，隔天早晨恰好能等分給 N 人（猴子分得 0 顆），求最大人數 N。

**English approach:** Try candidate number of people p downwards from ceil(sqrt(N)) down to 2. Simulate p divisions then 1 final division.

**中文解題思路：** 自 sqrt(total) + 1 向下枚舉人數 p，模擬 p 輪「減 1 後整除 p 且拿走 1/p」，隔日再整除 p，若皆合法即為最大人數。 ==========================================================================


<a id="uva-621_secret-research"></a>

### UVa 621 — Secret Research／秘密實驗結果加密辨識

- 原始碼：[621_secret-research.c](621_secret-research.c)
- 演算法：字串模式比對（string, pattern matching）

**English description:** Each decimal-looking result string belongs to one of four experiment classes. Print `+` for the exact values `1`, `4`, or `78`; `-` for strings ending in `35`; `*` for strings beginning with `9` and ending in `4`; and `?` for strings beginning with `190`.

**中文詳細描述：** 輸入先給測試筆數，再逐行給一個結果字串。若字串恰為 `1`、`4`、`78`，輸出 `+`；若末兩字元是 `35`，輸出 `-`；若首字元為 `9` 且末字元為 `4`，輸出 `*`；若以 `190` 開頭則輸出 `?`。每筆只輸出一個分類符號。

<a id="uva-621_secret-research-pr"></a>

### UVa 621 — Secret Research／秘密實驗結果加密模式解密

- 原始碼：[621_secret-research-pr.c](621_secret-research-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, pattern-matching

**English description:** Given encrypted result string, determine encryption type: '+' (positive), '-' (negative), '*' (failed), '?' (not completed).

**中文詳細描述：** 根據字串前後綴判斷實驗結果：'1', '4', '78' 判定為 '+'；結尾 '35' 判定為 '-'；開頭 '9' 結尾 '4' 判定為 '*'；開頭 '190' 判定為 '?'。

**English approach:** Check string length and prefix/suffix using strcmp and string slicing.

**中文解題思路：** 字串模式比對：若為 "1", "4", "78" 輸出 '+'；末兩位為 "35" 輸出 '-'；首為 '9' 尾為 '4' 輸出 '*'；其餘為 '?'。 ==========================================================================


<a id="uva-623_500"></a>

### UVa 623 — 500!／500 階乘大數乘法

- 原始碼：[623_500.c](623_500.c)
- 演算法：高精度整數乘法（big integer, factorial）

**English description:** For each input `N`, print the exact decimal value of `N!` in the format `N!` followed by the number on the next line. Because the result exceeds built-in integer types, store decimal digits in an array and multiply the big integer by each successive factor.

**中文詳細描述：** 每行輸入 `N`，要完整輸出 `N!` 的所有十進位位數，格式為先印 `N!`，下一行印結果。內建整數不足以容納答案，因此以陣列保存各位數，從 2 到 `N` 逐次做大數乘法並處理進位；每筆資料都輸出精確值。

<a id="uva-623_500-pr"></a>

### UVa 623 — 500!／500 階乘大數乘法

- 原始碼：[623_500-pr.c](623_500-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, big-integer

**English description:** For each input `N`, print the exact decimal value of `N!` in the format `N!` followed by the number on the next line. Because the result exceeds built-in integer types, store decimal digits in an array and multiply the big integer by each successive factor.

**中文詳細描述：** 每行輸入 `N`，要完整輸出 `N!` 的所有十進位位數，格式為先印 `N!`，下一行印結果。內建整數不足以容納答案，因此以陣列保存各位數，從 2 到 `N` 逐次做大數乘法並處理進位；每筆資料都輸出精確值。

**English approach:** Big integer multiplication array.

**中文解題思路：** 陣列模擬高精度乘法。 ==========================================================================


<a id="uva-624_cd"></a>

### UVa 624 — CD／錄音帶容量最大化 (0/1 背包與曲目路徑還原)

- 原始碼：[624_cd.c](624_cd.c)
- 難度：UVa Star 1
- 演算法：dynamic-programming, knapsack, backtracking

**English description:** Given tape length N and track durations, select subset of tracks to maximize total time without exceeding N.

**中文詳細描述：** 在給定錄音帶容量 N 的限制下，挑選曲目使得總播放時間最接近 N 且不超額，並輸出所挑選的曲目清單。

**English approach:** 0/1 Knapsack dynamic programming with path tracking, or backtracking DFS since number of tracks <= 20.

**中文解題思路：** 因曲目數不超過 20，可以 0/1 背包 DP 或回溯搜尋求最優容量，並記錄選取狀態還原具體曲目。 ==========================================================================


<a id="uva-627_the-net"></a>

### UVa 627 — The Net／網路最短路徑路由

- 原始碼：[627_the-net.c](627_the-net.c)
- 難度：Easy
- 演算法：graph, bfs, shortest-path

**English description:** Find the shortest routing path between routers in an unweighted communication network.

**中文詳細描述：** 在無權路由器通訊網路中尋找兩節點之間的最短路徑並輸出路徑節點序列。

**English approach:** BFS to find shortest hop distance, tracking predecessor pointers to reconstruct path from destination back to source.

**中文解題思路：** 無權圖 BFS 遍歷求最短路，記錄父節點指標，由終點沿父節點回溯輸出路徑。 ==========================================================================


<a id="uva-628_passwords"></a>

### UVa 628 — Passwords／密碼字典與規則生成回溯搜尋

- 原始碼：[628_passwords.c](628_passwords.c)
- 難度：UVa Star 1
- 演算法：backtracking, string

**English description:** Given a dictionary of words and password rules containing '#' (word from dict) and '0' (digit 0-9), generate all valid passwords.

**中文詳細描述：** 給定單詞字典與密碼規則字串 (包含 '#' 代表替換字典單詞，'0' 代表替換數字 0-9)，窮舉生成所有可能密碼。

**English approach:** Recursive backtracking: at '#' branch over all dictionary words; at '0' branch over digits '0' through '9'.

**中文解題思路：** 深度優先回溯生成：遇到 '#' 逐一嘗試字典中所有單詞，遇到 '0' 依序遞迴填入 0 到 9 十個數位。 ==========================================================================


<a id="uva-630_anagrams_ii"></a>

### UVa 630 — Anagrams (II)／字彙變位詞檢索

- 原始碼：[630_anagrams_ii.c](630_anagrams_ii.c)
- 難度：Easy
- 演算法：string, sorting, hash-table

**English description:** Given a vocabulary list, find and list all vocabulary words that are anagrams of a given query word.

**中文詳細描述：** 給定字彙字典，對於每次查詢單字，輸出字典中所有由相同字母組成的變位詞（保持字典中的出現順序）。

**English approach:** Sort characters of words to create signatures or count character frequency distributions to test anagram equivalence.

**中文解題思路：** 統計 26 個英文字母頻率分佈或字母排序簽名，比對查詢單字與字典中單字是否為變位詞。 ==========================================================================


<a id="uva-634_polygon"></a>

### UVa 634 — Polygon／點在多邊形內判定 (射線交叉法)

- 原始碼：[634_polygon.c](634_polygon.c)
- 難度：Easy
- 演算法：geometry, point-in-polygon, ray-casting

**English description:** Determine if a point lies strictly inside an orthogonal/general polygon using ray-casting algorithm.

**中文詳細描述：** 使用射線法判斷指定點是否落在任意多邊形內部（輸出 T 或 F）。

**English approach:** Cast a ray to the right. Count edge crossings: if total crossings is odd, point is inside; if even, outside.

**中文解題思路：** 由測試點向右引出水平射線，統計多邊形各邊與射線的交點個數，奇數在多邊形內，偶數在多邊形外。 ==========================================================================


<a id="uva-636_squares-base"></a>

### UVa 636 — Squares／完全平方數的基底測試

- 原始碼：[636_squares-base.c](636_squares-base.c)
- 難度：UVa Star 1
- 演算法：math, base-conversion, number-theory

**English description:** Find the smallest base B (B > max_digit) such that the string represents a perfect square in base B.

**中文詳細描述：** 求最小進位 B (大於字串中最大字元值)，使得該字串在 B 進位下轉換為十進位後恰為完全平方數。

**English approach:** Determine min valid base. Loop B from min_base to 100, convert to decimal, check if sqrt(val) is exact integer.

**中文解題思路：** 求字元最大值確定基底起點，從 min_base 逐一遞增至 100 計算十進位值，以 sqrt 判定是否為完全平方數。 ==========================================================================


<a id="uva-637_booklet-printing"></a>

### UVa 637 — Booklet Printing／小冊子雙面列印頁碼排列模擬

- 原始碼：[637_booklet-printing.c](637_booklet-printing.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Simulate folding sheets of paper into a booklet: determine page numbers printed on front and back of each sheet for an N-page document.

**中文詳細描述：** 模擬將紙張對折裝訂成小冊子：計算包含 N 頁的文件在每張紙正面與背面左右兩側應列印的頁碼 (不足處補 Blank)。

**English approach:** Total booklet slots = 4 * ceil(N / 4). Pages 1..N arranged on front/back: Sheet k Front has (Total - 2k + 2, 2k - 1), Back has (2k, Total - 2k + 1).

**中文解題思路：** 總格數為 4 的最小倍數 4*ceil(N/4)，第 k 張紙正面為 (總頁-2k+2, 2k-1)，背面為 (2k, 總頁-2k+1)，頁碼大於 N 標示為 Blank。 ==========================================================================


<a id="uva-639_dont-get-hooked"></a>

### UVa 639 — Don't Get Rooked／不要被城堡吃掉 (帶障礙牆之城堡最大放置)

- 原始碼：[639_dont-get-hooked.c](639_dont-get-hooked.c)
- 難度：UVa Star 1
- 演算法：backtracking, brute-force

**English description:** Place maximum number of rooks on n x n board with walls 'X' such that no two rooks can attack each other.

**中文詳細描述：** 在 n x n (n <= 4) 的棋盤上放置互不攻擊的城堡。牆壁 'X' 會阻隔城堡的攻擊視線，求最大擺放數量。

**English approach:** Backtracking search: for each empty cell, place rook if not seen by another rook in 4 ray directions; recurse and find max.

**中文解題思路：** 因棋盤最大僅 4x4，直接回溯搜尋每個方格放或不放，放置前向四個方向掃描檢查在遇牆前是否有其他城堡。 ==========================================================================


<a id="uva-640_self-numbers"></a>

### UVa 640 — Self Numbers／哥倫比亞數 / 自守數篩法

- 原始碼：[640_self-numbers.c](640_self-numbers.c)
- 難度：UVa Star 1
- 演算法：math, sieve

**English description:** Generate all Self Numbers up to 1,000,000 (numbers that cannot be generated by d(n) = n + sum_of_digits(n)).

**中文詳細描述：** 求 1 到 1,000,000 內的所有哥倫比亞數 (無法由 d(n) = n + 各數位和 生成的數)。

**English approach:** Boolean array sieve. For each n from 1 to 10^6, compute d(n) and mark generated[d(n)] = 1. Unmarked are self numbers.

**中文解題思路：** 布林標記篩法：遍歷 1 到 100 萬，計算 d(n) = n + 各數位之和並標記為非自生數，未被標記的即為哥倫比亞數。 ==========================================================================


<a id="uva-642_word-amalgamation"></a>

### UVa 642 — Word Amalgamation／字母異序詞字典查詢

- 原始碼：[642_word-amalgamation.c](642_word-amalgamation.c)
- 難度：UVa Star 1
- 演算法：string, sorting, hash-table

**English description:** Given scrambled word, find all matching dictionary words with exact same letter multiset in alphabetical order.

**中文詳細描述：** 給定被攪亂字母順序的單字，從字典中找出所有具備完全相同字母多重集的單詞，按字典序由小到大輸出。

**English approach:** Sort characters of scrambled word. Compare with pre-sorted signatures of dictionary words.

**中文解題思路：** 將查詢單字字元排序獲取簽名，與字典中預先排好字元的單詞簽名進行逐一比對，匹配則輸出。 ==========================================================================


<a id="uva-644_immediate-decodability"></a>

### UVa 644 — Immediate Decodability／前綴碼即時可譯性檢測 (Trie / Prefix Code)

- 原始碼：[644_immediate-decodability.c](644_immediate-decodability.c)
- 難度：UVa Star 1
- 演算法：string, trie, prefix-code

**English description:** Determine if a set of binary codes is immediately decodable (no code word is a prefix of any other code word).

**中文詳細描述：** 判定二進位編碼集合是否具備即時可譯性 (即任何編碼皆不可為其他編碼的前綴，前綴碼判定)。

**English approach:** Pairwise prefix check: for each pair (i, j), check if strncmp(c[i], c[j], len) == 0.

**中文解題思路：** 兩兩比對字串前綴：若存在某編碼為另一編碼的開頭前綴，則判定不具即時可譯性。 ==========================================================================


<a id="uva-657_the-die-is-cast"></a>

### UVa 657 — The die is cast／擲骰子點數雙層洪水填充判定

- 原始碼：[657_the-die-is-cast.c](657_the-die-is-cast.c)
- 難度：UVa Star 2
- 演算法：graph, flood-fill, dfs

**English description:** Given image with thrown dice ('*') and dots ('X'), count dice and dots on each die, output sorted dot numbers.

**中文詳細描述：** 解析圖像中散落的骰子 ('*') 與點數 ('X')：以雙層 DFS 先圈出整顆骰子，內部 DFS 統計骰子點數並排序輸出。

**English approach:** Outer DFS finds connected '*' components (dice). Inner DFS counts distinct 'X' connected components (dots).

**中文解題思路：** 外層 DFS 尋找連通的 '*' 區塊定位整顆骰子；內層 DFS 統計該骰子內部連通的 'X' 連通塊個數得出點數。 ==========================================================================


<a id="uva-661_blowing-fuses"></a>

### UVa 661 — Blowing Fuses／保險絲熔斷模擬

- 原始碼：[661_blowing-fuses.c](661_blowing-fuses.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Simulate device toggles with power consumption. Determine if fuse blows (capacity C exceeded) and find max power reached.

**中文詳細描述：** 模擬電器開關切換過程中的功率總和：若累積功率超出保險絲負載 C 則熔斷；否則求過程中達到的最大功率瓦數。

**English approach:** Maintain device states (on/off) and current total power. Track running maximum; check against capacity C.

**中文解題思路：** 以布林陣列維護各電器開關狀態，每次操作累計功率，維護歷史最高功率並隨時檢查是否超過容量 C。 ==========================================================================


<a id="uva-665_false_coin"></a>

### UVa 665 — False coin／尋找偽幣

- 原始碼：[665_false_coin.c](665_false_coin.c)
- 難度：Easy
- 演算法：logic, implementation

**English description:** Given weighing results (<, =, >) of coin subsets on a balance scale, determine the unique false coin if possible.

**中文詳細描述：** 天平稱量若干枚硬幣，給出秤重結果（<, =, >），判斷能否唯一確定哪一枚是重量不同的假幣。

**English approach:** Coins appearing in '=' weighings are definitely genuine. Suspect coins must participate in all unequal weighings. Count suspects.

**中文解題思路：** 在 '=' 天平兩側的硬幣皆為真幣；在不平衡天平中未出現的硬幣亦為真幣。統計符合所有不平衡秤重的唯一偽幣候選。 ==========================================================================


<a id="uva-673_parentheses-balance"></a>

### UVa 673 — Parentheses Balance／括號平衡檢驗

- 原始碼：[673_parentheses-balance.c](673_parentheses-balance.c)
- 演算法：堆疊（stack, string）

**English description:** For each line containing parentheses `()` and brackets `[]`, determine whether every opening symbol is closed by the correct type in proper nesting order. The empty string is balanced. Print `Yes` for a balanced line and `No` otherwise.

**中文詳細描述：** 輸入先給測試行數，每行由小括號與中括號構成，也可能是空字串。遇到左括號便推入堆疊；遇到右括號時必須與堆疊頂端種類相同才能配對。若發生不符、提早關閉，或掃描結束仍有未關閉括號就輸出 `No`，全部正確則輸出 `Yes`。

<a id="uva-673_parentheses-balance-pr"></a>

### UVa 673 — Parentheses Balance／括號平衡匹配驗證 (堆疊)

- 原始碼：[673_parentheses-balance-pr.c](673_parentheses-balance-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：stack, string

**English description:** Verify whether parentheses '(' ')' and brackets '[' ']' in string are properly balanced and nested.

**中文詳細描述：** 以堆疊判定字串中的小括號 () 與中括號 [] 是否合法成對平衡且巢狀嵌套。

**English approach:** Stack simulation: push open brackets; on close bracket check stack non-empty and matching top.

**中文解題思路：** 遇到左括號壓入堆疊；遇到右括號檢查堆疊是否為空且棧頂是否為對應的左括號，最後檢查堆疊是否為空。 ==========================================================================


<a id="uva-674_coin-change"></a>

### UVa 674 — Coin Change／找零錢問題

- 原始碼：[674_coin-change.c](674_coin-change.c)
- 演算法：完全背包動態規劃（dynamic programming, coin change）

**English description:** For every input amount, count the unordered combinations of unlimited 1, 5, 10, 25, and 50 cent coins that sum exactly to it. Precompute a one-dimensional unbounded-knapsack table and print the count for each amount.

**中文詳細描述：** 每行輸入一個以分為單位的金額，可任意使用面額 1、5、10、25、50 分硬幣，求剛好湊成該金額的組合數；硬幣選取順序不同不算新方法。依面額由外到內更新 `dp[j] += dp[j-coin]`，預先建立所有答案後逐行輸出計數。

<a id="uva-674_coin-change-pr"></a>

### UVa 674 — Coin Change／零錢兌換方法數 (完全背包 DP)

- 原始碼：[674_coin-change-pr.c](674_coin-change-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：dynamic-programming, coin-change

**English description:** Find number of ways to make change for given cents (up to 7489) using 1, 5, 10, 25, 50 cent coins.

**中文詳細描述：** 給定美分金額 (最多 7489)，計算使用 5 種美幣 (1, 5, 10, 25, 50) 湊齊該金額的方法總數。

**English approach:** Unbounded knapsack DP precomputed up to 7489: dp[j] += dp[j - coin]. Answer queries in O(1).

**中文解題思路：** 完全背包一維動態規劃：dp[j] += dp[j - coin]，預先建表至 7489，詢問時 O(1) 輸出。 ==========================================================================


<a id="uva-679_dropping-balls"></a>

### UVa 679 — Dropping Balls／下落的小球 (滿二元樹二進位路徑映射)

- 原始碼：[679_dropping-balls.c](679_dropping-balls.c)
- 難度：UVa Star 2
- 演算法：binary-tree, math, bit-manipulation

**English description:** Find the final leaf node number of the I-th dropped ball in a full binary tree of depth D.

**中文詳細描述：** 在深度為 D 的滿二元樹中連續投入 I 個球 (遇到開關為 false 往左並切換為 true，否則往右)，求第 I 個球落入的葉節點編號。

**English approach:** Avoid O(I*D) simulation. Determine left/right step directly via parity of (I - 1): odd goes right, even goes left.

**中文解題思路：** 位元奇偶性數學規律：每次下落方向直接由當前是第幾顆球的二進位位元決定，時間複雜度由 O(I) 降至 O(D)。 ==========================================================================


<a id="uva-681_convex-hull-finding"></a>

### UVa 681 — Convex Hull Finding／凸包求取

- 原始碼：[681_convex-hull-finding.c](681_convex-hull-finding.c)
- 難度：Medium
- 演算法：geometry, convex-hull, graham-scan

**English description:** Find the convex hull of a set of 2D points and output vertices in counter-clockwise order starting from lowest-y lowest-x point.

**中文詳細描述：** 求二維點集的凸包頂點，從 y 最小（若相同則 x 最小）的點開始依逆時針順序輸出。

**English approach:** Monotone Chain or Graham Scan: sort points lexicographically, build lower and upper hulls using 2D cross product.

**中文解題思路：** Monotone Chain 演算法：將點依 (x, y) 升序排序，利用二維向量叉積依序構造下凸包與上凸包。 ==========================================================================


<a id="uva-686_goldbachs-conjecture-ii"></a>

### UVa 686 — Goldbach's Conjecture (II)／哥德巴赫猜想拆分對數計數

- 原始碼：[686_goldbachs-conjecture-ii.c](686_goldbachs-conjecture-ii.c)
- 演算法：埃拉托斯特尼篩法、質數對枚舉（number theory, prime sieve）

**English description:** For each even integer, count the distinct unordered pairs of primes whose sum equals that integer. Enumerate only the first prime up to half the target so each pair is counted once, and print the count. Input ends with zero.

**中文詳細描述：** 每筆輸入一個偶數，計算有多少組質數 `p1 ≤ p2` 滿足 `p1 + p2 = 輸入值`。先篩出所需範圍內的質數，再只枚舉不超過目標一半的 `p1`，檢查另一項是否為質數，從而避免正反順序重複計數；逐筆輸出對數，輸入 0 結束。

<a id="uva-686_goldbachs-conjecture-ii-pr"></a>

### UVa 686 — Goldbach's Conjecture (II)／哥德巴赫猜想 (II) 質數對總數統計

- 原始碼：[686_goldbachs-conjecture-ii-pr.c](686_goldbachs-conjecture-ii-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, prime-sieve, number-theory

**English description:** Count the number of distinct prime pairs (p1, p2) with p1 <= p2 such that p1 + p2 = 2n for even 2n < 2^15.

**中文詳細描述：** 計算偶數 2n 表達成兩個質數之和 p1 + p2 = 2n (p1 <= p2) 的相異質數對數量。

**English approach:** Sieve primes up to 2^15 = 32768. Loop p1 from 2 up to n, count pairs where both p1 and (2n - p1) are prime.

**中文解題思路：** 質數篩預處理至 32768，由 2 枚舉質數 p1 至 n，若 2n - p1 亦為質數則計數 +1。 ==========================================================================


<a id="uva-694_the-collatz-sequence"></a>

### UVa 694 — The Collatz Sequence／考拉茲數列上限項數統計

- 原始碼：[694_the-collatz-sequence.c](694_the-collatz-sequence.c)
- 演算法：考拉茲數列模擬（simulation, math）

**English description:** Starting from positive integer `A`, repeatedly halve even values and replace odd values by `3A + 1`. Count terms beginning with the initial value, stopping before a term would exceed limit `L` or after reaching 1. Print the case number, original values, and term count; a pair of negative values terminates input.

**中文詳細描述：** 每組輸入起始正整數 `A` 與上限 `L`。從 `A` 起，偶數除以 2、奇數變成 `3A+1`，並計算未超過 `L` 的序列項數；起始值算一項，若到達 1 即停止，下一項超過上限則不列入。依案例格式輸出原始 `A`、`L` 與項數，負值終止資料。

<a id="uva-694_the-collatz-sequence-pr"></a>

### UVa 694 — The Collatz Sequence／考拉茲序列帶上限步數計算

- 原始碼：[694_the-collatz-sequence-pr.c](694_the-collatz-sequence-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, math

**English description:** Compute number of terms in Collatz sequence generated by A until term becomes 1 or exceeds limit L.

**中文詳細描述：** 計算起始值為 A 的 3n+1 序列項數，直到數值抵達 1 或運算中途數值超出上限 L 為止。

**English approach:** Step-by-step simulation using 64-bit integer. Stop when term == 1 or term > L.

**中文解題思路：** 以 64 位元整數模擬 3n+1 運算流程，當前項超過限制 L 或抵達 1 時終止並統計有效項數。 ==========================================================================


<a id="uva-696_how-many-knights"></a>

### UVa 696 — How Many Knights／棋盤上最多騎士放置數

- 原始碼：[696_how-many-knights.c](696_how-many-knights.c)
- 難度：UVa Star 1
- 演算法：math, chess, greedy

**English description:** Find maximum number of non-attacking knights on an M x N board.

**中文詳細描述：** 求在 M x N 棋盤上互不攻擊的西洋棋騎士的最大擺放數量 (特殊處理 1 列與 2 列棋盤)。

**English approach:** Cases: if min(M, N) == 1, ans = max(M, N); if min(M, N) == 2, blocks of 2x2 with period 4; else ans = (M*N + 1)/2.

**中文解題思路：** 分類討論：若有一邊為 1 則為全放；若有一邊為 2 則以 4 為週期 2x2 區塊交替；一般棋盤黑白棋格著色為 (M*N + 1)/2。 ==========================================================================


<a id="uva-699_the-falling-leaves"></a>

### UVa 699 — The Falling Leaves／落葉堆疊 (二元樹水平投影加權和)

- 原始碼：[699_the-falling-leaves.c](699_the-falling-leaves.c)
- 難度：UVa Star 1
- 演算法：binary-tree, recursion

**English description:** Compute total weight of leaves falling from binary tree onto horizontal positions on the ground.

**中文詳細描述：** 計算二元樹各結點垂直落入地面時，各水平相對位置上的結點權重累積總和。

**English approach:** Recursively parse tree: root at pos 0; left child at pos - 1, right child at pos + 1. Accumulate weights into pos array.

**中文解題思路：** 遞迴解析前序二元樹：根節點位於水平座標 0，左子節點為 pos - 1，右子節點為 pos + 1，累加權重到陣列中並由左至右輸出。 ==========================================================================
