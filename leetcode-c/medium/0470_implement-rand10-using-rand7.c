/*
 * Title-CN: 用 Rand7() 實作 Rand10()
 * LeetCode 470. Implement Rand10() Using Rand7()
 *
 * 題意翻譯：你只能呼叫會等機率回傳 1 到 7 的 rand7()。請實作 rand10()，
 * 讓它等機率回傳 1 到 10。
 *
 * 範例：每次呼叫 rand10() 都可能回傳 1 到 10 中任一值，且機率相同。
 *
 * 限制：rand7() 的輸出在 1 到 7 之間且均勻；呼叫 rand10() 次數不超過 10^5。
 *
 * 解題思路：連呼叫兩次 rand7()，把結果組成 1 到 49 的均勻整數：
 * (first-1)*7+second。只接受 1 到 40，將它映射成 1 到 10；拒絕 41 到 49
 * 後重新抽。每個結果恰好對應 4 個被接受的數字，所以 1 到 10 的機率相同。
 *
 * 複雜度：每次嘗試呼叫 rand7() 兩次，平均嘗試次數為 49/40；額外空間 O(1)。
 * LeetCode 介面：保留 rand10；rand7() 在 main 測試中以等機率亂數模擬。
 */

#include <assert.h>
#include <stdlib.h>

static int rand7(void) {
    return rand() % 7 + 1;
}

int rand10(void) {
    int value;
    do {
        value = (rand7() - 1) * 7 + rand7();
    } while (value > 40);
    return (value - 1) % 10 + 1;
}

int main(void) {
    srand(7);
    int counts[11] = {0};
    for (int i = 0; i < 100000; ++i) {
        int value = rand10();
        assert(value >= 1 && value <= 10);
        ++counts[value];
    }
    for (int value = 1; value <= 10; ++value) {
        assert(counts[value] > 9000 && counts[value] < 11000);
    }
    return 0;
}
