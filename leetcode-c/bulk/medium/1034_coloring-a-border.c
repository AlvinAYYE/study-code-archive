/*
 * ==========================================================================
 * LeetCode 1034. Coloring A Border
 * Difficulty: Medium
 * Tags: array, depth-first-search, breadth-first-search, matrix
 * URL: https://leetcode.com/problems/coloring-a-border/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an m x n integer matrix grid, and three integers row,
 *     col, and color. Each value in the grid represents the color of the
 *     grid square at that location.
 *     Two squares are called adjacent if they are next to each other in
 *     any of the 4 directions.
 *     Two squares belong to the same connected component if they have the
 *     same color and they are adjacent.
 *     The border of a connected component is all the squares in the
 *     connected component that are either adjacent to (at least) a square
 *     not in the component, or on the boundary of the grid (the first or
 *     last row or column).
 *     You should color the border of the connected component that contains
 *     the square grid[row][col] with color.
 *     Return the final grid.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個 m × n 的 整數 矩陣 網格, and three integers 行, col, and color. Each
 *     value in the 網格 represents the color of the 網格 square at that
 *     location.
 *
 * Examples:
 *     Input: grid = [[1,1],[1,2]], row = 0, col = 0, color = 3
 *     Output: [[3,3],[3,2]]
 *     Input: grid = [[1,2,2],[2,3,2]], row = 0, col = 1, color = 3
 *     Output: [[1,3,3],[2,3,3]]
 *     Input: grid = [[1,1,1],[1,1,1],[1,1,1]], row = 1, col = 1,
 *     color = 2
 *     Output: [[2,2,2],[2,1,2],[2,2,2]]
 *
 * Constraints:
 *   - m == grid.length
 *   - n == grid[i].length
 *   - 1 <= m, n <= 50
 *   - 1 <= grid[i][j], color <= 1000
 *   - 0 <= row < m
 *   - 0 <= col < n
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
#define IS_VISITED  (1)
#define IS_BOARDER  (2)

typedef struct dataInfo
{
	int x;
	int y;
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

void addQueue(QUEUE *obj, int row, int col)
{
	if (isFull(obj))
	{
		return;
	}
	obj->rear = (obj->rear+1) % obj->size;
	obj->data[obj->rear].x = row;
	obj->data[obj->rear].y = col;
	obj->cur++;
}

DATA delQueue(QUEUE *obj)
{
	DATA ret = obj->data[obj->front];
	obj->front = (obj->front+1) % obj->size;
	obj->cur--;
	return ret;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** colorBorder(int** grid, int gridSize, int* gridColSize, int r0, int c0, int color, int* returnSize, int** returnColumnSizes)
{
	int colSize = gridColSize[0];
	int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int **visited = malloc(sizeof(int *)*gridSize);
	for (int i = 0; i < gridSize; i++)
	{
		visited[i] = calloc(colSize, sizeof(int));
	}        

	QUEUE *q = createQueue(gridSize*colSize);
	addQueue(q, r0, c0);
	int connectedColor = grid[r0][c0];

	while (!isEmpty(q))
	{        
		DATA tmp = delQueue(q);
		if (visited[tmp.x][tmp.y])
		{
			continue;
		}
		int found = 0;
		for (int i = 0; i < 4; i++)
		{
			int curX = tmp.x + dir[i][0];
			int curY = tmp.y + dir[i][1];
			if (curX < 0 || curX >= gridSize || curY < 0 || curY >= colSize || visited[curX][curY])
			{
				continue;
			}

			if (connectedColor == grid[curX][curY])
			{
				addQueue(q, curX, curY);
			} else
			{
				found = 1;
			}
		}
		if (tmp.x == 0 || tmp.y == 0 || tmp.x == gridSize-1 || tmp.y == colSize-1 || found)
		{
			grid[tmp.x][tmp.y] = color;
			visited[tmp.x][tmp.y] = IS_BOARDER;
		} else
		{
			visited[tmp.x][tmp.y] = IS_VISITED;
		}
	}

	*returnSize = gridSize;
	(*returnColumnSizes) = malloc(sizeof(int)*gridSize);
	for (int i = 0; i < gridSize; i++)
	{        
		(*returnColumnSizes)[i] = colSize;
	}
	for (int i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < colSize; j++)
		{
			if (IS_BOARDER == visited[i][j])
			{
				grid[i][j] = color;
			}
		}        
	}

	destroyQueue(q);
	for (int i = 0; i < gridSize; i++)
	{
		free(visited[i]);        
	}
	free(visited);

	return grid;
}



/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  int *rcs_0 = 0;
  static int mr0_0_0[] = {1,1};
  static int mr0_0_1[] = {1,2};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1};
  static int mc0_0[] = {2,2};
  int **act_0 = colorBorder(mp0_0, 2,mc0_0,(0),(0),(3),&rsz_0,&rcs_0);
  static char ibuf_0[400000]; lc_canon_ii(act_0, rcs_0, rsz_0, ibuf_0, sizeof ibuf_0);
  if (!(strcmp(ibuf_0, "[[2,3],[3,3]]") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  int *rcs_1 = 0;
  static int mr1_0_0[] = {1,2,2};
  static int mr1_0_1[] = {2,3,2};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1};
  static int mc1_0[] = {3,3};
  int **act_1 = colorBorder(mp1_0, 2,mc1_0,(0),(1),(3),&rsz_1,&rcs_1);
  static char ibuf_1[400000]; lc_canon_ii(act_1, rcs_1, rsz_1, ibuf_1, sizeof ibuf_1);
  if (!(strcmp(ibuf_1, "[[1,3,3],[2,3,3]]") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  int *rcs_2 = 0;
  static int mr2_0_0[] = {1,1,1};
  static int mr2_0_1[] = {1,1,1};
  static int mr2_0_2[] = {1,1,1};
  static int *mp2_0[] = {mr2_0_0,mr2_0_1,mr2_0_2};
  static int mc2_0[] = {3,3,3};
  int **act_2 = colorBorder(mp2_0, 3,mc2_0,(1),(1),(2),&rsz_2,&rcs_2);
  static char ibuf_2[400000]; lc_canon_ii(act_2, rcs_2, rsz_2, ibuf_2, sizeof ibuf_2);
  if (!(strcmp(ibuf_2, "[[1,2,2],[2,2,2],[2,2,2]]") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1034, "colorBorder", ntests);
 return (pass&&ntests)?0:1;
}
