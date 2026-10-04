/*
 * ==========================================================================
 * LeetCode 002. Add Two Numbers
 * Title-CN: 兩數相加
 * Difficulty: Medium
 * Tags: linked-list, math, recursion
 * URL: https://leetcode.com/problems/add-two-numbers/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     You are given two non-empty linked lists representing two non-negative
 *     integers. The digits are stored in reverse order, and each of their
 *     nodes contains a single digit. Add the two numbers and return the sum as
 *     a linked list.
 *     You may assume the two numbers do not contain any leading zero, except
 *     the number 0 itself.
 *
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     兩個鏈表以逆序存放非負整數的每一位，求兩數之和並用同樣的逆序鏈表回傳。
 *
 * Examples:
 *   Example 1:
 *     Input: l1 = [2,4,3], l2 = [5,6,4]
 *     Output: [7,0,8]
 *     Explanation: 342 + 465 = 807.
 *   Example 2:
 *     Input: l1 = [0], l2 = [0]
 *     Output: [0]
 *   Example 3:
 *     Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *     Output: [8,9,9,9,0,0,0,1]
 *
 * Constraints:
 *   - The number of nodes in each linked list is in the range [1, 100].
 *   - 0 <= Node.val <= 9
 *   - It is guaranteed that the list represents a number that does not
 *   have leading zeros.
 *
 * LeetCode official C stub (函式簽名):
 *   struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
 *   }
 *
 * [EN] Approach: School addition with a carry: walk both lists, emit (sum%10) per node, keep the final carry. Time O(max(m,n)), space O(1) extra.
 * [中文] 思路: 直式加法帶進位：同時走兩個鏈表，每節點存 sum%10，最後進位補一新節點。時間 O(max(m,n))、額外空間 O(1)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* LeetCode provides this definition / LeetCode 已提供 */
struct ListNode { int val; struct ListNode *next; };
typedef struct ListNode ListNode;

/* ---------- LeetCode submission / 提交區 ---------- */
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy; ListNode *tail = &dummy; int carry = 0;
    dummy.next = NULL;
    while (l1 || l2 || carry) {
        int s = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode *nd;
        carry = s / 10;
        nd = (ListNode *)malloc(sizeof *nd);
        nd->val = s % 10; nd->next = NULL;
        tail->next = nd; tail = nd;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy.next;
}
/* ---------- end submission ---------- */

static ListNode *mkrev(int n, const int *digits_lsd) { /* build list, least significant digit first */
    ListNode *head = NULL; int i;
    for (i = n - 1; i >= 0; --i) {
        ListNode *nd = (ListNode *)malloc(sizeof *nd);
        nd->val = digits_lsd[i]; nd->next = head; head = nd;
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
    /* 342 + 465 = 807 */
    int a1[] = {2, 4, 3}, b1[] = {5, 6, 4}, e1[] = {7, 0, 8};
    ListNode *r = addTwoNumbers(mkrev(3, a1), mkrev(3, b1));
    ok = ok && eq(r, 3, e1); freeall(r);

    /* 0 + 0 = 0 */
    int a2[] = {0}, b2[] = {0}, e2[] = {0};
    r = addTwoNumbers(mkrev(1, a2), mkrev(1, b2));
    ok = ok && eq(r, 1, e2); freeall(r);

    /* 9999999 + 999 = 10008999 (as digit lists, lsd first) */
    int a3[] = {9,9,9,9,9,9,9}, b3[] = {9,9,9}, e3[] = {8,9,9,0,0,0,0,1};
    r = addTwoNumbers(mkrev(7, a3), mkrev(3, b3));
    ok = ok && eq(r, 8, e3); freeall(r);
    printf("%s: 002 add-two-numbers\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
