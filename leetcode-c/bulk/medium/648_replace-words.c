/*
 * ==========================================================================
 * LeetCode 0648. Replace Words
 * Difficulty: Medium
 * Tags: array, hash-table, string, trie
 * URL: https://leetcode.com/problems/replace-words/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     In English, we have a concept called root, which can be followed by
 *     some other word to form another longer word - let's call this word
 *     derivative. For example, when the root "help" is followed by the
 *     word "ful", we can form a derivative "helpful".
 *     Given a dictionary consisting of many roots and a sentence
 *     consisting of words separated by spaces, replace all the derivatives
 *     in the sentence with the root forming it. If a derivative can be
 *     replaced by more than one root, replace it with the root that has
 *     the shortest length.
 *     Return the sentence after the replacement.
 *
 * [中文] 題目: 單詞替換
 * [中文] 題目說明:
 *     字典提供多個字根，句子中的衍生詞若以前綴字根開頭，須以該字根取代。若
 *     同一詞可由多個字根取代，必須選擇最短的字根。句子只含小寫字母與單一空
 *     格分隔的單詞。
 *
 * [中文] 思路:
 *     將所有字根插入 Trie，並逐一走訪句子的每個單詞。搜尋時一旦到達存
 *     有字根的節點便停止，因而自然取得最短可替換字根。
 *
 * Examples:
 *     Input: dictionary = ["cat","bat","rat"], sentence = "the
 *     cattle was rattled by the battery"
 *     Output: "the cat was rat by the bat"
 *     Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs
 *     bbab cadsfafs"
 *     Output: "a a b c"
 *
 * Constraints:
 *   - 1 <= dictionary.length <= 1000
 *   - 1 <= dictionary[i].length <= 100
 *   - dictionary[i] consists of only lower-case letters.
 *   - 1 <= sentence.length <= 10^6
 *   - sentence consists of only lower-case letters and spaces.
 *   - The number of words in sentence is in the range [1, 1000]
 *   - The length of each word in sentence is in the range [1, 1000]
 *   - Every two consecutive words in sentence will be separated by
 *   exactly one space.
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
648. Replace Words

In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.




Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.



You need to output the sentence after the replacement.



Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"




Note:

The input will only have lower-case letters.
 1 <= dict words number <= 1000 
 1 <= sentence words number <= 1000  
 1 <= root length <= 100 
 1 <= sentence words length <= 1000
*/

typedef struct trie_s {
    struct trie_s *prev;
    struct trie_s *child[26];
    char *s;
} trie_t;
void add2trie(trie_t *node, char *s, trie_t **link_p) {
    char c, *str = s;
    trie_t *child;
    while (c = *(s ++)) {
        child = node->child[c - 'a'];
        if (!child) {
            child = calloc(1, sizeof(trie_t));
            //assert(child);
            child->prev = *link_p;
            *link_p = child;
            node->child[c - 'a'] = child;
        } else if (child->s) {
            return;
        }
        node = child;
    }
    node->s = str;
}
void trie_free(trie_t *link) {
    trie_t *prev;
    while (link) {
        prev = link->prev;
        free(link);     // oj fails here!!!
        link = prev;
    }
}
trie_t *trie_search(trie_t *node, char *str) {
    char c;
    while (c = *(str ++)) {
        node = node->child[c - 'a'];
        if (!node || node->s) return node;
    }
    return NULL;
}
char* replaceWords(char** dict, int dictSize, char* sentence) {
    trie_t root = { 0 }, *node, *link = NULL;
    char *p, *substr;
    
    // build a trie
    while (dictSize) {
        add2trie(&root, dict[-- dictSize], &link);
    }
    
    p = malloc((strlen(sentence) + 1) * sizeof(char));
    //assert(p);
    p[0] = 0;
    
    // search each word in the trie
    while (*sentence) {
        substr = sentence;       // start of a word
        while (*sentence && *sentence != ' ') {
            sentence ++;
        }
        if (*sentence == ' ') {
            *sentence = 0;
            sentence ++;
        }
        // skip blank spaces
        while (*sentence == ' ') sentence ++;
        
        // search
        node = trie_search(&root, substr);
        if (!node) {
            strcat(p, substr);
        } else {
            strcat(p, node->s);
        }
        strcat(p, " ");
    }
    p[strlen(p) - 1] = 0;
    
    trie_free(link);
    
    return p;
}


/*
Difficulty:Medium
Total Accepted:8.4K
Total Submissions:17.7K


Companies Uber
Related Topics Hash Table Trie
Similar Questions 
                
                  
                    Implement Trie (Prefix Tree)
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static char *sa0_0[] = {"cat","bat","rat"};
  char sentence_0[] = "the cattle was rattled by the battery";
  char *act_0 = replaceWords(sa0_0, 3,sentence_0);
  if (!(strcmp(act_0, "the cat was rat by the bat") == 0)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static char *sa1_0[] = {"a","b","c"};
  char sentence_1[] = "aadsfasf absbs bbab cadsfafs";
  char *act_1 = replaceWords(sa1_0, 3,sentence_1);
  if (!(strcmp(act_1, "a a b c") == 0)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 648, "replaceWords", ntests);
 return (pass&&ntests)?0:1;
}
