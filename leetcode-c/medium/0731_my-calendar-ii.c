/*
 * Title-CN: 我的日曆 II
 * LeetCode 731. My Calendar II
 *
 * 題意翻譯：設計日曆，允許同一時間最多有兩個活動。每次新增半開區間 [start,end)，
 * 若加入後會有三個活動同時進行，就拒絕並回傳 false；否則接受並回傳 true。
 *
 * 範例：[10,20)、[50,60)、[10,40) 都可接受；[5,15) 也可接受，因為與既有活動
 * 最多重疊兩層；若新增 [5,10) 則不會與 [10,20) 重疊，端點相接可接受。
 *
 * 限制：0 <= start < end <= 10^9；預約呼叫次數不超過 1000。
 *
 * 解題思路：保存所有已接受活動，也保存任兩個活動重疊的區間。新活動若與任何
 * 已存在的重疊區間相交，就會造成三重預約，直接拒絕。否則，將它與每個活動的
 * 交集加入重疊區間清單，再把活動本身加入清單。
 *
 * 複雜度：每次預約 O(n^2)（掃描活動與重疊區間）；空間 O(n^2)，n <= 1000。
 * LeetCode 介面：保留 MyCalendarTwo 操作與 myCalendarTwoFree；main() 僅供本機測試。
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    Interval *booked;
    int bookedCount;
    int bookedCapacity;
    Interval *overlaps;
    int overlapCount;
    int overlapCapacity;
} MyCalendarTwo;

MyCalendarTwo *myCalendarTwoCreate(void) {
    return calloc(1, sizeof(MyCalendarTwo));
}

static bool appendInterval(Interval **items, int *count, int *capacity,
                           int start, int end) {
    if (*count == *capacity) {
        int newCapacity = *capacity == 0 ? 8 : *capacity * 2;
        Interval *grown = realloc(*items, (size_t)newCapacity * sizeof(**items));
        if (grown == NULL) return false;
        *items = grown;
        *capacity = newCapacity;
    }
    (*items)[(*count)++] = (Interval){start, end};
    return true;
}

bool myCalendarTwoBook(MyCalendarTwo *obj, int start, int end) {
    for (int i = 0; i < obj->overlapCount; ++i) {
        if (start < obj->overlaps[i].end && obj->overlaps[i].start < end) return false;
    }

    for (int i = 0; i < obj->bookedCount; ++i) {
        int overlapStart = start > obj->booked[i].start ? start : obj->booked[i].start;
        int overlapEnd = end < obj->booked[i].end ? end : obj->booked[i].end;
        if (overlapStart < overlapEnd
            && !appendInterval(&obj->overlaps, &obj->overlapCount,
                               &obj->overlapCapacity, overlapStart, overlapEnd)) {
            return false;
        }
    }
    return appendInterval(&obj->booked, &obj->bookedCount,
                          &obj->bookedCapacity, start, end);
}

void myCalendarTwoFree(MyCalendarTwo *obj) {
    if (obj == NULL) return;
    free(obj->booked);
    free(obj->overlaps);
    free(obj);
}

int main(void) {
    MyCalendarTwo *calendar = myCalendarTwoCreate();
    assert(calendar != NULL);
    assert(myCalendarTwoBook(calendar, 10, 20));
    assert(myCalendarTwoBook(calendar, 50, 60));
    assert(myCalendarTwoBook(calendar, 10, 40));
    assert(!myCalendarTwoBook(calendar, 5, 15));
    assert(myCalendarTwoBook(calendar, 5, 10));
    assert(myCalendarTwoBook(calendar, 25, 55));
    myCalendarTwoFree(calendar);
    return 0;
}
