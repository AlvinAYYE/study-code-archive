/*
 * ==========================================================================
 * LeetCode 0841. Keys and Rooms
 * Difficulty: Medium
 * Tags: depth-first-search, breadth-first-search, graph
 * URL: https://leetcode.com/problems/keys-and-rooms/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     There are n rooms labeled from 0 to n - 1 and all the rooms are
 *     locked except for room 0. Your goal is to visit all the rooms.
 *     However, you cannot enter a locked room without having its key.
 *     When you visit a room, you may find a set of distinct keys in it.
 *     Each key has a number on it, denoting which room it unlocks, and you
 *     can take all of them with you to unlock the other rooms.
 *     Given an array rooms where rooms[i] is the set of keys that you can
 *     obtain if you visited room i, return true if you can visit all the
 *     rooms, or false otherwise.
 *
 * [中文] 題目: 鑰匙和房間
 * [中文] 題目說明:
 *     共有編號 0 到 n−1 的房間，初始只有 0 號房間未上鎖；進入房
 *     間後可取得其中列出的房間鑰匙。給定 rooms，其中 rooms[i
 *     ] 是造訪 i 號房間可取得的相異鑰匙，判斷能否造訪所有房間。
 *
 * [中文] 思路:
 *     程式以佇列從 0 號房間開始進行廣度優先搜尋，並用陣列記錄已造訪房間
 *     。每次取出新房間後將其持有、尚未造訪的鑰匙入列，最後比較造訪數量是否
 *     等於房間數。
 *
 * Examples:
 *     Input: rooms = [[1],[2],[3],[]]
 *     Output: true
 *     Explanation:
 *     We visit room 0 and pick up key 1.
 *     We then visit room 1 and pick up key 2.
 *     We then visit room 2 and pick up key 3.
 *     We then visit room 3.
 *     Since we were able to visit every room, we return true.
 *     Input: rooms = [[1,3],[3,0,1],[2],[0]]
 *     Output: false
 *     Explanation: We can not enter room number 2 since the only key
 *     that unlocks it is in that room.
 *
 * Constraints:
 *   - n == rooms.length
 *   - 2 <= n <= 1000
 *   - 0 <= rooms[i].length <= 1000
 *   - 1 <= sum(rooms[i].length) <= 3000
 *   - 0 <= rooms[i][j] < n
 *   - All the values of rooms[i] are unique.
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
typedef struct queueInfo
{
	int size;
	int cur;
	int front;
	int rear;
	int *arr;
} QUEUE;

QUEUE* createQueue(int size)
{
	QUEUE *obj = malloc(sizeof(QUEUE));
	obj->size = size;
	obj->cur = 0;
	obj->front = 0;
	obj->rear = -1;
	obj->arr = malloc(sizeof(int)*size);
	return obj;
}

void destroyQueue(QUEUE *obj)
{
	free(obj->arr);
	free(obj);
}

bool isEmpty(QUEUE *obj)
{
	return (obj->cur == 0 ? true : false) ;
}

bool isFull(QUEUE *obj)
{
	return (obj->cur == obj->size ? true : false) ;
}

void addQueue(QUEUE *obj, int key)
{
	if (isFull(obj))
	{
		return;
	}
	obj->rear = (obj->rear+1) % obj->size;
	obj->arr[obj->rear] = key;
	obj->cur++;
}

int delQueue(QUEUE *obj)
{
	if (isEmpty(obj))
	{
		return;
	}
	int ret = obj->arr[obj->front];
	obj->front = (obj->front+1) % obj->size;
	obj->cur--;
	return ret;
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
	QUEUE *q = createQueue(roomsSize);
	// Checking record
	char *checkRoom = calloc(roomsSize, sizeof(char));
	// Record checking status
	int checkCtr = 1;
	checkRoom[0] = 1; 
	for (int i = 0; i < roomsColSize[0]; i++)
	{
		if (!checkRoom[rooms[0][i]])
		{
			addQueue(q, rooms[0][i]);
		}
	}

	while (!isEmpty(q))
	{
		int curKey = delQueue(q);
		// Room has been checked
		if (checkRoom[curKey])
		{
			continue;
		}
		// Update the record
		checkCtr++;
		checkRoom[curKey] = 1;
		for (int i = 0; i < roomsColSize[curKey]; i++)
		{
			if (!checkRoom[rooms[curKey][i]])
			{
				addQueue(q, rooms[curKey][i]);
			}
		}
		// All rooms have been checked
		if (checkCtr == roomsSize)
		{
			break;            
		}
	}

	free(checkRoom);
	destroyQueue(q);
	return (roomsSize == checkCtr) ? true : false;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {1};
  static int mr0_0_1[] = {2};
  static int mr0_0_2[] = {3};
  static int mr0_0_3[] = {0};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3};
  static int mc0_0[] = {1,1,1,0};
  bool act_0 = canVisitAllRooms(mp0_0, 4,mc0_0);
  if (!(act_0 == true)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,3};
  static int mr1_0_1[] = {3,0,1};
  static int mr1_0_2[] = {2};
  static int mr1_0_3[] = {0};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3};
  static int mc1_0[] = {2,3,1,1};
  bool act_1 = canVisitAllRooms(mp1_0, 4,mc1_0);
  if (!(act_1 == false)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 841, "canVisitAllRooms", ntests);
 return (pass&&ntests)?0:1;
}
