/*
 * ==========================================================================
 * LeetCode 0401. Binary Watch
 * Difficulty: Easy
 * Tags: backtracking, bit-manipulation
 * URL: https://leetcode.com/problems/binary-watch/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     A binary watch has 4 LEDs on the top to represent the hours (0-11),
 *     and 6 LEDs on the bottom to represent the minutes (0-59). Each LED
 *     represents a zero or one, with the least significant bit on the
 *     right.
 *     Given an integer turnedOn which represents the number of LEDs that
 *     are currently on (ignoring the PM), return all possible times the
 *     watch could represent. You may return the answer in any order.
 *     The hour must not contain a leading zero.
 *     The minute must consist of two digits and may contain a leading
 *     zero.
 *
 * [中文] 題目: 二進位手錶
 * [中文] 題目說明:
 *     二進位手錶以 4 顆 LED 表示小時 0 至 11，以 6 顆 L
 *     ED 表示分鐘 0 至 59；給定目前亮起的 LED 數 turne
 *     dOn，回傳所有可能時間。小時不可有前導零，分鐘必須為兩位數且可有前
 *     導零，輸出順序不限。
 *
 * [中文] 思路:
 *     預先計算每個合法小時與分鐘的 1 位元數，枚舉 12 x 60 種時
 *     間並保留兩者總和等於 turnedOn 的格式化結果。
 *
 * Examples:
 *     Input: turnedOn = 1
 *     Output:
 *     ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 *     Input: turnedOn = 9
 *     Output: []
 *
 * Constraints:
 *   - 0 <= turnedOn <= 10
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
 * 題目：401. Binary Watch（二進位手錶）
 *
 * 題意完整翻譯：
 *     二進位手錶上方有 4 個 LED 表示小時（0 到 11），下方有 6 個 LED 表示分鐘（0 到 59）；亮起的 LED
 *     代表二進位中的 1，最右邊是最低位。給定亮著的 LED 數量
 *     turnedOn，回傳手錶可能顯示的所有時間，順序不限。小時不能有前導零；分鐘固定兩位，必要時在前面補 0。
 *
 * 範例：
 *   輸入：turnedOn = 1
 *   輸出：["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 *   說明：只有一個燈亮時，可能是分鐘的六個位元之一，或小時的四個位元之一。
 *   輸入：turnedOn = 9
 *   輸出：[]
 *   說明：手錶總共只有 10 個 LED，且小時和分鐘的有效範圍無法讓 9 個燈同時亮起。
 *
 * 限制：
 *   - 0 <= turnedOn <= 10
 *
 * 解題步驟：
 *   1. 列舉所有合法小時 0 到 11，以及分鐘 0 到 59。
 *   2. 分別計算小時與分鐘的二進位 1 數量；兩者相加等於 turnedOn 時，這個時間就是答案。
 *   3. 用小時不補零、分鐘補成兩位數的格式建立時間字串。
 *
 * 複雜度：
 *   時間：O(12 × 60 × 6)，範圍固定；也可視為 O(1)。
 *   空間：O(1) 額外空間；回傳的時間清單另需 O(k) 空間。
 */

static int countOnBits(int value) {
    int count = 0;

    while (value > 0) {
        count += value & 1;
        value >>= 1;
    }

    return count;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** times = (char**)malloc(sizeof(char*) * 720);
    int hour;
    int minute;

    *returnSize = 0;

    // 手錶只有 12 個合法小時與 60 個合法分鐘，逐一檢查即可。
    for (hour = 0; hour < 12; ++hour) {
        for (minute = 0; minute < 60; ++minute) {
            if (countOnBits(hour) + countOnBits(minute) == turnedOn) {
                char* time = (char*)malloc(6);
                sprintf(time, "%d:%02d", hour, minute);
                times[*returnSize] = time;
                ++(*returnSize);
            }
        }
    }

    return times;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  char **act_0 = readBinaryWatch((1),&rsz_0);
  static char *cexp_0[] = {"0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 10))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  char **act_1 = readBinaryWatch((9),&rsz_1);
  static char *cexp_1[] = {""};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 0))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 401, "readBinaryWatch", ntests);
 return (pass&&ntests)?0:1;
}
