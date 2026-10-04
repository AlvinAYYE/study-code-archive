/*
 * ==========================================================================
 * LeetCode 0321. Create Maximum Number
 * Difficulty: Hard
 * Tags: array, two-pointers, stack, greedy, monotonic-stack
 * URL: https://leetcode.com/problems/create-maximum-number/
 * Source: community solution, repo tongtzeho_LeetCode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given two integer arrays nums1 and nums2 of lengths m and n
 *     respectively. nums1 and nums2 represent the digits of two numbers.
 *     You are also given an integer k.
 *     Create the maximum number of length k <= m + n from digits of the
 *     two numbers. The relative order of the digits from the same array
 *     must be preserved.
 *     Return an array of the k digits representing the answer.
 *
 * [中文] 題目: 建立最大數
 * [中文] 題目說明:
 *     給定兩個數字陣列 nums1、nums2 與長度 k，請從兩陣列挑出
 *     共 k 個數字組成字典序最大的數字。從同一陣列選出的數字必須維持原本
 *     相對順序。
 *
 * [中文] 思路:
 *     枚舉從兩陣列各取幾位，透過預先記錄右方較大數字的位置來挑出每一側的最
 *     大子序列。再以剩餘後綴的字典序比較合併兩序列，並保留所有分配中最大的
 *     候選答案。
 *
 * Examples:
 *     Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
 *     Output: [9,8,6,5,3]
 *     Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
 *     Output: [6,7,6,0,4]
 *     Input: nums1 = [3,9], nums2 = [8,9], k = 3
 *     Output: [9,8,9]
 *
 * Constraints:
 *   - m == nums1.length
 *   - n == nums2.length
 *   - 1 <= m, n <= 500
 *   - 0 <= nums1[i], nums2[i] <= 9
 *   - 1 <= k <= m + n
 *   - nums1 and nums2 do not have leading zeros.
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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int *a;
int *b;
int *result;
int *cur;
int **rightfirst1;
int **rightfirst2;

void getrightfirst(int *num, int size, int **arr) {
    int i, j;
    for (i = size-1; i >= 0; i--)
    {
        arr[i] = (int*)malloc(sizeof(int)*10);
        for (j = 0; j < 10; j++)
        {
            if (i == size-1)
            {
                arr[i][j] = size;
            }
            else
            {
                arr[i][j] = arr[i+1][j];
            }
        }
        if (i < size-1)
        {
            arr[i][num[i+1]] = i+1;
        }
    }
}

void select_(int *src, int **mem, int size, int *dest, int destsize) {
    int i = 0, j, k = 0;
    while (k < destsize)
    {
        bool jmp = false;
        for (j = 9; j > src[i]; j--)
        {
            if (mem[i][j] != size && size-mem[i][j]+k >= destsize)
            {
                i = mem[i][j];
                jmp = true;
                break;
            }
        }
        if (!jmp)
        {
            dest[k++] = src[i++];
        }
    }
}

int cmp(int *arr1, int *arr2, int size1, int size2, int i1, int i2) {
    while (i1 < size1 && i2 < size2 && arr1[i1] == arr2[i2])
    {
        i1++;
        i2++;
    }
    if (i1 == size1) return -1;
    if (i2 == size2) return 1;
    if (arr1[i1] > arr2[i2]) return 1;
    return -1;
}

int* maxNumber(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize) {
    *returnSize = k;
    if (!k)
    {
        return NULL;
    }
    a = (int*)malloc(sizeof(int)*nums1Size);
    b = (int*)malloc(sizeof(int)*nums2Size);
    int i, j, l;
    result = (int*)malloc(sizeof(int)*k);
    cur = (int*)malloc(sizeof(int)*k);
    rightfirst1 = (int**)malloc(sizeof(int*)*nums1Size);
    rightfirst2 = (int**)malloc(sizeof(int*)*nums2Size);
    getrightfirst(nums1, nums1Size, rightfirst1);
    getrightfirst(nums2, nums2Size, rightfirst2);
    for (i = 0; i < k; i++)
    {
        result[i] = 0;
    }
    int minselect = k-nums2Size;
    if (minselect < 0) minselect = 0;
    for (i = minselect; i <= k && i <= nums1Size; i++)
    {
        if (k-i < 0) break;
        select_(nums1, rightfirst1, nums1Size, a, i);
        select_(nums2, rightfirst2, nums2Size, b, k-i);
        int i1 = 0, i2 = 0;
        bool eql = true;
        for (j = 0; j < k; j++)
        {
            if (cmp(a, b, i, k-i, i1, i2) == 1)
            {
                cur[j] = a[i1++];
            }
            else
            {
                cur[j] = b[i2++];
            }
            if (eql && cur[j] != result[j])
            {
                eql = false;
                if (cur[j] < result[j])
                {
                    break;
                }
            }
            if (!eql)
            {
                result[j] = cur[j];
            }
        }
    }
    return result;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int arr0_0[] = {3,4,6,5};
  static int arr0_2[] = {9,1,2,5,8,3};
  int *act_0 = maxNumber(arr0_0, 4,arr0_2, 6,(5),&rsz_0);
  static const int exp_0[] = {3,5,6,8,9};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 5))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int arr1_0[] = {6,7};
  static int arr1_2[] = {6,0,4};
  int *act_1 = maxNumber(arr1_0, 2,arr1_2, 3,(5),&rsz_1);
  static const int exp_1[] = {0,4,6,6,7};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 5))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  static int arr2_0[] = {3,9};
  static int arr2_2[] = {8,9};
  int *act_2 = maxNumber(arr2_0, 2,arr2_2, 2,(3),&rsz_2);
  static const int exp_2[] = {8,9,9};
  if (!(lc_eq_list_sorted(act_2, rsz_2, exp_2, 3))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 321, "maxNumber", ntests);
 return (pass&&ntests)?0:1;
}
