/*
 * ==========================================================================
 * LeetCode 0811. Subdomain Visit Count
 * Difficulty: Medium
 * Tags: array, hash-table, string, counting
 * URL: https://leetcode.com/problems/subdomain-visit-count/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     A website domain "discuss.leetcode.com" consists of various
 *     subdomains. At the top level, we have "com", at the next level, we
 *     have "leetcode.com" and at the lowest level, "discuss.leetcode.com".
 *     When we visit a domain like "discuss.leetcode.com", we will also
 *     visit the parent domains "leetcode.com" and "com" implicitly.
 *     A count-paired domain is a domain that has one of the two formats
 *     "rep d1.d2.d3" or "rep d1.d2" where rep is the number of visits to
 *     the domain and d1.d2.d3 is the domain itself.
 *     Given an array of count-paired domains cpdomains, return an array of
 *     the count-paired domains of each subdomain in the input. You may
 *     return the answer in any order.
 *
 * [中文] 題目: 子網域造訪計數
 * [中文] 題目說明:
 *     每筆 count-paired domain 以「次數 網域」表示，
 *     造訪一個網域也會隱含造訪其所有父網域。輸入格式只會是 d1.d2 或
 *      d1.d2.d3，彙整後回傳每個子網域的「總次數 網域」字串，順序
 *     不限。
 *
 * [中文] 思路:
 *     解析每筆前置次數，並在空格與每個句點後取出目前的網域尾段；用雜湊表累
 *     加各尾段的計數，最後組成輸出字串。
 *
 * Examples:
 *     Input: cpdomains = ["9001 discuss.leetcode.com"]
 *     Output: ["9001 leetcode.com","9001 discuss.leetcode.com","9001
 *     com"]
 *     Explanation: We only have one website domain:
 *     "discuss.leetcode.com".
 *     As discussed above, the subdomain "leetcode.com" and "com"
 *     will also be visited. So they will all be visited 9001 times.
 *     Input: cpdomains = ["900 google.mail.com", "50 yahoo.com", "1
 *     intel.mail.com", "5 wiki.org"]
 *     Output: ["901 mail.com","50 yahoo.com","900
 *     google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951
 *     com"]
 *     Explanation: We will visit "google.mail.com" 900 times,
 *     "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5
 *     times.
 *     For the subdomains, we will visit "mail.com" 900 + 1 = 901
 *     times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.
 *
 * Constraints:
 *   - 1 <= cpdomain.length <= 100
 *   - 1 <= cpdomain[i].length <= 100
 *   - cpdomain[i] follows either the "repi d1i.d2i.d3i" format or
 *   the "repi d1i.d2i" format.
 *   - repi is an integer in the range [1, 10^4].
 *   - d1i, d2i, and d3i consist of lowercase English letters.
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
struct domainInfo
{
	int ctr;
	char str[101];
};

typedef struct hashT HASH;
struct hashInfo
{
	int idx;
	char str[101];   
};

struct hashT
{
	int size;
	int mod;
	struct hashInfo **arr;
};

int hash(HASH *obj, char *key, int keyLen) 
{
	int tmp;
	if (keyLen > 2)
	{
		tmp = key[0]*15 + key[1] + key[2];
	} else
	{
		tmp = key[0]*15 + key[1];
	}
	return (tmp*(keyLen) % obj->mod);    
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
		obj->arr[x] = newInfo;
		newInfo->idx = -1;
	}
	return obj;
}

void addHash(HASH *ht, char *key, int idx) 
{
	int keyLen = strlen(key);
	int index = hash(ht, key, keyLen);
	while (ht->arr[index]->idx != -1) 
	{
		index++;
		index %= ht->size;
	}
	ht->arr[index]->idx = idx;
	strncpy(ht->arr[index]->str, key, keyLen);
}

int findHash(HASH *ht, char *key) 
{
	int keyLen = strlen(key);
	int index = hash(ht, key, keyLen);
	while (ht->arr[index]->idx != -1) 
	{
		if (!strncmp(ht->arr[index]->str, key, keyLen))
		{
			return ht->arr[index]->idx;
		}
		index++;
		index %= ht->size;
	}
	return -1;
}

void releaseHash(HASH *ht)
{
	for (int i = 0; i < ht->size; i++)
	{
		free(ht->arr[i]);
	}
	free(ht->arr);
	free(ht);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize)
{
	// Prepare the max size of ret
	char **ret = malloc(sizeof(char *)*cpdomainsSize*3);    
	for (int i = 0; i < (cpdomainsSize*3); i++)
	{
		ret[i] = calloc(100, sizeof(char));
	}

	struct domainInfo *dInfo = malloc(sizeof(struct domainInfo)*cpdomainsSize*3);
	int infoNum = 0;
	HASH *h = createHash(400);

	for (int i = 0; i < cpdomainsSize; i++)
	{        
		int idx = 0;
		int ctr = 0;        
		int domainLen = strlen(cpdomains[i]);
		char numDone = 0;
		while (idx < domainLen)
		{
			if (!numDone && cpdomains[i][idx] != ' ')
			{
				ctr = ctr*10 + (cpdomains[i][idx]-'0');
			} else if (cpdomains[i][idx] == ' ' || cpdomains[i][idx] == '.')
			{     
				numDone = 1;
				char *dotStr = &(cpdomains[i][idx+1]);
				int dotStrLen = strlen(dotStr);

				int hashRet = findHash(h, dotStr);
				if ( -1 == hashRet)
				{
					infoNum++;
					dInfo[infoNum-1].ctr = ctr;
					strncpy(dInfo[infoNum-1].str, dotStr, dotStrLen);
					dInfo[infoNum-1].str[dotStrLen] = '\0';
					addHash(h, dotStr, infoNum-1);
				} else
				{
					dInfo[hashRet].ctr += ctr;
				}
			}
			idx++;
		}
	}

	*returnSize = infoNum;
	for (int x = 0; x < infoNum; x++)
	{
		sprintf(ret[x], "%d %s", dInfo[x].ctr, dInfo[x].str);
	}

	free(dInfo);
	releaseHash(h);
	return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static char *sa0_0[] = {"9001 discuss.leetcode.com"};
  char **act_0 = subdomainVisits(sa0_0, 1,&rsz_0);
  static char *cexp_0[] = {"9001 leetcode.com","9001 discuss.leetcode.com","9001 com"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 3))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static char *sa1_0[] = {"900 google.mail.com","50 yahoo.com","1 intel.mail.com","5 wiki.org"};
  char **act_1 = subdomainVisits(sa1_0, 4,&rsz_1);
  static char *cexp_1[] = {"901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 7))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 811, "subdomainVisits", ntests);
 return (pass&&ntests)?0:1;
}
