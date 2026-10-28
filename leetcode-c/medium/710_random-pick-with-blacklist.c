/*
 * LeetCode 710. Random Pick with Blacklist（黑名單中的隨機數）
 *
 * 題意（繁體中文）：
 *   設計一個資料結構，從 [0,n-1] 中等機率挑選一個不在 blacklist 的整數。
 *   黑名單元素不重複，而且每次呼叫都要讓所有合法數字有相同機率被選中。
 *   請實作建立物件、隨機挑選與釋放物件的函式。
 *
 * 範例：
 *   n=7、blacklist=[2,3,5] 時，合法答案為 0、1、4、6，每個都應有 1/4 機率。
 *   任何一次 pick 都可回傳這四個數字中的任一個。
 *
 * 限制：1 <= n <= 10^9；黑名單長度 0..min(10^5,n-1)；最多呼叫 pick 2*10^4 次。
 *
 * 解題步驟：
 *   1. 合法數字總數為 bound=n-blacklistSize。先只在較小範圍 [0,bound) 等機率
 *      抽一個索引，這樣每次只需產生一個隨機索引，而不是重抽直到避開黑名單。
 *   2. 對落在 [0,bound) 的黑名單數字，預先配對到 [bound,n) 中未被封鎖的數字。
 *      高區間恰好能提供足夠的替代值。使用雜湊表存這些對應。
 *   3. 抽到低區間的黑名單值時回傳它的替代值；否則原樣回傳。因為每個合法
 *      數字對應到一個且僅一個低區間索引，所以分布均勻。隨機整數用拒絕取樣，
 *      避免直接取餘數造成偏差。
 *
 * 複雜度：建立時間 O(B) 平均、空間 O(B)；每次 pick 平均 O(1)，B 為黑名單長度。
 * LeetCode C API：Solution* solutionCreate(...), int solutionPick(...),
 *                  void solutionFree(...)
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int bound;
    int capacity;
    int *keys;
    int *values;
} Solution;

static unsigned int hashKey(int key) {
    return (unsigned int)key * 2654435761u;
}

static int findSlot(const Solution *obj, int key) {
    unsigned int mask = (unsigned int)(obj->capacity - 1);
    unsigned int slot = hashKey(key) & mask;
    while (obj->keys[slot] != -1 && obj->keys[slot] != key)
        slot = (slot + 1u) & mask;
    return (int)slot;
}

static int isBlacklisted(const Solution *obj, int value) {
    int slot = findSlot(obj, value);
    return obj->keys[slot] == value;
}

static uint64_t randomBelow(uint64_t bound) {
    uint64_t base = (uint64_t)RAND_MAX + 1u;
    for (;;) {
        uint64_t range = 1;
        uint64_t value = 0;
        /* 只取足以覆蓋 bound 的最少 rand() 數量。 */
        do {
            value = value * base + (unsigned int)rand();
            range *= base;
        } while (range < bound);

        uint64_t usable = range - range % bound;
        if (value < usable) return value % bound;
        /* 少數超出等長區間的結果丟棄，重新抽樣以避免取餘數偏差。 */
    }
}

Solution *solutionCreate(int n, int *blacklist, int blacklistSize) {
    Solution *obj = (Solution *)malloc(sizeof *obj);
    if (obj == NULL) return NULL;
    obj->bound = n - blacklistSize;
    obj->capacity = 1;
    while (obj->capacity < blacklistSize * 2 + 1) obj->capacity *= 2;
    obj->keys = (int *)malloc((size_t)obj->capacity * sizeof *obj->keys);
    obj->values = (int *)malloc((size_t)obj->capacity * sizeof *obj->values);
    if (obj->keys == NULL || obj->values == NULL) {
        free(obj->keys);
        free(obj->values);
        free(obj);
        return NULL;
    }
    for (int i = 0; i < obj->capacity; ++i) {
        obj->keys[i] = -1;
        obj->values[i] = -1;
    }

    for (int i = 0; i < blacklistSize; ++i) {
        int slot = findSlot(obj, blacklist[i]);
        obj->keys[slot] = blacklist[i];
    }

    int candidate = n - 1;
    for (int i = 0; i < blacklistSize; ++i) {
        int blocked = blacklist[i];
        if (blocked >= obj->bound) continue;
        while (isBlacklisted(obj, candidate)) --candidate;
        int slot = findSlot(obj, blocked);
        obj->values[slot] = candidate;
        --candidate;
    }
    return obj;
}

int solutionPick(Solution *obj) {
    if (obj == NULL) return -1;
    int value = (int)randomBelow((uint64_t)obj->bound);
    int slot = findSlot(obj, value);
    if (obj->keys[slot] == value) return obj->values[slot];
    return value;
}

void solutionFree(Solution *obj) {
    if (obj == NULL) return;
    free(obj->keys);
    free(obj->values);
    free(obj);
}

int main(void) {
    int blacklist[] = {2, 3, 5};
    int allowed[] = {1, 1, 0, 0, 1, 0, 1};
    Solution *obj = solutionCreate(7, blacklist, 3);
    int passed = obj != NULL;
    for (int i = 0; passed && i < 1000; ++i) {
        int value = solutionPick(obj);
        if (value < 0 || value >= 7 || !allowed[value]) passed = 0;
    }
    solutionFree(obj);

    Solution *noBlacklist = solutionCreate(4, NULL, 0);
    passed = passed && noBlacklist != NULL;
    for (int i = 0; passed && i < 100; ++i) {
        int value = solutionPick(noBlacklist);
        if (value < 0 || value >= 4) passed = 0;
    }
    solutionFree(noBlacklist);
    puts(passed ? "PASS: 710 random-pick-with-blacklist"
                : "FAIL: 710 random-pick-with-blacklist");
    return passed ? 0 : 1;
}
