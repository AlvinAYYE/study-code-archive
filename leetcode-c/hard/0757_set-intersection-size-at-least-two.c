/*
 * LeetCode 757. Set Intersection Size At Least Two
 * 題意（繁體中文）：給定多個整數閉區間，找出最小的整數集合，使每個區間
 * 至少包含集合中的兩個不同整數。回傳這個集合最少有幾個數。
 *
 * 範例：[[1,3],[3,7],[8,9]] -> 5；[[1,3],[1,4],[2,5],[3,5]] -> 3。
 *       [[1,2],[2,3],[2,4],[4,5]] -> 5。
 * 限制：區間最多 3000 個；0 <= start < end <= 10^8。
 * 解法：先依右端點由小到大排序，右端點相同時起點由大到小。
 *       維護已選數字中最大的兩個。若區間少於兩個已選數，就從右端開始
 *       補最靠右且尚未選的數字。靠右選能盡量留位置給後續區間，因此最優。
 * 複雜度：O(n log n) 時間、O(n) 額外空間。
 * LeetCode C API：int intersectionSizeTwo(int** intervals, int intervalsSize,
 *                                          int* intervalsColSize)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

static int compareIntervals(const void *left, const void *right) {
    const Interval *a = (const Interval *)left;
    const Interval *b = (const Interval *)right;
    if (a->end != b->end) return (a->end > b->end) - (a->end < b->end);
    return (b->start > a->start) - (b->start < a->start);
}

int intersectionSizeTwo(int** intervals, int intervalsSize, int* intervalsColSize) {
    (void)intervalsColSize;
    Interval *sorted = (Interval *)malloc((size_t)intervalsSize * sizeof *sorted);
    if (sorted == NULL) return 0;
    for (int i = 0; i < intervalsSize; ++i)
        sorted[i] = (Interval){intervals[i][0], intervals[i][1]};
    qsort(sorted, (size_t)intervalsSize, sizeof *sorted, compareIntervals);

    int secondLargest = -1, largest = -1, answer = 0;
    for (int i = 0; i < intervalsSize; ++i) {
        int start = sorted[i].start, end = sorted[i].end;
        if (start > largest) {
            secondLargest = end - 1;
            largest = end;
            answer += 2;
        } else if (start > secondLargest) {
            secondLargest = largest;
            largest = end;
            ++answer;
        }
    }
    free(sorted);
    return answer;
}

static int runCase(int rows[][2], int count, int expected) {
    int *intervals[4];
    int columns[4];
    for (int i = 0; i < count; ++i) {
        intervals[i] = rows[i];
        columns[i] = 2;
    }
    return intersectionSizeTwo(intervals, count, columns) == expected;
}

int main(void) {
    int a[][2] = {{1, 3}, {3, 7}, {8, 9}};
    int b[][2] = {{1, 3}, {1, 4}, {2, 5}, {3, 5}};
    int c[][2] = {{1, 2}, {2, 3}, {2, 4}, {4, 5}};
    int passed = runCase(a, 3, 5) && runCase(b, 4, 3) && runCase(c, 4, 5);
    puts(passed ? "PASS: 757 set-intersection-size-at-least-two"
                : "FAIL: 757 set-intersection-size-at-least-two");
    return passed ? 0 : 1;
}
