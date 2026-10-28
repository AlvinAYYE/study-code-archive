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
 *     N 皇后問題要求在 n x n 棋盤上放置 n 個皇后，使任意兩個皇后都
 *     無法互相攻擊。給定整數 n，請回傳所有不同的合法棋盤配置，順序不限。
 *     每個配置由 n 個字串組成，其中 'Q' 表示皇后，'.' 表示空格。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：n = 4
 *     輸出：
 *     [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 *     說明：四皇后問題共有上述兩種不同解法。
 *   範例 2：
 *     輸入：n = 1
 *     輸出：[["Q"]]
 *
 * [中文] 限制：
 *   - 1 <= n <= 9
 *
 * LeetCode official C stub (函式簽名):
 *   char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
 *   }
 *
 * [EN] Approach: Row-by-row backtracking with columns + both diagonals marked used; snapshot the board when row==n. Classic O(n!).
 * [中文] 直觀解題思路：
 *   1. 每列恰好放一個皇后，從第 0 列開始，依序嘗試該列的每一欄。
 *   2. 同一欄不能重複；兩格 (r,c) 的 r+c 相同時在同一條「/」對角線，
 *      r-c 相同時在同一條「\\」對角線。用三個布林陣列 O(1) 判斷衝突。
 *   3. 選定位置後標記三種攻擊線，遞迴處理下一列；返回時取消標記，
 *      讓後續分支可以重新使用，這就是回溯。
 *   4. 當 r == n 時代表所有列都合法放完，依 pos[] 複製出一份棋盤答案。
 *
 * 複雜度：搜尋上界約 O(n!)；三組標記與路徑使用 O(n) 空間，輸出所需
 * 空間另計。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ---------- */
static void record(int n, int *pos, char ****boards, int *bcnt, int *bcap) {
    char **board; int r, c;
    /* 答案數未知，以倍增方式擴充棋盤指標陣列。 */
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
        /* r-c 可能為負，加上 n-1 後映射到 0..2n-2。 */
        if (ucol[c] || ud1[r + c] || ud2[r - c + n - 1]) continue;
        ucol[c] = ud1[r + c] = ud2[r - c + n - 1] = 1; pos[r] = c;
        bt(n, r + 1, pos, ucol, ud1, ud2, boards, bcnt, bcap);
        /* 復原選擇，繼續嘗試同一列的下一個欄位。 */
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
