/*
 * ==========================================================================
 * LeetCode 2303. Calculate Amount Paid in Taxes
 * Difficulty: Easy
 * Tags: array, simulation
 * URL: https://leetcode.com/problems/calculate-amount-paid-in-taxes/
 * Source: community solution, repo self_sol (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a 0-indexed 2D integer array brackets where
 *     brackets[i] = [upperi, percenti] means that the ith tax bracket has
 *     an upper bound of upperi and is taxed at a rate of percenti. The
 *     brackets are sorted by upper bound (i.e. upperi-1 < upperi for 0 < i
 *     < brackets.length).
 *     Tax is calculated as follows:
 *     You are given an integer income representing the amount of money you
 *     earned. Return the amount of money that you have to pay in taxes.
 *     Answers within 10-5 of the actual answer will be accepted.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個從 0 開始索引的二維整數陣列 brackets where brackets[i] = [upperi, percenti]
 *     means that the ith tax bracket has an upper bound of upperi and is
 *     taxed at a rate of percenti. The brackets are 已排序 by upper bound
 *     (i.e.
 *
 * Examples:
 *     Input: brackets = [[3,50],[7,10],[12,25]], income = 10
 *     Output: 2.65000
 *     Explanation:
 *     Based on your income, you have 3 dollars in the 1st tax
 *     bracket, 4 dollars in the 2nd tax bracket, and 3 dollars in
 *     the 3rd tax bracket.
 *     The tax rate for the three tax brackets is 50%, 10%, and 25%,
 *     respectively.
 *     In total, you pay $3 * 50% + $4 * 10% + $3 * 25% = $2.65 in
 *     taxes.
 *     Input: brackets = [[1,0],[4,25],[5,50]], income = 2
 *     Output: 0.25000
 *     Explanation:
 *     Based on your income, you have 1 dollar in the 1st tax bracket
 *     and 1 dollar in the 2nd tax bracket.
 *     The tax rate for the two tax brackets is 0% and 25%,
 *     respectively.
 *     In total, you pay $1 * 0% + $1 * 25% = $0.25 in taxes.
 *     Input: brackets = [[2,50]], income = 0
 *     Output: 0.00000
 *     Explanation:
 *     You have no income to tax, so you have to pay a total of $0 in
 *     taxes.
 *
 * Constraints:
 *   - 1 <= brackets.length <= 100
 *   - 1 <= upperi <= 1000
 *   - 0 <= percenti <= 100
 *   - 0 <= income <= 1000
 *   - upperi is sorted in ascending order.
 *   - All the values of upperi are unique.
 *   - The upper bound of the last tax bracket is greater than or
 *   equal to income.
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
double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income) {
    double tax = 0.0;
    int i, prev = 0;
    (void)bracketsColSize;
    for (i = 0; i < bracketsSize; ++i) {
        int top = brackets[i][0];
        double pct = (double)brackets[i][1];
        int span;
        if (income <= prev) break;
        span = (income < top ? income : top) - prev;
        tax += (double)span * pct / 100.0;
        prev = top;
    }
    return tax;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {3,50};
  static int mr0_0_1[] = {7,10};
  static int mr0_0_2[] = {12,25};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2};
  static int mc0_0[] = {2,2,2};
  double act_0 = calculateTax(mp0_0, 3,mc0_0,(10));
  if (!(fabs(act_0 - 2.65) < 1e-4 + 1e-6*fabs(2.65))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,0};
  static int mr1_0_1[] = {4,25};
  static int mr1_0_2[] = {5,50};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2};
  static int mc1_0[] = {2,2,2};
  double act_1 = calculateTax(mp1_0, 3,mc1_0,(2));
  if (!(fabs(act_1 - 0.25) < 1e-4 + 1e-6*fabs(0.25))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {2,50};
  static int *mp2_0[] = {mr2_0_0};
  static int mc2_0[] = {2};
  double act_2 = calculateTax(mp2_0, 1,mc2_0,(0));
  if (!(fabs(act_2 - 0.0) < 1e-4 + 1e-6*fabs(0.0))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 2303, "calculateTax", ntests);
 return (pass&&ntests)?0:1;
}
