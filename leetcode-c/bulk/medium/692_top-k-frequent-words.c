/*
 * ==========================================================================
 * LeetCode 0692. Top K Frequent Words
 * Difficulty: Medium
 * Tags: array, hash-table, string, trie, sorting, heap-(priority-queue, bucket-sort, counting
 * URL: https://leetcode.com/problems/top-k-frequent-words/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an array of strings words and an integer k, return the k most
 *     frequent strings.
 *     Return the answer sorted by the frequency from highest to lowest.
 *     Sort the words with the same frequency by their lexicographical
 *     order.
 *
 * [中文] 題目: 前 K 個高頻單詞
 * [中文] 題目說明:
 *     給定單詞陣列 words 與整數 k，回傳出現頻率最高的 k 個單詞
 *     。結果須按頻率由高到低排列，頻率相同時按字典序排列。
 *
 * [中文] 思路:
 *     以 Trie 為每個不同單詞建立索引並累計出現次數。將單詞與頻率排序
 *     為頻率遞減、字典序遞增後，取前 k 個。
 *
 * Examples:
 *     Input: words = ["i","love","leetcode","i","love","coding"], k
 *     = 2
 *     Output: ["i","love"]
 *     Explanation: "i" and "love" are the two most frequent words.
 *     Note that "i" comes before "love" due to a lower alphabetical
 *     order.
 *     Input: words =
 *     ["the","day","is","sunny","the","the","the","sunny","is","is"],
 *     k = 4
 *     Output: ["the","is","sunny","day"]
 *     Explanation: "the", "is", "sunny" and "day" are the four most
 *     frequent words, with the number of occurrence being 4, 3, 2
 *     and 1 respectively.
 *
 * Constraints:
 *   - 1 <= words.length <= 500
 *   - 1 <= words[i].length <= 10
 *   - words[i] consists of lowercase English letters.
 *   - k is in the range [1, The number of unique words[i]]
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
typedef struct __candidates_info {
    char *s;
    int freq;
} candidates_t;

typedef struct __word_info {
    int idx;
    int used;
} winfo_t;

typedef struct __trie {
    winfo_t winfo;
    struct __trie *t[26];
} trie_t;

static inline trie_t* create_trie(void)
{
    return calloc(1, sizeof(trie_t));
}

static void free_trie(trie_t *root)
{
    if (!root)
        return;

    for (int i = 0; i < 26; i++)
        free_trie(root->t[i]);  
    free(root);
}

static int find_trie(trie_t *root, char *s)
{
    if (!root)
        return -1;
    if (*s)
        return find_trie(root->t[*s - 'a'], s+1);

    return (root->winfo.used == 0 ? -1 : root->winfo.idx);
}

static void add_trie(trie_t *root, char *s, int s_idx)
{
    while (*s) {
        if (NULL == root->t[*s - 'a'])
            root->t[*s - 'a'] = calloc(1, sizeof(trie_t));
        root = root->t[*s - 'a'];
        s++;
    }
    root->winfo.idx = s_idx;
    root->winfo.used = 1;
}

static int compare(const void *a, const void *b)
{
    candidates_t r1 = *(candidates_t *)a;
    candidates_t r2 = *(candidates_t *)b;
    if (r1.freq == r2.freq) {
        return strcmp(r1.s, r2.s);
    }
    return (*(candidates_t *)b).freq - (*(candidates_t *)a).freq;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** topKFrequent(char** words, int wordsSize, int k, int* returnSize)
{
    trie_t *t = create_trie();
    candidates_t *candidates = malloc(sizeof(candidates_t)*wordsSize);
    int cand_idx = 0;
    for (int i = 0; i < wordsSize; i++) {
        int find_res = find_trie(t, words[i]);
        if (find_res >= 0) {
            candidates[find_res].freq += 1;
        } else {
            add_trie(t, words[i], cand_idx);
            candidates[cand_idx].s = words[i];
            candidates[cand_idx].freq = 1;
            cand_idx++;
        }
    }

    qsort(candidates, cand_idx, sizeof(candidates_t), compare);

    char **topk = malloc(sizeof(char *)*k);
    for (int i = 0; i < k; i++) {
        topk[i] = candidates[i].s;
    }

    *returnSize = k;
    free(candidates);
    free_trie(t);
    return topk;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static char *sa0_0[] = {"i","love","leetcode","i","love","coding"};
  char **act_0 = topKFrequent(sa0_0, 6,(2),&rsz_0);
  static char *cexp_0[] = {"i","love"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static char *sa1_0[] = {"the","day","is","sunny","the","the","the","sunny","is","is"};
  char **act_1 = topKFrequent(sa1_0, 10,(4),&rsz_1);
  static char *cexp_1[] = {"the","is","sunny","day"};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 4))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 692, "topKFrequent", ntests);
 return (pass&&ntests)?0:1;
}
