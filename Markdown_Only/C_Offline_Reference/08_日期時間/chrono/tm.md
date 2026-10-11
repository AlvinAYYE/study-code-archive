# tm

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
struct tm;
```
|   |   |   |   |

|  |  |  |  |

Structure holding a calendar date and time broken down into its components.
儲存按組成部分分解的日曆日期和時間的結構體。

### Member objects

int tm_sec
|   | seconds after the minute – `[``0``, ``61``]`(until C99)`[``0``, ``60``]`(since C99)
(public member object)  |

int tm_min
|   | minutes after the hour – `[``0``, ``59``]`
(public member object)  |

int tm_hour
|   | hours since midnight – `[``0``, ``23``]`
(public member object)  |

int tm_mday
|   | day of the month – `[``1``, ``31``]`
(public member object)  |

int tm_mon
|   | months since January – `[``0``, ``11``]`
(public member object)  |

int tm_year
|   | years since 1900
(public member object)  |

int tm_wday
|   | days since Sunday – `[``0``, ``6``]`
(public member object)  |

int tm_yday
|   | days since January 1 – `[``0``, ``365``]`
(public member object)  |

int tm_isdst
|   | Daylight Saving Time flag. The value is positive if DST is in effect, zero if not and negative if no information is available
(public member object)  |

###### Notes

The Standard mandates only the presence of the aforementioned members in either order. The implementations usually add more data-members to this structure.
標準僅要求以上述成員存在，順序不限。實現通常會向該結構體新增更多資料成員。

- ↑ Range allows for a positive leap second. Two leap seconds in the same minute are not allowed (the C89 range 0..61 was a defect)
↑ 該範圍允許正閏秒。同一分鐘內不允許出現兩個閏秒（C89 的範圍 0..61 是一個缺陷）

### Example

Run this code

```c
#include <stdio.h> #include <time.h> int main(void) {  struct tm start = {.tm_year = 2022 - 1900, .tm_mday = 1};  mktime(&start);  printf("%s", asctime(&start)); // note implicit trailing '\n' }
```

Output:

```c
Sat Jan 1 00:00:00 2022
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

localtimelocaltime_rlocaltime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as local time
(function)   |

gmtimegmtime_rgmtime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)
(function)   |

C++ documentation for tm

---
來源頁路徑：`en.cppreference.com/c/chrono/tm.html`
