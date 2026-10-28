/*
 * LeetCode 732. My Calendar III（我的日曆 III）
 *
 * 題意（繁體中文）：
 *   每個活動占用半開時間區間 [startTime,endTime)。若 k 個活動有共同的非空
 *   時段，就稱為 k 重預約。設計日曆的 book 操作，每加入一個活動後，回傳目前
 *   所有活動中的最大重疊數。
 *
 * 範例：
 *   依序預約 [10,20)、[50,60)、[10,40)、[5,15)、[5,10)、[25,55)，
 *   每次回傳 1、1、2、3、3、3。
 *   例如 [5,10) 和 [10,20) 只在端點相接，不算同一時間重疊。
 *
 * 限制：0 <= startTime < endTime <= 10^9；最多呼叫 book 400 次。
 *
 * 解題步驟：
 *   1. 對每個預約的開始時間記錄 +1、結束時間記錄 -1；相同時間的變化合併。
 *   2. 每次新增預約後，依時間順序累加變化量。累計值代表該時段同時進行的
 *      活動數，過程中的最大值就是目前最大重疊數。
 *   3. 最多只有 800 個不同端點，使用排序陣列插入及掃描即可；不需要更複雜
 *      的平衡樹。
 *
 * 複雜度：每次 book 最多 O(Q)，累計 Q 次預約總時間 O(Q^2)，額外空間 O(Q)。
 * LeetCode C API：myCalendarThreeCreate、myCalendarThreeBook、
 *                  myCalendarThreeFree
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int times[800];
    int changes[800];
    int size;
} MyCalendarThree;

static void addTimeChange(MyCalendarThree *calendar, int time, int delta) {
    int low = 0, high = calendar->size;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (calendar->times[middle] < time) low = middle + 1;
        else high = middle;
    }
    if (low < calendar->size && calendar->times[low] == time) {
        calendar->changes[low] += delta;
        return;
    }
    for (int i = calendar->size; i > low; --i) {
        calendar->times[i] = calendar->times[i - 1];
        calendar->changes[i] = calendar->changes[i - 1];
    }
    calendar->times[low] = time;
    calendar->changes[low] = delta;
    ++calendar->size;
}

MyCalendarThree *myCalendarThreeCreate(void) {
    MyCalendarThree *calendar = (MyCalendarThree *)calloc(1, sizeof *calendar);
    return calendar;
}

int myCalendarThreeBook(MyCalendarThree *obj, int startTime, int endTime) {
    if (obj == NULL) return 0;
    addTimeChange(obj, startTime, 1);
    addTimeChange(obj, endTime, -1);

    int active = 0;
    int maximum = 0;
    for (int i = 0; i < obj->size; ++i) {
        active += obj->changes[i];
        if (active > maximum) maximum = active;
    }
    return maximum;
}

void myCalendarThreeFree(MyCalendarThree *obj) {
    free(obj);
}

int main(void) {
    MyCalendarThree *calendar = myCalendarThreeCreate();
    if (calendar == NULL) return 1;
    int expected[] = {1, 1, 2, 3, 3, 3};
    int starts[] = {10, 50, 10, 5, 5, 25};
    int ends[] = {20, 60, 40, 15, 10, 55};
    int passed = 1;
    for (int i = 0; i < 6; ++i)
        if (myCalendarThreeBook(calendar, starts[i], ends[i]) != expected[i])
            passed = 0;
    myCalendarThreeFree(calendar);

    calendar = myCalendarThreeCreate();
    if (calendar == NULL) return 1;
    passed = passed && myCalendarThreeBook(calendar, 5, 10) == 1 &&
             myCalendarThreeBook(calendar, 10, 20) == 1 &&
             myCalendarThreeBook(calendar, 9, 11) == 2;
    myCalendarThreeFree(calendar);
    puts(passed ? "PASS: 732 my-calendar-iii" : "FAIL: 732 my-calendar-iii");
    return passed ? 0 : 1;
}
