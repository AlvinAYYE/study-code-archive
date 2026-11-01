# UVa Volume 117

本卷收錄 22 份 C 解答，涵蓋 20 個 UVa 題號，以下依題號排序。

<a id="uva-11703_sqrt-log-sin"></a>

### UVa 11703 — sqrt log sin／平方根對數正弦遞推數列

- 原始碼：[11703_sqrt-log-sin.c](11703_sqrt-log-sin.c)
- 難度：Easy
- 演算法：dp, math

**English description:** Compute x_i = (x_{i - sqrt(i)} + x_{ln(i)} + x_{i*sin^2(i)}) mod 1,000,000 with x_0 = 1.

**中文詳細描述：** 計算遞推數列 x_i = (x_{i - sqrt(i)} + x_{ln(i)} + x_{i*sin^2(i)}) mod 1,000,000，初值 x_0 = 1。

**English approach:** Precompute array up to 1,000,000 in O(N) using floor and double math functions.

**中文解題思路：** 利用動態規劃陣列由 1 遞推至 1,000,000，下標使用 floor(i - sqrt(i))、floor(log(i))、floor(i * sin(i)^2)。 ==========================================================================


<a id="uva-11709_trust-groups"></a>

### UVa 11709 — Trust groups／信任群體 (強連通分量計數)

- 原始碼：[11709_trust-groups.c](11709_trust-groups.c)
- 難度：Medium
- 演算法：graph, scc, tarjan, kosaraju

**English description:** Find the number of strongly connected components (groups where trust is mutual directly or indirectly) in a directed trust graph.

**中文詳細描述：** 求有向信任關係圖中強連通分量 (SCC) 的總數量。

**English approach:** Run Tarjan's or Kosaraju's algorithm to partition the directed graph into strongly connected components and count them.

**中文解題思路：** 使用 Tarjan 演算法依據 dfn 與 low 標記求強連通分量個數。 ==========================================================================


<a id="uva-11710_expensive-subway"></a>

### UVa 11710 — Expensive subway／昂貴的地鐵 (最小生成樹連通性)

- 原始碼：[11710_expensive-subway.c](11710_expensive-subway.c)
- 難度：Medium
- 演算法：graph, mst, kruskal

**English description:** Determine the minimum cost to build a subway network connecting all stations starting from a given home station, or report 'Impossible'.

**中文詳細描述：** 求連接所有地鐵站的最小修建成本，若無法連通所有站點則輸出 Impossible。

**English approach:** Run Kruskal's algorithm. Check if total edges in MST equals n - 1. If yes, print total weight; otherwise impossible.

**中文解題思路：** 使用 Kruskal 演算法求最小生成樹，若選取的邊數恰好為 n - 1 則輸出總權重，否則不可達。 ==========================================================================


<a id="uva-11713_abstract-names"></a>

### UVa 11713 — Abstract Names／抽象姓名母音互換等價比對

- 原始碼：[11713_abstract-names.c](11713_abstract-names.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Two names are equivalent if they have same length, consonants match identically, and any mismatch only substitutes a vowel for another vowel.

**中文詳細描述：** 若兩個名字長度相同、所有子音字母完全一致，且母音 (a, e, i, o, u) 僅能與其他母音互相替換，則判定兩名字等價。

**English approach:** Check strlen equality. For each index, consonants must be identical; if one is vowel, both must be vowels.

**中文解題思路：** 比對兩字串長度，逐字元檢查：非母音者必須完全相等，若是母音則另一方也必須同為五大元音字母之一。 ==========================================================================


<a id="uva-11715_car"></a>

### UVa 11715 — Car／等加速度直線運動物理運動學公式

- 原始碼：[11715_car.c](11715_car.c)
- 難度：UVa Star 1
- 演算法：physics, math

**English description:** Compute missing kinematic quantities given 3 out of 5 variables (u, v, t, a, s) under constant acceleration.

**中文詳細描述：** 在等加速度直線運動中，已知初速 u、末速 v、時間 t、加速度 a、位移 s 中的三項，求出其餘兩項未知量。

**English approach:** Apply standard equations: v = u + at, s = (u + v)/2 * t, v^2 = u^2 + 2as.

**中文解題思路：** 依據題意代入等加速度運動學四公式分別求解位移與時間等相應物理量。 ==========================================================================


<a id="uva-11716_digital-fortress"></a>

### UVa 11716 — Digital Fortress／數位堡壘矩陣轉置解密

- 原始碼：[11716_digital-fortress.c](11716_digital-fortress.c)
- 難度：UVa Star 1
- 演算法：string, math

**English description:** Given ciphertext of length L, if L is a perfect square K*K, decode by reading the K x K matrix column by column; otherwise output INVALID.

**中文詳細描述：** 給定長度為 L 的密文字串，若 L 為完全平方數 K*K，則依縱行優先 (轉置) 還原出原始明文字串；否則判定為 INVALID。

**English approach:** Check if integer root K = round(sqrt(L)) satisfies K * K == L. Read row-major matrix in column-major order.

**中文解題思路：** 驗證 L 是否為完全平方數 K^2，若是則將字串填入 K x K 矩陣，並以雙重迴圈逐行 (先列後欄) 讀取輸出解密字串。 ==========================================================================


<a id="uva-11723_numbering-roads"></a>

### UVa 11723 — Numbering Roads／道路門牌後綴英文字母指派

- 原始碼：[11723_numbering-roads.c](11723_numbering-roads.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Given R roads and N base numbers with 26 letters (A-Z) available as suffixes, find minimum letters needed (0 to 26), or report impossible.

**中文詳細描述：** 給定 R 條道路與 N 個基本整數編號，可搭配 26 個英文字母 (A-Z) 作為後綴，求最少需要動用幾個英文字母，若超過 26 則無解。

**English approach:** Number of suffixes needed = ceil((R - N) / N) = (R - 1) / N. If > 26 return -1.

**中文解題思路：** 除了 N 個純整數外，其餘道路需後綴字母，計算 (R - 1) / N，若 <= 26 回傳該整數，否則判定無解回傳 -1。 ==========================================================================


<a id="uva-11727_cost-cutting"></a>
### UVa 11727 — Cost Cutting／削減成本

- 原始碼：[11727_cost-cutting.c](11727_cost-cutting.c)
- 演算法：中位數（Sorting, Math）

**English description:**

Each case supplies the salaries of three employees. To remove the highest and lowest salaries, find the middle value and output it with the case number.

**中文詳細描述：**

每組輸入三名員工的薪資，為了裁掉最高與最低薪資者，需要找出三數中的中位數。可排序或排除最大、最小值，最後以指定的案例格式輸出中間薪資。

<a id="uva-11727_cost-cutting-pr"></a>

### UVa 11727 — Cost Cutting／削減成本保留中等薪資 (三數取中位數)

- 原始碼：[11727_cost-cutting-pr.c](11727_cost-cutting-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：sorting, math

**English description:** Given 3 employee salaries, find the middle salary (neither highest nor lowest).

**中文詳細描述：** 三位員工薪資互不相同，公司為精簡開銷，決定資遣最高薪與最低薪員工，求留任的中等薪資值 (三數中位數)。

**English approach:** Sort 3 numbers or compute (a + b + c) - min(a, b, c) - max(a, b, c).

**中文解題思路：** 三數取中位數：三數總和減去最大值與最小值，即為留任的中等薪資。 ==========================================================================


<a id="uva-11728_alternate-task"></a>

### UVa 11728 — Alternate Task／替代任務 (因數和反查)

- 原始碼：[11728_alternate-task.c](11728_alternate-task.c)
- 難度：Easy
- 演算法：math, number-theory, sum-of-divisors

**English description:** Given integer S, find the largest integer N <= 1000 such that the sum of divisors of N equals S.

**中文詳細描述：** 給定整數 S，求所有因數之和剛好等於 S 的最大整數 N（N <= 1000）。

**English approach:** Precompute sum of divisors for all numbers 1 to 1000. Iterate backwards from 1000 to find the first N matching sum S.

**中文解題思路：** 預先計算 1~1000 每個整數的所有因數和，從 1000 向下倒序搜尋第一個因數和為 S 的整數 N。 ==========================================================================


<a id="uva-11729_commando-war"></a>
### UVa 11729 — Commando War／突擊隊作戰

- 原始碼：[11729_commando-war.c](11729_commando-war.c)
- 演算法：貪心排序、排程（Greedy, Scheduling）

**English description:**

Each soldier requires a briefing time before independently carrying out a job that takes an execution time. Briefings occur one at a time; order the soldiers to minimize when all jobs finish, and output that minimum completion time.

**中文詳細描述：**

每位士兵有簡報時間 `B` 與任務執行時間 `J`。指揮官一次只能為一人簡報，但士兵聽完後可獨立執行任務；將 `J` 較長者優先簡報，可最小化所有任務完成的時刻，最後輸出該最短總時間。

<a id="uva-11733_airports"></a>

### UVa 11733 — Airports／機場建設 (Kruskal帶閥值生成森林)

- 原始碼：[11733_airports.c](11733_airports.c)
- 難度：Medium
- 演算法：graph, mst, kruskal

**English description:** Given costs of building roads between cities and building an airport (cost A), find minimum total cost to make every city accessible to an airport.

**中文詳細描述：** 修建公路與建造機場（費用 A），使每座城市都能連通到至少一座機場，求最小成本與機場座數。

**English approach:** Run Kruskal's MST. Only add road edges if cost < A. Every remaining connected component must build an airport.

**中文解題思路：** 以 Kruskal 演算法求生成森林：僅選取建路費用嚴格小於機場費用 A 的邊，其餘獨立連通分量各自建造一座機場。 ==========================================================================


<a id="uva-11734_big-number-of-teams-will-solve-this"></a>

### UVa 11734 — Big Number of Teams will Solve This／評測系統空格格式錯誤判別

- 原始碼：[11734_big-number-of-teams-will-solve-this.c](11734_big-number-of-teams-will-solve-this.c)
- 難度：UVa Star 1
- 演算法：string

**English description:** Compare team submission with judge output: Yes if identical; Output Format Error if identical after removing all spaces; else Wrong Answer.

**中文詳細描述：** 比對參賽者輸出與裁判標準輸出：完全相同為 Yes；若去除所有空格後相同則為 Output Format Error；否則為 Wrong Answer。

**English approach:** Check exact strcmp. If not equal, strip all spaces from both strings and compare.

**中文解題思路：** 先以 strcmp 比較完全相等；若不相等則分別去除所有空格字元再行比較，相等判定為格式錯誤，否則為解答錯誤。 ==========================================================================


<a id="uva-11742_social-constraints"></a>

### UVa 11742 — Social Constraints／社交距離約束排列計數

- 原始碼：[11742_social-constraints.c](11742_social-constraints.c)
- 難度：Easy
- 演算法：permutations, brute-force

**English description:** Count permutations of n teenagers sitting in a row such that all distance constraints (|pos(a) - pos(b)| <= c or >= -c) are met.

**中文詳細描述：** 求 n 個青少年排成一排的座位排列數，使其同時滿足所有正負距離約束條件。

**English approach:** Since n <= 8, generate all n! permutations (at most 40,320) and check all m constraints for each.

**中文解題思路：** 由於 n <= 8，直接枚舉全排列（最多 40320 種），逐一驗證是否符合各限制條件並計數。 ==========================================================================


<a id="uva-11743_credit-check"></a>

### UVa 11743 — Credit Check／信用卡號碼校驗 (盧恩演算法 Luhn)

- 原始碼：[11743_credit-check.c](11743_credit-check.c)
- 難度：UVa Star 1
- 演算法：simulation, math

**English description:** Validate 16-digit credit card number using Luhn algorithm: double alternate digits, sum digits of products, check sum % 10 == 0.

**中文詳細描述：** 使用盧恩演算法驗證 16 位信用卡號：奇數位數字乘以 2 後各位數位加總，加上偶數位數字，若總和尾數為 0 則合法。

**English approach:** Iterate digits: for odd positions (from right), d = 2*digit; add d/10 + d%10. For even positions, add digit. Check total % 10 == 0.

**中文解題思路：** 依據標準 Luhn 規則計算位數加權：相隔一位乘以 2 (兩位數拆開相加)，其餘直接加總，驗證總和 mod 10 是否為 0。 ==========================================================================


<a id="uva-11747_heavy-cycle-edges"></a>

### UVa 11747 — Heavy Cycle Edges／環路最大冗餘邊 Kruskal 篩選

- 原始碼：[11747_heavy-cycle-edges.c](11747_heavy-cycle-edges.c)
- 難度：UVa Star 2
- 演算法：graph, mst, kruskal

**English description:** Find all edges in an undirected graph that are the heaviest edge on some cycle (i.e. edges discarded by Kruskal's algorithm).

**中文詳細描述：** 在無向圖中找出所有落在某環路上的最重邊 (即 Kruskal 最小生成樹演算法中因形成環而被丟棄的邊)。

**English approach:** Run Kruskal's algorithm on edges sorted by weight. Any edge whose endpoints are already in the same connected component is collected and printed.

**中文解題思路：** 按權重排序邊集執行 Kruskal 演算法：每當遇到兩端點已連通的邊，即為環中最重邊，收集此類邊排序輸出。 ==========================================================================


<a id="uva-11764_jumping-mario"></a>
### UVa 11764 — Jumping Mario／瑪利歐跳躍

- 原始碼：[11764_jumping-mario.c](11764_jumping-mario.c)
- 演算法：相鄰比較（Array, Simulation）

**English description:**

Given the heights of consecutive walls, count how many transitions go to a higher wall and how many go to a lower wall. Equal adjacent heights count as neither; output both counts for each case.

**中文詳細描述：**

每組輸入依序給出瑪利歐遇到的牆高。逐一比較相鄰兩面牆，後者較高時計為一次 high jump，較低時計為一次 low jump，相等則不計，最後依案例格式輸出兩種次數。

<a id="uva-11764_jumping-mario-pr"></a>

### UVa 11764 — Jumping Mario／跳躍瑪莉歐 (高跳與低跳次數統計)

- 原始碼：[11764_jumping-mario-pr.c](11764_jumping-mario-pr.c)
- 難度：UVa Star 1
- 解答版本：PR 同題替代實作
- 演算法：simulation, array

**English description:** Count number of high jumps (wall[i] > wall[i-1]) and low jumps (wall[i] < wall[i-1]) in Mario's run.

**中文詳細描述：** 瑪莉歐在不同高度的城牆間奔跑跳躍，統計由左至右跳越時的高跳 (往高處跳) 與低跳 (往低處跳) 的次數。

**English approach:** Compare adjacent wall heights: if w[i] > w[i-1] high++, if w[i] < w[i-1] low++.

**中文解題思路：** 單次線性掃描比對相鄰牆高：後者大於前者則高跳次數 +1，小於則低跳次數 +1，相等不計。 ==========================================================================


<a id="uva-11770_lighting-away"></a>

### UVa 11770 — Lighting Away／點亮全場 (有向圖強連通分量縮點)

- 原始碼：[11770_lighting-away.c](11770_lighting-away.c)
- 難度：Medium
- 演算法：graph, scc, tarjan, topological-sort

**English description:** Turning on a light manually triggers all lights reachable from it. Find minimum lights to turn on manually to illuminate all lights.

**中文詳細描述：** 手動點亮一盞燈會連鎖點亮其所有可達的燈，求最少需手動點亮幾盞燈以照亮所有燈光。

**English approach:** Condense graph into SCCs. In the resulting DAG of components, count SCCs with in-degree 0.

**中文解題思路：** 以 Tarjan 演算法將有向圖縮點為強連通分量 DAG，統計入度為 0 的強連通分量數量即為最少需手動點亮的燈數。 ==========================================================================


<a id="uva-11777_automate-the-grades"></a>

### UVa 11777 — Automate the Grades／學生成績自動評等系統

- 原始碼：[11777_automate-the-grades.c](11777_automate-the-grades.c)
- 難度：UVa Star 1
- 演算法：basics, math

**English description:** Calculate total grade from Term 1 (20), Term 2 (20), Final (30), Attendance (10), and average of best 2 out of 3 quizzes (20). Output letter grade A-F.

**中文詳細描述：** 根據兩次期中考 (各佔20%)、期末考 (30%)、出席率 (10%) 與三次隨堂測驗取最高兩次平均 (20%) 計算學期總分並判定等第 (A/B/C/D/F)。

**English approach:** Find sum of highest 2 quiz scores and divide by 2. Add all components and categorize into letter grade.

**中文解題思路：** 三次隨堂小考取最高兩次相加除以二，加上其餘項求得百分制總分，依照 90/80/70/60 分數線判定等第代碼。 ==========================================================================


<a id="uva-11790_murcias-skyline"></a>

### UVa 11790 — Murcia's Skyline／穆爾西亞的天際線

- 原始碼：[11790_murcias-skyline.c](11790_murcias-skyline.c)
- 難度：Medium
- 演算法：dp, lis, lds

**English description:** Given building heights and widths, find the maximum total width of strictly increasing and strictly decreasing subsequences of heights.

**中文詳細描述：** 給定大樓的高度與寬度，求高度嚴格遞增與嚴格遞減的子序列中，總寬度的最大值。

**English approach:** Weighted LIS and LDS using dynamic programming in O(N^2). dp_inc[i] = w[i] + max(dp_inc[j]) for h[j] < h[i].

**中文解題思路：** 帶權重的 LIS 與 LDS 動態規劃：dp_inc[i] = w[i] + max(dp_inc[j])（當 h[j] < h[i]）。 ==========================================================================


<a id="uva-11799_horror-dash"></a>
### UVa 11799 — Horror Dash／恐怖衝刺

- 原始碼：[11799_horror-dash.c](11799_horror-dash.c)
- 演算法：最大值搜尋（Linear Scan）

**English description:**

Each case lists the running speeds of all students chased by a clown. The clown must match the fastest student, so find and output the maximum speed with the case number.

**中文詳細描述：**

每組輸入列出所有學生的奔跑速度。小丑若要追上所有人，速度至少要等於其中最大值；以一次線性掃描找出最快速度，再連同案例編號輸出。
