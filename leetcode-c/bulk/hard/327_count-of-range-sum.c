/*
 * ==========================================================================
 * LeetCode 0327. Count of Range Sum
 * Difficulty: Hard
 * Tags: array, binary-search, divide-and-conquer, binary-indexed-tree, segment-tree, merge-sort, ordered-set
 * URL: https://leetcode.com/problems/count-of-range-sum/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an integer array nums and two integers lower and upper, return
 *     the number of range sums that lie in [lower, upper] inclusive.
 *     Range sum S(i, j) is defined as the sum of the elements in nums
 *     between indices i and j inclusive, where i <= j.
 *
 * [中文] 題目: 區間和的個數
 * [中文] 題目說明:
 *     給定整數陣列 nums 及 lower、upper，請計算所有連續區
 *     間和落在閉區間 [lower, upper] 的區間數。區間和 S(
 *     i, j) 為 nums 從 i 到 j（含）的元素總和，且 i ≤
 *      j。
 *
 * [中文] 思路:
 *     先建立前綴和，並以遞迴分治處理左右兩半。合併前在已排序的右半中檢查每
 *     個左側前綴和的差是否落在範圍內並計數，接著執行合併排序。
 *
 * Examples:
 *     Input: nums = [-2,5,-1], lower = -2, upper = 2
 *     Output: 3
 *     Explanation: The three ranges are: [0,0], [2,2], and [0,2] and
 *     their respective sums are: -2, -1, 2.
 *     Input: nums = [0], lower = 0, upper = 0
 *     Output: 1
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^5
 *   - -231 <= nums[i] <= 231 - 1
 *   - -10^5 <= lower <= upper <= 10^5
 *   - The answer is guaranteed to fit in a 32-bit integer.
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
327. Count of Range Sum

Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.

    Range sum S(i, j) is defined as the sum of the elements in nums between indices i and 
    j (i ? j), inclusive.



    Note:
    A naive algorithm of O(n2) is trivial. You MUST do better than that.


    Example:
    Given nums = [-2, 5, -1], lower = -2, upper = 2,
    Return 3.
    The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.


Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.
*/

int count_and_sort(int sort, double *sum, int start, int end, int l, int h, double *tmp) {
    int mid;
    int n, i, j, k, x, stop;
 
    if (end - start <= 1) return 0;
 
    mid = start + (end - start) / 2;
 
    // divide
    n = count_and_sort(1, sum, start, mid, l, h, tmp) +
        count_and_sort(1, sum, mid,   end, l, h, tmp);
 
    // count
    x = 0;
    for (i = start; i < mid; i ++) {
        stop = 0;
        for (j = mid; !stop && j < end; j ++) {
            k = sum[j] - sum[i];
            // because the second part of sum are sorted, the inner loop can stop early.
            if (k > h) stop = 1;
            else if (k >= l) n ++;
        }
    }
 
    // merge sort
    if (sort) {
        i = start;
        j = mid;
        k = 0;
        while (i < mid && j < end) {
            if (sum[i] <= sum[j]) {
                tmp[k] = sum[i];
                i ++;
            } else {
                tmp[k] = sum[j];
                j ++;
            }
            k ++;
        }
        if (i < mid) memcpy(&tmp[k], &sum[i], (mid - i) * sizeof(sum[0]));
        if (j < end) memcpy(&tmp[k], &sum[j], (end - j) * sizeof(sum[0]));
        memcpy(&sum[start], tmp, (end - start) * sizeof(sum[0]));
    }
 
    return n;
}
int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    double *sum, *tmp;
    int i, j, k, n;
    
    sum = malloc((numsSize + 1) * sizeof(double));
    //assert(sum);
    
    sum[0] = 0;
    for (i = 0; i < numsSize; i ++) {
        sum[i + 1] = sum[i] + (double)nums[i];
    }
    
#if 0  // this is O(n^2) 169ms
    n = 0;
    for (i = 0; i < numsSize; i ++) {
        for (j = i + 1; j <= numsSize; j ++) {
            k = sum[j] - sum[i];
            if (k >= lower && k <= upper) n ++;
        }
    }
#else  // this is 285ms :)
    tmp = malloc((numsSize + 1) * sizeof(double));
    //assert(tmp);
    n = count_and_sort(0, sum, 0, numsSize + 1, lower, upper, tmp);
    free(tmp);
#endif
    
    free(sum);
    
    return n;
}


/*
Difficulty:Hard
Total Accepted:19.1K
Total Submissions:64.3K


Companies Google
Related Topics Divide and Conquer Binary Search Tree
Similar Questions 
                
                  
                    Count of Smaller Numbers After Self
                  
                    Reverse Pairs
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {-2,5,-1};
  long long act_0 = (long long)countRangeSum(arr0_0, 3,(-2),(2));
  if (!(act_0 == 3LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {0};
  long long act_1 = (long long)countRangeSum(arr1_0, 1,(0),(0));
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 327, "countRangeSum", ntests);
 return (pass&&ntests)?0:1;
}
