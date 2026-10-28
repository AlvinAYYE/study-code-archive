/*
 * ==========================================================================
 * LeetCode 0010. Regular Expression Matching
 * Difficulty: Hard
 * Tags: string, dynamic-programming, recursion
 * URL: https://leetcode.com/problems/regular-expression-matching/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an input string s and a pattern p, implement regular
 *     expression matching with support for '.' and '*' where:
 *     The matching should cover the entire input string (not partial).
 *
 * [中文] 題目：正規表示式匹配
 * [中文] 題目說明：
 *     給定輸入字串 s 與模式 p，請實作支援 '.' 與 '*' 的完整匹配：
 *     '.' 可匹配任意單一字元，'*' 可讓它前面的元素出現零次或多次。
 *     匹配必須涵蓋整個輸入字串，不能只匹配其中一部分。
 *
 * [中文] 範例：
 *   範例 1：輸入 s = "aa", p = "a"；輸出 false。
 *     說明：模式 "a" 無法匹配完整字串 "aa"。
 *   範例 2：輸入 s = "aa", p = "a*"；輸出 true。
 *     說明：'*' 讓前面的 'a' 可重複多次，因此能匹配兩個 'a'。
 *   範例 3：輸入 s = "ab", p = ".*"；輸出 true。
 *     說明：'.' 可代表任意字元，'*' 再讓它出現零次或多次。
 *
 * [中文] 限制：
 *   - 1 <= s.length, p.length <= 20
 *   - s 僅包含小寫英文字母。
 *   - p 僅包含小寫英文字母、'.' 與 '*'。
 *   - 每個 '*' 前面都保證有一個可供它修飾的有效元素。
 *
 * [中文] 直觀解題思路：
 *   1. dp[i][j] 表示 s 的前 i 個字元能否被 p 的前 j 個字元完整匹配，
 *      空字串對空模式成立。
 *   2. 一般字元或 '.' 必須匹配目前字元，再承接左上角的前綴結果。
 *   3. 遇到 '*' 時，可把「前一元素 + *」視為出現零次；若前一元素能
 *      匹配目前字元，也可讓 '*' 再吃掉一個字元並停在同一模式位置。
 *   4. "a*b*" 這類模式能匹配空字串，因此需先初始化空字串那一列。
 *   5. 表格右下角就是整個 s 與 p 的答案。
 *
 * 複雜度：時間 O(|s||p|)，空間 O(|s||p|)。
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
10. Regular Expression Matching

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a")   false
isMatch("aa","aa")   true
isMatch("aaa","aa")   false
isMatch("aa", "a*")   true
isMatch("aa", ".*")   true
isMatch("ab", ".*")   true
isMatch("aab", "c*a*b")   true
*/

#define NOT_MATCH(A, B) (((B) == '.' && (A) == 0) || ((B) != '.' && (A) != (B)))
#define MATCH(A, B)     ((A) == (B) || (B) == '.')
#define IDX(I, J)       (((I) + 1) * (plen + 1) + (J) + 1)
 
bool match_recursive(char *s, char *p, int *retry) {
    if (*p == 0) return *s == 0;
    if (*(p + 1) == '*') {
        while (*retry) {
            if (match_recursive(s, p + 2, retry)) {
                return true;
            }
            if (NOT_MATCH(*s, *p)) {
                return false;
            }
            s ++;
        }
        *retry = 0;
        return false;
    }
    if (NOT_MATCH(*s, *p)) {
        return false;
    }
    return match_recursive(s + 1, p + 1, retry);
}
bool isMatch(char* s, char* p) {
#if 0  // 22ms
    int retry = 1;
    return match_recursive(s, p, &retry);
#else  // 9ms
    int *dp;
    int i, j;
    int slen, plen;
    
    slen = strlen(s);
    plen = strlen(p);
    
    dp = calloc((slen + 1) * (plen + 1), sizeof(int));
    //assert(dp);
 
    dp[0] = 1;  /* 空字串匹配空模式 */
    for (j = 0; j < plen; j ++) {
        if (p[j] == '*') {
            dp[IDX(-1, j)] = dp[IDX(-1, j - 2)];
        }
    }
    for (i = 0; i < slen; i++) {
        for (j = 0; j < plen; j++) {
            if (p[j] != '*') {
                dp[IDX(i, j)] = dp[IDX(i - 1, j - 1)] && MATCH(s[i], p[j]);
            } else {
                /* '*' 可令前一元素出現零次，或在字元相符時繼續重複。 */
                dp[IDX(i, j)] = dp[IDX(i, j - 2)] ||
                                dp[IDX(i, j - 1)] ||
                                (MATCH(s[i], p[j - 1]) && dp[IDX(i - 1, j)]);
            }
        }
    }
    
    i = dp[IDX(slen - 1, plen - 1)];
    
    free(dp);
    
    return i;
#endif
}


/*
Difficulty:Hard
Total Accepted:147.1K
Total Submissions:610.5K


Companies Google Uber Airbnb Facebook Twitter
Related Topics Dynamic Programming Backtracking String
Similar Questions 
                
                  
                    Wildcard Matching
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "aa";
  char p_0[] = "a";
  bool act_0 = isMatch(s_0,p_0);
  if (!(act_0 == false)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = "aa";
  char p_1[] = "a*";
  bool act_1 = isMatch(s_1,p_1);
  if (!(act_1 == true)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char s_2[] = "ab";
  char p_2[] = ".*";
  bool act_2 = isMatch(s_2,p_2);
  if (!(act_2 == true)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 10, "isMatch", ntests);
 return (pass&&ntests)?0:1;
}
