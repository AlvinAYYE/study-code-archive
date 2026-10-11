# 日期與時間工具

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Functions

#####  Time manipulation

Defined in header `<time.h>`

difftime
|   | 計算兩個時間值之間的差
(function)   |

time
|   | 取得目前日曆時間，並以自 Epoch 起經過的時間表示
(function)   |

clock
|   | 取得程式啟動後經過的處理器時間
(function)   |

timespec_get
(C11)
|   | 依指定的時間基準，取得以秒和奈秒表示的日曆時間
(function)   |

timespec_getres
(C23)
|   | 依指定的時間基準，取得日曆時間的解析度
(function)   |

#####  Format conversions

Defined in header `<time.h>`

asctimeasctime_s
(deprecated in C23)(C11)
|   | 將 `tm` 時間結構轉成文字
(function)   |

ctimectime_s
(deprecated in C23)(C11)
|   | 將 `time_t` 時間值轉成文字
(function)   |

strftime
|   | 按指定格式將 `tm` 時間結構轉成文字
(function)   |

Defined in header `<wchar.h>`

wcsftime
(C95)
|   | converts a tm object to custom wide string textual representation
(function)   |

Defined in header `<time.h>`

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

Defined in header `<time.h>`

CLOCKS_PER_SEC
|   | number of processor clock ticks per second
(macro constant)   |

### Types

Defined in header `<time.h>`

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

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.27 Date and time <time.h> (p: TBD)
7.27 日期與時間 <time.h>（p: 待定）
7.27 日期與時間 <time.h>（p: 待定）

- 7.29.5.1 The wcsftime function (p: TBD)
7.29.5.1 wcsftime 函式（頁碼：待定）
7.29.5.1 wcsftime 函式（頁碼：待定）

- 7.31.14 Date and time <time.h> (p: TBD)
7.31.14 日期與時間 <time.h>（p: 待定）
7.31.14 日期與時間 <time.h>（p: 待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27 Date and time <time.h> (p: 284-291)
7.27 日期與時間 <time.h>（p: 284-291）
7.27 日期與時間 <time.h>（p: 284-291）

- 7.29.5.1 The wcsftime function (p: 320-321)
7.29.5.1 wcsftime 函式（p: 320-321）
7.29.5.1 wcsftime 函式（p: 320-321）

- 7.31.14 Date and time <time.h> (p: 333)
7.31.14 日期與時間 <time.h>（p: 333）
7.31.14 日期與時間 <time.h>（p: 333）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27 Date and time <time.h> (p: 388-397)
7.27 日期與時間 <time.h>（p: 388-397）
7.27 日期與時間 <time.h>（p: 388-397）

- 7.29.5.1 The wcsftime function (p: 439-440)
7.29.5.1 wcsftime 函式（頁碼：439-440）
7.29.5.1 wcsftime 函式（頁碼：439-440）

- 7.31.14 Date and time <time.h> (p: 456)
7.31.14 日期與時間 <time.h>（p: 456）
7.31.14 日期與時間 <time.h>（p: 456）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23 Date and time <time.h> (p: 338-347)
7.23 日期與時間 <time.h>（p: 338-347）
7.23 日期與時間 <time.h>（p: 338-347）

- 7.24.5.1 The wcsftime function (p: 385-386)
7.24.5.1 wcsftime 函式（頁碼：385-386）
7.24.5.1 wcsftime 函式（頁碼：385-386）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12 DATE AND TIME <time.h>
4.12 日期與時間 <time.h>
4.12 日期與時間 <time.h>

### See also

C++ documentation for C Date and time utilities

---
來源頁路徑：`en.cppreference.com/c/chrono.html`
