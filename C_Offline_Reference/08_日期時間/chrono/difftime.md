# difftime

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
double difftime( time_t time_end, time_t time_beg );
```
|   |   |   |   |

|  |  |  |  |

Computes difference between two calendar times as time_t objects (`time_end - time_beg`) in seconds. If `time_end` refers to time point before `time_beg` then the result is negative.
計算兩個日曆時間（time_t 物件）的差值 time_end - time_beg，單位為秒。若 time_end 指向早於 time_beg 的時間點，結果會是負值。

### Parameters

| time_beg, time_end  |   | -  |   | times to compare  |

### Return value

Difference between two times in seconds.
兩個時間之間以秒為單位的差值。

### Notes

On POSIX systems, time_t is measured in seconds, and `difftime` is equivalent to arithmetic subtraction, but C and C++ allow fractional units for time_t.
在 POSIX 系統上，time_t 以秒為單位，difftime 等價於算術減法，但 C 和 C++ 允許 time_t 使用小數單位。

### Example

The following program computes the number of seconds that have passed since the beginning of the month.
下面的程式計算從本月開始以來經過的秒數。
Run this code

```c
#include <stdio.h> #include <time.h> int main(void) {  time_t now = time(0);  struct tm beg = *localtime(&now);  // set beg to the beginning of the month  beg.tm_hour = 0,  beg.tm_min = 0,  beg.tm_sec = 0,  beg.tm_mday = 1;  double seconds = difftime(now, mktime(&beg));  printf("%.f seconds have passed since the beginning of the month.\n", seconds);  return 0; }
```

Output:

```c
1937968 seconds have passed since the beginning of the month.
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.2.2 The difftime function (p: 285)
7.27.2.2 difftime 函式 (p: 285)
7.27.2.2 difftime 函式 (p: 285)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.2.2 The difftime function (p: 390)
7.27.2.2 difftime 函式 (p: 390)
7.27.2.2 difftime 函式 (p: 390)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.2.2 The difftime function (p: 338)
7.23.2.2 difftime 函式 (p: 338)
7.23.2.2 difftime 函式 (p: 338)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 7.12.2.2 The difftime function (p: 171)
7.12.2.2 difftime 函式 (p: 171)
7.12.2.2 difftime 函式 (p: 171)

### See also

C++ documentation for difftime

---
來源頁路徑：`en.cppreference.com/c/chrono/difftime.html`
