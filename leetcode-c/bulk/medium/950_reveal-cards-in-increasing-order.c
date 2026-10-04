/*
 * ==========================================================================
 * LeetCode 0950. Reveal Cards In Increasing Order
 * Difficulty: Medium
 * Tags: array, queue, sorting, simulation
 * URL: https://leetcode.com/problems/reveal-cards-in-increasing-order/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an integer array deck. There is a deck of cards where
 *     every card has a unique integer. The integer on the ith card is
 *     deck[i].
 *     You can order the deck in any order you want. Initially, all the
 *     cards start face down (unrevealed) in one deck.
 *     You will do the following steps repeatedly until all cards are
 *     revealed:
 *     Return an ordering of the deck that would reveal the cards in
 *     increasing order.
 *     Note that the first entry in the answer is considered to be the top
 *     of the deck.
 *
 * [中文] 題目: 按遞增順序顯示卡牌
 * [中文] 題目說明:
 *     給定一副數值互異的牌 deck，你可任意決定初始牌序，所有牌起初皆背
 *     面朝上。重複進行「翻開最上方牌」及「若仍有牌，將下一張最上方牌移至底
 *     部」，直到所有牌翻開。請回傳一種初始排序，使翻開的數值嚴格遞增；回傳
 *     陣列首項視為牌堆頂端。
 *
 * [中文] 思路:
 *     先將牌值排序，再用佇列模擬揭牌時各原始位置被取用的順序；依序把由小到
 *     大的牌填入這些位置。
 *
 * Examples:
 *     Input: deck = [17,13,11,2,3,5,7]
 *     Output: [2,13,3,11,5,17,7]
 *     Explanation:
 *     We get the deck in the order [17,13,11,2,3,5,7] (this order
 *     does not matter), and reorder it.
 *     After reordering, the deck starts as [2,13,3,11,5,17,7], where
 *     2 is the top of the deck.
 *     We reveal 2, and move 13 to the bottom. The deck is now
 *     [3,11,5,17,7,13].
 *     We reveal 3, and move 11 to the bottom. The deck is now
 *     [5,17,7,13,11].
 *     We reveal 5, and move 17 to the bottom. The deck is now
 *     [7,13,11,17].
 *     We reveal 7, and move 13 to the bottom. The deck is now
 *     [11,17,13].
 *     We reveal 11, and move 17 to the bottom. The deck is now
 *     [13,17].
 *     We reveal 13, and move 17 to the bottom. The deck is now [17].
 *     We reveal 17.
 *     Since all the cards revealed are in increasing order, the
 *     answer is correct.
 *     Input: deck = [1,1000]
 *     Output: [1,1000]
 *
 * Constraints:
 *   - 1 <= deck.length <= 1000
 *   - 1 <= deck[i] <= 10^6
 *   - All the values of deck are unique.
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
static int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize)
{
    // Sort the deck elements in ascending order.
    qsort(deck, deckSize, sizeof(int), cmp);

    // Create a simple queue to record the index order.
    // Initialize to sequentially put all deck indices into the queue.
    int* idx_q = malloc(sizeof(int) * deckSize);
    int front = 0, rear = 0;
    for (int i = 0; i < deckSize; i++)
        idx_q[i] = i;

    int* ret = malloc(sizeof(int) * deckSize);
    *returnSize = deckSize;

    // Handle two indices in one round, so process a total of `deckSize - 1`
    // elements in this loop.
    for (int deck_ctr = 0; deck_ctr < deckSize - 1; deck_ctr++) {
        // Dequeue to get the current index, then assign the latest deck element
        // to the corresponding `ret` position.
        ret[idx_q[front]] = deck[deck_ctr];
        front = (front + 1) % deckSize;
        // Dequeue to get the next index and then perform enqueue.
        idx_q[rear] = idx_q[front];
        front = (front + 1) % deckSize;
        rear = (rear + 1) % deckSize;
    }

    // Handle the last element from the queue.
    ret[idx_q[front]] = deck[deckSize - 1];
    free(idx_q);
    return ret;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int arr0_0[] = {17,13,11,2,3,5,7};
  int *act_0 = deckRevealedIncreasing(arr0_0, 7,&rsz_0);
  static const int exp_0[] = {2,3,5,7,11,13,17};
  if (!(lc_eq_list_sorted(act_0, rsz_0, exp_0, 7))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int arr1_0[] = {1,1000};
  int *act_1 = deckRevealedIncreasing(arr1_0, 2,&rsz_1);
  static const int exp_1[] = {1,1000};
  if (!(lc_eq_list_sorted(act_1, rsz_1, exp_1, 2))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 950, "deckRevealedIncreasing", ntests);
 return (pass&&ntests)?0:1;
}
