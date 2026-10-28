/*
 * LeetCode 160. Intersection of Two Linked Lists／相交鏈結串列
 * 題目（繁體中文）
 *   給定兩條鏈結串列的頭節點，找出它們共用的第一個節點並回傳；
 *   若沒有共用節點，回傳 NULL。比較的是「節點是否為同一個記憶體位置」，
 *   兩個不同節點即使 val 相同也不算相交。串列不能因本函式而改變。
 *   兩條串列各至少一個節點，長度最多 30000。
 *
 * 例子
 *   A: 4 → 1 ↘
 *              8 → 4 → 5   （後三個節點由 A、B 共用）
 *   B: 5 → 6 → 1 ↗          → 回傳值為 8 的那個共用節點。
 *   A: 2 → 6 → 4，B: 1 → 5 → NULL → 回傳 NULL。
 *
 * 解題思路
 *   1. 指標 a 從 A 頭走，b 從 B 頭走，每次各前進一節點。
 *   2. 走到尾端時，把 a 改從 B 頭走、b 改從 A 頭走。
 *   3. 兩人最後都走過「A 長度 + B 長度」，起點長度差自然抵消；
 *      有交點便會在共用節點相遇，沒交點則同時變成 NULL。
 *   4. 時間 O(m+n)，額外空間 O(1)。
 *
 * LeetCode 已提供 ListNode 定義；提交時只複製提交區。
 */
#include <stddef.h>
#include <stdio.h>

struct ListNode { int val; struct ListNode *next; };

/* ---------- LeetCode submission / 提交區 ---------- */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    while (a != b) {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}
/* ---------- end submission ---------- */

int main(void) {
    struct ListNode shared3 = {5, NULL}, shared2 = {4, &shared3};
    struct ListNode shared1 = {8, &shared2};
    struct ListNode a2 = {1, &shared1}, a1 = {4, &a2};
    struct ListNode b3 = {1, &shared1}, b2 = {6, &b3}, b1 = {5, &b2};
    struct ListNode other = {8, NULL};
    if (getIntersectionNode(&a1, &b1) != &shared1 ||
        getIntersectionNode(&a1, &other) != NULL) {
        puts("FAIL: 160 intersection-of-two-linked-lists");
        return 1;
    }
    puts("PASS: 160 intersection-of-two-linked-lists");
    return 0;
}
