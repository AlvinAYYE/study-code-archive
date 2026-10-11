# time

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
time_t time( time_t* arg );
```
|   |   |   |   |

|  |  |  |  |

Returns the current calendar time encoded as a time_t object, and also stores it in the time_t object pointed to by `arg` (unless `arg` is a null pointer)
傳回編碼為 time_t 物件的目前日曆時間，並將其同時儲存到 arg 所指向的 time_t 物件中（除非 arg 是空指標）

### Parameters

| arg  |   | -  |   | pointer to a time_t object where the time will be stored, or a null pointer  |

### Return value

Current calendar time encoded as time_t object on success, `(time_t)(-1)` on error. If `arg` is not a null pointer, the return value is also stored in the object pointed to by `arg`.
成功時傳回編碼為 time_t 物件的目前日曆時間，出錯時傳回 ( time_t )( -1 )。如果 arg 不是空指標，傳回值也會儲存到 arg 所指向的物件中。

### Notes

The encoding of calendar time in time_t is unspecified, but most systems conform to POSIX specification and return a value of integral type holding the number of seconds since the Epoch. Implementations in which time_t is a 32-bit signed integer (many historical implementations) fail in the year 2038.
time_t 中日曆時間的編碼未指定，但大多數系統符合 POSIX 規範，傳回包含自紀元以來秒數的整數型別值。在 time_t 為 32 位有符號整數的實現中（許多歷史實現）會在 2038 年失效。

### Example

Run this code

```c
#include <stdint.h> #include <stdio.h> #include <time.h> int main(void) {  time_t result = time(NULL);  if (result != (time_t)(-1))  printf("The current time is %s(%jd seconds since the Epoch)\n",  asctime(gmtime(&result)), (intmax_t)result); }
```

Possible output:
可能的輸出：

```c
The current time is Fri Apr 24 15:05:25 2015 (1429887925 seconds since the Epoch)
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.27.2.4 The time function (p: TBD)
7.27.2.4 time 函式（頁碼：待定）
7.27.2.4 time 函式（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.2.4 The time function (p: 286)
7.27.2.4 time 函式（頁碼：286）
7.27.2.4 time 函式（頁碼：286）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.2.4 The time function (p: 391)
7.27.2.4 time 函式（頁碼：391）
7.27.2.4 time 函式（頁碼：391）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.2.4 The time function (p: 341)
7.23.2.4 time 函式（頁碼：341）
7.23.2.4 time 函式（頁碼：341）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.2.4 The time function
4.12.2.4 time 函式
4.12.2.4 time 函式

### See also

localtimelocaltime_rlocaltime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as local time
(function)   |

gmtimegmtime_rgmtime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)
(function)   |

timespec_get
(C11)
|   | returns the calendar time in seconds and nanoseconds based on a given time base
(function)   |

C++ documentation for time

---
來源頁路徑：`en.cppreference.com/c/chrono/time.html`
