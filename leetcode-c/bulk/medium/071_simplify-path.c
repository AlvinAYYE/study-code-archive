/*
 * ==========================================================================
 * LeetCode 0071. Simplify Path
 * Difficulty: Medium
 * Tags: string, stack
 * URL: https://leetcode.com/problems/simplify-path/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an absolute path for a Unix-style file system, which
 *     always begins with a slash '/'. Your task is to transform this
 *     absolute path into its simplified canonical path.
 *     The rules of a Unix-style file system are as follows:
 *     The simplified canonical path should follow these rules:
 *     Return the simplified canonical path.
 *
 * [中文] 題目: 簡化路徑
 * [中文] 題目說明:
 *     給定一個以「/」開頭的有效 Unix 絕對路徑，將它化為規範路徑。連
 *     續斜線視為一個，單一「.」表示目前目錄，雙點「..」回到上一層且不得
 *     越過根目錄；其他名稱皆視為一般目錄。結果必須以單一「/」開頭，根目錄
 *     外不可有結尾斜線。
 *
 * [中文] 思路:
 *     以斜線切分路徑並用堆疊保存目錄名稱，遇到「..」便彈出、遇到「.」略
 *     過。最後反轉堆疊並以斜線重新串成結果。
 *
 * Examples:
 *     Input: path = "/home/"
 *     Output: "/home"
 *     Explanation:
 *     The trailing slash should be removed.
 *     Input: path = "/home//foo/"
 *     Output: "/home/foo"
 *     Explanation:
 *     Multiple consecutive slashes are replaced by a single one.
 *     Input: path = "/home/user/Documents/../Pictures"
 *     Output: "/home/user/Pictures"
 *     Explanation:
 *     A double period ".." refers to the directory up a level (the
 *     parent directory).
 *     Input: path = "/../"
 *     Output: "/"
 *     Explanation:
 *     Going one level up from the root directory is not possible.
 *     Input: path = "/.../a/../b/c/../d/./"
 *     Output: "/.../b/d"
 *     Explanation:
 *     "..." is a valid name for a directory in this problem.
 *
 * Constraints:
 *   - 1 <= path.length <= 3000
 *   - path consists of English letters, digits, period '.', slash
 *   '/' or '_'.
 *   - path is a valid absolute Unix path.
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
typedef struct linked_list
{
    char *str;
    struct linked_list *next;
} linked_list_t;

typedef struct
{
    linked_list_t top;
} stack_t;

stack_t* stack_init()
{
    stack_t *s = malloc(sizeof(stack_t));
    (s->top).next = NULL;
    return s;
}

void stack_deinit(stack_t *s)
{
    linked_list_t *root = (s->top).next, *tmp;
    while (root) {
        tmp = root->next;
        free(root->str);
        free(root);
        root = tmp;
    }
    free(s);
}

bool stack_is_empty(stack_t *s)
{
    return ((s->top).next == NULL);
}

void stack_push(stack_t *s, char *target, int target_len)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));
    node->str = calloc(target_len + 1, sizeof(char));
    strncpy(node->str, target, target_len);
    node->next = s->top.next;
    s->top.next = node;
}

void stack_pop(stack_t *s)
{
    if (stack_is_empty(s))
        return;

    linked_list_t *tmp_next = (s->top.next)->next;
    free((s->top.next)->str);
    free(s->top.next);
    s->top.next = tmp_next;
}

void reverse(stack_t *s)
{
    linked_list_t *root = s->top.next, *prev = NULL;
    while (root) {
        linked_list_t *tmp_next = root->next;
        root->next = prev;
        prev = root;
        root = tmp_next;
    }
    s->top.next = prev;
}

char * simplifyPath(char * path)
{
    int len = strlen(path);
    if (!len)
        return path;

    stack_t *s = stack_init();

    char *tmp = NULL, *token = NULL, *delim = "/";
    tmp = calloc(len + 1, sizeof(char)); 
    strncpy(tmp, path, len);

    token = strtok(tmp, delim);
    while (token != NULL) {
        int token_len = strlen(token);
        if (token_len == 2 && !strcmp(token, "..")) {
            // Case: `..`
            stack_pop(s);
        } else if (token_len != 1 || strcmp(token, ".")) {
            // Case: general string which excludes `.`
            stack_push(s, token, token_len);
        }
        token = strtok(NULL, delim);
    }

    // Reverse to perform bottom-up path created
    reverse(s);

    // Prepare the result
    memset(path, 0, sizeof(char) * len);    
    if (stack_is_empty(s)) {
        strcat(path, delim);
    } else {
        linked_list_t *root = s->top.next;
        while (root)
        {
            strcat(path, delim);
            strcat(path, root->str);
            root =root->next;
        }
    }

    stack_deinit(s);
    return path;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char path_0[] = "/home/";
  char *act_0 = simplifyPath(path_0);
  if (!(strcmp(act_0, "/home") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char path_1[] = "/home//foo/";
  char *act_1 = simplifyPath(path_1);
  if (!(strcmp(act_1, "/home/foo") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char path_2[] = "/home/user/Documents/../Pictures";
  char *act_2 = simplifyPath(path_2);
  if (!(strcmp(act_2, "/home/user/Pictures") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
{
  char path_3[] = "/../";
  char *act_3 = simplifyPath(path_3);
  if (!(strcmp(act_3, "/") == 0)) { pass = 0; printf("  test 3 FAIL\n"); }
  ntests++; }
{
  char path_4[] = "/.../a/../b/c/../d/./";
  char *act_4 = simplifyPath(path_4);
  if (!(strcmp(act_4, "/.../b/d") == 0)) { pass = 0; printf("  test 4 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 71, "simplifyPath", ntests);
 return (pass&&ntests)?0:1;
}
