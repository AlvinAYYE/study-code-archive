/*
 * ==========================================================================
 * LeetCode 0935. Knight Dialer
 * Difficulty: Medium
 * Tags: dynamic-programming
 * URL: https://leetcode.com/problems/knight-dialer/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     The chess knight has a unique movement, it may move two squares
 *     vertically and one square horizontally, or two squares horizontally
 *     and one square vertically (with both forming the shape of an L). The
 *     possible movements of chess knight are shown in this diagram:
 *     A chess knight can move as indicated in the chess diagram below:
 *     We have a chess knight and a phone pad as shown below, the knight
 *     can only stand on a numeric cell (i.e. blue cell).
 *     Given an integer n, return how many distinct phone numbers of length
 *     n we can dial.
 *     You are allowed to place the knight on any numeric cell initially
 *     and then you should perform n - 1 jumps to dial a number of length
 *     n. All jumps should be valid knight jumps.
 *     As the answer may be very large, return the answer modulo 10^9 + 7.
 *
 * [中文] 題目: 騎士撥號器
 * [中文] 題目說明:
 *     騎士每次可走標準西洋棋的 L 形跳法，且只能落在電話鍵盤的數字鍵上。
 *     給定 n，可任選起始數字並再跳 n - 1 次，計算可撥出的不同長度
 *      n 電話號碼數量。答案請對 10⁹ + 7 取模。
 *
 * [中文] 思路:
 *     以滾動 DP 記錄每個數字鍵作為目前結尾的方案數，依騎士可跳到的前一
 *     鍵更新下一輪，最後加總十個鍵的數量。
 *
 * Examples:
 *     Input: n = 1
 *     Output: 10
 *     Explanation: We need to dial a number of length 1, so placing
 *     the knight over any numeric cell of the 10 cells is
 *     sufficient.
 *     Input: n = 2
 *     Output: 20
 *     Explanation: All the valid number we can dial are [04, 06, 16,
 *     18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83,
 *     92, 94]
 *     Input: n = 3131
 *     Output: 136006598
 *     Explanation: Please take care of the mod.
 *
 * Constraints:
 *   - 1 <= n <= 5000
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
935. Knight Dialer

A chess knight can move as indicated in the chess diagram below:

 .           

 

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

 





Example 1:

Input: 1
Output: 10



Example 2:

Input: 2
Output: 20



Example 3:

Input: 3
Output: 46


 

Note:


	1 <= N <= 5000
*/

#define MOD 1000000007

const int map[][4] = {
    /* 0 */ { 4, 6, -1 },
    /* 1 */ { 6, 8, -1 },
    /* 2 */ { 7, 9, -1 },
    /* 3 */ { 4, 8, -1 },
    /* 4 */ { 3, 9, 0, -1 },
    /* 5 */ { -1 },
    /* 6 */ { 1, 7, 0, -1 },
    /* 7 */ { 2, 6, -1 },
    /* 8 */ { 1, 3, -1 },
    /* 9 */ { 2, 4, -1 }
};

/* simple back tracking, need to add memorization to pass TLE */
#if 0
int helper(int p, int n) {
    int *m, s, steps = 0;
    
    if (n == 0) return 1;
    if (p == 5) return -1;
    
    m = map[p];
    while (*m != -1) {
        s = helper(*m, n - 1);
        if (s > 0) steps += s;
        m ++;
    }
    
    return steps;
}
#endif

int knightDialer(int N) {
    int buff[20] = { 0 };
    int *p, *n, *t, i, k = 0;
    
    p = buff;
    n = &buff[10];
    
    p[0] = p[1] = p[2] = p[3] = p[4] =
    p[5] = p[6] = p[7] = p[8] = p[9] = 1;
    
    if (N > 1) p[5] = 0;
    
    while (N -- > 1) {
        n[0] = (p[4] + p[6]) % MOD;
        n[1] = (p[6] + p[8]) % MOD;
        n[2] = (p[7] + p[9]) % MOD;
        n[3] = (p[4] + p[8]) % MOD;
        n[4] = ((p[3] + p[9]) % MOD + p[0]) % MOD;
        n[6] = ((p[1] + p[7]) % MOD + p[0]) % MOD;
        n[7] = (p[2] + p[6]) % MOD;
        n[8] = (p[1] + p[3]) % MOD;
        n[9] = (p[2] + p[4]) % MOD;
        t = p;
        p = n;
        n = t;
    }
    
    for (i = 0; i < 10; i ++) {
        k = (k + p[i]) % MOD;
    }
    
    return k;
}


/*
Difficulty:Medium


*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  long long act_0 = (long long)knightDialer((1));
  if (!(act_0 == 10LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  long long act_1 = (long long)knightDialer((2));
  if (!(act_1 == 20LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  long long act_2 = (long long)knightDialer((3131));
  if (!(act_2 == 136006598LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 935, "knightDialer", ntests);
 return (pass&&ntests)?0:1;
}
