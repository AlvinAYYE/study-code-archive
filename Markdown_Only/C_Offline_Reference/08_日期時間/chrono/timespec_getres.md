# timespec_getres

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
int timespec_getres( struct timespec* ts, int base );
```
|   |   |   |  (since C23)  |

|  |  |  |  |

If `ts` is non-null and `base` is supported by timespec_get, modifies `*ts` to hold the resolution of time provided by timespec_get for `base`. For each supported `base`, multiple calls to `timespec_getres` during the same program execution have identical results.
如果 ts 非空且 timespec_get 支援 base，則修改 *ts 以儲存 timespec_get 為 base 提供的時間解析度。對於每個受支援的 base，在同一程式執行期間多次呼叫 timespec_getres 的結果相同。

### Parameters

| ts  |   | -  |   | pointer to an object of type `struct timespec`  |

| base  |   | -  |   | TIME_UTC or another nonzero integer value indicating the time base  |

### Return value

The value of `base` if `base` is supported, zero otherwise.
如果 base 受支援則傳回 base 的值，否則傳回零。

### Notes

The POSIX function `clock_getres(clock_id, ts)` may also be used to populate a timespec with the resolution of time identified by `clock_id`.
POSIX 函式 clock_getres(clock_id, ts) 也可用於用 clock_id 標識的時間解析度填充 timespec。

### Example

Run this code

```c
#include <stdio.h> #include <time.h> int main(void) {  char buff[128];  struct timespec ts;  const int res = timespec_getres(&ts, TIME_UTC);  if (res == TIME_UTC)  {  struct tm timer;  strftime(buff, sizeof buff, "%D %T", gmtime_r(&ts.tv_sec, &timer));  printf("Time resolution info: %s.%09ld UTC\n", buff, ts.tv_nsec);  }  else  printf("TIME_UTC base is not supported."); }
```

Possible output:
可能的輸出：

```c
Time resolution info: 01/01/70 00:00:00.000000001 UTC
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.29.2.7 The timespec_getres function (p: 404)
7.29.2.7 timespec_getres 函式（頁碼：404）
7.29.2.7 timespec_getres 函式（頁碼：404）

### See also

timespec
(C11)
|   | time in seconds and nanoseconds
(struct)  |

timespec_get
(C11)
|   | returns the calendar time in seconds and nanoseconds based on a given time base
(function)   |

time
|   | returns the current calendar time of the system as time since epoch
(function)   |

C++ documentation for timespec_getres

---
來源頁路徑：`en.cppreference.com/c/chrono/timespec_getres.html`
