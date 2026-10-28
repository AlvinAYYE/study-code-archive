/*
 * LeetCode 141. Linked List Cycle／環形鏈結串列
 * 題目（繁體中文）
 *   給定鏈結串列的頭節點，判斷沿 next 一直往前是否會回到走過的節點。
 *   題目說明中的 pos 只用來描述測試資料在哪個位置接回去，不會傳入函式。
 *   節點數可為 0～10000；節點值與是否有環無關。
 *
 * 例子
 *   3 → 2 → 0 → -4，最後的 -4 接回 2 → true。
 *   1 → 2 → NULL → false。
 *
 * 解題思路
 *   1. slow 每次走一步，fast 每次走兩步。
 *   2. 無環時 fast 會走到 NULL；有環時兩者終會在環中相遇。
 *   3. 只需兩個指標，時間 O(n)、額外空間 O(1)。
 *
 * LeetCode 已提供 ListNode 定義；提交時只複製 stdbool.h 與提交區。
 */
#include <stdbool.h>
#include <stdio.h>

struct ListNode { int val; struct ListNode *next; };

/* ---------- LeetCode submission / 提交區 ---------- */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
/* ---------- end submission ---------- */

int main(void) {
    struct ListNode a = {3, NULL}, b = {2, NULL};
    struct ListNode c = {0, NULL}, d = {-4, NULL};
    a.next = &b; b.next = &c; c.next = &d; d.next = &b;
    if (!hasCycle(&a)) {
        puts("FAIL: 141 cycle");
        return 1;
    }
    d.next = NULL;
    if (hasCycle(&a) || hasCycle(NULL)) {
        puts("FAIL: 141 no cycle");
        return 1;
    }
    puts("PASS: 141 linked-list-cycle");
    return 0;
}
