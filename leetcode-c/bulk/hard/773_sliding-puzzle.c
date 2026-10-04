/*
 * ==========================================================================
 * LeetCode 0773. Sliding Puzzle
 * Difficulty: Hard
 * Tags: array, dynamic-programming, backtracking, breadth-first-search, memoization, matrix
 * URL: https://leetcode.com/problems/sliding-puzzle/
 * Source: community solution, repo caotrongphuoc_algorithms (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an
 *     empty square represented by 0. A move consists of choosing 0 and a
 *     4-directionally adjacent number and swapping it.
 *     The state of the board is solved if and only if the board is
 *     [[1,2,3],[4,5,0]].
 *     Given the puzzle board board, return the least number of moves
 *     required so that the state of the board is solved. If it is
 *     impossible for the state of the board to be solved, return -1.
 *
 * [中文] 題目: 滑動拼圖
 * [中文] 題目說明:
 *     在 2 × 3 棋盤中，數字 1 至 5 與空格 0 可將 0 和上
 *     下左右相鄰數字交換。求將棋盤變為 [[1,2,3],[4,5,0]]
 *      的最少步數；若無法復原則回傳 -1。
 *
 * [中文] 思路:
 *     將棋盤壓成六字元狀態字串，對 0 的合法交換位置做廣度優先搜尋，並用
 *     已拜訪狀態避免重複；首次到達目標的層數即為答案。
 *
 * Examples:
 *     Input: board = [[1,2,3],[4,0,5]]
 *     Output: 1
 *     Explanation: Swap the 0 and the 5 in one move.
 *     Input: board = [[1,2,3],[5,4,0]]
 *     Output: -1
 *     Explanation: No number of moves will make the board solved.
 *     Input: board = [[4,1,2],[5,0,3]]
 *     Output: 5
 *     Explanation: 5 is the smallest number of moves that solves the
 *     board.
 *     An example path:
 *     After move 0: [[4,1,2],[5,0,3]]
 *     After move 1: [[4,1,2],[0,5,3]]
 *     After move 2: [[0,1,2],[4,5,3]]
 *     After move 3: [[1,0,2],[4,5,3]]
 *     After move 4: [[1,2,0],[4,5,3]]
 *     After move 5: [[1,2,3],[4,5,0]]
 *
 * Constraints:
 *   - board.length == 2
 *   - board[i].length == 3
 *   - 0 <= board[i][j] <= 5
 *   - Each value board[i][j] is unique.
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
int slidingPuzzle(int** board, int boardSize, int* boardColSize) 
{
    char start[7];
    int idx = 0;
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardColSize[i]; j++)
        {
            start[idx++] = '0' + board[i][j];
        }
    }
    start[6] = '\0';
    char target[] = "123450";

    if(strcmp(start, target) == 0) return 0;

    int neighbors[6][4] = {
        {1, 3, -1, -1},
        {0, 2, 4, -1},
        {1, 5, -1, -1},
        {0, 4, -1, -1},
        {1, 3, 5, -1},
        {2, 4, -1, -1},
    };
    int neighborCount[6] = {2, 3, 2, 2, 3, 2};

    //#define MAX 5041
    
    char queue[720][7];
    int steps[720];
    int front = 0, back = 0;

    char visited[720][7];
    int visitedCount = 0;

    strcpy(queue[back], start);
    steps[back] = 0;
    back++;
    strcpy(visited[visitedCount++], start);

    while(front < back)
    {
        char* cur = queue[front];
        int step = steps[front];
        front++;

        int zeroPos = -1;
        for(int i = 0; i < 6; i++)
        {
            if(cur[i] == '0') {zeroPos = i; break;}
        }
        for(int k = 0; k < neighborCount[zeroPos]; k++)
        {
            int swapPos = neighbors[zeroPos][k];

            char next[7];
            strcpy(next, cur);

            char tmp = next[zeroPos];
            next[zeroPos] = next[swapPos];
            next[swapPos] = tmp;

            if(strcmp(next, target) == 0) return step + 1;

            int seen = 0;
            for(int v = 0; v < visitedCount; v++)
                if(strcmp(visited[v], next) == 0) {seen = 1; break;}
            if (!seen) {
                strcpy(visited[visitedCount++], next);
                strcpy(queue[back], next);
                steps[back] = step + 1;
                back++;
            }
        }
    }
    return -1;
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {1,2,3};
  static int mr0_0_1[] = {4,0,5};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1};
  static int mc0_0[] = {3,3};
  long long act_0 = (long long)slidingPuzzle(mp0_0, 2,mc0_0);
  if (!(act_0 == 1LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,2,3};
  static int mr1_0_1[] = {5,4,0};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1};
  static int mc1_0[] = {3,3};
  long long act_1 = (long long)slidingPuzzle(mp1_0, 2,mc1_0);
  if (!(act_1 == -1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {4,1,2};
  static int mr2_0_1[] = {5,0,3};
  static int *mp2_0[] = {mr2_0_0,mr2_0_1};
  static int mc2_0[] = {3,3};
  long long act_2 = (long long)slidingPuzzle(mp2_0, 2,mc2_0);
  if (!(act_2 == 5LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 773, "slidingPuzzle", ntests);
 return (pass&&ntests)?0:1;
}
