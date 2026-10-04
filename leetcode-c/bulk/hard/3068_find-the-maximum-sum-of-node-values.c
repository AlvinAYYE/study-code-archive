/*
 * ==========================================================================
 * LeetCode 3068. Find the Maximum Sum of Node Values
 * Difficulty: Hard
 * Tags: array, dynamic-programming, greedy, bit-manipulation, tree, sorting
 * URL: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     There exists an undirected tree with n nodes numbered 0 to n - 1.
 *     You are given a 0-indexed 2D integer array edges of length n - 1,
 *     where edges[i] = [ui, vi] indicates that there is an edge between
 *     nodes ui and vi in the tree. You are also given a positive integer
 *     k, and a 0-indexed array of non-negative integers nums of length n,
 *     where nums[i] represents the value of the node numbered i.
 *     Alice wants the sum of values of tree nodes to be maximum, for which
 *     Alice can perform the following operation any number of times
 *     (including zero) on the tree:
 *     Return the maximum possible sum of the values Alice can achieve by
 *     performing the operation any number of times.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     There exists an undirected 樹 with n 節點 numbered 0 to n - 1. 給定一個從 0
 *     開始索引的二維整數陣列 edges of length n - 1, where edges[i] = [ui, vi]
 *     indicates that there is an edge between 節點 ui and vi in the 樹.
 *
 * Examples:
 *     Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
 *     Output: 6
 *     Explanation: Alice can achieve the maximum sum of 6 using a
 *     single operation:
 *     - Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 =
 *     2, and the array nums becomes: [1,2,1] -> [2,2,2].
 *     The total sum of values is 2 + 2 + 2 = 6.
 *     It can be shown that 6 is the maximum achievable sum of
 *     values.
 *     Input: nums = [2,3], k = 7, edges = [[0,1]]
 *     Output: 9
 *     Explanation: Alice can achieve the maximum sum of 9 using a
 *     single operation:
 *     - Choose the edge [0,1]. nums[0] becomes: 2 XOR 7 = 5 and
 *     nums[1] become: 3 XOR 7 = 4, and the array nums becomes: [2,3]
 *     -> [5,4].
 *     The total sum of values is 5 + 4 = 9.
 *     It can be shown that 9 is the maximum achievable sum of
 *     values.
 *     Input: nums = [7,7,7,7,7,7], k = 3, edges =
 *     [[0,1],[0,2],[0,3],[0,4],[0,5]]
 *     Output: 42
 *     Explanation: The maximum achievable sum is 42 which can be
 *     achieved by Alice performing no operations.
 *
 * Constraints:
 *   - 2 <= n == nums.length <= 2 * 10^4
 *   - 1 <= k <= 10^9
 *   - 0 <= nums[i] <= 10^9
 *   - edges.length == n - 1
 *   - edges[i].length == 2
 *   - 0 <= edges[i][0], edges[i][1] <= n - 1
 *   - The input is generated such that edges represent a valid tree.
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
long long maximumValueSum(int *nums, int nums_size, int k, int **edges, int edges_size, int *edges_col_size)
{
    long long max_sum = 0;
    int changed_count = 0, min_change_diff = INT_MAX;

    for (int i = 0; i < nums_size; ++i) {
        int num = nums[i];
        int xor_num = num ^ k;
        max_sum += (num > xor_num) ? num : xor_num;
        if (xor_num > num)
            changed_count++;

        int change_diff = abs(num - xor_num);
        if (change_diff < min_change_diff)
            min_change_diff = change_diff;
    }

    if (!(changed_count & 0x1))
        return max_sum;

    return max_sum - min_change_diff;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {1,2,1};
  static int mr0_3_0[] = {0,1};
  static int mr0_3_1[] = {0,2};
  static int *mp0_3[] = {mr0_3_0,mr0_3_1};
  static int mc0_3[] = {2,2};
  long long act_0 = (long long)maximumValueSum(arr0_0, 3,(3),mp0_3, 2,mc0_3);
  if (!(act_0 == 6LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {2,3};
  static int mr1_3_0[] = {0,1};
  static int *mp1_3[] = {mr1_3_0};
  static int mc1_3[] = {2};
  long long act_1 = (long long)maximumValueSum(arr1_0, 2,(7),mp1_3, 1,mc1_3);
  if (!(act_1 == 9LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {7,7,7,7,7,7};
  static int mr2_3_0[] = {0,1};
  static int mr2_3_1[] = {0,2};
  static int mr2_3_2[] = {0,3};
  static int mr2_3_3[] = {0,4};
  static int mr2_3_4[] = {0,5};
  static int *mp2_3[] = {mr2_3_0,mr2_3_1,mr2_3_2,mr2_3_3,mr2_3_4};
  static int mc2_3[] = {2,2,2,2,2};
  long long act_2 = (long long)maximumValueSum(arr2_0, 6,(3),mp2_3, 5,mc2_3);
  if (!(act_2 == 42LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 3068, "maximumValueSum", ntests);
 return (pass&&ntests)?0:1;
}
