/*
 * Title-CN: 隨機選取鏈結串列節點
 * LeetCode 382. Linked List Random Node
 *
 * 題目翻譯：設計一個資料結構，保存非空單向鏈結串列的開頭。每次呼叫
 * getRandom() 時，所有節點都必須有相同機率被選中。串列長度事先未知。
 *
 * 例子：串列為 1 -> 2 -> 3，呼叫 getRandom() 會回傳 1、2、3 其中一個。
 *
 * 限制：串列至少有一個節點，最多 10000 個；最多呼叫 getRandom() 10000 次。
 *
 * 解題步驟：每次從頭掃描串列，用蓄水池抽樣選一個節點：第 1 個節點先入選；
 * 第 i 個節點以 1/i 的機率取代目前答案。掃描完後，每個節點都有相同的 1/n 機率。
 *
 * 複雜度：每次抽樣走訪 n 個節點，時間 O(n)，只保存一個候選值，額外空間 O(1)。
 *
 * LeetCode 提交區：保留 ListNode、Solution 與三個函式；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    struct ListNode *head;
} Solution;

Solution *solutionCreate(struct ListNode *head) {
    Solution *obj = malloc(sizeof(*obj));
    if (obj != NULL) {
        obj->head = head;
    }
    return obj;
}

int solutionGetRandom(Solution *obj) {
    int chosen = obj->head->val;
    int seen = 1;
    for (struct ListNode *node = obj->head->next; node != NULL; node = node->next) {
        ++seen;
        if (rand() % seen == 0) {
            chosen = node->val;
        }
    }
    return chosen;
}

void solutionFree(Solution *obj) {
    free(obj);
}

int main(void) {
    struct ListNode nodes[3];
    nodes[0] = (struct ListNode){1, &nodes[1]};
    nodes[1] = (struct ListNode){2, &nodes[2]};
    nodes[2] = (struct ListNode){3, NULL};

    srand(7);
    Solution *obj = solutionCreate(&nodes[0]);
    assert(obj != NULL);
    for (int i = 0; i < 100; ++i) {
        int value = solutionGetRandom(obj);
        assert(value == 1 || value == 2 || value == 3);
    }
    solutionFree(obj);

    Solution *single = solutionCreate(&nodes[2]);
    assert(single != NULL);
    assert(solutionGetRandom(single) == 3);
    solutionFree(single);
    return 0;
}
