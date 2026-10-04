/*
 * ==========================================================================
 * LeetCode 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
 * Difficulty: Medium
 * Tags: array, queue, sliding-window, heap-(priority-queue, ordered-set, monotonic-queue
 * URL: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an array of integers nums and an integer limit, return the
 *     size of the longest non-empty subarray such that the absolute
 *     difference between any two elements of this subarray is less than or
 *     equal to limit.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     Given an 陣列 of integers nums and an 整數 limit, 回傳最長⋯⋯的長度 非空的 subarray
 *     such that the absolute difference between any two elements of this
 *     subarray is less than or equal to limit.
 *
 * Examples:
 *     Input: nums = [8,2,4,7], limit = 4
 *     Output: 2
 *     Explanation: All subarrays are:
 *     [8] with maximum absolute diff |8-8| = 0 <= 4.
 *     [8,2] with maximum absolute diff |8-2| = 6 > 4.
 *     [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
 *     [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
 *     [2] with maximum absolute diff |2-2| = 0 <= 4.
 *     [2,4] with maximum absolute diff |2-4| = 2 <= 4.
 *     [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
 *     [4] with maximum absolute diff |4-4| = 0 <= 4.
 *     [4,7] with maximum absolute diff |4-7| = 3 <= 4.
 *     [7] with maximum absolute diff |7-7| = 0 <= 4.
 *     Therefore, the size of the longest subarray is 2.
 *     Input: nums = [10,1,2,4,7,2], limit = 5
 *     Output: 4
 *     Explanation: The subarray [2,4,7,2] is the longest since the
 *     maximum absolute diff is |2-7| = 5 <= 5.
 *     Input: nums = [4,2,2,2,4,4,2,2], limit = 0
 *     Output: 3
 *
 * Constraints:
 *   - 1 <= nums.length <= 10^5
 *   - 1 <= nums[i] <= 10^9
 *   - 0 <= limit <= 10^9
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
/***

Approach: Sliding Window + Monotonic Queue

Maintain a monotonically decreasing queue, maxq, and a monotonically increasing
queue, minq, where both store indices. The front element of maxq is the index of
the current maximum element, and the front element of minq is the index of the
current minimum element. Note that while storing elements is possible, storing
indices is beneficial because it remains unaffected by duplicate elements.

Also, need two pointers, left and i. Initially, i moves forward. When it finds
that:
- maxq is not empty and the last element in maxq is smaller than the current
  element nums[i], it continually polls elements from maxq until it becomes
  monotonically decreasing again.
- minq is not empty and the last element in minq is larger than the current
  element nums[i], it continually polls elements from minq until it becomes
  monotonically increasing again.

At this point, we check: if both queues are not empty, but the diff between
the front elements in the two queues (one being the maximum value and the other
the minimum value) is greater than the limit, we start moving the left pointer
to the right. As we move the left pointer, if any element in the queues has an 
index less than or equal to left, we poll it out because it's no longer needed.
Here, storing indices is advantageous because the indices are sequentially
added to both queues, so if the diff exceeds the limit, we need to start 
checking from the very beginning of the left pointer.

Time complexity: O(n)
Space complexity: O(n)

***/

// Node for deque
typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node_t;

// Deque structure
typedef struct deque {
    node_t* front;
    node_t* rear;
    int sz;
} deque_t;

static deque_t* create_deque() {
    deque_t* deque = (deque_t*)malloc(sizeof(deque_t));
    deque->front = deque->rear = NULL;
    deque->sz = 0;
    return deque;
}

static void add_rear(deque_t* deque, int value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = deque->rear;
    if (deque->rear)
        deque->rear->next = new_node;
    else
        deque->front = new_node;
    deque->rear = new_node;
    deque->sz++;
}

static int rm_front(deque_t* deque) {
    if (deque->front == NULL)
        return -1;
    node_t* tmp = deque->front;
    int value = tmp->value;
    deque->front = deque->front->next;
    if (deque->front)
        deque->front->prev = NULL;
    else
        deque->rear = NULL;
    free(tmp);
    deque->sz--;
    return value;
}

static int rm_rear(deque_t* deque) {
    if (deque->rear == NULL)
        return -1;
    node_t* tmp = deque->rear;
    int value = tmp->value;
    deque->rear = deque->rear->prev;
    if (deque->rear)
        deque->rear->next = NULL;
    else
        deque->front = NULL;
    free(tmp);
    deque->sz--;
    return value;
}

static inline int get_front(deque_t* deque) {
    return deque->front ? deque->front->value : -1;
}

static inline int get_rear(deque_t* deque) {
    return deque->rear ? deque->rear->value : -1;
}

static inline int is_empty(deque_t* deque) {
    return deque->sz == 0;
}

static inline void free_deque(deque_t* deque) {
    while (!is_empty(deque))
        rm_front(deque);
    free(deque);
}

int longestSubarray(int* nums, int nums_sz, int limit) {
    deque_t *maxq = create_deque(), *minq = create_deque();
    int left = 0, n = nums_sz;

    for (int i = 0; i < n; i++) {
        int v = nums[i];
        // Maintain maxq as decreasing
        while (!is_empty(maxq) && get_rear(maxq) < v)
            rm_rear(maxq);
        // Maintain minq as increasing
        while (!is_empty(minq) && get_rear(minq) > v)
            rm_rear(minq);
        add_rear(maxq, v);
        add_rear(minq, v);

        // Check if current window is valid
        if (get_front(maxq) - get_front(minq) > limit) {
            if (get_front(maxq) == nums[left])
                rm_front(maxq);
            if (get_front(minq) == nums[left])
                rm_front(minq);
            left++;
        }
    }
    
    int result = n - left;
    free_deque(maxq);
    free_deque(minq);
    return result;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {8,2,4,7};
  long long act_0 = (long long)longestSubarray(arr0_0, 4,(4));
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {10,1,2,4,7,2};
  long long act_1 = (long long)longestSubarray(arr1_0, 6,(5));
  if (!(act_1 == 4LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {4,2,2,2,4,4,2,2};
  long long act_2 = (long long)longestSubarray(arr2_0, 8,(0));
  if (!(act_2 == 3LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1438, "longestSubarray", ntests);
 return (pass&&ntests)?0:1;
}
