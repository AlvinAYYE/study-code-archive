/*
 * ==========================================================================
 * LeetCode 0044. Wildcard Matching
 * Difficulty: Hard
 * Tags: string, dynamic-programming, greedy, recursion
 * URL: https://leetcode.com/problems/wildcard-matching/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an input string (s) and a pattern (p), implement wildcard
 *     pattern matching with support for '?' and '*' where:
 *     The matching should cover the entire input string (not partial).
 *
 * [中文] 題目: 萬用字元匹配
 * [中文] 題目說明:
 *     給定輸入字串 s 與模式 p，請實作萬用字元完整匹配：'?' 可匹配任意
 *     單一字元，'*' 可匹配任意長度的字元序列（包含空字串）。匹配必須
 *     涵蓋整個 s，不能只比對其中一段。
 *
 * [中文] 範例：
 *   範例 1：輸入 s = "aa", p = "a"；輸出 false。
 *     說明：模式 "a" 無法匹配完整字串 "aa"。
 *   範例 2：輸入 s = "aa", p = "*"；輸出 true。
 *     說明：'*' 可以匹配任意字元序列。
 *   範例 3：輸入 s = "cb", p = "?a"；輸出 false。
 *     說明：'?' 能匹配 'c'，但模式中的 'a' 無法匹配字串中的 'b'。
 *
 * [中文] 限制：
 *   - 0 <= s.length, p.length <= 2000
 *   - s 僅包含小寫英文字母。
 *   - p 僅包含小寫英文字母、'?' 或 '*'。
 *
 * [中文] 直觀解題思路（目前啟用的遞迴版本）：
 *   1. 一般字元必須相同，'?' 則可配任何非結尾字元；匹配後兩個指標都前進。
 *   2. 遇到 '*' 時先略過連續星號，因為多個相鄰 '*' 與一個效果相同。
 *   3. 若 '*' 已是模式尾端，它可直接吞掉 s 的所有剩餘字元，回傳 true。
 *   4. 否則依序嘗試讓 '*' 吞掉 0、1、2……個字元；每個位置都遞迴比對
 *      剩餘模式，任一分支成功即為成功。
 *   5. 模式耗盡時，只有字串也同時耗盡才算完整匹配。
 *
 * 最壞時間為指數級，遞迴深度 O(|s|+|p|)；檔案亦保留雙指標與 DP 版本
 * 供比較，目前由 ALG == 1 選用遞迴版本。
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
44. Wildcard Matching

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a")   false
isMatch("aa","aa")   true
isMatch("aaa","aa")   false
isMatch("aa", "*")   true
isMatch("aa", "a*")   true
isMatch("ab", "?*")   true
isMatch("aab", "c*a*b")   false
*/

#define MATCH(A, B) ((A) == (B) || ((A) && (B) == '?'))
#define IDX(I, J) ((I + 1) * (plen + 1) + J + 1)

#define ALG 1

bool match_recursive(char *s, char *p, int *retry) {
    if (!*p) return (*s) ? 0 : 1;

    if (*p == '*') {
        /* 相鄰星號等價於單一星號，先合併可減少重複分支。 */
        do { p ++; } while (*p == '*');
        
        if (!*p) return 1;
        
        while (*s && *retry) {
            if (match_recursive(s, p, retry)) {
                return 1;
            }
            s ++;  /* 讓 '*' 多吞一個字元後重試 */
        }
        *retry = 0; /* s 已耗盡仍失敗，前層星號不必再嘗試更長匹配 */
        return 0;
    }
    
    if (!MATCH(*s, *p)) return 0;
    
    return match_recursive(s + 1, p + 1, retry);
}
bool match_2_pointers(char *s, char *p) {
    char *saved_s, *saved_p = NULL;

    while (*s) {
        if (*p == '*') {
            do { p ++; } while (*p == '*');
            
            if (!*p) return 1;
            
            saved_s = s + 1;    // save the next s pointer for retry with skipping one
            saved_p = p;        // save the next p pointer for retry with skipping one
            continue;
        }
        
        if (MATCH(*s, *p)) { s ++; p ++; continue; }
        
        if (saved_p) {
            s = saved_s ++;     // go back to previously saved s pointer
                                // and advance the saved pointer for continuously skipping one
            p = saved_p;        // go back to previously saved p pointer and retry 
            continue;
        }
        return 0;
    }
    
    while (*p == '*') p ++;
    
    return (*p) ? 0 : 1;
}
bool match_dp(char *s, char *p) {
    int slen = strlen(s);
    int plen = strlen(p);
    int *dp = calloc((slen + 1) * (plen + 1), sizeof(int));
    int i, j;
    dp[0] = 1;
    for (j = 0; j < plen; j ++) {
        if (p[j] == '*') {
            dp[IDX(-1, j)] = dp[IDX(-1, j - 1)];
        }
    }
    for (i = 0; i < slen; i ++) {
        for (j = 0; j < plen; j ++) {
            if (p[j] != '*') {
                // it is a match if current match and previous s & p are a match
                dp[IDX(i, j)] = MATCH(s[i], p[j]) && dp[IDX(i - 1, j - 1)];
            } else {
                dp[IDX(i, j)] = dp[IDX(i, j - 1)] ||    // '*' match empty
                                dp[IDX(i - 1, j)];      // '*' match as one or multiple of any
            }
        }
    }
    
    i = dp[IDX(slen - 1, plen - 1)];
    
    free(dp);
    
    return i;
}
bool isMatch(char* s, char* p) {
#if ALG == 1    // 8ms, 7M
    int retry = 1;
    return match_recursive(s, p, &retry);
#elif ALG == 2  // 8ms, 7M
    return match_2_pointers(s, p);
#else           // 48ms, 23M
    return match_dp(s, p);
#endif
}


/*
Difficulty:Hard
Total Accepted:97.7K
Total Submissions:487.4K


Companies Google Snapchat Two Sigma Facebook Twitter
Related Topics Dynamic Programming Backtracking Greedy String
Similar Questions 
                
                  
                    Regular Expression Matching
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
  char p_1[] = "*";
  bool act_1 = isMatch(s_1,p_1);
  if (!(act_1 == true)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char s_2[] = "cb";
  char p_2[] = "?a";
  bool act_2 = isMatch(s_2,p_2);
  if (!(act_2 == false)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 44, "isMatch", ntests);
 return (pass&&ntests)?0:1;
}
