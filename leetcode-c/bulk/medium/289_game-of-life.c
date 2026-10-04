/*
 * ==========================================================================
 * LeetCode 0289. Game of Life
 * Difficulty: Medium
 * Tags: array, matrix, simulation
 * URL: https://leetcode.com/problems/game-of-life/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     According to Wikipedia's article: "The Game of Life, also known
 *     simply as Life, is a cellular automaton devised by the British
 *     mathematician John Horton Conway in 1970."
 *     The board is made up of an m x n grid of cells, where each cell has
 *     an initial state: live (represented by a 1) or dead (represented by
 *     a 0). Each cell interacts with its eight neighbors (horizontal,
 *     vertical, diagonal) using the following four rules (taken from the
 *     above Wikipedia article):
 *     The next state of the board is determined by applying the above
 *     rules simultaneously to every cell in the current state of the m x n
 *     grid board. In this process, births and deaths occur simultaneously.
 *     Given the current state of the board, update the board to reflect
 *     its next state.
 *     Note that you do not need to return anything.
 *
 * [中文] 題目: 生命遊戲
 * [中文] 題目說明:
 *     給定 m × n 的細胞棋盤，1 代表活細胞、0 代表死細胞；每個細
 *     胞只考慮周圍八個方向的鄰居。所有細胞必須同時依規則更新：活細胞有 2
 *      或 3 個活鄰居才存活，死細胞恰有 3 個活鄰居才復活，其餘情況為
 *     死亡或維持死亡。請原地把棋盤改為下一世代，無須回傳值。
 *
 * [中文] 思路:
 *     第一輪以低位保存原狀、以 0x10 標記下一世代，計算鄰居時只讀低位
 *     ，因此不會受已處理格子影響。第二輪再依高位統一寫回 0 或 1。
 *
 * Examples:
 *     Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
 *     Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
 *     Input: board = [[1,1],[1,0]]
 *     Output: [[1,1],[1,1]]
 *
 * Constraints:
 *   - m == board.length
 *   - n == board[i].length
 *   - 1 <= m, n <= 25
 *   - board[i][j] is 0 or 1.
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
struct ListNode { int val; struct ListNode *next; };
typedef struct ListNode ListNode;
struct TreeNode { int val; struct TreeNode *left; struct TreeNode *right; };
typedef struct TreeNode TreeNode;
#define LC_NULL (-2147483400)
static ListNode *lc_mklist(const int *a, int n) {
    ListNode *head = NULL; int i;
    for (i = n - 1; i >= 0; --i) { ListNode *nd = (ListNode*)malloc(sizeof *nd); nd->val = a[i]; nd->next = head; head = nd; }
    return head;
}
static TreeNode *lc_mktree(const int *tk, int n) {
    TreeNode **q; int qh = 0, qt = 0, i = 0;
    if (n == 0 || tk[0] == LC_NULL) return NULL;
    q = (TreeNode**)malloc(sizeof(TreeNode*) * (size_t)(n + 1));
    TreeNode *root = (TreeNode*)malloc(sizeof *root);
    root->val = tk[0]; root->left = root->right = NULL; q[qt++] = root; i = 1;
    while (qh < qt && i < n) {
        TreeNode *cur = q[qh++];
        if (i < n) { if (tk[i] != LC_NULL) { TreeNode *nd = (TreeNode*)malloc(sizeof *nd); nd->val = tk[i]; nd->left = nd->right = NULL; cur->left = nd; q[qt++] = nd; } i++; }
        if (i < n) { if (tk[i] != LC_NULL) { TreeNode *nd = (TreeNode*)malloc(sizeof *nd); nd->val = tk[i]; nd->left = nd->right = NULL; cur->right = nd; q[qt++] = nd; } i++; }
    }
    free(q);
    return root;
}
static void lc_list2str(ListNode *l, char *buf, int cap) {
    int n = 0, first = 1;
    n += snprintf(buf + n, cap - n, "[");
    while (l && n < cap - 16) { n += snprintf(buf + n, cap - n, "%s%d", first ? "" : ",", l->val); first = 0; l = l->next; }
    snprintf(buf + n, cap - n, "]");
}
static void lc_tree2str(TreeNode *root, char *buf, int cap) {
    TreeNode **q; int qh = 0, qt = 0, n = 0, first = 1;
    char tmp[16384];
    q = (TreeNode**)malloc(sizeof(TreeNode*) * 4096);
    if (root) q[qt++] = root;
    while (qh < qt) {
        TreeNode *cur = q[qh++];
        if (!cur) { n += snprintf(tmp + n, sizeof tmp - n, "%s%s", first ? "" : ",", "null"); first = 0; continue; }
        n += snprintf(tmp + n, sizeof tmp - n, "%s%d", first ? "" : ",", cur->val); first = 0;
        if (qt < 4094) { q[qt++] = cur->left; q[qt++] = cur->right; }
    }
    /* trim trailing nulls */
    {   /* remove trailing ",null" groups */
        for (;;) {
            size_t len = strlen(tmp);
            if (len > 5 && strcmp(tmp + len - 5, "null") == 0) { tmp[len - 5] = '\0'; if (len - 6 >= 0 && tmp[len - 6] == ',') tmp[len - 6] = '\0'; }
            else break;
        }
    }
    snprintf(buf, cap, "[%s]", tmp[0] ? tmp : "");
    free(q);
}
static void lc_tokens2str(const int *tk, int n, char *buf, int cap) {
    int i, k = 0;
    k += snprintf(buf + k, cap - k, "[");
    for (i = 0; i < n && k < cap - 20; ++i) {
        if (i) k += snprintf(buf + k, cap - k, ",");
        if (tk[i] == LC_NULL) k += snprintf(buf + k, cap - k, "null");
        else k += snprintf(buf + k, cap - k, "%d", tk[i]);
    }
    snprintf(buf + k, cap - k, "]");
}
static int lc_cmp_tokens(const char *a, const char *b) {
    const char *p = a + 1, *q = b + 1;
    for (;;) {
        while (*p == ' ') p++;
        while (*q == ' ') q++;
        if (*p == ']' && *q == ']') return 1;
        if (!*p || !*q) return 0;
        if (*p == ']' || *q == ']') return 0;
        size_t lp = strcspn(p, ",]"), lq = strcspn(q, ",]");
        if (lp != lq || strncmp(p, q, lp) != 0) return 0;
        p += lp; q += lq;
        if (*p == ',') p++;
        if (*q == ',') q++;
    }
}
static int lc_eq_list(int *a, int n, const int *b, int m) {
    int i;
    if (n != m) return 0;
    for (i = 0; i < n; ++i) if (a[i] != b[i]) return 0;
    return 1;
}
static int lc_eq_dbl(double *a, int n, const double *b, int m) { int i; if (n != m) return 0; for (i = 0; i < n; ++i) if (fabs(a[i] - b[i]) > 1e-4 + 1e-6 * fabs(b[i])) return 0; return 1; }
static int lc_bcmp(const void* x, const void* y) { return (*(const int*)x) - (*(const int*)y); }
static int lc_eq_bool_sorted(bool *a, int n, const int *b, int m) {
    int *c; int i;
    if (n != m) return 0;
    c = (int*)malloc(sizeof(int) * (size_t)(n > 0 ? n : 1));
    for (i = 0; i < n; ++i) c[i] = a[i] ? 1 : 0;
    qsort(c, (size_t)n, sizeof(int), lc_bcmp);
    for (i = 0; i < n; ++i) if (c[i] != b[i]) { free(c); return 0; }
    free(c);
    return 1;
}
static int lc_cmp_ints(const void *x, const void *y) { return (*(const int*)x > *(const int*)y) - (*(const int*)x < *(const int*)y); }
static int lc_eq_list_sorted(int *a, int n, const int *b, int m) {
    int *c = (int*)malloc(sizeof(int) * (size_t)(n > 0 ? n : 1)), i;
    if (n != m) { free(c); return 0; }
    memcpy(c, a, sizeof(int) * (size_t)n);
    qsort(c, (size_t)n, sizeof(int), lc_cmp_ints);
    for (i = 0; i < n; ++i) if (c[i] != b[i]) { free(c); return 0; }
    free(c);
    return 1;
}
static void lc_ser_ii(int **rows, const int *rcs, int nr, char *buf, int cap) {
    int r, c, n = 0;
    buf[n++] = '[';
    for (r = 0; r < nr; ++r) {
        if (r) buf[n++] = ',';
        buf[n++] = '[';
        for (c = 0; c < rcs[r]; ++c) n += snprintf(buf + n, cap - n, "%s%d", c ? "," : "", rows[r][c]);
        buf[n++] = ']';
    }
    buf[n++] = ']'; buf[n] = 0;
}
static void lc_ser_cs(char **flat, const int *gsz, int ng, char *buf, int cap) {
    int i, n = 0;
    buf[n++] = '[';
    for (i = 0; i < ng; ++i) { if (i) buf[n++] = ','; n += snprintf(buf + n, cap - n, "%s", flat[i]); }
    buf[n++] = ']'; buf[n] = 0;
}
static int lc_strcmp_pp(const void *x, const void *y) { return strcmp(*(char *const*)x, *(char *const*)y); }
static void lc_join_sorted(char *const *arr, int n, char *buf, int cap) {
    char **c; int i, k = 0;
    c = (char**)malloc(sizeof(char*) * (size_t)(n > 0 ? n : 1));
    for (i = 0; i < n; ++i) c[i] = arr[i];
    qsort(c, (size_t)n, sizeof(char*), lc_strcmp_pp);
    for (i = 0; i < n; ++i) k += snprintf(buf + k, cap - k, "%s%s", i ? "," : "", c[i]);
    free(c);
}
static int lc_eq_cands(char *const *a, int n, char *const *b, int m) {
    static char A[400000], B[400000];
    if (n != m) return 0;
    lc_join_sorted(a, n, A, sizeof A);
    lc_join_sorted(b, n, B, sizeof B);
    return strcmp(A, B) == 0;
}

static void lc_canon_ii(int **rows, const int *rcs, int nr, char *buf, int cap) {
    static char pool[400000]; char *rp[4096]; static int tmpi[1024];
    int i, j, pk = 0, k = 0;
    if (nr > 4096) nr = 4096;
    for (i = 0; i < nr; ++i) {
        char *pp; int m = rcs[i];
        if (m > 1024) m = 1024;
        for (j = 0; j < m; ++j) tmpi[j] = rows[i][j];
        qsort(tmpi, (size_t)m, sizeof(int), lc_cmp_ints);
        rp[i] = pool + pk; pp = rp[i];
        pp += sprintf(pp, "[");
        for (j = 0; j < m; ++j) pp += sprintf(pp, "%s%d", j ? "," : "", tmpi[j]);
        pp += sprintf(pp, "]");
        pk = (int)(pp - pool) + 1;
        if (pk > 380000) { nr = i + 1; break; }
    }
    qsort(rp, (size_t)nr, sizeof(char*), lc_strcmp_pp);
    if (k < cap - 2) buf[k++] = '[';
    for (i = 0; i < nr; ++i) {
        const char *q = rp[i];
        if (i && k < cap - 2) buf[k++] = ',';
        while (*q && k < cap - 2) buf[k++] = *q++;
    }
    if (k < cap - 2) buf[k++] = ']';
    buf[k] = 0;
}

/* ---- community solution ---- */
static int lc_dummy_;
/**

  289. Game of Life [Medium]

  According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

  Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

  Any live cell with fewer than two live neighbors dies, as if caused by under-population.
  Any live cell with two or three live neighbors lives on to the next generation.
  Any live cell with more than three live neighbors dies, as if by over-population..
  Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
  Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:
Input: 
[
	[0,1,0],
	[0,0,1],
	[1,1,1],
	[0,0,0]
]

Output: 
[
	[0,0,0],
	[1,0,1],
	[0,1,1],
	[0,1,0]
]

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

 */

void checkNeighbor(int** board, int row, int col, int rowSize, int colSize, int *live, int *dead)
{
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y ++)
		{
			int curRow = row + x;
			int curCol = col + y;

			if (curRow < 0 || curRow >= rowSize ||
					curCol < 0 || curCol >= colSize ||
					(curRow == row && curCol == col))
			{
				continue;
			}
			if ((board[curRow][curCol] & 0x01) == 0x01)
			{
				*live += 1;
			} else
			{
				*dead += 1;
			}
		}
	}    
}

void gameOfLife(int** board, int boardSize, int* boardColSize){

	if (boardSize == 0)
	{
		return board;        
	}

	int colSize = boardColSize[0];
	for (int x = 0; x < boardSize; x++)
	{
		for (int y = 0; y < colSize; y++)
		{            
			int live = 0, dead = 0;
			checkNeighbor(board, x, y, boardSize, colSize, &live, &dead);                        
			if ((board[x][y] & 0x01) == 0x01) /* live */
			{
				if (live == 2 || live == 3)
				{
					board[x][y] |= 0x10;
				}
			} else /* dead */
			{
				if (live == 3)
				{
					board[x][y] |= 0x10;
				}
			}
		}
	}

	for (int x = 0; x < boardSize; x++)
	{
		for (int y = 0; y < colSize; y++)
		{        
			if ((board[x][y] & 0x10) == 0x10)
			{
				board[x][y] = 1;
			} else
			{
				board[x][y] = 0;
			}
		}
	}
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {0,1,0};
  static int mr0_0_1[] = {0,0,1};
  static int mr0_0_2[] = {1,1,1};
  static int mr0_0_3[] = {0,0,0};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3};
  static int mc0_0[] = {3,3,3,3};
  gameOfLife(mp0_0, 4,mc0_0);
  static const int vex_0_0[] = {0,0,0};
  static const int vex_0_1[] = {1,0,1};
  static const int vex_0_2[] = {0,1,1};
  static const int vex_0_3[] = {0,1,0};
  if (!((lc_eq_list(mp0_0[0], 3, vex_0_0, 3) && lc_eq_list(mp0_0[1], 3, vex_0_1, 3) && lc_eq_list(mp0_0[2], 3, vex_0_2, 3) && lc_eq_list(mp0_0[3], 3, vex_0_3, 3)))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,1};
  static int mr1_0_1[] = {1,0};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1};
  static int mc1_0[] = {2,2};
  gameOfLife(mp1_0, 2,mc1_0);
  static const int vex_1_0[] = {1,1};
  static const int vex_1_1[] = {1,1};
  if (!((lc_eq_list(mp1_0[0], 2, vex_1_0, 2) && lc_eq_list(mp1_0[1], 2, vex_1_1, 2)))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 289, "gameOfLife", ntests);
 return (pass&&ntests)?0:1;
}
