/*
 * LeetCode 0289. Game of Life（生命遊戲）
 * Difficulty: Medium
 * 題意：給定只含 0（死細胞）和 1（活細胞）的棋盤，依生命遊戲規則同時更新所有格子：活細胞鄰居少於 2 個會死亡；有 2 或 3 個鄰居則存活；多於 3 個會死亡；死細胞恰有 3 個活鄰居時會復活。鄰居是水平、垂直或斜角相接的最多 8 格。請原地更新棋盤。
 * 範例：
 *   1. 輸入：board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]；輸出：[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]。
 *   2. 輸入：board = [[1,1],[1,0]]；輸出：[[1,1],[1,1]]。
 * 限制：
 *   - 1 <= m, n <= 25
 *   - board[i][j] 只能是 0 或 1
 * 解法：
 *   1. 逐格統計周圍 8 個位置的活細胞數，邊界外的位置忽略。
 *   2. 更新必須同時生效，所以先把新狀態存在第二個位元，低位仍保留原狀態供後續格子讀取。
 *   3. 新狀態為活細胞時，把該格的第二個位元設為 1。
 *   4. 所有格子都計算完後，將每格右移一位，讓新狀態成為正式值。
 * 複雜度：時間 O(mn)，額外空間 O(1)。
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
void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int rows = boardSize;
    int columns = boardColSize[0];
    const int rowOffset[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int columnOffset[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            int liveNeighbors = 0;
            for (int direction = 0; direction < 8; direction++) {
                int neighborRow = row + rowOffset[direction];
                int neighborColumn = column + columnOffset[direction];
                if (neighborRow >= 0 && neighborRow < rows &&
                    neighborColumn >= 0 && neighborColumn < columns) {
                    liveNeighbors += board[neighborRow][neighborColumn] & 1;
                }
            }

            int alive = board[row][column] & 1;
            int nextAlive = alive
                ? (liveNeighbors == 2 || liveNeighbors == 3)
                : (liveNeighbors == 3);
            board[row][column] |= nextAlive << 1;
        }
    }

    // 原狀態已不再需要，將第二個位元移到最低位。
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            board[row][column] >>= 1;
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
