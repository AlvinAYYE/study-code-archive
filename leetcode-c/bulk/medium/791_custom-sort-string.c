/*
 * ==========================================================================
 * LeetCode 0791. Custom Sort String
 * Difficulty: Medium
 * Tags: hash-table, string, sorting
 * URL: https://leetcode.com/problems/custom-sort-string/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given two strings order and s. All the characters of order
 *     are unique and were sorted in some custom order previously.
 *     Permute the characters of s so that they match the order that order
 *     was sorted. More specifically, if a character x occurs before a
 *     character y in order, then x should occur before y in the permuted
 *     string.
 *     Return any permutation of s that satisfies this property.
 *
 * [中文] 題目: 自訂字串排序
 * [中文] 題目說明:
 *     給定字串 order 與 s，order 的字元皆互異並定義其先後順
 *     序。重新排列 s，讓凡是在 order 中 x 排在 y 前的字元，
 *     在結果中 x 也排在 y 前；可回傳任一合法排列。
 *
 * [中文] 思路:
 *     先統計 s 中各字母數量並記錄 order 指定的起始位置，將不在 
 *     order 的字元留在尾端，再依 order 的位置與次數填回前段。
 *
 * Examples:
 *     Input: order = "cba", s = "abcd"
 *     Output: "cbad"
 *     Explanation: "a" , "b" , "c" appear in order, so the order of
 *     "a" , "b" , "c" should be "c" , "b" , and "a" .
 *     Since "d" does not appear in order , it can be at any position
 *     in the returned string. "dcba" , "cdba" , "cbda" are also
 *     valid outputs.
 *     Input: order = "bcafg", s = "abcd"
 *     Output: "bcad"
 *     Explanation: The characters "b" , "c" , and "a" from order
 *     dictate the order for the characters in s . The character "d"
 *     in s does not appear in order , so its position is flexible.
 *     Following the order of appearance in order , "b" , "c" , and
 *     "a" from s should be arranged as "b" , "c" , "a" . "d" can be
 *     placed at any position since it's not in order. The output
 *     "bcad" correctly follows this rule. Other arrangements like
 *     "dbca" or "bcda" would also be valid, as long as "b" , "c" ,
 *     "a" maintain their order.
 *
 * Constraints:
 *   - 1 <= order.length <= 26
 *   - 1 <= s.length <= 200
 *   - order and s consist of lowercase English letters.
 *   - All the characters of order are unique.
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
/***

Approach: Hash

First, set up the hash table and sequence/duplicate information. Then, iterate
through the string 's' from the end and place characters that are not in the
'order' array into the hash table. Finally, for characters in the 'order' array,
place them at the beginning according to their sequence and duplicates.

***/

#define LOWERCASE_CH_NUM (26)
typedef struct {
    unsigned short seq : 8;
    unsigned short dup : 8;
} order_set_t;

char* customSortString(char* order, char* s) {
    char* s_set = calloc(LOWERCASE_CH_NUM, sizeof(char));
    for (int i = 0; s[i]; i++)
        s_set[s[i] - 'a'] += 1;

    order_set_t* order_set = calloc(LOWERCASE_CH_NUM, sizeof(order_set_t));
    int seq = 1;
    for (int i = 0; order[i]; i++) {
        int idx = order[i] - 'a';
        if (s_set[idx]) {
            order_set[idx].seq = seq;
            order_set[idx].dup = s_set[idx];
            seq += s_set[idx];
        }
    }

    int tail = strlen(s) - 1;
    for (int x = tail; x >= 0; x--) {
        if (!order_set[s[x] - 'a'].seq) {
            s[tail--] = s[x];
        }
    }

    for (int i = 0; i < LOWERCASE_CH_NUM; i++) {
        int pos = order_set[i].seq - 1;
        if (-1 != pos) {
            for (int j = 0; j < order_set[i].dup; j++)
                s[pos++] = 'a' + i;
        }
    }

    free(order_set);
    free(s_set);
    return s;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char order_0[] = "cba";
  char s_0[] = "abcd";
  char *act_0 = customSortString(order_0,s_0);
  if (!(strcmp(act_0, "cbad") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char order_1[] = "bcafg";
  char s_1[] = "abcd";
  char *act_1 = customSortString(order_1,s_1);
  if (!(strcmp(act_1, "bcad") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 791, "customSortString", ntests);
 return (pass&&ntests)?0:1;
}
