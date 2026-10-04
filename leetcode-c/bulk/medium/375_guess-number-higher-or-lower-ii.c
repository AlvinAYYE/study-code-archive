/*
 * ==========================================================================
 * LeetCode 0375. Guess Number Higher or Lower II
 * Difficulty: Medium
 * Tags: math, dynamic-programming, game-theory
 * URL: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     We are playing the Guessing Game. The game will work as follows:
 *     Given a particular n, return the minimum amount of money you need to
 *     guarantee a win regardless of what number I pick.
 *
 * [中文] 題目: 猜數字大小 II
 * [中文] 題目說明:
 *     在 1 到 n 的猜數字遊戲中，猜錯數字 x 時必須支付 x 元，並
 *     會得知目標較高或較低。請回傳無論目標為何，都能保證猜中的最少準備金額
 *     。
 *
 * [中文] 思路:
 *     對每個區間以記憶化遞迴枚舉首次猜測 x，代價為 x 加上左右子區間較
 *     大的最壞代價，並取其中最小值。
 *
 * Examples:
 *     Input: n = 10
 *     Output: 16
 *     Explanation: The winning strategy is as follows:
 *     - The range is [1,10]. Guess 7.
 *     - If this is my number, your total is $0. Otherwise, you pay
 *     $7.
 *     - If my number is higher, the range is [8,10]. Guess 9.
 *     - If this is my number, your total is $7. Otherwise, you pay
 *     $9.
 *     - If my number is higher, it must be 10. Guess 10. Your total
 *     is $7 + $9 = $16.
 *     - If my number is lower, it must be 8. Guess 8. Your total is
 *     $7 + $9 = $16.
 *     - If my number is lower, the range is [1,6]. Guess 3.
 *     - If this is my number, your total is $7. Otherwise, you pay
 *     $3.
 *     - If my number is higher, the range is [4,6]. Guess 5.
 *     - If this is my number, your total is $7 + $3 = $10.
 *     Otherwise, you pay $5.
 *     - If my number is higher, it must be 6. Guess 6. Your total is
 *     $7 + $3 + $5 = $15.
 *     - If my number is lower, it must be 4. Guess 4. Your total is
 *     $7 + $3 + $5 = $15.
 *     - If my number is lower, the range is [1,2]. Guess 1.
 *     - If this is my number, your total is $7 + $3 = $10.
 *     Otherwise, you pay $1.
 *     - If my number is higher, it must be 2. Guess 2. Your total is
 *     $7 + $3 + $1 = $11.
 *     The worst case in all these scenarios is that you pay $16.
 *     Hence, you only need $16 to guarantee a win.
 *     Input: n = 1
 *     Output: 0
 *     Explanation: There is only one possible number, so you can
 *     guess 1 and not have to pay anything.
 *     Input: n = 2
 *     Output: 1
 *     Explanation: There are two possible numbers, 1 and 2.
 *     - Guess 1.
 *     - If this is my number, your total is $0. Otherwise, you pay
 *     $1.
 *     - If my number is higher, it must be 2. Guess 2. Your total is
 *     $1.
 *     The worst case is that you pay $1.
 *
 * Constraints:
 *   - 1 <= n <= 200
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
375. Guess Number Higher or Lower II

We are playing the Guess Game. The game is as follows: 

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower. 

However, when you guess a particular number x,  and you guess wrong, you pay $x. You win the game when you guess the number I picked.


Example:
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.



Given a particular n   1, find out how much money you need to have to guarantee a win.

Credits:Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.
*/

#define IDX(START, END, SZ) ((START - 1) * SZ + (END - 1))
 
int dp(int *p, int start, int end, int sz) {
    int i, l, r, k, m;
    
    if (start >= end) return 0;
    
    m = p[IDX(start, end, sz)];
    if (m) return m;
    
    for (i = start; i <= end; i ++) {
        k = i;
        l = dp(p, start, i - 1, sz);
        r = dp(p, i + 1, end, sz);
        k += l > r ? l : r;
        if (m == 0 || m > k) m = k;
    }
    p[IDX(start, end, sz)] = m;
    return m;
}
int getMoneyAmount(int n) {
    int *p = calloc(n * n, sizeof(int));
    int m = dp(p, 1, n, n);
    free(p);
    return m;
}


/*
Difficulty:Medium
Total Accepted:22.7K
Total Submissions:63.4K


Companies Google
Related Topics Dynamic Programming Minimax
Similar Questions 
                
                  
                    Flip Game II
                  
                    Guess Number Higher or Lower
                  
                    Can I Win
                  
                    Find K Closest Elements
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  long long act_0 = (long long)getMoneyAmount((10));
  if (!(act_0 == 16LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  long long act_1 = (long long)getMoneyAmount((1));
  if (!(act_1 == 0LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  long long act_2 = (long long)getMoneyAmount((2));
  if (!(act_2 == 1LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 375, "getMoneyAmount", ntests);
 return (pass&&ntests)?0:1;
}
