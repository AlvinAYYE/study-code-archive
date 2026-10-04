/*
 * ==========================================================================
 * LeetCode 0149. Max Points on a Line
 * Difficulty: Hard
 * Tags: array, hash-table, math, geometry
 * URL: https://leetcode.com/problems/max-points-on-a-line/
 * Source: community solution, repo Senthil455_Leetcode-Code (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an array of points where points[i] = [xi, yi] represents a
 *     point on the X-Y plane, return the maximum number of points that lie
 *     on the same straight line.
 *
 * [中文] 題目: 直線上的最大點數
 * [中文] 題目說明:
 *     給定平面點陣列 points，其中 points[i] = [xi,
 *      yi]，求同一直線上最多有多少點。所有點皆互不相同。點數介於 1 
 *     至 300，座標 xi、yi 介於 -10^4 至 10^4。
 *
 * [中文] 思路:
 *     逐一固定一個點作為錨點，將其與其他點的斜率以最大公因數約分並正規化後
 *     放入雜湊表計數，取各錨點的最大值。
 *
 * Examples:
 *     Input: points = [[1,1],[2,2],[3,3]]
 *     Output: 3
 *     Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 *     Output: 4
 *
 * Constraints:
 *   - 1 <= points.length <= 300
 *   - points[i].length == 2
 *   - -10^4 <= xi, yi <= 10^4
 *   - All the points are unique.
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
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Hash map key for slope: (dy, dx)
typedef struct {
    int dy;
    int dx;
} Slope;

typedef struct {
    Slope key;
    int count;
} HashEntry;

#define MAX_HASH_SIZE 10007

int hash(Slope s) {
    return ((s.dy * 31 + s.dx) % MAX_HASH_SIZE + MAX_HASH_SIZE) % MAX_HASH_SIZE;
}

int equal(Slope a, Slope b) {
    return a.dy == b.dy && a.dx == b.dx;
}

void clearHashMap(HashEntry* map) {
    for (int i = 0; i < MAX_HASH_SIZE; i++) {
        map[i].count = 0;
        map[i].key.dy = 0;
        map[i].key.dx = 0;
    }
}

void insert(HashEntry* map, Slope s) {
    int idx = hash(s);
    while (map[idx].count != 0) {
        if (equal(map[idx].key, s)) {
            map[idx].count++;
            return;
        }
        idx = (idx + 1) % MAX_HASH_SIZE;
    }
    map[idx].key = s;
    map[idx].count = 1;
}

int getCount(HashEntry* map, Slope s) {
    int idx = hash(s);
    while (map[idx].count != 0) {
        if (equal(map[idx].key, s)) {
            return map[idx].count;
        }
        idx = (idx + 1) % MAX_HASH_SIZE;
    }
    return 0;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) return pointsSize;

    int result = 2;
    HashEntry hashMap[MAX_HASH_SIZE];

    for (int i = 0; i < pointsSize; i++) {
        clearHashMap(hashMap);
        int samePoint = 1;
        int sameX = 0;
        int localMax = 0;

        int x0 = points[i][0];
        int y0 = points[i][1];

        for (int j = i + 1; j < pointsSize; j++) {
            int x = points[j][0];
            int y = points[j][1];

            if (x == x0 && y == y0) {
                samePoint++;
            } else if (x == x0) {
                sameX++;
                localMax = sameX > localMax ? sameX : localMax;
            } else {
                int dx = x - x0;
                int dy = y - y0;
                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }

                Slope slope = {dy, dx};
                insert(hashMap, slope);
                int count = getCount(hashMap, slope);
                localMax = count > localMax ? count : localMax;
            }
        }

        result = (localMax + samePoint) > result ? (localMax + samePoint) : result;
    }

    return result;
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int mr0_0_0[] = {1,1};
  static int mr0_0_1[] = {2,2};
  static int mr0_0_2[] = {3,3};
  static int *mp0_0[] = {mr0_0_0,mr0_0_1,mr0_0_2};
  static int mc0_0[] = {2,2,2};
  long long act_0 = (long long)maxPoints(mp0_0, 3,mc0_0);
  if (!(act_0 == 3LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int mr1_0_0[] = {1,1};
  static int mr1_0_1[] = {3,2};
  static int mr1_0_2[] = {5,3};
  static int mr1_0_3[] = {4,1};
  static int mr1_0_4[] = {2,3};
  static int mr1_0_5[] = {1,4};
  static int *mp1_0[] = {mr1_0_0,mr1_0_1,mr1_0_2,mr1_0_3,mr1_0_4,mr1_0_5};
  static int mc1_0[] = {2,2,2,2,2,2};
  long long act_1 = (long long)maxPoints(mp1_0, 6,mc1_0);
  if (!(act_1 == 4LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 149, "maxPoints", ntests);
 return (pass&&ntests)?0:1;
}
