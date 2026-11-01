# UVa Volume 101 題目索引

本卷收錄 60 份 C 解答，涵蓋 54 個 UVa 題號，以下依題號排序。

<a id="uva-10100_longest-match"></a>

### UVa 10100 — Longest Match／最長匹配單字序列 (單字級LCS)

- 原始碼：[10100_longest-match.c](10100_longest-match.c)
- 難度：Medium
- 演算法：dp, lcs, string-parsing

**English description:** Find the length of the longest common subsequence of words between two given texts.

**中文詳細描述：** 求兩段文字中以單字為單位的最長公共子序列 (LCS) 長度。

**English approach:** Tokenize text into words (alphanumeric sequences). Run standard dynamic programming LCS on words.

**中文解題思路：** 以非字母數字字元為邊界將文章分詞，對單字陣列進行標準 LCS 動態規劃。 ==========================================================================


<a id="uva-10101_bangla-numbers"></a>
### UVa 10101 — Bangla Numbers／孟加拉數字

- 原始碼：[10101_bangla-numbers.c](10101_bangla-numbers.c)
- 演算法：遞迴、數值分組格式化（Recursion, Simulation）

**English description:** Convert each nonnegative integer to the Bangla numbering system, using kuti, lakh, hajar, and shata at their proper place values while preserving the required case numbering format.

**中文詳細描述：** 輸入多個非負整數；任務是依孟加拉計數單位把數字拆成 kuti、lakh、hajar、shata 與剩餘部分。程式由大單位遞迴分解，特別處理 kuti 可重複出現的層級，並在每行輸出案例編號與格式化結果。

<a id="uva-10102_the-path-in-the-colored-field"></a>

### UVa 10102 — The path in the colored field／著色棋盤最短抵達最大值 (Minimax 曼哈頓距離)

- 原始碼：[10102_the-path-in-the-colored-field.c](10102_the-path-in-the-colored-field.c)
- 難度：UVa Star 1
- 演算法：brute-force, grid, geometry

**English description:** For all '1's in grid, find distance to closest '3'. Maximize this distance over all '1's.

**中文詳細描述：** 對網格中所有數字 '1' 尋找最近的數字 '3' 的曼哈頓距離，求所有 '1' 到其最近 '3' 的距離的最大值 (Minimax)。

**English approach:** Enumerate each '1' and find min |r1 - r3| + |c1 - c3| to all '3's. Take maximum among all '1's.

**中文解題思路：** 雙重枚舉：記錄所有 '1' 與 '3' 的座標，對每個 '1' 計算其到所有 '3' 的曼哈頓距離最小值，再取全局最大值。 ==========================================================================


<a id="uva-10104_euclid-problem"></a>
### UVa 10104 — Euclid Problem／歐幾里得問題

- 原始碼：[10104_euclid-problem.c](10104_euclid-problem.c)
- 演算法：擴展歐幾里得演算法（Extended Euclidean Algorithm）

**English description:** Given integers A and B, find integers X and Y such that A×X + B×Y equals D, where D is the greatest common divisor of A and B. Print X, Y, and D.

**中文詳細描述：** 每行輸入整數 A、B；除了求最大公因數 D，還要找出貝祖係數 X、Y，使 AX+BY=D。程式以擴展歐幾里得演算法沿除法遞迴回推係數，逐組輸出 X、Y 與 D。

<a id="uva-10105_polynomial-coefficients"></a>

### UVa 10105 — Polynomial Coefficients／多元多項式展開項係數計算

- 原始碼：[10105_polynomial-coefficients.c](10105_polynomial-coefficients.c)
- 難度：UVa Star 1
- 演算法：math, combinatorics

**English description:** Given n and k exponents n_1, n_2, ..., n_k such that sum(n_i) = n, calculate the multinomial coefficient n! / (n_1! * n_2! * ... * n_k!).

**中文詳細描述：** 給定總次數 n 與 k 個項的次數 n_1, ..., n_k (滿足總和為 n)，計算多項式定理展開項之係數 n! / (n_1! * ... * n_k!)。

**English approach:** Precompute factorials 0! to 13!. Compute n! / prod(n_i!).

**中文解題思路：** 預先計算 0! 至 13! 的階乘數值，套用多元展開係數公式計算 n! / (n_1! * ... * n_k!)。 ==========================================================================


<a id="uva-10106_product-bigint"></a>

### UVa 10106 — Product／高精度大數乘法

- 原始碼：[10106_product-bigint.c](10106_product-bigint.c)
- 難度：UVa Star 1
- 演算法：math, big-integer

**English description:** Multiply two non-negative integers up to 250 digits each.

**中文詳細描述：** 精確計算兩個長達 250 位數的非負大整數乘積。

**English approach:** Standard O(N*M) grade-school multiplication: res[i+j] += a[i] * b[j] with carry propagation.

**中文解題思路：** 直式乘法模擬：res[i + j] += a[i] * b[j]，外層雙重迴圈處理累計並處理進位，倒序輸出結果。 ==========================================================================


<a id="uva-10107_what-is-the-median"></a>
### UVa 10107 — What is the Median?／中位數是多少？

- 原始碼：[10107_what-is-the-median.c](10107_what-is-the-median.c)
- 演算法：線上中位數、插入排序（Running Median, Sorting）

**English description:** Integers arrive one at a time. After every insertion, print the median of all values read so far; for an even count, use the integer average of the two middle values.

**中文詳細描述：** 輸入是一串讀到檔案結尾的整數；每讀入一個新值，都要立刻輸出目前全部資料的中位數。程式維持有序陣列並把新值插入正確位置；筆數為奇數時取中央值，偶數時取兩個中央值的整數平均。

<a id="uva-10110_light-more-light"></a>
### UVa 10110 — Light, More Light／開燈，再開燈

- 原始碼：[10110_light-more-light.c](10110_light-more-light.c)
- 演算法：因數個數、完全平方數判定（Number Theory）

**English description:** Bulb n is toggled once for every positive divisor of n. Determine whether it is on after all passes, for each input value until the terminating zero.

**中文詳細描述：** 對編號 n 的燈泡，每個能整除 n 的人都會切換一次開關；輸入多個 n 並以 0 結束。一般因數成對出現，只有完全平方數有單獨的平方根因數而被切換奇數次，因此程式判斷 n 是否為完全平方數並輸出 yes 或 no。

<a id="uva-10112_myacm-triangles"></a>

### UVa 10112 — Myacm Triangles／最大無遮擋三角形

- 原始碼：[10112_myacm-triangles.c](10112_myacm-triangles.c)
- 難度：Easy
- 演算法：geometry, brute-force

**English description:** Find 3 points forming a triangle of maximum area that contains no other points strictly inside or on boundaries.

**中文詳細描述：** 在給定點集中尋找面積最大的三角形，使得該三角形內部及邊界上不包含點集中的任何其他點。

**English approach:** C(n, 3) combinations. For each triangle, check area > max_area. Then verify that no other point lies inside using orientation/area sum tests.

**中文解題思路：** 三重迴圈枚舉三頂點求三角形面積，並驗證其餘所有點皆不在該三角形內（點在三角形內等價於三子三角形面積和等於大三角形面積）。 ==========================================================================


<a id="uva-10114_loansome-car-buyer"></a>

### UVa 10114 — Loansome Car Buyer／買車貸款折舊與負債平衡月數

- 原始碼：[10114_loansome-car-buyer.c](10114_loansome-car-buyer.c)
- 難度：UVa Star 1
- 演算法：simulation

**English description:** Simulate monthly car depreciation and loan repayment to find the first month where the car value exceeds the remaining loan amount.

**中文詳細描述：** 模擬每月車輛折舊與本金分期攤還，求出首個使汽車剩餘價值大於未償還貸款金額的月份。

**English approach:** Maintain car value = (loan + down_payment) * (1 - dep[0]), then month by month apply loan -= payment and car_value *= (1 - dep[m]). Stop when car_value > loan.

**中文解題思路：** 第 0 個月車價乘上即時折舊率，其後每月依固定本金還款且車價按月折舊，記錄首次車價嚴格大於貸款餘額的月份。 ==========================================================================


<a id="uva-10115_automatic-editing"></a>
### UVa 10115 — Automatic Editing／自動編輯

- 原始碼：[10115_automatic-editing.c](10115_automatic-editing.c)
- 演算法：字串搜尋與替換、循序模擬（String, Simulation）

**English description:** Apply replacement rules to a text in the given order. For each rule, repeatedly replace the leftmost occurrence of its search string until no occurrence remains, then continue with the next rule and print the final text.

**中文詳細描述：** 輸入多組搜尋字串與替換字串，接著輸入待編輯文字；規則必須依序執行，同一規則要持續替換最左邊匹配處，直到找不到再換下一條，最後輸出完成文字。

<a id="uva-10115_automatic-editing-pr"></a>

### UVa 10115 — Automatic Editing／自動文字替換編輯

- 原始碼：[10115_automatic-editing-pr.c](10115_automatic-editing-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, simulation

**English description:** Sequentially apply find-and-replace rules on text until rule no longer matches.

**中文詳細描述：** 依序套用多條字串搜尋與替換規則，直到各規則不再能匹配為止。

**English approach:** Search with strstr, splice replacement text.

**中文解題思路：** 依序對各條規則執行 strstr 尋找並拼接替換字串。 ==========================================================================


<a id="uva-10116_robot-motion"></a>

### UVa 10116 — Robot Motion／網格機器人移動迴圈環路檢測

- 原始碼：[10116_robot-motion.c](10116_robot-motion.c)
- 難度：UVa Star 1
- 演算法：simulation, 2d-grid

**English description:** Simulate robot following grid instructions (N, S, E, W). Output either steps to exit grid or steps before entering a cycle and cycle length.

**中文詳細描述：** 在給定方位指示 (N, S, E, W) 的網格中模擬機器人移動，輸出成功脫離網格的步數，或陷入環路前的步數與環長度。

**English approach:** Trace path using a 2D step tracking array step[r][c]. If cell re-visited, cycle detected; if outside grid, exit achieved.

**中文解題思路：** 以 step[r][c] 記錄踏入各格之步數，若下一步超出邊界則為成功走出；若下一步為已走訪格則計算入環前步數與環長。 ==========================================================================


<a id="uva-10125_sumsets"></a>

### UVa 10125 — Sumsets／四數和等式最大目標值 (a + b + c = d)

- 原始碼：[10125_sumsets.c](10125_sumsets.c)
- 難度：UVa Star 2
- 演算法：sorting, two-pointers, meet-in-the-middle

**English description:** Find largest d in set S such that a + b + c = d for distinct a, b, c, d.

**中文詳細描述：** 從給定整數集合中尋找最大的元素 d，滿足存在集合中另三個相異元素使得 a + b + c = d。

**English approach:** Rewrite as a + b = d - c. Store pairwise sums in a sorted array or hash table and perform meet-in-the-middle check.

**中文解題思路：** 變形為 a + b = d - c。枚舉 d 由大到小、枚舉 c，以二分搜尋在預處理好的 a + b 集合中快速查找匹配。 ==========================================================================


<a id="uva-10127_ones"></a>
### UVa 10127 — Ones／全 1 數

- 原始碼：[10127_ones.c](10127_ones.c)
- 演算法：模運算、鴿籠原理（Modular Arithmetic）

**English description:** For each input integer n, find the smallest length of a decimal number consisting only of digit 1 that is divisible by n.

**中文詳細描述：** 每行輸入整數 n；要找最短的 1、11、111……使其可被 n 整除，並輸出這個全 1 數的位數。程式不實際建立巨大整數，而用 `remainder = (remainder×10+1) mod n` 逐位更新，首次餘數為 0 時即得到答案。

<a id="uva-10128_queue"></a>

### UVa 10128 — Queue／隊列視角 (斯特林數與排列DP)

- 原始碼：[10128_queue.c](10128_queue.c)
- 難度：Medium
- 演算法：dp, combinatorics, stirling-numbers

**English description:** Given N people of distinct heights standing in a line, count permutations where P people are visible from the front and R from the back.

**中文詳細描述：** N 個人排成一列，求由前看可見 P 個人、由後看可見 R 個人的排列總數。

**English approach:** DP state dp[n][p][r] = dp[n-1][p-1][r] (shortest in front) + dp[n-1][p][r-1] (shortest in back) + dp[n-1][p][r] * (n - 2) (shortest inside).

**中文解題思路：** 動態規劃：考慮最矮者位置，可放在最前（前視增 1）、最後（後視增 1）或中間 n-2 個位置之一（視角不變）：dp[n][p][r] = dp[n-1][p-1][r] + dp[n-1][p][r-1] + (n-2)*dp[n-1][p][r]。 ==========================================================================


<a id="uva-10129_play-on-words"></a>
### UVa 10129 — Play on Words／文字接龍

- 原始碼：[10129_play-on-words.c](10129_play-on-words.c)
- 演算法：有向歐拉路徑、入出度、並查集（Eulerian Path, DSU）

**English description:** Determine whether all given words can be ordered so that the final letter of each word equals the first letter of the next. This is an Euler-trail test on a directed graph of letters.

**中文詳細描述：** 輸入多個單字；把每個單字視為從首字母指向尾字母的一條有向邊，問題是能否把每條邊恰用一次排成接龍。完整判定需同時檢查入度與出度差，以及所有有邊字母的弱連通性，最後輸出能否開門。

<a id="uva-10129_play-on-words-pr"></a>

### UVa 10129 — Play on Words／文字接龍

- 原始碼：[10129_play-on-words-pr.c](10129_play-on-words-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：graph, eulerian-path, dsu

**English description:** Determine whether given words can be chained end-to-end like dominoes (Eulerian Path in directed graph).

**中文詳細描述：** 單字接龍：前一單字末尾字母與後一單字首字母相同，求能否將所有單字串接成一條（有向圖歐拉路徑判定）。

**English approach:** Check in-degree and out-degree condition for Eulerian path, and weakly connected component via Union-Find.

**中文解題思路：** 入度與出度條件：至多一個點 out - in = 1，至多一個點 in - out = 1，其餘 in == out，且非零度頂點連通。 ==========================================================================


<a id="uva-10130_supersale"></a>
### UVa 10130 — SuperSale／超級特賣

- 原始碼：[10130_supersale.c](10130_supersale.c)
- 演算法：0/1 背包動態規劃（Knapsack DP）

**English description:** Items have prices and weights, and each family member has an individual carrying capacity. Find the maximum total value each person can carry and print the sum over all family members.

**中文詳細描述：** 輸入商品的價值與重量，再輸入每位家庭成員可承受的重量上限；同一成員至多取每件商品一次，但不同成員的選擇彼此獨立。程式先對最大容量做一次 0/1 背包，之後查表加總每位成員的最佳價值並輸出。

<a id="uva-10131_is-bigger-smarter"></a>
### UVa 10131 — Is Bigger Smarter?／越大越聰明嗎？

- 原始碼：[10131_is-bigger-smarter.c](10131_is-bigger-smarter.c)
- 演算法：排序、最長遞增子序列、路徑回溯（LIS, Dynamic Programming）

**English description:** Each elephant has a weight and an IQ. Find the longest sequence in which weights strictly increase while IQ values strictly decrease, and print the original indices of the elephants in order.

**中文詳細描述：** 輸入若干大象的體重與智商直到檔案結尾；要找最長序列，使體重嚴格增加、智商嚴格下降。程式保留原輸入編號，排序後以 DP 求最長合法前驅鏈，並由 parent 指標回溯，輸出長度與各大象原編號。

<a id="uva-10132_file-fragmentation"></a>

### UVa 10132 — File Fragmentation／檔案碎片拼接還原原始位元字串

- 原始碼：[10132_file-fragmentation.c](10132_file-fragmentation.c)
- 難度：UVa Star 2
- 演算法：string, brute-force

**English description:** A file was fragmented into 2N pieces (each file split into 2 fragments). Find the original bit pattern that can be formed by pairing all fragments.

**中文詳細描述：** 原始二進位檔案被切為 2 塊，共收集到 2N 個碎片，找出能將所有碎片兩兩配對成功還原的原始位元字串。

**English approach:** Total original length = sum(len) / N. Pair the shortest fragment with all matching longest fragments to form candidate original strings, then verify consistency.

**中文解題思路：** 原始檔案長度為總碎片長度除以 N。將最短碎片與最長碎片拼接形成候選字串，驗證其是否能完整配對所有碎片。 ==========================================================================


<a id="uva-10137_the-trip"></a>
### UVa 10137 — The Trip／旅行分帳

- 原始碼：[10137_the-trip.c](10137_the-trip.c)
- 演算法：金額整數化、平均分配、貪心（Greedy, Simulation）

**English description:** Students paid different amounts on a trip. Compute the minimum amount of money that must change hands so everyone ends with expenses equal to within one cent.

**中文詳細描述：** 輸入每位學生已支付的金額；要在分攤至多相差一分的前提下，算出最少需要轉手多少錢。程式把金額轉為分以避免浮點誤差，根據總額的向下與向上平均分別累計多付與少付部分，取必要交換量並以貨幣格式輸出。

<a id="uva-10139_factovisors"></a>

### UVa 10139 — Factovisors／階乘被除數整除性勒讓德檢驗

- 原始碼：[10139_factovisors.c](10139_factovisors.c)
- 難度：UVa Star 2
- 演算法：math, number-theory

**English description:** Determine whether integer M divides N! (N factorial).

**中文詳細描述：** 判定整數 M 是否能整除 N! (N 的階乘)。

**English approach:** Prime factorize M. For each prime power p^k in M, verify that Legendre's formula sum_{i=1} floor(N / p^i) >= k.

**中文解題思路：** 將 M 進行質因數分解，利用勒讓德公式計算 N! 中包含該質因數 p 的總冪次，若對所有質因數冪次皆 >= M 中之冪次則整除。 ==========================================================================


<a id="uva-10140_prime-distance"></a>
### UVa 10140 — Prime Distance／質數距離

- 原始碼：[10140_prime-distance.c](10140_prime-distance.c)
- 演算法：分段質數篩、相鄰質數掃描（Segmented Sieve）

**English description:** Within each inclusive interval [L, U], find the pair of adjacent primes with the smallest gap and the pair with the largest gap. Report when fewer than two primes are present.

**中文詳細描述：** 每筆輸入一個閉區間 [L,U]；先找出區間內所有質數，再只比較排序後相鄰質數，輸出距離最近與最遠的兩對。適合用小質數篩去標記區間中的合數；若不足兩個質數則輸出沒有相鄰質數。

<a id="uva-10140_prime-distance-pr"></a>

### UVa 10140 — Prime Distance／相鄰質數最大與最小間距

- 原始碼：[10140_prime-distance-pr.c](10140_prime-distance-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：math, number-theory, segmented-sieve

**English description:** In range [L, U] (U - L <= 1,000,000, U <= 2^31-1), find closest and most distant adjacent primes.

**中文詳細描述：** 在區間 [L, U] 中找出相鄰兩質數距離最近與最遠的質數對。

**English approach:** Segmented Sieve of Eratosthenes using base primes up to sqrt(2^31) = 46340.

**中文解題思路：** 區間篩法。預處理 46340 內的質數篩去 [L, U] 內的合數。 ==========================================================================


<a id="uva-10141_request-for-proposal"></a>

### UVa 10141 — Request for Proposal／企劃書招標評選 (多條件排序)

- 原始碼：[10141_request-for-proposal.c](10141_request-for-proposal.c)
- 難度：UVa Star 1
- 演算法：string, sorting, simulation

**English description:** Select winning RFP proposal: highest compliance (requirements met), lowest price as tie-breaker, original order second tie-breaker.

**中文詳細描述：** 政府採購評選招標方案：優先選滿足需求數最多者；平手選投標報價最低者；再平手選最先投標者。

**English approach:** Linear scan tracking best candidate by (requirements_met DESC, price ASC, arrival_order ASC).

**中文解題思路：** 線性巡訪候選提案，以三鍵比較更新最優企劃：符合項目數較大、價格較低、輸入順序較先。 ==========================================================================


<a id="uva-10142_australian-voting"></a>

### UVa 10142 — Australian Voting／澳洲排序複選制即時決選投票

- 原始碼：[10142_australian-voting.c](10142_australian-voting.c)
- 難度：UVa Star 2
- 演算法：simulation

**English description:** Simulate Australian preferential voting: count 1st preferences; if no candidate has > 50%, eliminate candidate(s) with lowest votes and redistribute.

**中文詳細描述：** 模擬澳洲偏好投票制 (排序複選制)：統計首選票數，若無人過半則淘汰最低得票者並將選票依序遞補，重複直到勝出或平手。

**English approach:** Maintain candidate elimination flags. In each round, tally active first preferences. If max > 50% or all remaining tied, terminate.

**中文解題思路：** 以陣列記錄淘汰狀態，每輪統計有效選票之第一偏好，若最高票過半或所有剩餘候選人同票則宣告獲勝，否則淘汰最低票並循環。 ==========================================================================


<a id="uva-10147_highways"></a>

### UVa 10147 — Highways／公路系統建設

- 原始碼：[10147_highways.c](10147_highways.c)
- 難度：Medium
- 演算法：graph, mst, kruskal

**English description:** Given town locations and already existing highways, find additional highways to build to connect all towns with minimum total length.

**中文詳細描述：** 給定城鎮座標與已建成的公路，求需額外興建哪些公路以最小總成本使所有城鎮連通。

**English approach:** Kruskal's algorithm: pre-union existing highway endpoints in DSU, sort all remaining pairs by Euclidean distance, add edges connecting different components.

**中文解題思路：** Kruskal 演算法：將已存在的公路端點在並查集中預先合併，將剩餘點對按歐氏距離排序，依序加入連接不同分量的邊。 ==========================================================================


<a id="uva-10150_doublets"></a>

### UVa 10150 — Doublets／雙詞階梯 (字詞變換最短路徑)

- 原始碼：[10150_doublets.c](10150_doublets.c)
- 難度：Medium
- 演算法：graph, bfs, shortest-path

**English description:** Find the shortest sequence of dictionary words from start to end where each word differs by exactly one letter from the previous word.

**中文詳細描述：** 求字典中從起點單字到終點單字的最短變換序列，每次只允許改變一個字母。

**English approach:** Build graph connecting words of identical length differing by 1 character. Run BFS from start to target.

**中文解題思路：** 為長度相同且恰好相差一個字母的單字連邊建圖，使用 BFS 尋找最短路徑並回溯輸出路徑。 ==========================================================================


<a id="uva-10152_shell-sort"></a>
### UVa 10152 — ShellSort／烏龜排序

- 原始碼：[10152_shell-sort.c](10152_shell-sort.c)
- 演算法：貪心、由底向上比對（Greedy, Simulation）

**English description:** Transform one stack of named turtles into a target stack using only the operation of moving any turtle to the top. Print a shortest sequence of turtle names to move.

**中文詳細描述：** 輸入目前的烏龜堆疊與目標順序；每次只能抽出一隻烏龜放到最上方，任務是用最少操作完成排列。從兩堆底部向上比對可保留已對齊的最長部分，其餘目標烏龜依需要輸出為搬移順序。

<a id="uva-10152_shell-sort-pr"></a>

### UVa 10152 — Shell Sort／烏龜疊疊樂

- 原始碼：[10152_shell-sort-pr.c](10152_shell-sort-pr.c)
- 難度：UVa Star 2
- 解答版本：PR 同題替代實作
- 演算法：greedy, string, simulation

**English description:** Reorder turtle stack to target order using only "move to top" operations.

**中文詳細描述：** 烏龜堆疊只能將某一隻烏龜抽出來放到最頂端，求達成目標排序的最少操作順序。

**English approach:** Greedily match turtles from bottom to top; non-matching must be pulled to top in reverse.

**中文解題思路：** 從目標堆疊底部向上貪婪匹配，未匹配者由下而上依序抽到最頂部。 ==========================================================================


<a id="uva-10154_weights-and-measures"></a>

### UVa 10154 — Weights and Measures／烏龜疊羅漢 (重量與承重)

- 原始碼：[10154_weights-and-measures.c](10154_weights-and-measures.c)
- 難度：Hard
- 演算法：dp, greedy, sorting

**English description:** Find the maximum number of turtles that can be stacked on top of each other such that each turtle can support the total weight above it.

**中文詳細描述：** 求最多可將多少隻烏龜疊在一起，使得每隻烏龜都能承受其上方所有烏龜的重量總和。

**English approach:** Sort turtles by capacity (strength) ascending. DP state dp[k] = minimum weight of a stack of k turtles. dp[k] = min(dp[k], dp[k-1] + w) if dp[k-1] + w <= s.

**中文解題思路：** 依照承重能力升序排序。動態規劃 dp[k] 表示堆疊 k 隻烏龜的最小總重量，更新 dp[k] = min(dp[k], dp[k-1] + w)。 ==========================================================================


<a id="uva-10158_war"></a>

### UVa 10158 — War／戰爭

- 原始碼：[10158_war.c](10158_war.c)
- 難度：Medium
- 演算法：disjoint-set-union

**English description:** Maintain relationships between friends and enemies using DSU with negation / 2N representation.

**中文詳細描述：** 使用擴展並查集 (2N 節點) 維護人與人之間的朋友與敵人關係。

**English approach:** Use 2N union-find where node x represents x, and x+N represents enemy(x). Friends: union(x, y) & union(x+N, y+N). Enemies: union(x, y+N) & union(x+N, y).

**中文解題思路：** 使用 2N 大小的並查集，x 為本體，x+N 為敵人。朋友則合併 x 與 y、x+N 與 y+N；敵人則合併 x 與 y+N、x+N 與 y。 ==========================================================================


<a id="uva-10161_ant-on-a-chessboard"></a>
### UVa 10161 — Ant on a Chessboard／棋盤上的螞蟻

- 原始碼：[10161_ant-on-a-chessboard.c](10161_ant-on-a-chessboard.c)
- 演算法：平方層定位、座標數學（Math）

**English description:** Cells of an infinite chessboard are numbered along a square spiral. Given N, compute and print the column and row containing cell N.

**中文詳細描述：** 輸入螺旋編號 N，直到終止值；要找 N 在無限棋盤上的座標。程式以 `ceil(sqrt(N))` 找到 N 所在的正方形外層，再利用該層平方數、轉折點與奇偶方向計算列、欄，最後依題目順序輸出座標。

<a id="uva-10162_last-digit"></a>

### UVa 10162 — Last Digit／冪次和最後一位數字 (週期性)

- 原始碼：[10162_last-digit.c](10162_last-digit.c)
- 難度：Easy
- 演算法：math, periodicity

**English description:** Find the last digit of sum_{i=1}^N i^i for large integer N.

**中文詳細描述：** 求 sum_{i=1}^N i^i 的個位數字（N 為大整數）。

**English approach:** The sequence of last digits of sum_{i=1}^N i^i repeats with period 100. Evaluate S(N % 100).

**中文解題思路：** i^i mod 10 以 100 為週期重複循環。將大數 N 取模 100 後直接查表前綴和即為最後一位數字。 ==========================================================================


<a id="uva-10165_stone-game"></a>

### UVa 10165 — Stone Game／尼姆博弈 (石子遊戲)

- 原始碼：[10165_stone-game.c](10165_stone-game.c)
- 難度：Easy
- 演算法：game-theory, nim-sum

**English description:** Determine if the first player has a winning strategy in a standard game of Nim with n piles of stones.

**中文詳細描述：** 判斷先手在有 n 堆石子的標準尼姆 (Nim) 博弈中是否具備必勝策略。

**English approach:** Bouton's Theorem: First player wins if and only if the XOR sum of all pile sizes is non-zero.

**中文解題思路：** 由尼姆博弈博通定理 (Bouton's Theorem)，先手必勝若且唯若所有石子堆數量的異或和 (Nim-sum) 不為 0。 ==========================================================================


<a id="uva-10167_birthday-cake"></a>
### UVa 10167 — Birthday Cake／生日蛋糕

- 原始碼：[10167_birthday-cake.c](10167_birthday-cake.c)
- 演算法：計算幾何、整數枚舉（Geometry, Brute Force）

**English description:** Given 2N points representing cherries, find nonzero integers A and B so the line Ax + By = 0 passes through no point and places exactly N points on each side.

**中文詳細描述：** 輸入 2N 顆櫻桃的平面座標；要找通過原點的直線 Ax+By=0，使直線不穿過任何櫻桃，且兩側各有 N 顆。程式在題目允許的整數係數範圍枚舉 A、B，計算每點代入式子的正負號，找到均分配置後輸出係數。

<a id="uva-10168_summation-of-four-primes"></a>
### UVa 10168 — Summation of Four Primes／四個質數的和

- 原始碼：[10168_summation-of-four-primes.c](10168_summation-of-four-primes.c)
- 演算法：質數篩、哥德巴赫分解（Prime Sieve, Number Theory）

**English description:** Express each integer N as a sum of four prime numbers, or state that it is impossible. A parity-based fixed pair reduces the remaining task to finding two primes with a given sum.

**中文詳細描述：** 每行輸入整數 N；若可行，要輸出四個質數使其總和為 N。N 太小時無解；其餘情況依 N 奇偶先選 2+2 或 2+3，再在剩餘偶數中尋找一對質數，找到後輸出四項，否則輸出 Impossible。

<a id="uva-10170_the-hotel-with-infinite-rooms"></a>
### UVa 10170 — The Hotel with Infinite Rooms／無限房間旅館

- 原始碼：[10170_the-hotel-with-infinite-rooms.c](10170_the-hotel-with-infinite-rooms.c)
- 演算法：等差級數、累加搜尋（Math, Simulation）

**English description:** Starting with a group of size S, consecutive groups have sizes S, S+1, S+2, and so on, each occupying that many consecutive days. Given day D, find the size of the group staying then.

**中文詳細描述：** 每行輸入起始團體大小 S 與目標日 D；第一團停留 S 天，之後團體人數與停留天數都逐次加一。程式從 S 起累加各團停留天數，找到累積日數第一次涵蓋 D 時的團體大小，並輸出該值。

<a id="uva-10171_meeting-prof-miguel"></a>

### UVa 10171 — Meeting Prof. Miguel...／會見米格爾教授 (分年齡最短路徑與會面點)

- 原始碼：[10171_meeting-prof-miguel.c](10171_meeting-prof-miguel.c)
- 難度：Medium
- 演算法：graph, floyd-warshall, shortest-path

**English description:** Young man and old Miguel want to meet at a place where the sum of their travel costs is minimized. Young people and mature people can only use respective street networks.

**中文詳細描述：** 年輕人與年長教授各有一套可通行的街道系統，求使兩人前往會合地點的總路費最小的會面節點。

**English approach:** Run Floyd-Warshall independently on Young graph and Mature graph. Find node k minimizing dist_young[src1][k] + dist_mature[src2][k].

**中文解題思路：** 分別對年輕人與老年人的街道圖跑 Floyd-Warshall 全源最短路徑，枚舉所有節點 k 求兩者距離和最小值。 ==========================================================================


<a id="uva-10172_the-lonesome-cargo-distributor"></a>

### UVa 10172 — The Lonesome Cargo Distributor／孤獨的貨物搬運工 (環形裝卸模擬)

- 原始碼：[10172_the-lonesome-cargo-distributor.c](10172_the-lonesome-cargo-distributor.c)
- 難度：Medium
- 演算法：simulation, queue, stack

**English description:** Simulate a cargo carrier moving circularly between N stations with a cargo stack of capacity S and station queues of capacity Q until all cargo is delivered.

**中文詳細描述：** 搬運車在 N 個環形站點間循環移動，車上有容量為 S 的堆疊，各站有容量為 Q 的隊列，求送完所有貨物的最少時間。

**English approach:** Simulate: unload matching cargo to station A (1 min each) or into station queue B (if queue < Q). Load cargo from queue B to carrier stack (if stack < S). Move to next station (2 min). Stop when all queues and carrier empty.

**中文解題思路：** 嚴格依規則模擬車上堆疊與站點隊列：先卸貨（同站入庫或轉入站點隊列），再裝貨，最後移動到下一站，累計總耗時。 ==========================================================================


<a id="uva-10176_ocean-deep-make-it-shallow"></a>

### UVa 10176 — Ocean Deep! - Make it shallow!!／大洋深處！讓它變淺！

- 原始碼：[10176_ocean-deep-make-it-shallow.c](10176_ocean-deep-make-it-shallow.c)
- 難度：Medium
- 演算法：math, modulo-arithmetic

**English description:** Given a large binary number terminated by '#', determine if it is divisible by the prime 131071.

**中文詳細描述：** 給定一個以 '#' 結尾的長二進位數，判斷其是否能被質數 131071 整除。

**English approach:** Process the binary digits one by one using Horner's rule: rem = (rem * 2 + digit) % 131071. Check if rem == 0.

**中文解題思路：** 使用秦九韶算法 (Horner's rule) 逐位累計餘數：rem = (rem * 2 + digit) % 131071，最後檢查 rem 是否為 0。 ==========================================================================


<a id="uva-10177_2-3-4-d-sqr-rects-cubes-boxes"></a>

### UVa 10177 — (2/3/4)-D Sqr/Rects/Cubes/Boxes?／多維正方體與長方體計數

- 原始碼：[10177_2-3-4-d-sqr-rects-cubes-boxes.c](10177_2-3-4-d-sqr-rects-cubes-boxes.c)
- 難度：Easy
- 演算法：math, combinatorics

**English description:** Count squares vs non-square rectangles in 2D, cubes vs non-cube boxes in 3D, and hypercubes vs hyperboxes in 4D of an N-grid.

**中文詳細描述：** 在邊長為 N 的網格中，分別統計 2D 正方形與非正方形矩形、3D 立方體與非立方體長方體、4D 超立方體與非超立方體總數。

**English approach:** In d dimensions: total rectangles = (N*(N+1)/2)^d. Total hypercubes = sum_{i=1}^N i^d. Non-cubes = Total - Hypercubes.

**中文解題思路：** d 維空間中長方體總數為 (N*(N+1)/2)^d，正方體總數為 sum_{i=1}^N i^d，兩者相減即為非正方體數量。 ==========================================================================


<a id="uva-10179_irreducable-basic-fractions"></a>

### UVa 10179 — Irreducable Basic Fractions／不可約真分數與歐拉函數

- 原始碼：[10179_irreducable-basic-fractions.c](10179_irreducable-basic-fractions.c)
- 難度：UVa Star 2
- 演算法：math, number-theory

**English description:** Compute the number of irreducible proper fractions with denominator n, which equals Euler's totient phi(n).

**中文詳細描述：** 計算分母為 n 且分子小於 n 的不可約最簡真分數個數，即歐拉函數 phi(n)。

**English approach:** Euler's totient formula: phi(n) = n * product_{p|n} (1 - 1/p).

**中文解題思路：** 以試除法求出 n 的相異質因數 p，套用歐拉公式 phi(n) = n * prod(1 - 1/p)。 ==========================================================================


<a id="uva-10181_15-puzzle-problem"></a>

### UVa 10181 — 15-Puzzle Problem／15-數碼難題 (IDA*啟發式搜索與曼哈頓距離)

- 原始碼：[10181_15-puzzle-problem.c](10181_15-puzzle-problem.c)
- 難度：Hard
- 演算法：ida, heuristic-search, inversion-parity

**English description:** Solve 15-puzzle in <= 45 moves using IDA* with Manhattan distance heuristic and linear conflicts.

**中文詳細描述：** 在最多 45 步內解開 15-數碼謎題（IDA* 搭配曼哈頓距離與逆序對可解性檢驗）。

**English approach:** Check parity of inversions and empty space row. Run IDA* with Manhattan distance heuristic.

**中文解題思路：** 先驗證空白格行數與逆序對奇偶性檢定是否有解；使用曼哈頓距離作為啟發函數進行 IDA* 搜索。 ==========================================================================


<a id="uva-10182_bee-maja"></a>

### UVa 10182 — Bee Maja／蜜蜂瑪雅六角蜂巢螺旋座標映射

- 原始碼：[10182_bee-maja.c](10182_bee-maja.c)
- 難度：UVa Star 1
- 演算法：simulation, math

**English description:** Maja the bee numbers hex honeycomb cells in an expanding spiral. Find the 2D axial coordinates (x, y) of cell N.

**中文詳細描述：** 蜜蜂瑪雅以六角蜂巢外擴螺旋為蜂房編號，求編號為 N 的蜂房在二維軸向座標系下的座標 (x, y)。

**English approach:** Ring simulation: ring k has 6*k cells. Follow 6 directional steps (down-left, down, right, up-right, up, left) to step N.

**中文解題思路：** 分圈螺旋模擬：第 k 圈包含 6k 個格子，依六角網格的 6 個方向向量逐圈遞推精準定位座標。 ==========================================================================


<a id="uva-10183_how-many-fibs"></a>
### UVa 10183 — How Many Fibs?／有多少個費波那契數？

- 原始碼：[10183_how-many-fibs.c](10183_how-many-fibs.c)
- 演算法：大整數、費波那契預處理、區間計數（Big Integer, Fibonacci）

**English description:** For each pair of arbitrarily large bounds a and b, count the Fibonacci numbers lying in the inclusive interval [a, b], stopping at the pair 0 0.

**中文詳細描述：** 輸入可能長達許多位的上下界 a、b，以 0 0 結束；要計算閉區間內有幾個費波那契數。完整作法需用大整數預先產生序列，再比較或二分找出區間端點並輸出數量。

<a id="uva-10183_how-many-fibs-pr"></a>

### UVa 10183 — How Many Fibs?／區間內費氏數個數

- 原始碼：[10183_how-many-fibs-pr.c](10183_how-many-fibs-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：math, big-integer, fibonacci

**English description:** Count Fibonacci numbers within range [a, b] up to 10^100.

**中文詳細描述：** 計算區間 [a, b] 內費氏數的個數（可達 10^100）。

**English approach:** Precompute first 500 Fibonacci numbers using BigInt, binary search range [a, b].

**中文解題思路：** 預處理前 500 項大數費氏數列，二分搜尋區間落點計數。 ==========================================================================


<a id="uva-10188_automated-judge-script"></a>
### UVa 10188 — Automated Judge Script／自動評審程式

- 原始碼：[10188_automated-judge-script.c](10188_automated-judge-script.c)
- 演算法：字串比較、數字抽取（String, Simulation）

**English description:** Compare a team's output with the official output. Exact equality is Accepted; otherwise equal digit sequences produce Presentation Error, and all other differences produce Wrong Answer.

**中文詳細描述：** 輸入標準答案的多行文字與參賽輸出的多行文字。若包含換行在內完全相同則輸出 Accepted；否則各自抽出所有數字字元，數字序列仍相同便是 Presentation Error，不同則是 Wrong Answer，並附上案例編號。

<a id="uva-10188_automated-judge-script-pr"></a>

### UVa 10188 — Automated Judge Script／自動評判系統狀態判定 (AC, PE, WA)

- 原始碼：[10188_automated-judge-script-pr.c](10188_automated-judge-script-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：string, simulation

**English description:** Compare standard output and team output: Accepted if exact match, Presentation Error if only numeric characters match, else Wrong Answer.

**中文詳細描述：** 評判程式輸出：若完全吻合輸出 Accepted；若僅字串中抽取出的數字完全相同輸出 Presentation Error；否則輸出 Wrong Answer。

**English approach:** First strcmp full text. If mismatch, extract only digit characters and compare digit strings.

**中文解題思路：** 先比對完整字串是否完全相等；若不符則過濾抽出雙方所有數字字元比對，數字相同即為 PE，否則為 WA。 ==========================================================================


<a id="uva-10189_minesweeper"></a>
### UVa 10189 — Minesweeper／踩地雷

- 原始碼：[10189_minesweeper.c](10189_minesweeper.c)
- 演算法：二維陣列、八鄰格計數（Grid Simulation）

**English description:** Given mine locations in a rectangular field, replace every non-mine cell with the number of mines among its eight neighboring cells, preserving mines and printing each numbered field.

**中文詳細描述：** 輸入多個由 `*` 與 `.` 組成的雷區，直到尺寸 0 0；每個非地雷格要填入周圍八格中地雷的數量，地雷格保留星號。程式逐格檢查合法鄰座標並累計，依案例格式輸出完成的提示圖。

<a id="uva-10190_divide-but-not-quite-conquer"></a>
### UVa 10190 — Divide, But Not Quite Conquer!／除法，但不完全征服！

- 原始碼：[10190_divide-but-not-quite-conquer.c](10190_divide-but-not-quite-conquer.c)
- 演算法：反覆整除模擬（Simulation, Math）

**English description:** Starting with n, repeatedly divide by m and print the sequence down to 1 only when every division is exact. Otherwise print the failure message.

**中文詳細描述：** 每行輸入 n、m；若能從 n 開始反覆除以 m，且每一步都整除並最終恰好得到 1，就輸出包含 n 與 1 的完整序列。程式先排除 m 不適合與邊界情況，再逐步檢查餘數；任一步失敗便輸出 Boring!。

<a id="uva-10191_longest-nap"></a>
### UVa 10191 — Longest Nap／最長午睡

- 原始碼：[10191_longest-nap.c](10191_longest-nap.c)
- 演算法：區間排序、空檔掃描（Sorting, Greedy）

**English description:** Given a day's appointments between 10:00 and 18:00, find the longest free interval available for a nap. If several gaps are equally long, choose the earliest one.

**中文詳細描述：** 輸入一天內多個約會的起訖時間與文字說明；只考慮 10:00 到 18:00，找出未被約會占用的最長連續時段。程式把時間轉為分鐘並排序，合併掃描已占用範圍，也比較上班起點與下班終點兩側空檔，輸出最早的最長午睡開始時間與長度。

<a id="uva-10192_vacation"></a>
### UVa 10192 — Vacation／假期

- 原始碼：[10192_vacation.c](10192_vacation.c)
- 演算法：最長共同子序列、動態規劃（LCS, Dynamic Programming）

**English description:** Given two strings describing vacation preferences, find the length of their longest common subsequence and print how many cities can be visited in common.

**中文詳細描述：** 每組輸入兩行行程偏好字串，遇到終止標記結束；可刪去字元但不能改變順序，任務是找兩字串的最長共同子序列。程式以字元是否相等進行 LCS 二維 DP，並按案例格式輸出可共同造訪的最大城市數。

<a id="uva-10193_all-you-need-is-love"></a>
### UVa 10193 — All You Need Is Love／你只需要愛

- 原始碼：[10193_all-you-need-is-love.c](10193_all-you-need-is-love.c)
- 演算法：二進位轉換、最大公因數（Binary, GCD）

**English description:** Two positive integers are written as binary strings. Determine whether they share a common divisor greater than one and print the corresponding case message.

**中文詳細描述：** 每組輸入兩個二進位字串，代表兩人的愛情數值；若兩數有大於 1 的共同因數，題目視為可以得到愛。程式把二進位轉為整數，以歐幾里得演算法求最大公因數，再依是否大於 1 輸出案例訊息。

<a id="uva-10194_football-aka-soccer"></a>

### UVa 10194 — Football (aka Soccer)／足球錦標賽積分榜排序規則

- 原始碼：[10194_football-aka-soccer.c](10194_football-aka-soccer.c)
- 難度：UVa Star 2
- 演算法：sorting, simulation

**English description:** Rank soccer teams by: 1) Points (Win=3, Tie=1), 2) Most wins, 3) Goal difference, 4) Goals scored, 5) Fewest games, 6) Lexicographical case-insensitive.

**中文詳細描述：** 模擬足球聯賽積分榜排序：積分 (勝3平1) > 勝場數 > 得失球差 > 總進球數 > 較少出賽場次 > 忽略大小寫之隊名字典序。

**English approach:** Custom multi-criteria sorting comparator on team struct records.

**中文解題思路：** 在球隊成績結構體上實作嚴格多級比較器，依積分、勝場、淨勝球、進球數、場次及字母序排序。 ==========================================================================


<a id="uva-10195_the-knights-of-the-round-table"></a>

### UVa 10195 — The Knights Of The Round Table／圓桌騎士最大內切圓半徑

- 原始碼：[10195_the-knights-of-the-round-table.c](10195_the-knights-of-the-round-table.c)
- 難度：UVa Star 1
- 演算法：geometry, math

**English description:** Find the radius of the largest circular table (inscribed circle) that can fit inside a triangular room with side lengths a, b, c.

**中文詳細描述：** 計算可置入三邊長為 a, b, c 的三角形大廳內之最大圓形會議桌 (內切圓) 半徑。

**English approach:** Radius r = Area / semiperimeter s. Area via Heron's formula sqrt(s*(s-a)*(s-b)*(s-c)). If s == 0, r = 0.

**中文解題思路：** 利用海龍公式計算三角形面積 Area = sqrt(s(s-a)(s-b)(s-c))，內切圓半徑 r = Area / s。 ==========================================================================


<a id="uva-10196_check-the-check"></a>

### UVa 10196 — Check The Check／西洋棋將軍狀態即時偵測

- 原始碼：[10196_check-the-check.c](10196_check-the-check.c)
- 難度：UVa Star 2
- 演算法：simulation, 2d-grid

**English description:** Determine if either the black king or white king is under check on an 8x8 chessboard.

**中文詳細描述：** 在 8x8 西洋棋棋盤上，檢驗黑方國王或白方國王當前是否正處於被「將軍」(Check) 狀態。

**English approach:** Find positions of 'k' and 'K'. Scan possible attacking rays/jumps from pawns, knights, rooks, bishops, and queens.

**中文解題思路：** 定位雙方國王位置，分別向周圍八方向射線與馬的 8 個跳步位置檢查是否有敵方對應棋子威脅國王。 ==========================================================================


<a id="uva-10198_counting"></a>

### UVa 10198 — Counting／大數動態規劃數位和組合計數

- 原始碼：[10198_counting.c](10198_counting.c)
- 難度：UVa Star 2
- 演算法：dynamic-programming, math

**English description:** Count numbers composed of digits 1, 2, 3, 4 with sum n, where digit 4 is counted as having value 1.

**中文詳細描述：** 以數字 1, 2, 3, 4 (其中 4 的權重計為 1) 構成總和為 n 的數字組合數，推導動態規劃遞推式。

**English approach:** DP recurrence: since two digits have value 1 (digits 1 and 4), T(n) = 2*T(n-1) + T(n-2) + T(n-3).

**中文解題思路：** 動態規劃狀態轉移：權重為 1 的有兩種選擇 (1 與 4)，故 T(n) = 2*T(n-1) + T(n-2) + T(n-3)。 ==========================================================================


<a id="uva-10199_tourist-guide"></a>

### UVa 10199 — Tourist Guide／觀光地圖關鍵關節點割點偵測

- 原始碼：[10199_tourist-guide.c](10199_tourist-guide.c)
- 難度：UVa Star 2
- 演算法：graph, tarjan, cut-vertices

**English description:** Find all camera locations (articulation points / cut-vertices) in a city graph whose removal disconnects locations.

**中文詳細描述：** 找出城市景點地圖中的所有關鍵關節點 (割點)，若該節點發生狀況則會阻斷其他景點間的通聯。

**English approach:** Tarjan's cut-vertex algorithm: a root node is cut-vertex if it has >= 2 children; non-root node u is cut-vertex if child v has low[v] >= tin[u].

**中文解題思路：** 利用 Tarjan 演算法偵測圖中割點：根節點子樹個數 >= 2 或非根節點存在子節點 v 滿足 low[v] >= tin[u] 則為割點。 ==========================================================================
