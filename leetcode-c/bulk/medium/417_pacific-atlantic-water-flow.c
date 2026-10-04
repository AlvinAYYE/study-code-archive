/*
 * ==========================================================================
 * LeetCode 0417. Pacific Atlantic Water Flow
 * Difficulty: Medium
 * Tags: array, depth-first-search, breadth-first-search, matrix
 * URL: https://leetcode.com/problems/pacific-atlantic-water-flow/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     There is an m x n rectangular island that borders both the Pacific
 *     Ocean and Atlantic Ocean. The Pacific Ocean touches the island's
 *     left and top edges, and the Atlantic Ocean touches the island's
 *     right and bottom edges.
 *     The island is partitioned into a grid of square cells. You are given
 *     an m x n integer matrix heights where heights[r][c] represents the
 *     height above sea level of the cell at coordinate (r, c).
 *     The island receives a lot of rain, and the rain water can flow to
 *     neighboring cells directly north, south, east, and west if the
 *     neighboring cell's height is less than or equal to the current
 *     cell's height. Water can flow from any cell adjacent to an ocean
 *     into the ocean.
 *     Return a 2D list of grid coordinates result where result[i] = [ri,
 *     ci] denotes that rain water can flow from cell (ri, ci) to both the
 *     Pacific and Atlantic oceans.
 *
 * [中文] 題目: 太平洋大西洋水流問題
 * [中文] 題目說明:
 *     給定一座 m×n 高度矩陣的島嶼，太平洋接觸左、上邊界，大西洋接觸右
 *     、下邊界。雨水可由目前格流向上下左右高度不高於目前格的相鄰格，請回傳
 *     能同時流到兩個海洋的所有座標。
 *
 * [中文] 思路:
 *     分別從兩個海洋相鄰的邊界反向 DFS，只走向高度不低於目前格的鄰居。
 *     程式以高度整數的額外位元標記兩海洋可達與已訪問狀態，最後收集同時帶有
 *     兩種可達標記的格子。
 *
 * Examples:
 *     Input: heights =
 *     [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 *     Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 *     Explanation: The following cells can flow to the Pacific and
 *     Atlantic oceans, as shown below:
 *     [0,4]: [0,4] -> Pacific Ocean
 *     [0,4] -> Atlantic Ocean
 *     [1,3]: [1,3] -> [0,3] -> Pacific Ocean
 *     [1,3] -> [1,4] -> Atlantic Ocean
 *     [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
 *     [1,4] -> Atlantic Ocean
 *     [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
 *     [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
 *     [3,0]: [3,0] -> Pacific Ocean
 *     [3,0] -> [4,0] -> Atlantic Ocean
 *     [3,1]: [3,1] -> [3,0] -> Pacific Ocean
 *     [3,1] -> [4,1] -> Atlantic Ocean
 *     [4,0]: [4,0] -> Pacific Ocean
 *     [4,0] -> Atlantic Ocean
 *     Note that there are other possible paths for these cells to
 *     flow to the Pacific and Atlantic oceans.
 *     Input: heights = [[1]]
 *     Output: [[0,0]]
 *     Explanation: The water can flow from the only cell to the
 *     Pacific and Atlantic oceans.
 *
 * Constraints:
 *   - m == heights.length
 *   - n == heights[r].length
 *   - 1 <= m, n <= 200
 *   - 0 <= heights[r][c] <= 10^5
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

// heights[][] is from 0x0 to 0x0186A0
// 0x1 00000 => pacific bit
// 0x2 00000 => pacific ocean is visited
// 0x4 00000 => atlantic bit
// 0x8 00000 => atlantic ocean is visited
#define PACIFIC_TAG           (0x100000)
#define ATLANTIC_TAG          (PACIFIC_TAG << 2)
#define FLOW_BOTH_TAG         (PACIFIC_TAG | ATLANTIC_TAG)
#define OCEAN_MASK            (0xFFFFF)
#define IS_VISITED(OCEAN)       (OCEAN << 1)

static void dfs(int** heights, int row_sz, int col_sz, int cur_x, int cur_y, int *ret_sz, int ocean)
{
    if (heights[cur_x][cur_y] & IS_VISITED(ocean))
        return;

    heights[cur_x][cur_y] |= (ocean | IS_VISITED(ocean));
    if ((heights[cur_x][cur_y] & FLOW_BOTH_TAG) == FLOW_BOTH_TAG) {
        *ret_sz += 1;
    }

    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int next_x = cur_x + dirs[i][0];
        int next_y = cur_y + dirs[i][1];
        if (next_x >= 0 && next_y >= 0 && next_x < row_sz && next_y < col_sz &&
                (heights[cur_x][cur_y] & OCEAN_MASK) <= (heights[next_x][next_y] & OCEAN_MASK)) {
            dfs(heights, row_sz, col_sz, next_x, next_y, ret_sz, ocean);
        }  
    }
}

int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes)
{
    int col_sz = heightsColSize[0];
    *returnSize = 0;

    for (int i = 0; i < heightsSize; i++) {
        dfs(heights, heightsSize, col_sz, i, 0, returnSize, PACIFIC_TAG);
        dfs(heights, heightsSize, col_sz, i, col_sz-1, returnSize, ATLANTIC_TAG);
    }

    for (int i = 0; i < col_sz; i++) {
        dfs(heights, heightsSize, col_sz, 0, i, returnSize, PACIFIC_TAG);
        dfs(heights, heightsSize, col_sz, heightsSize-1, i, returnSize, ATLANTIC_TAG);
    }

    int **ret = malloc(sizeof(int *)*(*returnSize)), ctr = 0;
    *returnColumnSizes = malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < heightsSize; i++) {
        for (int j = 0; j < col_sz; j++) {
            if ((heights[i][j] & FLOW_BOTH_TAG) == FLOW_BOTH_TAG) {
                ret[ctr] = malloc(sizeof(int)*2);
                ret[ctr][0] = i;
                ret[ctr][1] = j;
                (*returnColumnSizes)[ctr] = 2;
                ctr++;
            }
        }
    }
    return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  int *rcs_0 = 0;
  static int mr0_0_0[] = {1,2,2,3,5};
  static int mr0_0_1[] = {3,2,3,4,4};
  static int mr0_0_2[] = {2,4,5,3,1};
  static int mr0_0_3[] = {6,7,1,4,5};
  static int mr0_0_4[] = {5,1,1,2,4};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3,mr0_0_4};
  static int mc0_0[] = {5,5,5,5,5};
  int **act_0 = pacificAtlantic(mp0_0, 5,mc0_0,&rsz_0,&rcs_0);
  static char ibuf_0[400000]; lc_canon_ii(act_0, rcs_0, rsz_0, ibuf_0, sizeof ibuf_0);
  if (!(strcmp(ibuf_0, "[[0,3],[0,4],[0,4],[1,3],[1,3],[1,4],[2,2]]") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  int *rcs_1 = 0;
  static int mr1_0_0[] = {1};
  static int *mp1_0[] = {mr1_0_0};
  static int mc1_0[] = {1};
  int **act_1 = pacificAtlantic(mp1_0, 1,mc1_0,&rsz_1,&rcs_1);
  static char ibuf_1[400000]; lc_canon_ii(act_1, rcs_1, rsz_1, ibuf_1, sizeof ibuf_1);
  if (!(strcmp(ibuf_1, "[[0,0]]") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 417, "pacificAtlantic", ntests);
 return (pass&&ntests)?0:1;
}
