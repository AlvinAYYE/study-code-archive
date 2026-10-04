/*
 * ==========================================================================
 * LeetCode 0224. Basic Calculator
 * Difficulty: Hard
 * Tags: math, string, stack, recursion
 * URL: https://leetcode.com/problems/basic-calculator/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given a string s representing a valid expression, implement a basic
 *     calculator to evaluate it, and return the result of the evaluation.
 *     Note: You are not allowed to use any built-in function which
 *     evaluates strings as mathematical expressions, such as eval().
 *
 * [中文] 題目: 基本計算機
 * [中文] 題目說明:
 *     給定合法運算式字串 s，計算只含整數、加減、括號與空白的結果。不可使
 *     用 eval 等內建字串運算功能；加號不可作一元運算，減號可以，結果
 *     保證在 32 位元有號整數範圍內。
 *
 * [中文] 思路:
 *     剖析字串後分別以動態堆疊保存運算元與運算子，並依優先序在適當時機歸約
 *     。左括號直接入堆疊，右括號會結算至對應左括號為止。
 *
 * Examples:
 *     Input: s = "1 + 1"
 *     Output: 2
 *     Input: s = " 2-1 + 2 "
 *     Output: 3
 *     Input: s = "(1+(4+5+2)-3)+(6+8)"
 *     Output: 23
 *
 * Constraints:
 *   - 1 <= s.length <= 3 * 10^5
 *   - s consists of digits, '+', '-', '(', ')', and ' '.
 *   - s represents a valid expression.
 *   - '+' is not used as a unary operation (i.e., "+1" and "+(2 +
 *   3)" is invalid).
 *   - '-' could be used as a unary operation (i.e., "-1" and "-(2 +
 *   3)" is valid).
 *   - There will be no two consecutive operators in the input.
 *   - Every number and running calculation will fit in a signed
 *   32-bit integer.
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
224. Basic Calculator

Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23




Note: Do not use the eval built-in library function.
*/

typedef struct {
    int *p;
    int sz;
    int n;
} s_t;
int parse(char **sp, int *k) {
    char *s = *sp;
    
    while (*s == ' ') s ++;
 
    *k = 0;
    
    if (*s == 0) return 0;
    
    if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '(' || *s == ')') {
        *k = *s == '+' ? 1 :
             *s == '-' ? 2 :
             *s == '*' ? 3 :
             *s == '/' ? 4 :
             *s == '(' ? 5 : 6;
        *sp = ++ s;
        return 1;
    }
    
    while (*s >= '0' && *s <= '9') {
        *k = (*k) * 10 + *s - '0';
        s ++;
    }
    *sp = s;
    return 2;
}
void push(s_t *stack, int k) {
    if (stack->sz == stack->n) {
        stack->sz *= 2;
        stack->p = realloc(stack->p, stack->sz * sizeof(int));
        //assert(stack->p);
    }
    stack->p[stack->n ++] = k;
}
int low_op(s_t *ops, int k) {
    const int priority[] = { 0, 2, 2, 3, 3, 1, 1 }; // null, +, -, *, /, (, )
    return (priority[ops->p[ops->n - 1]] >= priority[k]) ? 1 : 0;
}
int calculate(char* s) {
    s_t data = { 0 }, ops = { 0 };
    int x, k, d1, d2, o;
 
    data.n = ops.n = 0;
    data.sz = ops.sz = 10;
    data.p = malloc(data.sz * sizeof(int));
    ops.p = malloc(ops.sz * sizeof(int));
    
    push(&data, 0); // put a zero in case of with a null input
    push(&ops, 0);  // put a null operator on top of operator stack
    
    do {
        x = parse(&s, &k);
        if (x == 2) {   // data, push to stack
            push(&data, k);
        } else if (k == 5) {  // left parenthese, always push
            push(&ops, k);
        } else {        // operator
            while (low_op(&ops, k)) {
                o = ops.p[-- ops.n];
                if (o == 0 || o == 5) break; // end of input or left parenthese
                d2 = data.p[-- data.n];
                d1 = data.p[-- data.n];
                switch (o) {
                    case 1:             // '+'
                        d1 = d1 + d2;
                        break;
                    case 2:             // '-'
                        d1 = d1 - d2;
                        break;
                    case 3:             // '*'
                        d1 = d1 * d2;
                        break;
                    case 4:             // '/'
                        d1 = d1 / d2;
                        break;
                    default:
                        break;
                }
                push(&data, d1);
            }
            if (k && k != 6) push(&ops, k);  // ignore end or right parenthese
        }
    } while (x);
    
    //assert(ops.n == 0);
    k = data.p[data.n - 1];
    
    free(data.p);
    free(ops.p);
    
    return k;
}


/*
Difficulty:Hard
Total Accepted:51.6K
Total Submissions:190.7K


Companies Google
Related Topics Stack Math
Similar Questions 
                
                  
                    Evaluate Reverse Polish Notation
                  
                    Basic Calculator II
                  
                    Different Ways to Add Parentheses
                  
                    Expression Add Operators
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "1 + 1";
  long long act_0 = (long long)calculate(s_0);
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = " 2-1 + 2 ";
  long long act_1 = (long long)calculate(s_1);
  if (!(act_1 == 3LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char s_2[] = "(1+(4+5+2)-3)+(6+8)";
  long long act_2 = (long long)calculate(s_2);
  if (!(act_2 == 23LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 224, "calculate", ntests);
 return (pass&&ntests)?0:1;
}
