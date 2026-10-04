/*
 * ==========================================================================
 * LeetCode 051. N-Queens
 * Title-CN: N 皇后
 * Difficulty: Hard
 * Tags: array, backtracking
 * URL: https://leetcode.com/problems/n-queens/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     The n-queens puzzle is the problem of placing n queens on an n x n
 *     chessboard such that no two queens attack each other.
 *     Given an integer n, return all distinct solutions to the n-queens
 *     puzzle. You may return the answer in any order.
 *     Each solution contains a distinct board configuration of the n-queens'
 *     placement, where 'Q' and '.' both indicate a queen and an empty space,
 *     respectively.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     在 n×n 棋盤放 n 個皇后互不攻擊，回傳所有布局。
 *
 * Examples:
 *   Example 1:
 *     Input: n = 4
 *     Output:
 *     [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 *     Explanation: There exist two distinct solutions to the 4-queens
 *     puzzle as shown above
 *   Example 2:
 *     Input: n = 1
 *     Output: [["Q"]]
 *
 * Constraints:
 *   - 1 <= n <= 9
 *
 * LeetCode official C stub (函式簽名):
 *   char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [EN] Approach: Row-by-row backtracking with columns + both diagonals marked used; snapshot the board when row==n. Classic O(n!).
 * [中文] 思路: 逐行放置＋回溯，用陣列記錄欄位與兩條對角線是否被占；放滿 n 行就複製棋盤。時間 O(n!)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static void record(int n, int *pos, char ****boards, int *bcnt, int *bcap) {
    char **board; int r, c;
    if (*bcnt == *bcap) {
        *bcap = *bcap ? *bcap * 2 : 8;
        *boards = (char ***)realloc(*boards, (size_t)*bcap * sizeof(char **));
    }
    board = (char **)malloc((size_t)n * sizeof(char *));
    for (r = 0; r < n; ++r) {
        char *row = (char *)malloc((size_t)n + 1);
        for (c = 0; c < n; ++c) row[c] = (c == pos[r]) ? 'Q' : '.';
        row[n] = '\0';
        board[r] = row;
    }
    (*boards)[(*bcnt)++] = board;
}

static void bt(int n, int r, int *pos, char *ucol, char *ud1, char *ud2,
               char ****boards, int *bcnt, int *bcap) {
    int c;
    if (r == n) { record(n, pos, boards, bcnt, bcap); return; }
    for (c = 0; c < n; ++c) {
        if (ucol[c] || ud1[r + c] || ud2[r - c + n - 1]) continue;
        ucol[c] = ud1[r + c] = ud2[r - c + n - 1] = 1; pos[r] = c;
        bt(n, r + 1, pos, ucol, ud1, ud2, boards, bcnt, bcap);
        ucol[c] = ud1[r + c] = ud2[r - c + n - 1] = 0;
    }
}

char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes) {
    int *pos, i, bcnt = 0, bcap = 0;
    char *ucol, *ud1, *ud2;
    char ***boards = NULL;
    int *cols;
    pos  = (int *)malloc((size_t)n * sizeof(int));
    ucol = (char *)calloc((size_t)n, 1);
    ud1  = (char *)calloc((size_t)(2 * n - 1), 1);
    ud2  = (char *)calloc((size_t)(2 * n - 1), 1);
    bt(n, 0, pos, ucol, ud1, ud2, &boards, &bcnt, &bcap);
    cols = (int *)malloc((size_t)(bcnt ? bcnt : 1) * sizeof(int));
    for (i = 0; i < bcnt; ++i) cols[i] = n;
    *returnSize = bcnt;
    *returnColumnSizes = cols;
    free(pos); free(ucol); free(ud1); free(ud2);
    return boards;
}
/* ---------- end submission ---------- */

static int cmpBoard(const void *a, const void *b) {
    /* 元素是 char** (棋盤)；多剝一層才拿到第一列字串 */
    const char *const *ba = *(const char *const **)a;
    const char *const *bb = *(const char *const **)b;
    return strcmp(ba[0], bb[0]);
}
static int boardeq(char **b, const char *const *e, int n) {
    int r;
    for (r = 0; r < n; ++r) if (strcmp(b[r], e[r]) != 0) return 0;
    return 1;
}

int main(void) {
    int ok = 1, rs = 0; int *cols = NULL; char ***out;
    const char *sol1[4] = {"..Q.", "Q...", "...Q", ".Q.."};
    const char *sol2[4] = {".Q..", "...Q", "Q...", "..Q."};
    out = solveNQueens(4, &rs, &cols);
    qsort(out, (size_t)rs, sizeof(char **), cmpBoard);
    ok = ok && rs == 2 && cols[0] == 4 && cols[1] == 4;
    ok = ok && boardeq(out[0], sol1, 4) && boardeq(out[1], sol2, 4);

    rs = 0; out = solveNQueens(1, &rs, &cols);
    ok = ok && rs == 1 && strcmp(out[0][0], "Q") == 0;

    rs = 0; out = solveNQueens(6, &rs, &cols);
    ok = ok && rs == 4;
    printf("%s: 051 n-queens\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
