/*
 * ==========================================================================
 * LeetCode 0630. Course Schedule III
 * Difficulty: Hard
 * Tags: array, greedy, sorting, heap-(priority-queue
 * URL: https://leetcode.com/problems/course-schedule-iii/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     There are n different online courses numbered from 1 to n. You are
 *     given an array courses where courses[i] = [durationi, lastDayi]
 *     indicate that the ith course should be taken continuously for
 *     durationi days and must be finished before or on lastDayi.
 *     You will start on the 1st day and you cannot take two or more
 *     courses simultaneously.
 *     Return the maximum number of courses that you can take.
 *
 * [中文] 題目: 課程表 III
 * [中文] 題目說明:
 *     每門課以持續天數與最晚完成日表示，必須從第 1 天開始安排，且不能同
 *     時修讀多門課。選出的每門課都須在最晚完成日當天或之前結束，求最多可修
 *     的課程數量。
 *
 * [中文] 思路:
 *     先依最晚完成日排序，逐門加入目前選擇並累計總天數。程式以排序陣列模擬
 *     最大堆，若超過期限就移除已選課程中最長的一門。
 *
 * Examples:
 *     Input: courses =
 *     [[100,200],[200,1300],[1000,1250],[2000,3200]]
 *     Output: 3
 *     Explanation:
 *     There are totally 4 courses, but you can take 3 courses at
 *     most:
 *     First, take the 1st course, it costs 100 days so you will
 *     finish it on the 100th day, and ready to take the next course
 *     on the 101st day.
 *     Second, take the 3rd course, it costs 1000 days so you will
 *     finish it on the 1100th day, and ready to take the next course
 *     on the 1101st day.
 *     Third, take the 2nd course, it costs 200 days so you will
 *     finish it on the 1300th day.
 *     The 4th course cannot be taken now, since you will finish it
 *     on the 3300th day, which exceeds the closed date.
 *     Input: courses = [[1,2]]
 *     Output: 1
 *     Input: courses = [[3,2],[4,3]]
 *     Output: 0
 *
 * Constraints:
 *   - 1 <= courses.length <= 10^4
 *   - 1 <= durationi, lastDayi <= 10^4
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
630. Course Schedule III

There are n different online courses numbered from 1 to n. Each course has some duration(course length)  t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.



Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.



Example:
Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
Output: 3
Explanation: 
There're totally 4 courses, but you can take 3 courses at most:
First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.




Note:

The integer 1 <= d, t, n <= 10,000. 
You can't take two courses simultaneously.
*/

typedef struct {
    int *p;
    int n;
} heap_t;
int cmp(const void *a, const void *b) {
    int x = *(int *)a, y = *(int *)b;
    return x < y ? -1 :
           x > y ?  1 : 0;
}
int cmp2(const void *a, const void *b) {
    int x = (*(int **)a)[1], *y = (*(int **)b)[1];
    return x < y ? -1 :
           x > y ?  1 : 0;
}
void heap_push(heap_t *heap, int k) {
    heap->p[heap->n ++] = k;
    qsort(heap->p, heap->n, sizeof(int), cmp);  // optimize here to avoid TLE!!!
}
int heap_pop(heap_t *heap) {
    int k = heap->p[-- heap->n];
    return k;
}
int scheduleCourse(int** courses, int coursesRowSize, int coursesColSize) {
    heap_t heap = { 0 };
    int i, days, end, t;
    
    qsort(courses, coursesRowSize, sizeof(int *), cmp2);
    
    heap.p = malloc(coursesRowSize * sizeof(int));
    //assert(heap.p);
    
    t = 0;
    for (i = 0; i < coursesRowSize; i ++) {
        days = courses[i][0];
        end  = courses[i][1];
        heap_push(&heap, days);
        t += days;
        if (t > end) {
            t -= heap_pop(&heap);
        }
    }
    
    free(heap.p);
    
    return heap.n;
}


/*
Difficulty:Hard
Total Accepted:3.5K
Total Submissions:12.7K


Companies WAP
Related Topics Greedy
Similar Questions 
                
                  
                    Course Schedule
                  
                    Course Schedule II
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {100,200};
  static int mr0_0_1[] = {200,1300};
  static int mr0_0_2[] = {1000,1250};
  static int mr0_0_3[] = {2000,3200};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3};
  static int mc0_0[] = {2,2,2,2};
  long long act_0 = (long long)scheduleCourse(mp0_0, 4,mc0_0);
  if (!(act_0 == 3LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,2};
  static int *mp1_0[] = {mr1_0_0};
  static int mc1_0[] = {2};
  long long act_1 = (long long)scheduleCourse(mp1_0, 1,mc1_0);
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int mr2_0_0[] = {3,2};
  static int mr2_0_1[] = {4,3};
  static int *mp2_0[] = {mr2_0_0,mr2_0_1};
  static int mc2_0[] = {2,2};
  long long act_2 = (long long)scheduleCourse(mp2_0, 2,mc2_0);
  if (!(act_2 == 0LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 630, "scheduleCourse", ntests);
 return (pass&&ntests)?0:1;
}
