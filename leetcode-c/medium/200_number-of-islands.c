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
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     由 '1'(陸) 與 '0'(海) 組成的網格中數互不相連的島嶼數量（四相連）。
 *
 * Examples:
 *   Example 1:
 *     Input: grid = [
 *     ["1","1","1","1","0"],
 *     ["1","1","0","1","0"],
 *     ["1","1","0","0","0"],
 *     ["0","0","0","0","0"]
 *     ]
 *     Output: 1
 *   Example 2:
 *     Input: grid = [
 *     ["1","1","0","0","0"],
 *     ["1","1","0","0","0"],
 *     ["0","0","1","0","0"],
 *     ["0","0","0","1","1"]
 *     ]
 *     Output: 3
 *
 * Constraints:
 *   - m == grid.length
 *   - n == grid[i].length
 *   - 1 <= m, n <= 300
 *   - grid[i][j] is '0' or '1'.
 *
 * LeetCode official C stub (函式簽名):
 *   int numIslands(char** grid, int gridSize, int* gridColSize) {
 *   }
 *
 * [EN] Approach: Flood fill: from every unseen '1' run iterative BFS/DFS sinking its whole island; counter += 1. Time O(m*n).
 * [中文] 思路: 洪水填充：每遇到未訪問的 1 就用堆疊把整座島沉下去並計數一次。時間 O(m*n)。
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
            stack[top++] = r * cols + c;
            grid[r][c] = '0';                       /* sink while exploring */
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
