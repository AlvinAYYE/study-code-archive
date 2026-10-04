/*
 * ==========================================================================
 * LeetCode 0563. Binary Tree Tilt
 * Difficulty: Easy
 * Tags: tree, depth-first-search, binary-tree
 * URL: https://leetcode.com/problems/binary-tree-tilt/
 * Source: community solution, repo akib-islam-coder_leetcodesolutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given the root of a binary tree, return the sum of every tree node's
 *     tilt.
 *     The tilt of a tree node is the absolute difference between the sum
 *     of all left subtree node values and all right subtree node values.
 *     If a node does not have a left child, then the sum of the left
 *     subtree node values is treated as 0. The rule is similar if the node
 *     does not have a right child.
 *
 * [中文] 題目: 二元樹的坡度
 * [中文] 題目說明:
 *     二元樹節點的坡度，是其左右子樹所有節點值總和之差的絕對值；不存在的子
 *     樹總和視為 0。給定根節點，回傳全樹所有節點坡度的總和。
 *
 * [中文] 思路:
 *     以後序遞迴取得左右子樹總和，將兩者的絕對差累加到總坡度，並向上回傳包
 *     含目前節點的子樹總和。
 *
 * Examples:
 *     Input: root = [1,2,3]
 *     Output: 1
 *     Explanation:
 *     Tilt of node 2 : |0-0| = 0 (no children)
 *     Tilt of node 3 : |0-0| = 0 (no children)
 *     Tilt of node 1 : |2-3| = 1 (left subtree is just left child,
 *     so sum is 2; right subtree is just right child, so sum is 3)
 *     Sum of every tilt : 0 + 0 + 1 = 1
 *     Input: root = [4,2,9,3,5,null,7]
 *     Output: 15
 *     Explanation:
 *     Tilt of node 3 : |0-0| = 0 (no children)
 *     Tilt of node 5 : |0-0| = 0 (no children)
 *     Tilt of node 7 : |0-0| = 0 (no children)
 *     Tilt of node 2 : |3-5| = 2 (left subtree is just left child,
 *     so sum is 3; right subtree is just right child, so sum is 5)
 *     Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right
 *     subtree is just right child, so sum is 7)
 *     Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree
 *     values are 3, 5, and 2, which sums to 10; right subtree values
 *     are 9 and 7, which sums to 16)
 *     Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15
 *     Input: root = [21,7,14,1,1,2,2,3,3]
 *     Output: 9
 *
 * Constraints:
 *   - The number of nodes in the tree is in the range [0, 10^4].
 *   - -1000 <= Node.val <= 1000
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
 * Definition for a binary tree node.
 * 
 */

int find(struct TreeNode * root, int * total_sum)
{
        
    if(root == NULL)
        return 0;
    
    if((root->left == NULL) && (root->right == NULL))  //Leaf Node
    {
       return root->val; 
    }
    
    int left_sum = find(root->left, total_sum);
    int right_sum = find(root->right, total_sum);
    
    int diff = left_sum - right_sum;
    if(diff < 0)
    {
        diff *= -1;
    }
    
    *total_sum += diff;
    return (left_sum + right_sum + root->val);
}


int findTilt(struct TreeNode* root)
{
    int total_sum = 0;
    
    find(root, &total_sum);
    return total_sum;

        
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static const int tk0_0[] = {1,2,3};
  long long act_0 = (long long)findTilt(lc_mktree(tk0_0, 3));
  if (!(act_0 == 1LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static const int tk1_0[] = {4,2,9,3,5,-2147483400,7};
  long long act_1 = (long long)findTilt(lc_mktree(tk1_0, 7));
  if (!(act_1 == 15LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static const int tk2_0[] = {21,7,14,1,1,2,2,3,3};
  long long act_2 = (long long)findTilt(lc_mktree(tk2_0, 9));
  if (!(act_2 == 9LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 563, "findTilt", ntests);
 return (pass&&ntests)?0:1;
}
