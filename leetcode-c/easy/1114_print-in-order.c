/*
 * Title-CN: 依序列印
 * LeetCode 1114. Print in Order
 *
 * 題意完整翻譯：
 *   同一個 Foo 物件會交給三個不同執行緒：執行緒 A 呼叫 first()、B 呼叫 second()、C 呼叫
 *   third()。請設計同步機制，無論作業系統如何安排執行緒，都要保證 second() 在 first() 之後執行，third() 在
 *   second() 之後執行。每個方法中呼叫對應的 print 函式即可。
 *
 * 範例：
 *   1. 執行緒呼叫順序為 first、second、third，輸出 firstsecondthird。
 *   2. 執行緒呼叫順序為 first、third、second，輸出仍須是 firstsecondthird。
 *
 * 限制：
 *   - nums 是 [1,2,3] 的一種排列
 *
 * 解題步驟：
 *   1. 在 Foo 中用 atomic stage 記錄已完成的階段：0 表示尚未 first，1 表示 first 完成，2 表示 second 完成。
 *   2. first() 先輸出 first，再以 release 寫入 stage=1。
 *   3. second() 以 acquire 等待 stage 到 1，再輸出 second 並寫入 stage=2。
 *   4. third() 等待 stage 到 2 後才輸出 third。原子變數讓等待與狀態更新可安全地跨執行緒傳遞。
 *
 * 複雜度：
 *   時間：每個方法執行固定次數的輸出與原子讀寫；後序方法會等待前序完成。
 *   空間：O(1)，每個 Foo 只保存一個階段值。
 *
 * LeetCode C API：
 *   Foo* fooCreate(void); void first(Foo* obj); void second(Foo* obj); void
 *   third(Foo* obj); void fooFree(Foo* obj);
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
typedef volatile LONG FooStage;

static void stageInit(FooStage* stage) {
    *stage = 0;
}

static int stageLoad(FooStage* stage) {
    return (int)InterlockedCompareExchange(stage, 0, 0);
}

static void stageStore(FooStage* stage, int value) {
    InterlockedExchange(stage, (LONG)value);
}
#else
#include <stdatomic.h>
typedef atomic_int FooStage;

static void stageInit(FooStage* stage) {
    atomic_init(stage, 0);
}

static int stageLoad(FooStage* stage) {
    return atomic_load_explicit(stage, memory_order_acquire);
}

static void stageStore(FooStage* stage, int value) {
    atomic_store_explicit(stage, value, memory_order_release);
}
#endif

typedef struct {
    FooStage stage;
} Foo;

void printFirst(void);
void printSecond(void);
void printThird(void);

Foo* fooCreate(void) {
    Foo* obj = (Foo*)malloc(sizeof(Foo));
    if (obj != NULL) {
        stageInit(&obj->stage);
    }
    return obj;
}

void first(Foo* obj) {
    printFirst();
    stageStore(&obj->stage, 1);
}

void second(Foo* obj) {
    while (stageLoad(&obj->stage) < 1) {
        /* 等待 first() 完成。 */
    }
    printSecond();
    stageStore(&obj->stage, 2);
}

void third(Foo* obj) {
    while (stageLoad(&obj->stage) < 2) {
        /* 等待 second() 完成。 */
    }
    printThird();
}

void fooFree(Foo* obj) {
    free(obj);
}

#ifndef LEETCODE_SUBMISSION
static char output[32];
static int outputLength;

void printFirst(void) {
    outputLength += sprintf(output + outputLength, "first");
}
void printSecond(void) {
    outputLength += sprintf(output + outputLength, "second");
}
void printThird(void) {
    outputLength += sprintf(output + outputLength, "third");
}

int main(void) {
    Foo* foo = fooCreate();
    outputLength = 0;
    output[0] = '\0';

    // 本機依序呼叫驗證輸出；原子階段也能讓任意排程的執行緒等待正確順序。
    first(foo);
    second(foo);
    third(foo);

    assert(strcmp(output, "firstsecondthird") == 0);
    fooFree(foo);
    puts("PASS 1114 Foo");
    return 0;
}
#endif
