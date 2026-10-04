/*
 * ==========================================================================
 * LeetCode 0913. Cat and Mouse
 * Difficulty: Hard
 * Tags: math, dynamic-programming, graph, topological-sort, memoization, game-theory
 * URL: https://leetcode.com/problems/cat-and-mouse/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     A game on an undirected graph is played by two players, Mouse and
 *     Cat, who alternate turns.
 *     The graph is given as follows: graph[a] is a list of all nodes b
 *     such that ab is an edge of the graph.
 *     The mouse starts at node 1 and goes first, the cat starts at node 2
 *     and goes second, and there is a hole at node 0.
 *     During each player's turn, they must travel along one edge of the
 *     graph that meets where they are. For example, if the Mouse is at
 *     node 1, it must travel to any node in graph[1].
 *     Additionally, it is not allowed for the Cat to travel to the Hole
 *     (node 0).
 *     Then, the game can end in three ways:
 *     Given a graph, and assuming both players play optimally, return
 *
 * [中文] 題目: 貓和老鼠
 * [中文] 題目說明:
 *     在無向圖中，老鼠從節點 1 先走，貓從節點 2 後走，洞口位於節點 
 *     0，雙方每回合都必須沿一條相鄰邊移動，且貓不得進入洞口。老鼠到達洞口
 *     時獲勝，貓與老鼠位於同一節點時獲勝；若同一個雙方位置與輪到移動者的狀
 *     態重複，則為平手。假設雙方皆最佳策略，回傳老鼠勝的 1、貓勝的 2，
 *     或平手的 0。
 *
 * [中文] 思路:
 *     以「老鼠位置、貓位置、輪到誰走」建立狀態，從老鼠在洞口與雙方相遇的終
 *     局狀態反向推導。若行動方有一步可走向己方必勝子狀態即可定勝，否則所有
 *     子狀態皆為對手必勝時才判敗。
 *
 * Examples:
 *     Input: graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
 *     Output: 0
 *     Input: graph = [[1,3],[0],[3],[0,2]]
 *     Output: 1
 *
 * Constraints:
 *   - 3 <= graph.length <= 50
 *   - 1 <= graph[i].length < graph.length
 *   - 0 <= graph[i][j] < graph.length
 *   - graph[i][j] != i
 *   - graph[i] is unique.
 *   - The mouse and the cat can always move.
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
913. Cat and Mouse

A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in 3 ways:


	If ever the Cat occupies the same node as the Mouse, the Cat wins.
	If ever the Mouse reaches the Hole, the Mouse wins.
	If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.


Given a graph, and assuming both players play optimally, return 1 if the game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a draw.

 





Example 1:

Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
Output: 0
Explanation:
4---3---1
|   |
2---5
 \ /
  0


 

Note:


	3 <= graph.length <= 50
	It is guaranteed that graph[1] is non-empty.
	It is guaranteed that graph[2] contains a non-zero element.
*/

typedef struct {
    int m;      // mouse position
    int c;      // cat position
    int t;      // who is going to move in next turn
    int s;      // current win-lose state
} node_t;
#define MOUSE_POSITION(NODE)    ((NODE)->m)
#define CAT_POSITION(NODE)      ((NODE)->c)

#define MOUSE_MOVE  1
#define CAT_MOVE    2

#define IS_MOUSE_MOVE(NODE) ((NODE)->t == MOUSE_MOVE)
#define IS_CAT_MOVE(NODE)   ((NODE)->t == CAT_MOVE)

#define UNKNOWN_    0
#define MOUSE_WIN   1
#define CAT_WIN     2

#define SET_MOUSE_WIN(NODE) ((NODE)->s = MOUSE_WIN)
#define SET_CAT_WIN(NODE)   ((NODE)->s = CAT_WIN)

#define IS_MOUSE_WIN(NODE)  ((NODE)->s == MOUSE_WIN)
#define IS_CAT_WIN(NODE)    ((NODE)->s == CAT_WIN)

#define MSZ     50
#define CSZ     50
#define TSZ     3
#define SIZE    (MSZ * CSZ *TSZ)

#define IDX(M, C, T)    ((M) * (CSZ) * (TSZ) + (C) * (TSZ) + T)

node_t *get_node(node_t *nodes, int m, int c, int t) {
    node_t *node = &nodes[IDX(m, c, t)];
    
    node->m = m;
    node->c = c;
    node->t = t;
    
    return node;
}
bool mouse_win_on_all_children(node_t *node, node_t *nodes, int **graph, int *colsz) {
    int i, j, k;
    node_t *child;
    
    i = CAT_POSITION(node);
    for (j = 0; j < colsz[i]; j ++) {
        k = graph[i][j];
        if (k == 0) continue;   // cat cannot go to position 0
        child = get_node(nodes, MOUSE_POSITION(node), k, MOUSE_MOVE);
        if (!IS_MOUSE_WIN(child)) return false;  // not determined or cat wins
    }
    return true;    // mouse wins on all children
}
bool cat_win_on_all_children(node_t *node, node_t *nodes, int **graph, int *colsz) {
    int i, j, k;
    node_t *child;
    
    i = MOUSE_POSITION(node);
    for (j = 0; j < colsz[i]; j ++) {
        k = graph[i][j];
        child = get_node(nodes, k, CAT_POSITION(node), CAT_MOVE);
        if (!IS_CAT_WIN(child)) return false;
    }
    return true;
}
int catMouseGame(int** graph, int graphSize, int* graphColSize){
    int i, j, k;
    node_t nodes[SIZE] = { 0 }; // total number of nodes per (mouse position * cat position * who is going to move)
    node_t *buff1[SIZE], *buff2[SIZE];     // queue of knowns states
    node_t **q1 = buff1, **q2 = buff2, **q3;
    int q1len = 0, q2len = 0;
    
    node_t *node, *parent;
    
    // initial known states
    for (i = 1; i < graphSize; i ++) {
        // mouse is at 0, regardless where cat is and who is going to move, mouse wins
        node = get_node(nodes, 0, i, MOUSE_MOVE);
        SET_MOUSE_WIN(node);
        q1[q1len ++] = node;        // enqeue this node
        
        node = get_node(nodes, 0, i, CAT_MOVE);
        SET_MOUSE_WIN(node);
        q1[q1len ++] = node;
        
        // mouse and cat have met, regardless who is going to move, cat wins
        node = get_node(nodes, i, i, MOUSE_MOVE);
        SET_CAT_WIN(node);
        q1[q1len ++] = node;
        
        node = get_node(nodes, i, i, CAT_MOVE);
        SET_CAT_WIN(node);
        q1[q1len ++] = node;
    }
    
    while (q1len) {
        for (i = 0; i < q1len; i ++) {
            node = q1[i];
            // for each parent node which can move to current node
            if (IS_MOUSE_MOVE(node)) {      // current node is mouse going to move
                j = CAT_POSITION(node);     // parent must be cat was moving
                for (k = 0; k < graphColSize[j]; k ++) {
                    if (graph[j][k] == 0) continue; // cat cannot be at position 0
                    parent = get_node(nodes, MOUSE_POSITION(node), graph[j][k], CAT_MOVE);
                    if (IS_MOUSE_WIN(parent) || IS_CAT_WIN(parent)) continue;    // already determined
                    if (IS_CAT_WIN(node)) {     // if cat wins at present, parent must win because:
                        SET_CAT_WIN(parent);    // parent is cat to move so the cat can just move to here
                    } else if (mouse_win_on_all_children(parent, nodes, graph, graphColSize)) {
                        SET_MOUSE_WIN(parent);
                    } else {
                        parent = NULL;      // unable to determine it, forget about it at this moment.
                    }
                    if (parent) q2[q2len ++] = parent;  // enqueue it for next round expansion
                }
            } else {                        // current node is cat going to move
                j = MOUSE_POSITION(node);   // parent must be mouse was moving
                for (k = 0; k < graphColSize[j]; k ++) {
                    parent = get_node(nodes, graph[j][k], CAT_POSITION(node), MOUSE_MOVE);
                    if (IS_MOUSE_WIN(parent) || IS_CAT_WIN(parent)) continue;    // already determined
                    if (IS_MOUSE_WIN(node)) {
                        SET_MOUSE_WIN(parent);
                    } else if (cat_win_on_all_children(parent, nodes, graph, graphColSize)) {
                        SET_CAT_WIN(parent);
                    } else {
                        parent = NULL;
                    }
                    if (parent) q2[q2len ++] = parent;  // enqueue it for next round expansion
                }
            }
        }
        // switch q1 and q2
        q3 = q1;
        q1 = q2;
        q1len = q2len;
        q2 = q3;
        q2len = 0;
    }
    
    node = &nodes[IDX(1, 2, MOUSE_MOVE)];
    return node->s;
}


/*
Difficulty:Hard


*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {2,5};
  static int mr0_0_1[] = {3};
  static int mr0_0_2[] = {0,4,5};
  static int mr0_0_3[] = {1,4,5};
  static int mr0_0_4[] = {2,3};
  static int mr0_0_5[] = {0,2,3};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2,mr0_0_3,mr0_0_4,mr0_0_5};
  static int mc0_0[] = {2,1,3,3,2,3};
  long long act_0 = (long long)catMouseGame(mp0_0, 6,mc0_0);
  if (!(act_0 == 0LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,3};
  static int mr1_0_1[] = {0};
  static int mr1_0_2[] = {3};
  static int mr1_0_3[] = {0,2};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3};
  static int mc1_0[] = {2,1,1,2};
  long long act_1 = (long long)catMouseGame(mp1_0, 4,mc1_0);
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 913, "catMouseGame", ntests);
 return (pass&&ntests)?0:1;
}
