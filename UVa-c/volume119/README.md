# UVa Volume 119

本卷收錄 21 份 C 解答，涵蓋 21 個 UVa 題號，以下依題號排序。

<a id="uva-11900_boiled-eggs"></a>

### UVa 11900 — Boiled Eggs／水煮蛋鍋具容量與重量貪婪計數

- 原始碼：[11900_boiled-eggs.c](11900_boiled-eggs.c)
- 難度：UVa Star 1
- 演算法：greedy

**English description:** Given sorted weights of N eggs, find the maximum number of eggs (up to P eggs and up to Q grams total) that can be boiled in the bowl.

**中文詳細描述：** 給定 N 顆已按重量排序的水煮蛋，鍋子最多容納 P 顆蛋且總重不超過 Q 克，求最多可同時煮幾顆蛋。

**English approach:** Greedy choice: pick lightest eggs in order while count < P and total_weight + weight[i] <= Q.

**中文解題思路：** 貪婪策略：由最輕的蛋依序選取，在顆數不超過 P 且累計重量不超過 Q 的條件下盡可能多取。 ==========================================================================


<a id="uva-11902_dominator"></a>

### UVa 11902 — Dominator／支配點判定

- 原始碼：[11902_dominator.c](11902_dominator.c)
- 難度：Medium
- 演算法：graph, dfs, dominator-tree

**English description:** Given a directed graph, determine for every pair (u, v) if node u dominates node v (every path from start 0 to v must pass through u).

**中文詳細描述：** 給定有向圖，判斷節點 u 是否為節點 v 的支配點（從起點 0 到 v 的所有路徑皆必經 u）。

**English approach:** First DFS to find all nodes reachable from 0. For each node u, run DFS ignoring u; any node reachable initially but not without u is dominated by u.

**中文解題思路：** 先求起點 0 能抵達的節點集合。枚舉節點 u，忽略 u 進行 DFS，原本可達而現在不可達的點即被 u 支配。 ==========================================================================


<a id="uva-11906_knight-in-a-war-grid"></a>

### UVa 11906 — Knight in a War Grid／騎士巡邏網格 (奇數與偶數入度格統計)

- 原始碼：[11906_knight-in-a-war-grid.c](11906_knight-in-a-war-grid.c)
- 難度：Medium
- 演算法：bfs, flood-fill, graph

**English description:** A knight jumps with step (M, N) on an R x C grid with water hazards. Count reachable cells that can be reached from an even vs odd number of cells.

**中文詳細描述：** 騎士以 (M, N) 步伐在含水障礙的網格中跳躍，求所有可達格子中，能由偶數個相異格子跳入與奇數個相異格子跳入的個數。

**English approach:** BFS from (0,0) to mark all reachable non-water cells. For each reachable cell, count distinct valid neighbors that could jump to it.

**中文解題思路：** BFS 標記所有可達非水域格子。對每個可達格子，統計周圍能跳到該點的相異可達格子數，分類奇偶性。 ==========================================================================


<a id="uva-11909_soya-milk"></a>

### UVa 11909 — Soya Milk／豆漿倒出體積計算

- 原始碼：[11909_soya-milk.c](11909_soya-milk.c)
- 難度：Easy
- 演算法：geometry, math

**English description:** A milk carton of size l x w x h is tilted by angle theta. Find the remaining volume of milk in mL.

**中文詳細描述：** 長寬高為 l x w x h 的豆漿盒傾斜 theta 度，求盒中剩餘的豆漿體積（毫升）。

**English approach:** If tilted water surface cuts the bottom (tan(theta) <= h/l): lost volume is a triangular prism 0.5 * l * (l*tan(theta)) * w. Otherwise, remaining volume is 0.5 * h * (h/tan(theta)) * w.

**中文解題思路：** 若液面未觸及底面（l * tan(theta) <= h），倒出部分為直角三角柱 0.5 * l^2 * tan(theta) * w；否則剩餘部分為三角柱 0.5 * h^2 / tan(theta) * w。 ==========================================================================


<a id="uva-11917_do-your-own-homework"></a>

### UVa 11917 — Do Your Own Homework／自己的作業自己寫

- 原始碼：[11917_do-your-own-homework.c](11917_do-your-own-homework.c)
- 難度：Easy
- 演算法：map, simulation, string

**English description:** Sparrow must finish a homework subject. Given time to finish each subject and a deadline D, decide if he can finish on time, late, or must do his own homework.

**中文詳細描述：** Sparrow 必須完成某科作業，給定各科所需天數與截止期限 D，判定能否準時完成、遲交完成或來不及。

**English approach:** Look up required days T for the requested subject: if T <= D print 'Yesss', if T <= D+5 print 'Late', else 'Do your own homework!'.

**中文解題思路：** 在科目清單中查詢所需天數 T：若 T <= D 則如期完成；若 T <= D+5 則遲交；否則需自己寫。 ==========================================================================


<a id="uva-11926_multitasking"></a>

### UVa 11926 — Multitasking／多任務調度衝突檢測

- 原始碼：[11926_multitasking.c](11926_multitasking.c)
- 難度：Medium
- 演算法：bitset, interval-collision

**English description:** Detect if one-time and recurring calendar appointments overlap in time using a bitset up to 1,000,000 minutes.

**中文詳細描述：** 利用位元陣列檢查單次與週期性重複的日程預約是否存在時間重疊衝突（時間上限 1,000,000 分鐘）。

**English approach:** Use a bool array or bitset of size 1,000,000. Mark each interval [start, end-1]. If any minute is already marked, conflict exists.

**中文解題思路：** 使用長度 1,000,000 的布林陣列，將各任務在半開區間 [start, end) 內的每一分鐘標記為 1，若遇已標記則衝突。 ==========================================================================


<a id="uva-11933_splitting-numbers"></a>

### UVa 11933 — Splitting Numbers／二進位有效位元交錯拆分

- 原始碼：[11933_splitting-numbers.c](11933_splitting-numbers.c)
- 難度：UVa Star 1
- 演算法：bit-manipulation

**English description:** Given integer N, split its set bits (1s) into integers a and b by alternating bits: 1st bit to a, 2nd to b, 3rd to a, etc.

**中文詳細描述：** 給定整數 N，將其二進位中所有為 1 的位元交替分配給 a 與 b：第奇數個 1 歸入 a，第偶數個 1 歸入 b。

**English approach:** Iterate bit positions 0 to 30. Track count of set bits; if bit is set and count is odd, add to a, else add to b.

**中文解題思路：** 走訪 0 到 30 位元，若該位元為 1 且為第奇數次遇到則 OR 入 a，若為偶數次遇到則 OR 入 b。 ==========================================================================


<a id="uva-11934_magic-formula"></a>

### UVa 11934 — Magic Formula／神奇二次多項式整除次數統計

- 原始碼：[11934_magic-formula.c](11934_magic-formula.c)
- 難度：UVa Star 1
- 演算法：math

**English description:** Given a, b, c, d, L, count how many x in [0, L] satisfy f(x) = ax^2 + bx + c is divisible by d.

**中文詳細描述：** 給定常數 a, b, c, d 與上限 L，計算在 0 <= x <= L 區間內滿足 f(x) = ax^2 + bx + c 能被 d 整除之 x 的個數。

**English approach:** Iterate x from 0 to L; evaluate f(x) and check if f(x) % d == 0.

**中文解題思路：** 循序走訪 x 自 0 至 L，計算二次多項式 f(x) 並檢驗其對 d 取模是否為 0，累加滿足條件之數量。 ==========================================================================


<a id="uva-11936_the-lazy-lumberjacks"></a>

### UVa 11936 — The Lazy Lumberjacks／偷懶的伐木工 (三角形邊長不等式)

- 原始碼：[11936_the-lazy-lumberjacks.c](11936_the-lazy-lumberjacks.c)
- 難度：UVa Star 1
- 演算法：geometry, math

**English description:** Determine if three log lengths can form a valid triangle.

**中文詳細描述：** 給定三根木材長度，判定能否將其拼成一個合法三角形 (任意兩邊之和大於第三邊)。

**English approach:** Check triangle inequality: a + b > c and a + c > b and b + c > a.

**中文解題思路：** 檢驗三組兩邊之和大於第三邊不等式，全滿足輸出 OK，否則輸出 Wrong!!。 ==========================================================================


<a id="uva-11942_lumberjack-sequencing"></a>

### UVa 11942 — Lumberjack Sequencing／伐木工人鬍鬚長度單調性排序判定

- 原始碼：[11942_lumberjack-sequencing.c](11942_lumberjack-sequencing.c)
- 難度：UVa Star 1
- 演算法：simulation, array

**English description:** Determine if sequence of 10 integers is strictly ordered (either monotonically increasing or decreasing).

**中文詳細描述：** 檢查 10 名伐木工人的鬍鬚長度數列是否呈現單調排序 (遞增排序或遞減排序)。

**English approach:** Check all adjacent pairs for non-decreasing (a[i] <= a[i+1]) or non-increasing (a[i] >= a[i+1]).

**中文解題思路：** 線性遍歷比對相鄰元素，若全滿足 a[i] <= a[i+1] 或全滿足 a[i] >= a[i+1] 則為 Ordered，否則為 Unordered。 ==========================================================================


<a id="uva-11946_code-number"></a>

### UVa 11946 — Code Number／數字密碼文字解碼 (Leet 語解密)

- 原始碼：[11946_code-number.c](11946_code-number.c)
- 難度：Easy
- 演算法：string, substitution

**English description:** Decode leet-speak messages by replacing digits 0-9 with their corresponding letters (e.g. 4->A, 3->E, 1->I, 0->O).

**中文詳細描述：** 將含有 0-9 數字替換的火星文 (Leet) 解碼為正常文字（如 4->A, 3->E, 1->I, 0->O）。

**English approach:** Direct character substitution using a 10-character lookup table.

**中文解題思路：** 建立 10 個數字對應大寫字母的查找表（3->E, 0->O, 4->A, 1->I, 7->T 等）進行直接字元替換。 ==========================================================================


<a id="uva-11947_cancer-or-scorpio"></a>

### UVa 11947 — Cancer or Scorpio／巨蟹座還是天蠍座 (懷孕週期與十二星座推算)

- 原始碼：[11947_cancer-or-scorpio.c](11947_cancer-or-scorpio.c)
- 難度：Easy
- 演算法：simulation, calendar, date-math

**English description:** Add 40 weeks (280 days) to the first day of last menstrual cycle to determine baby's birth date and astrological sign.

**中文詳細描述：** 在末次月經起始日加上 40 週（280 天）計算預產期，並判斷新生兒所屬的十二星座。

**English approach:** Advance calendar date by 280 days taking leap years into account. Map resulting month/day into zodiac date ranges.

**中文解題思路：** 日期累加 280 天推算預產期，根據月份與日期區間判斷所屬黃道十二星座。 ==========================================================================


<a id="uva-11951_area"></a>

### UVa 11951 — Area／購地面積與最小開銷 (最大面積預算子矩陣)

- 原始碼：[11951_area.c](11951_area.c)
- 難度：Medium
- 演算法：dp, 2d-prefix-sums, two-pointers

**English description:** Find a subgrid of maximum area within budget K. If multiple subgrids have the same maximum area, choose the one with minimum cost.

**中文詳細描述：** 在預算 K 內購買一塊面積最大的連續矩形土地；若面積相同，取購地花費最小者。

**English approach:** Enumerate row bounds r1 and r2. Collapse columns into 1D array, then use two pointers to find maximum width with sum <= K.

**中文解題思路：** 枚舉上下邊界，列壓縮為一維陣列後使用雙指針（滑動窗口）在 O(C) 內求不超過預算 K 的最大寬度，更新全局最大面積與最小花費。 ==========================================================================


<a id="uva-11953_battleships"></a>

### UVa 11953 — Battleships／海戰棋存活戰艦連通分量計數

- 原始碼：[11953_battleships.c](11953_battleships.c)
- 難度：UVa Star 2
- 演算法：graph, flood-fill, dfs

**English description:** Given a grid of '.', 'x' (alive ship part), and '@' (hit part), count ships (connected horizontal/vertical cells) that have at least one 'x'.

**中文詳細描述：** 給定海戰棋盤面，包含空海 '.'、完好戰艦部位 'x' 與被擊中部位 '@'，統計包含至少一個完好部位 'x' 的存活戰艦總數。

**English approach:** Flood fill (DFS) connected components of 'x' and '@'. Mark has_alive flag if any cell is 'x'. Count components with has_alive == 1.

**中文解題思路：** 以 DFS 漫水填充走訪相鄰的 'x' 與 '@' 形成整艘戰艦，若連通分量內包含至少一個 'x' 則存活戰艦數加一。 ==========================================================================


<a id="uva-11956_brainfuck"></a>

### UVa 11956 — Brainfuck／Brainfuck 解釋器模擬

- 原始碼：[11956_brainfuck.c](11956_brainfuck.c)
- 難度：Easy
- 演算法：simulation, interpreter

**English description:** Simulate Brainfuck memory operations on a 100-byte circular array initialized to 0 with commands: '>', '<', '+', '-', '.' (loop commands '[' and ']' do not appear).

**中文詳細描述：** 在 100 位元組的循環數組上模擬 Brainfuck 記憶體操作（支援 > 右移、< 左移、+ 加一、- 減一，遇 256 取模）。

**English approach:** Maintain pointer ptr (0 to 99) with wrap-around, and byte values bytes[ptr] modulo 256.

**中文解題思路：** 維護指針 ptr (模 100 循環) 與記憶體值 byte[ptr] (模 256 循環)，遍歷指令字符更新狀態。 ==========================================================================


<a id="uva-11984_a-change-in-thermal-unit"></a>
### UVa 11984 — A Change in Thermal Unit／溫度單位變化

- 原始碼：[11984_a-change-in-thermal-unit.c](11984_a-change-in-thermal-unit.c)
- 演算法：單位換算（Math）

**English description:**

Each case gives an initial Celsius temperature `C` and an increase `d` measured in Fahrenheit degrees. Convert only the temperature difference to Celsius, add it to `C`, and output the final Celsius temperature.

**中文詳細描述：**

每組輸入給初始攝氏溫度 `C`，以及以華氏「溫差」表示的增加量 `d`。溫差換算不需加減 32，只要計算 `d × 5/9`，再加回 `C`，最後依指定精度輸出新的攝氏溫度。

<a id="uva-11987_almost-union-find"></a>

### UVa 11987 — Almost Union-Find／近似並查集 (支援單點移動的並查集)

- 原始碼：[11987_almost-union-find.c](11987_almost-union-find.c)
- 難度：Hard
- 演算法：disjoint-set-union

**English description:** Maintain sets supporting: union(p, q), move(p, to_set_of_q), and query sum & count of elements in set of p.

**中文詳細描述：** 維護支援合併集合、將單一元素 p 移動到 q 所在集合，以及查詢集合元素個數與元素和的並查集。

**English approach:** Assign a virtual node ID for each element index. On move(p, q), allocate a new virtual node for p and link to component of q.

**中文解題思路：** 將每個數值透過虛擬節點進行間接定址；執行移動操作時，為該數值重新分配新的虛擬節點編號並加入目標集合。 ==========================================================================


<a id="uva-11988_broken-keyboard"></a>

### UVa 11988 — Broken Keyboard (a.k.a. Beiju Text)／壞掉的鍵盤雙向游標鏈結串列

- 原始碼：[11988_broken-keyboard.c](11988_broken-keyboard.c)
- 難度：UVa Star 2
- 演算法：data-structures, linked-list

**English description:** Given a text with Home ('[') and End (']') keys randomly pressed, reconstruct the final string output on screen.

**中文詳細描述：** 鍵盤按鍵接觸不良導致在打字時隨機觸發 Home ('[') 與 End (']') 鍵，還原最終在螢幕上呈現的完整字串。

**English approach:** Use linked list or array of pointers. '[' moves insert cursor to head of list, ']' moves cursor to tail. Each character inserts at cursor.

**中文解題思路：** 使用鏈結串列模擬游標移動：遇到 '[' 游標跳至頭部，遇到 ']' 游標跳至尾部，逐字插入，時間複雜度 O(N)。 ==========================================================================


<a id="uva-11991_easy-problem-from-rujia-liu"></a>

### UVa 11991 — Easy Problem from Rujia Liu?／特定數值第 K 次出現位置查詢

- 原始碼：[11991_easy-problem-from-rujia-liu.c](11991_easy-problem-from-rujia-liu.c)
- 難度：UVa Star 2
- 演算法：hash, array

**English description:** Given an array of integers, answer queries asking for the 1-based index of the k-th occurrence of value v.

**中文詳細描述：** 給定一個整數陣列，多次查詢數值 v 在陣列中第 k 次出現時的下標位置 (從 1 開始計數)。

**English approach:** Store indices of occurrences for each value in dynamic lists or query via direct scanning.

**中文解題思路：** 對每個出現數值維護出現下標列表，若查詢之第 k 次超出總次數則回傳 0，否則回傳第 k 個下標。 ==========================================================================


<a id="uva-11995_i-can-guess-the-data-structure"></a>

### UVa 11995 — I Can Guess the Data Structure!／資料結構型態猜測與識別

- 原始碼：[11995_i-can-guess-the-data-structure.c](11995_i-can-guess-the-data-structure.c)
- 難度：UVa Star 2
- 演算法：data-structures, simulation

**English description:** Given a sequence of push and pop operations, determine if the underlying container is a stack, queue, priority queue, impossible, or not sure.

**中文詳細描述：** 給定一系列插入與取出資料的操作紀錄，判斷背後的容器是堆疊、佇列、優先佇列、無法判定或互相矛盾。

**English approach:** Simulate all 3 containers simultaneously. Check which ones successfully match every pop operation.

**中文解題思路：** 同步模擬 Stack、Queue 與 Priority Queue 三種結構，逐一比對取出值是否相符，統計吻合之容器數量。 ==========================================================================


<a id="uva-11997_k_smallest_sums"></a>

### UVa 11997 — K Smallest Sums／K 個陣列中取元素的最小 K 個和

- 原始碼：[11997_k_smallest_sums.c](11997_k_smallest_sums.c)
- 難度：Hard
- 演算法：data-structure, priority-queue, heap

**English description:** Given K sorted arrays of K integers each, find the K smallest sums formed by choosing one element from each array.

**中文詳細描述：** 給定 K 個長度為 K 的非遞減陣列，從每個陣列各選一個數字相加，求所有可能和中最小的 K 個和。

**English approach:** Iteratively merge two sorted arrays of size K at a time using a min-heap to extract the K smallest pair sums.

**中文解題思路：** 兩兩合併：每次使用優先佇列將目前最小的 K 個和與下一個陣列合併，保持陣列大小始終為 K。 ==========================================================================
