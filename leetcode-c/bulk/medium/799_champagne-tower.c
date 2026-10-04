/*
 * ==========================================================================
 * LeetCode 0799. Champagne Tower
 * Difficulty: Medium
 * Tags: dynamic-programming
 * URL: https://leetcode.com/problems/champagne-tower/
 * Source: community solution, repo ourhouchmohamed97_LeetCode_in_C (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     We stack glasses in a pyramid, where the first row has 1 glass, the
 *     second row has 2 glasses, and so on until the 100th row. Each glass
 *     holds one cup of champagne.
 *     Then, some champagne is poured into the first glass at the top. When
 *     the topmost glass is full, any excess liquid poured will fall
 *     equally to the glass immediately to the left and right of it. When
 *     those glasses become full, any excess champagne will fall equally to
 *     the left and right of those glasses, and so on. (A glass at the
 *     bottom row has its excess champagne fall on the floor.)
 *     For example, after one cup of champagne is poured, the top most
 *     glass is full. After two cups of champagne are poured, the two
 *     glasses on the second row are half full. After three cups of
 *     champagne are poured, those two cups become full - there are 3 full
 *     glasses total now. After four cups of champagne are poured, the
 *     third row has the middle glass half full, and the two outside
 *     glasses are a quarter full, as pictured below.
 *     Now after pouring some non-negative integer cups of champagne,
 *     return how full the jth glass in the ith row is (both i and j are
 *     0-indexed.)
 *
 * [中文] 題目: 香檳塔
 * [中文] 題目說明:
 *     香檳杯依金字塔排列，每杯容量為 1 杯；滿出的液體會平均流到下一列左
 *     右兩杯。倒入 poured 杯香檳後，回傳第 query_row 列
 *     第 query_glass 杯的滿度，列與杯索引皆從 0 起算且列數
 *     小於 100。
 *
 * [中文] 思路:
 *     以二維陣列模擬每杯收到的總量，將超過 1 的部分各分一半流向下一列兩
 *     杯，最後把查詢杯的量截為最多 1。
 *
 * Examples:
 *     Input: poured = 1, query_row = 1, query_glass = 1
 *     Output: 0.00000
 *     Explanation: We poured 1 cup of champange to the top glass of
 *     the tower (which is indexed as (0, 0)). There will be no
 *     excess liquid so all the glasses under the top glass will
 *     remain empty.
 *     Input: poured = 2, query_row = 1, query_glass = 1
 *     Output: 0.50000
 *     Explanation: We poured 2 cups of champange to the top glass of
 *     the tower (which is indexed as (0, 0)). There is one cup of
 *     excess liquid. The glass indexed as (1, 0) and the glass
 *     indexed as (1, 1) will share the excess liquid equally, and
 *     each will get half cup of champange.
 *     Input: poured = 100000009, query_row = 33, query_glass = 17
 *     Output: 1.00000
 *
 * Constraints:
 *   - 0 <= poured <= 10^9
 *   - 0 <= query_glass <= query_row < 100
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
// Champagne Tower

#include <math.h>
#include <string.h>

double champagneTower(int poured, int query_row, int query_glass) {
    double flow[102][102] = {0.0};

    flow[0][0] = (double)poured;

    for (int r = 0; r <= query_row; ++r) {
        for (int c = 0; c <= r; ++c) {
            double q = (flow[r][c] - 1.0) / 2.0;

            if (q > 0) {
                flow[r + 1][c] += q;
                flow[r + 1][c + 1] += q;
            }
        }
    }

    return fmin(1.0, flow[query_row][query_glass]);
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  double act_0 = champagneTower((1),(1),(1));
  if (!(fabs(act_0 - 0.0) < 1e-4 + 1e-6*fabs(0.0))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  double act_1 = champagneTower((2),(1),(1));
  if (!(fabs(act_1 - 0.5) < 1e-4 + 1e-6*fabs(0.5))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  double act_2 = champagneTower((100000009),(33),(17));
  if (!(fabs(act_2 - 1.0) < 1e-4 + 1e-6*fabs(1.0))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 799, "champagneTower", ntests);
 return (pass&&ntests)?0:1;
}
