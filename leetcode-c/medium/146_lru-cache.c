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
 * [中文] 題目說明 (翻譯自官方英文題面)
 *     實作容量固定的 LRU 快取，get/put 均需 O(1)。
 *
 * Examples:
 *   Example 1:
 *     Input
 *     ["LRUCache", "put", "put", "get", "put", "get", "put", "get",
 *     "get", "get"]
 *     [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 *     Output
 *     [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 *     Explanation
 *     LRUCache lRUCache = new LRUCache(2);
 *     lRUCache.put(1, 1); // cache is {1=1}
 *     lRUCache.put(2, 2); // cache is {1=1, 2=2}
 *     lRUCache.get(1); // return 1
 *     lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1,
 *     3=3}
 *     lRUCache.get(2); // returns -1 (not found)
 *     lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4,
 *     3=3}
 *     lRUCache.get(1); // return -1 (not found)
 *     lRUCache.get(3); // return 3
 *     lRUCache.get(4); // return 4
 *
 * Constraints:
 *   - 1 <= capacity <= 3000
 *   - 0 <= key <= 10^4
 *   - 0 <= value <= 10^5
 *   - At most 2 * 10^5 calls will be made to get and put.
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
 * [EN] Approach: Doubly-linked list (recency order) + open-addressing hash (node index): move-to-front on touch, evict tail when full. All ops O(1).
 * [中文] 思路: 雙向鏈表維護新近度 + 開放定址雜湊表定位節點：命中即移到頭部，容量滿時淘汰尾端。全部 O(1)。
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
 * Design: array-backed doubly linked list (recency order) + direct-index
 * table loc[key] -> node index.  LeetCode constraints: 0 <= key,value <= 10^4,
 * capacity <= 3*10^4, so a flat loc[10001] is O(1) with zero hashing.
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
    if (c->used < c->cap) {                     /* fresh slot */
        slot = c->used++;
    } else {                                    /* evict LRU */
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
