/*
 * ==========================================================================
 * LeetCode 0947. Most Stones Removed with Same Row or Column
 * Difficulty: Medium
 * Tags: hash-table, depth-first-search, union-find, graph
 * URL: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     On a 2D plane, we place n stones at some integer coordinate points.
 *     Each coordinate point may have at most one stone.
 *     A stone can be removed if it shares either the same row or the same
 *     column as another stone that has not been removed.
 *     Given an array stones of length n where stones[i] = [xi, yi]
 *     represents the location of the ith stone, return the largest
 *     possible number of stones that can be removed.
 *
 * [中文] 題目: 移除最多的同行或同列石頭
 * [中文] 題目說明:
 *     平面上有 n 顆石頭，每個座標至多一顆；若一顆石頭與另一顆尚未移除的
 *     石頭同列或同行，就可移除它。給定各石頭座標，請回傳最多能移除多少顆石
 *     頭。
 *
 * [中文] 思路:
 *     以 DFS 尋找由同行或同列關係連通的石頭群；每個大小為 m 的連通
 *     元件可移除 m-1 顆，累加所有元件即可。
 *
 * Examples:
 *     Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 *     Output: 5
 *     Explanation: One way to remove 5 stones is as follows:
 *     1. Remove stone [2,2] because it shares the same row as [2,1].
 *     2. Remove stone [2,1] because it shares the same column as
 *     [0,1].
 *     3. Remove stone [1,2] because it shares the same row as [1,0].
 *     4. Remove stone [1,0] because it shares the same column as
 *     [0,0].
 *     5. Remove stone [0,1] because it shares the same row as [0,0].
 *     Stone [0,0] cannot be removed since it does not share a
 *     row/column with another stone still on the plane.
 *     Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 *     Output: 3
 *     Explanation: One way to make 3 moves is as follows:
 *     1. Remove stone [2,2] because it shares the same row as [2,0].
 *     2. Remove stone [2,0] because it shares the same column as
 *     [0,0].
 *     3. Remove stone [0,2] because it shares the same row as [0,0].
 *     Stones [0,0] and [1,1] cannot be removed since they do not
 *     share a row/column with another stone still on the plane.
 *     Input: stones = [[0,0]]
 *     Output: 0
 *     Explanation: [0,0] is the only stone on the plane, so you
 *     cannot remove it.
 *
 * Constraints:
 *   - 1 <= stones.length <= 1000
 *   - 0 <= xi, yi <= 10^4
 *   - No two stones are at the same coordinate point.
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
947. Most Stones Removed with Same Row or Column

On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

 


Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5



Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3



Example 3:

Input: stones = [[0,0]]
Output: 0


 

Note:


	1 <= stones.length <= 1000
	0 <= stones[i][j] < 10000
*/

// The description of this question is very unclear.
// The best way is to use bfs to visit all connected stones.
void dfs(int **stones, int sz, int p, int *visited, int *n) {
    int r, c, i;
    
    if (visited[p]) return;
    
    visited[p] = 1;

    (*n) ++;
    
    r = stones[p][0];
    c = stones[p][1];
    
    // remove stones on same row
    for (i = 0; i < sz; i ++) {
        if (stones[i][0] == r) dfs(stones, sz, i, visited, n);
    }
    
    // remove stones on same col
    for (i = 0; i < sz; i ++) {
        if (stones[i][1] == c) dfs(stones, sz, i, visited, n);
    }
    
    //visited[p] = 0;
}
 
int removeStones(int** stones, int stonesSize, int* stonesColSize){
    int n, ans = 0;
    int *visited;
    int i;
    
    visited = calloc(stonesSize, sizeof(int));
    //assert(visited);
    
    for (i = 0; i < stonesSize; i ++) {
        n = 0;
        dfs(stones, stonesSize, i, visited, &n);
        if (n) ans += n - 1;
        //printf("%d\n", n);
    }
    
    free(visited);
    
    return ans;
}
 
 
    


/*
Difficulty:Medium


*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {0,0};
  static int mr0_0_1[] = {0,1};
  static int mr0_0_2[] = {1,0};
  static int mr0_0_3[] = {1,2};
  static int mr0_0_4[] = {2,1};
  static int mr0_0_5[] = {2,2};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3,mr0_0_4,mr0_0_5};
  static int mc0_0[] = {2,2,2,2,2,2};
  long long act_0 = (long long)removeStones(mp0_0, 6,mc0_0);
  if (!(act_0 == 5LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {0,0};
  static int mr1_0_1[] = {0,2};
  static int mr1_0_2[] = {1,1};
  static int mr1_0_3[] = {2,0};
  static int mr1_0_4[] = {2,2};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3,mr1_0_4};
  static int mc1_0[] = {2,2,2,2,2};
  long long act_1 = (long long)removeStones(mp1_0, 5,mc1_0);
  if (!(act_1 == 3LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {0,0};
  static int *mp2_0[] = {mr2_0_0};
  static int mc2_0[] = {2};
  long long act_2 = (long long)removeStones(mp2_0, 1,mc2_0);
  if (!(act_2 == 0LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 947, "removeStones", ntests);
 return (pass&&ntests)?0:1;
}
