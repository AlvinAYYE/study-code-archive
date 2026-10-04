/*
 * ==========================================================================
 * LeetCode 0446. Arithmetic Slices II - Subsequence
 * Difficulty: Hard
 * Tags: array, dynamic-programming
 * URL: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an integer array nums, return the number of all the arithmetic
 *     subsequences of nums.
 *     A sequence of numbers is called arithmetic if it consists of at
 *     least three elements and if the difference between any two
 *     consecutive elements is the same.
 *     A subsequence of an array is a sequence that can be formed by
 *     removing some elements (possibly none) of the array.
 *     The test cases are generated so that the answer fits in 32-bit
 *     integer.
 *
 * [中文] 題目: 等差數列劃分 II：子序列
 * [中文] 題目說明:
 *     給定整數陣列 nums，回傳所有長度至少為 3 的等差子序列數量。子
 *     序列可刪除任意元素但必須保留原順序，且測資保證答案可裝入 32 位元
 *     整數。
 *
 * [中文] 思路:
 *     對每個結尾索引 i，以雜湊串列記錄各公差的二元以上序列數量。枚舉前一
 *     索引 j 時，將 j 的同公差序列延伸到 i，並把原本長度至少 3 
 *     的延伸數累加到答案。
 *
 * Examples:
 *     Input: nums = [2,4,6,8,10]
 *     Output: 7
 *     Explanation: All arithmetic subsequence slices are:
 *     [2,4,6]
 *     [4,6,8]
 *     [6,8,10]
 *     [2,4,6,8]
 *     [4,6,8,10]
 *     [2,4,6,8,10]
 *     [2,6,10]
 *     Input: nums = [7,7,7,7,7]
 *     Output: 16
 *     Explanation: Any subsequence of this array is arithmetic.
 *
 * Constraints:
 *   - 1 <= nums.length <= 1000
 *   - -231 <= nums[i] <= 231 - 1
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
typedef struct __slist {
    long long diff;
    int ctr;
    struct __slist *next;
} slist_t;

typedef struct __hash_ctx {
    int size;
    slist_t *bucket;
} hash_ctx_t;

static inline int do_hash(hash_ctx_t ctx, long long val)
{
    int hash = val % ctx.size;
    return hash < 0 ? hash + ctx.size : hash;
}

static slist_t* find_hash(hash_ctx_t ctx, long long target)
{
    int id = do_hash(ctx, target);
    slist_t *root = ctx.bucket[id].next;
    while (root) {
        if (root->diff == target)
            return root;

        root = root->next;
    }
    return NULL;
}

static slist_t* add_hash(hash_ctx_t ctx, long long diff, int ctr)
{
    int id = do_hash(ctx, diff);
    slist_t *new_node = malloc(sizeof(slist_t));
    new_node->next = ctx.bucket[id].next;
    new_node->diff = diff;
    new_node->ctr = ctr;
    ctx.bucket[id].next = new_node;
    return new_node;
}

int numberOfArithmeticSlices(int* nums, int numsSize)
{
    int ret = 0;
    hash_ctx_t *dp = calloc(numsSize, sizeof(hash_ctx_t));

    for (int i = 0; i < numsSize; i++) {
        dp[i].size = numsSize;
        dp[i].bucket = calloc(numsSize, sizeof(slist_t));
    }

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            long long diff = (long long)nums[i] - nums[j];
            slist_t *curr = find_hash(dp[i], diff);
            // Create first node with diff value
            if (!curr) {
                curr = add_hash(dp[i], diff, 0);
            }

            slist_t *prev = find_hash(dp[j], diff);
            if (!prev) {
                // Update second node with diff value.
                curr->ctr += 1;
            } else {
                // existence of the previous node indicates that we have found the third element
                // 1. update the counter of current node
                // 2. Add counter to the result.
                curr->ctr += prev->ctr + 1;
                ret += prev->ctr;
            }
        }
    }

    // Free resource
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < dp[i].size; j++) {
            slist_t *node = dp[i].bucket[j].next;
            while (node) {
                slist_t *tmp = node;
                node = node->next;
                free(tmp);
            }
        }
        free(dp[i].bucket);
    }
    free(dp);

    return ret;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {2,4,6,8,10};
  long long act_0 = (long long)numberOfArithmeticSlices(arr0_0, 5);
  if (!(act_0 == 7LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {7,7,7,7,7};
  long long act_1 = (long long)numberOfArithmeticSlices(arr1_0, 5);
  if (!(act_1 == 16LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 446, "numberOfArithmeticSlices", ntests);
 return (pass&&ntests)?0:1;
}
