/*
 * Title-CN: 扁平化多級雙向鏈結串列
 * LeetCode 430. Flatten a Multilevel Doubly Linked List
 *
 * 題意翻譯：每個節點除了 next、prev，還可能有一條 child 子串列。
 * 請將所有 child 串列插入原串列：遇到節點的 child 時，先完整走訪 child，
 * 再接回原本的 next。扁平化後所有 child 都必須是 NULL，並保持雙向連結正確。
 *
 * 範例：1-2-3-4 中，若 3 的 child 是 7-8-9，扁平後為
 * 1-2-3-7-8-9-4。
 *
 * 限制：節點數不超過 1000；節點值介於 -100000 到 100000。
 *
 * 解題思路：從左到右走訪。遇到 child 時，遞迴把 child 串列扁平化，
 * 把它接在目前節點後面，再把原本的 next 接到 child 串列尾端；接著從尾端繼續。
 * 這樣子串列會完整出現在原 next 之前，而且 prev/next 同步更新。
 *
 * 複雜度：時間 O(n)，每個節點只處理一次；遞迴堆疊最壞 O(n)。
 * LeetCode 介面：保留 flatten；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
    struct Node *child;
};

static struct Node *flattenFrom(struct Node *head) {
    struct Node *node = head;
    struct Node *tail = head;
    while (node != NULL) {
        struct Node *next = node->next;
        if (node->child != NULL) {
            struct Node *childHead = node->child;
            struct Node *childTail = flattenFrom(childHead);

            node->next = childHead;
            childHead->prev = node;
            node->child = NULL;
            childTail->next = next;
            if (next != NULL) next->prev = childTail;
            tail = childTail;
            node = childTail;
        } else {
            tail = node;
        }
        node = node->next;
    }
    return tail;
}

struct Node *flatten(struct Node *head) {
    if (head != NULL) {
        head->prev = NULL;
        flattenFrom(head);
    }
    return head;
}

static struct Node *newNode(int value) {
    struct Node *node = malloc(sizeof(*node));
    assert(node != NULL);
    node->val = value;
    node->prev = node->next = node->child = NULL;
    return node;
}

static void linkNext(struct Node *left, struct Node *right) {
    left->next = right;
    right->prev = left;
}

int main(void) {
    struct Node *nodes[12];
    for (int i = 0; i < 12; ++i) nodes[i] = newNode(i + 1);
    linkNext(nodes[0], nodes[1]);
    linkNext(nodes[1], nodes[2]);
    linkNext(nodes[2], nodes[3]);
    linkNext(nodes[3], nodes[4]);
    linkNext(nodes[4], nodes[5]);
    linkNext(nodes[6], nodes[7]);
    linkNext(nodes[7], nodes[8]);
    linkNext(nodes[8], nodes[9]);
    linkNext(nodes[10], nodes[11]);
    nodes[2]->child = nodes[6];
    nodes[7]->child = nodes[10];

    int expected[] = {1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6};
    struct Node *head = flatten(nodes[0]);
    struct Node *previous = NULL;
    struct Node *node = head;
    for (int i = 0; i < 12; ++i) {
        assert(node != NULL && node->val == expected[i]);
        assert(node->prev == previous && node->child == NULL);
        previous = node;
        node = node->next;
    }
    assert(node == NULL && previous == nodes[5]);
    for (int i = 0; i < 12; ++i) free(nodes[i]);
    assert(flatten(NULL) == NULL);
    return 0;
}
