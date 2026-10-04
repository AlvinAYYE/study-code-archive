/*
 * ==========================================================================
 * LeetCode 0452. Minimum Number of Arrows to Burst Balloons
 * Difficulty: Medium
 * Tags: array, greedy, sorting
 * URL: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     There are some spherical balloons taped onto a flat wall that
 *     represents the XY-plane. The balloons are represented as a 2D
 *     integer array points where points[i] = [xstart, xend] denotes a
 *     balloon whose horizontal diameter stretches between xstart and xend.
 *     You do not know the exact y-coordinates of the balloons.
 *     Arrows can be shot up directly vertically (in the positive
 *     y-direction) from different points along the x-axis. A balloon with
 *     xstart and xend is burst by an arrow shot at x if xstart <= x <=
 *     xend. There is no limit to the number of arrows that can be shot. A
 *     shot arrow keeps traveling up infinitely, bursting any balloons in
 *     its path.
 *     Given the array points, return the minimum number of arrows that
 *     must be shot to burst all balloons.
 *
 * [中文] 題目: 用最少數量的箭引爆氣球
 * [中文] 題目說明:
 *     牆面上的每個氣球以水平直徑區間 [xstart,xend] 表示，從
 *      x 軸某一位置垂直往上射出的箭可引爆所有涵蓋該 x 座標的氣球。箭
 *     可無限向上飛行且數量不限，請求引爆全部氣球所需的最少箭數。
 *
 * [中文] 思路:
 *     將氣球依右端點遞增排序，先在第一個右端點射箭。其後只有當下一氣球的左
 *     端點大於目前箭的位置時才需新增一箭，並將位置改為該氣球的右端點。
 *
 * Examples:
 *     Input: points = [[10,16],[2,8],[1,6],[7,12]]
 *     Output: 2
 *     Explanation: The balloons can be burst by 2 arrows:
 *     - Shoot an arrow at x = 6, bursting the balloons [2,8] and
 *     [1,6].
 *     - Shoot an arrow at x = 11, bursting the balloons [10,16] and
 *     [7,12].
 *     Input: points = [[1,2],[3,4],[5,6],[7,8]]
 *     Output: 4
 *     Explanation: One arrow needs to be shot for each balloon for a
 *     total of 4 arrows.
 *     Input: points = [[1,2],[2,3],[3,4],[4,5]]
 *     Output: 2
 *     Explanation: The balloons can be burst by 2 arrows:
 *     - Shoot an arrow at x = 2, bursting the balloons [1,2] and
 *     [2,3].
 *     - Shoot an arrow at x = 4, bursting the balloons [3,4] and
 *     [4,5].
 *
 * Constraints:
 *   - 1 <= points.length <= 10^5
 *   - points[i].length == 2
 *   - -231 <= xstart < xend <= 231 - 1
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

static int compare(const void *a, const void *b)
{
    int _a = ((*(int**)a)[1]);
    int _b = ((*(int**)b)[1]);

    return (_a < _b)? -1: (_a > _b);   
}


int findMinArrowShots(int** points, int pointsSize, int* pointsColSize)
{
    qsort(points, pointsSize, sizeof(int *), compare);
    int ret = 1, prev_tail = points[0][1];
    for (int i = 1; i < pointsSize; i++) {
        if (points[i][0] > prev_tail) {
            prev_tail = points[i][1];
            ret++;
        }
    }

    return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {10,16};
  static int mr0_0_1[] = {2,8};
  static int mr0_0_2[] = {1,6};
  static int mr0_0_3[] = {7,12};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3};
  static int mc0_0[] = {2,2,2,2};
  long long act_0 = (long long)findMinArrowShots(mp0_0, 4,mc0_0);
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,2};
  static int mr1_0_1[] = {3,4};
  static int mr1_0_2[] = {5,6};
  static int mr1_0_3[] = {7,8};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3};
  static int mc1_0[] = {2,2,2,2};
  long long act_1 = (long long)findMinArrowShots(mp1_0, 4,mc1_0);
  if (!(act_1 == 4LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {1,2};
  static int mr2_0_1[] = {2,3};
  static int mr2_0_2[] = {3,4};
  static int mr2_0_3[] = {4,5};
  static int *mp2_0[] = {mr2_0_0,mr2_0_1,mr2_0_2,mr2_0_3};
  static int mc2_0[] = {2,2,2,2};
  long long act_2 = (long long)findMinArrowShots(mp2_0, 4,mc2_0);
  if (!(act_2 == 2LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 452, "findMinArrowShots", ntests);
 return (pass&&ntests)?0:1;
}
