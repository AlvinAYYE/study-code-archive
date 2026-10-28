/*
 * ==========================================================================
 * LeetCode 023. Merge k Sorted Lists
 * Title-CN: 合併 K 個升序鏈表
 * Difficulty: Hard
 * Tags: linked-list, divide-and-conquer, heap-priority-queue, merge-sort
 * URL: https://leetcode.com/problems/merge-k-sorted-lists/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are given an array of k linked-lists lists, each linked-list is
 *     sorted in ascending order.
 *     Merge all the linked-lists into one sorted linked-list and return it.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     給定一個包含 k 條鏈結串列的陣列 lists，每條串列都已按非遞減
 *     順序排列。請將所有串列合併成一條排序後的鏈結串列並回傳。
 *
 * [中文] 範例：
 *   範例 1：
 *     輸入：lists = [[1,4,5],[1,3,4],[2,6]]
 *     輸出：[1,1,2,3,4,4,5,6]
 *     說明：三條串列分別為 1->4->5、1->3->4、2->6；合併後為
 *           1->1->2->3->4->4->5->6。
 *   範例 2：
 *     輸入：lists = []
 *     輸出：[]
 *   範例 3：
 *     輸入：lists = [[]]
 *     輸出：[]
 *
 * [中文] 限制：
 *   - k == lists.length，且 0 <= k <= 10^4
 *   - 0 <= lists[i].length <= 500
 *   - -10^4 <= lists[i][j] <= 10^4
 *   - 每條 lists[i] 都按非遞減順序排列。
 *   - 所有串列的節點總數不超過 10^4。
 *
 * LeetCode official C stub (函式簽名):
 *   struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
 *   }
 *
 * [EN] Approach: Divide and conquer: pairwise-merge the list array (log k rounds), reusing the two-list merge. Time O(n log k).
 * [中文] 直觀解題思路：
 *   1. 兩條已排序串列可以用兩個游標線性合併：每次接上目前值較小的
 *      節點，直到其中一條用完，再直接接上另一條剩餘部分。
 *   2. 將 k 條串列兩兩配對合併；第一輪由 k 條變約 k/2 條，下一輪再
 *      減半，直到只剩一條。這就是自底向上的分治合併。
 *   3. 每一輪每個節點最多被走訪一次，而輪數為 log k，因此若總節點數
 *      為 N，總時間為 O(N log k)。合併直接重接原節點，不配置新資料節點。
 *
 * 複雜度：時間 O(N log k)，除函式呼叫與輸入陣列外的額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* LeetCode provides this definition / LeetCode 已提供 */
struct ListNode { int val; struct ListNode *next; };
typedef struct ListNode ListNode;

/* ---------- LeetCode submission / 提交區 ---------- */
static ListNode *merge2(ListNode *a, ListNode *b) {
    ListNode dummy, *tail = &dummy;
    /* dummy 讓第一個節點與後續節點使用同一套接法。 */
    dummy.next = NULL;
    while (a && b) {
        ListNode *pick;
        if (a->val <= b->val) { pick = a; a = a->next; }
        else                  { pick = b; b = b->next; }
        tail->next = pick;
        tail = pick;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

ListNode *mergeKLists(ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    while (listsSize > 1) {                       /* 每輪兩兩合併，串列數約減半 */
        int i, newSize = 0;
        for (i = 0; i < listsSize; i += 2) {
            ListNode *a = lists[i];
            ListNode *b = (i + 1 < listsSize) ? lists[i + 1] : NULL;
            /* 奇數條時，最後一條會與 NULL 合併並直接晉級。 */
            lists[newSize++] = merge2(a, b);
        }
        listsSize = newSize;
    }
    return lists[0];
}
/* ---------- end submission ---------- */

static ListNode *mk(int n, const int *v) {
    ListNode *head = NULL; int i;
    for (i = n - 1; i >= 0; --i) {
        ListNode *nd = (ListNode *)malloc(sizeof *nd);
        nd->val = v[i]; nd->next = head; head = nd;
    }
    return head;
}
static int eq(ListNode *l, int n, const int *v) {
    int i;
    for (i = 0; i < n; ++i, l = l ? l->next : NULL)
        if (!l || l->val != v[i]) return 0;
    return l == NULL;
}
static void freeall(ListNode *l) { while (l) { ListNode *x = l; l = l->next; free(x); } }

int main(void) {
    int ok = 1;
    int l1[] = {1, 4, 5}, l2[] = {1, 3, 4}, l3[] = {2, 6};
    int e1[] = {1, 1, 2, 3, 4, 4, 5, 6};
    ListNode *arr[3] = {mk(3, l1), mk(3, l2), mk(2, l3)};
    ListNode *r = mergeKLists(arr, 3);
    ok = ok && eq(r, 8, e1); freeall(r);

    ok = ok && mergeKLists(arr, 0) == NULL;

    int l4[] = {7, 8, 9};
    ListNode *arr2[1] = {mk(3, l4)};
    r = mergeKLists(arr2, 1);
    ok = ok && eq(r, 3, l4); freeall(r);
    printf("%s: 023 merge-k-sorted-lists\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
