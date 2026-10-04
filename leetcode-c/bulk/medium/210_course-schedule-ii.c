/*
 * ==========================================================================
 * LeetCode 0210. Course Schedule II
 * Difficulty: Medium
 * Tags: depth-first-search, breadth-first-search, graph, topological-sort
 * URL: https://leetcode.com/problems/course-schedule-ii/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     There are a total of numCourses courses you have to take, labeled
 *     from 0 to numCourses - 1. You are given an array prerequisites where
 *     prerequisites[i] = [ai, bi] indicates that you must take course bi
 *     first if you want to take course ai.
 *     Return the ordering of courses you should take to finish all
 *     courses. If there are many valid answers, return any of them. If it
 *     is impossible to finish all courses, return an empty array.
 *
 * [中文] 題目: 課程表 II
 * [中文] 題目說明:
 *     共有 numCourses 門編號課程，先修關係 [a, b] 表示
 *     必須先完成 b 才能修 a。請回傳任一可完成全部課程的修習順序；若存
 *     在循環而無法完成，回傳空陣列。
 *
 * [中文] 思路:
 *     程式以鄰接矩陣與入度陣列建圖，從所有入度為零的課程做 DFS，走訪時
 *     遞減後繼入度並在歸零時遞迴加入，最後僅在輸出數量等於課程數時保留結果
 *     。
 *
 * Examples:
 *     Input: numCourses = 2, prerequisites = [[1,0]]
 *     Output: [0,1]
 *     Explanation: There are a total of 2 courses to take. To take
 *     course 1 you should have finished course 0. So the correct
 *     course order is [0,1].
 *     Input: numCourses = 4, prerequisites =
 *     [[1,0],[2,0],[3,1],[3,2]]
 *     Output: [0,2,1,3]
 *     Explanation: There are a total of 4 courses to take. To take
 *     course 3 you should have finished both courses 1 and 2. Both
 *     courses 1 and 2 should be taken after you finished course 0.
 *     So one correct course order is [0,1,2,3]. Another correct
 *     ordering is [0,2,1,3].
 *     Input: numCourses = 1, prerequisites = []
 *     Output: [0]
 *
 * Constraints:
 *   - 1 <= numCourses <= 2000
 *   - 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 *   - prerequisites[i].length == 2
 *   - 0 <= ai, bi < numCourses
 *   - ai != bi
 *   - All the pairs [ai, bi] are distinct.
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
210. Course Schedule II

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]


Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.


For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.



click to show more hints.

Hints:

This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int has_cycle(int *buff, int n, int sz, int *visited) {
    int i, *node;
    
    if (visited[n] == -1) return 0;
    if (visited[n] == 1) return 1;
    
    visited[n] = 1;
    
    node = &buff[n * sz];
    for (i = 0; i < sz; i ++) {
        if (node[i] != 0 && has_cycle(buff, node[i], sz, visited)) {
            return true;
        }
    }
    
    visited[n] = -1;
    
    return false;
}
void dfs(int *buff, int n, int sz, int *indegree, int *visited, int *courses, int *k) {
    int i, *node;
    
    visited[n] = 3;
    
    courses[(*k) ++] = n - 1;
    
    node = &buff[n * sz];
    for (i = 0; i < sz; i ++) {
        n = node[i];
        if (n && visited[n] != 3) {
            indegree[n] --;
            if (indegree[n] == 0) {
                dfs(buff, n, sz, indegree, visited, courses, k);
            }
        }
    }
}
int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize, int* returnSize) {
    int *buff, *root, *node_a;
    int i, n, k, a, b;
    int *visited;
    int *indegree;
    int *courses;
    
    buff = calloc((numCourses + 1) * numCourses, sizeof(int)); // each node with all possible neighbors
    visited = calloc((numCourses + 1), sizeof(int));
    indegree = calloc((numCourses + 1), sizeof(int));
    courses  = calloc(numCourses, sizeof(int));
    //assert(buff && visited && indegree && courses);
    
    root = &buff[0];  // root node has neighbors of all
    for (i = 0; i < numCourses; i ++) {
        root[i] = i + 1;
    }
    
    for (i = 0; i < prerequisitesRowSize; i ++) {
        a = prerequisites[i][1];
        b = prerequisites[i][0];
        node_a = &buff[(a + 1) * numCourses];
        node_a[b] = (b + 1);    // node a has neighbor b which has id b + 1
        indegree[(b + 1)] ++;
    }
    
    k = 0;
    
    //if (has_cycle(buff, 0, numCourses, visited)) {
    //    goto done;
    //}
    
    // topological sort using dfs
    for (i = 0; i < numCourses; i ++) {
        n = root[i];
        if (indegree[n] == 0 && visited[n] != 3) {
            dfs(buff, n, numCourses, indegree, visited, courses, &k);
        }
    }
    
    if (k != numCourses) k = 0;
    
done:
    free(buff);
    free(visited);
    free(indegree);

    *returnSize = k;
    
    return courses;
}


/*
Difficulty:Medium
Total Accepted:65.8K
Total Submissions:235.5K


Companies Facebook Zenefits
Related Topics Depth-first Search Breadth-first Search Graph Topological Sort
Similar Questions 
                
                  
                    Course Schedule
                  
                    Alien Dictionary
                  
                    Minimum Height Trees
                  
                    Sequence Reconstruction
                  
                    Course Schedule III
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int mr0_1_0[] = {1,0};
  static int *mp0_1[] = {mr0_1_0};
  static int mc0_1[] = {2};
  int *act_0 = findOrder((2),mp0_1, 1,mc0_1,&rsz_0);
  static const int exp_0[] = {0,1};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int mr1_1_0[] = {1,0};
  static int mr1_1_1[] = {2,0};
  static int mr1_1_2[] = {3,1};
  static int mr1_1_3[] = {3,2};
  static int *mp1_1[] = {mr1_1_0,mr1_1_1,mr1_1_2,mr1_1_3};
  static int mc1_1[] = {2,2,2,2};
  int *act_1 = findOrder((4),mp1_1, 4,mc1_1,&rsz_1);
  static const int exp_1[] = {0,1,2,3};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 4))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  static int *mp2_1[] = {0};
  static int mc2_1[] = {0};
  int *act_2 = findOrder((1),mp2_1, 0,mc2_1,&rsz_2);
  static const int exp_2[] = {0};
  if (!(lc_eq_list_sorted(act_2, rsz_2, exp_2, 1))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 210, "findOrder", ntests);
 return (pass&&ntests)?0:1;
}
