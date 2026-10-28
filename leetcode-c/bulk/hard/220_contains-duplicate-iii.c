/*
 * ==========================================================================
 * LeetCode 0220. Contains Duplicate III
 * Difficulty: Hard
 * Tags: array, sliding-window, sorting, bucket-sort, ordered-set
 * URL: https://leetcode.com/problems/contains-duplicate-iii/
 * Source: community solution, repo vli02_leetcode (verified: compiles + passes example tests)
 * ==========================================================================
 * [EN] Problem (official statement, github mcaupybugs/leetcode-problems-db):
 *     You are given an integer array nums and two integers indexDiff and
 *     valueDiff.
 *     Find a pair of indices (i, j) such that:
 *     Return true if such pair exists or false otherwise.
 *
 * [中文] 題目: 存在重複元素 III
 * [中文] 題目說明:
 *     給定 nums、indexDiff 與 valueDiff，判斷是否存在兩個不同索引
 *     i、j，使 |i-j| <= indexDiff，且 |nums[i]-nums[j]| <= valueDiff。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入 nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
 *     輸出 true。
 *     說明：可選 i=0、j=3；索引差為 3，數值差為 0。
 *   範例 2：
 *     輸入 nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
 *     輸出 false。
 *
 * [中文] 限制：
 *   - 2 <= nums.length <= 10^5
 *   - -10^9 <= nums[i] <= 10^9
 *   - 1 <= indexDiff <= nums.length
 *   - 0 <= valueDiff <= 10^9
 *
 * [中文] 直觀解題思路（目前實作的參數 k、t 分別對應 indexDiff、valueDiff）：
 *   1. 將每個數值與原索引包成 (val,idx)，再依 val 由小到大排序。
 *   2. 固定排序後位置 i，只需向後檢查與 p[i].val 的差不超過 t 的元素；
 *      一旦數值差過大，後面更大的值也不可能符合。
 *   3. 對每個仍符合數值差的候選，計算原索引差；若不超過 k，立即回傳 true。
 *   4. 掃描結束仍找不到即回傳 false。條件式分支避免整數相加時溢位。
 *
 * 排序時間 O(n log n)；候選值密集時雙層枚舉最壞 O(n^2)，額外空間 O(n)。
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
220. Contains Duplicate III

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
*/

typedef struct {
    int val;
    int idx;
} e_t;
int cmp(void const *a, void const *b) {
    return ((const e_t *)a)->val < ((const e_t *)b)->val ? -1 :
           ((const e_t *)a)->val > ((const e_t *)b)->val ?  1 :
           ((const e_t *)a)->idx < ((const e_t *)b)->idx ? -1 : 1;
}
typedef struct {
    long long key;
    int index;
    unsigned char state; /* 0 空槽、1 使用中、2 已刪除 */
} BucketSlot;

static int findBucket(BucketSlot *table, int capacity, long long key) {
    unsigned long long x = (unsigned long long)key;
    int slot;
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    slot = (int)(x & (unsigned long long)(capacity - 1));
    while (table[slot].state != 0) {
        if (table[slot].state == 1 && table[slot].key == key) return slot;
        slot = (slot + 1) & (capacity - 1);
    }
    return -1;
}

static void insertBucket(BucketSlot *table, int capacity,
                         long long key, int index) {
    unsigned long long x = (unsigned long long)key;
    int slot, firstDeleted = -1;
    x ^= x >> 33;
    x *= 0xff51afd7ed558ccdULL;
    x ^= x >> 33;
    slot = (int)(x & (unsigned long long)(capacity - 1));
    while (table[slot].state != 0) {
        if (table[slot].state == 2 && firstDeleted < 0) firstDeleted = slot;
        slot = (slot + 1) & (capacity - 1);
    }
    if (firstDeleted >= 0) slot = firstDeleted;
    table[slot].key = key;
    table[slot].index = index;
    table[slot].state = 1;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    int capacity = 1;
    BucketSlot *table;
    long long width = (long long)t + 1;

    while (capacity < numsSize * 4) capacity <<= 1;
    table = (BucketSlot*)calloc((size_t)capacity, sizeof(BucketSlot));
    if (!table) return false;

    for (int i = 0; i < numsSize; ++i) {
        /* 保留的舊索引需與 i 相差不超過 k。 */
        int expired = i - k - 1;
        if (expired >= 0) {
            long long oldBucket = (long long)nums[expired] / width;
            if (nums[expired] < 0 && nums[expired] % width != 0) --oldBucket;
            int oldSlot = findBucket(table, capacity, oldBucket);
            if (oldSlot >= 0) table[oldSlot].state = 2;
        }

        long long bucket = (long long)nums[i] / width;
        if (nums[i] < 0 && nums[i] % width != 0) --bucket;

        /* 同桶差距一定小於 width；相鄰桶只需再確認實際差值。 */
        if (findBucket(table, capacity, bucket) >= 0) {
            free(table);
            return true;
        }
        for (int offset = -1; offset <= 1; offset += 2) {
            int neighbor = findBucket(table, capacity, bucket + offset);
            if (neighbor >= 0) {
                long long difference = (long long)nums[i] - nums[table[neighbor].index];
                if (difference < 0) difference = -difference;
                if (difference <= t) {
                    free(table);
                    return true;
                }
            }
        }
        insertBucket(table, capacity, bucket, i);
    }

    free(table);
    return false;
}


/*
Difficulty:Medium
Total Accepted:55.6K
Total Submissions:291K


Companies Palantir Airbnb
Related Topics Binary Search Tree
Similar Questions 
                
                  
                    Contains Duplicate
                  
                    Contains Duplicate II
*/

/* ---- generated tests ---- */
int main(void){
 int pass=1,ntests=0;
{
  static int arr0_0[] = {1,2,3,1};
  bool act_0 = containsNearbyAlmostDuplicate(arr0_0, 4,(3),(0));
  if (!(act_0 == true)) { pass = 0; printf("  test 0 FAIL\n"); }
  ntests++; }
{
  static int arr1_0[] = {1,5,9,1,5,9};
  bool act_1 = containsNearbyAlmostDuplicate(arr1_0, 6,(2),(3));
  if (!(act_1 == false)) { pass = 0; printf("  test 1 FAIL\n"); }
  ntests++; }
{
  static int arr2_0[] = {-1,1};
  bool act_2 = containsNearbyAlmostDuplicate(arr2_0, 2,(1),(2));
  if (!(act_2 == true)) { pass = 0; printf("  test 2 FAIL\n"); }
  ntests++; }
{
  static int arr3_0[] = {-1000000000,1000000000};
  bool act_3 = containsNearbyAlmostDuplicate(arr3_0, 2,(1),(1000000000));
  if (!(act_3 == false)) { pass = 0; printf("  test 3 FAIL\n"); }
  ntests++; }
 printf("%s: %04d %s tests=%d\n", (pass&&ntests)?"PASS":"FAIL", 220, "containsNearbyAlmostDuplicate", ntests);
 return (pass&&ntests)?0:1;
}
