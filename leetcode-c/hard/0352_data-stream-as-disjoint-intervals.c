/*
 * LeetCode 352. Data Stream as Disjoint Intervals（資料流的互斥區間）
 *
 * 題意（繁體中文）：
 *   一次收到一個整數，請維護目前收到的所有不同數字，並將連續整數合併成
 *   不重疊且排序的閉區間 [start,end]。實作加入數字與回傳目前所有區間兩種操作。
 *
 * 範例：
 *   依序加入 1、3、7、2、6，區間依序為：
 *   [[1,1]]、[[1,1],[3,3]]、[[1,1],[3,3],[7,7]]、
 *   [[1,3],[7,7]]、[[1,3],[6,7]]。
 *
 * 限制：0 <= value <= 10^4；addNum 與 getIntervals 合計最多 3*10^4 次；
 *   getIntervals 最多呼叫 10^2 次。
 *
 * 解題步驟：
 *   1. 值域只有 0..10000，用一個布林陣列記錄每個數字是否出現；重複加入只
 *      會把同一格再設為已出現。
 *   2. 回傳區間時由小到大掃描，遇到已出現的數字就延伸連續區段，直到下一個
 *      未出現的數字，輸出該段的起訖值。
 *   3. 回傳的二維陣列與欄數陣列由函式配置，呼叫端負責釋放；資料結構本身
 *      只需保存固定大小的存在標記。
 *
 * 複雜度：addNum O(1)；getIntervals O(U)，U=10001；結構空間 O(U)。
 * LeetCode C API：summaryRangesCreate、summaryRangesAddNum、
 *                  summaryRangesGetIntervals、summaryRangesFree
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 10000

typedef struct {
    unsigned char present[MAX_VALUE + 1];
} SummaryRanges;

SummaryRanges *summaryRangesCreate(void) {
    return (SummaryRanges *)calloc(1, sizeof(SummaryRanges));
}

void summaryRangesAddNum(SummaryRanges *obj, int value) {
    if (obj != NULL && value >= 0 && value <= MAX_VALUE)
        obj->present[value] = 1;
}

int **summaryRangesGetIntervals(SummaryRanges *obj, int *retSize,
                                int **retColSize) {
    *retSize = 0;
    *retColSize = NULL;
    if (obj == NULL) return NULL;

    int intervalCount = 0;
    for (int value = 0; value <= MAX_VALUE;) {
        if (!obj->present[value]) {
            ++value;
            continue;
        }
        ++intervalCount;
        while (value <= MAX_VALUE && obj->present[value]) ++value;
    }
    if (intervalCount == 0) return NULL;

    int **intervals = (int **)malloc((size_t)intervalCount * sizeof *intervals);
    int *columnSizes = (int *)malloc((size_t)intervalCount * sizeof *columnSizes);
    if (intervals == NULL || columnSizes == NULL) {
        free(intervals);
        free(columnSizes);
        return NULL;
    }

    int outputIndex = 0;
    for (int value = 0; value <= MAX_VALUE;) {
        if (!obj->present[value]) {
            ++value;
            continue;
        }
        int start = value;
        while (value <= MAX_VALUE && obj->present[value]) ++value;
        intervals[outputIndex] = (int *)malloc(2 * sizeof **intervals);
        if (intervals[outputIndex] == NULL) {
            for (int i = 0; i < outputIndex; ++i) free(intervals[i]);
            free(intervals);
            free(columnSizes);
            return NULL;
        }
        intervals[outputIndex][0] = start;
        intervals[outputIndex][1] = value - 1;
        columnSizes[outputIndex] = 2;
        ++outputIndex;
    }

    *retSize = intervalCount;
    *retColSize = columnSizes;
    return intervals;
}

void summaryRangesFree(SummaryRanges *obj) {
    free(obj);
}

static int intervalsMatch(int **actual, int size, const int expected[][2], int expectedSize) {
    if (actual == NULL || size != expectedSize) return 0;
    for (int i = 0; i < size; ++i)
        if (actual[i][0] != expected[i][0] || actual[i][1] != expected[i][1])
            return 0;
    return 1;
}

static void freeIntervals(int **intervals, int size, int *columnSizes) {
    for (int i = 0; i < size; ++i) free(intervals[i]);
    free(intervals);
    free(columnSizes);
}

int main(void) {
    SummaryRanges *obj = summaryRangesCreate();
    if (obj == NULL) return 1;
    const int expected[][3][2] = {
        {{1, 1}, {0, 0}, {0, 0}},
        {{1, 1}, {3, 3}, {0, 0}},
        {{1, 1}, {3, 3}, {7, 7}},
        {{1, 3}, {7, 7}, {0, 0}},
        {{1, 3}, {6, 7}, {0, 0}}
    };
    const int expectedSizes[] = {1, 2, 3, 2, 2};
    const int inputs[] = {1, 3, 7, 2, 6};
    int passed = 1;
    for (int step = 0; step < 5; ++step) {
        summaryRangesAddNum(obj, inputs[step]);
        int size = 0, *columns = NULL;
        int **intervals = summaryRangesGetIntervals(obj, &size, &columns);
        passed = passed && intervalsMatch(intervals, size, expected[step],
                                          expectedSizes[step]);
        if (columns != NULL)
            for (int i = 0; i < size; ++i)
                if (columns[i] != 2) passed = 0;
        freeIntervals(intervals, size, columns);
    }
    summaryRangesAddNum(obj, 2); /* 重複加入不會改變區間。 */
    int size = 0, *columns = NULL;
    int **intervals = summaryRangesGetIntervals(obj, &size, &columns);
    const int expectedFinal[][2] = {{1, 3}, {6, 7}};
    passed = passed && intervalsMatch(intervals, size, expectedFinal, 2);
    freeIntervals(intervals, size, columns);
    summaryRangesFree(obj);
    puts(passed ? "PASS: 352 data-stream-as-disjoint-intervals"
                : "FAIL: 352 data-stream-as-disjoint-intervals");
    return passed ? 0 : 1;
}
