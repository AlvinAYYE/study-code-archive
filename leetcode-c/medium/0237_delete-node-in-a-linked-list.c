/*
 * Title-CN: 刪除鏈結串列中的指定節點
 * LeetCode 237. Delete Node in a Linked List
 *
 * 題目翻譯：給定單向鏈結串列中的一個節點 node，但不會給你串列的開頭。
 * 請刪除 node。所有值都不同，而且保證 node 不是最後一個節點。
 * 「刪除」是指呼叫後串列不再包含 node 原本的值。
 *
 * 例子：串列 4 -> 5 -> 1 -> 9，給定值為 5 的節點，結果是 4 -> 1 -> 9。
 *
 * 限制：串列有 2 到 1000 個節點；節點值不重複；給定節點一定不是尾節點。
 *
 * 解題步驟：
 *   1. 因為拿不到前一個節點，不能把 node 從前方直接摘除。
 *   2. 把下一個節點的值複製到 node，讓 node 看起來變成下一個節點。
 *   3. 讓 node 越過原本的下一個節點，直接連到下下個節點。
 *   4. 因為 node 保證有下一個節點，這兩步一定可以執行。
 *
 * 複雜度：只修改一個節點，時間 O(1)、額外空間 O(1)。
 *
 * LeetCode 提交區：保留 ListNode 定義與 deleteNode 函式；main() 僅供本機測試。
 */

#include <assert.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode *node) {
    struct ListNode *next = node->next;
    node->val = next->val;
    node->next = next->next;
}

int main(void) {
    struct ListNode first[4];
    first[0] = (struct ListNode){4, &first[1]};
    first[1] = (struct ListNode){5, &first[2]};
    first[2] = (struct ListNode){1, &first[3]};
    first[3] = (struct ListNode){9, NULL};

    deleteNode(&first[1]);
    assert(first[0].val == 4);
    assert(first[0].next == &first[1]);
    assert(first[1].val == 1);
    assert(first[1].next == &first[3]);
    assert(first[1].next->val == 9);

    struct ListNode second[4];
    second[0] = (struct ListNode){4, &second[1]};
    second[1] = (struct ListNode){5, &second[2]};
    second[2] = (struct ListNode){1, &second[3]};
    second[3] = (struct ListNode){9, NULL};

    deleteNode(&second[2]);
    assert(second[1].next == &second[2]);
    assert(second[2].val == 9);
    assert(second[2].next == NULL);
    return 0;
}
