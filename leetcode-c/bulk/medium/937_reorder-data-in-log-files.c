/*
 * ==========================================================================
 * LeetCode 0937. Reorder Data in Log Files
 * Difficulty: Medium
 * Tags: array, string, sorting
 * URL: https://leetcode.com/problems/reorder-data-in-log-files/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an array of logs. Each log is a space-delimited string
 *     of words, where the first word is the identifier.
 *     There are two types of logs:
 *     Reorder these logs so that:
 *     Return the final order of the logs.
 *
 * [中文] 題目: 重新排列日誌檔案
 * [中文] 題目說明:
 *     給定日誌陣列，每筆日誌以識別字開頭，後面接以空格分隔的內容；內容全為
 *     字母者是字母日誌，內容全為數字者是數字日誌。重新排序時，所有字母日誌
 *     須在數字日誌之前，字母日誌依內容字典序排序、內容相同時依識別字排序，
 *     而數字日誌維持原相對順序。回傳排序後的日誌陣列。
 *
 * [中文] 思路:
 *     程式先依識別字後第一個字元把數字日誌與字母日誌分開，保存字母日誌內容
 *     和原索引後排序，最後將排序後字母日誌接在原順序的數字日誌之前。
 *
 * Examples:
 *     Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2
 *     own kit dig","let3 art zero"]
 *     Output: ["let1 art can","let3 art zero","let2 own kit
 *     dig","dig1 8 1 5 1","dig2 3 6"]
 *     Explanation:
 *     The letter-log contents are all different, so their ordering
 *     is "art can", "art zero", "own kit dig".
 *     The digit-logs have a relative order of "dig1 8 1 5 1", "dig2
 *     3 6".
 *     Input: logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off
 *     key dog","a8 act zoo"]
 *     Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3
 *     1","zo4 4 7"]
 *
 * Constraints:
 *   - 1 <= logs.length <= 100
 *   - 3 <= logs[i].length <= 100
 *   - All the tokens of logs[i] are separated by a single space.
 *   - logs[i] is guaranteed to have an identifier and at least one
 *   word after the identifier.
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
typedef struct letterLogsInfo
{
	char str[99];
	int idx;
}LETTERINFO;

bool isDigit(char c)
{
	return ('0' <= c && c <= '9') ? true : false;
}

int compare(const void *a, const void *b)
{
	LETTERINFO *s1 = (LETTERINFO *)a;
	LETTERINFO *s2 = (LETTERINFO *)b;

	int ret = strcmp(s1->str, s2->str);
	return (ret == 0) ? (s2->idx - s1->idx) : ret;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize)
{
	// Record the digit-log index
	int *digitLogRecord = malloc(logsSize*sizeof(int));
	int digitLogCtr = 0;
	// Record the letter-logs info
	LETTERINFO *letterLogInfo = calloc(logsSize, sizeof(LETTERINFO));
	int letterLogCtr = 0;
	for (int logsIdx = 0; logsIdx < logsSize; logsIdx++)
	{        
		int curLogLen = strlen(logs[logsIdx]);
		int i = 0;
		while (logs[logsIdx][i] != ' ')
		{
			i++;
		}
		if (isDigit(logs[logsIdx][i+1]))
		{
			digitLogRecord[digitLogCtr] = logsIdx;
			digitLogCtr++;
		} else
		{
			strcpy(letterLogInfo[letterLogCtr].str, &(logs[logsIdx][i+1]));
			letterLogInfo[letterLogCtr].idx = logsIdx;
			letterLogCtr++;

		}
	}

	qsort(letterLogInfo, letterLogCtr, sizeof(LETTERINFO), compare);

	char **ret = malloc(sizeof(char*)*logsSize);
	*returnSize = logsSize;
	int x;
	for (x = 0; x < letterLogCtr; x++)
	{
		ret[x] = calloc(101, sizeof(char));
		strcpy(ret[x], logs[letterLogInfo[x].idx]);
	}
	for (int i = 0; i < digitLogCtr; i++)
	{
		ret[i+x] = calloc(101, sizeof(char));
		strcpy(ret[i+x], logs[digitLogRecord[i]]);
	}

	free(letterLogInfo);
	return ret;

}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static char *sa0_0[] = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
  char **act_0 = reorderLogFiles(sa0_0, 5,&rsz_0);
  static char *cexp_0[] = {"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 5))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static char *sa1_0[] = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
  char **act_1 = reorderLogFiles(sa1_0, 5,&rsz_1);
  static char *cexp_1[] = {"g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 5))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 937, "reorderLogFiles", ntests);
 return (pass&&ntests)?0:1;
}
