/*
 * LeetCode 432. All O`one Data Structure／全 O(1) 資料結構
 *
 * 題目（繁體中文）
 *   設計一個計數器資料結構，支援：inc(key) 將字串計數加一、dec(key) 減一，
 *   計數降到零時刪除該字串；getMaxKey() 與 getMinKey() 分別回傳目前計數
 *   最大、最小的任一字串。所有操作都要求平均 O(1)。
 *
 * 範例：依序對 "hello" 執行兩次 inc，再查最大、最小都得到 "hello"；
 *   對 "leet" 執行 inc 後，最大是 "hello"、最小是 "leet"。
 * 限制：key 長度 1..10，只含小寫英文字母；dec 呼叫時 key 一定存在；
 *   inc、dec、查詢合計最多 5×10^4 次。
 *
 * 解題步驟：
 *   1. 以計數值遞增排列一串桶，每個桶保存該計數下的所有 key。
 *   2. 用雜湊表從 key 直接找到其節點與所在桶。
 *   3. inc 或 dec 只會讓 key 移到相鄰計數桶；目標桶不存在時就在旁邊建立。
 *   4. 桶變空就刪除；鏈結串列頭尾的桶分別提供最小與最大 key。
 *   所有操作平均 O(1)，空間 O(K+B)，K 為不同 key 數、B 為非空計數桶數。
 *
 * LeetCode C API：allOneCreate、allOneInc、allOneDec、allOneGetMaxKey、
 * allOneGetMinKey、allOneFree。兩個查詢函式都回傳新配置的字串，呼叫端負責釋放。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ALLONE_HASH_SIZE 131071
#define ALLONE_KEY_LENGTH 10

typedef struct AllOneKey AllOneKey;
typedef struct AllOneBucket AllOneBucket;

struct AllOneKey {
    char text[ALLONE_KEY_LENGTH + 1];
    AllOneBucket *bucket;
    AllOneKey *previous;
    AllOneKey *next;
    AllOneKey *hashNext;
};

struct AllOneBucket {
    int count;
    AllOneBucket *previous;
    AllOneBucket *next;
    AllOneKey *keys;
};

typedef struct {
    AllOneBucket first;
    AllOneBucket last;
    AllOneKey **table;
} AllOne;

static size_t hashKey(const char *key) {
    uint32_t hash = 2166136261u;
    for (const unsigned char *p = (const unsigned char *)key; *p != '\0'; ++p) {
        hash ^= *p;
        hash *= 16777619u;
    }
    return (size_t)(hash % ALLONE_HASH_SIZE);
}

static AllOneKey *findKey(AllOne *obj, const char *key) {
    size_t slot = hashKey(key);
    for (AllOneKey *node = obj->table[slot]; node != NULL; node = node->hashNext) {
        if (strcmp(node->text, key) == 0) return node;
    }
    return NULL;
}

static AllOneBucket *newBucket(int count) {
    AllOneBucket *bucket = (AllOneBucket *)calloc(1, sizeof *bucket);
    if (bucket != NULL) bucket->count = count;
    return bucket;
}

static void insertBucketAfter(AllOneBucket *position, AllOneBucket *bucket) {
    bucket->previous = position;
    bucket->next = position->next;
    position->next->previous = bucket;
    position->next = bucket;
}

static void removeBucket(AllOneBucket *bucket) {
    bucket->previous->next = bucket->next;
    bucket->next->previous = bucket->previous;
    free(bucket);
}

static void insertKeyAtFront(AllOneBucket *bucket, AllOneKey *key) {
    key->bucket = bucket;
    key->previous = NULL;
    key->next = bucket->keys;
    if (bucket->keys != NULL) bucket->keys->previous = key;
    bucket->keys = key;
}

static void unlinkKey(AllOneKey *key) {
    AllOneBucket *bucket = key->bucket;
    if (key->previous != NULL) key->previous->next = key->next;
    else bucket->keys = key->next;
    if (key->next != NULL) key->next->previous = key->previous;
    key->previous = NULL;
    key->next = NULL;
}

static void removeFromHash(AllOne *obj, AllOneKey *key) {
    size_t slot = hashKey(key->text);
    AllOneKey **link = &obj->table[slot];
    while (*link != NULL && *link != key) link = &(*link)->hashNext;
    if (*link == key) *link = key->hashNext;
}

static AllOneBucket *bucketAfterOrCreate(AllOneBucket *current, int count) {
    AllOneBucket *target = current->next;
    if (target->count == count) return target;
    target = newBucket(count);
    if (target != NULL) insertBucketAfter(current, target);
    return target;
}

/* ---------- LeetCode submission / 提交區 ---------- */
AllOne *allOneCreate(void) {
    AllOne *obj = (AllOne *)calloc(1, sizeof *obj);
    if (obj == NULL) return NULL;
    obj->table = (AllOneKey **)calloc(ALLONE_HASH_SIZE, sizeof *obj->table);
    if (obj->table == NULL) {
        free(obj);
        return NULL;
    }
    obj->first.next = &obj->last;
    obj->last.previous = &obj->first;
    return obj;
}

void allOneInc(AllOne *obj, char *key) {
    if (obj == NULL || key == NULL) return;
    AllOneKey *node = findKey(obj, key);
    if (node == NULL) {
        AllOneBucket *bucket = obj->first.next;
        int createdBucket = 0;
        if (bucket == &obj->last || bucket->count != 1) {
            bucket = newBucket(1);
            if (bucket == NULL) return;
            insertBucketAfter(&obj->first, bucket);
            createdBucket = 1;
        }
        node = (AllOneKey *)calloc(1, sizeof *node);
        if (node == NULL) {
            if (createdBucket) removeBucket(bucket);
            return;
        }
        strcpy(node->text, key);
        size_t slot = hashKey(key);
        node->hashNext = obj->table[slot];
        obj->table[slot] = node;
        insertKeyAtFront(bucket, node);
        return;
    }

    AllOneBucket *oldBucket = node->bucket;
    AllOneBucket *newBucket = bucketAfterOrCreate(oldBucket, oldBucket->count + 1);
    if (newBucket == NULL) return;
    unlinkKey(node);
    insertKeyAtFront(newBucket, node);
    if (oldBucket->keys == NULL) removeBucket(oldBucket);
}

void allOneDec(AllOne *obj, char *key) {
    if (obj == NULL || key == NULL) return;
    AllOneKey *node = findKey(obj, key);
    if (node == NULL) return; /* 題目保證存在；此檢查也讓本地 API 更安全。 */
    AllOneBucket *oldBucket = node->bucket;

    if (oldBucket->count == 1) {
        unlinkKey(node);
        removeFromHash(obj, node);
        free(node);
        if (oldBucket->keys == NULL) removeBucket(oldBucket);
        return;
    }

    AllOneBucket *target = oldBucket->previous;
    if (target == &obj->first || target->count != oldBucket->count - 1) {
        target = newBucket(oldBucket->count - 1);
        if (target == NULL) return;
        insertBucketAfter(oldBucket->previous, target);
    }
    unlinkKey(node);
    insertKeyAtFront(target, node);
    if (oldBucket->keys == NULL) removeBucket(oldBucket);
}

static char *copyReturnedKey(const char *key) {
    size_t length = strlen(key) + 1;
    char *copy = (char *)malloc(length);
    if (copy != NULL) memcpy(copy, key, length);
    return copy;
}

char *allOneGetMaxKey(AllOne *obj) {
    if (obj == NULL || obj->last.previous == &obj->first)
        return copyReturnedKey("");
    return copyReturnedKey(obj->last.previous->keys->text);
}

char *allOneGetMinKey(AllOne *obj) {
    if (obj == NULL || obj->first.next == &obj->last)
        return copyReturnedKey("");
    return copyReturnedKey(obj->first.next->keys->text);
}

void allOneFree(AllOne *obj) {
    if (obj == NULL) return;
    AllOneBucket *bucket = obj->first.next;
    while (bucket != &obj->last) {
        AllOneBucket *nextBucket = bucket->next;
        AllOneKey *key = bucket->keys;
        while (key != NULL) {
            AllOneKey *nextKey = key->next;
            free(key);
            key = nextKey;
        }
        free(bucket);
        bucket = nextBucket;
    }
    free(obj->table);
    free(obj);
}
/* ---------- end submission ---------- */

static int returnedKeyEquals(char *actual, const char *expected) {
    int equal = actual != NULL && strcmp(actual, expected) == 0;
    free(actual);
    return equal;
}

int main(void) {
    AllOne *allOne = allOneCreate();
    int passed = allOne != NULL;
    if (allOne != NULL) {
        char hello[] = "hello", leet[] = "leet";
        allOneInc(allOne, hello);
        allOneInc(allOne, hello);
        passed = passed && returnedKeyEquals(allOneGetMaxKey(allOne), "hello") &&
                 returnedKeyEquals(allOneGetMinKey(allOne), "hello");
        allOneInc(allOne, leet);
        passed = passed && returnedKeyEquals(allOneGetMaxKey(allOne), "hello") &&
                 returnedKeyEquals(allOneGetMinKey(allOne), "leet");
        allOneInc(allOne, leet);
        allOneDec(allOne, hello);
        passed = passed && returnedKeyEquals(allOneGetMaxKey(allOne), "leet") &&
                 returnedKeyEquals(allOneGetMinKey(allOne), "hello");
        allOneDec(allOne, hello);
        passed = passed && returnedKeyEquals(allOneGetMaxKey(allOne), "leet") &&
                 returnedKeyEquals(allOneGetMinKey(allOne), "leet");
        allOneFree(allOne);
    }
    puts(passed ? "PASS: 432 all-oone-data-structure"
                : "FAIL: 432 all-oone-data-structure");
    return passed ? 0 : 1;
}
