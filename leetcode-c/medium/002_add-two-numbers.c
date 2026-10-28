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
 * [中文] 題目說明
 *     給定兩條非空鏈結串列，分別表示兩個非負整數。每個節點只存一位數，
 *     而且數字由個位數開始反向存放。請將兩數相加，並用相同的反向串列格式
 *     回傳總和。除了數字 0 本身以外，輸入不會有前導零。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：l1 = [2,4,3], l2 = [5,6,4]
 *     輸出：[7,0,8]
 *     說明：兩條串列分別表示 342 與 465，342 + 465 = 807。
 *   範例 2：
 *     輸入：l1 = [0], l2 = [0]
 *     輸出：[0]
 *   範例 3：
 *     輸入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 *     輸出：[8,9,9,9,0,0,0,1]
 *
 * [中文] 限制
 *   - 每條串列的節點數介於 1 到 100。
 *   - 0 <= Node.val <= 9。
 *   - 串列表示的數字沒有前導零，數字 0 除外。
 *
 * LeetCode official C stub (函式簽名):
 *   struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 因為串列已從個位數開始排列，可以像直式加法一樣同步往後走。
 *   2. 每一輪把 l1、l2 的目前數字與上一輪進位相加；缺少節點時視為 0。
 *   3. 新節點存 sum % 10，並把 sum / 10 留給下一輪。
 *   4. 兩條串列都走完後，若仍有進位，再建立最後一個節點。
 *   時間複雜度 O(max(m, n))；回傳串列需 O(max(m, n)) 空間，除此之外為 O(1)。
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
        /* 串列長度不同時，已走完的一側視為 0。 */
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
