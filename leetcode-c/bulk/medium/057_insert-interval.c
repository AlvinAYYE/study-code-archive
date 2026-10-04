/*
 * ==========================================================================
 * LeetCode 0057. Insert Interval
 * Difficulty: Medium
 * Tags: array
 * URL: https://leetcode.com/problems/insert-interval/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an array of non-overlapping intervals intervals where
 *     intervals[i] = [starti, endi] represent the start and the end of the
 *     ith interval and intervals is sorted in ascending order by starti.
 *     You are also given an interval newInterval = [start, end] that
 *     represents the start and end of another interval.
 *     Insert newInterval into intervals such that intervals is still
 *     sorted in ascending order by starti and intervals still does not
 *     have any overlapping intervals (merge overlapping intervals if
 *     necessary).
 *     Return intervals after the insertion.
 *     Note that you don't need to modify intervals in-place. You can make
 *     a new array and return it.
 *
 * [中文] 題目: 插入區間
 * [中文] 題目說明:
 *     給定已依起點排序且互不重疊的區間陣列 intervals，以及一個 
 *     newInterval，插入後仍須保持排序與不重疊。若 newInt
 *     erval 與既有區間重疊，必須合併後回傳結果；不要求原地修改。
 *
 * [中文] 思路:
 *     先複製完全位於新區間左側的區間，再找出所有重疊區間並更新新區間的兩端
 *     。加入合併後的新區間，最後接上右側其餘區間。
 *
 * Examples:
 *     Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 *     Output: [[1,5],[6,9]]
 *     Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]],
 *     newInterval = [4,8]
 *     Output: [[1,2],[3,10],[12,16]]
 *     Explanation: Because the new interval [4,8] overlaps with
 *     [3,5],[6,7],[8,10].
 *
 * Constraints:
 *   - 0 <= intervals.length <= 10^4
 *   - intervals[i].length == 2
 *   - 0 <= starti <= endi <= 10^5
 *   - intervals is sorted by starti in ascending order.
 *   - newInterval.length == 2
 *   - 0 <= start <= end <= 10^5
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
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) 
{
    int **ret = malloc(sizeof(int *)*(intervalsSize + 1));
    *returnColumnSizes = malloc(sizeof(int)*(intervalsSize + 1));
    int ret_ctr = 0, idx = 0;

    // Handle the non-opverlap partition
    while (idx < intervalsSize && newInterval[0] > intervals[idx][1]) {
        ret[ret_ctr] = intervals[idx]; // use original ptr to ignore mem alloc
        (*returnColumnSizes)[ret_ctr] = 2;
        ret_ctr++;
        idx++;
    }

    // Use tmp to detect the overlapping, it will occur if tmp != idx
    int tmp = idx;
    while (idx < intervalsSize &&  newInterval[1] >= intervals[idx][0])
        idx++;

    if (tmp != idx) {
        // update opverlapping interval
        newInterval[0] = MIN(intervals[tmp][0], newInterval[0]);
        newInterval[1] = MAX(intervals[idx-1][1], newInterval[1]);
    }
    ret[ret_ctr] = (int *)calloc(2, sizeof(int));
    ret[ret_ctr][0] = newInterval[0];
    ret[ret_ctr][1] = newInterval[1];
    (*returnColumnSizes)[ret_ctr] = 2;
    ret_ctr++;

    // Handle the rest of non-opverlap partition
    while (idx < intervalsSize) {
        ret[ret_ctr] = intervals[idx];
        (*returnColumnSizes)[ret_ctr] = 2;
        ret_ctr++;
        idx++;
    }

    *returnSize = ret_ctr;
    return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  int *rcs_0 = 0;
  static int mr0_0_0[] = {1,3};
  static int mr0_0_1[] = {6,9};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1};
  static int mc0_0[] = {2,2};
  static int arr0_3[] = {2,5};
  int **act_0 = insert(mp0_0, 2,mc0_0,arr0_3, 2,&rsz_0,&rcs_0);
  static char ibuf_0[400000]; lc_canon_ii(act_0, rcs_0, rsz_0, ibuf_0, sizeof ibuf_0);
  if (!(strcmp(ibuf_0, "[[1,5],[6,9]]") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  int *rcs_1 = 0;
  static int mr1_0_0[] = {1,2};
  static int mr1_0_1[] = {3,5};
  static int mr1_0_2[] = {6,7};
  static int mr1_0_3[] = {8,10};
  static int mr1_0_4[] = {12,16};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3,mr1_0_4};
  static int mc1_0[] = {2,2,2,2,2};
  static int arr1_3[] = {4,8};
  int **act_1 = insert(mp1_0, 5,mc1_0,arr1_3, 2,&rsz_1,&rcs_1);
  static char ibuf_1[400000]; lc_canon_ii(act_1, rcs_1, rsz_1, ibuf_1, sizeof ibuf_1);
  if (!(strcmp(ibuf_1, "[[1,2],[12,16],[3,10]]") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 57, "insert", ntests);
 return (pass&&ntests)?0:1;
}
