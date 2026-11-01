# UVa Volume 118

本卷收錄 17 份 C 解答，涵蓋 16 個 UVa 題號，以下依題號排序。

<a id="uva-11804_argentina"></a>

### UVa 11804 — Argentina／阿根廷國家隊先發陣容選拔

- 原始碼：[11804_argentina.c](11804_argentina.c)
- 難度：Medium
- 演算法：brute-force, backtracking, combinations

**English description:** Select 5 attackers and 5 defenders from 10 players to maximize attacking ability, then maximize defense, tie-breaking alphabetically.

**中文詳細描述：** 從 10 名球員中選出 5 名進攻球員與 5 名防守球員，最大化進攻總值，次之最大化防守總值，並依姓名辭典順序決選。

**English approach:** Combinations C(10, 5) = 252. Evaluate attack sum, then defense sum, then lexicographical order of attacker names.

**中文解題思路：** 組合數 C(10, 5) 僅 252 種可能，枚舉所有選擇，比較進攻和、防守和以及球員名字字元順序輸出最佳先發。 ==========================================================================


<a id="uva-11805_bafana-bafana"></a>

### UVa 11805 — Bafana Bafana／南非足球傳球 (環形取模位移)

- 原始碼：[11805_bafana-bafana.c](11805_bafana-bafana.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** N players in a circle (1..N). Ball starts at player K and is passed P times clockwise. Find player holding the ball.

**中文詳細描述：** N 名球員圍成一圈 (編號 1 到 N)。球從 K 號開始順時針傳球 P 次，求最後持球的球員編號。

**English approach:** Formula: 1-based circular shift: ((K - 1 + P) % N) + 1.

**中文解題思路：** 循環取模公式：將 1-based 轉為 0-based 位移取模後加 1，即 ((K - 1 + P) % N) + 1。 ==========================================================================


<a id="uva-11824_a-minimum-land-price"></a>

### UVa 11824 — A Minimum Land Price／最小土地總價格 (貪心排序)

- 原始碼：[11824_a-minimum-land-price.c](11824_a-minimum-land-price.c)
- 難度：Easy
- 演算法：greedy, sorting, math

**English description:** Given parcel prices L_i, buying in order 1..k costs sum 2 * (L_i)^i. Find min cost and check if <= budget 5,000,000.

**中文詳細描述：** 給定土地基準價格，第 i 年購買成本為 2 * (L)^i，求最優購買順序下的最小總價，並檢查是否超支 5,000,000。

**English approach:** Sort parcel prices descending so largest base prices receive smallest exponents i = 1, 2, ...

**中文解題思路：** 貪心法：將土地基準價格由大到小排序，最大者分配最小指數，使得總成本 2 * L^i 最小。 ==========================================================================


<a id="uva-11827_maximum-gcd"></a>

### UVa 11827 — Maximum GCD／整數數列兩兩最大公因數之極大值

- 原始碼：[11827_maximum-gcd.c](11827_maximum-gcd.c)
- 難度：UVa Star 1
- 演算法：math, number-theory

**English description:** Given N integers, find the maximum greatest common divisor (GCD) among all possible pairs (a_i, a_j) with i != j.

**中文詳細描述：** 給定包含 N 個整數的數列，求任兩數 (a_i, a_j) 間的最大公因數 (GCD) 之最大值。

**English approach:** Pairwise enumeration: compute gcd(a[i], a[j]) for all 0 <= i < j < N using Euclidean algorithm, and keep track of maximum.

**中文解題思路：** 雙重迴圈枚舉所有數對，以輾轉相除法求每對之 GCD，動態維護最大值並回傳。 ==========================================================================


<a id="uva-11830_contract-revision"></a>

### UVa 11830 — Contract Revision／合約修訂 (過濾故障數位字元)

- 原始碼：[11830_contract-revision.c](11830_contract-revision.c)
- 難度：Easy
- 演算法：string, simulation

**English description:** A typewriter's digit key D is broken and does not type. Given digit D and original contract number string N, output the resulting number (stripping leading zeros).

**中文詳細描述：** 打字機的某個數字鍵 D 故障無法印出，給定故障鍵 D 與原合約數字 N，輸出修訂後的數值（去除前導 0，若全被刪除則為 0）。

**English approach:** Filter out char D from string N. Remove leading zeros. If empty, output '0'.

**中文解題思路：** 過濾掉字串中的所有字元 D，去除前導零；若字串為空則輸出 '0'。 ==========================================================================


<a id="uva-11831_sticker-collector-robot"></a>

### UVa 11831 — Sticker Collector Robot／貼紙收集機器人行進方向模擬

- 原始碼：[11831_sticker-collector-robot.c](11831_sticker-collector-robot.c)
- 難度：UVa Star 2
- 演算法：simulation, 2d-grid

**English description:** Simulate a robot on a grid following 'D' (turn right 90 deg), 'E' (turn left 90 deg), and 'F' (forward 1 step). Collect stickers '*'.

**中文詳細描述：** 在帶有障礙物 '#' 的網格上模擬機器人移動指令：右轉 'D'、左轉 'E'、前進 'F'，並收集沿途踩踏到的貼紙 '*'。

**English approach:** Maintain direction orientation (N, L, S, O). Execute commands: ignore forward moves into pillars '#' or grid boundaries. Collect stickers upon entry.

**中文解題思路：** 以方向變數記錄目前朝向 (北東南西)，依序執行指令：遇到障礙物或邊界則原地踏步，踏入貼紙格時收集貼紙並標記為空地。 ==========================================================================


<a id="uva-11838_come-and-go"></a>

### UVa 11838 — Come and Go／雙向通達街道全源強連通性驗證

- 原始碼：[11838_come-and-go.c](11838_come-and-go.c)
- 難度：UVa Star 2
- 演算法：graph, scc, tarjan

**English description:** Determine whether a directed street network is strongly connected (every intersection can reach every other intersection).

**中文詳細描述：** 判定給定單行道與雙向道街道網路是否為強連通圖 (即任意兩路口均可互相通達)。

**English approach:** Tarjan's strongly connected components algorithm: graph is valid if and only if there is exactly 1 SCC containing all N nodes.

**中文解題思路：** 利用 Tarjan 演算法求強連通分量個數，全圖強連通的充要條件為恰好只有 1 個包含全部 N 個節點的 SCC。 ==========================================================================


<a id="uva-11849_cd"></a>

### UVa 11849 — CD／CD 光碟共同擁有重複計數

- 原始碼：[11849_cd.c](11849_cd.c)
- 難度：UVa Star 1
- 演算法：two-pointers, sorting

**English description:** Jack and Jill each have sorted catalogs of CD catalog numbers. Count how many CDs they both own.

**中文詳細描述：** Jack 和 Jill 各自擁有一批按遞增順序排列的 CD 光碟編號，統計兩人共同擁有的 CD 數量。

**English approach:** Two pointers traversing both sorted arrays in O(N + M) time. If equal, increment count and advance both pointers.

**中文解題思路：** 雙指針同步掃描兩已排序陣列：數值相等則計數加一並同時前進，否則推進較小元素之指針，時間複雜度 O(N+M)。 ==========================================================================


<a id="uva-11850_alaska"></a>

### UVa 11850 — Alaska／阿拉斯加公路

- 原始碼：[11850_alaska.c](11850_alaska.c)
- 難度：Easy
- 演算法：greedy, sorting

**English description:** Determine if a car with a 200-mile tank can make a round trip of 1422 miles visiting given charging stations along the route.

**中文詳細描述：** 判斷滿油能跑 200 英里的車能否利用沿途加油站完成全長 1422 英里的阿拉斯加公路來回旅程。

**English approach:** Sort stations. Check distance between consecutive stations <= 200, and last station to end and back <= 200: 2 * (1422 - stations[n-1]) <= 200.

**中文解題思路：** 將加油站座標排序，檢查相鄰加油站距離不超過 200，且最後一個加油站到終點折返距離 2 * (1422 - stations[n-1]) <= 200。 ==========================================================================


<a id="uva-11854_egypt"></a>
### UVa 11854 — Egypt／埃及

- 原始碼：[11854_egypt.c](11854_egypt.c)
- 演算法：畢氏定理、排序（Geometry, Math）

**English description:**

For each triple of side lengths until the terminating zeros, determine whether the three sides form a right triangle. Treat the largest side as the hypotenuse and output `right` or `wrong`.

**中文詳細描述：**

逐筆讀入三個邊長，直到三者皆為 0。先找出最大邊作為斜邊，檢查另外兩邊平方和是否等於最大邊平方；成立時輸出 `right`，否則輸出 `wrong`。

<a id="uva-11854_egypt-pr"></a>

### UVa 11854 — Egypt／埃及直角三角形判定 (畢氏定理逆定理)

- 原始碼：[11854_egypt-pr.c](11854_egypt-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：geometry, math

**English description:** Determine if triangle with given sides a, b, c is a right triangle (Pythagorean theorem).

**中文詳細描述：** 給定三角形三邊長，判定其是否為直角三角形 (畢氏定理逆定理 a^2 + b^2 = c^2)。

**English approach:** Sort sides so that c is largest. Check if a^2 + b^2 == c^2.

**中文解題思路：** 找出最大邊作為斜邊，檢驗兩較小邊的平方和是否恰等於最大邊的平方。 ==========================================================================


<a id="uva-11875_brick-game"></a>

### UVa 11875 — Brick Game／積木遊戲隊長年齡 (排序數列中位數)

- 原始碼：[11875_brick-game.c](11875_brick-game.c)
- 難度：UVa Star 1
- 演算法：sorting, array

**English description:** Find age of team captain (median of N sorted player ages, where N is odd).

**中文詳細描述：** 隊伍共有奇數個隊員，年齡已依升序排序，隊長為年齡居中的隊員，求隊長年齡 (中位數)。

**English approach:** Median of sorted odd-length array: ages[N / 2].

**中文解題思路：** 已排序奇數長度陣列的中位數直接取索引下標 N / 2。 ==========================================================================


<a id="uva-11876_n-plus-nod-n"></a>

### UVa 11876 — N + NOD (N)／N + 因數個數序列 (前綴和與二分查找)

- 原始碼：[11876_n-plus-nod-n.c](11876_n-plus-nod-n.c)
- 難度：Easy
- 演算法：math, number-theory, binary-search

**English description:** Sequence begins with A_0 = 1, and A_i = A_{i-1} + NOD(A_{i-1}) where NOD is number of divisors. Count sequence elements in [A, B].

**中文詳細描述：** 數列定義為 A_0 = 1, A_i = A_{i-1} + NOD(A_{i-1})（NOD 為因數個數），求區間 [A, B] 內包含多少個數列元素。

**English approach:** Precompute NOD up to 1,000,000 using sieve. Generate sequence A until > 1,000,000 (around 70,000 terms). Query range [A, B] via binary search.

**中文解題思路：** 線性篩法預處理因數個數 NOD(n)，遞推生成序列數組（約 7 萬項達到 100 萬），每次詢問用二分查找 (upper_bound - lower_bound)。 ==========================================================================


<a id="uva-11877_the-coco-cola-store"></a>

### UVa 11877 — The Coco-Cola Store／可口可樂商店空瓶借還

- 原始碼：[11877_the-coco-cola-store.c](11877_the-coco-cola-store.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Exchange 3 empty bottles for 1 full bottle with bottle borrowing permitted. Find max bottles drank.

**中文詳細描述：** 3 個空瓶換 1 瓶新飲料，可向老闆借空瓶但最終須還清，求最多可喝到的可樂瓶數 (等同 n / 2)。

**English approach:** Integer division: n / 2.

**中文解題思路：** 每消耗 2 個空瓶即可淨喝 1 瓶可樂，可喝瓶數恆等於 n / 2。 ==========================================================================


<a id="uva-11878_homework-checker"></a>

### UVa 11878 — Homework Checker／作業檢查員

- 原始碼：[11878_homework-checker.c](11878_homework-checker.c)
- 難度：Easy
- 演算法：string, parsing, math

**English description:** Count how many arithmetic equations like 'a+b=c' or 'a-b=c' are graded correctly when answers marked '?' are ignored.

**中文詳細描述：** 檢查給定類似 'a+b=c' 或 'a-b=c' 的算式，統計其中計算正確的數量（答案為 '?' 者不計）。

**English approach:** Parse equations with sscanf, check if answer is '?', otherwise verify if a + b == c or a - b == c.

**中文解題思路：** 使用 sscanf 解析算式，若答案為 '?' 則跳過，否則驗證 a + b == c 或 a - b == c 是否成立。 ==========================================================================


<a id="uva-11879_multiple-of-17"></a>

### UVa 11879 — Multiple of 17／十七的倍數大數整除性判定

- 原始碼：[11879_multiple-of-17.c](11879_multiple-of-17.c)
- 難度：UVa Star 1
- 演算法：math, number-theory

**English description:** Check if a very large integer (up to 100 digits) is divisible by 17.

**中文詳細描述：** 判定給定超長十進位大整數 (長達 100 位) 是否為 17 的倍數。

**English approach:** Modulo arithmetic on string digits: cur = (cur * 10 + digit) % 17. At end, check if cur == 0.

**中文解題思路：** 逐位掃描大數數字字串，透過霍納法則 (Horner's rule) 維護累計餘數 cur = (cur * 10 + d) % 17，最後檢驗餘數是否為 0。 ==========================================================================


<a id="uva-11889_benefit"></a>

### UVa 11889 — Benefit／利益最大化 (LCM逆算與最小B值)

- 原始碼：[11889_benefit.c](11889_benefit.c)
- 難度：Medium
- 演算法：math, number-theory, lcm, gcd

**English description:** Given A and C, find the smallest positive integer B such that LCM(A, B) = C. If no such B exists, output 'NO SOLUTION'.

**中文詳細描述：** 給定整數 A 與 C，求滿足 LCM(A, B) = C 的最小正整數 B；若無解輸出 NO SOLUTION。

**English approach:** C must be divisible by A. Prime factorize A and C. For each prime, if power in C > power in A, B must contain prime^(power in C).

**中文解題思路：** 若 C % A != 0 則無解。對 A 與 C 做質因數分解：若 C 中質因數冪次大於 A，則 B 必須包含該質因數在 C 中的全部冪次。 ==========================================================================
