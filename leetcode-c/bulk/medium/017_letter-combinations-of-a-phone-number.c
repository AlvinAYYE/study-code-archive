/*
 * ==========================================================================
 * LeetCode 0017. Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Tags: hash-table, string, backtracking
 * URL: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given a string containing digits from 2-9 inclusive, return all
 *     possible letter combinations that the number could represent. Return
 *     the answer in any order.
 *     A mapping of digits to letters (just like on the telephone buttons)
 *     is given below. Note that 1 does not map to any letters.
 *
 * [中文] 題目：電話號碼的字母組合
 *     給定只含數字 2 到 9 的字串 digits，依傳統電話按鍵對應回傳所有可能
 *     的字母組合，順序不限。空字串的答案是空集合。
 *
 * [中文] 範例
 *   範例 1：輸入 digits = "23"，輸出
 *           ["ad","ae","af","bd","be","bf","cd","ce","cf"]。
 *   範例 2：輸入 digits = ""，輸出 []。
 *   範例 3：輸入 digits = "2"，輸出 ["a","b","c"]。
 *
 * [中文] 限制
 *   - 0 <= digits.length <= 4。
 *   - digits[i] 介於 '2' 到 '9'。
 *
 * [中文] 直觀解題思路
 *   1. 用表格保存每個按鍵對應的字母。
 *   2. 先將每一位可選數量相乘，配置剛好的答案指標陣列。
 *   3. 回溯逐位挑選字母；走到字串末端時複製目前組合。
 *   4. 返回上一層後改試下一個字母，直到列舉所有組合。
 *   若答案數為 M、字串長度為 n，時間與輸出空間皆為 O(M * n)，遞迴空間 O(n)。
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

/* 數字 2 到 9 對應電話按鍵上的字母。 */
static const char *PHONE_LETTERS[10] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

/* 每一層選一個字母，填完所有位置時保存一份完整答案。 */
static void buildLetterCombinations(const char *digits, int length, int position,
                                    char *buffer, char **answer, int *count) {
    const char *choices;
    int i;

    if (position == length) {
        answer[*count] = (char *)malloc((size_t)length + 1);
        memcpy(answer[*count], buffer, (size_t)length + 1);
        ++(*count);
        return;
    }

    choices = PHONE_LETTERS[digits[position] - '0'];
    for (i = 0; choices[i] != '\0'; ++i) {
        buffer[position] = choices[i];
        buildLetterCombinations(digits, length, position + 1,
                                buffer, answer, count);
    }
}

/* ---- 易讀解法：回溯枚舉每個按鍵的字母選擇 ---- */
char** letterCombinations(char* digits, int* returnSize) {
    int length = (int)strlen(digits);
    int total = 1;
    int count = 0;
    int i;
    char **answer;
    char buffer[5];

    *returnSize = 0;
    if (length == 0) return NULL;

    for (i = 0; i < length; ++i) {
        total *= (int)strlen(PHONE_LETTERS[digits[i] - '0']);
    }
    answer = (char **)malloc((size_t)total * sizeof(char *));
    buffer[length] = '\0';
    buildLetterCombinations(digits, length, 0, buffer, answer, &count);

    *returnSize = count;
    return answer;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  char digits_0[] = "23";
  char **act_0 = letterCombinations(digits_0,&rsz_0);
  static char *cexp_0[] = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 9))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  char digits_1[] = "";
  char **act_1 = letterCombinations(digits_1,&rsz_1);
  static char *cexp_1[] = {""};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 0))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  char digits_2[] = "2";
  char **act_2 = letterCombinations(digits_2,&rsz_2);
  static char *cexp_2[] = {"a","b","c"};
  if (!(lc_eq_cands(act_2, rsz_2, cexp_2, 3))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 17, "letterCombinations", ntests);
 return (pass&&ntests)?0:1;
}
