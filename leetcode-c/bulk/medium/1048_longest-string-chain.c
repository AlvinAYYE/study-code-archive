/*
 * ==========================================================================
 * LeetCode 1048. Longest String Chain
 * Difficulty: Medium
 * Tags: array, hash-table, two-pointers, string, dynamic-programming, sorting
 * URL: https://leetcode.com/problems/longest-string-chain/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an array of words where each word consists of
 *     lowercase English letters.
 *     wordA is a predecessor of wordB if and only if we can insert exactly
 *     one letter anywhere in wordA without changing the order of the other
 *     characters to make it equal to wordB.
 *     A word chain is a sequence of words [word1, word2, ..., wordk] with
 *     k >= 1, where word1 is a predecessor of word2, word2 is a
 *     predecessor of word3, and so on. A single word is trivially a word
 *     chain with k == 1.
 *     Return the length of the longest possible word chain with words
 *     chosen from the given list of words.
 *
 * [中文] 題目摘要 (術語規則翻譯, 供快速理解; 完整題意以上方英文為準):
 *     給定一個陣列 of words where each word consists of lowercase English
 *     letters.
 *
 * Examples:
 *     Input: words = ["a","b","ba","bca","bda","bdca"]
 *     Output: 4
 *     Explanation: One of the longest word chains is
 *     ["a","ba","bda","bdca"].
 *     Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
 *     Output: 5
 *     Explanation: All the words can be put in a word chain ["xb",
 *     "xbc", "cxbc", "pcxbc", "pcxbcf"].
 *     Input: words = ["abcd","dbqca"]
 *     Output: 1
 *     Explanation: The trivial word chain ["abcd"] is one of the
 *     longest word chains.
 *     ["abcd","dbqca"] is not a valid word chain because the
 *     ordering of the letters is changed.
 *
 * Constraints:
 *   - 1 <= words.length <= 1000
 *   - 1 <= words[i].length <= 16
 *   - words[i] only consists of lowercase English letters.
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
#define MAX_WORDS_LEN 1000
typedef struct hashT HASH;

struct hashInfo
{
	int ctr; // Count the chain len
	int len;
	char *str;       
};

struct hashT
{
	int size;
	int mod;
	struct hashInfo **arr;
};

int hash(HASH *obj, char *str, int keyLen)
{
	size_t hash = 5381;
	while (*str)
	{
		hash = 33 * hash ^ (unsigned char) *str++;
	}
	return hash % obj->mod;
}

HASH* createHash(int size)
{
	HASH *obj = malloc(sizeof(HASH));
	obj->size = size;
	obj->mod = size;
	obj->arr = malloc(sizeof(struct hashInfo)*(size));
	for (int x = 0; x < size; x++)
	{
		struct hashInfo *newInfo = calloc(1, sizeof(struct hashInfo));
		newInfo->ctr = 0;
		obj->arr[x] = newInfo;
	}
	return obj;
}

void addHash(HASH *ht, char *key, int ctr)
{
	int keyLen = strlen(key);
	int index = hash(ht, key, keyLen);
	while (ht->arr[index]->ctr != 0)
	{
		if (!strncmp(key, ht->arr[index]->str, keyLen))
		{
			return;
		}
		index++;
		index %= ht->size;
	}

	ht->arr[index]->ctr = ctr;
	ht->arr[index]->str = calloc(keyLen+1, sizeof(char));
	ht->arr[index]->len = keyLen;
	strcpy(ht->arr[index]->str, key);
}

int findHash(HASH *ht, char *key) 
{
	int keyLen = strlen(key);
	int index = hash(ht, key, keyLen);    
	while (ht->arr[index]->ctr != 0) 
	{
		if (ht->arr[index]->len == keyLen && !strncmp(ht->arr[index]->str, key, keyLen))
		{
			return ht->arr[index]->ctr;
		}
		index++;
		index %= ht->size;
	}
	return 0;
}

void releaseHash(HASH *ht)
{
	for (int i = 0; i < ht->size; i++)
	{
		free(ht->arr[i]->str);
		free(ht->arr[i]);
	}
	free(ht->arr);
	free(ht);
}

int getMaxPredecessorLen(HASH *h, char *str)
{
	int len = strlen(str);
	int maxLen = 0;
	char chkStr[17] = {0};
	for (int i = 0; i < len; i++)
	{
		char *str1 = (i > 0 ? str : "");
		char *str2 = (i+1 < len ? &(str[i+1]) : "");
		/* Backup character and set the ith char to '\0' */
		char tmp = str[i];
		str[i] = '\0';
		sprintf(chkStr, "%s%s", str1, str2);

		/* Check Hash */
		int chainLen = findHash(h, chkStr);
		maxLen = chainLen > maxLen ? chainLen : maxLen;
		/* restore the char */
		str[i] = tmp;
	}

	return maxLen;
}

int compare(const void *a, const void *b)
{
	char *n1 = *(char **)a;
	char *n2 = *(char **)b;

	int len1 = strlen(n1);
	int len2 = strlen(n2);
	return (len1 - len2);
}

int longestStrChain(char ** words, int wordsSize)
{
	/* sort via "string length" */
	qsort(words, wordsSize, sizeof(char *), compare);
	/* Create hash table */
	HASH *h = createHash(MAX_WORDS_LEN);
	int ret = 0;
	for (int i = 0; i < wordsSize; i++)
	{
		// Get the previous max chain length based on current words[]
		int chkChain = getMaxPredecessorLen(h, words[i]) + 1;
		// Add current words[] to hash
		addHash(h, words[i], chkChain);       
		ret = chkChain > ret ? chkChain : ret;
	}
	releaseHash(h);
	return ret;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static char *sa0_0[] = {"a","b","ba","bca","bda","bdca"};
  long long act_0 = (long long)longestStrChain(sa0_0, 6);
  if (!(act_0 == 4LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static char *sa1_0[] = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
  long long act_1 = (long long)longestStrChain(sa1_0, 5);
  if (!(act_1 == 5LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static char *sa2_0[] = {"abcd","dbqca"};
  long long act_2 = (long long)longestStrChain(sa2_0, 2);
  if (!(act_2 == 1LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 1048, "longestStrChain", ntests);
 return (pass&&ntests)?0:1;
}
