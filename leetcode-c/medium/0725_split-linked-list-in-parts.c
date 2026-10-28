/*
 * Title-CN: 將鏈結串列拆成多段
 * LeetCode 725. Split Linked List in Parts
 *
 * 題意翻譯：給定一條鏈結串列和整數 k，將串列切成 k 段。各段長度盡量相等，
 * 前面的段可以比後面的段多一個節點；若節點數少於 k，後面的段為空。
 * 回傳每段的頭節點陣列。
 *
 * 範例：1->2->3->4->5，k=3，拆成 [1->2, 3->4, 5]。
 *
 * 限制：節點數為 0 到 1000；1 <= k <= 50。
 *
 * 解題思路：先計算節點總數 n。每段基本長度是 n/k，前 n%k 段再各多一個節點。
 * 依照算出的長度逐段走訪，將該段尾節點的 next 設為 NULL，然後繼續下一段。
 *
 * 複雜度：時間 O(n+k)，空間 O(k)（回傳頭節點陣列）。
 * LeetCode 介面：保留 splitListToParts；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode **splitListToParts(struct ListNode *head, int k, int *returnSize) {
    int length = 0;
    for (struct ListNode *node = head; node != NULL; node = node->next) ++length;

    struct ListNode **parts = malloc((size_t)k * sizeof(*parts));
    if (parts == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = k;
    int baseLength = length / k;
    int extra = length % k;
    struct ListNode *current = head;
    for (int i = 0; i < k; ++i) {
        parts[i] = current;
        int partLength = baseLength + (i < extra ? 1 : 0);
        for (int step = 1; step < partLength; ++step) current = current->next;
        if (partLength > 0) {
            struct ListNode *nextPart = current->next;
            current->next = NULL;
            current = nextPart;
        }
    }
    return parts;
}

int main(void) {
    struct ListNode nodes[5];
    for (int i = 0; i < 5; ++i) {
        nodes[i].val = i + 1;
        nodes[i].next = i + 1 < 5 ? &nodes[i + 1] : NULL;
    }
    int count = 0;
    struct ListNode **parts = splitListToParts(nodes, 3, &count);
    assert(count == 3 && parts[0]->val == 1 && parts[0]->next->val == 2);
    assert(parts[0]->next->next == NULL && parts[1]->val == 3 && parts[1]->next->val == 4);
    assert(parts[1]->next->next == NULL && parts[2]->val == 5 && parts[2]->next == NULL);
    free(parts);

    struct ListNode one = {9, NULL};
    parts = splitListToParts(&one, 3, &count);
    assert(count == 3 && parts[0] == &one && parts[1] == NULL && parts[2] == NULL);
    free(parts);
    return 0;
}
