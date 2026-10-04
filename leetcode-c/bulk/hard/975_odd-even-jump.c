/*
 * ==========================================================================
 * LeetCode 0975. Odd Even Jump
 * Difficulty: Hard
 * Tags: array, dynamic-programming, stack, sorting, monotonic-stack, ordered-set
 * URL: https://leetcode.com/problems/odd-even-jump/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an integer array arr. From some starting index, you
 *     can make a series of jumps. The (1st, 3rd, 5th, ...) jumps in the
 *     series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...)
 *     jumps in the series are called even-numbered jumps. Note that the
 *     jumps are numbered, not the indices.
 *     You may jump forward from index i to index j (with i < j) in the
 *     following way:
 *     A starting index is good if, starting from that index, you can reach
 *     the end of the array (index arr.length - 1) by jumping some number
 *     of times (possibly 0 or more than once).
 *     Return the number of good starting indices.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個整數陣列 arr. From some starting index, you can make a series of
 *     jumps.
 *
 * Examples:
 *     Input: arr = [10,13,12,14,15]
 *     Output: 2
 *     Explanation:
 *     From starting index i = 0, we can make our 1st jump to i = 2
 *     (since arr[2] is the smallest among arr[1], arr[2], arr[3],
 *     arr[4] that is greater or equal to arr[0]), then we cannot
 *     jump any more.
 *     From starting index i = 1 and i = 2, we can make our 1st jump
 *     to i = 3, then we cannot jump any more.
 *     From starting index i = 3, we can make our 1st jump to i = 4,
 *     so we have reached the end.
 *     From starting index i = 4, we have reached the end already.
 *     In total, there are 2 different starting indices i = 3 and i =
 *     4, where we can reach the end with some number of
 *     jumps.
 *     Input: arr = [2,3,1,1,4]
 *     Output: 3
 *     Explanation:
 *     From starting index i = 0, we make jumps to i = 1, i = 2, i =
 *     3:
 *     During our 1st jump (odd-numbered), we first jump to i = 1
 *     because arr[1] is the smallest value in [arr[1], arr[2],
 *     arr[3], arr[4]] that is greater than or equal to arr[0].
 *     During our 2nd jump (even-numbered), we jump from i = 1 to i =
 *     2 because arr[2] is the largest value in [arr[2], arr[3],
 *     arr[4]] that is less than or equal to arr[1]. arr[3] is also
 *     the largest value, but 2 is a smaller index, so we can only
 *     jump to i = 2 and not i = 3
 *     During our 3rd jump (odd-numbered), we jump from i = 2 to i =
 *     3 because arr[3] is the smallest value in [arr[3], arr[4]]
 *     that is greater than or equal to arr[2].
 *     We can't jump from i = 3 to i = 4, so the starting index i = 0
 *     is not good.
 *     In a similar manner, we can deduce that:
 *     From starting index i = 1, we jump to i = 4, so we reach the
 *     end.
 *     From starting index i = 2, we jump to i = 3, and then we can't
 *     jump anymore.
 *     From starting index i = 3, we jump to i = 4, so we reach the
 *     end.
 *     From starting index i = 4, we are already at the end.
 *     In total, there are 3 different starting indices i = 1, i = 3,
 *     and i = 4, where we can reach the end with some
 *     number of jumps.
 *     Input: arr = [5,1,3,4,2]
 *     Output: 3
 *     Explanation: We can reach the end from starting indices 1, 2,
 *     and 4.
 *
 * Constraints:
 *   - 1 <= arr.length <= 2 * 10^4
 *   - 0 <= arr[i] < 10^5
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
975. Odd Even Jump

You are given an integer array A.  From some starting index, you can make a series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even numbered jumps.

You may from index i jump forward to index j (with i < j) in the following way:


	During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j such that A[i] <= A[j] and A[j] is the smallest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
	During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j such that A[i] >= A[j] and A[j] is the largest possible value.  If there are multiple such indexes j, you can only jump to the smallest such index j.
	(It may be the case that for some index i, there are no legal jumps.)


A starting index is good if, starting from that index, you can reach the end of the array (index A.length - 1) by jumping some number of times (possibly 0 or more than once.)

Return the number of good starting indexes.

 

Example 1:

Input: [10,13,12,14,15]
Output: 2
Explanation: 
From starting index i = 0, we can jump to i = 2 (since A[2] is the smallest among A[1], A[2], A[3], A[4] that is greater or equal to A[0]), then we can't jump any more.
From starting index i = 1 and i = 2, we can jump to i = 3, then we can't jump any more.
From starting index i = 3, we can jump to i = 4, so we've reached the end.
From starting index i = 4, we've reached the end already.
In total, there are 2 different starting indexes (i = 3, i = 4) where we can reach the end with some number of jumps.



Example 2:

Input: [2,3,1,1,4]
Output: 3
Explanation: 
From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:

During our 1st jump (odd numbered), we first jump to i = 1 because A[1] is the smallest value in (A[1], A[2], A[3], A[4]) that is greater than or equal to A[0].

During our 2nd jump (even numbered), we jump from i = 1 to i = 2 because A[2] is the largest value in (A[2], A[3], A[4]) that is less than or equal to A[1].  A[3] is also the largest value, but 2 is a smaller index, so we can only jump to i = 2 and not i = 3.

During our 3rd jump (odd numbered), we jump from i = 2 to i = 3 because A[3] is the smallest value in (A[3], A[4]) that is greater than or equal to A[2].

We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.

In a similar manner, we can deduce that:
From starting index i = 1, we jump to i = 4, so we reach the end.
From starting index i = 2, we jump to i = 3, and then we can't jump anymore.
From starting index i = 3, we jump to i = 4, so we reach the end.
From starting index i = 4, we are already at the end.
In total, there are 3 different starting indexes (i = 1, i = 3, i = 4) where we can reach the end with some number of jumps.



Example 3:

Input: [5,1,3,4,2]
Output: 3
Explanation: 
We can reach the end from starting indexes 1, 2, and 4.




 

Note:


	1 <= A.length <= 20000
	0 <= A[i] < 100000
*/

int smallest_among_greaters(int k, int *map, int sz) {
    for (int i = k; i < sz; i ++) {
        if (map[i] != 0) return map[i];
    }
    return 0;
}
int greatest_among_smallers(int k, int *map, int sz) {
    for (int i = k; i >= 0; i --) {
        if (map[i] != 0) return map[i];
    }
    return 0;
}
int oddEvenJumps(int* A, int ASize){
    // if jump can to to a high or low number on current index
    bool hi[20000] = { false }, lo[20000] = { false };
    
    // index of a number is on
    int map[100000] = { 0 };
#define sz (sizeof(map) / sizeof(map[0]))
    
    int i, h, l, ans;
    
    hi[ASize - 1] = lo[ASize - 1] = true;
    
    map[A[ASize - 1]] = ASize;  // index + 1
    
    ans = 1;
    
    for (i = ASize - 2; i >= 0; i --) {
        h = smallest_among_greaters(A[i], map, sz);
        l = greatest_among_smallers(A[i], map, sz);
        if (h && lo[h - 1]) { hi[i] = true; ans ++; }
        if (l && hi[l - 1]) lo[i] = true;
        map[A[i]] = i + 1;
    }
    
    return ans;
}


/*
Difficulty:Hard


*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {10,13,12,14,15};
  long long act_0 = (long long)oddEvenJumps(arr0_0, 5);
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {2,3,1,1,4};
  long long act_1 = (long long)oddEvenJumps(arr1_0, 5);
  if (!(act_1 == 3LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {5,1,3,4,2};
  long long act_2 = (long long)oddEvenJumps(arr2_0, 5);
  if (!(act_2 == 3LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 975, "oddEvenJumps", ntests);
 return (pass&&ntests)?0:1;
}
