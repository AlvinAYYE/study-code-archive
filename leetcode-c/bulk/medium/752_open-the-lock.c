/*
 * ==========================================================================
 * LeetCode 0752. Open the Lock
 * Difficulty: Medium
 * Tags: array, hash-table, string, breadth-first-search
 * URL: https://leetcode.com/problems/open-the-lock/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You have a lock in front of you with 4 circular wheels. Each wheel
 *     has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The
 *     wheels can rotate freely and wrap around: for example we can turn
 *     '9' to be '0', or '0' to be '9'. Each move consists of turning one
 *     wheel one slot.
 *     The lock initially starts at '0000', a string representing the state
 *     of the 4 wheels.
 *     You are given a list of deadends dead ends, meaning if the lock
 *     displays any of these codes, the wheels of the lock will stop
 *     turning and you will be unable to open it.
 *     Given a target representing the value of the wheels that will unlock
 *     the lock, return the minimum total number of turns required to open
 *     the lock, or -1 if it is impossible.
 *
 * [中文] 題目: 打開轉盤鎖
 * [中文] 題目說明:
 *     四位轉盤鎖從 0000 開始，每次可將任一位向上或向下轉一格，且 9
 *      與 0 可循環相接。給定無法通過的 deadends 與目標 ta
 *     rget，求到達 target 的最少轉動次數；若起點或路徑受死鎖限
 *     制而無法到達則回傳 -1。
 *
 * [中文] 思路:
 *     以 BFS 從 0000 展開狀態，對每個轉盤位置產生加一與減一共八
 *     個鄰居。四維標記表同時記錄死鎖與已拜訪狀態，首次抵達目標的層數就是最
 *     少轉動數。
 *
 * Examples:
 *     Input: deadends = ["0201","010^1","010^2","1212","2002"],
 *     target = "0202"
 *     Output: 6
 *     Explanation:
 *     A sequence of valid moves would be "0000" -> "1000" -> "1100"
 *     -> "1200" -> "1201" -> "1202" -> "0202".
 *     Note that a sequence like "0000" -> "0001" -> "0002" ->
 *     "010^2" -> "0202" would be invalid,
 *     because the wheels of the lock become stuck after the display
 *     becomes the dead end "010^2".
 *     Input: deadends = ["8888"], target = "0009"
 *     Output: 1
 *     Explanation: We can turn the last wheel in reverse to move
 *     from "0000" -> "0009".
 *     Input: deadends =
 *     ["8887","8889","8878","8898","8788","8988","7888","9888"],
 *     target = "8888"
 *     Output: -1
 *     Explanation: We cannot reach the target without getting stuck.
 *
 * Constraints:
 *   - 1 <= deadends.length <= 500
 *   - deadends[i].length == 4
 *   - target.length == 4
 *   - target will not be in the list deadends.
 *   - target and deadends[i] consist of digits only.
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
/**
752. Open the Lock [M]
Ref: https://leetcode.com/problems/open-the-lock/

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

 */

typedef struct queueInfo
{
	int size;
	int cur;
	int front;
	int rear;
	/* q[X][0]-q[X][3] save the index, 
	   q[X][4] save the wheels turns 
	 */
	int q[10000][5];
} QUEUE;

QUEUE* createQueue()
{
	QUEUE *obj = malloc(sizeof(QUEUE));
	obj->size = 10000;
	obj->cur = 0;
	obj->front = 0;
	obj->rear = -1;

	return obj;
}

void destroyQueue(QUEUE *obj)
{
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

void addQueue(QUEUE *obj, int x, int y, int z, int w, int turns)
{
	if (isFull(obj))
	{
		return;
	}
	obj->rear = (obj->rear+1) % obj->size;
	obj->q[obj->rear][0] = x;
	obj->q[obj->rear][1] = y;
	obj->q[obj->rear][2] = z;
	obj->q[obj->rear][3] = w;
	obj->q[obj->rear][4] = turns;
	obj->cur++;
}

int* delQueue(QUEUE *obj)
{
	if (isEmpty(obj))
	{
		return;
	}
	int *ret = obj->q[obj->front];
	obj->front = (obj->front+1) % obj->size;
	obj->cur--;

	return ret;
}

int openLock(char ** deadends, int deadendsSize, char * target)
{
	if (!strcmp(target,"0000"))
	{
		return -1;
	}

	char map[10][10][10][10];
	memset(map, 0, sizeof(char)*10000);
	QUEUE *queue = createQueue();
	for (int i = 0; i < deadendsSize; i++)
	{
		if (!strcmp(deadends[i],"0000"))
		{
			return -1;
		}
		/* set 1 to indicate the deadends */
		map[deadends[i][0]-'0'][deadends[i][1]-'0'][deadends[i][2]-'0'][deadends[i][3]-'0'] = 1;
	}
	/* set 2 to indicate the end */
	map[target[0]-'0'][target[1]-'0'][target[2]-'0'][target[3]-'0'] = 2;

	addQueue(queue, 0, 0, 0, 0, 0);
	int dir[8][4] = {{1,0,0,0}, {9,0,0,0}, {0,1,0,0}, {0,9,0,0}, 
		{0,0,1,0}, {0,0,9,0}, {0,0,0,1}, {0,0,0,9}};
	/* BFS */
	while (!isEmpty(queue))
	{
		int *cur= delQueue(queue);
		map[cur[0]][cur[1]][cur[2]][cur[3]] = -1;

		int curTurns = cur[4]+1;
		for (int i = 0; i < 8; i++)
		{
			int n1 = (cur[0] + dir[i][0]) % 10;
			int n2 = (cur[1] + dir[i][1]) % 10;
			int n3 = (cur[2] + dir[i][2]) % 10;
			int n4 = (cur[3] + dir[i][3]) % 10;
			if (2 == map[n1][n2][n3][n4])
			{
				return curTurns;
			}
			if (0 == map[n1][n2][n3][n4])
			{
				map[n1][n2][n3][n4] = 1;
				addQueue(queue, n1, n2, n3, n4, curTurns);
			}
		}       
	}

	destroyQueue(queue);
	return -1;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static char *sa0_0[] = {"0201","0101","0102","1212","2002"};
  char target_0[] = "0202";
  long long act_0 = (long long)openLock(sa0_0, 5,target_0);
  if (!(act_0 == 6LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static char *sa1_0[] = {"8888"};
  char target_1[] = "0009";
  long long act_1 = (long long)openLock(sa1_0, 1,target_1);
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static char *sa2_0[] = {"8887","8889","8878","8898","8788","8988","7888","9888"};
  char target_2[] = "8888";
  long long act_2 = (long long)openLock(sa2_0, 8,target_2);
  if (!(act_2 == -1LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 752, "openLock", ntests);
 return (pass&&ntests)?0:1;
}
