/*
 * ==========================================================================
 * LeetCode 0636. Exclusive Time of Functions
 * Difficulty: Medium
 * Tags: array, stack
 * URL: https://leetcode.com/problems/exclusive-time-of-functions/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     On a single-threaded CPU, we execute a program containing n
 *     functions. Each function has a unique ID between 0 and n-1.
 *     Function calls are stored in a call stack: when a function call
 *     starts, its ID is pushed onto the stack, and when a function call
 *     ends, its ID is popped off the stack. The function whose ID is at
 *     the top of the stack is the current function being executed. Each
 *     time a function starts or ends, we write a log with the ID, whether
 *     it started or ended, and the timestamp.
 *     You are given a list logs, where logs[i] represents the ith log
 *     message formatted as a string "{function_id}:{"start" |
 *     "end"}:{timestamp}". For example, "0:start:3" means a function call
 *     with function ID 0 started at the beginning of timestamp 3, and
 *     "1:end:2" means a function call with function ID 1 ended at the end
 *     of timestamp 2. Note that a function can be called multiple times,
 *     possibly recursively.
 *     A function's exclusive time is the sum of execution times for all
 *     function calls in the program. For example, if a function is called
 *     twice, one call executing for 2 time units and another call
 *     executing for 1 time unit, the exclusive time is 2 + 1 = 3.
 *     Return the exclusive time of each function in an array, where the
 *     value at the ith index represents the exclusive time for the
 *     function with ID i.
 *
 * [中文] 題目: 函式的獨占時間
 * [中文] 題目說明:
 *     單執行緒 CPU 依序處理函式呼叫日誌，每筆格式為函式 ID、sta
 *     rt 或 end，以及時間戳；函式可巢狀或遞迴呼叫。函式的獨占時間不
 *     含其呼叫之其他函式所花的時間，且 end 時刻屬於該函式的執行區間。
 *     回傳各 ID 的總獨占時間。
 *
 * [中文] 思路:
 *     以堆疊保存未結束函式的起始時間與已被子呼叫占用的時間。讀到結束日誌時
 *     ，依含端點的時間長度扣除子呼叫時間，再將此次執行時間累加到該函式與其
 *     父層。
 *
 * Examples:
 *     Input: n = 2, logs =
 *     ["0:start:0","1:start:2","1:end:5","0:end:6"]
 *     Output: [3,4]
 *     Explanation:
 *     Function 0 starts at the beginning of time 0, then it executes
 *     2 for units of time and reaches the end of time 1.
 *     Function 1 starts at the beginning of time 2, executes for 4
 *     units of time, and ends at the end of time 5.
 *     Function 0 resumes execution at the beginning of time 6 and
 *     executes for 1 unit of time.
 *     So function 0 spends 2 + 1 = 3 units of total time executing,
 *     and function 1 spends 4 units of total time executing.
 *     Input: n = 1, logs =
 *     ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
 *     Output: [8]
 *     Explanation:
 *     Function 0 starts at the beginning of time 0, executes for 2
 *     units of time, and recursively calls itself.
 *     Function 0 (recursive call) starts at the beginning of time 2
 *     and executes for 4 units of time.
 *     Function 0 (initial call) resumes execution then immediately
 *     calls itself again.
 *     Function 0 (2nd recursive call) starts at the beginning of
 *     time 6 and executes for 1 unit of time.
 *     Function 0 (initial call) resumes execution at the beginning
 *     of time 7 and executes for 1 unit of time.
 *     So function 0 spends 2 + 4 + 1 + 1 = 8 units of total time
 *     executing.
 *     Input: n = 2, logs =
 *     ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]
 *     Output: [7,1]
 *     Explanation:
 *     Function 0 starts at the beginning of time 0, executes for 2
 *     units of time, and recursively calls itself.
 *     Function 0 (recursive call) starts at the beginning of time 2
 *     and executes for 4 units of time.
 *     Function 0 (initial call) resumes execution then immediately
 *     calls function 1.
 *     Function 1 starts at the beginning of time 6, executes 1 unit
 *     of time, and ends at the end of time 6.
 *     Function 0 resumes execution at the beginning of time 6 and
 *     executes for 2 units of time.
 *     So function 0 spends 2 + 4 + 1 = 7 units of total time
 *     executing, and function 1 spends 1 unit of total time
 *     executing.
 *
 * Constraints:
 *   - 1 <= n <= 100
 *   - 2 <= logs.length <= 500
 *   - 0 <= function_id < n
 *   - 0 <= timestamp <= 10^9
 *   - No two start events will happen at the same timestamp.
 *   - No two end events will happen at the same timestamp.
 *   - Each function has an "end" log for each "start" log.
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
636. Exclusive Time of Functions

Given the running logs of n functions that are executed in a nonpreemptive single threaded CPU, find the exclusive time of these functions. 

Each function has a unique id, start from 0 to n-1. A function may be called recursively or by another function.

A log is a string has this format : function_id:start_or_end:timestamp. For example, "0:start:0" means function 0 starts from the very beginning of time 0. "0:end:0" means function 0 ends to the very end of time 0. 

Exclusive time of a function is defined as the time spent within this function, the time spent by calling other functions should not be considered as this function's exclusive time. You should return the exclusive time of each function sorted by their function id.

Example 1:
Input:
n = 2
logs = 
["0:start:0",
 "1:start:2",
 "1:end:5",
 "0:end:6"]
Output:[3, 4]
Explanation:
Function 0 starts at time 0, then it executes 2 units of time and reaches the end of time 1. 
Now function 0 calls function 1, function 1 starts at time 2, executes 4 units of time and end at time 5.
Function 0 is running again at time 6, and also end at the time 6, thus executes 1 unit of time. 
So function 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4 units of time.



Note:

Input logs will be sorted by timestamp, NOT log id.
Your output should be sorted by function id, which means the 0th element of your output corresponds to the exclusive time of function 0.
Two functions won't start or end at the same time.
Functions could be called recursively, and will always end.
1 <= n <= 100
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int *p;
    int *o; // offset
    int sp;
    int sz;
} s_t;

void push(s_t *stack, int tx) {
    if (stack->sz == stack->sp) {
        stack->sz *= 2;
        stack->p = realloc(stack->p, stack->sz * sizeof(int));
        //assert(stack->p);
        stack->o = realloc(stack->o, stack->sz * sizeof(int));
        //assert(stack->o);
    }
    stack->o[stack->sp   ] = 0;
    stack->p[stack->sp ++] = tx;
}

int pop(s_t *stack) {
    -- stack->sp;
    if (stack->sp > 0) {
        stack->o[stack->sp - 1] += stack->o[stack->sp];
    }
    return stack->p[stack->sp] + stack->o[stack->sp];
}

void update(s_t *stack, int tx) {
    if (stack->sp > 0) {
        stack->o[stack->sp - 1] += tx;
    }
}

void parse(char *log, int *fid, int *d, int *t) {
    char c;
    *fid = 0;
    while ((c = *(log ++)) != ':') {
        *fid = (*fid) * 10 + c - '0';
    }
    if (*log == 'e') {  // end
        log += 4;
        *d = 0;
    } else {
        log += 6;
        *d = 1;
    }
    *t = 0;
    while ((c = *(log ++)) != 0) {
        *t = (*t) * 10 + c - '0';
    }
}

int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize) {
    s_t stack;
    int *res, i, fid, d, t;
    
    stack.sz = 100;
    stack.sp = 0;
    stack.p = malloc(stack.sz * sizeof(int));
    //assert(stack.p);
    stack.o = malloc(stack.sz * sizeof(int));
    //assert(stack.o);
    
    res = calloc(n, sizeof(int));
    //assert(t);
    
    *returnSize = n;
    
    for (i = 0; i < logsSize; i ++) {
        parse(logs[i], &fid, &d, &t);
        if (d) {
            push(&stack, t);
        } else {
            t = t - pop(&stack) + 1;
            update(&stack, t);
            res[fid] += t;
        }
    }
    
    free(stack.p);
    free(stack.o);
    
    return res;
}

/*
Difficulty:Medium
Total Accepted:5.9K
Total Submissions:13.8K


Companies Facebook
Related Topics Stack

*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static char *sa0_1[] = {"0:start:0","1:start:2","1:end:5","0:end:6"};
  int *act_0 = exclusiveTime((2),sa0_1, 4,&rsz_0);
  static const int exp_0[] = {3,4};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static char *sa1_1[] = {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"};
  int *act_1 = exclusiveTime((1),sa1_1, 6,&rsz_1);
  static const int exp_1[] = {8};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 1))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  static char *sa2_1[] = {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
  int *act_2 = exclusiveTime((2),sa2_1, 6,&rsz_2);
  static const int exp_2[] = {1,7};
  if (!(lc_eq_list_sorted(act_2, rsz_2, exp_2, 2))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 636, "exclusiveTime", ntests);
 return (pass&&ntests)?0:1;
}
