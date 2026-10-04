/*
 * ==========================================================================
 * LeetCode 0662. Maximum Width of Binary Tree
 * Difficulty: Medium
 * Tags: tree, depth-first-search, breadth-first-search, binary-tree
 * URL: https://leetcode.com/problems/maximum-width-of-binary-tree/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given the root of a binary tree, return the maximum width of the
 *     given tree.
 *     The maximum width of a tree is the maximum width among all levels.
 *     The width of one level is defined as the length between the
 *     end-nodes (the leftmost and rightmost non-null nodes), where the
 *     null nodes between the end-nodes that would be present in a complete
 *     binary tree extending down to that level are also counted into the
 *     length calculation.
 *     It is guaranteed that the answer will in the range of a 32-bit
 *     signed integer.
 *
 * [中文] 題目: 二叉樹的最大寬度
 * [中文] 題目說明:
 *     給定二叉樹，求所有層級中最大的寬度。某層寬度從最左與最右非空節點之間
 *     計算，並包含若將樹補成完全二叉樹時夾在中間的空節點位置。答案保證落在
 *      32 位元帶符號整數範圍內。
 *
 * [中文] 思路:
 *     以 BFS 佇列保存節點及其完全二叉樹位置索引，左、右子節點索引分別
 *     為 2i 與 2i+1。每層以首末索引之差加一更新最大寬度，單節點層
 *     會重設索引以降低溢位風險。
 *
 * Examples:
 *     Input: root = [1,3,2,5,3,null,9]
 *     Output: 4
 *     Explanation: The maximum width exists in the third level with
 *     length 4 (5,3,null,9).
 *     Input: root = [1,3,2,5,null,null,9,6,null,7]
 *     Output: 7
 *     Explanation: The maximum width exists in the fourth level with
 *     length 7 (6,null,null,null,null,null,7).
 *     Input: root = [1,3,2,5]
 *     Output: 2
 *     Explanation: The maximum width exists in the second level with
 *     length 2 (3,2).
 *
 * Constraints:
 *   - The number of nodes in the tree is in the range [1, 3000].
 *   - -100 <= Node.val <= 100
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

#define MAX(a, b) (a > b ? a : b)

typedef struct TreeNode NODE;
typedef struct __data {
    NODE *ptr;
    int idx;
} DATA;

typedef struct __queue {
    int size;
    int cur;
    int front;
    int rear;
    DATA *d;
} QUEUE;

static QUEUE *createq(int size)
{
    QUEUE *obj = malloc(sizeof(QUEUE));
    obj->size = size;
    obj->cur = 0;
    obj->front = 0;
    obj->rear = -1;
    obj->d = malloc(sizeof(DATA) * size);
    return obj;
}

static inline void destroyq(QUEUE *obj)
{
    free(obj->d);
    free(obj);
}

static inline int get_qsize(QUEUE *obj)
{
    return obj->cur;
}

static inline bool is_emptyq(QUEUE *obj)
{
    return (obj->cur == 0);
}

static inline void addq(QUEUE *obj, NODE *n, int idx)
{
    obj->rear = (obj->rear + 1) % obj->size;
    obj->d[obj->rear].ptr = n;
    obj->d[obj->rear].idx = idx;
    obj->cur++;
}

static inline DATA delq(QUEUE *obj)
{
    DATA ret = obj->d[obj->front];
    obj->front = (obj->front + 1) % obj->size;
    obj->cur--;
    return ret;
}

static int count_node(NODE *root)
{
    if (!root)
        return 0;
    return count_node(root->left) + count_node(root->right) + 1;
}

#define CHECK_CHILD(q, n, idx)              \
    {                                       \
        if (n->left)                        \
            addq(q, n->left, idx * 2);      \
        if (n->right)                       \
            addq(q, n->right, idx * 2 + 1); \
    }

int widthOfBinaryTree(struct TreeNode *root)
{
    int ret = 0;
    if (!root)
        goto out;

    QUEUE *q = createq(count_node(root));
    addq(q, root, 1);
    while (!is_emptyq(q)) {
        int cnt = get_qsize(q);
        DATA cur = delq(q);
        /* Reset the index if we only have one node in current level to avoid
         * int overflow problem */
        if (cnt == 1)
            cur.idx = 1;

        int start = cur.idx, end = start;
        CHECK_CHILD(q, cur.ptr, end);
        while (--cnt) {
            cur = delq(q);
            end = cur.idx;
            CHECK_CHILD(q, cur.ptr, end);
        }
        ret = MAX(ret, (end - start + 1));
    }

    destroyq(q);
out:
    return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static const int tk0_0[] = {1,3,2,5,3,-2147483400,9};
  long long act_0 = (long long)widthOfBinaryTree(lc_mktree(tk0_0, 7));
  if (!(act_0 == 4LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static const int tk1_0[] = {1,3,2,5,-2147483400,-2147483400,9,6,-2147483400,7};
  long long act_1 = (long long)widthOfBinaryTree(lc_mktree(tk1_0, 10));
  if (!(act_1 == 7LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static const int tk2_0[] = {1,3,2,5};
  long long act_2 = (long long)widthOfBinaryTree(lc_mktree(tk2_0, 4));
  if (!(act_2 == 2LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 662, "widthOfBinaryTree", ntests);
 return (pass&&ntests)?0:1;
}
