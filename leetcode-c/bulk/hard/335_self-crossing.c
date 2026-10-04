/*
 * ==========================================================================
 * LeetCode 0335. Self Crossing
 * Difficulty: Hard
 * Tags: array, math, geometry
 * URL: https://leetcode.com/problems/self-crossing/
 * Source: community solution, repo tongtzeho_LeetCode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an array of integers distance.
 *     You start at the point (0, 0) on an X-Y plane, and you move
 *     distance[0] meters to the north, then distance[1] meters to the
 *     west, distance[2] meters to the south, distance[3] meters to the
 *     east, and so on. In other words, after each move, your direction
 *     changes counter-clockwise.
 *     Return true if your path crosses itself or false if it does not.
 *
 * [中文] 題目: 路徑交叉
 * [中文] 題目說明:
 *     從原點開始，依序向北、西、南、東移動 distance[0]、dis
 *     tance[1]、distance[2]、distance[3] 的
 *     距離，之後持續以逆時針方向循環。請判斷走出的路徑是否在任何位置與自身
 *     交叉。
 *
 * [中文] 思路:
 *     程式逐步更新目前座標，並用四個邊界記錄螺旋路徑的外框。在路徑開始向內
 *     收縮後，每一步檢查是否越過對向邊界；若越界即代表發生交叉。
 *
 * Examples:
 *     Input: distance = [2,1,1,2]
 *     Output: true
 *     Explanation: The path crosses itself at the point (0, 1).
 *     Input: distance = [1,2,3,4]
 *     Output: false
 *     Explanation: The path does not cross itself at any point.
 *     Input: distance = [1,1,1,2,1]
 *     Output: true
 *     Explanation: The path crosses itself at the point (0, 0).
 *
 * Constraints:
 *   - 1 <= distance.length <= 10^5
 *   - 1 <= distance[i] <= 10^5
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
struct Pos {
    int x, y;
};

bool isSelfCrossing(int* x, int xSize) {
    if (xSize < 4) return false;
    struct Pos pos[4], cur, temp;
    int right, left, up, down;
    pos[0].x = pos[0].y = pos[1].x = 0;
    pos[1].y = pos[2].y = x[0];
    pos[2].x = pos[3].x = -x[1];
    pos[3].y = pos[1].y-x[2];
    cur = pos[3];
    int i = 3;
    bool inbound = false;
    if (cur.y >= pos[0].y)
    {
        down = cur.y;
        right = 0;
        left = cur.x;
        up = pos[1].y;
        inbound = true;
    }
    else if (cur.x+x[3] < 0)
    {
        down = cur.y;
        right = cur.x+x[3];
        left = cur.x;
        up = pos[1].y;
        inbound = true;
        cur.x += x[3];
        i = 4;
    }
    else if (cur.x+x[3] == 0)
    {
        down = cur.y;
        right = cur.x+x[3];
        left = cur.x;
        up = 0;
        inbound = true;
        cur.x += x[3];
        i = 4;
    }
    else
    {
        cur.x += x[3];
        i = 4;
    }
    if (!inbound)
    {
        while (i < xSize)
        {
            temp = cur;
            if ((i & 3) == 0) // up
            {
                cur.y += x[i++];
                if (cur.y < pos[0].y)
                {
                    inbound = true;
                    left = pos[3].x;
                    up = cur.y;
                    down = pos[3].y;
                    right = cur.x;
                    break;
                }
                else if (cur.y <= pos[1].y)
                {
                    inbound = true;
                    left = pos[1].x;
                    up = cur.y;
                    down = pos[3].y;
                    right = cur.x;
                    break;
                }
                else
                {
                    pos[0] = temp;
                }
            }
            else if ((i & 3) == 1) // left
            {
                cur.x -= x[i++];
                if (cur.x > pos[1].x)
                {
                    inbound = true;
                    left = cur.x;
                    up = cur.y;
                    down = pos[0].y;
                    right = pos[0].x;
                    break;
                }
                else if (cur.x >= pos[2].x)
                {
                    inbound = true;
                    left = cur.x;
                    up = cur.y;
                    down = pos[2].y;
                    right = pos[0].x;
                    break;
                }
                else
                {
                    pos[1] = temp;
                }
            }
            else if ((i & 3) == 2) // down
            {
                cur.y -= x[i++];
                if (cur.y > pos[2].y)
                {
                    inbound = true;
                    left = cur.x;
                    down = cur.y;
                    right = pos[1].x;
                    up = pos[1].y;
                    break;
                }
                else if (cur.y >= pos[3].y)
                {
                    inbound = true;
                    left = cur.x;
                    down = cur.y;
                    right = pos[3].x;
                    up = pos[1].y;
                    break;
                }
                else
                {
                    pos[2] = temp;
                }
            }
            else // right
            {
                cur.x += x[i++];
                if (cur.x < pos[3].x)
                {
                    inbound = true;
                    right = cur.x;
                    down = cur.y;
                    left = pos[2].x;
                    up = pos[2].y;
                    break;
                }
                else if (cur.x <= pos[0].x)
                {
                    inbound = true;
                    right = cur.x;
                    down = cur.y;
                    left = pos[2].x;
                    up = pos[0].y;
                    break;
                }
                else
                {
                    pos[3] = temp;
                }
            }
        }
    }
    if (inbound)
    {
        while (i < xSize)
        {
            if ((i & 3) == 0) // up
            {
                cur.y += x[i++];
                if (cur.y >= up) return true;
                else up = cur.y;
            }
            else if ((i & 3) == 1) // left
            {
                cur.x -= x[i++];
                if (cur.x <= left) return true;
                else left = cur.x;
            }
            else if ((i & 3) == 2) // down
            {
                cur.y -= x[i++];
                if (cur.y <= down) return true;
                else down = cur.y;
            }
            else
            {
                cur.x += x[i++];
                if (cur.x >= right) return true;
                else right = cur.x;
            }
        }
    }
    return false;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {2,1,1,2};
  bool act_0 = isSelfCrossing(arr0_0, 4);
  if (!(act_0 == true)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {1,2,3,4};
  bool act_1 = isSelfCrossing(arr1_0, 4);
  if (!(act_1 == false)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {1,1,1,2,1};
  bool act_2 = isSelfCrossing(arr2_0, 5);
  if (!(act_2 == true)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 335, "isSelfCrossing", ntests);
 return (pass&&ntests)?0:1;
}
