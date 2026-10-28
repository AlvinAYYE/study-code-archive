/*
 * LeetCode 0785. Is Graph Bipartite?（二分圖判斷）
 * 題意：給定無向圖的鄰接清單，能否把節點分成兩組，使每條邊都連接不同組？
 * 範例：[[1,2,3],[0,2],[0,1,3],[0,2]] -> false；[[1,3],[0,2],[1,3],[0,2]] -> true。
 * 限制：節點數 1..100；圖無自環，鄰接關係對稱，清單內不重複。
 * 解法：對每個尚未上色的連通分量做 BFS；相鄰節點必須塗相反顏色，若遇到同色鄰居則不是二分圖。
 * 複雜度：時間 O(V+E)，空間 O(V)。
 */
#include <stdbool.h>
#include <stdio.h>

/* ---- community solution ---- */
bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[100];
    int queue[100];
    for (int node = 0; node < graphSize; node++) {
        color[node] = -1;
    }

    for (int start = 0; start < graphSize; start++) {
        if (color[start] != -1) {
            continue;
        }
        int head = 0;
        int tail = 0;
        color[start] = 0;
        queue[tail++] = start;

        while (head < tail) {
            int node = queue[head++];
            for (int i = 0; i < graphColSize[node]; i++) {
                int neighbor = graph[node][i];
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[tail++] = neighbor;
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

/* ---- generated tests ---- */
int main(void) {
    int a0[] = {1, 2, 3};
    int a1[] = {0, 2};
    int a2[] = {0, 1, 3};
    int a3[] = {0, 2};
    int *graphOne[] = {a0, a1, a2, a3};
    int sizesOne[] = {3, 2, 3, 2};

    int b0[] = {1, 3};
    int b1[] = {0, 2};
    int b2[] = {1, 3};
    int b3[] = {0, 2};
    int *graphTwo[] = {b0, b1, b2, b3};
    int sizesTwo[] = {2, 2, 2, 2};

    int *emptyRows[] = {NULL, NULL, NULL};
    int emptySizes[] = {0, 0, 0};
    bool passed = !isBipartite(graphOne, 4, sizesOne) &&
                  isBipartite(graphTwo, 4, sizesTwo) &&
                  isBipartite(emptyRows, 3, emptySizes);
    printf("%s: 0785 isBipartite tests=3\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
