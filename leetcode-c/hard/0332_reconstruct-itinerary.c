/*
 * LeetCode 332. Reconstruct Itinerary（重新安排行程）
 *
 * 題意（繁體中文）：
 *   每張機票表示一段「出發地 -> 目的地」航班。請從 JFK 出發，使用每張機票
 *   恰好一次，組成完整行程。若有多種可行行程，回傳字典順序最小的那一條。
 *   城市代碼都是三個大寫英文字母。
 *
 * 範例：
 *   1. [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
 *      回傳 ["JFK","MUC","LHR","SFO","SJC"]。
 *   2. [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],
 *       ["ATL","SFO"]]，回傳 ["JFK","ATL","JFK","SFO","ATL","SFO"]，
 *      這是所有可行路線中字典順序最小的結果。
 *
 * 限制：1 <= tickets.length <= 300；每張票有兩個三字母城市代碼；城市代碼只含大寫字母。
 *
 * 解題步驟：
 *   1. 把每張票視為一條有向邊。從目前城市反覆選擇尚未使用且目的地字典序
 *      最小的機票，沿邊遞迴前進。
 *   2. 當某城市沒有未用出邊時，才把它加入路線尾端。這是 Hierholzer 演算法：
 *      先走完每條邊，再以回溯順序串起完整行程。
 *   3. 回溯得到的城市順序是反向的，最後倒轉並轉回三字母代碼。每次掃描
 *      全部機票尋找最小出邊，最多 300 張票，實作簡單且足夠快。
 *
 * 複雜度：E 為機票數，時間 O(E^2)，額外空間 O(E)。
 * LeetCode C API：
 * char** findItinerary(char*** tickets, int ticketsSize,
 *                      int* ticketsColSize, int* returnSize)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int from;
    int to;
    int used;
} TicketEdge;

static int cityCode(const char *city) {
    return (city[0] - 'A') * 26 * 26 + (city[1] - 'A') * 26 + (city[2] - 'A');
}

static void cityName(int code, char output[4]) {
    output[0] = (char)('A' + code / (26 * 26));
    output[1] = (char)('A' + (code / 26) % 26);
    output[2] = (char)('A' + code % 26);
    output[3] = '\0';
}

static void buildRoute(int city, TicketEdge *edges, int edgeCount,
                       int *route, int *routeSize) {
    for (;;) {
        int chosen = -1;
        for (int i = 0; i < edgeCount; ++i) {
            if (!edges[i].used && edges[i].from == city &&
                (chosen == -1 || edges[i].to < edges[chosen].to))
                chosen = i;
        }
        if (chosen == -1) break;
        edges[chosen].used = 1;
        buildRoute(edges[chosen].to, edges, edgeCount, route, routeSize);
    }
    route[(*routeSize)++] = city;
}

char **findItinerary(char ***tickets, int ticketsSize,
                     int *ticketsColSize, int *returnSize) {
    (void)ticketsColSize;
    *returnSize = 0;
    TicketEdge edges[300];
    for (int i = 0; i < ticketsSize; ++i) {
        edges[i].from = cityCode(tickets[i][0]);
        edges[i].to = cityCode(tickets[i][1]);
        edges[i].used = 0;
    }

    int route[301];
    int routeSize = 0;
    buildRoute(cityCode("JFK"), edges, ticketsSize, route, &routeSize);
    if (routeSize != ticketsSize + 1) return NULL;

    char **answer = (char **)malloc((size_t)routeSize * sizeof *answer);
    if (answer == NULL) return NULL;
    for (int i = 0; i < routeSize; ++i) {
        answer[i] = (char *)malloc(4);
        if (answer[i] == NULL) {
            for (int j = 0; j < i; ++j) free(answer[j]);
            free(answer);
            return NULL;
        }
        cityName(route[routeSize - 1 - i], answer[i]);
    }
    *returnSize = routeSize;
    return answer;
}

static int routeMatches(char **route, int size, const char *const *expected,
                        int expectedSize) {
    if (route == NULL || size != expectedSize) return 0;
    for (int i = 0; i < size; ++i)
        if (strcmp(route[i], expected[i]) != 0) return 0;
    return 1;
}

static void freeRoute(char **route, int size) {
    for (int i = 0; i < size; ++i) free(route[i]);
    free(route);
}

int main(void) {
    char *a0[] = {"MUC", "LHR"}, *a1[] = {"JFK", "MUC"};
    char *a2[] = {"SFO", "SJC"}, *a3[] = {"LHR", "SFO"};
    char **tickets1[] = {a0, a1, a2, a3};
    int columns1[] = {2, 2, 2, 2};
    const char *expected1[] = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    int size1 = 0;
    char **route1 = findItinerary(tickets1, 4, columns1, &size1);

    char *b0[] = {"JFK", "SFO"}, *b1[] = {"JFK", "ATL"};
    char *b2[] = {"SFO", "ATL"}, *b3[] = {"ATL", "JFK"};
    char *b4[] = {"ATL", "SFO"};
    char **tickets2[] = {b0, b1, b2, b3, b4};
    int columns2[] = {2, 2, 2, 2, 2};
    const char *expected2[] = {"JFK", "ATL", "JFK", "SFO", "ATL", "SFO"};
    int size2 = 0;
    char **route2 = findItinerary(tickets2, 5, columns2, &size2);

    int passed = routeMatches(route1, size1, expected1, 5) &&
                 routeMatches(route2, size2, expected2, 6);
    freeRoute(route1, size1);
    freeRoute(route2, size2);
    puts(passed ? "PASS: 332 reconstruct-itinerary"
                : "FAIL: 332 reconstruct-itinerary");
    return passed ? 0 : 1;
}
