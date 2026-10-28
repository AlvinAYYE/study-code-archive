/*
 * ==========================================================================
 * LeetCode 0006. Zigzag Conversion
 * Difficulty: Medium
 * Tags: string
 * URL: https://leetcode.com/problems/zigzag-conversion/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     The string "PAYPALISHIRING" is written in a zigzag pattern on a
 *     given number of rows like this: (you may want to display this
 *     pattern in a fixed font for better legibility)
 *     And then read line by line: "PAHNAPLSIIGYIR"
 *     Write the code that will take a string and make this conversion
 *     given a number of rows:
 *
 * [中文] 題目：Z 字形變換
 *     將字串 s 依 numRows 列，以由上往下、再斜向上、反覆往返的 Z 字形
 *     排列，最後按列由上到下讀取並回傳新字串。
 *
 * [中文] 範例
 *   範例 1：輸入 s = "PAYPALISHIRING", numRows = 3，
 *           輸出 "PAHNAPLSIIGYIR"。
 *   範例 2：輸入 s = "PAYPALISHIRING", numRows = 4，
 *           輸出 "PINALSIGYAHRPI"。
 *   範例 3：輸入 s = "A", numRows = 1，輸出 "A"。
 *
 * [中文] 限制
 *   - 1 <= s.length <= 1000。
 *   - s 由大小寫英文字母、逗號與句點組成。
 *   - 1 <= numRows <= 1000。
 *
 * [中文] 直觀解題思路
 *   1. 沿 Z 字形走訪一次，統計每一列會放幾個字元。
 *   2. 計算每列在答案字串中的起始位置。
 *   3. 再沿相同路徑走一次，將字元寫入所屬列的下一個位置。
 *   4. 只有一列或列數不少於字串長度時，直接複製原字串。
 *   時間 O(n + numRows)，額外位置資料與回傳字串共 O(n + numRows) 空間。
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

/* ---- 易讀解法：先計算各列範圍，再按 Z 字形填入 ---- */
char* convert(char* s, int numRows) {
    int n = (int)strlen(s);
    char *answer = (char *)malloc((size_t)n + 1);
    int *rowCounts;
    int *rowStarts;
    int *nextPosition;
    int row = 0;
    int direction = 1;
    int i;

    if (numRows == 1 || numRows >= n) {
        memcpy(answer, s, (size_t)n + 1);
        return answer;
    }

    rowCounts = (int *)calloc((size_t)numRows, sizeof(int));
    rowStarts = (int *)malloc((size_t)numRows * sizeof(int));
    nextPosition = (int *)malloc((size_t)numRows * sizeof(int));

    /* 第一趟只計算每列會放幾個字元。 */
    for (i = 0; i < n; ++i) {
        ++rowCounts[row];
        if (row == 0) direction = 1;
        else if (row == numRows - 1) direction = -1;
        row += direction;
    }

    /* 每列在答案中的區間接在前一列後面。 */
    rowStarts[0] = 0;
    for (row = 1; row < numRows; ++row) {
        rowStarts[row] = rowStarts[row - 1] + rowCounts[row - 1];
    }
    for (row = 0; row < numRows; ++row) {
        nextPosition[row] = rowStarts[row];
    }

    /* 第二趟沿 Z 字形行走，把字元放進它所屬列的區間。 */
    row = 0;
    direction = 1;
    for (i = 0; i < n; ++i) {
        answer[nextPosition[row]++] = s[i];
        if (row == 0) direction = 1;
        else if (row == numRows - 1) direction = -1;
        row += direction;
    }

    answer[n] = '\0';
    free(rowCounts);
    free(rowStarts);
    free(nextPosition);
    return answer;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "PAYPALISHIRING";
  char *act_0 = convert(s_0,(3));
  if (!(strcmp(act_0, "PAHNAPLSIIGYIR") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = "PAYPALISHIRING";
  char *act_1 = convert(s_1,(4));
  if (!(strcmp(act_1, "PINALSIGYAHRPI") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char s_2[] = "A";
  char *act_2 = convert(s_2,(1));
  if (!(strcmp(act_2, "A") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 6, "convert", ntests);
 return (pass&&ntests)?0:1;
}
