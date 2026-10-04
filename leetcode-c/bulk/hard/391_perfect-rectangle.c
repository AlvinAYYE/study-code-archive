/*
 * ==========================================================================
 * LeetCode 0391. Perfect Rectangle
 * Difficulty: Hard
 * Tags: array, hash-table, math, geometry, line-sweep
 * URL: https://leetcode.com/problems/perfect-rectangle/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an array rectangles where rectangles[i] = [xi, yi, ai, bi]
 *     represents an axis-aligned rectangle. The bottom-left point of the
 *     rectangle is (xi, yi) and the top-right point of it is (ai, bi).
 *     Return true if all the rectangles together form an exact cover of a
 *     rectangular region.
 *
 * [中文] 題目: 完美矩形
 * [中文] 題目說明:
 *     給定多個軸對齊矩形，每個 rectangles[i] = [xi, 
 *     yi, ai, bi] 的左下角為 (xi, yi)、右上角為 (a
 *     i, bi)。判斷所有矩形合起來是否恰好完整覆蓋一個矩形區域，不能有
 *     缺口或重疊。
 *
 * [中文] 思路:
 *     累加各矩形面積並維護外框，同時以集合切換每個角點的存在狀態；最後面積
 *     須等於外框面積，且集合只剩外框四個角。
 *
 * Examples:
 *     Input: rectangles =
 *     [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 *     Output: true
 *     Explanation: All 5 rectangles together form an exact cover of
 *     a rectangular region.
 *     Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 *     Output: false
 *     Explanation: Because there is a gap between the two
 *     rectangular regions.
 *     Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 *     Output: false
 *     Explanation: Because two of the rectangles overlap with each
 *     other.
 *
 * Constraints:
 *   - 1 <= rectangles.length <= 2 * 10^4
 *   - rectangles[i].length == 4
 *   - -10^5 <= xi < ai <= 10^5
 *   - -10^5 <= yi < bi <= 10^5
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
/*
391. Perfect Rectangle

Given N axis-aligned rectangles where N > 0, determine if they all together form an exact cover of a rectangular region.



Each rectangle is represented as a bottom-left point and a top-right point. For example, a unit square is represented as [1,1,2,2]. (coordinate of bottom-left point is (1, 1) and top-right point is (2, 2)).



Example 1:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [3,2,4,4],
  [1,3,2,4],
  [2,3,3,4]
]

Return true. All 5 rectangles together form an exact cover of a rectangular region.






Example 2:
rectangles = [
  [1,1,2,3],
  [1,3,2,4],
  [3,1,4,2],
  [3,2,4,4]
]

Return false. Because there is a gap between the two rectangular regions.






Example 3:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [3,2,4,4]
]

Return false. Because there is a gap in the top center.






Example 4:
rectangles = [
  [1,1,3,3],
  [3,1,4,2],
  [1,3,2,4],
  [2,2,4,4]
]

Return false. Because two of the rectangles overlap with each other.
*/

typedef struct dot_s {
    int x;
    int y;
    struct dot_s *shadow;
} dot_t;
#define HSZ 1000
typedef struct set_s {
    dot_t **d;
    int n;
} set_t;
int lookup_remove(set_t *set, int x, int y) {
    dot_t **p, *d;
    
    p = &set->d[x % HSZ];
    while ((*p) && ((*p)->x != x || (*p)->y != y)) {
        p = &((*p)->shadow);
    }
    
    if (*p) {
        d = *p;
        *p = d->shadow;
        free(d);
        set->n --;
        return 1;
    }
    
    return 0;
}
void add2set(set_t *set, int x, int y) {
    dot_t *d = malloc(sizeof(dot_t));
    //assert(d);
    d->x = x;
    d->y = y;
    d->shadow = set->d[x % HSZ];
    set->d[x % HSZ] = d;
    set->n ++;
}
bool map_area(int **rectangles, int rowsz) {
    int a, i;
    int x1, y1, x2, y2;
    int x_min, y_min, x_max, y_max;
    dot_t *buff[HSZ * 2] = { 0 };
    set_t set = { 0 };
    set.d = &buff[HSZ];
    
    a = 0;
    for (i = 0; i < rowsz; i ++) {
        x1 = rectangles[i][0];
        y1 = rectangles[i][1];
        x2 = rectangles[i][2];
        y2 = rectangles[i][3];
        
        a += (x2 - x1) * (y2 - y1);   // total area
        
        if (i == 0 || x_min > x1) x_min = x1;   // find the outermost shape
        if (i == 0 || y_min > y1) y_min = y1;
        if (i == 0 || x_max < x2) x_max = x2;
        if (i == 0 || y_max < y2) y_max = y2;
        
        if (!lookup_remove(&set, x1, y1)) add2set(&set, x1, y1);
        if (!lookup_remove(&set, x1, y2)) add2set(&set, x1, y2);
        if (!lookup_remove(&set, x2, y1)) add2set(&set, x2, y1);
        if (!lookup_remove(&set, x2, y2)) add2set(&set, x2, y2);
    }
    
    return ((a == ((y_max - y_min) * (x_max - x_min))) &&
            (set.n == 4 &&
             lookup_remove(&set, x_min, y_min) &&
             lookup_remove(&set, x_min, y_max) &&
             lookup_remove(&set, x_max, y_min) &&
             lookup_remove(&set, x_max, y_max))) ? true : false;
}
bool isRectangleCover(int** rectangles, int rectanglesRowSize, int rectanglesColSize) {
    return map_area(rectangles, rectanglesRowSize);
}

/*
Difficulty:Hard
Total Accepted:10.3K
Total Submissions:39.2K


Companies Google

*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {1,1,3,3};
  static int mr0_0_1[] = {3,1,4,2};
  static int mr0_0_2[] = {3,2,4,4};
  static int mr0_0_3[] = {1,3,2,4};
  static int mr0_0_4[] = {2,3,3,4};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3,mr0_0_4};
  static int mc0_0[] = {4,4,4,4,4};
  bool act_0 = isRectangleCover(mp0_0, 5,mc0_0);
  if (!(act_0 == true)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,1,2,3};
  static int mr1_0_1[] = {1,3,2,4};
  static int mr1_0_2[] = {3,1,4,2};
  static int mr1_0_3[] = {3,2,4,4};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3};
  static int mc1_0[] = {4,4,4,4};
  bool act_1 = isRectangleCover(mp1_0, 4,mc1_0);
  if (!(act_1 == false)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {1,1,3,3};
  static int mr2_0_1[] = {3,1,4,2};
  static int mr2_0_2[] = {1,3,2,4};
  static int mr2_0_3[] = {2,2,4,4};
  static int *mp2_0[] = {mr2_0_0,mr2_0_1,mr2_0_2,mr2_0_3};
  static int mc2_0[] = {4,4,4,4};
  bool act_2 = isRectangleCover(mp2_0, 4,mc2_0);
  if (!(act_2 == false)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 391, "isRectangleCover", ntests);
 return (pass&&ntests)?0:1;
}
