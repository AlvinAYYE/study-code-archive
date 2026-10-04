/*
 * ==========================================================================
 * LeetCode 1694. Reformat Phone Number
 * Difficulty: Easy
 * Tags: string
 * URL: https://leetcode.com/problems/reformat-phone-number/
 * Source: community solution, repo DimitrisJim_leetcode_solutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a phone number as a string number. number consists of
 *     digits, spaces ' ', and/or dashes '-'.
 *     You would like to reformat the phone number in a certain manner.
 *     Firstly, remove all spaces and dashes. Then, group the digits from
 *     left to right into blocks of length 3 until there are 4 or fewer
 *     digits. The final digits are then grouped as follows:
 *     The blocks are then joined by dashes. Notice that the reformatting
 *     process should never produce any blocks of length 1 and produce at
 *     most two blocks of length 2.
 *     Return the phone number after formatting.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定 a phone number as a 字串 number. number consists of 數位, spaces ' ',
 *     and/or dashes '-'.
 *
 * Examples:
 *     Input: number = "1-23-45 6"
 *     Output: "123-456"
 *     Explanation: The digits are "123456".
 *     Step 1: There are more than 4 digits, so group the next 3
 *     digits. The 1st block is "123".
 *     Step 2: There are 3 digits remaining, so put them in a single
 *     block of length 3. The 2nd block is "456".
 *     Joining the blocks gives "123-456".
 *     Input: number = "123 4-567"
 *     Output: "123-45-67"
 *     Explanation: The digits are "1234567".
 *     Step 1: There are more than 4 digits, so group the next 3
 *     digits. The 1st block is "123".
 *     Step 2: There are 4 digits left, so split them into two blocks
 *     of length 2. The blocks are "45" and "67".
 *     Joining the blocks gives "123-45-67".
 *     Input: number = "123 4-5678"
 *     Output: "123-456-78"
 *     Explanation: The digits are "12345678".
 *     Step 1: The 1st block is "123".
 *     Step 2: The 2nd block is "456".
 *     Step 3: There are 2 digits left, so put them in a single block
 *     of length 2. The 3rd block is "78".
 *     Joining the blocks gives "123-456-78".
 *
 * Constraints:
 *   - 2 <= number.length <= 100
 *   - number consists of digits and the characters '-' and ' '.
 *   - There are at least two digits in number.
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
#include <stdlib.h>

// Count numbers in s.
#define COUNT_NUMS(s, counter)                                                 \
  do {                                                                         \
    if (*s != '-' && *s != ' ')                                                \
      counter++;                                                               \
  } while (*(++s));

char *reformatNumber(char *number) {
  int len = 0;
  char *runner = number;
  COUNT_NUMS(runner, len);

  // Find how many times to repeat and what will be left.
  int left = len, repeat = 0;
  while (left > 4) {
    left -= 3;
    repeat++;
  }

  // Find resulting size -> len digits + repeat dashes + 1 if 4 left.
  // rlen keeps track of length of result.
  int resSize = len + repeat + 1 + (left == 4 ? 1 : 0), rlen = 0;
  char *result = malloc(resSize + 1); // keep space for '\0'

  // Add triplets, takes care of a number of edge cases:
  //  digits -> keep track of how many digits we've added so far (
  //            to know when to move to next group.)
  //  end    -> flag, re-use the while loop to also add left overs.
  //  lim    -> how many digits to we add? 3 or 2.
  //  repeat needs to be re-adjusted for the case where repeat == 0
  //  and left == 4. We want to repeat twice even though repeat has
  // initially been set to 0.
  int digits = 0, end = repeat > 0 ? 0 : 1,
      lim = repeat > 0 ? 3 : (left == 4 ? 2 : left);
  repeat = repeat > 0 ? repeat : (left == 4 ? 2 : 0);
  while (1) {
    // Skip '-' and ' '.
    while (*number && *number == '-' || *number == ' ')
      number++;

    // Add dash and, if we have leftovers, handle them, else break.
    if (digits == lim) {
      result[rlen++] = '-';
      digits = 0;
      repeat--;
      if (repeat <= 0) {
        if (end)
          break;
        repeat = left == 4 ? 2 : 1;
        lim = left == 4 ? 2 : left;
        end = 1;
      }
      // Add digit.
    } else {
      result[rlen++] = *number++;
      digits++;
    }
  }
  // Replace superflous '-' added with terminator.
  result[--rlen] = '\0';
  return result;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char number_0[] = "1-23-45 6";
  char *act_0 = reformatNumber(number_0);
  if (!(strcmp(act_0, "123-456") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char number_1[] = "123 4-567";
  char *act_1 = reformatNumber(number_1);
  if (!(strcmp(act_1, "123-45-67") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char number_2[] = "123 4-5678";
  char *act_2 = reformatNumber(number_2);
  if (!(strcmp(act_2, "123-456-78") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1694, "reformatNumber", ntests);
 return (pass&&ntests)?0:1;
}
