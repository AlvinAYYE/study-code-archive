/*
 * ==========================================================================
 * LeetCode 0350. Intersection of Two Arrays II
 * Difficulty: Easy
 * Tags: array, hash-table, two-pointers, binary-search, sorting
 * URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given two integer arrays nums1 and nums2, return an array of their
 *     intersection. Each element in the result must appear as many times
 *     as it shows in both arrays and you may return the result in any
 *     order.
 *
 * [中文] 題目: 兩個陣列的交集 II
 * [中文] 題目說明:
 *     給定兩個整數陣列 nums1 與 nums2，回傳它們的交集。每個值
 *     在結果中出現的次數，必須等於它在兩個陣列中共同出現的次數，順序不限。
 *
 * [中文] 思路:
 *     先以雜湊表記錄 nums2 各值的剩餘次數，掃描 nums1 時若仍
 *     有可配對次數便輸出該值並遞減計數。
 *
 * Examples:
 *     Input: nums1 = [1,2,2,1], nums2 = [2,2]
 *     Output: [2,2]
 *     Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 *     Output: [4,9]
 *     Explanation: [9,4] is also accepted.
 *
 * Constraints:
 *   - 1 <= nums1.length, nums2.length <= 1000
 *   - 0 <= nums1[i], nums2[i] <= 1000
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
350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.


Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].


Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.



Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#if 1
typedef struct e_s {
    int val;
    int cnt;
    struct e_s *shadow;
} e_t;
#define HF  1021
e_t *lookup(e_t **ht, int v) {
    int hc = v % HF;
    e_t *e = ht[hc];
    while (e && e->val != v) e = e->shadow;
    return e;
}
void insert(e_t **ht, e_t *e) {
    int hc = e->val % HF;
    e->shadow = ht[hc];
    ht[hc] = e;
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    e_t *e, *buff, *ht[HF] = { 0 };
    int i, v;
    int k, *result;
    
    *returnSize = 0;
    if (!nums1Size || !nums2Size) {
        return NULL;
    }
    
    buff = malloc(nums2Size * sizeof(e_t));
    //assert(buff);
    for (i = 0; i < nums2Size; i ++) {
        v = nums2[i];
        e = lookup(ht, v);
        if (e) e->cnt ++;
        else {
            e = &buff[i];
            e->val = v;
            e->cnt = 1;
            insert(ht, e);
        }
    }
    
    k = 0;
    result = malloc(nums1Size * sizeof(int));
    //assert(result);
    
    for (i = 0; i < nums1Size; i ++) {
        v = nums1[i];
        e = lookup(ht, v);
        if (e && e->cnt > 0) {
            result[k ++] = v;
            e->cnt --;
        }
    }
    
    free(buff);
    
    *returnSize = k;
    return result;
}
#else
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int i, j, k;
    int *result, *flags;
    
    if (nums1Size > nums2Size) {
        return intersect(nums2, nums2Size, nums1, nums1Size, returnSize);
    }
    
    *returnSize = 0;
    if (!nums1Size || !nums2Size) {
        return NULL;
    }
    
    result = malloc(nums1Size * sizeof(int));
    flags  = calloc(nums2Size, sizeof(int));
    //assert(result && flags);
    
    k = 0;
    for (i = 0; i < nums1Size; i ++) {
        for (j = 0; j < nums2Size; j ++) {
            if (!flags[j] && nums1[i] == nums2[j]) {
                result[k++] = nums1[i];
                flags[j] = 1;
                break;
            }
        }
    }
    
    *returnSize = k;
    free(flags);
    return result;
}
#endif


/*
Difficulty:Easy
Total Accepted:72K
Total Submissions:161.4K


Related Topics Binary Search Hash Table Two Pointers Sort
Similar Questions Intersection of Two Arrays

*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int arr0_0[] = {1,2,2,1};
  static int arr0_2[] = {2,2};
  int *act_0 = intersect(arr0_0, 4,arr0_2, 2,&rsz_0);
  static const int exp_0[] = {2,2};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int arr1_0[] = {4,9,5};
  static int arr1_2[] = {9,4,9,8,4};
  int *act_1 = intersect(arr1_0, 3,arr1_2, 5,&rsz_1);
  static const int exp_1[] = {4,9};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 2))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 350, "intersect", ntests);
 return (pass&&ntests)?0:1;
}
