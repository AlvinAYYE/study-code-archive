/*
 * ==========================================================================
 * LeetCode 0748. Shortest Completing Word
 * Difficulty: Easy
 * Tags: array, hash-table, string
 * URL: https://leetcode.com/problems/shortest-completing-word/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given a string licensePlate and an array of strings words, find the
 *     shortest completing word in words.
 *     A completing word is a word that contains all the letters in
 *     licensePlate. Ignore numbers and spaces in licensePlate, and treat
 *     letters as case insensitive. If a letter appears more than once in
 *     licensePlate, then it must appear in the word the same number of
 *     times or more.
 *     For example, if licensePlate = "aBc 12c", then it contains letters
 *     'a', 'b' (ignoring case), and 'c' twice. Possible completing words
 *     are "abccdef", "caaacab", and "cbca".
 *     Return the shortest completing word in words. It is guaranteed an
 *     answer exists. If there are multiple shortest completing words,
 *     return the first one that occurs in words.
 *
 * [中文] 題目: 最短補全單詞
 * [中文] 題目說明:
 *     給定車牌字串 licensePlate 與單詞陣列 words，找出
 *     包含車牌所有字母的最短補全單詞；車牌中的數字與空白忽略，字母不分大小
 *     寫且重複次數必須滿足。若最短答案有多個，回傳 words 中最先出現
 *     者，且保證存在答案。
 *
 * [中文] 思路:
 *     先統計車牌所需的 26 個字母次數，再逐一掃描單詞，用暫存計數扣除已
 *     匹配的字母。程式優先保留匹配需求最多且長度較短的候選；因答案保證存在
 *     ，最終即為最短完整補全詞。
 *
 * Examples:
 *     Input: licensePlate = "1s3 PSt", words =
 *     ["step","steps","stripe","stepple"]
 *     Output: "steps"
 *     Explanation: licensePlate contains letters 's', 'p', 's'
 *     (ignoring case), and 't'.
 *     "step" contains 't' and 'p', but only contains 1 's'.
 *     "steps" contains 't', 'p', and both 's' characters.
 *     "stripe" is missing an 's'.
 *     "stepple" is missing an 's'.
 *     Since "steps" is the only word containing all the letters,
 *     that is the answer.
 *     Input: licensePlate = "1s3 456", words =
 *     ["looks","pest","stew","show"]
 *     Output: "pest"
 *     Explanation: licensePlate only contains the letter 's'. All
 *     the words contain 's', but among these "pest", "stew", and
 *     "show" are shortest. The answer is "pest" because it is the
 *     word that appears earliest of the 3.
 *
 * Constraints:
 *   - 1 <= licensePlate.length <= 7
 *   - licensePlate contains digits, letters (uppercase or
 *   lowercase), or space ' '.
 *   - 1 <= words.length <= 1000
 *   - 1 <= words[i].length <= 15
 *   - words[i] consists of lower case English letters.
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
typedef struct __data {
    int idx;
    int match;
    int len;
} DATA;

char *shortestCompletingWord(char *licensePlate, char **words, int words_sz)
{
    int set[26] = {0};
    char *cur = licensePlate;
    while (*cur) {
        if (*cur >= 'A' && *cur <= 'Z') {
            set[*cur - 'A'] += 1;
        } else if (*cur >= 'a' && *cur <= 'z') {
            set[*cur - 'a'] += 1;
        }
        cur++;
    }

    DATA ret;
    ret.match = 0;
    ret.len = 0;
    for (int i = 0; i < words_sz; i++) {
        int tmp[26] = {0}, match = 0, cur_len = 0;
        memcpy(tmp, set, sizeof(int) * 26);
        cur = words[i];
        while (*cur) {
            int idx = -1;
            if (*cur >= 'A' && *cur <= 'Z') {
                idx = *cur - 'A';
            } else if (*cur >= 'a' && *cur <= 'z') {
                idx = *cur - 'a';
            }

            if (idx != -1 && tmp[idx] > 0) {
                tmp[idx] -= 1;
                match++;
            }
            cur++;
            cur_len++;
        }

        if ((match > ret.match) || (match == ret.match && ret.len > cur_len)) {
            ret.idx = i;
            ret.match = match;
            ret.len = cur_len;
        }
    }

    return words[ret.idx];
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char licensePlate_0[] = "1s3 PSt";
  static char *sa0_1[] = {"step","steps","stripe","stepple"};
  char *act_0 = shortestCompletingWord(licensePlate_0,sa0_1, 4);
  if (!(strcmp(act_0, "steps") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char licensePlate_1[] = "1s3 456";
  static char *sa1_1[] = {"looks","pest","stew","show"};
  char *act_1 = shortestCompletingWord(licensePlate_1,sa1_1, 4);
  if (!(strcmp(act_1, "pest") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 748, "shortestCompletingWord", ntests);
 return (pass&&ntests)?0:1;
}
