/*
 * Title-CN: 我的日曆 I
 * LeetCode 729. My Calendar I
 *
 * 題意翻譯：設計日曆並依序預約半開區間 [start,end)。若新預約與任何已接受的
 * 預約重疊就拒絕，否則接受並回傳 true。端點相接不算重疊。
 *
 * 範例：預約 [10,20) 成功；再預約 [15,25) 失敗；預約 [20,30) 成功。
 *
 * 限制：0 <= start < end <= 10^9；預約呼叫次數不超過 1000。
 *
 * 解題思路：把已接受的區間依 start 排序保存。新區間只需與插入位置前一個、
 * 後一個區間檢查是否重疊；若不重疊，就插入到有序陣列中。
 *
 * 複雜度：查找 O(log n)，搬移插入 O(n)，空間 O(n)。
 * LeetCode 介面：保留 MyCalendar 操作與 myCalendarFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    Interval *events;
    int count;
    int capacity;
} MyCalendar;

MyCalendar *myCalendarCreate(void) {
    return calloc(1, sizeof(MyCalendar));
}

bool myCalendarBook(MyCalendar *obj, int start, int end) {
    int low = 0;
    int high = obj->count;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (obj->events[middle].start < start) low = middle + 1;
        else high = middle;
    }
    int insertion = low;
    if (insertion > 0 && obj->events[insertion - 1].end > start) return false;
    if (insertion < obj->count && obj->events[insertion].start < end) return false;

    if (obj->count == obj->capacity) {
        int newCapacity = obj->capacity == 0 ? 8 : obj->capacity * 2;
        Interval *grown = realloc(obj->events, (size_t)newCapacity * sizeof(*obj->events));
        if (grown == NULL) return false;
        obj->events = grown;
        obj->capacity = newCapacity;
    }
    for (int i = obj->count; i > insertion; --i) obj->events[i] = obj->events[i - 1];
    obj->events[insertion] = (Interval){start, end};
    ++obj->count;
    return true;
}

void myCalendarFree(MyCalendar *obj) {
    if (obj == NULL) return;
    free(obj->events);
    free(obj);
}

int main(void) {
    MyCalendar *calendar = myCalendarCreate();
    assert(calendar != NULL);
    assert(myCalendarBook(calendar, 10, 20));
    assert(!myCalendarBook(calendar, 15, 25));
    assert(myCalendarBook(calendar, 20, 30));
    assert(myCalendarBook(calendar, 5, 10));
    myCalendarFree(calendar);
    return 0;
}
