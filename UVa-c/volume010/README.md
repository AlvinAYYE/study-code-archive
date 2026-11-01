# UVa Volume 010 題目索引

本卷收錄 4 份 C 解答，涵蓋 4 個 UVa 題號，以下依題號排序。

<a id="uva-1001_say-cheese"></a>

### UVa 1001 — Say Cheese／起司乳酪洞最短路徑 (3D 穿洞 Dijkstra)

- 原始碼：[1001_say-cheese.c](1001_say-cheese.c)
- 難度：UVa Star 2
- 演算法：geometry, graph, dijkstra, shortest-path

**English description:** Find shortest time to travel between two points in Swiss cheese with spherical holes (time inside holes is 0).

**中文詳細描述：** 起司內部含有多個球形孔洞，在孔洞內部移動時間為 0。求起點到終點的最短時間 (加權圖 Dijkstra)。

**English approach:** Graph vertices: start, end, and n holes. Edge weight between holes i and j is max(0, dist(c_i, c_j) - r_i - r_j) * 10.

**中文解題思路：** 以起點、終點與 n 個球形洞為頂點建圖。兩球間移動距離為球心距離減去兩球半徑 (負數則為 0)，Dijkstra 求最短路。 ==========================================================================


<a id="uva-1002_country-roads"></a>

### UVa 1002 — Country Roads／鄉間小路瓶頸路徑最小化 (Minimax Shortest Path)

- 原始碼：[1002_country-roads.c](1002_country-roads.c)
- 難度：UVa Star 2
- 演算法：graph, mst, dijkstra

**English description:** Find path from city t to all other cities minimizing the maximum edge weight on the path.

**中文詳細描述：** 由指定城市 t 出發前往各城市，使路徑上的最大邊權值最小化 (Minimax 最短路 / 最小生成樹 MST)。

**English approach:** Modified Dijkstra: dist[v] = min(dist[v], max(dist[u], weight(u, v))).

**中文解題思路：** Dijkstra 變形演算法：鬆弛條件為 dist[v] = min(dist[v], max(dist[u], weight))，以優先佇列求解。 ==========================================================================


<a id="uva-1025_a_spy_in_the_metro"></a>

### UVa 1025 — A Spy in the Metro／地鐵裡的間諜 (動態規劃)

- 原始碼：[1025_a_spy_in_the_metro.c](1025_a_spy_in_the_metro.c)
- 難度：Medium
- 演算法：dynamic-programming, dag

**English description:** Find the minimum waiting time for a spy to meet an agent at station N at time T given metro timetables.

**中文詳細描述：** 給定地鐵時刻表，求間諜在時間 T 於第 N 站與特工會面時所需的最小車站月台等待時間。

**English approach:** DP state dp[t][i] = min waiting time to be at station i at time t. Transition: wait 1 min at i, or ride a rightbound/leftbound train.

**中文解題思路：** 動態規劃狀態 dp[t][i] 為時間 t 位於車站 i 的最少等待時間。轉移：在月台等 1 分鐘，或搭乘此時出發的向右/向左列車。 ==========================================================================


<a id="uva-1062_containers"></a>

### UVa 1062 — Containers／貨櫃堆疊

- 原始碼：[1062_containers.c](1062_containers.c)
- 難度：Medium
- 演算法：greedy, lis

**English description:** Find the minimum number of container stacks required to load cargo onto ships in alphabetical order.

**中文詳細描述：** 求最少需要多少個堆疊來放置貨櫃，使得所有貨櫃能依字母順序被裝船。

**English approach:** Greedily place each incoming container onto the top of the stack whose top letter is >= container letter with minimal difference; otherwise open a new stack.

**中文解題思路：** 貪心法：每個貨櫃放在頂部字元大於等於該貨櫃且頂部字元最小的堆疊上，若無合適堆疊則開啟新堆疊。 ==========================================================================
