/*
 * LeetCode 142. Linked List Cycle II
 * Title-CN: 找出鏈結串列環的起點
 *
 * 題意：給定單向鏈結串列的頭節點。若串列有環，回傳環開始的節點；沒有環時回傳 NULL。
 * 環表示沿著 next 一直前進會再次走到先前看過的節點。題目用 pos 表示尾端接回的索引，
 * 但 pos 不會傳入函式。不得修改串列。
 *
 * 範例：
 * 1. [3,2,0,-4] 且尾端接回索引 1，回傳值為第二個節點（值為 2）的節點指標。
 * 2. [1,2] 且尾端接回索引 0，回傳頭節點。
 * 3. [1] 且 pos=-1，沒有環，回傳 NULL。
 *
 * 限制：節點數 0 到 10^4；-10^5 <= Node.val <= 10^5；pos 為 -1 或有效索引。
 *
 * 解題思路：快慢指標先確認是否有環。快指標每次走兩格、慢指標每次走一格；若相遇，
 * 一個指標回到頭節點，兩個指標改成每次走一格。它們下一次相遇的位置就是環起點。
 *
 * 為什麼有效：設頭到環入口長 a，入口到第一次相遇點長 b，環長 c。相遇時快指標比慢指標
 * 多走的距離是環長的整數倍，因此 a+b 是 c 的倍數。從頭走 a 格會到入口；從相遇點走 a 格，
 * 因為 a+b 是整數個環長，也會到入口。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)。
 */
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/* LeetCode 提交函式 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            struct ListNode *fromHead = head;
            while (fromHead != slow) {
                fromHead = fromHead->next;
                slow = slow->next;
            }
            return fromHead;
        }
    }
    return NULL;
}

int main(void) {
    struct ListNode a = {3, NULL};
    struct ListNode b = {2, NULL};
    struct ListNode c = {0, NULL};
    struct ListNode d = {-4, NULL};
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &b;

    int passed = detectCycle(&a) == &b;
    d.next = &a;
    passed = passed && detectCycle(&a) == &a;
    d.next = NULL;
    passed = passed && detectCycle(&a) == NULL;

    puts(passed ? "PASS: 142 linked-list-cycle-ii" : "FAIL: 142 linked-list-cycle-ii");
    return passed ? 0 : 1;
}
