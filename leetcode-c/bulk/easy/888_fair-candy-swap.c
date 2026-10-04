/*
 * ==========================================================================
 * LeetCode 0888. Fair Candy Swap
 * Difficulty: Easy
 * Tags: array, hash-table, binary-search, sorting
 * URL: https://leetcode.com/problems/fair-candy-swap/
 * Source: community solution, repo akib-islam-coder_leetcodesolutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Alice and Bob have a different total number of candies. You are
 *     given two integer arrays aliceSizes and bobSizes where aliceSizes[i]
 *     is the number of candies of the ith box of candy that Alice has and
 *     bobSizes[j] is the number of candies of the jth box of candy that
 *     Bob has.
 *     Since they are friends, they would like to exchange one candy box
 *     each so that after the exchange, they both have the same total
 *     amount of candy. The total amount of candy a person has is the sum
 *     of the number of candies in each box they have.
 *     Return an integer array answer where answer[0] is the number of
 *     candies in the box that Alice must exchange, and answer[1] is the
 *     number of candies in the box that Bob must exchange. If there are
 *     multiple answers, you may return any one of them. It is guaranteed
 *     that at least one answer exists.
 *
 * [中文] 題目: 公平的糖果交換
 * [中文] 題目說明:
 *     Alice 與 Bob 分別持有若干糖果盒，兩人的糖果總數不同。兩人
 *     各交換一盒後必須使總數相等；回傳 Alice 應交出的盒子糖果數與 
 *     Bob 應交出的盒子糖果數，且保證至少有一組答案。
 *
 * [中文] 思路:
 *     程式先計算兩人的總和並以雜湊表記錄 Bob 擁有的盒子大小。接著逐一
 *     嘗試 Alice 交出的盒子，依交換後的總數差推得 Bob 應交出的
 *     大小，再以雜湊表查找。
 *
 * Examples:
 *     Input: aliceSizes = [1,1], bobSizes = [2,2]
 *     Output: [1,2]
 *     Input: aliceSizes = [1,2], bobSizes = [2,3]
 *     Output: [1,2]
 *     Input: aliceSizes = [2], bobSizes = [1,3]
 *     Output: [2,3]
 *
 * Constraints:
 *   - 1 <= aliceSizes.length, bobSizes.length <= 10^4
 *   - 1 <= aliceSizes[i], bobSizes[j] <= 10^5
 *   - Alice and Bob have a different total number of candies.
 *   - There will be at least one valid answer for the given input.
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
long alice_hashtable[200001] = {0};
long bob_hashtable[200001] = {0};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize)
{
    memset(alice_hashtable, 0x00, sizeof(alice_hashtable));
    memset(bob_hashtable, 0x00, sizeof(bob_hashtable));
    
    int alice_sum = 0;
    int bob_sum = 0;
    
    int i=0;
    for(i=0; i<aliceSizesSize; i++)
    {
        alice_hashtable[aliceSizes[i]] += 1;
        alice_sum += aliceSizes[i];
    }
    
    for(i=0; i<bobSizesSize; i++)
    {
        bob_hashtable[bobSizes[i]] += 1;
        bob_sum += bobSizes[i];
    }
    
    int * ret_arr = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    
    for(i=0; i<aliceSizesSize; i++)
    {
        alice_sum -= aliceSizes[i];
        bob_sum   += aliceSizes[i];
        
        if(bob_sum <= alice_sum)
        {
            alice_sum += aliceSizes[i];
            bob_sum -= aliceSizes[i];
            continue;
        }
        else
        {
            int diff = bob_sum - alice_sum;
            if(diff%2 != 0)
            {
                alice_sum += aliceSizes[i];
                bob_sum -= aliceSizes[i];
                continue; 
            }
            else
            {
                diff = (diff / 2);
                if(bob_hashtable[diff] > 0)
                {
                    ret_arr[0] = aliceSizes[i];
                    ret_arr[1] = diff;
                    break;
                }
                else
                {
                    alice_sum += aliceSizes[i];
                    bob_sum -= aliceSizes[i];
                    continue; 
                }
            }
        }
        
    }
    return ret_arr;
    
    
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int arr0_0[] = {1,1};
  static int arr0_2[] = {2,2};
  int *act_0 = fairCandySwap(arr0_0, 2,arr0_2, 2,&rsz_0);
  static const int exp_0[] = {1,2};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int arr1_0[] = {1,2};
  static int arr1_2[] = {2,3};
  int *act_1 = fairCandySwap(arr1_0, 2,arr1_2, 2,&rsz_1);
  static const int exp_1[] = {1,2};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 2))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  static int arr2_0[] = {2};
  static int arr2_2[] = {1,3};
  int *act_2 = fairCandySwap(arr2_0, 1,arr2_2, 2,&rsz_2);
  static const int exp_2[] = {2,3};
  if (!(lc_eq_list_sorted(act_2, rsz_2, exp_2, 2))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 888, "fairCandySwap", ntests);
 return (pass&&ntests)?0:1;
}
