/*
 * 【初學者詳細導讀】
 * 【這題要做什麼】讀取有向加權邊，找指定起點到終點的最低成本路徑。此資料夾附 input.txt
 * 範例，可用輸入重新導向測試。 【輸入】邊數 m、m 行「起點 終點 成本」、起點
 * s、終點 t。範例節點編號為 1 到 7。【輸出】最低成本和路徑順序。
 * 【閱讀順序】先把 g 矩陣填為 INF，再填入已知邊成本。接著使用
 * Dijkstra：挑目前距離最小的未拜訪節點，嘗試更新其他點。pre
 * 保存最佳路徑的前一站；最後從終點反向回溯並反向輸出。 【C 語法】二維矩陣
 * g[u][v] 代表方向 u→v 的成本；vis[] 防止重複確定節點；若
 * d[t] 仍是 INF，表示沒有路。
 *
 * 【共通讀法】程式從 main 開始執行。scanf 依格式讀入資料，printf 將答案印到螢幕；for/while
 * 重複執行大括號中的步驟。C 陣列索引從 0 開始。遇到函式時，可把它當成一段有名字、可重複使用的工作。
 */
/* 輸入 m、m 筆有向邊 u v cost、起點和終點。樣例邊可參考同資料夾
 * input.txt。 */
#include <stdio.h>
#define N 100
#define INF 4000000000000000000LL
int main(void) {
    /* 先讀取並檢查輸入；接著依導讀中的演算法處理資料，最後輸出結果。 */
    int vertex_count, start_vertex, target_vertex;
    long long edge_cost[N][N], distance[N];
    int previous_vertex[N], visited[N] = {0};
    if (scanf("%d", &vertex_count) != 1 || vertex_count < 0)
        return 1;
    for (int index = 0; index < N; index++)
        for (int inner_index = 0; inner_index < N; inner_index++)
            edge_cost[index][inner_index] = index == inner_index ? 0 : INF;
    int maximum_vertex = 0;
    for (int index = 0, current_vertex, neighbor_vertex; index < vertex_count; index++) {
        long long edge_weight;
        if (scanf("%d%d%lld", &current_vertex, &neighbor_vertex, &edge_weight) != 3 ||
            current_vertex < 1 || current_vertex >= N || neighbor_vertex < 1 ||
            neighbor_vertex >= N || edge_weight < 0)
            return 1;
        edge_cost[current_vertex][neighbor_vertex] = edge_weight;
        if (current_vertex > maximum_vertex)
            maximum_vertex = current_vertex;
        if (neighbor_vertex > maximum_vertex)
            maximum_vertex = neighbor_vertex;
    }
    if (scanf("%d%d", &start_vertex, &target_vertex) != 2)
        return 1;
    for (int index = 1; index < N; index++)
        distance[index] = INF, previous_vertex[index] = -1;
    distance[start_vertex] = 0;
    for (int z = 0; z < N - 1; z++) {
        int current_vertex = -1;
        for (int index = 1; index < N; index++)
            if (!visited[index] &&
                (current_vertex < 0 || distance[index] < distance[current_vertex]))
                current_vertex = index;
        if (current_vertex < 0 || distance[current_vertex] == INF)
            break;
        visited[current_vertex] = 1;
        for (int neighbor_vertex = 1; neighbor_vertex < N; neighbor_vertex++)
            if (edge_cost[current_vertex][neighbor_vertex] != INF &&
                distance[neighbor_vertex] >
                    distance[current_vertex] + edge_cost[current_vertex][neighbor_vertex]) {
                distance[neighbor_vertex] =
                    distance[current_vertex] + edge_cost[current_vertex][neighbor_vertex];
                previous_vertex[neighbor_vertex] = current_vertex;
            }
    }
    if (distance[target_vertex] == INF)
        return puts("沒有可行路徑"), 0;
    int route[N], route_length = 0;
    for (int current_vertex = target_vertex; current_vertex != -1;
         current_vertex = previous_vertex[current_vertex])
        route[route_length++] = current_vertex;
    printf("最低成本總額：%lld\n路徑次序：", distance[target_vertex]);
    for (int index = route_length - 1; index >= 0; index--)
        printf("%d%s", route[index], index ? " -> " : "\n");
    return 0;
}
