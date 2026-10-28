/*
 * LeetCode 381. Insert Delete GetRandom O(1) - Duplicates allowed
 * （插入、刪除與隨機取值 O(1)，允許重複）
 *
 * 題意（繁體中文）：
 *   設計一個集合，支援插入整數、移除一個指定整數，以及隨機回傳目前集合中
 *   的一個元素。集合允許重複值；insert 在該值原本不存在時回傳 true，否則
 *   回傳 false，但無論如何都要插入一份。remove 若找到一份就移除並回傳 true，
 *   否則回傳 false。getRandom 依集合中每一份元素等機率抽取，因此重複值會
 *   按出現次數提高被抽中的機率。三種操作都需平均 O(1)。
 *
 * 範例：
 *   插入 1、再插入 1、再插入 2，回傳 true、false、true；此時抽到 1 的機率
 *   是 2/3，抽到 2 的機率是 1/3。移除一份 1 後，1 和 2 各以 1/2 機率被抽到。
 *
 * 限制：整數值可涵蓋 32 位元有號範圍；insert、remove、getRandom 合計最多
 *   2*10^5 次；呼叫 getRandom 時集合保證非空。
 *
 * 解題步驟：
 *   1. 用緊密陣列保存每一份元素，隨機抽取時只需均勻選一個陣列索引。
 *   2. 用雜湊表記錄每個值在陣列中的一個位置，並用每個陣列位置的前後連結
 *      索引，串起相同值的所有出現位置。插入新值時把位置接到該值的串列前端。
 *   3. 刪除時先從該值串列移除一個位置，再把陣列最後一格搬到空位，並修正
 *      被搬元素在其值串列中的鄰居索引。陣列不需留下空洞，操作只改常數個位置。
 *
 * 複雜度：insert、remove、getRandom 平均 O(1)；額外空間 O(N)，N 為目前元素數。
 * LeetCode C API：randomizedCollectionCreate、randomizedCollectionInsert、
 *                  randomizedCollectionRemove、randomizedCollectionGetRandom、
 *                  randomizedCollectionFree
 */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int head;
    unsigned char state; /* 0=空格，1=使用中，2=刪除標記 */
} HashEntry;

typedef struct {
    int value;
    int previousSame;
    int nextSame;
} Occurrence;

typedef struct {
    Occurrence *items;
    int size;
    int capacity;
    HashEntry *table;
    int tableCapacity;
    int tableSize;
    int tableUsed;
} RandomizedCollection;

static unsigned int hashValue(int value) {
    uint32_t x = (uint32_t)value;
    x ^= x >> 16;
    x *= 0x7feb352du;
    x ^= x >> 15;
    x *= 0x846ca68bu;
    x ^= x >> 16;
    return x;
}

static int locateEntry(const RandomizedCollection *obj, int value) {
    unsigned int mask = (unsigned int)(obj->tableCapacity - 1);
    unsigned int slot = hashValue(value) & mask;
    while (obj->table[slot].state != 0) {
        if (obj->table[slot].state == 1 && obj->table[slot].key == value)
            return (int)slot;
        slot = (slot + 1u) & mask;
    }
    return -1;
}

static int insertionSlot(const RandomizedCollection *obj, int value) {
    unsigned int mask = (unsigned int)(obj->tableCapacity - 1);
    unsigned int slot = hashValue(value) & mask;
    int firstDeleted = -1;
    while (obj->table[slot].state != 0) {
        if (obj->table[slot].state == 2 && firstDeleted == -1)
            firstDeleted = (int)slot;
        else if (obj->table[slot].state == 1 && obj->table[slot].key == value)
            return (int)slot;
        slot = (slot + 1u) & mask;
    }
    return firstDeleted == -1 ? (int)slot : firstDeleted;
}

static bool rehash(RandomizedCollection *obj, int newCapacity) {
    HashEntry *newTable = (HashEntry *)calloc((size_t)newCapacity, sizeof *newTable);
    if (newTable == NULL) return false;
    HashEntry *oldTable = obj->table;
    int oldCapacity = obj->tableCapacity;
    obj->table = newTable;
    obj->tableCapacity = newCapacity;
    obj->tableSize = 0;
    obj->tableUsed = 0;
    for (int i = 0; i < oldCapacity; ++i) {
        if (oldTable[i].state != 1) continue;
        int slot = insertionSlot(obj, oldTable[i].key);
        obj->table[slot] = oldTable[i];
        ++obj->tableSize;
        ++obj->tableUsed;
    }
    free(oldTable);
    return true;
}

static bool ensureTableRoom(RandomizedCollection *obj) {
    if ((obj->tableUsed + 1) * 10 < obj->tableCapacity * 7) return true;
    if (obj->tableCapacity > 1073741823) return false;
    return rehash(obj, obj->tableCapacity * 2);
}

static bool ensureOccurrenceRoom(RandomizedCollection *obj) {
    if (obj->size < obj->capacity) return true;
    int newCapacity = obj->capacity == 0 ? 8 : obj->capacity * 2;
    Occurrence *grown = (Occurrence *)realloc(
        obj->items, (size_t)newCapacity * sizeof *obj->items);
    if (grown == NULL) return false;
    obj->items = grown;
    obj->capacity = newCapacity;
    return true;
}

RandomizedCollection *randomizedCollectionCreate(void) {
    RandomizedCollection *obj = (RandomizedCollection *)calloc(1, sizeof *obj);
    if (obj == NULL) return NULL;
    obj->tableCapacity = 16;
    obj->table = (HashEntry *)calloc((size_t)obj->tableCapacity, sizeof *obj->table);
    if (obj->table == NULL) {
        free(obj);
        return NULL;
    }
    return obj;
}

bool randomizedCollectionInsert(RandomizedCollection *obj, int value) {
    if (obj == NULL) return false;
    int entry = locateEntry(obj, value);
    bool wasAbsent = entry == -1;
    if (wasAbsent && !ensureTableRoom(obj)) return false;
    if (!ensureOccurrenceRoom(obj)) return false;

    int index = obj->size++;
    obj->items[index].value = value;
    if (wasAbsent) {
        entry = insertionSlot(obj, value);
        if (obj->table[entry].state == 0) ++obj->tableUsed;
        obj->table[entry].state = 1;
        obj->table[entry].key = value;
        obj->table[entry].head = -1;
        ++obj->tableSize;
    }
    int oldHead = obj->table[entry].head;
    obj->items[index].previousSame = -1;
    obj->items[index].nextSame = oldHead;
    if (oldHead != -1) obj->items[oldHead].previousSame = index;
    obj->table[entry].head = index;
    return wasAbsent;
}

bool randomizedCollectionRemove(RandomizedCollection *obj, int value) {
    if (obj == NULL) return false;
    int entry = locateEntry(obj, value);
    if (entry == -1) return false;

    int index = obj->table[entry].head;
    int previous = obj->items[index].previousSame;
    int next = obj->items[index].nextSame;
    if (previous != -1) obj->items[previous].nextSame = next;
    else obj->table[entry].head = next;
    if (next != -1) obj->items[next].previousSame = previous;

    int last = obj->size - 1;
    if (index != last) {
        int movedValue = obj->items[last].value;
        int movedEntry = locateEntry(obj, movedValue);
        int movedPrevious = obj->items[last].previousSame;
        int movedNext = obj->items[last].nextSame;
        if (movedPrevious != -1) obj->items[movedPrevious].nextSame = index;
        else obj->table[movedEntry].head = index;
        if (movedNext != -1) obj->items[movedNext].previousSame = index;
        obj->items[index] = obj->items[last];
    }
    --obj->size;

    if (obj->table[entry].head == -1) {
        obj->table[entry].state = 2;
        --obj->tableSize;
    }
    return true;
}

static uint64_t randomBelow(uint64_t bound) {
    uint64_t base = (uint64_t)RAND_MAX + 1u;
    for (;;) {
        uint64_t range = 1;
        uint64_t value = 0;
        do {
            value = value * base + (unsigned int)rand();
            range *= base;
        } while (range < bound);
        uint64_t usable = range - range % bound;
        if (value < usable) return value % bound;
    }
}

int randomizedCollectionGetRandom(RandomizedCollection *obj) {
    if (obj == NULL || obj->size == 0) return 0;
    return obj->items[randomBelow((uint64_t)obj->size)].value;
}

void randomizedCollectionFree(RandomizedCollection *obj) {
    if (obj == NULL) return;
    free(obj->items);
    free(obj->table);
    free(obj);
}

int main(void) {
    RandomizedCollection *obj = randomizedCollectionCreate();
    if (obj == NULL) return 1;
    int passed = randomizedCollectionInsert(obj, 1) &&
                 !randomizedCollectionInsert(obj, 1) &&
                 randomizedCollectionInsert(obj, 2);
    for (int i = 0; passed && i < 200; ++i) {
        int value = randomizedCollectionGetRandom(obj);
        if (value != 1 && value != 2) passed = 0;
    }
    passed = passed && randomizedCollectionRemove(obj, 1);
    for (int i = 0; passed && i < 100; ++i) {
        int value = randomizedCollectionGetRandom(obj);
        if (value != 1 && value != 2) passed = 0;
    }
    passed = passed && randomizedCollectionRemove(obj, 1) &&
             !randomizedCollectionRemove(obj, 1) &&
             randomizedCollectionGetRandom(obj) == 2;
    randomizedCollectionFree(obj);

    obj = randomizedCollectionCreate();
    if (obj == NULL) return 1;
    int firstInsert = randomizedCollectionInsert(obj, -7);
    int secondInsert = randomizedCollectionInsert(obj, -7);
    int thirdInsert = randomizedCollectionInsert(obj, -7);
    int remA = randomizedCollectionRemove(obj, -7);
    int remB = randomizedCollectionRemove(obj, -7);
    int randomVal = randomizedCollectionGetRandom(obj);
    int remC = randomizedCollectionRemove(obj, -7);
    int remD = randomizedCollectionRemove(obj, -7);
    passed = passed && firstInsert && !secondInsert && !thirdInsert && remA && remB &&
             randomVal == -7 && remC && !remD;
    randomizedCollectionFree(obj);

    puts(passed ? "PASS: 381 insert-delete-getrandom-o1-duplicates-allowed"
                : "FAIL: 381 insert-delete-getrandom-o1-duplicates-allowed");
    return passed ? 0 : 1;
}
