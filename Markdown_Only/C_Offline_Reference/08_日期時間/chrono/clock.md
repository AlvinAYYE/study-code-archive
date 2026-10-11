# clock

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
clock_t clock(void);
```
|   |   |   |   |

|  |  |  |  |

Returns the approximate processor time used by the process since the beginning of an implementation-defined era related to the program's execution. To convert result value to seconds, divide it by CLOCKS_PER_SEC.
傳回程式自與程式執行相關的實現定義紀元以來使用的近似處理器時間。要將結果值轉換為秒，請將其除以 CLOCKS_PER_SEC 。
Only the difference between two values returned by different calls to `clock` is meaningful, as the beginning of the `clock` era does not have to coincide with the start of the program.
只有不同 clock 呼叫傳回的兩個值之間的差值才有意義，因為時鐘紀元的起點不必與程式的開始相重合。
`clock` time may advance faster or slower than the wall clock, depending on the execution resources given to the program by the operating system. For example, if the CPU is shared by other processes, `clock` time may advance slower than wall clock. On the other hand, if the current process is multithreaded and more than one execution core is available, `clock` time may advance faster than wall clock.
clock 時間可能比牆上時鐘走得快或慢，取決於作業系統分配給程式的執行資源。例如，如果 CPU 被其他程式共享，clock 時間可能比牆上時鐘慢。另一方面，如果目前程式是多執行緒的且有多個執行核心可用，clock 時間可能比牆上時鐘快。

### Return value

Processor time used by the program so far.
程式到目前為止使用的處理器時間。

- If the processor time used is not available, returns `(clock_t)(-1)`.
如果無法獲得已使用的處理器時間，則傳回 ( clock_t )( -1 ) 。

- If the value of the processor time used cannot be represented by clock_t, returns an unspecified value.
如果已使用的處理器時間值無法用 clock_t 表示，則傳回未指定的值。

### Notes

On POSIX-compatible systems, `clock_gettime` with clock id `CLOCK_PROCESS_CPUTIME_ID` offers better resolution.
在相容 POSIX 的系統上，使用時鐘 ID CLOCK_PROCESS_CPUTIME_ID 的 clock_gettime 提供更好的解析度。
The value returned by `clock()` may wrap around on some implementations. For example, on such an implementation, if clock_t is a signed 32-bit integer and CLOCKS_PER_SEC is `1000000`, it will wrap after about 2147 seconds (about 36 minutes).
在某些實現中，clock() 傳回的值可能會迴繞。例如，在這樣的實現中，如果 clock_t 是有符號 32 位整數且 CLOCKS_PER_SEC 為 1000000 ，則約 2147 秒（約 36 分鐘）後會迴繞。

### Example

This example demonstrates the difference between `clock()` time and real time.
本示例演示 clock() 時間與實際時間之間的差異。
Run this code

```c
#ifndef __STDC_NO_THREADS__  #include <threads.h> #else  // POSIX alternative  #define _POSIX_C_SOURCE 199309L  #include <pthread.h> #endif #include <stdio.h> #include <stdlib.h> #include <time.h> // the function f() does some time-consuming work int f(void* thr_data) // return void* in POSIX {  (void) thr_data;  volatile double d = 0;  for (int n = 0; n < 10000; ++n)  for (int m = 0; m < 10000; ++m)  d += d * n * m;  return 0; } int main(void) {  struct timespec ts1, tw1; // both C11 and POSIX  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1); // POSIX  clock_gettime(CLOCK_MONOTONIC, &tw1); // POSIX; use timespec_get in C11  clock_t t1 = clock();   #ifndef __STDC_NO_THREADS__  thrd_t thr1, thr2; // C11; use pthread_t in POSIX  thrd_create(&thr1, f, NULL); // C11; use pthread_create in POSIX  thrd_create(&thr2, f, NULL);  thrd_join(thr1, NULL); // C11; use pthread_join in POSIX  thrd_join(thr2, NULL); #endif    struct timespec ts2, tw2;  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2);  clock_gettime(CLOCK_MONOTONIC, &tw2);  clock_t t2 = clock();    double dur = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;  double posix_dur = 1000.0 * ts2.tv_sec + 1e-6 * ts2.tv_nsec  - (1000.0 * ts1.tv_sec + 1e-6 * ts1.tv_nsec);  double posix_wall = 1000.0 * tw2.tv_sec + 1e-6 * tw2.tv_nsec  - (1000.0 * tw1.tv_sec + 1e-6 * tw1.tv_nsec);    printf("CPU time used (per clock()): %.2f ms\n", dur);  printf("CPU time used (per clock_gettime()): %.2f ms\n", posix_dur);  printf("Wall time passed: %.2f ms\n", posix_wall); }
```

Possible output:
可能的輸出：

```c
CPU time used (per clock()): 1580.00 ms CPU time used (per clock_gettime()): 1582.76 ms Wall time passed: 792.13 ms
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.2.1 The clock function (p: 285)
7.27.2.1 clock 函式（頁碼：285）
7.27.2.1 clock 函式（頁碼：285）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.2.1 The clock function (p: 389)
7.27.2.1 clock 函式（頁碼：389）
7.27.2.1 clock 函式（頁碼：389）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.2.1 The clock function (p: 339)
7.23.2.1 clock 函式（頁碼：339）
7.23.2.1 clock 函式（頁碼：339）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.2.1 The clock function
4.12.2.1 clock 函式
4.12.2.1 clock 函式

### See also

ctimectime_s
(deprecated in C23)(C11)
|   | converts a time_t object to a textual representation
(function)   |

time
|   | returns the current calendar time of the system as time since epoch
(function)   |

C++ documentation for clock

---
來源頁路徑：`en.cppreference.com/c/chrono/clock.html`
