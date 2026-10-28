/*
 * Title-CN: 找到最終安全狀態
 * LeetCode 802. Find Eventual Safe States
 *
 * 題意翻譯：有 n 個狀態，graph[i] 列出從狀態 i 可以直接前往的狀態。若從某個
 * 狀態出發，不論沿著邊怎麼走，最後都一定會到達沒有外連邊的終點，這個狀態就是
 * 安全狀態。請回傳所有安全狀態，並依編號由小到大排列。
 *
 * 範例 1：graph = [[1,2],[2,3],[5],[0],[5],[],[]]，輸出 [2,4,5,6]。
 *         0、1、3 會互相形成循環，無法保證走到終點；2、4、5、6 最後都會停下。
 * 範例 2：graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]，輸出 [4]。
 *
 * 限制：1 <= n <= 10^4；每個狀態的出邊數小於 n；graph 不含重複邊。
 *
 * 解題思路：用 DFS 判斷每個節點是否安全，並用狀態避免重複走訪：0=尚未拜訪、
 * 1=正在目前 DFS 路徑上、2=已確認安全、3=已確認不安全。若遇到狀態 1，代表沿路
 * 回到了目前路徑，形成循環；若任一鄰居不安全，自己也不安全。只有所有鄰居都
 * 安全時，節點才安全。最後按編號掃描並收集狀態 2 的節點。每個節點和邊最多處理
 * 一次，時間 O(V+E)，空間 O(V)。
 *
 * LeetCode C 介面：回傳陣列由呼叫端釋放；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

static int isSafeState(int node, int **graph, int *graphColSize, unsigned char *state) {
    int edge;

    if (state[node] == 1 || state[node] == 3) return 0;
    if (state[node] == 2) return 1;

    state[node] = 1;
    for (edge = 0; edge < graphColSize[node]; ++edge) {
        if (!isSafeState(graph[node][edge], graph, graphColSize, state)) {
            state[node] = 3;
            return 0;
        }
    }
    state[node] = 2;
    return 1;
}

int *eventualSafeNodes(int **graph, int graphSize, int *graphColSize,
                       int *returnSize) {
    unsigned char *state = calloc((size_t)graphSize, sizeof(*state));
    int *safeNodes = malloc(sizeof(*safeNodes) * (size_t)graphSize);
    int safeCount = 0;
    int node;

    *returnSize = 0;
    if (state == NULL || safeNodes == NULL) {
        free(state);
        free(safeNodes);
        return NULL;
    }

    for (node = 0; node < graphSize; ++node) {
        (void)isSafeState(node, graph, graphColSize, state);
    }
    for (node = 0; node < graphSize; ++node) {
        if (state[node] == 2) safeNodes[safeCount++] = node;
    }

    free(state);
    *returnSize = safeCount;
    return safeNodes;
}

static void checkSafeNodes(int **graph, int *columnSizes, int graphSize,
                           const int *expected, int expectedSize) {
    int returnSize = 0;
    int *actual = eventualSafeNodes(graph, graphSize, columnSizes, &returnSize);
    int i;

    assert(returnSize == expectedSize);
    for (i = 0; i < expectedSize; ++i) assert(actual[i] == expected[i]);
    free(actual);
}

int main(void) {
    int row0[] = {1, 2}, row1[] = {2, 3}, row2[] = {5}, row3[] = {0};
    int row4[] = {5};
    int *example1[] = {row0, row1, row2, row3, row4, NULL, NULL};
    int sizes1[] = {2, 2, 1, 1, 1, 0, 0};
    int expected1[] = {2, 4, 5, 6};
    int rowA[] = {1, 2, 3, 4}, rowB[] = {1, 2}, rowC[] = {3, 4};
    int rowD[] = {0, 4};
    int *example2[] = {rowA, rowB, rowC, rowD, NULL};
    int sizes2[] = {4, 2, 2, 2, 0};
    int expected2[] = {4};
    int emptyRow[] = {0};
    int *example3[] = {emptyRow, NULL};
    int sizes3[] = {0, 0};
    int expected3[] = {0, 1};

    checkSafeNodes(example1, sizes1, 7, expected1, 4);
    checkSafeNodes(example2, sizes2, 5, expected2, 1);
    checkSafeNodes(example3, sizes3, 2, expected3, 2);
    return 0;
}
