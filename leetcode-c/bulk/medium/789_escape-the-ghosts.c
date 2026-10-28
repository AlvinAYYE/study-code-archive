/*
 * LeetCode 0789. Escape The Ghosts（逃離鬼魂）
 * 題意：玩家從 (0,0) 走向 target，鬼魂各從 ghosts[i] 出發；每回合都可向上下左右移一格或停留。
 *       玩家必須比所有鬼魂先到終點，同時到達也算被抓；判斷是否必定能逃脫。
 * 範例：target=[0,1]、ghosts=[[1,0],[0,3]] -> true；ghosts=[[1,0]], target=[2,0] -> false。
 * 限制：ghosts 數量 1..100；鬼魂與目標座標介於 -10^4 到 10^4。
 * 解法：玩家到終點最短步數為曼哈頓距離；若任一鬼魂到終點的距離不大於玩家距離，鬼魂可在玩家之前或同時到達並攔截。
 * 複雜度：時間 O(g)，空間 O(1)。
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

/* ---- community solution ---- */
bool escapeGhosts(int** ghosts, int ghostsSize, int* ghostsColSize,
                  int* target, int targetSize) {
    (void)ghostsColSize;
    (void)targetSize;
    int playerDistance = manhattanDistance(0, 0, target[0], target[1]);
    for (int i = 0; i < ghostsSize; i++) {
        int ghostDistance = manhattanDistance(ghosts[i][0], ghosts[i][1],
                                             target[0], target[1]);
        if (ghostDistance <= playerDistance) {
            return false;
        }
    }
    return true;
}

/* ---- generated tests ---- */
int main(void) {
    int ghostOneA[] = {1, 0};
    int ghostOneB[] = {0, 3};
    int *ghostsOne[] = {ghostOneA, ghostOneB};
    int ghostOneColumns[] = {2, 2};
    int targetOne[] = {0, 1};

    int ghostTwoA[] = {1, 0};
    int *ghostsTwo[] = {ghostTwoA};
    int ghostTwoColumns[] = {2};
    int targetTwo[] = {2, 0};

    int ghostThreeA[] = {2, 0};
    int *ghostsThree[] = {ghostThreeA};
    int targetThree[] = {1, 0};
    bool passed = escapeGhosts(ghostsOne, 2, ghostOneColumns, targetOne, 2) &&
                  !escapeGhosts(ghostsTwo, 1, ghostTwoColumns, targetTwo, 2) &&
                  !escapeGhosts(ghostsThree, 1, ghostTwoColumns, targetThree, 2);
    printf("%s: 0789 escapeGhosts tests=3\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}
