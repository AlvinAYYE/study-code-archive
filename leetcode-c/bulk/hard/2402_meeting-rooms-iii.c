/*
 * ==========================================================================
 * LeetCode 2402. Meeting Rooms III
 * Difficulty: Hard
 * Tags: array, hash-table, sorting, heap-(priority-queue, simulation
 * URL: https://leetcode.com/problems/meeting-rooms-iii/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an integer n. There are n rooms numbered from 0 to n -
 *     1.
 *     You are given a 2D integer array meetings where meetings[i] =
 *     [starti, endi] means that a meeting will be held during the
 *     half-closed time interval [starti, endi). All the values of starti
 *     are unique.
 *     Meetings are allocated to rooms in the following manner:
 *     Return the number of the room that held the most meetings. If there
 *     are multiple rooms, return the room with the lowest number.
 *     A half-closed interval [a, b) is the interval between a and b
 *     including a and not including b.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個整數 n. There are n rooms numbered from 0 to n - 1.
 *
 * Examples:
 *     Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
 *     Output: 0
 *     Explanation:
 *     - At time 0, both rooms are not being used. The first meeting
 *     starts in room 0.
 *     - At time 1, only room 1 is not being used. The second meeting
 *     starts in room 1.
 *     - At time 2, both rooms are being used. The third meeting is
 *     delayed.
 *     - At time 3, both rooms are being used. The fourth meeting is
 *     delayed.
 *     - At time 5, the meeting in room 1 finishes. The third meeting
 *     starts in room 1 for the time period [5,10).
 *     - At time 10, the meetings in both rooms finish. The fourth
 *     meeting starts in room 0 for the time period [10,11).
 *     Both rooms 0 and 1 held 2 meetings, so we return 0.
 *     Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
 *     Output: 1
 *     Explanation:
 *     - At time 1, all three rooms are not being used. The first
 *     meeting starts in room 0.
 *     - At time 2, rooms 1 and 2 are not being used. The second
 *     meeting starts in room 1.
 *     - At time 3, only room 2 is not being used. The third meeting
 *     starts in room 2.
 *     - At time 4, all three rooms are being used. The fourth
 *     meeting is delayed.
 *     - At time 5, the meeting in room 2 finishes. The fourth
 *     meeting starts in room 2 for the time period [5,10).
 *     - At time 6, all three rooms are being used. The fifth meeting
 *     is delayed.
 *     - At time 10, the meetings in rooms 1 and 2 finish. The fifth
 *     meeting starts in room 1 for the time period [10,12).
 *     Room 0 held 1 meeting while rooms 1 and 2 each held 2
 *     meetings, so we return 1.
 *
 * Constraints:
 *   - 1 <= n <= 100
 *   - 1 <= meetings.length <= 10^5
 *   - meetings[i].length == 2
 *   - 0 <= starti < endi <= 5 * 10^5
 *   - All the values of starti are unique.
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

Approach: Heap

Clearly, we first need to keep track of which rooms are currently occupied and
how many meetings have been scheduled in each room.

Furthermore, to determine the point in time to which subsequent meetings should
be delayed if necessary, we need to record the end times of all meetings
currently in progress. Since the earliest ending meeting will be replaced by
later meetings, the data structure used for recording needs to dynamically
maintain the minimum value among all end times, and a min_heap(priority queue)
can fulfill this scenario.

Process the data itself, we need to sort them ourselves
in ascending order of start time. (This problem does not guarantee that the
given meeting times will be sorted by start time)

Then iterate over each meeting after sorting:
Suppose the current meeting is m, with time interval [L, R). If it is observed
that the minimum value in the min_heap (the meeting that ends earliest) starts
before m, i.e., "the earliest end time"   L, then m will be scheduled in the
room of this ended meeting. The judgment condition includes the case of "="
because the meeting time is a half-closed interval, so the end time itself can
accommodate the start of another meeting; or if the number of elements in the
min_heap reaches n, meaning all rooms are occupied, then the room of the
earliest ending meeting must be vacated.

If only the latter condition of the above situation is satisfied (all rooms are
occupied), it means the earliest ending time (denoted as X) is greater than L.
Therefore, we need to additionally adjust the time interval of m to [X, X + (R -
L)).

Regardless of whether the above situation occurs or not, at this stage, there
must be rooms available. Therefore,
we iterate from index 0 to index n - 1 to find which room is available (using
the rooms_usage for judgment). Suppose the found room is room i, then we
need to increment rooms_usage[i].ctr by 1, indicating that room i has one more
meeting scheduled. Then, we add the end time of m (either the original R or X +
(R - L), depending on whether the previous condition is met) and the room number
used to the min_heap.

***/

typedef struct {
    int used;
    int ctr;
} room_t;

typedef struct {
    long long** arr;
    int cur_sz;
    int sz;
} heap_t;

#define MAX(a, b) (a > b ? a : b)

static inline int* heap_size(heap_t* obj) { return obj->cur_sz; }
static inline bool heap_is_empty(heap_t* obj) { return (heap_size(obj) == 0); }
static inline long long* heap_top(heap_t* obj) { return obj->arr[0]; }

static inline heap_t* heap_init(int sz) {
    heap_t* obj = malloc(sizeof(heap_t));
    obj->arr = malloc(sizeof(long long*) * sz);
    for (int i = 0; i < sz; i++)
        obj->arr[i] = malloc(sizeof(long long) * 2);
    obj->cur_sz = 0;
    obj->sz = sz;
    return obj;
}

static inline void heap_dinit(heap_t* obj) {
    for (int i = 0; i < obj->sz; i++)
        free(obj->arr[i]);
    free(obj->arr);
    free(obj);
}

static inline void swap(long long** a, long long** b) {
    long long* tmp = *a;
    *a = *b;
    *b = tmp;
}

static void min_heapify_bottom_up(long long** arr, int i) {
    int parent = ((i - 1) >> 1);
    if (parent >= 0) {
        if (arr[i][0] < arr[parent][0] ||
            (arr[i][0] == arr[parent][0] && arr[i][1] < arr[parent][1])) {
            swap(&arr[i], &arr[parent]);
            min_heapify_bottom_up(arr, parent);
        }
    }
}

static void min_heapify(long long** arr, int cur, int size) {
    int l_chd = (cur << 1) + 1;
    int r_chd = (cur << 1) + 2;
    int min = cur;
    if (l_chd < size &&
        (arr[l_chd][0] < arr[min][0] ||
         (arr[l_chd][0] == arr[min][0] && arr[l_chd][1] < arr[min][1])))
        min = l_chd;
    if (r_chd < size &&
        (arr[r_chd][0] < arr[min][0] ||
         (arr[r_chd][0] == arr[min][0] && arr[r_chd][1] < arr[min][1])))
        min = r_chd;

    if (min != cur) {
        swap(&arr[min], &arr[cur]);
        min_heapify(arr, min, size);
    }
}

static void heap_pop(heap_t* obj) {
    obj->arr[0][0] = obj->arr[obj->cur_sz - 1][0];
    obj->arr[0][1] = obj->arr[obj->cur_sz - 1][1];
    obj->cur_sz -= 1;
    min_heapify(obj->arr, 0, obj->cur_sz);
}

static void heap_push(heap_t* obj, long time, long id) {

    obj->arr[obj->cur_sz][0] = time;
    obj->arr[obj->cur_sz][1] = id;

    min_heapify_bottom_up(obj->arr, obj->cur_sz);
    obj->cur_sz += 1;
}

static int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), compare);
    heap_t* occupied = heap_init(n);
    room_t* rooms_usage = calloc(n, sizeof(room_t));
    // Note: use long long to avoid integer overflow
    long long begin_t_adjusted = 0;
    for (int i = 0; i < meetingsSize; i++) {
        long long cur_meeting_head = (long long)meetings[i][0];
        long long cur_meeting_tail = (long long)meetings[i][1];
        begin_t_adjusted = MAX(begin_t_adjusted, cur_meeting_head);
        while (!heap_is_empty(occupied) &&
               (heap_size(occupied) == n ||
                begin_t_adjusted >= (heap_top(occupied))[0])) {
            long long* occu_top = heap_top(occupied);
            begin_t_adjusted = MAX(begin_t_adjusted, occu_top[0]);
            rooms_usage[occu_top[1]].used = 0;
            heap_pop(occupied);
        }

        for (int rid = 0; rid < n; rid++) {
            if (0 == rooms_usage[rid].used) {
                long long ending_time =
                    begin_t_adjusted + cur_meeting_tail - cur_meeting_head;
                rooms_usage[rid].used = 1;
                rooms_usage[rid].ctr += 1;
                heap_push(occupied, ending_time, rid);
                break;
            }
        }
    }

    int ret = 0;
    for (int rid = 0; rid < n; rid++) {
        if (rooms_usage[rid].ctr > rooms_usage[ret].ctr)
            ret = rid;
    }

    free(rooms_usage);
    heap_dinit(occupied);
    return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_1_0[] = {0,10};
  static int mr0_1_1[] = {1,5};
  static int mr0_1_2[] = {2,7};
  static int mr0_1_3[] = {3,4};
  static int *mp0_1[] = {mr0_1_0,mr0_1_1,mr0_1_2,mr0_1_3};
  static int mc0_1[] = {2,2,2,2};
  long long act_0 = (long long)mostBooked((2),mp0_1, 4,mc0_1);
  if (!(act_0 == 0LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_1_0[] = {1,20};
  static int mr1_1_1[] = {2,10};
  static int mr1_1_2[] = {3,5};
  static int mr1_1_3[] = {4,9};
  static int mr1_1_4[] = {6,8};
  static int *mp1_1[] = {mr1_1_0,mr1_1_1,mr1_1_2,mr1_1_3,mr1_1_4};
  static int mc1_1[] = {2,2,2,2,2};
  long long act_1 = (long long)mostBooked((3),mp1_1, 5,mc1_1);
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 2402, "mostBooked", ntests);
 return (pass&&ntests)?0:1;
}
