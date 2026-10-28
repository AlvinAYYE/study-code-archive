/*
 * Title-CN: 找出井字棋的勝者
 * LeetCode 1275. Find Winner on a Tic Tac Toe Game (Easy)
 *
 * 題意翻譯：A、B 兩人輪流在 3 x 3 棋盤落子，A 先下。moves[i] = [row, col]
 * 表示第 i 步落在第 row 列、第 col 欄。三格橫向、直向或斜向相同者獲勝；若有人
 * 獲勝就回傳 "A" 或 "B"。若九格下完仍沒人獲勝，回傳 "Draw"；棋局尚未結束則
 * 回傳 "Pending"。題目保證落子順序合法且不會重複佔用格子。
 *
 * 範例 1：moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]，輸出 "A"；A 連成左上到
 *         右下的斜線。
 * 範例 2：moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]，輸出 "B"；B 連成
 *         第一欄。
 * 範例 3：moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]，
 *         輸出 "Draw"；棋盤已滿，沒有三格連線。
 *
 * 限制：1 <= moves.length <= 9；每步座標都介於 0 和 2；所有落子都合法。
 *
 * 解題思路：先把 moves 依序放進 3 x 3 棋盤，奇數步由 A 落子、偶數步由 B 落子。
 * 放完後，逐一檢查三列、三欄和兩條對角線。若找到三格相同且不是空格，回傳對應
 * 玩家；否則依落子數判斷棋盤是否已滿。最多只有九步，時間與空間都是 O(1)。
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

char *tictactoe(int **moves, int movesSize, int *movesColSize) {
    int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
    int move;
    int line;

    (void)movesColSize;
    for (move = 0; move < movesSize; ++move) {
        int player = move % 2 == 0 ? 1 : 0;
        int row = moves[move][0];
        int column = moves[move][1];
        board[row][column] = player;
    }

    for (line = 0; line < 3; ++line) {
        if (board[line][0] != -1 && board[line][0] == board[line][1] &&
            board[line][1] == board[line][2]) {
            return board[line][0] == 1 ? "A" : "B";
        }
        if (board[0][line] != -1 && board[0][line] == board[1][line] &&
            board[1][line] == board[2][line]) {
            return board[0][line] == 1 ? "A" : "B";
        }
    }

    if (board[1][1] != -1 && board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {
        return board[1][1] == 1 ? "A" : "B";
    }
    if (board[1][1] != -1 && board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {
        return board[1][1] == 1 ? "A" : "B";
    }

    return movesSize == 9 ? "Draw" : "Pending";
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {0,0};
  static int mr0_0_1[] = {2,0};
  static int mr0_0_2[] = {1,1};
  static int mr0_0_3[] = {2,1};
  static int mr0_0_4[] = {2,2};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3,mr0_0_4};
  static int mc0_0[] = {2,2,2,2,2};
  char *act_0 = tictactoe(mp0_0, 5,mc0_0);
  if (!(strcmp(act_0, "A") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {0,0};
  static int mr1_0_1[] = {1,1};
  static int mr1_0_2[] = {0,1};
  static int mr1_0_3[] = {0,2};
  static int mr1_0_4[] = {1,0};
  static int mr1_0_5[] = {2,0};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3,mr1_0_4,mr1_0_5};
  static int mc1_0[] = {2,2,2,2,2,2};
  char *act_1 = tictactoe(mp1_0, 6,mc1_0);
  if (!(strcmp(act_1, "B") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {0,0};
  static int mr2_0_1[] = {1,1};
  static int mr2_0_2[] = {2,0};
  static int mr2_0_3[] = {1,0};
  static int mr2_0_4[] = {1,2};
  static int mr2_0_5[] = {2,1};
  static int mr2_0_6[] = {0,1};
  static int mr2_0_7[] = {0,2};
  static int mr2_0_8[] = {2,2};
  static int *mp2_0[] = {mr2_0_0,mr2_0_1,mr2_0_2,mr2_0_3,mr2_0_4,mr2_0_5,mr2_0_6,mr2_0_7,mr2_0_8};
  static int mc2_0[] = {2,2,2,2,2,2,2,2,2};
  char *act_2 = tictactoe(mp2_0, 9,mc2_0);
  if (!(strcmp(act_2, "Draw") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
{
  static int anti0[] = {0,2}, anti1[] = {0,0}, anti2[] = {1,1};
  static int anti3[] = {0,1}, anti4[] = {2,0};
  static int *antiMoves[] = {anti0,anti1,anti2,anti3,anti4};
  static int antiColumns[] = {2,2,2,2,2};
  char *actual = tictactoe(antiMoves, 5, antiColumns);
  if (!(strcmp(actual, "A") == 0)) { pass = 0; printf("  anti-diagonal test FAIL\n"); }
  ntests++; }
{
  static int pending0[] = {0,0}, pending1[] = {1,1};
  static int *pendingMoves[] = {pending0,pending1};
  static int pendingColumns[] = {2,2};
  char *actual = tictactoe(pendingMoves, 2, pendingColumns);
  if (!(strcmp(actual, "Pending") == 0)) { pass = 0; printf("  pending test FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1275, "tictactoe", ntests);
 return (pass&&ntests)?0:1;
}
