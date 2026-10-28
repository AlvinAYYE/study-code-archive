/*
 * ==========================================================================
 * LeetCode 0140. Word Break II
 * Difficulty: Hard
 * Tags: array, hash-table, string, dynamic-programming, backtracking, trie, memoization
 * URL: https://leetcode.com/problems/word-break-ii/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     Given a string s and a dictionary of strings wordDict, add spaces in
 *     s to construct a sentence where each word is a valid dictionary
 *     word. Return all such possible sentences in any order.
 *     Note that the same word in the dictionary may be reused multiple
 *     times in the segmentation.
 *
 * [中文] 題目: 單字拆分 II
 * [中文] 題目說明:
 *     給定字串 s 與字典 wordDict，請在 s 中加入空格，形成每
 *     個單字都存在於字典中的所有可能句子，順序不限。切分時同一個字典單字可
 *     以重複使用。若無合法切分則回傳空陣列。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 *     輸出：["cats and dog","cat sand dog"]
 *   範例 2：
 *     輸入：s = "pineapplepenapple",
 *           wordDict = ["apple","pen","applepen","pine","pineapple"]
 *     輸出：["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 *     說明：同一個字典單字可以重複使用。
 *   範例 3：
 *     輸入：s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 *     輸出：[]
 *
 * [中文] 限制：
 *   - 1 <= s.length <= 20
 *   - 1 <= wordDict.length <= 1000
 *   - 1 <= wordDict[i].length <= 10
 *   - s 與 wordDict[i] 僅包含小寫英文字母。
 *   - wordDict 中的字串互不重複。
 *   - 測試資料保證所有答案字串的總長度不超過 10^5。
 *
 * [中文] 直觀解題思路：
 *   1. 將字串位置視為切點；dp[i] 保存從切點 i 可接到哪些下一個切點。
 *   2. 從 dp[0] 開始，只處理已可到達的切點。逐一比對所有字典單字，若
 *      s[i..] 以該單字開頭，就在 dp[i] 記錄單字結束位置 k，並建立 dp[k]。
 *   3. 如此先建出一張只包含合法切分的有向圖，也可提前判斷終點是否可達。
 *   4. 若 dp[len] 存在，從位置 0 沿記錄的邊回溯；每走一條邊就把對應單字
 *      與空格寫入暫存字串，到終點時複製成一筆答案。
 *   5. 回溯返回後以原長度覆寫緩衝區，繼續嘗試其他切法。
 *
 * 建圖時間 O(|s| * D * L)，D 為字典大小、L 為單字長度；列舉階段與
 * 輸出總量成正比。DP、路徑與回傳結果所需空間另計。
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
/*
140. Word Break II

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.



Return all such possible sentences.



For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].



A solution is ["cats and dog", "cat sand dog"].



UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char **p;
    int sz;
    int n;
} res_t;
typedef struct {
    char *b;
    int sz;
    int n;
} buff_t;
void add2res(res_t *res, char *str) {
    if (res->sz == res->n) {
        res->sz *= 2;
        res->p = realloc(res->p, res->sz * sizeof(char *));
        //assert(res->p);
    }
    res->p[res->n ++] = str;
}
void add2buff(buff_t *buff, int n, char *s, int l) {
    buff->n = n;
    if (buff->sz <= buff->n + l + 2) {
        buff->sz *= 2 + l + 2;
        buff->b = realloc(buff->b, buff->sz * sizeof(char));
        //assert(buff->b);
    }
    strncpy(&buff->b[buff->n], s, l);
    buff->n += l;
    buff->b[buff->n] = ' ';
    buff->n ++;
}
int *newvec() {
    int *vec = malloc(12 * sizeof(int));
    //assert(vec);
    vec[0] = 12;
    vec[1] = 0;
    return vec;
}
void add2vec(int *vec, int i) {
    if (vec[0] == vec[1]) {
        vec[0] *= 2;
        vec = realloc(vec, vec[0] * sizeof(int));
        //assert(vec);
    }
    vec[2 + vec[1] ++] = i;
}
void bt(res_t *res, buff_t *buff, char *s, int **dp, int start, int end) {
    int i, k, n, *vec;
    
    if (start == end) {
        /* 移除最後一個空格，複製出獨立答案字串。 */
        buff->b[-- buff->n] = 0;
        add2res(res, strdup(buff->b));
        return;
    }
    
    n = buff->n;
    
    vec = dp[start];
    for (i = 0; i < vec[1]; i ++) {
        k = vec[2 + i];
        add2buff(buff, n, &s[start], k - start);
        bt(res, buff, s, dp, k, end);
    }
}
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    res_t res;
    buff_t buff;
    
    int *wsz, **dp, *vec;
    int len, i, j, k;
 
    res.sz = 10;
    res.n = 0;
    res.p = malloc(res.sz * sizeof(char *));
    //assert(res.p);
    
    wsz = calloc(wordDictSize, sizeof(int));
    len = strlen(s);
    dp = calloc(len + 1, sizeof(int *));
    //assert(dp && used && len);
    
    buff.sz = 100;
    buff.n = 0;
    buff.b = malloc(buff.sz * sizeof(char));
    //assert(buff.b);
    
    for (i = 0; i < wordDictSize; i ++) {
        wsz[i] = strlen(wordDict[i]);
    }
    
    dp[0] = newvec();
    for (i = 0; i < len; i ++) {
        if (dp[i]) {    /* 只從可到達的合法切點繼續延伸 */
            for (j = 0; j < wordDictSize; j ++) {
                if (!strncmp(&s[i], wordDict[j], wsz[j])) {
                    k = i + wsz[j];
                    add2vec(dp[i], k);  /* 記錄一條合法切分邊 i -> k */
                    if (!dp[k]) dp[k] = newvec();
                }
            }
        }
    }
    
    if (dp[len]) {
        bt(&res, &buff, s, dp, 0, len);
    }
    
    free(wsz);
    for (i = 1; i <= len; i ++) {
        if (dp[i]) free(dp[i]);
    }
    free(dp);
    free(buff.b);
 
    *returnSize = res.n;
    
    return res.p;
}


/*
Difficulty:Hard
Total Accepted:92K
Total Submissions:395K


Companies Dropbox Google Uber Snapchat Twitter
Related Topics Dynamic Programming Backtracking
Similar Questions 
                
                  
                    Word Break
                  
                    Concatenated Words
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  char s_0[] = "catsanddog";
  static char *sa0_1[] = {"cat","cats","and","sand","dog"};
  char **act_0 = wordBreak(s_0,sa0_1, 5,&rsz_0);
  static char *cexp_0[] = {"cats and dog","cat sand dog"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 2))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  char s_1[] = "pineapplepenapple";
  static char *sa1_1[] = {"apple","pen","applepen","pine","pineapple"};
  char **act_1 = wordBreak(s_1,sa1_1, 5,&rsz_1);
  static char *cexp_1[] = {"pine apple pen apple","pineapple pen apple","pine applepen apple"};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 3))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  int rsz_2 = 0;
  char s_2[] = "catsandog";
  static char *sa2_1[] = {"cats","dog","sand","and","cat"};
  char **act_2 = wordBreak(s_2,sa2_1, 5,&rsz_2);
  static char *cexp_2[] = {""};
  if (!(lc_eq_cands(act_2, rsz_2, cexp_2, 0))) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 140, "wordBreak", ntests);
 return (pass&&ntests)?0:1;
}
