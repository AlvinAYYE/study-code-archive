/*
 * ==========================================================================
 * LeetCode 0639. Decode Ways II
 * Difficulty: Hard
 * Tags: string, dynamic-programming
 * URL: https://leetcode.com/problems/decode-ways-ii/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     A message containing letters from A-Z can be encoded into numbers
 *     using the following mapping:
 *     To decode an encoded message, all the digits must be grouped then
 *     mapped back into letters using the reverse of the mapping above
 *     (there may be multiple ways). For example, "1110^6" can be mapped
 *     into:
 *     Note that the grouping (1 11 06) is invalid because "06" cannot be
 *     mapped into 'F' since "6" is different from "06".
 *     In addition to the mapping above, an encoded message may contain the
 *     '*' character, which can represent any digit from '1' to '9' ('0' is
 *     excluded). For example, the encoded message "1*" may represent any
 *     of the encoded messages "11", "12", "13", "14", "15", "16", "17",
 *     "18", or "19". Decoding "1*" is equivalent to decoding any of the
 *     encoded messages it can represent.
 *     Given a string s consisting of digits and '*' characters, return the
 *     number of ways to decode it.
 *     Since the answer may be very large, return it modulo 10^9 + 7.
 *
 * [中文] 題目: 解碼方法 II
 * [中文] 題目說明:
 *     字母 A 到 Z 分別可由 1 到 26 編碼，給定只含數字與 '*
 *     ' 的編碼字串，計算所有合法解碼方式。'*' 可代表 1 到 9 的
 *     任一數字，而前導 0 的編碼無效。答案可能很大，需對 10^9 + 
 *     7 取模。
 *
 * [中文] 思路:
 *     以常數空間的滾動動態規劃保存前兩個位置的解碼數。對目前字元分別處理 
 *     0、* 與一般數字，並依前一字元決定可形成的一位或兩位編碼數量。
 *
 * Examples:
 *     'A' -> "1"
 *     'B' -> "2"
 *     ...
 *     'Z' -> "26"
 *     Input: s = "*"
 *     Output: 9
 *     Explanation: The encoded message can represent any of the
 *     encoded messages "1", "2", "3", "4", "5", "6", "7", "8", or
 *     "9".
 *     Each of these can be decoded to the strings "A", "B", "C",
 *     "D", "E", "F", "G", "H", and "I" respectively.
 *     Hence, there are a total of 9 ways to decode "*".
 *     Input: s = "1*"
 *     Output: 18
 *     Explanation: The encoded message can represent any of the
 *     encoded messages "11", "12", "13", "14", "15", "16", "17",
 *     "18", or "19".
 *     Each of these encoded messages have 2 ways to be decoded (e.g.
 *     "11" can be decoded to "AA" or "K").
 *     Hence, there are a total of 9 * 2 = 18 ways to decode "1*".
 *     Input: s = "2*"
 *     Output: 15
 *     Explanation: The encoded message can represent any of the
 *     encoded messages "21", "22", "23", "24", "25", "26", "27",
 *     "28", or "29".
 *     "21", "22", "23", "24", "25", and "26" have 2 ways of being
 *     decoded, but "27", "28", and "29" only have 1 way.
 *     Hence, there are a total of (6 * 2) + (3 * 1) = 12 + 3 = 15
 *     ways to decode "2*".
 *
 * Constraints:
 *   - 1 <= s.length <= 10^5
 *   - s[i] is a digit or '*'.
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
639. Decode Ways II

A message containing letters from A-Z is being encoded to numbers using the following mapping way:


'A' -> 1
'B' -> 2
...
'Z' -> 26



Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.




Given the encoded message containing digits and the character '*', return the total number of ways to decode it.



Also, since the answer may be very large, you should return the output mod 109 + 7.


Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".



Example 2:
Input: "1*"
Output: 9 + 9 = 18



Note:

The length of the input string will fit in range [1, 105].
The input string will only contain the character '*' and digits '0' - '9'.
*/

#define MOD 1000000007
 
int numDecodings(char* s) {
    char p, t;
    long long a, b, c;
    
    p = '0';    // previous character
    a = 0;      // previous previous number
    b = 1;      // previous number
    c = 0;      // current number
    
    while (t = *(s ++)) {
        switch (t) {
            case '0':
                if (p == '*') {
                    c = a * 2;
                } else if (p != '1' && p != '2') {
                    return 0;
                } else {
                    c = a;
                }
                break;
            case '*':
                c = b * 9;
                if (p == '1') {
                    c += a * 9;
                } else if (p == '2') {
                    c += a * 6;
                } else if (p == '*') {
                    c += a * 15;
                }
                break;
            default:
                c = b;
                if (p == '*') {
                    if (t <= '6') {
                        c += a * 2;
                    } else {
                        c += a;
                    }
                } else if (p == '1' ||
                    (p == '2' && t >= '0' && t <= '6')) {
                    c += a;
                }
                break;
        }
        a = b % MOD;
        b = c % MOD;
        p = t;
    }
    
    return c % MOD;
}


/*
Difficulty:Hard
Total Accepted:5.3K
Total Submissions:22.3K


Companies Facebook
Related Topics Dynamic Programming
Similar Questions 
                
                  
                    Decode Ways
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "*";
  long long act_0 = (long long)numDecodings(s_0);
  if (!(act_0 == 9LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = "1*";
  long long act_1 = (long long)numDecodings(s_1);
  if (!(act_1 == 18LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char s_2[] = "2*";
  long long act_2 = (long long)numDecodings(s_2);
  if (!(act_2 == 15LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 639, "numDecodings", ntests);
 return (pass&&ntests)?0:1;
}
