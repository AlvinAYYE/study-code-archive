# thrd_yield

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
void thrd_yield(void);
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Provides a hint to the implementation to reschedule the execution of threads, allowing other threads to run.
向實現提供提示，使其重新排程執行緒的執行，讓其他執行緒得以執行。

### Parameters

(none)

### Return value

(none)

### Notes

The exact behavior of this function depends on the implementation, in particular on the mechanics of the OS scheduler in use and the state of the system. For example, a first-in-first-out realtime scheduler (`SCHED_FIFO` in Linux) would suspend the current thread and put it on the back of the queue of the same-priority threads that are ready to run, and if there are no other threads at the same priority, `yield` has no effect.
此函式的確切行為取決於實現，特別是取決於所使用的作業系統排程器的機制和系統狀態。例如，先進先出的實時排程器（Linux 中的 SCHED_FIFO ）會掛起目前執行緒，並把它放到已就緒的同優先順序執行緒佇列的末尾；如果沒有其他同優先順序的執行緒，yield 沒有任何效果。
The POSIX equivalent of this function is `sched_yield`.
此函式在 POSIX 中的等價物是 sched_yield 。

### Example

Run this code

```c
#include <stdio.h> #include <time.h> #include <threads.h> // utility function: difference between timespecs in microseconds double usdiff(struct timespec s, struct timespec e) {  double sdiff = difftime(e.tv_sec, s.tv_sec);  long nsdiff = e.tv_nsec - s.tv_nsec;  if(nsdiff < 0) return 1000000*(sdiff-1) + (1000000000L+nsdiff)/1000.0;  else return 1000000*(sdiff) + nsdiff/1000.0; } // busy wait while yielding void sleep_100us() {  struct timespec start, end;  timespec_get(&start, TIME_UTC);  do {  thrd_yield();  timespec_get(&end, TIME_UTC);  } while(usdiff(start, end) < 100.0); } int main() {  struct timespec start, end;  timespec_get(&start, TIME_UTC);  sleep_100us();  timespec_get(&end, TIME_UTC);  printf("Waited for %.3f us\n", usdiff(start, end)); }
```

Possible output:
可能的輸出：

```c
Waited for 100.344 us
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.5.8 The thrd_yield function (p: 281)
7.26.5.8 thrd_yield 函式（頁：281）
7.26.5.8 thrd_yield 函式（頁：281）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.5.8 The thrd_yield function (p: 385)
7.26.5.8 thrd_yield 函式（頁：385）
7.26.5.8 thrd_yield 函式（頁：385）

### See also

thrd_sleep
(C11)
|   | suspends execution of the calling thread for the given period of time
(function)   |

C++ documentation for yield

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_yield.html`
