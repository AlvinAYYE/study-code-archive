/*
 * LeetCode 749. Contain Virus
 * 題意（繁體中文）：0 表示未感染、1 表示感染。每天先找出所有上下左右相連的
 * 感染區域，為「下一晚會感染最多未感染格」的區域築牆隔離，再讓其他區域
 * 向相鄰的未感染格擴散一格。回傳總共築了幾面牆。
 *
 * 範例：[[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],
 *        [0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]] -> 10。
 *       [[1,1,1],[1,0,1],[1,1,1]] -> 4。
 *       [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],
 *        [1,1,1,0,0,0,0,0,0]] -> 13。
 * 限制：列數、欄數各為 1 到 50；格子只會是 0 或 1；每一天都存在能感染新格的區域。
 * 解法：每一天用 BFS 標記所有感染連通區。逐區計算它接觸的不同未感染格數
 *       （威脅數）與相鄰邊數（築牆數），挑威脅最大的區域隔離。其餘感染格
 *       同步標記新感染，最後再一起轉成感染狀態，避免同一天連鎖擴散。
 * 複雜度：每輪 O(mn)，最多 O(mn) 輪；額外空間 O(mn)。
 * LeetCode C API：int containVirus(int** isInfected, int isInfectedSize,
 *                                   int* isInfectedColSize)
 */
#include <stdio.h>
#include <string.h>

#define MAX_CELLS 2500

int containVirus(int** isInfected, int isInfectedSize, int* isInfectedColSize) {
    int rows = isInfectedSize, cols = isInfectedColSize[0];
    int total = rows * cols, wallsBuilt = 0;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    for (;;) {
        int visited[MAX_CELLS] = {0};
        int regionOf[MAX_CELLS];
        int frontierStamp[MAX_CELLS];
        int queue[MAX_CELLS];
        int regionCount = 0;
        for (int cell = 0; cell < total; ++cell) {
            regionOf[cell] = -1;
            frontierStamp[cell] = -1;
        }

        for (int start = 0; start < total; ++start) {
            int sr = start / cols, sc = start % cols;
            if (isInfected[sr][sc] != 1 || visited[start]) continue;
            int region = regionCount++;
            int head = 0, tail = 0;
            queue[tail++] = start;
            visited[start] = 1;
            regionOf[start] = region;
            while (head < tail) {
                int cell = queue[head++];
                int r = cell / cols, c = cell % cols;
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols ||
                        isInfected[nr][nc] != 1)
                        continue;
                    int next = nr * cols + nc;
                    if (visited[next]) continue;
                    visited[next] = 1;
                    regionOf[next] = region;
                    queue[tail++] = next;
                }
            }
        }
        if (regionCount == 0) break;

        int threats[MAX_CELLS] = {0};
        int walls[MAX_CELLS] = {0};
        for (int cell = 0; cell < total; ++cell) {
            int region = regionOf[cell];
            if (region < 0) continue;
            int r = cell / cols, c = cell % cols;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols ||
                    isInfected[nr][nc] != 0)
                    continue;
                ++walls[region];
                int frontier = nr * cols + nc;
                if (frontierStamp[frontier] != region) {
                    frontierStamp[frontier] = region;
                    ++threats[region];
                }
            }
        }

        int selected = -1;
        for (int region = 0; region < regionCount; ++region)
            if (selected == -1 || threats[region] > threats[selected]) selected = region;
        if (selected == -1 || threats[selected] == 0) break;
        wallsBuilt += walls[selected];

        for (int cell = 0; cell < total; ++cell) {
            int r = cell / cols, c = cell % cols;
            if (regionOf[cell] == selected) isInfected[r][c] = -1;
        }
        for (int cell = 0; cell < total; ++cell) {
            int r = cell / cols, c = cell % cols;
            if (isInfected[r][c] != 1) continue;
            for (int d = 0; d < 4; ++d) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    isInfected[nr][nc] == 0)
                    isInfected[nr][nc] = 2;
            }
        }
        for (int cell = 0; cell < total; ++cell) {
            int r = cell / cols, c = cell % cols;
            if (isInfected[r][c] == 2) isInfected[r][c] = 1;
        }
    }
    return wallsBuilt;
}

int main(void) {
    int a0[] = {0, 1, 0, 0, 0, 0, 0, 1};
    int a1[] = {0, 1, 0, 0, 0, 0, 0, 1};
    int a2[] = {0, 0, 0, 0, 0, 0, 0, 1};
    int a3[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int *example1[] = {a0, a1, a2, a3};
    int sizes1[] = {8, 8, 8, 8};

    int b0[] = {1, 1, 1}, b1[] = {1, 0, 1}, b2[] = {1, 1, 1};
    int *example2[] = {b0, b1, b2};
    int sizes2[] = {3, 3, 3};

    int c0[] = {1, 1, 1, 0, 0, 0, 0, 0, 0};
    int c1[] = {1, 0, 1, 0, 1, 1, 1, 1, 1};
    int c2[] = {1, 1, 1, 0, 0, 0, 0, 0, 0};
    int *example3[] = {c0, c1, c2};
    int sizes3[] = {9, 9, 9};

    int passed = containVirus(example1, 4, sizes1) == 10 &&
                 containVirus(example2, 3, sizes2) == 4 &&
                 containVirus(example3, 3, sizes3) == 13;
    puts(passed ? "PASS: 749 contain-virus" : "FAIL: 749 contain-virus");
    return passed ? 0 : 1;
}
