/*
 * ==========================================================================
 * LeetCode 0127. Word Ladder
 * Difficulty: Hard
 * Tags: hash-table, string, breadth-first-search
 * URL: https://leetcode.com/problems/word-ladder/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     A transformation sequence from word beginWord to word endWord using
 *     a dictionary wordList is a sequence of words beginWord -> s1 -> s2
 *     -> ... -> sk such that:
 *     Given two words, beginWord and endWord, and a dictionary wordList,
 *     return the number of words in the shortest transformation sequence
 *     from beginWord to endWord, or 0 if no such sequence exists.
 *
 * [中文] 題目: 單字接龍
 * [中文] 題目說明:
 *     給定 beginWord、endWord 與字典 wordList，
 *     轉換序列中每一步只能改變一個字母，且每個轉換後的單字都必須在字典中。
 *     請回傳從 beginWord 到 endWord 的最短轉換序列所含
 *     單字數；若不存在則回傳 0。所有單字等長且由小寫英文字母組成，beg
 *     inWord 與 endWord 不同，字典單字不重複。單字長度至多
 *      10，wordList 長度至多 5000。
 *
 * [中文] 思路:
 *     從 beginWord 做廣度優先搜尋，以兩個佇列分層處理；對每個未
 *     拜訪字典單字檢查是否只差一個字母，首次到達 endWord 即得到最
 *     短層數。
 *
 * Examples:
 *     Input: beginWord = "hit", endWord = "cog", wordList =
 *     ["hot","dot","dog","lot","log","cog"]
 *     Output: 5
 *     Explanation: One shortest transformation sequence is "hit" ->
 *     "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
 *     Input: beginWord = "hit", endWord = "cog", wordList =
 *     ["hot","dot","dog","lot","log"]
 *     Output: 0
 *     Explanation: The endWord "cog" is not in wordList, therefore
 *     there is no valid transformation sequence.
 *
 * Constraints:
 *   - 1 <= beginWord.length <= 10
 *   - endWord.length == beginWord.length
 *   - 1 <= wordList.length <= 5000
 *   - wordList[i].length == beginWord.length
 *   - beginWord, endWord, and wordList[i] consist of lowercase
 *   English letters.
 *   - beginWord != endWord
 *   - All the words in wordList are unique.
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
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:


Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.



For example,


Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]


As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.



Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.




UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
*/

typedef struct {
    char **q;
    int n;
} q_t;
int one_diff(char *a, char *b) {
    int diff = 0;
    while (*a && diff <= 1) {
        diff += (*a != *b) ? 1 : 0;
        a ++; b ++;
    }
    return diff == 1 ? 1 : 0;
}
int bfs(q_t *q1, q_t *q2, char *end, char **dict, int sz, int *v) {
    int i, d;
    char *a, *b;
    q_t *tmp;
    
    d = 1;
    while (q1->n) {
        while (q1->n) {
            a = q1->q[-- q1->n];
            for (i = 0; i < sz; i ++) {
                if (v[i]) continue;
                b = dict[i];
                if (one_diff(a, b)) {
                    if (!strcmp(b, end)) {  // done!
                        return d;
                    }
                    v[i] = 1;
                    q2->q[q2->n ++] = b;
                }
            }
        }
        tmp = q1;  // switch queues
        q1 = q2;
        q2 = tmp;
        d ++;
    }
    
    return -1;
}
int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
    int *visited, i, n = 0;
    q_t q1 = { 0 }, q2 = { 0 };
    
    visited = calloc(wordListSize, sizeof(int));
    q1.q = malloc(wordListSize * 2 * sizeof(char *));
    //assert(visited && q1);
    q2.q = &q1.q[wordListSize];
    
    q1.q[q1.n ++] = beginWord;  // initialize q1
    
    n = bfs(&q1, &q2, endWord, wordList, wordListSize, visited);
    
    free(visited);
    free(q1.q);
    
    return n + 1;
}

/*
Difficulty:Medium
Total Accepted:128.8K
Total Submissions:664.1K


Companies Amazon LinkedIn Snapchat Facebook Yelp

*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  char beginWord_0[] = "hit";
  char endWord_0[] = "cog";
  static char *sa0_2[] = {"hot","dot","dog","lot","log","cog"};
  long long act_0 = (long long)ladderLength(beginWord_0,endWord_0,sa0_2, 6);
  if (!(act_0 == 5LL)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  char beginWord_1[] = "hit";
  char endWord_1[] = "cog";
  static char *sa1_2[] = {"hot","dot","dog","lot","log"};
  long long act_1 = (long long)ladderLength(beginWord_1,endWord_1,sa1_2, 5);
  if (!(act_1 == 0LL)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 127, "ladderLength", ntests);
 return (pass&&ntests)?0:1;
}
