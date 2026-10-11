# timespec_get

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
int timespec_get( struct timespec *ts, int base );
```
|   |  (1)  |   |  (since C11)  |

```c
#define TIME_UTC /* implementation-defined */
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Modifies the timespec object pointed to by `ts` to hold the current calendar time in the time base `base`.

2) Expands to a value suitable for use as the `base` argument of `timespec_get`

Other macro constants beginning with `TIME_` may be provided by the implementation to indicate additional time bases
實現可以提供其他以 TIME_ 開頭的宏常量來表示附加的時間基
If `base` is `TIME_UTC`, then
如果 base 是 TIME_UTC ，則

- `ts->tv_sec` is set to the number of seconds since an implementation defined epoch, truncated to a whole value
ts -> tv_sec 被設定為自實現定義的紀元以來的秒數，截斷為整數值

- `ts->tv_nsec` member is set to the integral number of nanoseconds, rounded to the resolution of the system clock
ts -> tv_nsec 成員被設定為納秒的整數值，舍入到系統時鐘的解析度

### Parameters

| ts  |   | -  |   | pointer to an object of type `struct timespec`  |

| base  |   | -  |   | `TIME_UTC` or another nonzero integer value indicating the time base  |

### Return value

The value of `base` if successful, zero otherwise.
成功時傳回 base 的值，否則傳回零。

### Notes

The POSIX function `clock_gettime(CLOCK_REALTIME, ts)` may also be used to populate a `timespec` with the time since the Epoch.
POSIX 函式 clock_gettime(CLOCK_REALTIME, ts) 也可用於用自紀元以來的時間填充 timespec。

### Example

Run this code

```c
#include <stdio.h> #include <time.h> int main(void) {  struct timespec ts;  timespec_get(&ts, TIME_UTC);  char buff[100];  strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));  printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec); }
```

Possible output:
可能的輸出：

```c
Current time: 02/18/15 14:34:03.048508855 UTC
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.27.2.5 The timespec_get function (p: TBD)
7.27.2.5 timespec_get 函式（頁碼：待定）
7.27.2.5 timespec_get 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.2.5 The timespec_get function (p: 286)
7.27.2.5 timespec_get 函式（頁碼：286）
7.27.2.5 timespec_get 函式（頁碼：286）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.2.5 The timespec_get function (p: 390)
7.27.2.5 timespec_get 函式（頁碼：390）
7.27.2.5 timespec_get 函式（頁碼：390）

### See also

timespec
(C11)
|   | time in seconds and nanoseconds
(struct)  |

timespec_getres
(C23)
|   | returns the resolution of calendar time based on a given time base
(function)   |

time
|   | returns the current calendar time of the system as time since epoch
(function)   |

C++ documentation for timespec_get

---
來源頁路徑：`en.cppreference.com/c/chrono/timespec_get.html`
