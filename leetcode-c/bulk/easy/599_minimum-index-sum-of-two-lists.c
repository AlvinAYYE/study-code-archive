/*
 * ==========================================================================
 * LeetCode 0599. Minimum Index Sum of Two Lists
 * Difficulty: Easy
 * Tags: array, hash-table, string
 * URL: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given two arrays of strings list1 and list2, find the common strings
 *     with the least index sum.
 *     A common string is a string that appeared in both list1 and list2.
 *     A common string with the least index sum is a common string such
 *     that if it appeared at list1[i] and list2[j] then i + j should be
 *     the minimum value among all the other common strings.
 *     Return all the common strings with the least index sum. Return the
 *     answer in any order.
 *
 * [中文] 題目: 兩個列表的最小索引總和
 * [中文] 題目說明:
 *     給定兩個字串陣列，找出同時出現在兩個列表中的字串。對每個共同字串，將
 *     它在兩列表中的索引相加，回傳索引總和最小的所有字串；若有並列可任意順
 *     序回傳。保證至少存在一個共同字串，且各列表內的字串皆不重複。
 *
 * [中文] 思路:
 *     先以自製雜湊表記錄第一個列表中每個字串的索引，再走訪第二個列表查詢共
 *     同字串。持續維護最小索引和，遇到更小值便清空答案，遇到相同值則一併加
 *     入。
 *
 * Examples:
 *     Input: list1 = ["Shogun","Tapioca Express","Burger
 *     King","KFC"], list2 = ["Piatti","The Grill at Torrey
 *     Pines","Hungry Hunter Steakhouse","Shogun"]
 *     Output: ["Shogun"]
 *     Explanation: The only common string is "Shogun".
 *     Input: list1 = ["Shogun","Tapioca Express","Burger
 *     King","KFC"], list2 = ["KFC","Shogun","Burger King"]
 *     Output: ["Shogun"]
 *     Explanation: The common string with the least index sum is
 *     "Shogun" with index sum = (0 + 1) = 1.
 *     Input: list1 = ["happy","sad","good"], list2 =
 *     ["sad","happy","good"]
 *     Output: ["sad","happy"]
 *     Explanation: There are three common strings:
 *     "happy" with index sum = (0 + 1) = 1.
 *     "sad" with index sum = (1 + 0) = 1.
 *     "good" with index sum = (2 + 2) = 4.
 *     The strings with the least index sum are "sad" and "happy".
 *
 * Constraints:
 *   - 1 <= list1.length, list2.length <= 1000
 *   - 1 <= list1[i].length, list2[i].length <= 30
 *   - list1[i] and list2[i] consist of spaces ' ' and English
 *   letters.
 *   - All the strings of list1 are unique.
 *   - All the strings of list2 are unique.
 *   - There is at least a common string between list1 and list2.
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
/**
599. Minimum Index Sum of Two Lists [E]

Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
	["Shogun", "Tapioca Express", "Burger King", "KFC"]
	["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: 
	["Shogun"]
Explanation: The only restaurant they both like is "Shogun".

Example 2:
Input:
	["Shogun", "Tapioca Express", "Burger King", "KFC"]
	["KFC", "Shogun", "Burger King"]
Output: 
	["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).

Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.

 */

#define HASH_SIZE 52
#define HASH_MOD  52

typedef struct node NODE;
struct node
{
	char *str;
	int idx;
	NODE *next;
};

typedef struct {    
	NODE *bucket[HASH_SIZE];
} HASH;


/** Initialize your data structure here. */

NODE* nodeCreate()
{
	NODE *n = calloc(1, sizeof(NODE));
	n->next = NULL;
	n->str = NULL;
	n->idx = -1;

	return n;
}

HASH* hashCreate() 
{
	HASH *obj = malloc(sizeof(HASH)*HASH_SIZE);    
	for (int i = 0; i < HASH_SIZE; i++)
	{
		obj->bucket[i] = nodeCreate();
	}
	return obj;
}

void destroyHash(HASH *obj)
{
	for (int i = 0; i < HASH_SIZE; i++)
	{
		NODE *tmp = obj->bucket[i];        
		while (tmp != NULL)
		{
			NODE *nextOne = tmp->next;
			free(tmp->str);
			free(tmp);
			tmp = nextOne;
		}                
	}
	free(obj);
}

int doHash(char *key)
{
	return ((key[0]+key[1]) % HASH_MOD);
}

int findHash(HASH *obj, char *key)
{
	int kenLen = strlen(key);
	/* calculate hash index */
	int hashIdx = doHash(key);

	NODE *tmp = obj->bucket[hashIdx];
	while (tmp->str != NULL)
	{
		if (strcmp(tmp->str, key) == 0)
		{
			return tmp->idx;
		} else
		{
			tmp = tmp->next;   
		}        
	}

	return (-1);
}

void hashAdd(HASH *obj, char *key, int idx)
{
	int keyLen = strlen(key);
	/* calculate hash index */
	int hashIdx = doHash(key);
	NODE *newNode = nodeCreate();
	NODE *tmp = obj->bucket[hashIdx];  
	/* Empty bucket, add it directly */
	if (obj->bucket[hashIdx]->str == NULL)
	{
		obj->bucket[hashIdx]->str = calloc(keyLen+1, sizeof(char));        
		strcpy(obj->bucket[hashIdx]->str, key); 
		obj->bucket[hashIdx]->idx = idx;
		obj->bucket[hashIdx]->next = newNode; 
		return;
	} else
	{      
		while (tmp->next != NULL)
		{
			//printf("%s: msg=%s(%d) vs tmp=%s(%d)\n",__func__, msg, time, tmp->msg, tmp->time);
			/* Match the previous msg, check the time > 10*/            
			if (strcmp(obj->bucket[hashIdx]->str, key) == 0)
			{
				printf("%s: Already add key %s \n", __func__, key);
				free(newNode); /* free */
				return;
			}            
			tmp =  tmp->next;
		}        
	}

	tmp->str = calloc(keyLen+1, sizeof(char)); 
	strcpy(tmp->str , key);
	tmp->idx = idx;
	tmp->next = newNode;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize)
{
	HASH *h = hashCreate();

	/* Traverse and add to hash table */
	for (int i = 0; i < list1Size; i++)
	{
		hashAdd(h, list1[i], i);
	}
	// The length of both lists will be in the range of [1, 1000].
	int minRes = 2000;
	// Pre-allocate to recuce extra malloc time when excuting (but waste memory)
	char **ret = calloc(list1Size, sizeof(char *));       
	*returnSize = 0;
	for (int i =0; i < list2Size; i++)
	{
		// No need to check min result because of i is bigger then minRes
		if ( i > minRes)
		{
			break;
		}
		int hashRet = findHash(h, list2[i]);
		if (hashRet == -1)
		{
			continue;
		}
		if ((hashRet + i) < minRes)
		{
			*returnSize = 0;
			ret[*returnSize] = calloc(strlen(list1[hashRet]) + 1, sizeof(char));
			strcpy(ret[*returnSize], list1[hashRet]);
			*returnSize += 1;
			minRes = (hashRet + i);
		} else if ((hashRet + i) == minRes)
		{
			ret[*returnSize] = calloc(strlen(list1[hashRet]) + 1, sizeof(char));
			strcpy(ret[*returnSize], list1[hashRet]);
			*returnSize += 1;
		}
	}
	destroyHash(h);

	return ret;
}

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static char *sa0_0[] = {"Shogun","Tapioca Express","Burger King","KFC"};
  static char *sa0_2[] = {"Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"};
  char **act_0 = findRestaurant(sa0_0, 4,sa0_2, 4,&rsz_0);
  static char *cexp_0[] = {"Shogun"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 1))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static char *sa1_0[] = {"Shogun","Tapioca Express","Burger King","KFC"};
  static char *sa1_2[] = {"KFC","Shogun","Burger King"};
  char **act_1 = findRestaurant(sa1_0, 4,sa1_2, 3,&rsz_1);
  static char *cexp_1[] = {"Shogun"};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 1))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  static char *sa2_0[] = {"happy","sad","good"};
  static char *sa2_2[] = {"sad","happy","good"};
  char **act_2 = findRestaurant(sa2_0, 3,sa2_2, 3,&rsz_2);
  static char *cexp_2[] = {"sad","happy"};
  if (!(lc_eq_cands(act_2, rsz_2, cexp_2, 2))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 599, "findRestaurant", ntests);
 return (pass&&ntests)?0:1;
}
