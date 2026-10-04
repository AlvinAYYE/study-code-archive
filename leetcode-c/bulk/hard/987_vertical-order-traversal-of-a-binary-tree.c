/*
 * ==========================================================================
 * LeetCode 0987. Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Tags: hash-table, tree, depth-first-search, breadth-first-search, sorting, binary-tree
 * URL: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given the root of a binary tree, calculate the vertical order
 *     traversal of the binary tree.
 *     For each node at position (row, col), its left and right children
 *     will be at positions (row + 1, col - 1) and (row + 1, col + 1)
 *     respectively. The root of the tree is at (0, 0).
 *     The vertical order traversal of a binary tree is a list of
 *     top-to-bottom orderings for each column index starting from the
 *     leftmost column and ending on the rightmost column. There may be
 *     multiple nodes in the same row and same column. In such a case, sort
 *     these nodes by their values.
 *     Return the vertical order traversal of the binary tree.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     Given the 根節點 of a binary 樹, calculate the vertical order traversal
 *     of the binary 樹.
 *
 * Examples:
 *     Input: root = [3,9,20,null,null,15,7]
 *     Output: [[9],[3,15],[20],[7]]
 *     Explanation:
 *     Column -1: Only node 9 is in this column.
 *     Column 0: Nodes 3 and 15 are in this column in that order from
 *     top to bottom.
 *     Column 1: Only node 20 is in this column.
 *     Column 2: Only node 7 is in this column.
 *     Input: root = [1,2,3,4,5,6,7]
 *     Output: [[4],[2],[1,5,6],[3],[7]]
 *     Explanation:
 *     Column -2: Only node 4 is in this column.
 *     Column -1: Only node 2 is in this column.
 *     Column 0: Nodes 1, 5, and 6 are in this column.
 *     1 is at the top, so it comes first.
 *     5 and 6 are at the same position (2, 0), so we order them by
 *     their value, 5 before 6.
 *     Column 1: Only node 3 is in this column.
 *     Column 2: Only node 7 is in this column.
 *     Input: root = [1,2,3,4,6,5,7]
 *     Output: [[4],[2],[1,5,6],[3],[7]]
 *     Explanation:
 *     This case is the exact same as example 2, but with nodes 5 and
 *     6 swapped.
 *     Note that the solution remains the same since 5 and 6 are in
 *     the same location and should be ordered by their values.
 *
 * Constraints:
 *   - The number of nodes in the tree is in the range [1, 1000].
 *   - 0 <= Node.val <= 1000
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
#define INFO_SIZE_UNIT 500

typedef struct TreeNode NODE;
typedef struct
{
	int val;
	int pos;
	int lv;
}INFO;


void traversal(NODE *root, int pos, int level, INFO **data, int *dataCtr)
{
	if (root == NULL)
	{
		return;
	}

	traversal(root->left, pos-1, level+1, data, dataCtr);
	// Add info
	(*data)[*dataCtr].val = root->val;
	(*data)[*dataCtr].pos = pos;
	(*data)[*dataCtr].lv = level;
	*dataCtr += 1;
	if (0 == *dataCtr % INFO_SIZE_UNIT)
	{
		*data = realloc(*data, sizeof(INFO)*(*dataCtr + INFO_SIZE_UNIT));
	}

	traversal(root->right, pos+1, level+1, data, dataCtr);
}

int compare(void *a, void *b)
{
	INFO *n1 = (INFO *)a;
	INFO *n2 = (INFO *)b;

	if (n1->pos == n2->pos)
	{
		return (n1->lv == n2->lv ? n1->val - n2->val : n1->lv - n2->lv);
	}
	return n1->pos - n2->pos;
}

int** verticalTraversal(NODE* root, int* returnSize, int** returnColumnSizes)
{
	INFO *data = malloc(sizeof(INFO)*INFO_SIZE_UNIT);
	int dataCtr = 0;
	traversal(root, 0, 0, &data, &dataCtr);

	qsort(data, dataCtr, sizeof(INFO), compare);

	int **ret = malloc(sizeof(int*));
	*returnColumnSizes = malloc(sizeof(int));

	// The tree must has "1" nodes
	ret[0] = malloc(sizeof(int));
	(*returnColumnSizes)[0] = 1;
	ret[0][0] = data[0].val;
	int retCtr = 1;    
	for (int i = 1; i < dataCtr; i++)
	{
		if (data[i].pos == data[i-1].pos)
		{
			int tmp = retCtr-1;            
			ret[tmp] = realloc(ret[tmp], sizeof(int)*((*returnColumnSizes)[tmp] + 1));            
			ret[tmp][(*returnColumnSizes)[tmp]] = data[i].val;
			(*returnColumnSizes)[tmp] += 1;
		} else
		{
			ret = realloc(ret, sizeof(int *)*(retCtr+1));
			*returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(retCtr+1));                
			ret[retCtr] = malloc(sizeof(int));
			(*returnColumnSizes)[retCtr] = 1;
			ret[retCtr][0] = data[i].val;
			retCtr ++;            
		}
	}

	*returnSize = retCtr;
	return ret;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  int *rcs_0 = 0;
  static const int tk0_0[] = {3,9,20,-2147483400,-2147483400,15,7};
  int **act_0 = verticalTraversal(lc_mktree(tk0_0, 7),&rsz_0,&rcs_0);
  static char ibuf_0[400000]; lc_canon_ii(act_0, rcs_0, rsz_0, ibuf_0, sizeof ibuf_0);
  if (!(strcmp(ibuf_0, "[[20],[3,15],[7],[9]]") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  int *rcs_1 = 0;
  static const int tk1_0[] = {1,2,3,4,5,6,7};
  int **act_1 = verticalTraversal(lc_mktree(tk1_0, 7),&rsz_1,&rcs_1);
  static char ibuf_1[400000]; lc_canon_ii(act_1, rcs_1, rsz_1, ibuf_1, sizeof ibuf_1);
  if (!(strcmp(ibuf_1, "[[1,5,6],[2],[3],[4],[7]]") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  int *rcs_2 = 0;
  static const int tk2_0[] = {1,2,3,4,6,5,7};
  int **act_2 = verticalTraversal(lc_mktree(tk2_0, 7),&rsz_2,&rcs_2);
  static char ibuf_2[400000]; lc_canon_ii(act_2, rcs_2, rsz_2, ibuf_2, sizeof ibuf_2);
  if (!(strcmp(ibuf_2, "[[1,5,6],[2],[3],[4],[7]]") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 987, "verticalTraversal", ntests);
 return (pass&&ntests)?0:1;
}
