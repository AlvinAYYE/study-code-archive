/*
 * ==========================================================================
 * LeetCode 0468. Validate IP Address
 * Difficulty: Medium
 * Tags: string
 * URL: https://leetcode.com/problems/validate-ip-address/
 * Source: community solution, repo kenjin_Awesome-LC-Cracker (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given a string queryIP, return "IPv4" if IP is a valid IPv4 address,
 *     "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a
 *     correct IP of any type.
 *     A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <=
 *     xi <= 255 and xi cannot contain leading zeros. For example,
 *     "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while
 *     "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4
 *     addresses.
 *     A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8"
 *     where:
 *     For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and
 *     "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while
 *     "2001:0db8:85a3::8A2E:037j:7334" and
 *     "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6
 *     addresses.
 *
 * [中文] 題目: 驗證 IP 位址
 * [中文] 題目說明:
 *     給定 queryIP，合法 IPv4 回傳「IPv4」，合法 IPv
 *     6 回傳「IPv6」，否則回傳「Neither」。IPv4 要有 4
 *      個介於 0 到 255 且無前導零的十進位欄位。IPv6 要有 8
 *      個以冒號分隔、各含 1 到 4 個十六進位字元的欄位。
 *
 * [中文] 思路:
 *     程式依是否含句點選擇 IPv4 或 IPv6 驗證，並拆分欄位、計算
 *     群組與分隔符數。IPv4 檢查數字、前導零與範圍；IPv6 檢查十六
 *     進位字元與欄位長度。
 *
 * Examples:
 *     Input: queryIP = "172.16.254.1"
 *     Output: "IPv4"
 *     Explanation: This is a valid IPv4 address, return "IPv4".
 *     Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
 *     Output: "IPv6"
 *     Explanation: This is a valid IPv6 address, return "IPv6".
 *     Input: queryIP = "256.256.256.256"
 *     Output: "Neither"
 *     Explanation: This is neither a IPv4 address nor a IPv6
 *     address.
 *
 * Constraints:
 *   - queryIP consists only of English letters, digits and the
 *   characters '.' and ':'.
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
bool validHexChar(char c)
{
	if (('0' <= c & c <= '9') ||
			('a' <= c & c <= 'f') ||
			('A' <= c & c <= 'F'))
	{
		return true;
	}
	return false;
}

bool validIPv6(char *s)
{
	int len = strlen(s);
	int strCtr = 0;
	int groupCtr = 0;
	char *delim = ":";
	char *pch;
	pch = strtok(s, delim);
	while (pch != NULL)
	{
		int hexCtr = 0;        
		char *tmp = pch;
		while (*tmp)
		{
			if (!validHexChar(*tmp))
			{
				return false;
			}
			hexCtr++;
			strCtr++;
			tmp++;            
		}

		if (hexCtr > 4)
		{
			return false;
		}
		pch = strtok(NULL, delim);
		groupCtr++;
	} 

	return (groupCtr != 8 || len - strCtr != 7) ? false : true;
}

bool validIPv4(char *s)
{
	int len = strlen(s);
	int strCtr = 0;
	int groupCtr = 0;
	char *delim = ".";
	char *pch;
	pch = strtok(s, delim);
	while (pch != NULL)
	{
		int num = 0, gotZero = 0;
		char *tmp = pch;
		while (*tmp)
		{
			if (*tmp < '0' || *tmp > '9' || gotZero)
			{
				return false;
			}
			if (*tmp == '0')
			{                
				gotZero = 1;
			}
			strCtr++;
			num *= 10;
			num += *tmp - '0';
			tmp++;
			if (num < 0 || num > 255)
			{
				return false;
			}
		}
		pch = strtok(NULL, delim);
		groupCtr++;
	}      

	return (groupCtr != 4 || len - strCtr != 3) ? false : true;
}

char * validIPAddress(char * IP)
{
	// IPv4: 
	if (NULL != strchr(IP, '.'))
	{
		return (validIPv4(IP) ? "IPv4" : "Neither");
	} else
	{
		return (validIPv6(IP) ? "IPv6" : "Neither");
	}
}


/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char queryIP_0[] = "172.16.254.1";
  char *act_0 = validIPAddress(queryIP_0);
  if (!(strcmp(act_0, "IPv4") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char queryIP_1[] = "2001:0db8:85a3:0:0:8A2E:0370:7334";
  char *act_1 = validIPAddress(queryIP_1);
  if (!(strcmp(act_1, "IPv6") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  char queryIP_2[] = "256.256.256.256";
  char *act_2 = validIPAddress(queryIP_2);
  if (!(strcmp(act_2, "Neither") == 0)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 468, "validIPAddress", ntests);
 return (pass&&ntests)?0:1;
}
