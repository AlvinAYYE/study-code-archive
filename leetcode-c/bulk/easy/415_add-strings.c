/*
 * ==========================================================================
 * LeetCode 0415. Add Strings
 * Difficulty: Easy
 * Tags: math, string, simulation
 * URL: https://leetcode.com/problems/add-strings/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given two non-negative integers, num1 and num2 represented as
 *     string, return the sum of num1 and num2 as a string.
 *     You must solve the problem without using any built-in library for
 *     handling large integers (such as BigInteger). You must also not
 *     convert the inputs to integers directly.
 *
 * [中文] 題目: 字串相加
 * [中文] 題目說明:
 *     給定兩個以字串表示的非負整數 num1 與 num2，回傳其和的字串
 *     。輸入只含數字且除數值 0 外沒有前導零；不得使用大整數函式庫，也不
 *     可直接將輸入轉成整數。
 *
 * [中文] 思路:
 *     由兩個字串末端向前逐位相加，連同進位寫入由尾端填入的緩衝區。最後視是
 *     否仍有進位，回傳完整緩衝區或其有效的後段。
 *
 * Examples:
 *     Input: num1 = "11", num2 = "123"
 *     Output: "134"
 *     Input: num1 = "456", num2 = "77"
 *     Output: "533"
 *     Input: num1 = "0", num2 = "0"
 *     Output: "0"
 *
 * Constraints:
 *   - 1 <= num1.length, num2.length <= 10^4
 *   - num1 and num2 consist of only digits.
 *   - num1 and num2 don't have any leading zeros except for the zero
 *   itself.
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
/* 解題說明
 * 題目：415. Add Strings（字串相加）
 *
 * 題意完整翻譯：
 *     給定以字串表示的兩個非負整數 num1 與
 *     num2，請回傳它們相加後的字串。不可直接將輸入轉成整數，也不可使用大整數函式庫；請像直式加法一樣逐位計算。
 *
 * 範例：
 *   輸入：num1 = "11", num2 = "123"
 *   輸出："134"
 *   說明：11 + 123 = 134。
 *   輸入：num1 = "456", num2 = "77"
 *   輸出："533"
 *   說明：從右向左逐位相加並處理進位，結果為 533。
 *   輸入：num1 = "0", num2 = "0"
 *   輸出："0"
 *   說明：兩個零相加仍是字串 0。
 *
 * 限制：
 *   - 1 <= num1.length, num2.length <= 10^4
 *   - num1 與 num2 只含數字
 *   - 除了字串 0 本身，輸入沒有前導零
 *
 * 解題步驟：
 *   1. 配置可容納較長輸入長度加一位的結果緩衝區，並從兩字串最右端開始。
 *   2. 逐位將兩個數字與 carry 相加；目前位寫入總和除以 10 的餘數，carry 更新為總和除以 10。
 *   3. 其中一個字串用完後，把缺少的位數當成 0；直到兩個字串都用完且 carry 為 0。
 *   4. 結果目前是倒著寫入，將有效部分移到緩衝區開頭並回傳。
 *
 * 複雜度：
 *   時間：O(max(m,n))，逐位處理兩個字串。
 *   空間：O(max(m,n))，結果字串需要額外儲存。
 */

char* addStrings(char* num1, char* num2) {
    int length1 = (int)strlen(num1);
    int length2 = (int)strlen(num2);
    int maxLength = length1 > length2 ? length1 : length2;
    char* answer = (char*)malloc((size_t)maxLength + 2);
    int i = length1 - 1;
    int j = length2 - 1;
    int position = maxLength;
    int carry = 0;

    answer[maxLength + 1] = '\0';

    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        answer[position] = (char)('0' + sum % 10);
        carry = sum / 10;
        --position;
        --i;
        --j;
    }

    // 有效答案從 position + 1 開始，將它連同結尾字元移到字串開頭。
    memmove(answer, answer + position + 1, (size_t)(maxLength - position + 1));
    return answer;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char num1_0[] = "11";
  char num2_0[] = "123";
  char *act_0 = addStrings(num1_0,num2_0);
  if (!(strcmp(act_0, "134") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char num1_1[] = "456";
  char num2_1[] = "77";
  char *act_1 = addStrings(num1_1,num2_1);
  if (!(strcmp(act_1, "533") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char num1_2[] = "0";
  char num2_2[] = "0";
  char *act_2 = addStrings(num1_2,num2_2);
  if (!(strcmp(act_2, "0") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 415, "addStrings", ntests);
 return (pass&&ntests)?0:1;
}
