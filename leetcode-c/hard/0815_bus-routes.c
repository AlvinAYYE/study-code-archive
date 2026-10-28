/*
 * Title-CN: 公車路線
 * LeetCode 815. Bus Routes
 *
 * 題意翻譯：routes[i] 是第 i 條公車路線會停靠的站牌，公車會沿該路線循環行駛。
 * 給定起點 source 和終點 target，每次上車後可以在該路線任一站下車並換乘。請回傳
 * 到達 target 至少要搭幾班公車；若無法到達，回傳 -1。若起點就是終點，回傳 0。
 *
 * 範例 1：routes = [[1,2,7],[3,6,7]]、source = 1、target = 6，輸出 2。先搭第一條
 *         路線到 7，再換搭第二條路線到 6。
 * 範例 2：routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]]、source = 15、
 *         target = 12，輸出 -1；兩地之間沒有可連接的路線。
 *
 * 限制：1 <= routes.length <= 500；每條路線至少一站；站牌編號介於 0 到 10^6。
 *
 * 解題思路：把每條公車路線當成 BFS 的節點。先建立「站牌 -> 經過該站的路線」索引，
 * 再把所有經過 source 的路線放進佇列，搭乘班數設為 1。每次取出一條路線，檢查它
 * 的所有站牌：到達 target 就回傳目前班數；否則找出經過該站的其他路線，尚未搭過的
 * 路線加入佇列，班數加一。每個站牌只展開一次，避免在多條路線間重複掃描。時間
 * O(S + E)，空間 O(S + R)，S 是總停靠次數、E 是站牌到路線的關聯數、R 是路線數。
 *
 * LeetCode C 介面：回傳最少公車班數或 -1；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

#define MAX_STOP_NUMBER 1000000
#define STOP_COUNT ((size_t)MAX_STOP_NUMBER + 1U)

int numBusesToDestination(int **routes, int routesSize, int *routesColSize,
                          int source, int target) {
    int totalStops = 0;
    int *firstRouteAtStop;
    unsigned char *expandedStop;
    unsigned char *visitedRoute;
    int *routeQueue;
    int *busesToRoute;
    int *nextLink;
    int *linkedRoute;
    int linkCount = 0;
    int front = 0;
    int back = 0;
    int route;
    int answer = -1;

    if (source == target) return 0;
    for (route = 0; route < routesSize; ++route) totalStops += routesColSize[route];

    firstRouteAtStop = malloc(sizeof(*firstRouteAtStop) * STOP_COUNT);
    expandedStop = calloc(STOP_COUNT, sizeof(*expandedStop));
    visitedRoute = calloc((size_t)routesSize, sizeof(*visitedRoute));
    routeQueue = malloc(sizeof(*routeQueue) * (size_t)routesSize);
    busesToRoute = calloc((size_t)routesSize, sizeof(*busesToRoute));
    nextLink = malloc(sizeof(*nextLink) * (size_t)totalStops);
    linkedRoute = malloc(sizeof(*linkedRoute) * (size_t)totalStops);
    if (firstRouteAtStop == NULL || expandedStop == NULL || visitedRoute == NULL ||
        routeQueue == NULL || busesToRoute == NULL || nextLink == NULL || linkedRoute == NULL) {
        free(firstRouteAtStop);
        free(expandedStop);
        free(visitedRoute);
        free(routeQueue);
        free(busesToRoute);
        free(nextLink);
        free(linkedRoute);
        return -1;
    }

    for (size_t stop = 0; stop < STOP_COUNT; ++stop) firstRouteAtStop[stop] = -1;
    for (route = 0; route < routesSize; ++route) {
        int position;
        for (position = 0; position < routesColSize[route]; ++position) {
            int stop = routes[route][position];
            linkedRoute[linkCount] = route;
            nextLink[linkCount] = firstRouteAtStop[stop];
            firstRouteAtStop[stop] = linkCount;
            ++linkCount;
            if (stop == source && !visitedRoute[route]) {
                visitedRoute[route] = 1;
                busesToRoute[route] = 1;
                routeQueue[back++] = route;
            }
        }
    }

    while (front < back) {
        int currentRoute = routeQueue[front++];
        int busesTaken = busesToRoute[currentRoute];
        int position;

        for (position = 0; position < routesColSize[currentRoute]; ++position) {
            int stop = routes[currentRoute][position];
            int link;
            if (stop == target) {
                answer = busesTaken;
                goto cleanup;
            }
            if (expandedStop[stop]) continue;
            expandedStop[stop] = 1;

            for (link = firstRouteAtStop[stop]; link != -1; link = nextLink[link]) {
                int nextBusRoute = linkedRoute[link];
                if (!visitedRoute[nextBusRoute]) {
                    visitedRoute[nextBusRoute] = 1;
                    busesToRoute[nextBusRoute] = busesTaken + 1;
                    routeQueue[back++] = nextBusRoute;
                }
            }
        }
    }

cleanup:
    free(firstRouteAtStop);
    free(expandedStop);
    free(visitedRoute);
    free(routeQueue);
    free(busesToRoute);
    free(nextLink);
    free(linkedRoute);
    return answer;
}

int main(void) {
    int route1a[] = {1, 2, 7}, route1b[] = {3, 6, 7};
    int *example1[] = {route1a, route1b};
    int sizes1[] = {3, 3};
    int route2a[] = {7, 12}, route2b[] = {4, 5, 15}, route2c[] = {6};
    int route2d[] = {15, 19}, route2e[] = {9, 12, 13};
    int *example2[] = {route2a, route2b, route2c, route2d, route2e};
    int sizes2[] = {2, 3, 1, 2, 3};
    int route3[] = {0, 4, 8};
    int *example3[] = {route3};
    int size3[] = {3};

    assert(numBusesToDestination(example1, 2, sizes1, 1, 6) == 2);
    assert(numBusesToDestination(example2, 5, sizes2, 15, 12) == -1);
    assert(numBusesToDestination(example3, 1, size3, 4, 4) == 0);
    assert(numBusesToDestination(example3, 1, size3, 0, 8) == 1);
    return 0;
}
