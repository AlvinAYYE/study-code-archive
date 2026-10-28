/*
 * LeetCode 407. Trapping Rain Water II
 * 題意（繁體中文）：給定每個格子的高度，計算下雨後地圖中能留下的總水量。
 * 邊界是水流出的出口；格子能裝多少水，取決於通往外界路徑上最低的邊界。
 *
 * 範例：
 *   heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] -> 4
 *   heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],
 *                [3,2,2,2,3],[3,3,3,3,3]] -> 10
 *
 * 限制：1 <= 列數、欄數 <= 200；每格高度介於 0 到 20000。
 * 解法：先把所有外圍格子放進最小堆。每次取出目前最低的邊界，
 *       查看尚未拜訪的鄰格：低於邊界的部分就是積水；再用兩者較高者
 *       作為新邊界放回堆。如此由外往內擴張，最低邊界會先決定內側水位。
 * 複雜度：O(mn log(mn)) 時間、O(mn) 額外空間。
 * LeetCode C API：int trapRainWater(int** heightMap, int heightMapSize,
 *                                    int* heightMapColSize)
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int height;
    int cell;
} HeapCell;

static void heapPush(HeapCell *heap, int *size, HeapCell value) {
    int index = (*size)++;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].height <= value.height) break;
        heap[index] = heap[parent];
        index = parent;
    }
    heap[index] = value;
}

static HeapCell heapPop(HeapCell *heap, int *size) {
    HeapCell answer = heap[0];
    HeapCell tail = heap[--(*size)];
    int index = 0;
    while (index * 2 + 1 < *size) {
        int child = index * 2 + 1;
        if (child + 1 < *size && heap[child + 1].height < heap[child].height)
            ++child;
        if (tail.height <= heap[child].height) break;
        heap[index] = heap[child];
        index = child;
    }
    if (*size > 0) heap[index] = tail;
    return answer;
}

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize) {
    int rows = heightMapSize;
    int cols = heightMapColSize[0];
    int total = rows * cols;
    bool *visited = (bool *)calloc((size_t)total, sizeof *visited);
    HeapCell *heap = (HeapCell *)malloc((size_t)total * sizeof *heap);
    if (visited == NULL || heap == NULL) {
        free(visited);
        free(heap);
        return 0;
    }

    int heapSize = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (r != 0 && r != rows - 1 && c != 0 && c != cols - 1) continue;
            int cell = r * cols + c;
            if (visited[cell]) continue;
            visited[cell] = true;
            heapPush(heap, &heapSize, (HeapCell){heightMap[r][c], cell});
        }
    }

    int water = 0;
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};
    while (heapSize > 0) {
        HeapCell boundary = heapPop(heap, &heapSize);
        int r = boundary.cell / cols;
        int c = boundary.cell % cols;
        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            int nextCell = nr * cols + nc;
            if (visited[nextCell]) continue;
            visited[nextCell] = true;
            int ground = heightMap[nr][nc];
            if (ground < boundary.height) water += boundary.height - ground;
            int effectiveHeight = ground > boundary.height ? ground : boundary.height;
            heapPush(heap, &heapSize, (HeapCell){effectiveHeight, nextCell});
        }
    }
    free(visited);
    free(heap);
    return water;
}

int main(void) {
    int a0[] = {1, 4, 3, 1, 3, 2};
    int a1[] = {3, 2, 1, 3, 2, 4};
    int a2[] = {2, 3, 3, 2, 3, 1};
    int *example1[] = {a0, a1, a2};
    int cols1[] = {6, 6, 6};
    int b0[] = {3, 3, 3, 3, 3};
    int b1[] = {3, 2, 2, 2, 3};
    int b2[] = {3, 2, 1, 2, 3};
    int b3[] = {3, 2, 2, 2, 3};
    int b4[] = {3, 3, 3, 3, 3};
    int *example2[] = {b0, b1, b2, b3, b4};
    int cols2[] = {5, 5, 5, 5, 5};
    int passed = trapRainWater(example1, 3, cols1) == 4 &&
                 trapRainWater(example2, 5, cols2) == 10;
    puts(passed ? "PASS: 407 trapping-rain-water-ii" : "FAIL: 407 trapping-rain-water-ii");
    return passed ? 0 : 1;
}
