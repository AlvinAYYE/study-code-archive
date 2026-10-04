/*
 * ==========================================================================
 * LeetCode 1742. Maximum Number of Balls in a Box
 * Difficulty: Easy
 * Tags: hash-table, math, counting
 * URL: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
 * Source: community solution, repo DimitrisJim_leetcode_solutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are working in a ball factory where you have n balls numbered
 *     from lowLimit up to highLimit inclusive (i.e., n == highLimit -
 *     lowLimit + 1), and an infinite number of boxes numbered from 1 to
 *     infinity.
 *     Your job at this factory is to put each ball in the box with a
 *     number equal to the sum of digits of the ball's number. For example,
 *     the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and
 *     the ball number 10 will be put in the box number 1 + 0 = 1.
 *     Given two integers lowLimit and highLimit, return the number of
 *     balls in the box with the most balls.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     You are working in a ball factory where you have n balls numbered
 *     from lowLimit up to highLimit inclusive (i.e., n == highLimit -
 *     lowLimit + 1), and an infinite number of boxes numbered from 1 to
 *     infinity.
 *
 * Examples:
 *     Input: lowLimit = 1, highLimit = 10
 *     Output: 2
 *     Explanation:
 *     Box Number: 1 2 3 4 5 6 7 8 9 10 11 ...
 *     Ball Count: 2 1 1 1 1 1 1 1 1 0 0 ...
 *     Box 1 has the most number of balls with 2 balls.
 *     Input: lowLimit = 5, highLimit = 15
 *     Output: 2
 *     Explanation:
 *     Box Number: 1 2 3 4 5 6 7 8 9 10 11 ...
 *     Ball Count: 1 1 1 1 2 2 1 1 1 0 0 ...
 *     Boxes 5 and 6 have the most number of balls with 2 balls in
 *     each.
 *     Input: lowLimit = 19, highLimit = 28
 *     Output: 2
 *     Explanation:
 *     Box Number: 1 2 3 4 5 6 7 8 9 10 11 12 ...
 *     Ball Count: 0 1 1 1 1 1 1 1 1 2 0 0 ...
 *     Box 10 has the most number of balls with 2 balls.
 *
 * Constraints:
 *   - 1 <= lowLimit <= highLimit <= 10^5
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

// Note brackets: need a new local namespace for base.
#define ADD_FROM_BASE(arr, n, start, end)                                      \
  {                                                                            \
    int base = count_digits(n);                                                \
    for (int i = start; i < end; i++)                                          \
      (*(arr + base + i))++;                                                   \
  }

// Count digits in int n.
inline int count_digits(int n) {
  int sum = 0;
  while (n) {
    sum += n % 10;
    n /= 10;
  }
  return sum - 1;
}

// Return zero initialized array for storing counts.
// Caller responsible for free-ing array.
int *init_counter(int n, int *counter_size) {
  int slots = 18;
  if (n > 10000)
    slots = 45;
  else if (n > 1000)
    slots = 36;
  else
    slots = 27;
  // Set size for caller.
  *counter_size = slots;
  return calloc(slots, sizeof(int));
}

int countBalls(int lowLimit, int highLimit) {
  int aLen = 0;
  int *a = init_counter(highLimit, &aLen);

  int start = lowLimit / 10, start_left = lowLimit % 10,
      end = (highLimit + 1) / 10, end_left = (highLimit + 1) % 10;

  // start == end -> we're on the same multiple of ten. add
  // range [start_left, end_left) and be done.
  if (start == end)
    ADD_FROM_BASE(a, start, start_left, end_left)
  // Not on same multiple. Add [start_left, 10) and [0, end_left)
  // and then go through [lowLimit, highLimit] in multiples of ten.
  else {
    ADD_FROM_BASE(a, start, start_left, 10);
    ADD_FROM_BASE(a, end, 0, end_left);

    start = (start + 1) * 10;
    end = (end - 1) * 10;
    for (int i = start; i <= end; i += 10) {
      ADD_FROM_BASE(a, i, 0, 10);
    }
  }
  // Find max and return it.
  int max = a[0];
  for (int i = 1; i < aLen; i++) {
    if (a[i] > max)
      max = a[i];
  }
  free(a);
  return max;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  long long act_0 = (long long)countBalls((1),(10));
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  long long act_1 = (long long)countBalls((5),(15));
  if (!(act_1 == 2LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  long long act_2 = (long long)countBalls((19),(28));
  if (!(act_2 == 2LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1742, "countBalls", ntests);
 return (pass&&ntests)?0:1;
}
