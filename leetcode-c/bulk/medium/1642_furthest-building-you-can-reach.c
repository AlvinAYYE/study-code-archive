/*
 * ==========================================================================
 * LeetCode 1642. Furthest Building You Can Reach
 * Difficulty: Medium
 * Tags: array, greedy, heap-(priority-queue
 * URL: https://leetcode.com/problems/furthest-building-you-can-reach/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an integer array heights representing the heights of
 *     buildings, some bricks, and some ladders.
 *     You start your journey from building 0 and move to the next building
 *     by possibly using bricks or ladders.
 *     While moving from building i to building i+1 (0-indexed),
 *     Return the furthest building index (0-indexed) you can reach if you
 *     use the given ladders and bricks optimally.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個整數陣列 heights representing the heights of buildings, some bricks,
 *     and some ladders.
 *
 * Examples:
 *     Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
 *     Output: 4
 *     Explanation: Starting at building 0, you can follow these
 *     steps:
 *     - Go to building 1 without using ladders nor bricks since 4 >=
 *     2.
 *     - Go to building 2 using 5 bricks. You must use either bricks
 *     or ladders because 2 < 7.
 *     - Go to building 3 without using ladders nor bricks since 7 >=
 *     6.
 *     - Go to building 4 using your only ladder. You must use either
 *     bricks or ladders because 6 < 9.
 *     It is impossible to go beyond building 4 because you do not
 *     have any more bricks or ladders.
 *     Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders
 *     = 2
 *     Output: 7
 *     Input: heights = [14,3,19,3], bricks = 17, ladders = 0
 *     Output: 3
 *
 * Constraints:
 *   - 1 <= heights.length <= 10^5
 *   - 1 <= heights[i] <= 10^6
 *   - 0 <= bricks <= 10^9
 *   - 0 <= ladders <= heights.length
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
/***
Go through the array heights, for each building heights[i], determine if the
next building heights[i + 1] is greater than it.

If so, we define diff = heights[i + 1] - heights[i]. Then, push the diff into
the max_heap(priority queue), and attempt to reach the next building using
bricks first. Bricks need to be subtracted by diff.

When bricks < 0, it means there are not enough bricks to run from the i-th
building to the (i+1)th building. At this point, we can try to use a ladder to
replace the maximum bricks between the previous two buildings, which is
the root of max_heap. Therefore, bricks can be incremented
by removing the root element of max_heap(Need to adjust the max_heap), and
decrease the number of ladders by 1.

When ladders == 0, we cannot perform the above actions for current building,
return (`current` - 1).


Time: O(n)
Space: O(n)
***/

typedef struct {
    int* arr;
    int cur_sz;
    int sz;
} heap_t;

static inline heap_t* heap_init(int sz) {
    heap_t* obj = malloc(sizeof(heap_t));
    obj->arr = malloc(sizeof(int) * sz);
    obj->cur_sz = 0;
    obj->sz = sz;
    return obj;
}

static inline void heap_dinit(heap_t* obj) {
    free(obj->arr);
    free(obj);
}

static inline void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void max_heapify_bottom_up(int* arr, int i) {
    int parent = ((i - 1) >> 1);
    if (parent >= 0) {
        if (arr[i] > arr[parent]) {
            swap(&arr[i], &arr[parent]);
            max_heapify_bottom_up(arr, parent);
        }
    }
}

static void max_heapify(int* arr, int cur, int size) {
    int l_chd = (cur << 1) + 1;
    int r_chd = (cur << 1) + 2;
    int max = cur;
    if (l_chd < size && arr[l_chd] > arr[max])
        max = l_chd;
    if (r_chd < size && arr[r_chd] > arr[max])
        max = r_chd;

    if (max != cur) {
        swap(&arr[max], &arr[cur]);
        max_heapify(arr, max, size);
    }
}

static int heap_pop(heap_t* obj) {
    int ret = obj->arr[0];
    obj->arr[0] = obj->arr[obj->cur_sz - 1];
    obj->cur_sz -= 1;
    max_heapify(obj->arr, 0, obj->sz);
    return ret;
}

static void heap_push(heap_t* obj, int val) {
    obj->arr[obj->cur_sz] = val;
    max_heapify_bottom_up(obj->arr, obj->cur_sz);
    obj->cur_sz += 1;
}

int furthestBuilding(int* heights, int heightsSize, int bricks, int ladders) {
    int ret = 0;
    heap_t* heap = heap_init(heightsSize);
    for (int i = 1; i < heightsSize; i++) {
        int diff = heights[i] - heights[i - 1];
        if (diff > 0) {
            bricks -= diff;
            heap_push(heap, diff);
            if (bricks < 0) {
                if (0 == ladders) {
                    heap_dinit(heap);
                    return i - 1;
                }
                bricks += heap_pop(heap);
                ladders--;
            }
        }
    }
    heap_dinit(heap);
    return heightsSize - 1;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {4,2,7,6,9,14,12};
  long long act_0 = (long long)furthestBuilding(arr0_0, 7,(5),(1));
  if (!(act_0 == 4LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {4,12,2,7,3,18,20,3,19};
  long long act_1 = (long long)furthestBuilding(arr1_0, 9,(10),(2));
  if (!(act_1 == 7LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {14,3,19,3};
  long long act_2 = (long long)furthestBuilding(arr2_0, 4,(17),(0));
  if (!(act_2 == 3LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1642, "furthestBuilding", ntests);
 return (pass&&ntests)?0:1;
}
