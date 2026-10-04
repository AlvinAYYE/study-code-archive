/*
 * ==========================================================================
 * LeetCode 0685. Redundant Connection II
 * Difficulty: Hard
 * Tags: depth-first-search, breadth-first-search, union-find, graph
 * URL: https://leetcode.com/problems/redundant-connection-ii/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     In this problem, a rooted tree is a directed graph such that, there
 *     is exactly one node (the root) for which all other nodes are
 *     descendants of this node, plus every node has exactly one parent,
 *     except for the root node which has no parents.
 *     The given input is a directed graph that started as a rooted tree
 *     with n nodes (with distinct values from 1 to n), with one additional
 *     directed edge added. The added edge has two different vertices
 *     chosen from 1 to n, and was not an edge that already existed.
 *     The resulting graph is given as a 2D-array of edges. Each element of
 *     edges is a pair [ui, vi] that represents a directed edge connecting
 *     nodes ui and vi, where ui is a parent of child vi.
 *     Return an edge that can be removed so that the resulting graph is a
 *     rooted tree of n nodes. If there are multiple answers, return the
 *     answer that occurs last in the given 2D-array.
 *
 * [中文] 題目: 冗餘連線 II
 * [中文] 題目說明:
 *     根樹是一種有向圖：根節點沒有父節點，其餘每個節點恰有一個父節點，且皆
 *     為根的後代。給定一棵含 1 到 n 節點的根樹加上一條額外有向邊後的
 *     邊列表，請回傳刪除後可恢復為根樹的邊；若有多個答案，回傳列表中最靠後
 *     者。
 *
 * [中文] 思路:
 *     先找出入度變成 2 的節點，暫時略過後出現的那條入邊，再以並查集檢測
 *     環。若仍形成環則刪較早的入邊，若未形成環則刪被略過的較晚入邊。
 *
 * Examples:
 *     Input: edges = [[1,2],[1,3],[2,3]]
 *     Output: [2,3]
 *     Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 *     Output: [4,1]
 *
 * Constraints:
 *   - n == edges.length
 *   - 3 <= n <= 1000
 *   - edges[i].length == 2
 *   - 1 <= ui, vi <= n
 *   - ui != vi
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

static int get_root(int *root, int i)
{
    while (i != root[i]) {
        i = root[i];
        root[i] = root[i];
    }
    return i;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{
    int *ret = malloc(sizeof(int)*2);
    *returnSize = 2;

    int *root = calloc(edgesSize + 1, sizeof(int));
    // Used to record first edge and second edge that
    int fst[2] = {0}, sec[2] = {0};
    for (int i = 0; i < edgesSize; i++) {
        int src = edges[i][0];
        int dst = edges[i][1];
        /*
         * - Find the node(dst) with an indegree of 2
         * - Note that after finding the nodes with an indegree of 2, we need 
         *   to set edge[i][1] to 0. This effectively breaks the edge of the 
         *   last node that generates an indegree of 2.
         */
        if (root[dst] != 0) {
            fst[0] = root[dst];
            fst[1] = dst;
            sec[0] = src;
            sec[1] = dst;
            edges[i][1] = 0;
            break;
        } else {
            root[dst] = src;
        }
    }

    // Reset and do union again, to decide we need to remove first edge or second.
    for (int i = 1; i <= edgesSize; i++)
        root[i] = i;
    
    bool found = false;
    for (int i = 0; i < edgesSize; i++) {
        if (!edges[i][1])
            continue;

        int n0 = get_root(root, edges[i][0]);
        int n1 = get_root(root, edges[i][1]);
        // Find the cycle, directly return the current edge or first edge
        if (n0 == n1) {
            if (fst[0]) {
                ret[0] = fst[0];
                ret[1] = fst[1];
            } else {
                ret[0] = edges[i][0];
                ret[1] = edges[i][1];
            }
            found = true;
            break;
        }
        root[n1] = n0;
    }   
    
    if (!found) {
        ret[0] = sec[0];
        ret[1] = sec[1];    
    }
    
    free(root);
    return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int mr0_0_0[] = {1,2};
  static int mr0_0_1[] = {1,3};
  static int mr0_0_2[] = {2,3};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2};
  static int mc0_0[] = {2,2,2};
  int *act_0 = findRedundantDirectedConnection(mp0_0, 3,mc0_0,&rsz_0);
  static const int exp_0[] = {2,3};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int mr1_0_0[] = {1,2};
  static int mr1_0_1[] = {2,3};
  static int mr1_0_2[] = {3,4};
  static int mr1_0_3[] = {4,1};
  static int mr1_0_4[] = {1,5};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3,mr1_0_4};
  static int mc1_0[] = {2,2,2,2,2};
  int *act_1 = findRedundantDirectedConnection(mp1_0, 5,mc1_0,&rsz_1);
  static const int exp_1[] = {1,4};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 2))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 685, "findRedundantDirectedConnection", ntests);
 return (pass&&ntests)?0:1;
}
