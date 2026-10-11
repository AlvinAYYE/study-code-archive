# timespec

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
struct timespec;
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Structure holding an interval broken down into seconds and nanoseconds.
儲存以秒和納秒分解的時間間隔的結構體。

### Member objects

| Member  |   | Description  |

| time_t `tv_sec`  |   | whole seconds (valid values are >= `0`)  |

| `/* see below */` `tv_nsec`  |   | nanoseconds (valid values are `[``0``, ``999999999``]`)  |

The type of `tv_nsec` is `long`.
|   | (until C23) |

The type of `tv_nsec` is an implementation-defined signed integer type that can represent integers in `[``0``, ``999999999``]`.
|   | (since C23) |

The declaration order of `tv_sec` and `tv_nsec` is unspecified. Implementation may add other members to `struct timespec`.
tv_sec 和 tv_nsec 的宣告順序未指定。實現可以向 struct timespec 新增其他成員。

### Notes

The type of `tv_nsec` is `long long` on some platforms, which is conforming only since C23.
在某些平臺上 tv_nsec 的型別是 long long，這僅從 C23 起才符合標準。

### Example

Run this code

```c
#include <stdint.h> #include <stdio.h> #include <time.h>   int main(void) {  struct timespec ts;  timespec_get(&ts, TIME_UTC);  char buff[100];  strftime(buff, sizeof buff, "%D %T", gmtime(&ts.tv_sec));  printf("Current time: %s.%09ld UTC\n", buff, ts.tv_nsec);  printf("Raw timespec.tv_sec: %jd\n", (intmax_t)ts.tv_sec);  printf("Raw timespec.tv_nsec: %09ld\n", ts.tv_nsec); }
```

Possible output:
可能的輸出：

```c
Current time: 04/04/24 14:45:17.885909786 UTC Raw timespec.tv_sec: 1712241917 Raw timespec.tv_nsec: 885909786
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.27.1/3 Components of time (p: TBD)
7.27.1/3 時間的組成（頁碼：待定）
7.27.1/3 時間的組成（頁碼：待定）

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

### See also

timespec_get
(C11)
|   | returns the calendar time in seconds and nanoseconds based on a given time base
(function)   |

tm
|   | calendar time type
(struct)  |

C++ documentation for timespec

---
來源頁路徑：`en.cppreference.com/c/chrono/timespec.html`
