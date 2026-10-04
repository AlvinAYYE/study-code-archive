/*
 * ==========================================================================
 * LeetCode 1044. Longest Duplicate Substring
 * Difficulty: Hard
 * Tags: string, binary-search, sliding-window, rolling-hash, suffix-array, hash-function
 * URL: https://leetcode.com/problems/longest-duplicate-substring/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given a string s, consider all duplicated substrings: (contiguous)
 *     substrings of s that occur 2 or more times. The occurrences may
 *     overlap.
 *     Return any duplicated substring that has the longest possible
 *     length. If s does not have a duplicated substring, the answer is "".
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     Given a 字串 s, consider all 重複 子字串: (連續的) 子字串 of s that occur 2 or
 *     more times. The occurrences may overlap.
 *
 * Examples:
 *     Input: s = "banana"
 *     Output: "ana"
 *     Input: s = "abcd"
 *     Output: ""
 *
 * Constraints:
 *   - 2 <= s.length <= 3 * 10^4
 *   - s consists of lowercase English letters.
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
#define HASH_SIZE 10000
#define RHASH_MOD 8513
#define RHASH_BASE 26
#define HASH_MAP(_key, size) (_key % size)

typedef struct __ret_str_idx {
    int head;
    int tail;
} RET;

typedef struct __bucket_node {
    int head;
    int len;
    struct __bucket_node *next;
} NODE;

typedef struct {
    int size;
    NODE *bucket[HASH_SIZE];
} HASH;

static inline NODE *create_node()
{
    NODE *newNode = calloc(1, sizeof(NODE));
    return newNode;
}

static inline HASH *hash_init(int size)
{
    HASH *hash = calloc(1, sizeof(HASH));
    hash->size = size;
    return hash;
}

static void hash_insert(HASH *obj, int head, int len, int hash_idx)
{
    NODE *tmp = obj->bucket[HASH_MAP(hash_idx, obj->size)];
    NODE *newone = create_node();
    newone->head = head;
    newone->len = len;
    /* exist at least one node in current bucket */
    if (!tmp) {
        obj->bucket[hash_idx] = newone;
        return;
    }

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = newone;
}

static bool hash_find(HASH *obj, char *src_str, char *cur_str, int hash_idx)
{
    NODE *tmp = obj->bucket[HASH_MAP(hash_idx, obj->size)];
    while (tmp != NULL) {
        if (tmp->len != 0 && !memcmp(&src_str[tmp->head], cur_str, tmp->len)) {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

static void hash_free(HASH *obj)
{
    for (int i = 0; i < obj->size; i++) {
        NODE *tmp = obj->bucket[i];
        while (tmp) {
            NODE *delNode = tmp;
            tmp = tmp->next;
            free(delNode);
        }
    }
    free(obj);
}

/* rolling hash */
static long cal_rollhash(char *s, int len)
{
    long h = 0;
    for (int x = 0; x < len; x++)
        h = (RHASH_BASE * h + RHASH_MOD + s[x] - 'a') % RHASH_MOD;
    return h;
}

/**
 * @brief Check the longest duplicate substring
 * @return -1 on checking failed or head index of LPS
 */
static int check_lps(char *s, int slen, int clen)
{
    if (clen == 0)
        return -1;

    int ret = -1;
    HASH *h = hash_init(HASH_SIZE);
    long max_pow = 1l;

    for (int i = 1; i < clen; i++)
        max_pow = (RHASH_BASE * max_pow) % RHASH_MOD;

    /*
     * - Insert first string to hash table
     * - Calculate the rolling hash key of first string
     */
    long rh_key = cal_rollhash(s, clen);
    hash_insert(h, 0, clen, rh_key);

    for (int i = 1; (i + clen) <= slen; i++) {
        /* do rolling hash */
        rh_key = (rh_key + RHASH_MOD - max_pow * (s[i - 1] - 'a') % RHASH_MOD) %
                 RHASH_MOD;
        rh_key = (rh_key * RHASH_BASE + s[i + clen - 1] - 'a') % RHASH_MOD;
        if (hash_find(h, s, &s[i], rh_key)) {
            ret = i;
            break;
        } else
            hash_insert(h, i, clen, rh_key);
    }

    hash_free(h);
    return ret;
}

char *longestDupSubstring(char *S)
{
    int slen = strlen(S);
    int left = 0, right = slen;
    RET ret = {.head = -1, .tail = -1};

    while (left <= right) {
        int mid = ((right - left) >> 1) + left;
        int tmp = check_lps(S, slen, mid);
        if (tmp != -1) {
            ret.head = tmp;
            ret.tail = tmp + mid - 1;
            left = mid + 1;
        } else
            right = mid - 1;
    }

    if (-1 != ret.head) {
        S[ret.tail + 1] = 0;
        return &S[ret.head];
    }

    return "";
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "banana";
  char *act_0 = longestDupSubstring(s_0);
  if (!(strcmp(act_0, "ana") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = "abcd";
  char *act_1 = longestDupSubstring(s_1);
  if (!(strcmp(act_1, "") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1044, "longestDupSubstring", ntests);
 return (pass&&ntests)?0:1;
}
