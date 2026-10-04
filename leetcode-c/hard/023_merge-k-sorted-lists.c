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
 *     K 個已排序鏈表合併成一個有序鏈表。
 *
 * Examples:
 *   Example 1:
 *     Input: lists = [[1,4,5],[1,3,4],[2,6]]
 *     Output: [1,1,2,3,4,4,5,6]
 *     Explanation: The linked-lists are:
 *     [
 *     1->4->5,
 *     1->3->4,
 *     2->6
 *     ]
 *     merging them into one sorted linked list:
 *     1->1->2->3->4->4->5->6
 *   Example 2:
 *     Input: lists = []
 *     Output: []
 *   Example 3:
 *     Input: lists = [[]]
 *     Output: []
 *
 * Constraints:
 *   - k == lists.length
 *   - 0 <= k <= 10^4
 *   - 0 <= lists[i].length <= 500
 *   - -10^4 <= lists[i][j] <= 10^4
 *   - lists[i] is sorted in ascending order.
 *   - The sum of lists[i].length will not exceed 10^4.
 *
 * LeetCode official C stub (函式簽名):
 *   struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
 *   }
 *
 * [EN] Approach: Divide and conquer: pairwise-merge the list array (log k rounds), reusing the two-list merge. Time O(n log k).
 * [中文] 思路: 分治：把鏈表陣列兩兩配對合併（log k 輪），底層沿用雙鏈表合併。時間 O(n log k)。
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
    dummy.next = NULL;
    while (a && b) {
        ListNode *pick;
        if (a->val <= b->val) { pick = a; a = a->next; }
        else                  { pick = b; b = b->next; }
        tail->next = pick; tail = pick;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

ListNode *mergeKLists(ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;
    while (listsSize > 1) {                       /* pairwise rounds: O(n log k) */
        int i, newSize = 0;
        for (i = 0; i < listsSize; i += 2) {
            ListNode *a = lists[i];
            ListNode *b = (i + 1 < listsSize) ? lists[i + 1] : NULL;
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
