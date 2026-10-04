/*
 * ==========================================================================
 * LeetCode 1560. Most Visited Sector in  a Circular Track
 * Difficulty: Easy
 * Tags: array, simulation
 * URL: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
 * Source: community solution, repo DimitrisJim_leetcode_solutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an integer n and an integer array rounds. We have a circular
 *     track which consists of n sectors labeled from 1 to n. A marathon
 *     will be held on this track, the marathon consists of m rounds. The
 *     ith round starts at sector rounds[i - 1] and ends at sector
 *     rounds[i]. For example, round 1 starts at sector rounds[0] and ends
 *     at sector rounds[1]
 *     Return an array of the most visited sectors sorted in ascending
 *     order.
 *     Notice that you circulate the track in ascending order of sector
 *     numbers in the counter-clockwise direction (See the first example).
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     Given an 整數 n and an 整數 陣列 rounds. We have a circular track which
 *     consists of n sectors labeled from 1 to n.
 *
 * Examples:
 *     Input: n = 4, rounds = [1,3,1,2]
 *     Output: [1,2]
 *     Explanation: The marathon starts at sector 1. The order of the
 *     visited sectors is as follows:
 *     1 --> 2 --> 3 (end of round 1) --> 4 --> 1 (end of round 2)
 *     --> 2 (end of round 3 and the marathon)
 *     We can see that both sectors 1 and 2 are visited twice and
 *     they are the most visited sectors. Sectors 3 and 4 are visited
 *     only once.
 *     Input: n = 2, rounds = [2,1,2,1,2,1,2,1,2]
 *     Output: [2]
 *     Input: n = 7, rounds = [1,3,5,7]
 *     Output: [1,2,3,4,5,6,7]
 *
 * Constraints:
 *   - 2 <= n <= 100
 *   - 1 <= m <= 100
 *   - rounds.length == m + 1
 *   - 1 <= rounds[i] <= n
 *   - rounds[i] != rounds[i + 1] for 0 <= i < m
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

#define ADD_FROM_RANGE(rng, arr)                                               \
  int s = rng[0], e = rng[1];                                                  \
  for (int i = s; i <= e; i++)                                                 \
    tmp[i - 1]++;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *mostVisited(int n, int *rounds, int roundsSize, int *returnSize) {
  int i = 0, begin[2] = {0, 0};
  // If i == 1, we start from the beginning and can just skip this,
  // if not, we need to see where we started from since those sectors
  // will have been visited +1 times.
  if (rounds[i] != 1) {
    int start = rounds[i];
    while (i < (roundsSize - 1) && rounds[i] < rounds[i + 1])
      i++;

    // return early, reached end.
    if (i == roundsSize - 1) {
      *returnSize = (rounds[i] - start) + 1;
      int *result = malloc(*returnSize * sizeof(*result));
      for (int j = start; j <= rounds[i]; j++)
        result[j - start] = j;
      return result;
    }
    begin[0] = start;
    begin[1] = n;
  }
  // Grab trailing (last marathon).
  int trail[2] = {1, rounds[roundsSize - 1]}, *tmp = calloc(n, sizeof(*tmp));

  if (begin[0] != 0) {
    ADD_FROM_RANGE(begin, tmp);
  }
  ADD_FROM_RANGE(trail, tmp);
  // Find max + how many elements == max.
  int max = 0, retSize = 0, retlen = 0;
  for (int i = 0; i < n; i++) {
    int v = tmp[i];
    if (v >= max)
      max = v;
  }
  for (int i = 0; i < n; i++) {
    if (*(tmp + i) == max)
      retSize++;
  }
  // Create return array and fill.
  *returnSize = retSize;
  int *ret = malloc(retSize * sizeof(*ret));
  for (int i = 0; i < n; i++) {
    if (tmp[i] == max)
      ret[retlen++] = i + 1;
  }
  free(tmp);
  return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int arr0_1[] = {1,3,1,2};
  int *act_0 = mostVisited((4),arr0_1, 4,&rsz_0);
  static const int exp_0[] = {1,2};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int arr1_1[] = {2,1,2,1,2,1,2,1,2};
  int *act_1 = mostVisited((2),arr1_1, 9,&rsz_1);
  static const int exp_1[] = {2};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 1))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  static int arr2_1[] = {1,3,5,7};
  int *act_2 = mostVisited((7),arr2_1, 4,&rsz_2);
  static const int exp_2[] = {1,2,3,4,5,6,7};
  if (!(lc_eq_list_sorted(act_2, rsz_2, exp_2, 7))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1560, "mostVisited", ntests);
 return (pass&&ntests)?0:1;
}
