/*
 * ==========================================================================
 * LeetCode 0649. Dota2 Senate
 * Difficulty: Medium
 * Tags: string, greedy, queue
 * URL: https://leetcode.com/problems/dota2-senate/
 * Source: community solution, repo Senthil455_Leetcode-Code (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     In the world of Dota2, there are two parties: the Radiant and the
 *     Dire.
 *     The Dota2 senate consists of senators coming from two parties. Now
 *     the Senate wants to decide on a change in the Dota2 game. The voting
 *     for this change is a round-based procedure. In each round, each
 *     senator can exercise one of the two rights:
 *     Given a string senate representing each senator's party belonging.
 *     The character 'R' and 'D' represent the Radiant party and the Dire
 *     party. Then if there are n senators, the size of the given string
 *     will be n.
 *     The round-based procedure starts from the first senator to the last
 *     senator in the given order. This procedure will last until the end
 *     of voting. All the senators who have lost their rights will be
 *     skipped during the procedure.
 *     Suppose every senator is smart enough and will play the best
 *     strategy for his own party. Predict which party will finally
 *     announce the victory and change the Dota2 game. The output should be
 *     "Radiant" or "Dire".
 *
 * [中文] 題目: Dota2 參議院
 * [中文] 題目說明:
 *     參議員依原順序分屬 Radiant 或 Dire，會一輪輪行使權利，
 *     已被禁止者會被跳過。每位仍有權利的參議員都採對己方最有利的策略，可禁
 *     止一名對方日後投票，或在只剩己方時宣布勝利。預測最後獲勝的陣營。
 *
 * [中文] 思路:
 *     以環狀佇列反覆處理參議員，並分別記錄兩方尚待生效的禁令數。未被禁的人
 *     會對敵方增加禁令並重新排到隊尾，直到其中一方人數歸零。
 *
 * Examples:
 *     Input: senate = "RD"
 *     Output: "Radiant"
 *     Explanation:
 *     The first senator comes from Radiant and he can just ban the
 *     next senator's right in round 1.
 *     And the second senator can't exercise any rights anymore since
 *     his right has been banned.
 *     And in round 2, the first senator can just announce the
 *     victory since he is the only guy in the senate who can vote.
 *     Input: senate = "RDD"
 *     Output: "Dire"
 *     Explanation:
 *     The first senator comes from Radiant and he can just ban the
 *     next senator's right in round 1.
 *     And the second senator can't exercise any rights anymore since
 *     his right has been banned.
 *     And the third senator comes from Dire and he can ban the first
 *     senator's right in round 1.
 *     And in round 2, the third senator can just announce the
 *     victory since he is the only guy in the senate who can vote.
 *
 * Constraints:
 *   - n == senate.length
 *   - 1 <= n <= 10^4
 *   - senate[i] is either 'R' or 'D'.
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
char * predictPartyVictory(char * senate){
    int dCount=0, rCount=0, dBan = 0, rBan = 0;
    int l , head = 0, tail, i;
    char c;
    for (i = 0; senate[i] != '\0'; ++i) {
        if (senate[i] == 'D') {
            ++dCount;
        } else {
            ++rCount;
        }
    }
    tail = i;
    l = i+1;
    while (dCount > 0 && rCount > 0) {
        c = senate[head];
        head = (head + 1) % l;
        if (c == 'D') {
            if (dBan > 0) {
                --dBan;
                --dCount;
            } else {
                ++rBan;
                senate[tail] = 'D';
                tail = (tail + 1) % l;
            }
        } else { /* c == 'R' */
            if (rBan > 0) {
                --rBan;
                --rCount;
            } else {
                ++dBan;
                senate[tail] = 'R';
                tail = (tail + 1) % l;
            }
        }
    }
    return dCount > 0 ? "Dire" : "Radiant";
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char senate_0[] = "RD";
  char *act_0 = predictPartyVictory(senate_0);
  if (!(strcmp(act_0, "Radiant") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char senate_1[] = "RDD";
  char *act_1 = predictPartyVictory(senate_1);
  if (!(strcmp(act_1, "Dire") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 649, "predictPartyVictory", ntests);
 return (pass&&ntests)?0:1;
}
