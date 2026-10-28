/*
 * LeetCode 460. LFU Cache／最不常使用快取
 *
 * 題目（繁體中文）
 *   設計容量固定的 LFU 快取。get(key) 命中時回傳值並增加該 key 的使用次數，
 *   未命中時回傳 -1；
 *   put(key,value) 更新已存在 key 時也增加使用次數。新增資料使快取超量時，
 *   淘汰使用次數最少的 key；若次數相同，淘汰最久未使用者。查找與更新都要
 *   平均 O(1)。
 *
 * 範例：capacity=2，依序 put(1,1)、put(2,2)、get(1)、put(3,3)，會淘汰
 *   key 2；之後 get(2)=-1、get(3)=3。若再 put(4,4)，會在同頻率者中淘汰
 *   較久沒用的 key 1。
 * 限制：1 <= capacity <= 10^4；0 <= key <= 10^5；0 <= value <= 10^9；
 *   get 與 put 合計最多 2×10^5 次。
 *
 * 解題步驟：
 *   1. 每個快取節點記錄 key、value、使用次數與所屬頻率桶；用 key 範圍表格
 *      直接找到節點。
 *   2. 頻率桶依次數由小到大串成雙向鏈結串列，每個桶內再以雙向鏈結串列
 *      記錄最近使用順序（前端最新、尾端最舊）。
 *   3. get 或更新 put 時，把節點從 f 桶移到 f+1 桶；相鄰桶不存在才建立。
 *   4. 新 key 放進頻率 1 桶；滿載時刪除第一個頻率桶尾端的節點，正好符合
 *      「最低頻率、同頻率最久未使用」的淘汰規則。
 *   get 與 put 平均 O(1)；空間 O(容量 + key 範圍 + 頻率桶數)。
 *
 * LeetCode C API：lFUCacheCreate、lFUCacheGet、lFUCachePut、lFUCacheFree。
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LFU_MAX_KEY 100000

typedef struct LFUNode LFUNode;
typedef struct FrequencyBucket FrequencyBucket;

struct LFUNode {
    int key;
    int value;
    int frequency;
    FrequencyBucket *bucket;
    LFUNode *previous; /* 較新節點 */
    LFUNode *next;     /* 較舊節點 */
};

struct FrequencyBucket {
    int frequency;
    FrequencyBucket *previous;
    FrequencyBucket *next;
    LFUNode *newest;
    LFUNode *oldest;
};

typedef struct {
    int capacity;
    int size;
    LFUNode **byKey;
    FrequencyBucket first;
    FrequencyBucket last;
} LFUCache;

static FrequencyBucket *newFrequencyBucket(int frequency) {
    FrequencyBucket *bucket = (FrequencyBucket *)calloc(1, sizeof *bucket);
    if (bucket != NULL) bucket->frequency = frequency;
    return bucket;
}

static void insertBucketAfter(FrequencyBucket *position,
                              FrequencyBucket *bucket) {
    bucket->previous = position;
    bucket->next = position->next;
    position->next->previous = bucket;
    position->next = bucket;
}

static void removeBucket(FrequencyBucket *bucket) {
    bucket->previous->next = bucket->next;
    bucket->next->previous = bucket->previous;
    free(bucket);
}

static void insertNodeAsNewest(FrequencyBucket *bucket, LFUNode *node) {
    node->bucket = bucket;
    node->previous = NULL;
    node->next = bucket->newest;
    if (bucket->newest != NULL) bucket->newest->previous = node;
    else bucket->oldest = node;
    bucket->newest = node;
}

static void unlinkNode(LFUNode *node) {
    FrequencyBucket *bucket = node->bucket;
    if (node->previous != NULL) node->previous->next = node->next;
    else bucket->newest = node->next;
    if (node->next != NULL) node->next->previous = node->previous;
    else bucket->oldest = node->previous;
    node->previous = NULL;
    node->next = NULL;
}

static void increaseFrequency(LFUCache *obj, LFUNode *node) {
    FrequencyBucket *oldBucket = node->bucket;
    FrequencyBucket *target = oldBucket->next;
    if (target == &obj->last || target->frequency != oldBucket->frequency + 1) {
        target = newFrequencyBucket(oldBucket->frequency + 1);
        if (target == NULL) return;
        insertBucketAfter(oldBucket, target);
    }
    unlinkNode(node);
    ++node->frequency;
    insertNodeAsNewest(target, node);
    if (oldBucket->newest == NULL) removeBucket(oldBucket);
}

/* ---------- LeetCode submission / 提交區 ---------- */
LFUCache *lFUCacheCreate(int capacity) {
    LFUCache *obj = (LFUCache *)calloc(1, sizeof *obj);
    if (obj == NULL) return NULL;
    obj->capacity = capacity;
    obj->byKey = (LFUNode **)calloc((size_t)LFU_MAX_KEY + 1,
                                    sizeof *obj->byKey);
    if (obj->byKey == NULL) {
        free(obj);
        return NULL;
    }
    obj->first.next = &obj->last;
    obj->last.previous = &obj->first;
    return obj;
}

int lFUCacheGet(LFUCache *obj, int key) {
    if (obj == NULL || key < 0 || key > LFU_MAX_KEY) return -1;
    LFUNode *node = obj->byKey[key];
    if (node == NULL) return -1;
    int value = node->value;
    increaseFrequency(obj, node);
    return value;
}

void lFUCachePut(LFUCache *obj, int key, int value) {
    if (obj == NULL || key < 0 || key > LFU_MAX_KEY || obj->capacity <= 0) return;
    LFUNode *node = obj->byKey[key];
    if (node != NULL) {
        node->value = value;
        increaseFrequency(obj, node);
        return;
    }

    if (obj->size == obj->capacity) {
        FrequencyBucket *leastBucket = obj->first.next;
        LFUNode *victim = leastBucket->oldest;
        obj->byKey[victim->key] = NULL;
        unlinkNode(victim);
        free(victim);
        --obj->size;
        if (leastBucket->newest == NULL) removeBucket(leastBucket);
    }

    FrequencyBucket *oneBucket = obj->first.next;
    if (oneBucket == &obj->last || oneBucket->frequency != 1) {
        oneBucket = newFrequencyBucket(1);
        if (oneBucket == NULL) return;
        insertBucketAfter(&obj->first, oneBucket);
    }
    node = (LFUNode *)calloc(1, sizeof *node);
    if (node == NULL) {
        if (oneBucket->newest == NULL) removeBucket(oneBucket);
        return;
    }
    node->key = key;
    node->value = value;
    node->frequency = 1;
    insertNodeAsNewest(oneBucket, node);
    obj->byKey[key] = node;
    ++obj->size;
}

void lFUCacheFree(LFUCache *obj) {
    if (obj == NULL) return;
    FrequencyBucket *bucket = obj->first.next;
    while (bucket != &obj->last) {
        FrequencyBucket *nextBucket = bucket->next;
        LFUNode *node = bucket->newest;
        while (node != NULL) {
            LFUNode *nextNode = node->next;
            free(node);
            node = nextNode;
        }
        free(bucket);
        bucket = nextBucket;
    }
    free(obj->byKey);
    free(obj);
}
/* ---------- end submission ---------- */

int main(void) {
    LFUCache *cache = lFUCacheCreate(2);
    int passed = cache != NULL;
    if (cache != NULL) {
        lFUCachePut(cache, 1, 1);
        lFUCachePut(cache, 2, 2);
        passed = passed && lFUCacheGet(cache, 1) == 1;
        lFUCachePut(cache, 3, 3); /* 淘汰低頻的 2 */
        passed = passed && lFUCacheGet(cache, 2) == -1 &&
                 lFUCacheGet(cache, 3) == 3;
        lFUCachePut(cache, 4, 4); /* 1、3 同頻，淘汰較久沒用的 1 */
        passed = passed && lFUCacheGet(cache, 1) == -1 &&
                 lFUCacheGet(cache, 3) == 3 &&
                 lFUCacheGet(cache, 4) == 4;
        lFUCacheFree(cache);
    }
    puts(passed ? "PASS: 460 lfu-cache" : "FAIL: 460 lfu-cache");
    return passed ? 0 : 1;
}
