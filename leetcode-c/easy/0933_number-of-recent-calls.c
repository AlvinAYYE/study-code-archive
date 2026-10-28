/*
 * Title-CN: 最近的請求次數
 * LeetCode 933. Number of Recent Calls
 *
 * 題意完整翻譯：
 *   設計 RecentCounter，支援 ping(t)。每次呼叫時，回傳最近 3000 毫秒內收到的請求數，時間範圍包含端點 [t - 3000,
 *   t]。每次 ping 的 t 都嚴格大於前一次。
 *
 * 範例：
 *   1. 依序 ping(1)、ping(100)、ping(3001)、ping(3002)，回傳 1、2、3、3。以 t=3001 為例，範圍是
 *      [1,3001]，包含時間 1、100、3001。
 *
 * 限制：
 *   - 1 <= t <= 10^9
 *   - 每次 ping 的 t 嚴格遞增
 *   - ping 最多呼叫 10^4 次
 *
 * 解題步驟：
 *   1. 用陣列依序保存每次請求時間，並用 head 指向目前仍在時間範圍內的第一筆。
 *   2. ping(t) 時將 t 加到陣列尾端。
 *   3. 把所有小於 t - 3000 的舊時間從 head 移出有效範圍。
 *   4. 有效請求數是 tail - head。每筆時間最多被加入、移出各一次。
 *
 * 複雜度：
 *   時間：O(1) 均攤每次 ping；總處理時間 O(P)，P 為 ping 次數。
 *   空間：O(P)，最多保存 10^4 個請求時間。
 *
 * LeetCode C API：
 *   RecentCounter* recentCounterCreate(void); int
 *   recentCounterPing(RecentCounter* obj, int t); void
 *   recentCounterFree(RecentCounter* obj);
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PINGS 10000

typedef struct {
    int times[MAX_PINGS];
    int head;
    int tail;
} RecentCounter;

RecentCounter* recentCounterCreate(void) {
    RecentCounter* obj = (RecentCounter*)calloc(1, sizeof(RecentCounter));
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->times[obj->tail] = t;
    ++obj->tail;

    // 時間範圍包含 t - 3000，因此只移除更早的請求。
    while (obj->head < obj->tail && obj->times[obj->head] < t - 3000) {
        ++obj->head;
    }

    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

int main(void) {
    RecentCounter* counter = recentCounterCreate();
    assert(recentCounterPing(counter, 1) == 1);
    assert(recentCounterPing(counter, 100) == 2);
    assert(recentCounterPing(counter, 3001) == 3);
    assert(recentCounterPing(counter, 3002) == 3);
    recentCounterFree(counter);

    puts("PASS 0933 RecentCounter");
    return 0;
}
