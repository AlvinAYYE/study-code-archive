# thrd_sleep

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int thrd_sleep( const struct timespec* duration,  struct timespec* remaining );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Blocks the execution of the current thread for *at least* until the TIME_UTC based duration pointed to by `duration` has elapsed.
阻塞目前執行緒的執行，至少持續到 duration 所指向的基於 TIME_UTC 的時長經過為止。
The sleep may resume earlier if a signal that is not ignored is received. In such case, if `remaining` is not NULL, the remaining time duration is stored into the object pointed to by `remaining`.
如果收到未被忽略的訊號，睡眠可能會提前結束。在這種情況下，如果 remaining 不是 NULL ，剩餘的時間長度會被存入 remaining 所指向的物件中。

### Parameters

| duration  |   | -  |   | pointer to the duration to sleep for  |

| remaining  |   | -  |   | pointer to the object to put the remaining time on interruption. May be NULL, in which case it is ignored  |

### Return value

`0` on successful sleep, `-1` if a signal occurred, other negative value if an error occurred.
睡眠成功傳回 0，如果發生訊號傳回 -1，如果發生錯誤傳回其他負值。

### Notes

`duration` and `remaining` may point at the same object, which simplifies re-running the function after a signal.
duration 和 remaining 可以指向同一個物件，這簡化了收到訊號後重新執行該函式的操作。
The actual sleep time may be longer than requested because it is rounded up to the timer granularity and because of scheduling and context switching overhead.
實際睡眠時間可能比請求的更長，因為它會被向上取整到計時器粒度，並且受排程和上下文切換開銷的影響。
The POSIX equivalent of this function is `nanosleep`.
此函式在 POSIX 中的等價物是 nanosleep 。

### Example

Run this code

```c
#include <threads.h> #include <time.h> #include <stdio.h> int main(void) {  printf("Time: %s", ctime(&(time_t){time(NULL)}));  thrd_sleep(&(struct timespec){.tv_sec=1}, NULL); // sleep 1 sec  printf("Time: %s", ctime(&(time_t){time(NULL)})); }
```

Output:

```c
Time: Mon Feb 2 16:18:41 2015 Time: Mon Feb 2 16:18:42 2015
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.5.7 The thrd_sleep function (p: 281)
7.26.5.7 thrd_sleep 函式（頁：281）
7.26.5.7 thrd_sleep 函式（頁：281）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.5.7 The thrd_sleep function (p: 385)
7.26.5.7 thrd_sleep 函式（頁：385）
7.26.5.7 thrd_sleep 函式（頁：385）

### See also

thrd_yield
(C11)
|   | yields the current time slice
(function)   |

C++ documentation for sleep_for

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_sleep.html`
