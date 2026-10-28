/*
 * Title-CN: 在不重疊矩形中隨機選點
 * LeetCode 497. Random Point in Non-overlapping Rectangles
 *
 * 題意翻譯：給定多個互不重疊、邊平行於座標軸的整數座標矩形。設計 pick，
 * 讓它從所有矩形覆蓋的整數格點中等機率回傳一點。
 *
 * 範例：矩形 [1,1,2,2] 含 4 個整數點；矩形 [3,1,3,2] 含 2 個。六個點
 * 都應有相同機率被選到。
 *
 * 限制：矩形數量為 1 到 100；座標絕對值不超過 10^9；矩形互不重疊。
 *
 * 解題思路：先算出每個矩形內整數點數，建立累積總數。每次在所有點的總編號中
 * 均勻抽一個，再用二分搜尋找出它屬於哪個矩形。最後把矩形內的偏移編號換算成
 * x、y 座標。這樣每個格點都恰好對應一個編號。
 *
 * 複雜度：建立 O(r)；每次 pick O(log r)，
 * 額外空間 O(r)。
 * LeetCode 介面：保留 solutionCreate、solutionPick、solutionFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

struct Solution {
    int (*rectangles)[4];
    uint64_t *prefix;
    int count;
    uint64_t total;
};

static uint64_t randomBelow(uint64_t bound) {
    /* 兩次 rand() 組成一個均勻的較大範圍，再拒絕末端不完整區段。 */
    uint64_t radix = (uint64_t)RAND_MAX + 1;
    uint64_t range = radix * radix;
    uint64_t limit = range - range % bound;
    uint64_t value;
    do {
        value = (uint64_t)rand() * radix + (uint64_t)rand();
    } while (value >= limit);
    return value % bound;
}

struct Solution *solutionCreate(int **rects, int rectsSize, int *rectsColSize) {
    (void)rectsColSize;
    struct Solution *solution = calloc(1, sizeof(*solution));
    if (solution == NULL) return NULL;
    solution->count = rectsSize;
    solution->rectangles = malloc((size_t)rectsSize * sizeof(*solution->rectangles));
    solution->prefix = malloc((size_t)rectsSize * sizeof(*solution->prefix));
    if (solution->rectangles == NULL || solution->prefix == NULL) {
        free(solution->rectangles);
        free(solution->prefix);
        free(solution);
        return NULL;
    }

    for (int i = 0; i < rectsSize; ++i) {
        for (int j = 0; j < 4; ++j) solution->rectangles[i][j] = rects[i][j];
        uint64_t width = (uint64_t)((long long)rects[i][2] - rects[i][0] + 1);
        uint64_t height = (uint64_t)((long long)rects[i][3] - rects[i][1] + 1);
        solution->total += width * height;
        solution->prefix[i] = solution->total;
    }
    return solution;
}

int *solutionPick(struct Solution *solution) {
    uint64_t target = randomBelow(solution->total) + 1;
    int low = 0;
    int high = solution->count - 1;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (target <= solution->prefix[middle]) high = middle;
        else low = middle + 1;
    }

    uint64_t before = low == 0 ? 0 : solution->prefix[low - 1];
    uint64_t offset = target - before - 1;
    int *point = malloc(2 * sizeof(*point));
    if (point == NULL) return NULL;
    uint64_t width = (uint64_t)((long long)solution->rectangles[low][2]
                                - solution->rectangles[low][0] + 1);
    point[0] = solution->rectangles[low][0] + (int)(offset % width);
    point[1] = solution->rectangles[low][1] + (int)(offset / width);
    return point;
}

void solutionFree(struct Solution *solution) {
    if (solution == NULL) return;
    free(solution->rectangles);
    free(solution->prefix);
    free(solution);
}

int main(void) {
    srand(11);
    int first[] = {1, 1, 2, 2};
    int second[] = {3, 1, 3, 2};
    int *rectangles[] = {first, second};
    int columns[] = {4, 4};
    struct Solution *solution = solutionCreate(rectangles, 2, columns);
    assert(solution != NULL);
    for (int i = 0; i < 1000; ++i) {
        int *point = solutionPick(solution);
        assert(point != NULL);
        assert(point[1] == 1 || point[1] == 2);
        assert((point[0] >= 1 && point[0] <= 2) || point[0] == 3);
        free(point);
    }
    solutionFree(solution);
    return 0;
}
