/*
 * ==========================================================================
 * LeetCode 0336. Palindrome Pairs
 * Difficulty: Hard
 * Tags: array, hash-table, string, trie
 * URL: https://leetcode.com/problems/palindrome-pairs/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given a 0-indexed array of unique strings words.
 *     A palindrome pair is a pair of integers (i, j) such that:
 *     Return an array of all the palindrome pairs of words.
 *     You must write an algorithm with O(sum of words[i].length) runtime
 *     complexity.
 *
 * [中文] 題目: 回文配對
 * [中文] 題目說明:
 *     給定由互不相同字串組成的陣列 words，找出所有索引對 (i, j
 *     )，使 i 不等於 j 且 words[i] + words[j] 
 *     為回文。回傳所有這類索引對，並須處理空字串情況。
 *
 * [中文] 思路:
 *     把所有非空單字存入 Trie，針對每個單字查找其反轉字串。再枚舉切分
 *     點，若其中一側是回文便到 Trie 查找另一側的反轉字串，同時特別處
 *     理空字串與完整回文。
 *
 * Examples:
 *     Input: words = ["abcd","dcba","lls","s","sssll"]
 *     Output: [[0,1],[1,0],[3,2],[2,4]]
 *     Explanation: The palindromes are
 *     ["abcddcba","dcbaabcd","slls","llssssll"]
 *     Input: words = ["bat","tab","cat"]
 *     Output: [[0,1],[1,0]]
 *     Explanation: The palindromes are ["battab","tabbat"]
 *     Input: words = ["a",""]
 *     Output: [[0,1],[1,0]]
 *     Explanation: The palindromes are ["a","a"]
 *
 * Constraints:
 *   - 1 <= words.length <= 5000
 *   - 0 <= words[i].length <= 300
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
#define MAX_RET_SIZE(a) (a*(a-1))

typedef struct trieNode 
{
	int idx;
	struct trieNode *child[26];
} TRIE;

void freeTrie(TRIE *root)
{
	if (NULL == root)
	{
		return;
	}
	for (int i = 0; i < 26; i++)
	{
		freeTrie(root->child[i]);
	}

	free(root);
}

TRIE* createTrie()
{
	TRIE *obj = calloc(1, sizeof(TRIE));
	obj->idx = -1; 

	return obj;
}

void reverseStr(char *s)
{
	int head = 0;
	int tail = strlen(s) - 1;
	while (head < tail)
	{
		char tmp = s[head];
		s[head] = s[tail];
		s[tail] = tmp;
		head++;
		tail--;
	}
}

bool validPalindrome(char *s)
{
	int head = 0;
	int tail = strlen(s)-1;
	while (head < tail)
	{
		if (s[head] != s[tail])
		{
			return false;
		}
		head++;
		tail--;
	}

	return true;
}

void addTrie(TRIE *head, char *word, int index)
{
	char *tmpWord = word;
	while (*tmpWord)
	{
		int childIdx = *tmpWord - 'a';
		if (NULL == head->child[childIdx])
		{
			head->child[childIdx] = createTrie();
		}
		head = head->child[childIdx];
		tmpWord++;
	}

	head->idx = index;
}

int findTrie(TRIE *head, char *word)
{
	int len = strlen(word);
	char *rword = calloc(len+1, sizeof(char));
	strcpy(rword, word);
	reverseStr(rword);

	char *tmpWord = rword;
	while (*tmpWord)
	{
		int childIdx = *tmpWord - 'a';
		if (NULL == head->child[childIdx])
		{
			free(rword);
			return -1;
		}
		head = head->child[childIdx];
		tmpWord++;
	}

	free(rword);
	return head->idx;
}

void updateResult(int **ret, int **returnColumnSizes, int *retCtr, int idx1, int idx2)
{
	ret[*retCtr] = malloc(sizeof(int)*2);
	ret[*retCtr][0] = idx1;
	ret[*retCtr][1] = idx2;
	(*returnColumnSizes)[*retCtr] = 2;
	*retCtr += 1;
}

int** palindromePairs(char ** words, int wordsSize, int* returnSize, int** returnColumnSizes)
{
	int **ret = malloc(sizeof(int *)*MAX_RET_SIZE(wordsSize));
	*returnColumnSizes = malloc(sizeof(int)*MAX_RET_SIZE(wordsSize));
	*returnSize = 0;

	TRIE *t = createTrie();
	int emptyIdx = -1;
	for (int i = 0; i < wordsSize; i++)
	{
		if (strlen(words[i]) == 0)
		{
			emptyIdx = i;
			continue;
		}
		addTrie(t, words[i], i);        
	}

	for (int i = 0; i < wordsSize; i++)
	{        
		int curLen = strlen(words[i]);        
		if (curLen == 0)
		{
			continue;
		}
		// Current word is palindrome and there is an empty string in words
		if (validPalindrome(words[i]) && emptyIdx != -1)
		{
			updateResult(ret, returnColumnSizes, returnSize, i, emptyIdx);
			updateResult(ret, returnColumnSizes, returnSize, emptyIdx, i);
		}

		// Check that the current reverse word has existed in TRIE
		int findIdx = findTrie(t, words[i]);
		if (-1 != findIdx && findIdx != i)
		{
			updateResult(ret, returnColumnSizes, returnSize, i, findIdx);
		}

		// Split the current word to left half and right half
		char *lStr = calloc(curLen+1, sizeof(char));
		strcpy(lStr, words[i]);
		char *rStr = NULL;
		for (int x = 1; x < curLen; x++)
		{
			lStr[x] = '\0';
			rStr = &(words[i][x]);
			// Left is palindrome, check right in TRIE
			if (validPalindrome(lStr))
			{
				int findIdx_right = findTrie(t, rStr);
				if (-1 != findIdx_right)
				{
					updateResult(ret, returnColumnSizes, returnSize, findIdx_right, i);
				}
			}

			// Right is palindrome, check left in TRIE
			if (validPalindrome(rStr))
			{
				int findIdx_left = findTrie(t, lStr);
				if (-1 != findIdx_left)
				{
					updateResult(ret, returnColumnSizes, returnSize, i, findIdx_left);
				}
			}                        

			lStr[x] = words[i][x];
		}
		free(lStr);
	}

	freeTrie(t);
	return ret;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  int *rcs_0 = 0;
  static char *sa0_0[] = {"abcd","dcba","lls","s","sssll"};
  int **act_0 = palindromePairs(sa0_0, 5,&rsz_0,&rcs_0);
  static char ibuf_0[400000]; lc_canon_ii(act_0, rcs_0, rsz_0, ibuf_0, sizeof ibuf_0);
  if (!(strcmp(ibuf_0, "[[0,1],[0,1],[2,3],[2,4]]") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  int *rcs_1 = 0;
  static char *sa1_0[] = {"bat","tab","cat"};
  int **act_1 = palindromePairs(sa1_0, 3,&rsz_1,&rcs_1);
  static char ibuf_1[400000]; lc_canon_ii(act_1, rcs_1, rsz_1, ibuf_1, sizeof ibuf_1);
  if (!(strcmp(ibuf_1, "[[0,1],[0,1]]") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  int *rcs_2 = 0;
  static char *sa2_0[] = {"a",""};
  int **act_2 = palindromePairs(sa2_0, 2,&rsz_2,&rcs_2);
  static char ibuf_2[400000]; lc_canon_ii(act_2, rcs_2, rsz_2, ibuf_2, sizeof ibuf_2);
  if (!(strcmp(ibuf_2, "[[0,1],[0,1]]") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 336, "palindromePairs", ntests);
 return (pass&&ntests)?0:1;
}
