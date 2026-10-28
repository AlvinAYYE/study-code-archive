/*
 * ==========================================================================
 * LeetCode 146. LRU Cache
 * Title-CN: LRU 緩存
 * Difficulty: Medium
 * Tags: hash-table, linked-list, design, doublylinked-list
 * URL: https://leetcode.com/problems/lru-cache/
 * ==========================================================================
 * [EN] Problem (official statement, source: github mcaupybugs/leetcode-problems-db)
 *     Design a data structure that follows the constraints of a Least Recently
 *     Used (LRU) cache.
 *     Implement the LRUCache class:
 *     The functions get and put must each run in O(1) average time complexity.
 *
 * [中文] 題目說明
 *     設計一個固定容量、遵循「最近最少使用」（LRU）規則的快取，並實作：
 *       - LRUCache(capacity)：以正整數 capacity 初始化快取。
 *       - get(key)：若 key 存在，回傳其值並標記為最近使用；否則回傳 -1。
 *       - put(key, value)：若 key 已存在就更新值並標記為最近使用；若不存在則
 *         插入。插入使容量超限時，刪除最久未使用的 key。
 *     get 與 put 都必須達到平均 O(1) 時間複雜度。
 *
 * [中文] 範例
 *   範例 1：
 *     輸入：
 *     ["LRUCache", "put", "put", "get", "put", "get", "put", "get",
 *     "get", "get"]
 *     [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 *     輸出：
 *     [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 *     說明：
 *     LRUCache lRUCache = new LRUCache(2);
 *     lRUCache.put(1, 1); // 快取為 {1=1}
 *     lRUCache.put(2, 2); // 快取為 {1=1, 2=2}
 *     lRUCache.get(1);    // 回傳 1，key 1 成為最近使用
 *     lRUCache.put(3, 3); // 淘汰最久未使用的 key 2
 *     lRUCache.get(2);    // 找不到，回傳 -1
 *     lRUCache.put(4, 4); // 淘汰最久未使用的 key 1
 *     lRUCache.get(1);    // 回傳 -1
 *     lRUCache.get(3);    // 回傳 3
 *     lRUCache.get(4);    // 回傳 4
 *
 * [中文] 限制
 *   - 1 <= capacity <= 3000。
 *   - 0 <= key <= 10^4。
 *   - 0 <= value <= 10^5。
 *   - get 與 put 合計最多呼叫 2 * 10^5 次。
 *
 * LeetCode official C stub (函式簽名):
 *   typedef struct {
 *   } LRUCache;
 *   LRUCache* lRUCacheCreate(int capacity) {
 *   }
 *   int lRUCacheGet(LRUCache* obj, int key) {
 *   }
 *   void lRUCachePut(LRUCache* obj, int key, int value) {
 *   }
 *   void lRUCacheFree(LRUCache* obj) {
 *   }
 *
 * [中文] 直觀解題思路
 *   1. 用雙向鏈結串列維護使用順序：head 是最近使用，tail 是最久未使用。
 *   2. 題目限制 key 在 0..10000，可用 loc[key] 直接找到節點槽位，省去搜尋。
 *   3. get 命中或 put 更新時，把該節點從原位置移到 head。
 *   4. put 新增且容量已滿時，重用 tail 槽位，清除舊 key 對應後再移到 head。
 *   每次查找、移動、更新與淘汰都是 O(1)；儲存空間 O(capacity + 10001)。
 * ==========================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- LeetCode submission / 提交區 ----------
 * LeetCode stub: typedef struct { ... } LRUCache;
 *                LRUCache* lRUCacheCreate(int capacity);
 *                int lRUCacheGet(LRUCache* obj, int key);
 *                void lRUCachePut(LRUCache* obj, int key, int value);
 *                void lRUCacheFree(LRUCache* obj);
 * 設計：以陣列模擬雙向鏈結串列，loc[key] 直接對應節點索引。
 * 題目限制 key <= 10^4、capacity <= 3000，因此固定 loc[10001] 可直接 O(1) 查找。
 * ------------------------------------------------- */
#define LRU_KEYMAX 10001

typedef struct {
    int cap, used;
    int *k, *v, *prv, *nxt;   /* per-slot key, value, list links (index+1, 0=nil) */
    int *loc;                 /* key -> slot index+1, 0 = absent */
    int head, tail;           /* index+1 of MRU / LRU slot, 0 = empty */
} LRUCache;

static void lruUnlink(LRUCache *c, int i) {
    int p = c->prv[i], n = c->nxt[i];
    /* 連結存的是 index + 1，讓 0 能代表沒有前後節點。 */
    if (p) c->nxt[p - 1] = n; else c->head = n;
    if (n) c->prv[n - 1] = p; else c->tail = p;
    c->prv[i] = c->nxt[i] = 0;
}
static void lruPushFront(LRUCache *c, int i) {
    c->prv[i] = 0; c->nxt[i] = c->head;
    if (c->head) c->prv[c->head - 1] = i + 1;
    c->head = i + 1;
    if (!c->tail) c->tail = i + 1;
}

LRUCache *lRUCacheCreate(int capacity) {
    LRUCache *c = (LRUCache *)malloc(sizeof *c);
    int i;
    c->cap = capacity; c->used = 0; c->head = c->tail = 0;
    c->k    = (int *)malloc((size_t)capacity * sizeof(int));
    c->v    = (int *)malloc((size_t)capacity * sizeof(int));
    c->prv  = (int *)calloc((size_t)capacity, sizeof(int));
    c->nxt  = (int *)calloc((size_t)capacity, sizeof(int));
    c->loc  = (int *)malloc((size_t)LRU_KEYMAX * sizeof(int));
    for (i = 0; i < LRU_KEYMAX; ++i) c->loc[i] = 0;
    return c;
}

int lRUCacheGet(LRUCache *c, int key) {
    int slot;
    if (key < 0 || key >= LRU_KEYMAX) return -1;
    slot = c->loc[key];
    if (!slot) return -1;
    --slot;
    /* 被讀取的節點立刻成為最近使用。 */
    lruUnlink(c, slot);
    lruPushFront(c, slot);
    return c->v[slot];
}

void lRUCachePut(LRUCache *c, int key, int value) {
    int slot = (key >= 0 && key < LRU_KEYMAX) ? c->loc[key] : 0;
    if (slot) {                                 /* update existing */
        --slot;
        c->v[slot] = value;
        lruUnlink(c, slot);
        lruPushFront(c, slot);
        return;
    }
    if (c->used < c->cap) {                     /* 尚有空槽 */
        slot = c->used++;
    } else {                                    /* 重用最久未使用的尾端槽位 */
        slot = c->tail - 1;
        c->loc[c->k[slot]] = 0;
        lruUnlink(c, slot);
    }
    c->k[slot] = key; c->v[slot] = value;
    c->loc[key] = slot + 1;
    lruPushFront(c, slot);
}

void lRUCacheFree(LRUCache *c) {
    free(c->k); free(c->v); free(c->prv); free(c->nxt); free(c->loc); free(c);
}
/* ---------- end submission ---------- */

int main(void) {
    int ok = 1;
    LRUCache *c = lRUCacheCreate(2);
    lRUCachePut(c, 1, 1); lRUCachePut(c, 2, 2);
    ok = ok && lRUCacheGet(c, 1) == 1;
    lRUCachePut(c, 3, 3);                          /* evicts key 2 */
    ok = ok && lRUCacheGet(c, 2) == -1;
    lRUCachePut(c, 4, 4);                          /* evicts key 1 */
    ok = ok && lRUCacheGet(c, 1) == -1;
    ok = ok && lRUCacheGet(c, 3) == 3;
    ok = ok && lRUCacheGet(c, 4) == 4;
    lRUCachePut(c, 4, 40);                         /* update */
    ok = ok && lRUCacheGet(c, 4) == 40;
    lRUCacheFree(c);
    printf("%s: 146 lru-cache\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
