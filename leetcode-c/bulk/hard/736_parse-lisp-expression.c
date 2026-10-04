/*
 * ==========================================================================
 * LeetCode 0736. Parse Lisp Expression
 * Difficulty: Hard
 * Tags: hash-table, string, stack, recursion
 * URL: https://leetcode.com/problems/parse-lisp-expression/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a string expression representing a Lisp-like
 *     expression to return the integer value of.
 *     The syntax for these expressions is given as follows.
 *
 * [中文] 題目: 解析 Lisp 表達式
 * [中文] 題目說明:
 *     給定合法的 Lisp 風格字串表達式，計算其整數結果；表達式可為整數
 *     、變數、add、mult 或 let。let 的賦值依序執行，變數查
 *     找採由內而外的作用域規則，而 add 與 mult 各對兩個子表達式
 *     做加法或乘法。
 *
 * [中文] 思路:
 *     遞迴剖析括號、運算子、整數與識別字，並以符號鏈結串列保存變數綁定。每
 *     層 let 以深度標記其新綁定，完成該層後移除，變數解析時自然優先取
 *     得最內層值。
 *
 * Examples:
 *     Input: expression = "(let x 2 (mult x (let x 3 y 4 (add x
 *     y))))"
 *     Output: 14
 *     Explanation: In the expression (add x y), when checking for
 *     the value of the variable x,
 *     we check from the innermost scope to the outermost in the
 *     context of the variable we are trying to evaluate.
 *     Since x = 3 is found first, the value of x is 3.
 *     Input: expression = "(let x 3 x 2 x)"
 *     Output: 2
 *     Explanation: Assignment in let statements is processed
 *     sequentially.
 *     Input: expression = "(let x 1 y 2 x (add x y) (add x y))"
 *     Output: 5
 *     Explanation: The first (add x y) evaluates as 3, and is
 *     assigned to x.
 *     The second (add x y) evaluates as 3+2 = 5.
 *
 * Constraints:
 *   - 1 <= expression.length <= 2000
 *   - There are no leading or trailing spaces in expression.
 *   - All tokens are separated by a single space in expression.
 *   - The answer and all intermediate calculations of that answer
 *   are guaranteed to fit in a 32-bit integer.
 *   - The expression is guaranteed to be legal and evaluate to an
 *   integer.
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
736. Parse Lisp Expression

You are given a string expression representing a Lisp-like expression to return the integer value of.

The syntax for these expressions is given as follows.

An expression is either an integer, a let-expression, an add-expression, a mult-expression, or an assigned variable.  Expressions always evaluate to a single integer.

(An integer could be positive or negative.)

A let-expression takes the form (let v1 e1 v2 e2 ... vn en expr), where let is always the string "let", then there are 1 or more pairs of alternating variables and expressions, meaning that the first variable v1 is assigned the value of the expression e1, the second variable v2 is assigned the value of the expression e2, and so on sequentially; and then the value of this let-expression is the value of the expression expr.

An add-expression takes the form (add e1 e2) where add is always the string "add", there are always two expressions e1, e2, and this expression evaluates to the addition of the evaluation of e1 and the evaluation of e2.

A mult-expression takes the form (mult e1 e2) where mult is always the string "mult", there are always two expressions e1, e2, and this expression evaluates to the multiplication of the evaluation of e1 and the evaluation of e2.

For the purposes of this question, we will use a smaller subset of variable names.  A variable starts with a lowercase letter, then zero or more lowercase letters or digits.  Additionally for your convenience, the names "add", "let", or "mult" are protected and will never be used as variable names.

Finally, there is the concept of scope.  When an expression of a variable name is evaluated, within the context of that evaluation, the innermost scope (in terms of parentheses) is checked first for the value of that variable, and then outer scopes are checked sequentially.  It is guaranteed that every expression is legal.  Please see the examples for more details on scope.


Evaluation Examples:
Input: (add 1 2)
Output: 3

Input: (mult 3 (add 2 3))
Output: 15

Input: (let x 2 (mult x 5))
Output: 10

Input: (let x 2 (mult x (let x 3 y 4 (add x y))))
Output: 14
Explanation: In the expression (add x y), when checking for the value of the variable x,
we check from the innermost scope to the outermost in the context of the variable we are trying to evaluate.
Since x = 3 is found first, the value of x is 3.

Input: (let x 3 x 2 x)
Output: 2
Explanation: Assignment in let statements is processed sequentially.

Input: (let x 1 y 2 x (add x y) (add x y))
Output: 5
Explanation: The first (add x y) evaluates as 3, and is assigned to x.
The second (add x y) evaluates as 3+2 = 5.

Input: (let x 2 (add (let x 3 (let x 4 x)) x))
Output: 6
Explanation: Even though (let x 4 x) has a deeper scope, it is outside the context
of the final x in the add-expression.  That final x will equal 2.

Input: (let a1 3 b2 (add a1 1) b2) 
Output 4
Explanation: Variable names can contain digits after the first character.



Note:
The given string expression is well formatted: There are no leading or trailing spaces, there is only a single space separating different components of the string, and no space between adjacent parentheses.  The expression is guaranteed to be legal and evaluate to an integer.
The length of expression is at most 2000.  (It is also non-empty, as that would not be a legal expression.)
The answer and all intermediate calculations of that answer are guaranteed to fit in a 32-bit integer.
*/

#define TYPE_INT    0
#define TYPE_ID     1

typedef struct {
    char *p;
    int len;
} idn_t;

typedef struct {
    int type;       // 0: identifier, 1: value
    union {
        idn_t id;
        int num;
    } u;
} expr_t;

typedef struct sym_s {
    idn_t id;
    int val;
    int scope;
    struct sym_s *list;
} sym_t;

typedef struct {
    char *input;
    sym_t *sym;
} p_t;

#define IS_LET(E)  ((E)[0] == 'l' && \
                    (E)[1] == 'e' && \
                    (E)[2] == 't' && \
                    (E)[3] == ' ')
#define IS_ADD(E)  ((E)[0] == 'a' && \
                    (E)[1] == 'd' && \
                    (E)[2] == 'd' && \
                    (E)[3] == ' ')
#define IS_MULT(E) ((E)[0] == 'm' && \
                    (E)[1] == 'u' && \
                    (E)[2] == 'l' && \
                    (E)[3] == 't' && \
                    (E)[4] == ' ')
#define IS_NUM(E)  ((E)[0] >= '0' && \
                    (E)[0] <= '9')

char *next_input(char *input) {
    int n = 0;
    char c;
    while (c = *(input ++)) {
        if (c == '(') n ++;
        else if (c == ')') {
            if (n) n --;
            else {
                *(input - 1) = 0;
                break;
            }
        }
    }
    if (*input == ' ') input ++;
    //assert(0);
    return input;
}

idn_t parse_identifier(p_t *p) {
    char c;
    idn_t id;

    id.p = p->input;
    do {
        c = *(++ p->input);
    } while (c != 0 && c != ' ');

    id.len = p->input - id.p;

    if (c == ' ') p->input ++;

    return id;
}

expr_t parse_num(p_t *p) {
    expr_t expr;
    int neg = 0;
    
    if (*p->input == '-') {
        neg = 1;
        p->input ++;
    }
    
    expr.type = TYPE_INT;
    expr.u.num = 0;
    do {
        expr.u.num = expr.u.num * 10 + *p->input - '0';
        p->input ++;
    } while (IS_NUM(p->input));
    
    if (neg) {
        expr.u.num = 0 - expr.u.num;
    }
    
    if (*p->input == ' ') p->input ++;
    
    return expr;
}

expr_t resolve(p_t *p, expr_t a) {
    sym_t *sym;

    if (a.type == TYPE_ID) {
        sym = p->sym;
        while (a.u.id.len != sym->id.len ||
               strncmp(a.u.id.p, sym->id.p, sym->id.len)) sym = sym->list;
        a.type = TYPE_INT;
        a.u.num = sym->val;
    }

    return a;
}

expr_t parse(p_t *, int);

expr_t parse_let(p_t *p, int d) {
    char c;
    sym_t *sym;
    expr_t a, b;
    while (c = *p->input) {
        if (c == ' ') {
            p->input ++;
            continue;
        }
        a = parse(p, d);
        if (a.type == TYPE_INT) break;
        if (*p->input) {
            b = parse(p, d);
            b = resolve(p, b);
            sym = malloc(sizeof(*sym));
            //assert(sym);
            sym->id = a.u.id;
            sym->val = b.u.num;
            sym->scope = d;
            sym->list = p->sym;
            p->sym = sym;
        }
    }
    if (a.type == TYPE_ID) {
        a = resolve(p, a);
    }
    sym = p->sym;
    while (sym && sym->scope == d) {
        p->sym = sym->list;
        free(sym);
        sym = p->sym;
    }
    return a;
}

expr_t parse(p_t *p, int d) {
    char c, *next;
    expr_t a, b, sym, expr;

    if ((c = *p->input) == '(') {
        p->input ++;
        next = next_input(p->input);
        expr = parse(p, d + 1);
        p->input = next;
    } else if (IS_LET(p->input)) {
        p->input += 4;
        expr = parse_let(p, d);
    } else if (IS_ADD(p->input)) {
        p->input += 4;
        a = parse(p, d);
        b = parse(p, d);
        a = resolve(p, a);
        b = resolve(p, b);
        expr.type = TYPE_INT;
        expr.u.num = a.u.num + b.u.num;
    } else if (IS_MULT(p->input)) {
        p->input += 5;
        a = parse(p, d);
        b = parse(p, d);
        a = resolve(p, a);
        b = resolve(p, b);
        expr.type = TYPE_INT;
        expr.u.num = a.u.num * b.u.num;
    } else if (IS_NUM(p->input) ||
               *p->input == '-') {
        expr = parse_num(p);
    } else {
        expr.type = TYPE_ID;
        expr.u.id = parse_identifier(p);
    }

    //assert(*p->input == 0);

    return expr;
}

int evaluate(char * expression) {
    expr_t result;
    p_t p = { 0 };
    p.input = expression;
    result = parse(&p, 0);
    return result.u.num;
}


/*
Difficulty:Hard


*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char expression_0[] = "(let x 2 (mult x (let x 3 y 4 (add x y))))";
  long long act_0 = (long long)evaluate(expression_0);
  if (!(act_0 == 14LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char expression_1[] = "(let x 3 x 2 x)";
  long long act_1 = (long long)evaluate(expression_1);
  if (!(act_1 == 2LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char expression_2[] = "(let x 1 y 2 x (add x y) (add x y))";
  long long act_2 = (long long)evaluate(expression_2);
  if (!(act_2 == 5LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 736, "evaluate", ntests);
 return (pass&&ntests)?0:1;
}
