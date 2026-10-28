/*
 * Title-CN: 磚牆
 * LeetCode 554. Brick Wall
 *
 * 題意翻譯：牆由多列磚塊組成，每列的總寬度相同。畫一條從上到下的垂直線，
 * 若線剛好沿著磚縫通過，就不算切到該列的磚；請回傳最少會切到幾塊磚。
 * 線不能沿著牆的最左或最右邊緣。
 *
 * 範例：若某個內部位置的磚縫穿過最多列，答案就是總列數減去該位置的穿縫列數。
 *
 * 限制：列數為 1 到 10^4；每列磚塊數量不超過 10^4；磚寬為正整數。
 *
 * 解題思路：對每一列由左往右加總磚寬，記下每個內部磚縫的位置（最後一塊的
 * 右邊界不可選）。把所有位置排序，統計相同位置最多出現幾次。最佳切線穿過
 * 這麼多磚縫，因此最少切磚數 = 列數 - 最多穿過的磚縫列數。
 *
 * 複雜度：令 B 為牆中磚塊總數，時間 O(B log B)，空間 O(B)。
 * LeetCode 介面：保留 leastBricks；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

static int compareLongLong(const void *left, const void *right) {
    long long a = *(const long long *)left;
    long long b = *(const long long *)right;
    return (a > b) - (a < b);
}

int leastBricks(int **wall, int wallSize, int *wallColSize) {
    int capacity = 0;
    for (int row = 0; row < wallSize; ++row) capacity += wallColSize[row] - 1;
    if (capacity == 0) return wallSize;

    long long *edges = malloc((size_t)capacity * sizeof(*edges));
    if (edges == NULL) return wallSize;
    int count = 0;
    for (int row = 0; row < wallSize; ++row) {
        long long position = 0;
        for (int brick = 0; brick < wallColSize[row] - 1; ++brick) {
            position += wall[row][brick];
            edges[count++] = position;
        }
    }

    qsort(edges, (size_t)count, sizeof(*edges), compareLongLong);
    int mostRows = 0;
    int run = 0;
    for (int i = 0; i < count; ++i) {
        run = (i > 0 && edges[i] == edges[i - 1]) ? run + 1 : 1;
        if (run > mostRows) mostRows = run;
    }
    free(edges);
    return wallSize - mostRows;
}

int main(void) {
    int r0[] = {1, 2, 2, 1};
    int r1[] = {3, 1, 2};
    int r2[] = {1, 3, 2};
    int r3[] = {2, 4};
    int r4[] = {3, 1, 2};
    int r5[] = {1, 3, 1, 1};
    int *wall[] = {r0, r1, r2, r3, r4, r5};
    int columns[] = {4, 3, 3, 2, 3, 4};
    assert(leastBricks(wall, 6, columns) == 2);

    int singleBrick[] = {10};
    int *oneRow[] = {singleBrick};
    int oneColumn[] = {1};
    assert(leastBricks(oneRow, 1, oneColumn) == 1);
    return 0;
}
