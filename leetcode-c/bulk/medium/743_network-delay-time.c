/*
 * ==========================================================================
 * LeetCode 0743. Network Delay Time
 * Difficulty: Medium
 * Tags: depth-first-search, breadth-first-search, graph, heap-(priority-queue, shortest-path
 * URL: https://leetcode.com/problems/network-delay-time/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a network of n nodes, labeled from 1 to n. You are
 *     also given times, a list of travel times as directed edges times[i]
 *     = (ui, vi, wi), where ui is the source node, vi is the target node,
 *     and wi is the time it takes for a signal to travel from source to
 *     target.
 *     We will send a signal from a given node k. Return the minimum time
 *     it takes for all the n nodes to receive the signal. If it is
 *     impossible for all the n nodes to receive the signal, return -1.
 *
 * [中文] 題目: 網路延遲時間
 * [中文] 題目說明:
 *     給定 n 個編號 1 到 n 的節點與有向邊 times[i] = 
 *     (ui, vi, wi)，wi 是訊號沿邊傳遞所需時間。從節點 k 
 *     發送訊號，回傳所有節點收到訊號所需的最短總等待時間；若有節點無法收到
 *     則回傳 -1。
 *
 * [中文] 思路:
 *     建立各節點的出邊資料，採用 Dijkstra 演算法反覆選取距離最小
 *     的未確定節點並鬆弛其鄰邊。所有節點確定後取最大最短距離，若有未走訪節
 *     點則回傳 -1。
 *
 * Examples:
 *     Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 *     Output: 2
 *     Input: times = [[1,2,1]], n = 2, k = 1
 *     Output: 1
 *     Input: times = [[1,2,1]], n = 2, k = 2
 *     Output: -1
 *
 * Constraints:
 *   - 1 <= k <= n <= 100
 *   - 1 <= times.length <= 6000
 *   - times[i].length == 3
 *   - 1 <= ui, vi <= n
 *   - ui != vi
 *   - 0 <= wi <= 100
 *   - All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
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

typedef struct __node {
    int edge_num;
    int** edges;
} node_t;

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

static int find_min_path_idx(int* dist, bool* set, int size) {
    int ret = -1, min = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (!set[i] && dist[i] < min) {
            ret = i;
            min = dist[i];
        }
    }
    return ret;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n,
                     int k) {
    node_t* ninfo = calloc(n, sizeof(node_t));
    for (int i = 0; i < n; i++) {
        ninfo[i].edges = malloc(sizeof(int*) * (n - 1));
        ninfo[i].edge_num = 0;
    }

    // Update edge info
    for (int i = 0; i < timesSize; i++) {
        int src = times[i][0] - 1; // 0-indexed
        int dst = times[i][1] - 1; // 0-indexed
        int cost = times[i][2];
        ninfo[src].edges[ninfo[src].edge_num] = times[i];
        ninfo[src].edge_num += 1;
    }

    int* dist = malloc(sizeof(int) * n);
    bool* spt_set = malloc(sizeof(bool) * n);
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = false;
    }

    dist[k - 1] = 0;
    int target = k - 1;
    while (target != -1) {
        spt_set[target] = true;
        for (int i = 0; i < ninfo[target].edge_num; i++) {
            int cur_dst = (ninfo[target].edges[i])[1] - 1; // 0-indexed
            int cur_cost = (ninfo[target].edges[i])[2];
            dist[cur_dst] = MIN(dist[cur_dst], dist[target] + cur_cost);
        }
        target = find_min_path_idx(dist, spt_set, n);
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!spt_set[i]) {
            ret = -1;
            break;
        }
        ret = MAX(ret, dist[i]);
    }

    free(spt_set);
    free(dist);
    free(ninfo);
    return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {2,1,1};
  static int mr0_0_1[] = {2,3,1};
  static int mr0_0_2[] = {3,4,1};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2};
  static int mc0_0[] = {3,3,3};
  long long act_0 = (long long)networkDelayTime(mp0_0, 3,mc0_0,(4),(2));
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,2,1};
  static int *mp1_0[] = {mr1_0_0};
  static int mc1_0[] = {3};
  long long act_1 = (long long)networkDelayTime(mp1_0, 1,mc1_0,(2),(1));
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {1,2,1};
  static int *mp2_0[] = {mr2_0_0};
  static int mc2_0[] = {3};
  long long act_2 = (long long)networkDelayTime(mp2_0, 1,mc2_0,(2),(2));
  if (!(act_2 == -1LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 743, "networkDelayTime", ntests);
 return (pass&&ntests)?0:1;
}
