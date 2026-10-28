/*
 * ==========================================================================
 * LeetCode 0076. Minimum Window Substring
 * Difficulty: Hard
 * Tags: hash-table, string, sliding-window
 * URL: https://leetcode.com/problems/minimum-window-substring/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given two strings s and t of lengths m and n respectively, return
 *     the minimum window substring of s such that every character in t
 *     (including duplicates) is included in the window. If there is no
 *     such substring, return the empty string "".
 *     The testcases will be generated such that the answer is unique.
 *
 * [中文] 題目: 最小覆蓋子字串
 * [中文] 題目說明:
 *     給定長度分別為 m、n 的字串 s 與 t，找出 s 中最短的連續子字串，
 *     使它包含 t 的所有字元及各字元的需求次數。若不存在則回傳空字串 ""；
 *     測試資料保證最短答案唯一。
 *
 * [中文] 範例：
 *   範例 1：輸入 s = "ADOBECODEBANC", t = "ABC"；輸出 "BANC"。
 *     說明："BANC" 包含 A、B、C，且長度最短。
 *   範例 2：輸入 s = "a", t = "a"；輸出 "a"。
 *   範例 3：輸入 s = "a", t = "aa"；輸出 ""。
 *     說明：t 需要兩個 a，但 s 只有一個，因此不存在合法視窗。
 *
 * [中文] 限制：
 *   - m == s.length，n == t.length
 *   - 1 <= m, n <= 10^5
 *   - s 與 t 僅包含大寫及小寫英文字母。
 *
 * [中文] 直觀解題思路：
 *   1. cnt[c] 起初記錄 t 還需要幾個字元 c；n 記錄尚未滿足的字元總數。
 *   2. tail 向右擴張。若加入字元前 cnt[c] > 0，代表補到一個需求，n 減一；
 *      無論是否需要，都將 cnt[c] 減一以反映視窗內數量。
 *   3. n == 0 時視窗已涵蓋 t，持續右移 head 收縮並更新最短區間。
 *   4. 移出字元後 cnt[c] 加一；若變成正數，表示移掉必要字元，視窗失效，
 *      再回到擴張階段。
 *   5. 找到答案時在原字串的區間尾端寫入 '\0' 並回傳其起點；否則回傳 ""。
 *
 * head、tail 各走過 s 至多一次，時間 O(m+n)，固定計數表使額外空間 O(1)。
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
76. Minimum Window Substring

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).



For example,
S = "ADOBECODEBANC"
T = "ABC"


Minimum window is "BANC".



Note:
If there is no such window in S that covers all characters in T, return the empty string "".


If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

char* minWindow(char* s, char* t) {
    int n = 0, cnt[128] = { 0 };
    int head, tail, start, len = -1;
    char c, *p;
    
    if (!s || !*s || !t || !*t) return NULL;
    
    while (c = *(t ++)) {
        cnt[c] ++;
        n ++;   /* 尚未由視窗滿足的字元總數 */
    }
    
    head = tail = 0;
    while (c = s[tail ++]) {
        if (cnt[c] > 0) n --;  /* 此字元補到尚未滿足的需求 */
        cnt[c]--;              /* 負值表示視窗內有多餘字元 */
        
        while (n == 0) { /* 視窗有效時持續縮小左端 */
            if (len == -1 || len > tail - head) {
                start = head;
                len = tail - head;
            }
            c = s[head++];
            cnt[c]++;
            if (cnt[c] > 0) {
                n = 1;  // a valid character was pushed out of head, will find it back from tail
            }
        }
    }
    
    if (len != -1) {
        p = &s[start];
        p[len] = 0;
    } else {
        p = "";
    }
    
    return p;
}


/*
Difficulty:Hard
Total Accepted:108.4K
Total Submissions:428.3K


Companies LinkedIn Snapchat Uber Facebook
Related Topics Hash Table Two Pointers String
Similar Questions 
                
                  
                    Substring with Concatenation of All Words
                  
                    Minimum Size Subarray Sum
                  
                    Sliding Window Maximum
                  
                    Permutation in String
                  
                    Smallest Range
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "ADOBECODEBANC";
  char t_0[] = "ABC";
  char *act_0 = minWindow(s_0,t_0);
  if (!(strcmp(act_0, "BANC") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = "a";
  char t_1[] = "a";
  char *act_1 = minWindow(s_1,t_1);
  if (!(strcmp(act_1, "a") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char s_2[] = "a";
  char t_2[] = "aa";
  char *act_2 = minWindow(s_2,t_2);
  if (!(strcmp(act_2, "") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 76, "minWindow", ntests);
 return (pass&&ntests)?0:1;
}
