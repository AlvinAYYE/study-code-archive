/*
 * ==========================================================================
 * LeetCode 0909. Snakes and Ladders
 * Difficulty: Medium
 * Tags: array, breadth-first-search, matrix
 * URL: https://leetcode.com/problems/snakes-and-ladders/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an n x n integer matrix board where the cells are
 *     labeled from 1 to n2 in a Boustrophedon style starting from the
 *     bottom left of the board (i.e. board[n - 1][0]) and alternating
 *     direction each row.
 *     You start on square 1 of the board. In each move, starting from
 *     square curr, do the following:
 *     A board square on row r and column c has a snake or ladder if
 *     board[r][c] != -1. The destination of that snake or ladder is
 *     board[r][c]. Squares 1 and n2 are not the starting points of any
 *     snake or ladder.
 *     Note that you only take a snake or ladder at most once per dice
 *     roll. If the destination to a snake or ladder is the start of
 *     another snake or ladder, you do not follow the subsequent snake or
 *     ladder.
 *     Return the least number of dice rolls required to reach the square
 *     n2. If it is not possible to reach the square, return -1.
 *
 * [中文] 題目: 蛇梯棋
 * [中文] 題目說明:
 *     給定 n × n 棋盤，方格從左下角的 1 起按蛇形編號至 n²，且
 *     每列方向交替。從 1 出發時，每次擲骰可前進 1 到 6 格；落在有
 *     蛇或梯子的格子必須立即移至其指定終點，但同一次擲骰不會繼續連鎖移動。
 *     求抵達 n² 的最少擲骰次數，若無法抵達則回傳 -1。
 *
 * [中文] 思路:
 *     將格號換算為棋盤座標後，以 BFS 逐層枚舉每次可走的六個目的地；入
 *     隊前套用至多一次蛇或梯子，並以走訪標記避免重複搜尋。
 *
 * Examples:
 *     Input: board =
 *     [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
 *     Output: 4
 *     Explanation:
 *     In the beginning, you start at square 1 (at row 5, column 0).
 *     You decide to move to square 2 and must take the ladder to
 *     square 15.
 *     You then decide to move to square 17 and must take the snake
 *     to square 13.
 *     You then decide to move to square 14 and must take the ladder
 *     to square 35.
 *     You then decide to move to square 36, ending the game.
 *     This is the lowest possible number of moves to reach the last
 *     square, so return 4.
 *     Input: board = [[-1,-1],[-1,3]]
 *     Output: 1
 *
 * Constraints:
 *   - n == board.length == board[i].length
 *   - 2 <= n <= 20
 *   - board[i][j] is either -1 or in the range [1, n2].
 *   - The squares labeled 1 and n2 are not the starting points of
 *   any snake or ladder.
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
typedef struct
{
	int step;
	int val;
} DATA;

typedef struct queueInfo
{
	int size;
	int cur;
	int front;
	int rear;
	DATA *data;
} QUEUE;

QUEUE* createQueue(int size)
{
	QUEUE *obj = malloc(sizeof(QUEUE));
	obj->size = size;
	obj->cur = 0;
	obj->front = 0;
	obj->rear = -1;
	obj->data = malloc(sizeof(DATA)*size);
	return obj;
}

void destroyQueue(QUEUE *obj)
{
	free(obj->data);
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

void addQueue(QUEUE *obj, int step, int val)
{
	if (isFull(obj))
	{
		return;
	}
	obj->rear = (obj->rear+1) % obj->size;
	obj->data[obj->rear].step = step;
	obj->data[obj->rear].val = val;
	obj->cur++;
}

DATA delQueue(QUEUE *obj)
{
	if (isEmpty(obj))
	{
		return;
	}
	DATA ret = obj->data[obj->front];
	obj->front = (obj->front+1) % obj->size;
	obj->cur--;
	return ret;
}

void transferCoordinate(int boardSize, int val, int *x, int *y)
{
	*x = (boardSize-1) - (val / boardSize);
	*y = ((boardSize - 1 - *x) % 2 == 0 ? val % boardSize : (boardSize - 1 - (val % boardSize)));
}

int snakesAndLadders(int** board, int boardSize, int* boardColSize)
{
	int minStep, endX, endY, addVal;
	char **visited = malloc(sizeof(int *)*boardSize);
	for (int i = 0; i < boardSize; i++)
	{
		visited[i] = calloc(boardSize, sizeof(int));
	}

	QUEUE *q = createQueue(boardSize*boardSize);
	minStep = boardSize+1;

	// Calculate the end point
	endX = 0;
	endY = (boardSize % 2 == 0 ? 0 : boardSize-1);
	// Add the first square info
	addVal = (board[0][0] == -1 ? 0: board[0][0]-1);
	addQueue(q, 0, addVal);
	while (!isEmpty(q))
	{
		DATA cur = delQueue(q);
		int x, y;
		transferCoordinate(boardSize, cur.val, &x, &y);
		if (x == endX && y == endY)
		{
			minStep = (minStep < (cur.step) ? minStep : (cur.step));
		}
		// move at most 6 destinations
		int tmpVal = cur.val + 1;
		while (tmpVal <= cur.val + 6)
		{
			if (tmpVal == boardSize*boardSize)
			{
				break;
			}

			transferCoordinate(boardSize, tmpVal, &x, &y);
			if (visited[x][y])
			{
				tmpVal++;
				continue;
			}         

			if (x == endX && y == endY)
			{
				minStep = (minStep < (cur.step + 1) ? minStep : (cur.step + 1));
			}

			addVal = (board[x][y] != -1) ? (board[x][y]-1) : tmpVal;
			addQueue(q, cur.step + 1, addVal);
			// Ignore the duplicate point
			visited[x][y] = 1;

			tmpVal++;            
		}
	}

	destroyQueue(q);
	for (int i = 0; i < boardSize; i++)
	{
		free(visited[i]);
	}
	free(visited);

	return (minStep == boardSize+1) ? -1 : minStep;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {-1,-1,-1,-1,-1,-1};
  static int mr0_0_1[] = {-1,-1,-1,-1,-1,-1};
  static int mr0_0_2[] = {-1,-1,-1,-1,-1,-1};
  static int mr0_0_3[] = {-1,35,-1,-1,13,-1};
  static int mr0_0_4[] = {-1,-1,-1,-1,-1,-1};
  static int mr0_0_5[] = {-1,15,-1,-1,-1,-1};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3,mr0_0_4,mr0_0_5};
  static int mc0_0[] = {6,6,6,6,6,6};
  long long act_0 = (long long)snakesAndLadders(mp0_0, 6,mc0_0);
  if (!(act_0 == 4LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {-1,-1};
  static int mr1_0_1[] = {-1,3};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1};
  static int mc1_0[] = {2,2};
  long long act_1 = (long long)snakesAndLadders(mp1_0, 2,mc1_0);
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 909, "snakesAndLadders", ntests);
 return (pass&&ntests)?0:1;
}
