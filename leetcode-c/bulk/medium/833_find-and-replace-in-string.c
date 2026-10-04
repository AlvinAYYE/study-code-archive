/*
 * ==========================================================================
 * LeetCode 0833. Find And Replace in String
 * Difficulty: Medium
 * Tags: array, hash-table, string, sorting
 * URL: https://leetcode.com/problems/find-and-replace-in-string/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a 0-indexed string s that you must perform k
 *     replacement operations on. The replacement operations are given as
 *     three 0-indexed parallel arrays, indices, sources, and targets, all
 *     of length k.
 *     To complete the ith replacement operation:
 *     For example, if s = "abcd", indices[i] = 0, sources[i] = "ab", and
 *     targets[i] = "eee", then the result of this replacement will be
 *     "eeecd".
 *     All replacement operations must occur simultaneously, meaning the
 *     replacement operations should not affect the indexing of each other.
 *     The testcases will be generated such that the replacements will not
 *     overlap.
 *     Return the resulting string after performing all replacement
 *     operations on s.
 *     A substring is a contiguous sequence of characters in a string.
 *
 * [中文] 題目: 字串中的查找與替換
 * [中文] 題目說明:
 *     給定字串 s，以及長度相同的 indices、sources、tar
 *     gets 三個平行陣列，需執行多個替換操作。若 sources[i]
 *      恰好從 s 的 indices[i] 開始出現，便以 target
 *     s[i] 替換；所有替換必須同時進行，且測資保證替換區間不重疊。回傳
 *     替換後的字串。
 *
 * [中文] 思路:
 *     程式先依起始索引排序所有操作，再由左至右掃描原字串並建立結果緩衝區。
 *     每個索引處以字首比對確認 source 是否相符，只有相符時才附加 
 *     target 並跳過原片段。
 *
 * Examples:
 *     Input: s = "abcd", indices = [0, 2], sources = ["a", "cd"],
 *     targets = ["eee", "ffff"]
 *     Output: "eeebffff"
 *     Explanation:
 *     "a" occurs at index 0 in s, so we replace it with "eee".
 *     "cd" occurs at index 2 in s, so we replace it with "ffff".
 *     Input: s = "abcd", indices = [0, 2], sources = ["ab","ec"],
 *     targets = ["eee","ffff"]
 *     Output: "eeecd"
 *     Explanation:
 *     "ab" occurs at index 0 in s, so we replace it with "eee".
 *     "ec" does not occur at index 2 in s, so we do nothing.
 *
 * Constraints:
 *   - 1 <= s.length <= 1000
 *   - k == indices.length == sources.length == targets.length
 *   - 1 <= k <= 100
 *   - 0 <= indexes[i] < s.length
 *   - 1 <= sources[i].length, targets[i].length <= 50
 *   - s consists of only lowercase English letters.
 *   - sources[i] and targets[i] consist of only lowercase English
 *   letters.
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
833. Find And Replace in String

To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".


Example 2:

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee". 
"ec" doesn't starts at index 2 in the original S, so we do nothing.


Notes:


	0 <= indexes.length = sources.length = targets.length <= 100
	0 < indexes[i] < S.length <= 1000
	All characters in given inputs are lowercase letters.
*/

typedef struct {
    int i;
    char *s;
    char *t;
} e_t;
int cmp(const void *a, const void *b) {
    const e_t *e1 = a;
    const e_t *e2 = b;
    if (e1->i < e2->i) return -1;
    if (e1->i > e2->i) return 1;
    return 0;
}
char * findReplaceString(char * S, int* indexes, int indexesSize, char ** sources, int sourcesSize, char ** targets, int targetsSize){
    int sz, i, j, l, k;
    char *buff, *newbuff, *p, *o, *s, *t;
    
    e_t e[100];
    for (i = 0; i < indexesSize; i ++) {
        e[i].i = indexes[i];
        e[i].s = sources[i];
        e[i].t = targets[i];
    }
    
    qsort(e, indexesSize, sizeof(*e), cmp);
    
    sz = 1000;
    buff = malloc(sz * sizeof(char));
    //assert(buff);
    
    o = S;
    p = buff;
    p[0] = 0;
    
    for (i = 0; i < indexesSize; i ++) {
        j = e[i].i;
        l = j - (o - S);
        if (l > 0) {
            if (p - buff + l >= sz) {
                sz *= 2;
                newbuff = realloc(buff, sz * sizeof(char));
                //assert(newbuff);
                p = &newbuff[p - buff];
                buff = newbuff;
            }
            strncpy(p, o, l);
            o += l;
            p += l;
            p[0] = 0;   // add null
        }
        s = e[i].s;
        l = strlen(s);
        t = e[i].t;
        if (!strncmp(o, s, l)) {
            k = strlen(t);
            if (p - buff + k >= sz) {
                sz *= 2;
                newbuff = realloc(buff, sz * sizeof(char));
                //assert(newbuff);
                p = &newbuff[p - buff];
                buff = newbuff;
            }
            strcat(p, t);
            o += l;
            p += k;
        }
    }
    
    l = strlen(S) - (o - S);
    if (l > 0) {
        if (p - buff + l >= sz) {
            sz *= 2;
            newbuff = realloc(buff, sz * sizeof(char));
            //assert(newbuff);
            p = &newbuff[p - buff];
            buff = newbuff;
        }
        strcat(p, o);
    }
    
    return buff;
}


/*
Difficulty:Medium


*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "abcd";
  static int arr0_1[] = {0,2};
  static char *sa0_3[] = {"a","cd"};
  static char *sa0_5[] = {"eee","ffff"};
  char *act_0 = findReplaceString(s_0,arr0_1, 2,sa0_3, 2,sa0_5, 2);
  if (!(strcmp(act_0, "eeebffff") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = "abcd";
  static int arr1_1[] = {0,2};
  static char *sa1_3[] = {"ab","ec"};
  static char *sa1_5[] = {"eee","ffff"};
  char *act_1 = findReplaceString(s_1,arr1_1, 2,sa1_3, 2,sa1_5, 2);
  if (!(strcmp(act_1, "eeecd") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 833, "findReplaceString", ntests);
 return (pass&&ntests)?0:1;
}
