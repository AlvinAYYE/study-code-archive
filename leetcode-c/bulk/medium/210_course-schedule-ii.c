/*
 * LeetCode 0210. Course Schedule II（課程表 II）
 * Difficulty: Medium
 * 題意：共有 numCourses 門課，prerequisites[i] = [a, b] 表示必須先修完 b 才能修 a。請回傳一個能修完所有課程的順序；若無法完成（有循環），回傳空陣列。答案順序不唯一時，回傳任何一種都可以。
 * 範例：
 *   1. 輸入：numCourses = 2，prerequisites = [[1,0]]；輸出：[0,1]。
 *   2. 輸入：numCourses = 4，prerequisites = [[1,0],[2,0],[3,1],[3,2]]；輸出：[0,1,2,3] 或 [0,2,1,3]。
 *   3. 輸入：numCourses = 1，prerequisites = []；輸出：[0]。
 * 限制：
 *   - 1 <= numCourses <= 2000
 *   - 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 *   - 每列長度為 2，且 ai != bi
 *   - 先修組合不重複
 * 解法：
 *   1. 把每個先修條件轉成「先修課 -> 後續課」的邊，並計算每門課的入度。
 *   2. 先把所有入度為 0 的課放入佇列；這些課目前都可以直接修。
 *   3. 逐一取出課程加入答案，再沿著它的邊降低後續課程入度；入度歸零就加入佇列。
 *   4. 若答案包含所有課，回傳答案；若處理完仍有課未加入，表示有循環，釋放答案並回傳 NULL、將 returnSize 設為 0。
 * 複雜度：時間 O(V + E)，額外空間 O(V + E)。
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
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize,
               int* prerequisitesColSize, int* returnSize) {
    (void)prerequisitesColSize;  // 每列固定有兩個課程編號。
    *returnSize = 0;

    int edgeCapacity = prerequisitesSize > 0 ? prerequisitesSize : 1;
    int *head = (int *)malloc(sizeof(int) * (size_t)numCourses);
    int *to = (int *)malloc(sizeof(int) * (size_t)edgeCapacity);
    int *next = (int *)malloc(sizeof(int) * (size_t)edgeCapacity);
    int *indegree = (int *)calloc((size_t)numCourses, sizeof(int));
    int *queue = (int *)malloc(sizeof(int) * (size_t)numCourses);
    int *order = (int *)malloc(sizeof(int) * (size_t)numCourses);
    if (head == NULL || to == NULL || next == NULL || indegree == NULL ||
        queue == NULL || order == NULL) {
        free(head);
        free(to);
        free(next);
        free(indegree);
        free(queue);
        free(order);
        return NULL;
    }

    for (int course = 0; course < numCourses; course++) {
        head[course] = -1;
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];
        to[i] = course;
        next[i] = head[prerequisite];
        head[prerequisite] = i;
        indegree[course]++;
    }

    int front = 0;
    int back = 0;
    for (int course = 0; course < numCourses; course++) {
        if (indegree[course] == 0) {
            queue[back++] = course;
        }
    }

    while (front < back) {
        int prerequisite = queue[front++];
        order[(*returnSize)++] = prerequisite;

        for (int edge = head[prerequisite]; edge != -1; edge = next[edge]) {
            int course = to[edge];
            indegree[course]--;
            if (indegree[course] == 0) {
                queue[back++] = course;
            }
        }
    }

    free(head);
    free(to);
    free(next);
    free(indegree);
    free(queue);

    if (*returnSize != numCourses) {
        free(order);
        *returnSize = 0;
        return NULL;
    }
    return order;
}

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
