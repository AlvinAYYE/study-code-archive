/*
 * ==========================================================================
 * LeetCode 0807. Max Increase to Keep City Skyline
 * Difficulty: Medium
 * Tags: array, greedy, matrix
 * URL: https://leetcode.com/problems/max-increase-to-keep-city-skyline/
 * Source: community solution, repo DimitrisJim_leetcode_solutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     There is a city composed of n x n blocks, where each block contains
 *     a single building shaped like a vertical square prism. You are given
 *     a 0-indexed n x n integer matrix grid where grid[r][c] represents
 *     the height of the building located in the block at row r and column
 *     c.
 *     A city's skyline is the outer contour formed by all the building
 *     when viewing the side of the city from a distance. The skyline from
 *     each cardinal direction north, east, south, and west may be
 *     different.
 *     We are allowed to increase the height of any number of buildings by
 *     any amount (the amount can be different per building). The height of
 *     a 0-height building can also be increased. However, increasing the
 *     height of a building should not affect the city's skyline from any
 *     cardinal direction.
 *     Return the maximum total sum that the height of the buildings can be
 *     increased by without changing the city's skyline from any cardinal
 *     direction.
 *
 * [中文] 題目: 保持城市天際線的最大增高
 * [中文] 題目說明:
 *     給定 n × n 建築高度矩陣，可任意提高任意棟建築（含原高為 0 
 *     者），但四個方向看到的城市天際線不得改變。求所有建築可增加高度總和的
 *     最大值；n 介於 2 與 50。
 *
 * [中文] 思路:
 *     對每列求列最大值、對每欄求欄最大值；每格至多可提高到兩者較小值，將此
 *     值與原高度的差累加。
 *
 * Examples:
 *     Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
 *     Output: 35
 *     Explanation: The building heights are shown in the center of
 *     the above image.
 *     The skylines when viewed from each cardinal direction are
 *     drawn in red.
 *     The grid after increasing the height of buildings without
 *     affecting skylines is:
 *     gridNew = [ [8, 4, 8, 7],
 *     [7, 4, 7, 7],
 *     [9, 4, 8, 7],
 *     [3, 3, 3, 3] ]
 *     Input: grid = [[0,0,0],[0,0,0],[0,0,0]]
 *     Output: 0
 *     Explanation: Increasing the height of any building will result
 *     in the skyline changing.
 *
 * Constraints:
 *   - n == grid.length
 *   - n == grid[r].length
 *   - 2 <= n <= 50
 *   - 0 <= grid[r][c] <= 100
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
#include <stdlib.h>

int maxIncreaseKeepingSkyline(int **grid, int gridSize, int *gridColSize) {
  int rows = gridSize, cols = *gridColSize, mxcolsLen = 0;
  int *max_cols = malloc(cols * sizeof(*max_cols));

  int max_increase = 0;
  for (int i = 0; i < rows; i++) {
    int *row = grid[i];
    // find max row for this row to use.
    int max_row = -1;
    for (int j = 0; j < cols; j++) {
      int v = row[j];
      if (v > max_row)
        max_row = v;
    }
    for (int j = 0; j < cols; j++) {
      if (mxcolsLen == 0) {
        // find max column value.
        int max_col = -1;
        for (int i = 0; i < rows; i++) {
          int v = grid[i][j];
          if (v > max_col)
            max_col = v;
        }
        max_cols[j] = max_col;
      }
      int value = grid[i][j];
      // diff is the difference between min of maxes minus value.
      int diff = max_row < max_cols[j] ? max_row - value : max_cols[j] - value;
      if (diff > 0) {
        max_increase += diff;
      }
    }
  }
  free(max_cols);
  return max_increase;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {3,0,8,4};
  static int mr0_0_1[] = {2,4,5,7};
  static int mr0_0_2[] = {9,2,6,3};
  static int mr0_0_3[] = {0,3,1,0};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3};
  static int mc0_0[] = {4,4,4,4};
  long long act_0 = (long long)maxIncreaseKeepingSkyline(mp0_0, 4,mc0_0);
  if (!(act_0 == 35LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {0,0,0};
  static int mr1_0_1[] = {0,0,0};
  static int mr1_0_2[] = {0,0,0};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2};
  static int mc1_0[] = {3,3,3};
  long long act_1 = (long long)maxIncreaseKeepingSkyline(mp1_0, 3,mc1_0);
  if (!(act_1 == 0LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 807, "maxIncreaseKeepingSkyline", ntests);
 return (pass&&ntests)?0:1;
}
