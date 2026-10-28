/*
 * ==========================================================================
 * LeetCode 200. Number of Islands
 * Title-CN: 島嶼數量
 * Difficulty: Medium
 * Tags: array, depthfirst-search, breadthfirst-search, union-find, matrix
 * URL: https://leetcode.com/problems/number-of-islands/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Given an m x n 2D binary grid grid which represents a map of '1's (land)
 *     and '0's (water), return the number of islands.
 *     An island is surrounded by water and is formed by connecting adjacent
 *     lands horizontally or vertically. You may assume all four edges of the
 *     grid are all surrounded by water.
 *
 * [中文] 題目說明
 *     給定 m x n 的二元網格 grid，其中 '1' 表示陸地、'0' 表示水域，
 *     回傳島嶼數量。上下或左右相鄰的陸地屬於同一座島；斜角相鄰不算連接。
 *     每座島都被水包圍，且可假設網格外圍也是水。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：grid = [
 *     ["1","1","1","1","0"],
 *     ["1","1","0","1","0"],
 *     ["1","1","0","0","0"],
 *     ["0","0","0","0","0"]
 *     ]
 *     輸出：1
 *   範例 2：
 *     輸入：grid = [
 *     ["1","1","0","0","0"],
 *     ["1","1","0","0","0"],
 *     ["0","0","1","0","0"],
 *     ["0","0","0","1","1"]
 *     ]
 *     輸出：3
 *
 * [中文] 限制
 *   - m == grid.length。
 *   - n == grid[i].length。
 *   - 1 <= m, n <= 300。
 *   - grid[i][j] 只會是 '0' 或 '1'。
 *
 * LeetCode official C stub (函式簽名):
 *   int numIslands(char** grid, int gridSize, int* gridColSize) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 逐格掃描網格；遇到 '0' 直接略過。
 *   2. 每次遇到 '1' 就找到一座尚未計數的島，計數加一，並從該格開始深度優先搜尋。
 *   3. 用堆疊走訪上下左右相連的陸地；加入堆疊時立刻改成 '0'，避免重複加入。
 *   4. 整座島沉沒後繼續掃描，下一個仍為 '1' 的格子必屬於另一座島。
 *   每格最多處理一次，時間複雜度 O(m * n)，堆疊最壞空間 O(m * n)。此作法會修改 grid。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* ---------- LeetCode submission / 提交區 ---------- */
int numIslands(char **grid, int gridSize, int *gridColSize) {
    int cols = gridColSize[0], count = 0, r, c;
    int *stack = (int *)malloc((size_t)gridSize * cols * sizeof(int));
    for (r = 0; r < gridSize; ++r) {
        for (c = 0; c < cols; ++c) {
            int top = 0;
            if (grid[r][c] != '1') continue;
            /* 入堆疊時就標記為水，保證每格最多只入堆疊一次。 */
            stack[top++] = r * cols + c;
            grid[r][c] = '0';
            while (top) {
                int cur = stack[--top];
                int cr = cur / cols, cc = cur % cols;
                if (cr > 0 && grid[cr - 1][cc] == '1') { grid[cr - 1][cc] = '0'; stack[top++] = cur - cols; }
                if (cr + 1 < gridSize && grid[cr + 1][cc] == '1') { grid[cr + 1][cc] = '0'; stack[top++] = cur + cols; }
                if (cc > 0 && grid[cr][cc - 1] == '1') { grid[cr][cc - 1] = '0'; stack[top++] = cur - 1; }
                if (cc + 1 < cols && grid[cr][cc + 1] == '1') { grid[cr][cc + 1] = '0'; stack[top++] = cur + 1; }
            }
            count++;
        }
    }
    free(stack);
    return count;
}
/* ---------- end submission ---------- */

int main(void) {
    int ok = 1, colsz1 = 4, colsz2 = 4, i;
    char g1[3][4] = {{'1','1','0','0'},{'1','1','0','0'},{'0','0','1','0'}};
    char g2[3][4] = {{'1','1','0','0'},{'0','1','0','1'},{'1','0','1','1'}};
    char *rows1[3], *rows2[3];
    for (i = 0; i < 3; ++i) { rows1[i] = g1[i]; rows2[i] = g2[i]; }
    ok = ok && numIslands(rows1, 3, &colsz1) == 2;   /* {1,1 / 1,1} + {1} */
    ok = ok && numIslands(rows2, 3, &colsz2) == 3;
    printf("%s: 200 number-of-islands\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
