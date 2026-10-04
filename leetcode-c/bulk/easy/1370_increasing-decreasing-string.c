/*
 * ==========================================================================
 * LeetCode 1370. Increasing Decreasing String
 * Difficulty: Easy
 * Tags: hash-table, string, counting
 * URL: https://leetcode.com/problems/increasing-decreasing-string/
 * Source: community solution, repo DimitrisJim_leetcode_solutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a string s. Reorder the string using the following
 *     algorithm:
 *     If the smallest or largest character appears more than once, you may
 *     choose any occurrence to append to the result.
 *     Return the resulting string after reordering s using this algorithm.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個字串 s. Reorder the 字串 using the following algorithm:
 *
 * Examples:
 *     Input: s = "aaaabbbbcccc"
 *     Output: "abccbaabccba"
 *     Explanation: After steps 1, 2 and 3 of the first iteration,
 *     result = "abc"
 *     After steps 4, 5 and 6 of the first iteration, result =
 *     "abccba"
 *     First iteration is done. Now s = "aabbcc" and we go back to
 *     step 1
 *     After steps 1, 2 and 3 of the second iteration, result =
 *     "abccbaabc"
 *     After steps 4, 5 and 6 of the second iteration, result =
 *     "abccbaabccba"
 *     Input: s = "rat"
 *     Output: "art"
 *     Explanation: The word "rat" becomes "art" after re-ordering it
 *     with the mentioned algorithm.
 *
 * Constraints:
 *   - 1 <= s.length <= 500
 *   - s consists of only lowercase English letters.
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
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

/* Little map. {char -> int}
 *
 * Supports (get, set, has, keys)
 * No error checking, really. Quick and dirty.
 * */
struct tablet {
    // size => allocated.
    // length => num of elements.
    int size, length;
    unsigned (*hashfunc)(char k);
    struct bucket {
        struct bucket *next;
        char key;
        int value;
    } **buckets;
};

// Basic hash.
unsigned hf(char key){
    unsigned x = key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

// Create table. Size used is smallest prime that is
// larger than size supplied.
struct tablet* tablet_new(int size){
    struct tablet *t;
    int psize = 521;
    t = malloc(sizeof(*t) + psize * sizeof(t->buckets[0]));

    // Assign values.
    t->size = psize;
    t->hashfunc = hf;
    t->length = 0;
    t->buckets = (struct bucket**)(t + 1);
    // init buckets.
    for (unsigned i = 0; i < psize; i++)
        t->buckets[i] = NULL;

    return t;
}

// Free table memory.
void tablet_free(struct tablet *tablet){
    // If we have elements, go through and free them.
    if((tablet)->length > 0){
        struct bucket *p, *q;
        for(int i = 0; i < (tablet)->size; i++){
            for(p = (tablet)->buckets[i]; p; p = q){
                q = p->next;
                free(p);
            }
        }
    }
    // If not, just free the table.
    free(tablet);
}

// Get value with key `key`
int tablet_get(struct tablet* t, char key){

    struct bucket *p;
    unsigned i = (*t->hashfunc)(key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(key == p->key)
            break;
    }
    // we *know* value >= 0 since they're counts, in general,
    // this isn't good.
    return p ? p->value : -1;
}

// Check if table has specific key.
// Returns 1 if true, 0 if false.
int tablet_has(struct tablet* t, char key){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        // Return true.
        if (key == p->key)
            return 1;
    }
    // Return false.
    return 0;
}

// Set key-value pair in table.
void tablet_set(struct tablet* t, char key, int value){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(key) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(key == p->key)
            break;
    }
    // Key value pair isn't present in table.
    // alloc bucket and add key-value.
    if (p == NULL){
        p = malloc(sizeof(struct bucket));
        p->value = value;
        p->key = key;
        // make new binding point to old beginning
        p->next = t->buckets[i];
        t->buckets[i] = p;
        t->length++;
    }
    // Update value.
    p->value = value;
}

// Delete from the table the key. 1 success, -1 failure.
int tablet_del(struct tablet *t, char key){
    if((t)->length > 0){
        struct bucket *p, *q;
        unsigned i = (*t->hashfunc)(key) % t->size;
        for(p = t->buckets[i]; p; p = p->next){
            if(key == p->key){
                // Re-align nodes.
                q = p;
                p = p->next;
                free(q);
                t->length--;
                t->buckets[i] = p;
                return 1;
            }
        }
    }
    return -1;
}

// Keys must be free'd by caller, size of keys is
// returned via keys_size.
char *tablet_keys(struct tablet* t, int *keys_size){
    // Iterate through nodes and find key:
    char *keys = malloc(t->length);
    struct bucket *p, *q;
    for(int i = 0, j=0; i < (t)->size; i++){
        for(p = (t)->buckets[i]; p; p = q){
            // Add to keys and advance
            keys[j] = p->key;
            j++;
            q = p->next;
        }
    }
    // Set keys_size.
    *keys_size = t->length;
    return keys;
}

//---------- End of little table implementation --------------//

// Sorting functions. One reverse one normal.
int ascending(const void *a, const void *b){
    // ascending
    return *(char *)a - *(char *)b;
}

int descending(const void *a, const void *b){
    return -ascending(a, b);
}


char * sortString(char *s){
    int slen = strlen(s);
    struct tablet *t = tablet_new(slen+1);
    // Create a table of counts. (NOTE: slen, not slen + 1.)
    for(int i = 0; i < slen; i++){
        char k = s[i];
        // if true, k: val => k: val+1
        if (tablet_has(t, k)){
            int val = tablet_get(t, k);
            tablet_set(t, k, val + 1);
        // set initial value of 1.
        } else {
            tablet_set(t, k, 1);
        }
    }
    int keys_size;
    // NOTE: Free both at end.
    char *reversed, *sorted = tablet_keys(t, &keys_size);
    // We can bail early here if keys_size == 1 or slen.
    if (keys_size == 1){
        free(sorted);
        tablet_free(t);
        return s;
    }
    if (keys_size == slen){
        // Sort s and return it.
        char *chars = malloc(slen+1);
        memcpy(chars, s, slen+1);
        qsort(chars, slen, sizeof(char), ascending);
        // Note caller frees chars.
        free(sorted);
        tablet_free(t);
        return chars;
    }
    // Sort first array.
    qsort(sorted, keys_size, sizeof(char), ascending);
    // Create and sort second array.
    reversed = malloc(keys_size);
    memcpy(reversed, sorted, keys_size);
    qsort(reversed, keys_size, sizeof(char), descending);

    // Go through sorted/reversed and fill up res.
    char *res = malloc(slen+1);
    res[slen] = '\0';
    unsigned toggle = 0, pending = 1, j = 0;
    while (pending != 0){
        for(int i = 0; i < keys_size; i++){
            // choose value from correct array.
            char key = toggle ? reversed[i]: sorted[i];
            if (tablet_has(t, key)) {
                int value = tablet_get(t, key);
                // case 1: table has key with only one occurence.
                // => Remove key and break if table length is 1.
                if (value == 1){
                    tablet_del(t, key);
                    if (t->length == 1)
                        pending ^= 1;
                // case 2: table has key with 1+ occurences.
                // => Decrement count.
                } else {
                    tablet_set(t, key, value-1);
                }
                // Add to res.
                res[j] = key;
                j++;
            }
        }
        toggle ^= 1;
    }
    // Handle the case of 1 remaining character.
    if (t->length == 1){
        int ks;
        char *keys = tablet_keys(t, &ks);
        if (ks != 1){
            // Error.
            return "";
        }
        char key = keys[0];
        free(keys);
        // key val will be slen - j
        for(int i = j; i < slen; i++)
           res[i] = key;
    }

    free(sorted);
    free(reversed);
    tablet_free(t);
    return res;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char s_0[] = "aaaabbbbcccc";
  char *act_0 = sortString(s_0);
  if (!(strcmp(act_0, "abccbaabccba") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char s_1[] = "rat";
  char *act_1 = sortString(s_1);
  if (!(strcmp(act_1, "art") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1370, "sortString", ntests);
 return (pass&&ntests)?0:1;
}
