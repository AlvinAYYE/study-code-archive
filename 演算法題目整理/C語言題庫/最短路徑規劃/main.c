/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】在有向、非負權重的圖中，找起點到終點的最短路徑。採用 Dijkstra 演算法。
 * 【輸入】節點數 n、邊數 m、m 行「起點 終點 權重」、查詢起點
 * s 和終點 t。節點編號從 1 開始。
 * 【輸出】節點路徑和路徑長度；若不可達則印出無可行路徑。
 * 【閱讀順序】g[u][v] 存從 u 到 v 的直接成本，沒有邊時設成很大的
 * INF。d[v] 是目前已知最短距離。每輪挑尚未確定且 d 最小的節點 u，再用 u
 * 嘗試改善鄰點距離；pre 記錄每個節點的前一站。最後從 t 沿 pre 反向回溯。 【C 語法】INF
 * 代表「目前視為無限大」；static 陣列放在固定儲存區，避免大型矩陣超出 Windows 預設堆疊；used[]
 * 標記節點是否已確定最短距離。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 n m、m 筆有向邊 u v
 * weight、起點終點（節點編號 1..n）。 */
#include <stdio.h>
#define N 501
#define INF 4000000000000000000LL
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int vertex_count, edge_count, start_vertex, target_vertex;
    static long long edge_cost[N][N], best_distance[N];
    static int previous_vertex[N], visited[N];
    if (scanf("%d%d", &vertex_count, &edge_count) != 2 || vertex_count < 1 || vertex_count >= N ||
        edge_count < 0)
        return 1;
    for (int index = 1; index <= vertex_count; index++)
        for (int inner_index = 1; inner_index <= vertex_count; inner_index++)
            edge_cost[index][inner_index] = index == inner_index ? 0 : INF;
    for (int index = 0, current_vertex, neighbor_vertex; index < edge_count; index++) {
        long long edge_weight;
        if (scanf("%d%d%lld", &current_vertex, &neighbor_vertex, &edge_weight) != 3 ||
            current_vertex < 1 || current_vertex > vertex_count || neighbor_vertex < 1 ||
            neighbor_vertex > vertex_count || edge_weight < 0)
            return 1;
        if (edge_weight < edge_cost[current_vertex][neighbor_vertex])
            edge_cost[current_vertex][neighbor_vertex] = edge_weight;
    }
    if (scanf("%d%d", &start_vertex, &target_vertex) != 2 || start_vertex < 1 ||
        start_vertex > vertex_count || target_vertex < 1 || target_vertex > vertex_count)
        return 1;
    for (int index = 1; index <= vertex_count; index++)
        best_distance[index] = INF, previous_vertex[index] = -1;
    best_distance[start_vertex] = 0;
    for (int z = 1; z <= vertex_count; z++) {
        int current_vertex = -1;
        for (int index = 1; index <= vertex_count; index++)
            if (!visited[index] &&
                (current_vertex < 0 || best_distance[index] < best_distance[current_vertex]))
                current_vertex = index;
        if (current_vertex < 0 || best_distance[current_vertex] == INF)
            break;
        visited[current_vertex] = 1;
        for (int neighbor_vertex = 1; neighbor_vertex <= vertex_count; neighbor_vertex++)
            if (edge_cost[current_vertex][neighbor_vertex] != INF &&
                best_distance[neighbor_vertex] >
                    best_distance[current_vertex] + edge_cost[current_vertex][neighbor_vertex]) {
                best_distance[neighbor_vertex] =
                    best_distance[current_vertex] + edge_cost[current_vertex][neighbor_vertex];
                previous_vertex[neighbor_vertex] = current_vertex;
            }
    }
    if (best_distance[target_vertex] == INF)
        return puts("無可行路徑"), 0;
    int route[N], route_length = 0;
    for (int current_vertex = target_vertex; current_vertex != -1;
         current_vertex = previous_vertex[current_vertex])
        route[route_length++] = current_vertex;
    printf("路徑：");
    for (int index = route_length - 1; index >= 0; index--)
        printf("V%d%s", route[index], index ? " -> " : "\n");
    printf("路徑長度：%lld\n", best_distance[target_vertex]);
    return 0;
}
