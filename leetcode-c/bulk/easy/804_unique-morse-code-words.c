/*
 * ==========================================================================
 * LeetCode 0804. Unique Morse Code Words
 * Difficulty: Easy
 * Tags: array, hash-table, string
 * URL: https://leetcode.com/problems/unique-morse-code-words/
 * Source: community solution, repo DimitrisJim_leetcode_solutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     International Morse Code defines a standard encoding where each
 *     letter is mapped to a series of dots and dashes, as follows:
 *     For convenience, the full table for the 26 letters of the English
 *     alphabet is given below:
 *     Given an array of strings words where each word can be written as a
 *     concatenation of the Morse code of each letter.
 *     Return the number of different transformations among all words we
 *     have.
 *
 * [中文] 題目: 獨特的摩斯密碼詞
 * [中文] 題目說明:
 *     將 words 中每個小寫英文單字依國際摩斯碼逐字串接，形成其轉換結
 *     果。回傳所有轉換結果中不同字串的數量；單字數最多為 100，單字長度
 *     最多為 12。
 *
 * [中文] 思路:
 *     以字母對應表組合每個單字的摩斯碼，並將完整字串存入自製雜湊集合，集合
 *     大小即為答案。
 *
 * Examples:
 *     [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 *     Input: words = ["gin","zen","gig","msg"]
 *     Output: 2
 *     Explanation: The transformation of each word is:
 *     "gin" -> "--...-."
 *     "zen" -> "--...-."
 *     "gig" -> "--...--."
 *     "msg" -> "--...--."
 *     There are 2 different transformations: "--...-." and
 *     "--...--.".
 *     Input: words = ["a"]
 *     Output: 1
 *
 * Constraints:
 *   - 1 <= words.length <= 100
 *   - 1 <= words[i].length <= 12
 *   - words[i] consists of lowercase English letters.
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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Hold our morse code translations:
static char *morse[26] = {
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",
    ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-","-.--","--.."
};

/* Little hashmap. {int -> int} 
 *
 * Supports only basic ops (get, set)
 * No error checking, really. Quick and dirty.
 * */
struct tablet {
    // size => allocated.
    // length => num of elements.
    unsigned size, length;
    unsigned long (*hashfunc)(const char *k);
    // Separate chaining (with a linked list).
    struct bucket {
        struct bucket *next;
        const char* value;
    } **buckets;
};

// polynomial rolling hash function, thanks:
// https://cp-algorithms.com/string/string-hashing.html
unsigned long hf(const char* key){
    const int p = 31;
    const int m = 1e9 + 9;
    int len = strlen(key);
    long long hash_value = 0;
    long long p_pow = 1;
    for(int i = 0; i < len; i++) {
        hash_value = (hash_value + (key[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
    return (unsigned long)key >> 2;
}

// Base size on prime (I remember somewhere this is a good idea,
// need to find that source.)
int get_next_prime(int size){
    // return next prime after size to use as table size.
    unsigned i = 0; 
    static int PRIMES[] = {
        61, 101, 137, 167, 211, 263, 313,
        367, 401, 449, 	503, INT_MAX 	
    };

    for(;; i++){
        if (size <= PRIMES[i])
            break;
    } 
    // return first prime that is > size.
    return PRIMES[i];
}

// Create table.
struct tablet* tablet_new(int size){
    struct tablet *t;
    int psize = get_next_prime(size);
    if (psize < size){
        // Problem here. Bail.
        return NULL;
    }
    t = (struct tablet *)malloc(
            sizeof(*t) + psize * sizeof(t->buckets[0])
            );
    if (t == NULL){
        return NULL;
    }
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

// delete table.
void tablet_free(struct tablet *tablet){
    // If we have elements, go through and free them.
    if((tablet)->length > 0){
        struct bucket *p, *q;
        for(int i = 0; i < (tablet)->size; i++){
            for(p = (tablet)->buckets[i]; p; p = q){
                q = p->next;
                // Free the strings we allocated in 
                // uniqueMorseRepresentations here!
                free((void *)p->value);
                free(p);
            }
        }
    }
    // If not, just free the table.
    free(tablet);
}

// get value with key `key`
int tablet_has(struct tablet* t, const char* val){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(val) % t->size; 
    for(p = t->buckets[i]; p; p = p->next){
        if(strcmp(val, p->value) == 0)
            return 1;
    }
    return 0;
}

// set key value in table.
void * tablet_set(struct tablet* t, const char* value){
    struct bucket *p;
    unsigned i = (*t->hashfunc)(value) % t->size;
    for(p = t->buckets[i]; p; p = p->next){
        if(strcmp(value, p->value) == 0)
            break;
    }
    // Key value pair isn't present in table.
    // alloc bucket and add key-value.
    if (p == NULL){
        p = (struct bucket *)malloc(sizeof(struct bucket));
        if (p == NULL){
            return NULL;
        }
        p->value = value;
        // make new binding point to old beginning
        p->next = t->buckets[i];
        t->buckets[i] = p;
        t->length++;
        return t;
    }
    // Free old value and replace
    // Could just've not updated the value, really, and move the 
    // free in uniqueMorseRepresentations. Meh.
    const char *old_value = p->value;
    p->value = value;
    free((void *)old_value);
    return t;
}

int uniqueMorseRepresentations(char ** words, int wordsSize){
    struct tablet *seen = tablet_new(4);
    if (seen == NULL) {
        return -1;
    }
    for(int i = 0; i < wordsSize; i++){
        // Max morse word size == 4. Allocate enough.
        int len=strlen(words[i]);
        // Max + 1 for trailing '\0'
        int size = (len * 4) + 1;
        char *code = (char *)malloc(size);
        if (code == NULL){
            tablet_free(seen);
            return -1;
        }
        // j: where do we strcopy to?
        // i: word we're currently looking at.
        // k: char we're currently looking at.
        int j = 0;
        for(int k = 0; k < len; k++){
            char *mc = morse[words[i][k] - 97];
            strcpy(code+j, (const char *)mc);
            j += strlen(mc);
        }
        code[j] = '\0';
        // Add it to set.
        if (tablet_set(seen, (const char *)code) == NULL){
            tablet_free(seen);
            return -1;
        };
    }
    int res = seen->length;
    tablet_free(seen);
    return res;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static char *sa0_0[] = {"gin","zen","gig","msg"};
  long long act_0 = (long long)uniqueMorseRepresentations(sa0_0, 4);
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static char *sa1_0[] = {"a"};
  long long act_1 = (long long)uniqueMorseRepresentations(sa1_0, 1);
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 804, "uniqueMorseRepresentations", ntests);
 return (pass&&ntests)?0:1;
}
