/*
 * ==========================================================================
 * LeetCode 0506. Relative Ranks
 * Difficulty: Easy
 * Tags: array, sorting, heap-(priority-queue
 * URL: https://leetcode.com/problems/relative-ranks/
 * Source: community solution, repo akib-islam-coder_leetcodesolutions (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an integer array score of size n, where score[i] is
 *     the score of the ith athlete in a competition. All the scores are
 *     guaranteed to be unique.
 *     The athletes are placed based on their scores, where the 1st place
 *     athlete has the highest score, the 2nd place athlete has the 2nd
 *     highest score, and so on. The placement of each athlete determines
 *     their rank:
 *     Return an array answer of size n where answer[i] is the rank of the
 *     ith athlete.
 *
 * [中文] 題目: 相對名次
 * [中文] 題目說明:
 *     給定各選手的唯一分數 score，分數最高者為第 1 名，依此決定所
 *     有名次。前 3 名分別以 Gold、Silver、Bronze Me
 *     dal 表示，其餘以名次數字字串表示。依原選手順序回傳名次陣列。
 *
 * [中文] 思路:
 *     程式建立最大堆依分數由高到低取出選手，並用雜湊表把分數對應回原索引。
 *     依彈出次序填入前三名獎牌或一般名次，即可保留原輸入順序。
 *
 * Examples:
 *     Input: score = [5,4,3,2,1]
 *     Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
 *     Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
 *     Input: score = [10,3,8,9,4]
 *     Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
 *     Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].
 *
 * Constraints:
 *   - n == score.length
 *   - 1 <= n <= 10^4
 *   - 0 <= score[i] <= 10^6
 *   - All the values in score are unique.
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
#define MAX_SIZE 1000001
int hashtable[MAX_SIZE] = {-1};

void insert_heap(int heap[], int element, int n)
{    
    int i = n;   
    while(i>1 && element > heap[i/2])
    {
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = element;
}

int delete_heap(int heap[], int * heap_index)
{
    int tmp = heap[*heap_index];
    int del_element = heap[1];

    heap[1] = tmp;
    
    *heap_index = *heap_index - 1;
    int i = 1;
    int j = i*2;
    while(j <= *heap_index)
    {
        
        if(j+1 <= *heap_index)
        {   

            if(heap[j+1] > heap[j]) //Compare both the childs of root
            {
                j = j+1;
            }
        }
        
        if(heap[j] > tmp)   //Adjust the tmp
        {

            int tmp_element = heap[i];
            heap[i] = heap[j];
            heap[j] = tmp;
            i = j;
            j = i*2;
        }
        else
        {

            break;
        }
        
        
    }    
    return del_element;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRelativeRanks(int* score, int scoreSize, int* returnSize)
{
    memset(hashtable, -1, sizeof(hashtable));
    
    int * heap = (int *)malloc(sizeof(int) * (scoreSize + 1));
    
    heap[0] = 0;
    heap[1] = score[0];
    hashtable[score[0]] = 0;
   
    int i=0;
    for(i=1; i<scoreSize; i++)
    {
        insert_heap(heap, score[i], i+1);
        hashtable[score[i]] = i;
    }
    
    char ** ret_arr = (char **)malloc(sizeof(char *) * scoreSize);
    int ret_arr_index = 0;
    int heap_index = scoreSize;
    
    for(i=1; i<scoreSize+1; i++)
    {
        //printf("del_element : %d \r\n", delete_heap(heap, &heap_index));

        if(i == 1)
        {
            int len = strlen("Gold Medal");
            char * tmp_arr = (char *)malloc(sizeof(char) * (len + 1));
            int delete_element = delete_heap(heap, &heap_index);
            
            int index = hashtable[delete_element];
            ret_arr[index] = tmp_arr;
            memcpy(tmp_arr, "Gold Medal", sizeof(char) * len);
            tmp_arr[len] = '\0';
        }
        else if(i == 2)
        {
            int len = strlen("Silver Medal");
            char * tmp_arr = (char *)malloc(sizeof(char) * (len + 1));
            int delete_element = delete_heap(heap, &heap_index);
            
            int index = hashtable[delete_element];
            ret_arr[index] = tmp_arr;
            memcpy(tmp_arr, "Silver Medal", sizeof(char) * len);
            tmp_arr[len] = '\0';
        }
        else if(i == 3)
        {
            int len = strlen("Bronze Medal");
            char * tmp_arr = (char *)malloc(sizeof(char) * (len + 1));
            int delete_element = delete_heap(heap, &heap_index);
            
            int index = hashtable[delete_element];
            ret_arr[index] = tmp_arr;
            memcpy(tmp_arr, "Bronze Medal", sizeof(char) * len);
            tmp_arr[len] = '\0';
        }
        else
        {
            char tmp_buf[10] = {'\0'};
            sprintf(tmp_buf, "%d", i);
            int len = strlen(tmp_buf);
            char * tmp_arr = (char *)malloc(sizeof(char) * (len + 1));
            int delete_element = delete_heap(heap, &heap_index);
            
            int index = hashtable[delete_element];
            ret_arr[index] = tmp_arr;
            memcpy(tmp_arr, tmp_buf, sizeof(char) * len);
            tmp_arr[len] = '\0';
        }
        
    }

    
    *returnSize = scoreSize;
    return ret_arr;
    
}
/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  int rsz_0 = 0;
  static int arr0_0[] = {5,4,3,2,1};
  char **act_0 = findRelativeRanks(arr0_0, 5,&rsz_0);
  static char *cexp_0[] = {"Gold Medal","Silver Medal","Bronze Medal","4","5"};
  if (!(lc_eq_cands(act_0, rsz_0, cexp_0, 5))) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  int rsz_1 = 0;
  static int arr1_0[] = {10,3,8,9,4};
  char **act_1 = findRelativeRanks(arr1_0, 5,&rsz_1);
  static char *cexp_1[] = {"Gold Medal","5","Bronze Medal","Silver Medal","4"};
  if (!(lc_eq_cands(act_1, rsz_1, cexp_1, 5))) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 506, "findRelativeRanks", ntests);
 return (pass&&ntests)?0:1;
}
