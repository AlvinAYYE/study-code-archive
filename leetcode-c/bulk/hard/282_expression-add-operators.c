/*
 * ==========================================================================
 * LeetCode 0282. Expression Add Operators
 * Difficulty: Hard
 * Tags: math, string, backtracking
 * URL: https://leetcode.com/problems/expression-add-operators/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given a string num that contains only digits and an integer target,
 *     return all possibilities to insert the binary operators '+', '-',
 *     and/or '*' between the digits of num so that the resultant
 *     expression evaluates to the target value.
 *     Note that operands in the returned expressions should not contain
 *     leading zeros.
 *     Note that a number can contain multiple digits.
 *
 * [中文] 題目: 為運算式加上運算子
 * [中文] 題目說明:
 *     給定僅含數字的字串 num 與整數 target，請在相鄰數字間插入
 *      +、- 或 *，列出所有計算值等於 target 的運算式。運算元
 *     可由多個數字組成，但不得有前導零（單一 0 除外）。答案的排列順序不
 *     限。
 *
 * [中文] 思路:
 *     以回溯枚舉下一個運算元和三種運算子，遞迴保留目前總值與最後一項。遇到
 *     乘法時用「總值減去最後一項再加上乘積」修正運算優先序，並略過前導零與
 *     溢位的數字。
 *
 * Examples:
 *     Input: num = "123", target = 6
 *     Output: ["1*2*3","1+2+3"]
 *     Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
 *     Input: num = "232", target = 8
 *     Output: ["2*3+2","2+3*2"]
 *     Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
 *     Input: num = "3456237490", target = 9191
 *     Output: []
 *     Explanation: There are no expressions that can be created from
 *     "3456237490" to evaluate to 9191.
 *
 * Constraints:
 *   - 1 <= num.length <= 10
 *   - num consists of only digits.
 *   - -231 <= target <= 231 - 1
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
282. Expression Add Operators

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.


Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []


Credits:Special thanks to @davidtan1890 for adding this problem and creating all test cases.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **p;
    int sz;
    int n;
} res_t;
int str2int(char *num, int l) {
    int k, i;
    k = 0;
    while (l -- > 0) {
        i = *num - '0';
        if (k > 214748364 ||
            (k == 214748364 && i > 7)) {
            return -1;
        }
        k = k * 10 + i;
        num ++;
    }
    return k;
}
void add2res(char *buff, res_t *res) {
    if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = strdup(buff);
}
void bt(char *num, int s, int e, long n, long m, int target, char *buff, int d, res_t *res) {
    int l, k;
    
    if (s == e) {  // start == end, done!
        if (n == target) {
            //printf("%d, %d\n", n, target);
            buff[d] = 0;
            add2res(buff, res);
        }
        return;
    }
    
    for (l = 1; l <= e - s && l <= 10; l ++) {
        if (l > 1 && num[s] == '0') break;
        k = str2int(&num[s], l);
        if (k == -1) break;     // overflow
        //printf("%d\n", k);
        if (!d) {
            strncpy(buff, &num[s], l);
            bt(num, s + l, e, k, k, target, buff, l, res);
        } else {
            strncpy(&buff[d + 1], &num[s], l);
            buff[d] = '+';
            bt(num, s + l, e, n + k, k,             target, buff, d + 1 + l, res);
            buff[d] = '-';
            bt(num, s + l, e, n - k, -k,            target, buff, d + 1 + l, res);
            buff[d] = '*';
            bt(num, s + l, e, n - m + m * k, m * k, target, buff, d + 1 + l, res);
            // m is previous k, n is overall total up to previous k
        }
    }
}
char** addOperators(char* num, int target, int* returnSize) {
    res_t res;
    char *buff;
    int l;
    
    res.sz = 10;
    res.p = malloc(res.sz * sizeof(char *));
    //assert(res.p);
    res.n = 0;
    
    l = strlen(num);
    buff = malloc(l * 2 * sizeof(char));
    //assert(buff);
    
    bt(num, 0, l, 0, 0, target, buff, 0, &res);
    
    free(buff);
    
    *returnSize = res.n;
    return res.p;
}


/*
Difficulty:Hard
Total Accepted:33.1K
Total Submissions:111.5K


Companies Google Facebook
Related Topics Divide and Conquer
Similar Questions 
                
                  
                    Evaluate Reverse Polish Notation
                  
                    Basic Calculator
                  
                    Basic Calculator II
                  
                    Different Ways to Add Parentheses
                  
                    Target Sum
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  char num_0[] = "123";
  char **act_0 = addOperators(num_0,(6),&rsz_0);
  static char *cexp_0[] = {"1*2*3","1+2+3"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  char num_1[] = "232";
  char **act_1 = addOperators(num_1,(8),&rsz_1);
  static char *cexp_1[] = {"2*3+2","2+3*2"};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 2))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  char num_2[] = "3456237490";
  char **act_2 = addOperators(num_2,(9191),&rsz_2);
  static char *cexp_2[] = {""};
  if (!(lc_eq_cands(act_2, rsz_2, cexp_2, 0))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 282, "addOperators", ntests);
 return (pass&&ntests)?0:1;
}
