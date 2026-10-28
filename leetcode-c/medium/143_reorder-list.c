/*
 * LeetCode 143. Reorder List
 * Title-CN: 重新排列鏈結串列
 *
 * 題意：給定單向鏈結串列 L0 → L1 → … → Ln，原地改成
 * L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …。不能改節點中的值，只能重新連接節點。
 *
 * 範例：
 * 1. [1,2,3,4] 變成 [1,4,2,3]。
 * 2. [1,2,3,4,5] 變成 [1,5,2,4,3]。
 *
 * 限制：節點數 1 到 5 * 10^4；1 <= Node.val <= 1000。
 *
 * 解題思路：串列先切成前後兩半；把後半反轉，再從前半、後半輪流取一個節點接起來。
 * 例如 [1,2,3,4,5] 切成 [1,2,3] 與 [4,5]，反轉後半成 [5,4]，交錯合併即得答案。
 *
 * 步驟：
 * 1. 快慢指標找前半最後一個節點。
 * 2. 斷開串列，反轉後半。
 * 3. 從兩半各取一個節點交錯連接。
 *
 * 複雜度：時間 O(n)，額外空間 O(1)。
 */
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *previous = NULL;
    while (head != NULL) {
        struct ListNode *next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
}

/* LeetCode 提交函式：直接改接原本節點 */
void reorderList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return;

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *second = reverseList(slow->next);
    slow->next = NULL;

    struct ListNode *first = head;
    while (second != NULL) {
        struct ListNode *firstNext = first->next;
        struct ListNode *secondNext = second->next;
        first->next = second;
        second->next = firstNext;
        first = firstNext;
        second = secondNext;
    }
}

static void makeList(struct ListNode *nodes, const int *values, int count) {
    for (int i = 0; i < count; ++i) {
        nodes[i].val = values[i];
        nodes[i].next = (i + 1 < count) ? &nodes[i + 1] : NULL;
    }
}

static int listEquals(const struct ListNode *head, const int *expected, int count) {
    for (int i = 0; i < count; ++i) {
        if (head == NULL || head->val != expected[i]) return 0;
        head = head->next;
    }
    return head == NULL;
}

int main(void) {
    const int input4[] = {1, 2, 3, 4};
    const int expected4[] = {1, 4, 2, 3};
    struct ListNode nodes4[4];
    makeList(nodes4, input4, 4);
    reorderList(nodes4);
    int passed = listEquals(nodes4, expected4, 4);

    const int input5[] = {1, 2, 3, 4, 5};
    const int expected5[] = {1, 5, 2, 4, 3};
    struct ListNode nodes5[5];
    makeList(nodes5, input5, 5);
    reorderList(nodes5);
    passed = passed && listEquals(nodes5, expected5, 5);

    puts(passed ? "PASS: 143 reorder-list" : "FAIL: 143 reorder-list");
    return passed ? 0 : 1;
}
