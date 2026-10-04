/*
 * ==========================================================================
 * LeetCode 0454. 4Sum II
 * Difficulty: Medium
 * Tags: array, hash-table
 * URL: https://leetcode.com/problems/4sum-ii/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given four integer arrays nums1, nums2, nums3, and nums4 all of
 *     length n, return the number of tuples (i, j, k, l) such that:
 *
 * [中文] 題目: 四數相加 II
 * [中文] 題目說明:
 *     給定四個長度皆為 n 的整數陣列 nums1、nums2、nums3
 *     、nums4，計算索引四元組 (i,j,k,l) 使四個對應元素總和
 *     為 0 的數量。每個索引都分別選自其對應陣列。
 *
 * [中文] 思路:
 *     先用自製雜湊表統計 nums3 與 nums4 每一組和的相反數出現
 *     次數。接著枚舉 nums1 與 nums2 的所有組合，查表並加上相
 *     同和值的計數。
 *
 * Examples:
 *     Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 =
 *     [0,2]
 *     Output: 2
 *     Explanation:
 *     The two tuples are:
 *     1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] =
 *     1 + (-2) + (-1) + 2 = 0
 *     2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] =
 *     2 + (-1) + (-1) + 0 = 0
 *     Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 *     Output: 1
 *
 * Constraints:
 *   - n == nums1.length
 *   - n == nums2.length
 *   - n == nums3.length
 *   - n == nums4.length
 *   - 1 <= n <= 200
 *   - -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228
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
	int ctr;
	int val;
	HASH_LIST *next;
};

typedef struct
{
	int size;
	int mod;
	HASH_LIST  **list;
} HASH;

int hash(HASH *obj, int key) 
{
	return abs(key) % obj->mod;
}

HASH_LIST * createHashInfo()
{
	HASH_LIST  *newInfo = calloc(1, sizeof(HASH_LIST ));
	return newInfo;
}

HASH* createHash(int size)
{
	HASH *obj = malloc(sizeof(HASH));
	obj->size = obj->mod = size;    
	obj->list = malloc(sizeof(HASH_LIST *)*(size));
	for (int x = 0; x < size; x++)
	{
		obj->list[x] = createHashInfo();
	}
	return obj;
}

void addHash(HASH *obj, int key) 
{
	int hashIndex = hash(obj, key);

	HASH_LIST *newNode = createHashInfo();
	if (obj->list[hashIndex]->next == NULL) // Bucket is empty, first time put
	{
		obj->list[hashIndex]->ctr = 1;
		obj->list[hashIndex]->val = key;
		obj->list[hashIndex]->next = newNode;
	} else // Bucket is not empty
	{   
		HASH_LIST *tmp = obj->list[hashIndex];
		while (tmp->next != NULL)
		{
			if (tmp->val == key)
			{
				tmp->ctr += 1;
				free(newNode);
				return;
			}
			tmp = tmp->next;
		}
		tmp->ctr = 1;
		tmp->val = key;
		tmp->next = newNode;
	}
}

int findHash(HASH *obj, int target) 
{
	int hashIndex = hash(obj, target);
	HASH_LIST *tmp = obj->list[hashIndex];

	while (tmp->next != NULL)
	{
		if (tmp->val == target)
		{
			return tmp->ctr;
		}
		tmp = tmp->next;                
	}
	return 0;
}

void releaseHash(HASH *obj)
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
	free(obj->list);
	free(obj);
}

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize)
{
	int ret = 0, size = ASize;

	HASH *h = createHash(size*size+1);
	for (int i = 0; i < size; i++)
	{        
		for (int j = 0; j < size; j++)
		{
			addHash(h, (C[i] + D[j])*(-1));
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int tmpSum = A[i] + B[j];
			ret += findHash(h, tmpSum);
		}
	}

	releaseHash(h);    
	return ret;
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {1,2};
  static int arr0_2[] = {-2,-1};
  static int arr0_4[] = {-1,2};
  static int arr0_6[] = {0,2};
  long long act_0 = (long long)fourSumCount(arr0_0, 2,arr0_2, 2,arr0_4, 2,arr0_6, 2);
  if (!(act_0 == 2LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {0};
  static int arr1_2[] = {0};
  static int arr1_4[] = {0};
  static int arr1_6[] = {0};
  long long act_1 = (long long)fourSumCount(arr1_0, 1,arr1_2, 1,arr1_4, 1,arr1_6, 1);
  if (!(act_1 == 1LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 454, "fourSumCount", ntests);
 return (pass&&ntests)?0:1;
}
