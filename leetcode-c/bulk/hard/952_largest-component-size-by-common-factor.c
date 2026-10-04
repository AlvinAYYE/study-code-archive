/*
 * ==========================================================================
 * LeetCode 0952. Largest Component Size by Common Factor
 * Difficulty: Hard
 * Tags: array, hash-table, math, union-find, number-theory
 * URL: https://leetcode.com/problems/largest-component-size-by-common-factor/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an integer array of unique positive integers nums.
 *     Consider the following graph:
 *     Return the size of the largest connected component in the graph.
 *
 * [中文] 題目: 按公因數連通的最大元件大小
 * [中文] 題目說明:
 *     給定互不相同的正整數陣列 nums，將每個數字視為圖中的節點。若兩數
 *     的最大公因數大於 1，兩節點之間便有一條邊。請回傳圖中最大連通元件的
 *     大小。
 *
 * [中文] 思路:
 *     程式枚舉每個數字的因數，透過並查集把數字與其因數及互補因數合併；最後
 *     依各數字所屬根節點統計元件計數並取最大值。
 *
 * Examples:
 *     Input: nums = [4,6,15,35]
 *     Output: 4
 *     Input: nums = [20,50,9,63]
 *     Output: 2
 *     Input: nums = [2,3,6,7,4,12,21,39]
 *     Output: 8
 *
 * Constraints:
 *   - 1 <= nums.length <= 2 * 10^4
 *   - 1 <= nums[i] <= 10^5
 *   - All the values of nums are unique.
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

#define MAX(a, b) (a > b ? a : b)

typedef struct {
    int val;
    int com_sz;
} data_t;

typedef struct {
    data_t *d;
    int size;
} hash_t;

static inline hash_t *hash_create(int size)
{
    hash_t *obj = malloc(sizeof(hash_t));
    obj->size = size;
    obj->d = calloc(size, sizeof(data_t));
    return obj;
}

static inline void hash_release(hash_t *h)
{
    free(h->d);
    free(h);
}

static void hash_add(hash_t *h, int val)
{
    int hidx = val % h->size;
    while (h->d[hidx].com_sz)
        hidx = (hidx + 1) % h->size;

    h->d[hidx].val = val;
    h->d[hidx].com_sz = 1;
}

static int hash_update(hash_t *h, int val)
{
    int hidx = val % h->size;
    while (h->d[hidx].val != val)
        hidx = (hidx + 1) % h->size;

    h->d[hidx].com_sz += 1;
    return h->d[hidx].com_sz;
}

/* Return the idnex of root */
static int set_find(int *set, int target)
{
    if (set[target] < 0)
        return target;

    int ret = set_find(set, set[target]);
    /* compress set */
    set[target] = ret;
    return ret;
}

static void set_union(int *set, int target, int cur)
{
    int r1_idx = set_find(set, target);
    int r2_idx = set_find(set, cur);
    if (r1_idx == r2_idx)
        return;

    if (set[r1_idx] <= set[r2_idx]) {
        set[r1_idx] += set[r2_idx];
        set[r2_idx] = r1_idx;
    } else {
        set[r2_idx] += set[r1_idx];
        set[r1_idx] = r2_idx;
    }
}

int largestComponentSize(int *A, int ASize)
{
    int max = A[0];
    for (int i = 1; i < ASize; i++)
        max = MAX(max, A[i]);

    int *set = malloc(sizeof(int) * (max + 1));
    for (int i = 0; i < max + 1; i++)
        set[i] = -1;

    hash_t *h = hash_create(max + 1);
    for (int i = 0; i < ASize; i++)
        hash_add(h, A[i]);

    for (int i = 0; i < ASize; i++) {
        int num = sqrt(A[i]);
        for (int cur = 2; cur <= num; cur++) {
            if (A[i] % cur == 0) {
                set_union(set, A[i], cur);
                set_union(set, A[i], A[i] / cur);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < ASize; i++) {
        int cur_ret = hash_update(h, set_find(set, A[i]));
        ret = MAX(ret, cur_ret);
    }

    hash_release(h);
    free(set);
    return (ret - 1);
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {4,6,15,35};
  long long act_0 = (long long)largestComponentSize(arr0_0, 4);
  if (!(act_0 == 4LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {20,50,9,63};
  long long act_1 = (long long)largestComponentSize(arr1_0, 4);
  if (!(act_1 == 2LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {2,3,6,7,4,12,21,39};
  long long act_2 = (long long)largestComponentSize(arr2_0, 8);
  if (!(act_2 == 8LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 952, "largestComponentSize", ntests);
 return (pass&&ntests)?0:1;
}
