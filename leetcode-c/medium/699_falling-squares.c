/*
 * LeetCode 699. Falling Squares（落下的方塊）
 *
 * 題意（繁體中文）：
 *   依序將正方形放到 x 軸上方。positions[i]=[left, side] 表示方塊左邊界在
 *   left，邊長為 side。方塊從高處落下，碰到下方方塊的頂面或 x 軸後停住；
 *   只擦過另一個方塊的側邊不算重疊。每放下一個方塊，就記錄目前所有堆疊中
 *   的最高高度，最後依順序回傳這些高度。
 *
 * 範例：
 *   1. positions=[[1,2],[2,3],[6,1]]，回傳 [2,5,5]。第二個方塊與第一個
 *      方塊有正長度的重疊，因此落在高度 2 上，頂端到 5。
 *   2. positions=[[100,100],[200,100]]，回傳 [100,100]。兩方塊只碰到邊界，
 *      不算重疊，第二個方塊直接落到地面。
 *   3. positions=[[1,1],[2,1]]，回傳 [1,1]，兩段區間相鄰但沒有交集。
 *
 * 限制：1 <= positions.length <= 1000；1 <= left <= 10^8；1 <= side <= 10^6。
 *
 * 解題步驟：
 *   1. 依序處理每個方塊，將它的水平範圍視為半開區間 [left,left+side)。
 *   2. 查看所有先前方塊，找出與此區間有正長度交集者，取其中最高的頂面；
 *      新方塊的頂面高度就是該高度加上自己的邊長。若沒有相交方塊，就從地面起算。
 *   3. 更新目前最高高度並存入答案。最多 1000 個方塊，逐一比較所有舊方塊
 *      已足夠快速，也最容易看懂。
 *
 * 複雜度：n 個方塊時，時間 O(n^2)，額外空間 O(n)。
 * LeetCode C API：
 * int* fallingSquares(int** positions, int positionsSize,
 *                     int* positionsColSize, int* returnSize)
 */
#include <stdio.h>
#include <stdlib.h>

int *fallingSquares(int **positions, int positionsSize,
                    int *positionsColSize, int *returnSize) {
    (void)positionsColSize;
    *returnSize = positionsSize;
    int *answer = (int *)malloc((size_t)positionsSize * sizeof *answer);
    int *topHeights = (int *)malloc((size_t)positionsSize * sizeof *topHeights);
    if (answer == NULL || topHeights == NULL) {
        free(answer);
        free(topHeights);
        *returnSize = 0;
        return NULL;
    }

    int tallest = 0;
    for (int i = 0; i < positionsSize; ++i) {
        int left = positions[i][0];
        int right = left + positions[i][1];
        int baseHeight = 0;

        for (int j = 0; j < i; ++j) {
            int oldLeft = positions[j][0];
            int oldRight = oldLeft + positions[j][1];
            /* 半開區間只有在交集長度大於 0 時才算真正重疊。 */
            if (left < oldRight && oldLeft < right && topHeights[j] > baseHeight)
                baseHeight = topHeights[j];
        }

        topHeights[i] = baseHeight + positions[i][1];
        if (topHeights[i] > tallest) tallest = topHeights[i];
        answer[i] = tallest;
    }

    free(topHeights);
    return answer;
}

static int matches(int *actual, int size, const int *expected, int expectedSize) {
    if (actual == NULL || size != expectedSize) return 0;
    for (int i = 0; i < size; ++i)
        if (actual[i] != expected[i]) return 0;
    return 1;
}

int main(void) {
    int a0[] = {1, 2}, a1[] = {2, 3}, a2[] = {6, 1};
    int *positions1[] = {a0, a1, a2};
    int columns1[] = {2, 2, 2};
    int expected1[] = {2, 5, 5};
    int size1 = 0;
    int *answer1 = fallingSquares(positions1, 3, columns1, &size1);

    int b0[] = {100, 100}, b1[] = {200, 100};
    int *positions2[] = {b0, b1};
    int columns2[] = {2, 2};
    int expected2[] = {100, 100};
    int size2 = 0;
    int *answer2 = fallingSquares(positions2, 2, columns2, &size2);

    int c0[] = {1, 1}, c1[] = {2, 1};
    int *positions3[] = {c0, c1};
    int columns3[] = {2, 2};
    int expected3[] = {1, 1};
    int size3 = 0;
    int *answer3 = fallingSquares(positions3, 2, columns3, &size3);

    int passed = matches(answer1, size1, expected1, 3) &&
                 matches(answer2, size2, expected2, 2) &&
                 matches(answer3, size3, expected3, 2);
    free(answer1);
    free(answer2);
    free(answer3);
    puts(passed ? "PASS: 699 falling-squares" : "FAIL: 699 falling-squares");
    return passed ? 0 : 1;
}
