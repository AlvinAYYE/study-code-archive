/*
 * ==========================================================================
 * LeetCode 0898. Bitwise ORs of Subarrays
 * Difficulty: Medium
 * Tags: array, dynamic-programming, bit-manipulation
 * URL: https://leetcode.com/problems/bitwise-ors-of-subarrays/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given an integer array arr, return the number of distinct bitwise
 *     ORs of all the non-empty subarrays of arr.
 *     The bitwise OR of a subarray is the bitwise OR of each integer in
 *     the subarray. The bitwise OR of a subarray of one integer is that
 *     integer.
 *     A subarray is a contiguous non-empty sequence of elements within an
 *     array.
 *
 * [中文] 題目: 子陣列的按位或
 * [中文] 題目說明:
 *     給定整數陣列 arr，計算所有非空連續子陣列的按位或結果中，有多少個
 *     相異值。單一元素子陣列的按位或即為該元素本身。
 *
 * [中文] 思路:
 *     程式維護所有以目前位置結尾之子陣列的相異 OR 值，將前一輪每個值與
 *     新元素 OR 後去重。另以全域雜湊表記錄所有出現過的結果並累加其數量
 *     。
 *
 * Examples:
 *     Input: arr = [0]
 *     Output: 1
 *     Explanation: There is only one possible result: 0.
 *     Input: arr = [1,1,2]
 *     Output: 3
 *     Explanation: The possible subarrays are [1], [1], [2], [1, 1],
 *     [1, 2], [1, 1, 2].
 *     These yield the results 1, 1, 2, 1, 3, 3.
 *     There are 3 unique values, so the answer is 3.
 *     Input: arr = [1,2,4]
 *     Output: 6
 *     Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
 *
 * Constraints:
 *   - 1 <= arr.length <= 5 * 10^4
 *   - 0 <= arr[i] <= 10^9
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
typedef struct hashList HASH_LIST;
struct hashList 
{
	int val;
	HASH_LIST *next;
};

typedef struct 
{
	int size;
	int mod;
	HASH_LIST **list;
} HASH;


HASH_LIST* createNewNode(int val)
{
	HASH_LIST *newNode = calloc(1, sizeof(HASH_LIST));
	newNode->val = val;	
	return newNode;
}

HASH* hashCreate(int size) 
{
	HASH *hash = malloc(sizeof(HASH));
	hash->size = hash->mod = size;
	hash->list = calloc(size,sizeof(HASH_LIST*));
	return hash;
}

int doHash(int mod, int val)
{
	return val % mod;
}

void hashInsert(HASH* obj, int val)
{
	int hashIndex = doHash(obj->mod, val);
	HASH_LIST *newNode = createNewNode(val);
	HASH_LIST *tmp = obj->list[hashIndex];
	if (tmp == NULL)
	{
		obj->list[hashIndex] = newNode;
		return;
	}
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = newNode;
}

bool hashFind(HASH* obj, int val) 
{
	int hashIndex = doHash(obj->mod, val);
	HASH_LIST *tmp = obj->list[hashIndex];

	while (tmp != NULL)
	{
		if (tmp->val == val)
		{
			return true;
		}
		tmp = tmp->next;                
	}

	return false;
}

void hashFree(HASH* obj) 
{
	for (int i = 0; i < obj->size; i++)
	{
		HASH_LIST *tmp = obj->list[i];
		while (tmp)
		{
			HASH_LIST *delNode = tmp;
			tmp = tmp->next;
			free(delNode);
		}   
	}
	free(obj);
}


int subarrayBitwiseORs(int* A, int ASize)
{
	HASH *h = hashCreate(ASize+1);

	int set[32] = {0};
	int setCtr = 0, ret = 0;
	for (int i = 0; i < ASize; i++)
	{
		HASH *hTmp = hashCreate(setCtr+1);

		int curSetCtr = setCtr;
		setCtr = 0;
		for (int x = 0; x < curSetCtr; x++)
		{
			int cur = (set[x] | A[i]);

			if (!hashFind(hTmp, cur))
			{
				hashInsert(hTmp, cur);
				set[setCtr] = cur;
				setCtr++;
			}
			if (!hashFind(h, cur))
			{                
				hashInsert(h, cur);
				ret++;
			}            
		}

		if (!hashFind(hTmp, A[i]))
		{
			set[setCtr] = A[i];
			setCtr++;
		}

		if (!hashFind(h, A[i]))
		{        
			hashInsert(h, A[i]);
			ret++;
		}
		hashFree(hTmp);
	}

	hashFree(h);
	return ret;
}



/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {0};
  long long act_0 = (long long)subarrayBitwiseORs(arr0_0, 1);
  if (!(act_0 == 1LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {1,1,2};
  long long act_1 = (long long)subarrayBitwiseORs(arr1_0, 3);
  if (!(act_1 == 3LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {1,2,4};
  long long act_2 = (long long)subarrayBitwiseORs(arr2_0, 3);
  if (!(act_2 == 6LL)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 898, "subarrayBitwiseORs", ntests);
 return (pass&&ntests)?0:1;
}
