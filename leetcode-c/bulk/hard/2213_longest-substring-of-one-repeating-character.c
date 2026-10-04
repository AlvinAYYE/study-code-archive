/*
 * ==========================================================================
 * LeetCode 2213. Longest Substring of One Repeating Character
 * Difficulty: Hard
 * Tags: array, string, segment-tree, ordered-set
 * URL: https://leetcode.com/problems/longest-substring-of-one-repeating-character/
 * Source: community solution, repo kaushiknrk_leetcode-c-practice (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a 0-indexed string s. You are also given a 0-indexed
 *     string queryCharacters of length k and a 0-indexed array of integer
 *     indices queryIndices of length k, both of which are used to describe
 *     k queries.
 *     The ith query updates the character in s at index queryIndices[i] to
 *     the character queryCharacters[i].
 *     Return an array lengths of length k where lengths[i] is the length
 *     of the longest substring of s consisting of only one repeating
 *     character after the ith query is performed.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個從 0 開始索引的 字串 s. You are also given a 0-indexed 字串
 *     queryCharacters of length k and a 0-indexed 陣列 of 整數 下標 queryIndices
 *     of length k, both of which are used to describe k queries.
 *
 * Examples:
 *     Input: s = "babacc", queryCharacters = "bcb", queryIndices =
 *     [1,3,3]
 *     Output: [3,3,4]
 *     Explanation:
 *     - 1st query updates s = "bbbacc". The longest substring
 *     consisting of one repeating character is "bbb" with length 3.
 *     - 2nd query updates s = "bbbccc".
 *     The longest substring consisting of one repeating character
 *     can be "bbb" or "ccc" with length 3.
 *     - 3rd query updates s = "bbbbcc". The longest substring
 *     consisting of one repeating character is "bbbb" with length 4.
 *     Thus, we return [3,3,4].
 *     Input: s = "abyzz", queryCharacters = "aa", queryIndices =
 *     [2,1]
 *     Output: [2,3]
 *     Explanation:
 *     - 1st query updates s = "abazz". The longest substring
 *     consisting of one repeating character is "zz" with length 2.
 *     - 2nd query updates s = "aaazz". The longest substring
 *     consisting of one repeating character is "aaa" with length 3.
 *     Thus, we return [2,3].
 *
 * Constraints:
 *   - 1 <= s.length <= 10^5
 *   - s consists of lowercase English letters.
 *   - k == queryCharacters.length == queryIndices.length
 *   - 1 <= k <= 10^5
 *   - queryCharacters consists of lowercase English letters.
 *   - 0 <= queryIndices[i] < s.length
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int max_len;
    int pref_len;
    int suff_len;
    int total_len;
    char left_char;
    char right_char;
} Node;

Node tree[400005];

void merge(Node* parent, Node* left, Node* right) {
    parent->total_len = left->total_len + right->total_len;
    parent->left_char = left->left_char;
    parent->right_char = right->right_char;

    parent->pref_len = left->pref_len;
    if (left->pref_len == left->total_len && left->left_char == right->left_char) {
        parent->pref_len += right->pref_len;
    }

    parent->suff_len = right->suff_len;
    if (right->suff_len == right->total_len && right->right_char == left->right_char) {
        parent->suff_len += left->suff_len;
    }

    parent->max_len = MAX(left->max_len, right->max_len);
    if (left->right_char == right->left_char) {
        parent->max_len = MAX(parent->max_len, left->suff_len + right->pref_len);
    }
    parent->max_len = MAX(parent->max_len, MAX(parent->pref_len, parent->suff_len));
}

void build(int node, int start, int end, const char* s) {
    if (start == end) {
        tree[node].max_len = 1;
        tree[node].pref_len = 1;
        tree[node].suff_len = 1;
        tree[node].total_len = 1;
        tree[node].left_char = s[start];
        tree[node].right_char = s[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, s);
    build(2 * node + 1, mid + 1, end, s);
    merge(&tree[node], &tree[2 * node], &tree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, char val) {
    if (start == end) {
        tree[node].left_char = val;
        tree[node].right_char = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid) {
        update(2 * node, start, mid, idx, val);
    } else {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    merge(&tree[node], &tree[2 * node], &tree[2 * node + 1]);
}

int* longestRepeating(char* s, char* queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize) {
    int n = strlen(s);
    build(1, 0, n - 1, s);

    int* result = (int*)malloc(queryIndicesSize * sizeof(int));
    *returnSize = queryIndicesSize;

    for (int i = 0; i < queryIndicesSize; i++) {
        update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        result[i] = tree[1].max_len;
    }

    return result;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  char s_0[] = "babacc";
  char queryCharacters_0[] = "bcb";
  static int arr0_2[] = {1,3,3};
  int *act_0 = longestRepeating(s_0,queryCharacters_0,arr0_2, 3,&rsz_0);
  static const int exp_0[] = {3,3,4};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 3))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  char s_1[] = "abyzz";
  char queryCharacters_1[] = "aa";
  static int arr1_2[] = {2,1};
  int *act_1 = longestRepeating(s_1,queryCharacters_1,arr1_2, 2,&rsz_1);
  static const int exp_1[] = {2,3};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 2))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 2213, "longestRepeating", ntests);
 return (pass&&ntests)?0:1;
}
