# Standard library header <time.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of date and time utilities library.
該標頭檔是日期和時間實用工具庫的一部分。

### Functions

#####  Time manipulation

difftime
|   | computes the difference between times
(function)   |

time
|   | returns the current calendar time of the system as time since epoch
(function)   |

clock
|   | returns raw processor clock time since the program is started
(function)   |

timespec_get
(C11)
|   | returns the calendar time in seconds and nanoseconds based on a given time base
(function)   |

timespec_getres
(C23)
|   | returns the resolution of calendar time based on a given time base
(function)   |

#####  Format conversions

asctimeasctime_s
(deprecated in C23)(C11)
|   | converts a tm object to a textual representation
(function)   |

ctimectime_s
(deprecated in C23)(C11)
|   | converts a time_t object to a textual representation
(function)   |

strftime
|   | converts a tm object to custom textual representation
(function)   |

gmtimegmtime_rgmtime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as Coordinated Universal Time (UTC)
(function)   |

localtimelocaltime_rlocaltime_s
(C23)(C11)
|   | converts time since epoch to calendar time expressed as local time
(function)   |

mktime
|   | converts calendar time to time since epoch
(function)   |

timegm
(C23)
|   | converts calendar time to time since epoch, ignoring the Daylight Saving Time flag
(function)   |

### Constants

CLOCKS_PER_SEC
|   | number of processor clock ticks per second
(macro constant)   |

### Types

tm
|   | calendar time type
(struct)  |

time_t
|   | calendar time since epoch type
(typedef)   |

clock_t
|   | processor time since era type
(typedef)   |

timespec
(C11)
|   | time in seconds and nanoseconds
(struct)  |

### Synopsis

```c
#define __STDC_VERSION_TIME_H__ 202311L #define NULL /* see description */ #define CLOCKS_PER_SEC /* see description */ #define TIME_UTC /* see description */ typedef /* see description */ clock_t; typedef /* see description */ size_t; typedef /* see description */ time_t; struct timespec { /* see description */ }; struct tm { /* see description */ }; clock_t clock(void); double difftime(time_t time1, time_t time0); time_t mktime(struct tm* timeptr); time_t timegm(struct tm* timeptr); time_t time(time_t* timer); int timespec_get(struct timespec* ts, int base); int timespec_getres(struct timespec* ts, int base); [[deprecated]] char* asctime(const struct tm* timeptr); [[deprecated]] char* ctime(const time_t* timer); struct tm* gmtime(const time_t* timer); struct tm* gmtime_r(const time_t* timer, struct tm* buf); struct tm* localtime(const time_t* timer); struct tm* localtime_r(const time_t* timer, struct tm* buf); size_t strftime(char* restrict s, size_t maxsize, const char* restrict format, const struct tm* restrict timeptr);
```

Only if supported by the implementation:
僅當實現支援時：

```c
#define TIME_MONOTONIC /* see description */ #define TIME_ACTIVE /* see description */
```

Only if threads are supported and it is supported by the implementation:
僅當支援執行緒且實現支援時：

```c
#define TIME_THREAD_ACTIVE /* see description */
```

Only if the implementation defines `__STDC_LIB_EXT1__` and additionally the user code defines `__STDC_WANT_LIB_EXT1__` before any inclusion of `<time.h>`:
僅當實現定義 __STDC_LIB_EXT1__ ，且此外使用者程式碼在包含 <time.h> 之前的任何位置定義 __STDC_WANT_LIB_EXT1__ ：

```c
#ifdef __STDC_WANT_LIB_EXT1__ typedef /* see description */ errno_t; typedef /* see description */ rsize_t; errno_t asctime_s(char* s, rsize_t maxsize, const struct tm* timeptr); errno_t ctime_s(char* s, rsize_t maxsize, const time_t* timer); struct tm* gmtime_s(const time_t* restrict timer, struct tm* restrict result); struct tm* localtime_s(const time_t* restrict timer, struct tm* restrict result); #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/time.html`
