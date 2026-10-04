/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】從加權鄰接矩陣表示的圖中，找出起點至終點的最低成本路徑。使用
 * Dijkstra，適用於非負邊權。 【輸入】節點數 n、n×n 矩陣（0
 * 表示沒有邊）、起點 s 和終點 t；節點編號從 1 起。【輸出】路徑和總距離。
 * 【閱讀順序】讀矩陣時把 0 轉成 INF（對角線除外）。每輪選 d 最小的未拜訪節點
 * u，再用 u 到所有鄰點的邊嘗試縮短距離。p[j]
 * 記錄最佳路徑中 j 的前一站。最後由終點回溯並反向列印。 【C 語法】g[i][j]
 * 是二維陣列元素；v[] 表示節點是否已處理；static 矩陣放在靜態記憶體，不占用函式堆疊。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入節點數 n、n*n 權重矩陣（0
 * 代表沒有邊）、起點終點；輸出最短路徑及距離。 */
#include <stdio.h>
#define N 501
#define INF 4000000000000000000LL
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int vertex_count, start_vertex, target_vertex;
    static long long edge_cost[N][N], best_distance[N];
    static int previous_vertex[N], visited[N];
    if (scanf("%d", &vertex_count) != 1 || vertex_count < 1 || vertex_count >= N)
        return 1;
    for (int index = 1; index <= vertex_count; index++)
        for (int inner_index = 1; inner_index <= vertex_count; inner_index++) {
            long long edge_weight;
            if (scanf("%lld", &edge_weight) != 1)
                return 1;
            edge_cost[index][inner_index] =
                (index == inner_index) ? 0 : (edge_weight == 0 ? INF : edge_weight);
        }
    if (scanf("%d%d", &start_vertex, &target_vertex) != 2 || start_vertex < 1 ||
        start_vertex > vertex_count || target_vertex < 1 || target_vertex > vertex_count)
        return 1;
    for (int index = 1; index <= vertex_count; index++)
        best_distance[index] = INF, previous_vertex[index] = -1;
    best_distance[start_vertex] = 0;
    for (int z = 0; z < vertex_count; z++) {
        int current_vertex = -1;
        for (int index = 1; index <= vertex_count; index++)
            if (!visited[index] &&
                (current_vertex < 0 || best_distance[index] < best_distance[current_vertex]))
                current_vertex = index;
        if (current_vertex < 0 || best_distance[current_vertex] == INF)
            break;
        visited[current_vertex] = 1;
        for (int inner_index = 1; inner_index <= vertex_count; inner_index++)
            if (edge_cost[current_vertex][inner_index] != INF &&
                best_distance[inner_index] >
                    best_distance[current_vertex] + edge_cost[current_vertex][inner_index]) {
                best_distance[inner_index] =
                    best_distance[current_vertex] + edge_cost[current_vertex][inner_index];
                previous_vertex[inner_index] = current_vertex;
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
        printf("%d%s", route[index], index ? " -> " : "\n");
    printf("距離：%lld\n", best_distance[target_vertex]);
    return 0;
}
