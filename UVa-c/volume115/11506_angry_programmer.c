/*
 * ==========================================================================
 * UVa 11506 - Angry Programmer
 * Title-CN: 憤怒的程式設計師 (頂點割與最小割)
 * Difficulty: Hard
 * Tags: Network Flow, Min-Cut, Vertex Splitting
 * URL: https://onlinejudge.org/external/115/11506.pdf
 * ==========================================================================
 * [EN] Problem:
 *     Disconnect boss's computer from server by destroying minimum total cost of machines and wires.
 *
 * [中文] 題目描述:
 *     破壞電腦與電纜以切斷老闆電腦與伺服器的連線，求所需的最小破壞成本總和。
 *
 * [EN] Approach:
 *     Model as Min-Cut (Max-Flow): split intermediate vertex u into u_in and u_out with capacity cost[u]. Edges have wire capacities. Source is 1, sink is M.
 *
 * [中文] 解題思維:
 *     轉化為最小割問題：拆點法將中間節點 u 拆成 u_in 與 u_out，中間連邊容量為電腦成本 cost[u]，電纜連接為容量為電纜成本的雙向邊，求最大流。
 * ==========================================================================
 * UVa Online Judge Submission Template:
 * #include <stdio.h>
 * #include <stdlib.h>
 * #include <string.h>
 * #include <math.h>
 *
 * int main(void) {
 *     // Read input and call logic function
 *     return 0;
 * }
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define DINIC_INF 100000000

typedef struct {
    int to, cap, flow, rev;
} DinicEdge;

static DinicEdge dinic_adj[205][405];
static int dinic_deg[205];
static int dinic_level[205], dinic_ptr[205];

static void add_flow_edge(int from, int to, int cap) {
    dinic_adj[from][dinic_deg[from]] = (DinicEdge){to, cap, 0, dinic_deg[to]};
    dinic_deg[from]++;
    dinic_adj[to][dinic_deg[to]] = (DinicEdge){from, 0, 0, dinic_deg[from] - 1};
    dinic_deg[to]++;
}

static int dinic_bfs(int s, int t) {
    memset(dinic_level, -1, sizeof(dinic_level));
    dinic_level[s] = 0;
    int q[205], head = 0, tail = 0;
    q[tail++] = s;
    while (head < tail) {
        int u = q[head++];
        for (int i = 0; i < dinic_deg[u]; i++) {
            DinicEdge *e = &dinic_adj[u][i];
            if (e->cap > e->flow && dinic_level[e->to] == -1) {
                dinic_level[e->to] = dinic_level[u] + 1;
                q[tail++] = e->to;
            }
        }
    }
    return dinic_level[t] != -1;
}

static int dinic_dfs(int u, int t, int pushed) {
    if (pushed == 0 || u == t) return pushed;
    for (int *cid = &dinic_ptr[u]; *cid < dinic_deg[u]; (*cid)++) {
        DinicEdge *e = &dinic_adj[u][*cid];
        if (dinic_level[e->to] != dinic_level[u] + 1 || e->cap <= e->flow) continue;
        int tr = dinic_dfs(e->to, t, pushed < e->cap - e->flow ? pushed : e->cap - e->flow);
        if (tr == 0) continue;
        e->flow += tr;
        dinic_adj[e->to][e->rev].flow -= tr;
        return tr;
    }
    return 0;
}

int min_cut_angry_programmer(int m, int w, int *node_costs, int wires[][3]) {
    int total_nodes = 2 * m + 2;
    for (int i = 0; i <= total_nodes; i++) dinic_deg[i] = 0;

    // Node 1 is source (1_out = 1), Node m is sink (m_in = 2*m)
    // For i = 2..m-1: in = 2*i-1, out = 2*i
    for (int i = 2; i < m; i++) {
        add_flow_edge(2 * i - 1, 2 * i, node_costs[i]);
    }
    for (int i = 0; i < w; i++) {
        int u = wires[i][0], v = wires[i][1], c = wires[i][2];
        int u_out = (u == 1 ? 1 : 2 * u);
        int u_in  = (u == m ? 2 * m : 2 * u - 1);
        int v_out = (v == 1 ? 1 : 2 * v);
        int v_in  = (v == m ? 2 * m : 2 * v - 1);
        add_flow_edge(u_out, v_in, c);
        add_flow_edge(v_out, u_in, c);
    }
    int s = 1, t = (m == 1 ? 1 : 2 * m);
    if (m == 1) return 0;

    int max_flow = 0;
    while (dinic_bfs(s, t)) {
        memset(dinic_ptr, 0, sizeof(dinic_ptr));
        while (1) {
            int pushed = dinic_dfs(s, t, DINIC_INF);
            if (!pushed) break;
            max_flow += pushed;
        }
    }
    return max_flow;
}

int main(void) {

    int node_costs[5] = {0, 0, 10, 0, 0};
    int wires[2][3] = {{1, 2, 100}, {2, 3, 100}};
    // Boss 1 -> Node 2 (cost 10) -> Server 3. Breaking node 2 costs 10.
    int res = min_cut_angry_programmer(3, 2, node_costs, wires);
    int ok = (res == 10);
    printf("%s: UVa 11506 - Angry Programmer\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
