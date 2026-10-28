# UVa Volume 101 題目索引

本目錄收錄 23 支 C 題目檔，涵蓋 23 個題目。

<a id="uva-10101_bangla-numbers"></a>
### UVa 10101 — Bangla Numbers／孟加拉數字

- 原始碼：[10101_bangla-numbers.c](10101_bangla-numbers.c)
- 演算法：遞迴、數值分組格式化（Recursion, Simulation）

**English description:** Convert each nonnegative integer to the Bangla numbering system, using kuti, lakh, hajar, and shata at their proper place values while preserving the required case numbering format.

**中文詳細描述：** 輸入多個非負整數；任務是依孟加拉計數單位把數字拆成 kuti、lakh、hajar、shata 與剩餘部分。程式由大單位遞迴分解，特別處理 kuti 可重複出現的層級，並在每行輸出案例編號與格式化結果。

<a id="uva-10104_euclid-problem"></a>
### UVa 10104 — Euclid Problem／歐幾里得問題

- 原始碼：[10104_euclid-problem.c](10104_euclid-problem.c)
- 演算法：擴展歐幾里得演算法（Extended Euclidean Algorithm）

**English description:** Given integers A and B, find integers X and Y such that A×X + B×Y equals D, where D is the greatest common divisor of A and B. Print X, Y, and D.

**中文詳細描述：** 每行輸入整數 A、B；除了求最大公因數 D，還要找出貝祖係數 X、Y，使 AX+BY=D。程式以擴展歐幾里得演算法沿除法遞迴回推係數，逐組輸出 X、Y 與 D。

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

<a id="uva-10115_automatic-editing"></a>
### UVa 10115 — Automatic Editing／自動編輯

- 原始碼：[10115_automatic-editing.c](10115_automatic-editing.c)
- 演算法：字串搜尋與替換、循序模擬（String, Simulation）

**English description:** Apply replacement rules to a text in the given order. For each rule, repeatedly replace the leftmost occurrence of its search string until no occurrence remains, then continue with the next rule and print the final text.

**中文詳細描述：** 輸入多組搜尋字串與替換字串，接著輸入待編輯文字；規則必須依序執行，同一規則要持續替換最左邊匹配處，直到找不到再換下一條，最後輸出完成文字。

<a id="uva-10127_ones"></a>
### UVa 10127 — Ones／全 1 數

- 原始碼：[10127_ones.c](10127_ones.c)
- 演算法：模運算、鴿籠原理（Modular Arithmetic）

**English description:** For each input integer n, find the smallest length of a decimal number consisting only of digit 1 that is divisible by n.

**中文詳細描述：** 每行輸入整數 n；要找最短的 1、11、111……使其可被 n 整除，並輸出這個全 1 數的位數。程式不實際建立巨大整數，而用 `remainder = (remainder×10+1) mod n` 逐位更新，首次餘數為 0 時即得到答案。

<a id="uva-10129_play-on-words"></a>
### UVa 10129 — Play on Words／文字接龍

- 原始碼：[10129_play-on-words.c](10129_play-on-words.c)
- 演算法：有向歐拉路徑、入出度、並查集（Eulerian Path, DSU）

**English description:** Determine whether all given words can be ordered so that the final letter of each word equals the first letter of the next. This is an Euler-trail test on a directed graph of letters.

**中文詳細描述：** 輸入多個單字；把每個單字視為從首字母指向尾字母的一條有向邊，問題是能否把每條邊恰用一次排成接龍。完整判定需同時檢查入度與出度差，以及所有有邊字母的弱連通性，最後輸出能否開門。

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

<a id="uva-10137_the-trip"></a>
### UVa 10137 — The Trip／旅行分帳

- 原始碼：[10137_the-trip.c](10137_the-trip.c)
- 演算法：金額整數化、平均分配、貪心（Greedy, Simulation）

**English description:** Students paid different amounts on a trip. Compute the minimum amount of money that must change hands so everyone ends with expenses equal to within one cent.

**中文詳細描述：** 輸入每位學生已支付的金額；要在分攤至多相差一分的前提下，算出最少需要轉手多少錢。程式把金額轉為分以避免浮點誤差，根據總額的向下與向上平均分別累計多付與少付部分，取必要交換量並以貨幣格式輸出。

<a id="uva-10140_prime-distance"></a>
### UVa 10140 — Prime Distance／質數距離

- 原始碼：[10140_prime-distance.c](10140_prime-distance.c)
- 演算法：分段質數篩、相鄰質數掃描（Segmented Sieve）

**English description:** Within each inclusive interval [L, U], find the pair of adjacent primes with the smallest gap and the pair with the largest gap. Report when fewer than two primes are present.

**中文詳細描述：** 每筆輸入一個閉區間 [L,U]；先找出區間內所有質數，再只比較排序後相鄰質數，輸出距離最近與最遠的兩對。適合用小質數篩去標記區間中的合數；若不足兩個質數則輸出沒有相鄰質數。

<a id="uva-10152_shell-sort"></a>
### UVa 10152 — ShellSort／烏龜排序

- 原始碼：[10152_shell-sort.c](10152_shell-sort.c)
- 演算法：貪心、由底向上比對（Greedy, Simulation）

**English description:** Transform one stack of named turtles into a target stack using only the operation of moving any turtle to the top. Print a shortest sequence of turtle names to move.

**中文詳細描述：** 輸入目前的烏龜堆疊與目標順序；每次只能抽出一隻烏龜放到最上方，任務是用最少操作完成排列。從兩堆底部向上比對可保留已對齊的最長部分，其餘目標烏龜依需要輸出為搬移順序。

<a id="uva-10161_ant-on-a-chessboard"></a>
### UVa 10161 — Ant on a Chessboard／棋盤上的螞蟻

- 原始碼：[10161_ant-on-a-chessboard.c](10161_ant-on-a-chessboard.c)
- 演算法：平方層定位、座標數學（Math）

**English description:** Cells of an infinite chessboard are numbered along a square spiral. Given N, compute and print the column and row containing cell N.

**中文詳細描述：** 輸入螺旋編號 N，直到終止值；要找 N 在無限棋盤上的座標。程式以 `ceil(sqrt(N))` 找到 N 所在的正方形外層，再利用該層平方數、轉折點與奇偶方向計算列、欄，最後依題目順序輸出座標。

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

<a id="uva-10183_how-many-fibs"></a>
### UVa 10183 — How Many Fibs?／有多少個費波那契數？

- 原始碼：[10183_how-many-fibs.c](10183_how-many-fibs.c)
- 演算法：大整數、費波那契預處理、區間計數（Big Integer, Fibonacci）

**English description:** For each pair of arbitrarily large bounds a and b, count the Fibonacci numbers lying in the inclusive interval [a, b], stopping at the pair 0 0.

**中文詳細描述：** 輸入可能長達許多位的上下界 a、b，以 0 0 結束；要計算閉區間內有幾個費波那契數。完整作法需用大整數預先產生序列，再比較或二分找出區間端點並輸出數量。

<a id="uva-10188_automated-judge-script"></a>
### UVa 10188 — Automated Judge Script／自動評審程式

- 原始碼：[10188_automated-judge-script.c](10188_automated-judge-script.c)
- 演算法：字串比較、數字抽取（String, Simulation）

**English description:** Compare a team's output with the official output. Exact equality is Accepted; otherwise equal digit sequences produce Presentation Error, and all other differences produce Wrong Answer.

**中文詳細描述：** 輸入標準答案的多行文字與參賽輸出的多行文字。若包含換行在內完全相同則輸出 Accepted；否則各自抽出所有數字字元，數字序列仍相同便是 Presentation Error，不同則是 Wrong Answer，並附上案例編號。

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
