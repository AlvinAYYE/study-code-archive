# time_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
typedef /* unspecified */ time_t;
```
|   |   |   |   |

|  |  |  |  |

Real arithmetic type capable of representing times.
能夠表示時間的實算術型別。
Although not defined by the C standard, this is almost always an integral value holding the number of seconds (not counting leap seconds) since 00:00, Jan 1 1970 UTC, corresponding to  POSIX time.
雖然 C 標準未定義，但它幾乎總是某個整數值，儲存自 1970 年 1 月 1 日 00:00 UTC 以來的秒數（不計閏秒），對應於 POSIX 時間。

### Notes

The standard uses the term *calendar time* when referring to a value of type time_t.
標準在指代 time_t 型別的值時使用“日曆時間”這一術語。

### Example

Show the start of the epoch.
顯示紀元的起點。
Run this code

```c
#include <stdio.h> #include <time.h> #include <stdint.h> int main(void) {  time_t epoch = 0;  printf("%jd seconds since the epoch began\n", (intmax_t)epoch);  printf("%s", asctime(gmtime(&epoch))); }
```

Possible output:
可能的輸出：

```c
0 seconds since the epoch began Thu Jan 1 00:00:00 1970
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.1/3 Components of time (p: 284)
7.27.1/3 時間的組成部分 (p: 284)
7.27.1/3 時間的組成部分 (p: 284)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.1/3 Components of time (p: 388)
7.27.1/3 時間的組成部分 (p: 388)
7.27.1/3 時間的組成部分 (p: 388)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.1/3 Components of time (p: 338)
7.23.1/3 時間的組成部分 (p: 338)
7.23.1/3 時間的組成部分 (p: 338)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.1 Components of time
4.12.1 時間的組成部分
4.12.1 時間的組成部分

### See also

time
|   | returns the current calendar time of the system as time since epoch
(function)   |

localtimelocaltime_rlocaltime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as local time
(function)   |

gmtimegmtime_rgmtime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)
(function)   |

C++ documentation for time_t

---
來源頁路徑：`en.cppreference.com/c/chrono/time_t.html`
