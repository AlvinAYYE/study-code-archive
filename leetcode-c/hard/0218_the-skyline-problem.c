/*
 * Title-CN: 天際線問題
 * LeetCode 218. The Skyline Problem
 *
 * 題意翻譯：每棟大樓用 [左邊界, 右邊界, 高度] 表示。把大樓想成貼在地面上的
 * 長方形，請找出從遠處看時，整座城市外輪廓改變的位置。每個答案點是 [x, y]：
 * 從 x 開始，輪廓高度變成 y。答案依 x 遞增，而且相鄰輪廓高度相同時要合併；
 * 最後一點的高度一定是 0，代表最高的大樓也已結束。
 *
 * 範例 1：輸入 [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]，
 *         輸出 [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]。
 * 範例 2：輸入 [[0,2,3],[2,5,3]]，輸出 [[0,3],[5,0]]；相鄰等高的大樓會合併。
 *
 * 限制：1 <= 大樓數量 <= 10^4；座標與高度皆為正整數範圍內的 32 位整數；
 *      大樓依左邊界排序。
 *
 * 解題思路：輪廓只可能在大樓的左、右邊界改變。先排序所有邊界 x，從左到右掃描：
 * 1. 到達某個 x 時，把左邊界等於 x 的大樓放進最大堆，堆頂代表目前最高的大樓。
 * 2. 把堆頂右邊界 <= x 的大樓移除；它們已經不覆蓋目前的位置。
 * 3. 若最高高度和上一個輪廓高度不同，就輸出 [x, 新高度]。
 * 堆中以大樓索引保存高度與右邊界，過期但還不在堆頂的大樓先留著，等它到堆頂
 * 再移除即可。每棟大樓最多進出堆一次，時間 O(n log n)，空間 O(n)。
 *
 * LeetCode C 介面：回傳的二維陣列和欄數陣列由呼叫端釋放；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

typedef struct {
    int x;
} Boundary;

static int **sortBuildings;

static int compareBoundary(const void *left, const void *right) {
    int a = ((const Boundary *)left)->x;
    int b = ((const Boundary *)right)->x;
    return (a > b) - (a < b);
}

static int higherBuilding(int first, int second) {
    int firstHeight = sortBuildings[first][2];
    int secondHeight = sortBuildings[second][2];
    if (firstHeight != secondHeight) return firstHeight > secondHeight;
    return sortBuildings[first][1] > sortBuildings[second][1];
}

static void heapPush(int *heap, int *heapSize, int buildingIndex) {
    int position = (*heapSize)++;
    while (position > 0) {
        int parent = (position - 1) / 2;
        if (higherBuilding(heap[parent], buildingIndex)) break;
        heap[position] = heap[parent];
        position = parent;
    }
    heap[position] = buildingIndex;
}

static void heapPop(int *heap, int *heapSize) {
    int last = heap[--(*heapSize)];
    int position = 0;
    while (position * 2 + 1 < *heapSize) {
        int child = position * 2 + 1;
        if (child + 1 < *heapSize && higherBuilding(heap[child + 1], heap[child])) {
            ++child;
        }
        if (higherBuilding(last, heap[child])) break;
        heap[position] = heap[child];
        position = child;
    }
    if (*heapSize > 0) heap[position] = last;
}

int **getSkyline(int **buildings, int buildingsSize, int *buildingsColSize,
                 int *returnSize, int **returnColumnSizes) {
    Boundary *boundaries;
    int *heap;
    int **answer;
    int boundaryCount = buildingsSize * 2;
    int heapSize = 0;
    int answerSize = 0;
    int nextBuilding = 0;
    int previousHeight = 0;
    int i;

    (void)buildingsColSize;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (buildingsSize == 0) return NULL;

    boundaries = malloc(sizeof(*boundaries) * (size_t)boundaryCount);
    heap = malloc(sizeof(*heap) * (size_t)buildingsSize);
    answer = malloc(sizeof(*answer) * (size_t)boundaryCount);
    *returnColumnSizes = malloc(sizeof(**returnColumnSizes) * (size_t)boundaryCount);
    if (boundaries == NULL || heap == NULL || answer == NULL || *returnColumnSizes == NULL) {
        free(boundaries);
        free(heap);
        free(answer);
        free(*returnColumnSizes);
        *returnColumnSizes = NULL;
        return NULL;
    }

    for (i = 0; i < buildingsSize; ++i) {
        boundaries[i * 2].x = buildings[i][0];
        boundaries[i * 2 + 1].x = buildings[i][1];
    }
    qsort(boundaries, (size_t)boundaryCount, sizeof(*boundaries), compareBoundary);

    sortBuildings = buildings;
    for (i = 0; i < boundaryCount; ++i) {
        int x = boundaries[i].x;
        int currentHeight;

        if (i > 0 && boundaries[i - 1].x == x) continue;
        while (nextBuilding < buildingsSize && buildings[nextBuilding][0] == x) {
            heapPush(heap, &heapSize, nextBuilding);
            ++nextBuilding;
        }
        while (heapSize > 0 && buildings[heap[0]][1] <= x) {
            heapPop(heap, &heapSize);
        }

        currentHeight = heapSize == 0 ? 0 : buildings[heap[0]][2];
        if (currentHeight != previousHeight) {
            answer[answerSize] = malloc(sizeof(**answer) * 2U);
            if (answer[answerSize] == NULL) {
                int j;
                for (j = 0; j < answerSize; ++j) free(answer[j]);
                free(boundaries);
                free(heap);
                free(answer);
                free(*returnColumnSizes);
                *returnColumnSizes = NULL;
                return NULL;
            }
            answer[answerSize][0] = x;
            answer[answerSize][1] = currentHeight;
            (*returnColumnSizes)[answerSize] = 2;
            ++answerSize;
            previousHeight = currentHeight;
        }
    }

    free(boundaries);
    free(heap);
    *returnSize = answerSize;
    return answer;
}

static void checkSkyline(int **buildings, int buildingCount, const int *expected,
                         int expectedPointCount) {
    int *columnSizes = NULL;
    int resultSize = 0;
    int **result = getSkyline(buildings, buildingCount, NULL, &resultSize, &columnSizes);
    int i;

    assert(resultSize == expectedPointCount);
    for (i = 0; i < resultSize; ++i) {
        assert(columnSizes[i] == 2);
        assert(result[i][0] == expected[i * 2]);
        assert(result[i][1] == expected[i * 2 + 1]);
        free(result[i]);
    }
    free(result);
    free(columnSizes);
}

int main(void) {
    int b1a[] = {2, 9, 10}, b1b[] = {3, 7, 15}, b1c[] = {5, 12, 12};
    int b1d[] = {15, 20, 10}, b1e[] = {19, 24, 8};
    int *example1[] = {b1a, b1b, b1c, b1d, b1e};
    int expected1[] = {2, 10, 3, 15, 7, 12, 12, 0, 15, 10, 20, 8, 24, 0};
    int b2a[] = {0, 2, 3}, b2b[] = {2, 5, 3};
    int *example2[] = {b2a, b2b};
    int expected2[] = {0, 3, 5, 0};
    int b3a[] = {1, 5, 11}, b3b[] = {2, 7, 6}, b3c[] = {3, 9, 13};
    int *example3[] = {b3a, b3b, b3c};
    int expected3[] = {1, 11, 3, 13, 9, 0};

    checkSkyline(example1, 5, expected1, 7);
    checkSkyline(example2, 2, expected2, 2);
    checkSkyline(example3, 3, expected3, 3);
    return 0;
}
