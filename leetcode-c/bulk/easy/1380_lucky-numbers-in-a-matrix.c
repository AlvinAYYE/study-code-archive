/*
 * ==========================================================================
 * LeetCode 1380. Lucky Numbers in a Matrix
 * Difficulty: Easy
 * Tags: array, matrix
 * URL: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
 * Source: community solution, repo akib-islam-coder_leetcodesolutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an m x n matrix of distinct numbers, return all lucky numbers
 *     in the matrix in any order.
 *     A lucky number is an element of the matrix such that it is the
 *     minimum element in its row and maximum in its column.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     Given an m x n 矩陣 of 不重複 numbers, 回傳 all lucky numbers in the 矩陣
 *     （順序不限）.
 *
 * Examples:
 *     Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
 *     Output: [15]
 *     Explanation: 15 is the only lucky number since it is the
 *     minimum in its row and the maximum in its column.
 *     Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
 *     Output: [12]
 *     Explanation: 12 is the only lucky number since it is the
 *     minimum in its row and the maximum in its column.
 *     Input: matrix = [[7,8],[1,2]]
 *     Output: [7]
 *     Explanation: 7 is the only lucky number since it is the
 *     minimum in its row and the maximum in its column.
 *
 * Constraints:
 *   - m == mat.length
 *   - n == mat[i].length
 *   - 1 <= n, m <= 50
 *   - 1 <= matrix[i][j] <= 10^5.
 *   - All elements in the matrix are distinct.
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
void merge(int arr[], int low, int mid, int high)
{
    int * ret_arr = (int *)malloc(sizeof(int) * (high-low+1));
    int ret_arr_index = 0;

    int i=0,j=0;
    for(i=low, j=mid+1; i<=mid && j<=high;)
    {
        if(arr[i] <= arr[j])
        {
            ret_arr[ret_arr_index++] = arr[i++];
        }
        else
        {
            ret_arr[ret_arr_index++] = arr[j++];
        }
    }

    while(i<=mid)
    {
        ret_arr[ret_arr_index++] = arr[i++];
    }

    while(j<=high)
    {
        ret_arr[ret_arr_index++] = arr[j++];
    }

    memcpy(&arr[low], ret_arr, sizeof(int)*(high-low+1));
    free(ret_arr);
}

void merge_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers (int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    
    int rows = 0, columns = 0;
    
    int min_row_element = INT_MAX;
    int max_column_element = INT_MIN;
    
    int * min_arr = (int *)malloc(sizeof(int) * matrixSize);
    int min_arr_index = 0;
    int i=0,j=0;
    for(i=0; i<matrixSize; i++)
    {
        min_row_element = INT_MAX;
        for(j=0; j<*matrixColSize; j++ )
        {
            if(matrix[i][j] <= min_row_element)
            {
                min_row_element = matrix[i][j];
            }
        }
        min_arr[min_arr_index++] = min_row_element;
    }
    
    
    int * max_arr = (int *)malloc(sizeof(int) * (*matrixColSize));
    int max_arr_index = 0;
    
    for(j=0; j<*matrixColSize; j++)
    {
        max_column_element = INT_MIN;
        for(i=0; i<matrixSize; i++)
        {
            if(matrix[i][j] >= max_column_element)
            {
                max_column_element = matrix[i][j];
            }
        }
        max_arr[max_arr_index++] = max_column_element;
    }
    
    
    //Sort both the arrays
    merge_sort(min_arr, 0, min_arr_index-1);
    merge_sort(max_arr, 0, max_arr_index-1);
    
    int * merge_arr = (int *)malloc(sizeof(int) * (min_arr_index + max_arr_index));
    memcpy(&merge_arr[0], min_arr, sizeof(int)*min_arr_index);
    memcpy(&merge_arr[min_arr_index], max_arr, sizeof(int)*max_arr_index);
    merge_sort(merge_arr, 0, min_arr_index + max_arr_index-1);
    
    int * ret_arr = (int *)malloc(sizeof(int)  * (min_arr_index + max_arr_index));
    int ret_arr_index = 0;
    int prev_element = merge_arr[0];
    //Find the duplicates and assign in the array
    for(i=1; i<min_arr_index + max_arr_index; i++)
    {
        if(merge_arr[i] == prev_element)
        {
            ret_arr[ret_arr_index++] = merge_arr[i];
        }
        prev_element = merge_arr[i];
    }
    
    free(min_arr);
    free(max_arr);
    free(merge_arr);
    
    *returnSize = ret_arr_index;
    return ret_arr;
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int mr0_0_0[] = {3,7,8};
  static int mr0_0_1[] = {9,11,13};
  static int mr0_0_2[] = {15,16,17};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2};
  static int mc0_0[] = {3,3,3};
  int *act_0 = luckyNumbers(mp0_0, 3,mc0_0,&rsz_0);
  static const int exp_0[] = {15};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 1))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int mr1_0_0[] = {1,10,4,2};
  static int mr1_0_1[] = {9,3,8,7};
  static int mr1_0_2[] = {15,16,17,12};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2};
  static int mc1_0[] = {4,4,4};
  int *act_1 = luckyNumbers(mp1_0, 3,mc1_0,&rsz_1);
  static const int exp_1[] = {12};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 1))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  static int mr2_0_0[] = {7,8};
  static int mr2_0_1[] = {1,2};
  static int *mp2_0[] = {mr2_0_0,mr2_0_1};
  static int mc2_0[] = {2,2};
  int *act_2 = luckyNumbers(mp2_0, 2,mc2_0,&rsz_2);
  static const int exp_2[] = {7};
  if (!(lc_eq_list_sorted(act_2, rsz_2, exp_2, 1))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1380, "luckyNumbers", ntests);
 return (pass&&ntests)?0:1;
}
