/*
 * ==========================================================================
 * LeetCode 021. Merge Two Sorted Lists
 * Title-CN: 合併兩個有序鏈表
 * Difficulty: Easy
 * Tags: linked-list, recursion
 * URL: https://leetcode.com/problems/merge-two-sorted-lists/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are given the heads of two sorted linked lists list1 and list2.
 *     Merge the two lists into one sorted list. The list should be made by
 *     splicing together the nodes of the first two lists.
 *     Return the head of the merged linked list.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     兩個已排序單向鏈表
 *     list1、list2，串接節點合併成一個新的有序鏈表並回傳表頭。
 *
 * Examples:
 *   Example 1:
 *     Input: list1 = [1,2,4], list2 = [1,3,4]
 *     Output: [1,1,2,3,4,4]
 *   Example 2:
 *     Input: list1 = [], list2 = []
 *     Output: []
 *   Example 3:
 *     Input: list1 = [], list2 = [0]
 *     Output: [0]
 *
 * Constraints:
 *   - The number of nodes in both lists is in the range [0, 50].
 *   - -100 <= Node.val <= 100
 *   - Both list1 and list2 are sorted in non-decreasing order.
 *
 * LeetCode official C stub (函式簽名):
 *   struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
 *   }
 *
 * [EN] Approach: Dummy head + tail pointer; always attach the smaller front node, then append the rest. Time O(m+n), space O(1).
 * [中文] 思路: 虛擬表頭加尾指針：每次接較小的頭節點，其中一條走完直接接上剩餘鏈表。時間 O(m+n)、空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* LeetCode provides this definition / LeetCode 已提供 */
struct ListNode { int val; struct ListNode *next; };
typedef struct ListNode ListNode;

/* ---------- LeetCode submission / 提交區 ---------- */
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode dummy;                 /* stack-allocated sentinel */
    ListNode *tail = &dummy;
    dummy.next = NULL;
    while (list1 && list2) {
        ListNode *pick;
        if (list1->val <= list2->val) { pick = list1; list1 = list1->next; }
        else                          { pick = list2; list2 = list2->next; }
        tail->next = pick; tail = pick;
    }
    tail->next = list1 ? list1 : list2;
    return dummy.next;
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
    int a1[] = {1, 2, 4}, b1[] = {1, 3, 4}, e1[] = {1, 1, 2, 3, 4, 4};
    ListNode *r = mergeTwoLists(mk(3, a1), mk(3, b1));
    ok = ok && eq(r, 6, e1); freeall(r);

    r = mergeTwoLists(NULL, NULL);
    ok = ok && r == NULL;

    int b3[] = {0}, e3[] = {0};
    r = mergeTwoLists(NULL, mk(1, b3));
    ok = ok && eq(r, 1, e3); freeall(r);

    int a4[] = {5}, b4[] = {1, 2, 3, 4}, e4[] = {1, 2, 3, 4, 5};
    r = mergeTwoLists(mk(1, a4), mk(4, b4));
    ok = ok && eq(r, 5, e4); freeall(r);
    printf("%s: 021 merge-two-sorted-lists\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
