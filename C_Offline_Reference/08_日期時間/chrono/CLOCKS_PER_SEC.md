# CLOCKS_PER_SEC

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<time.h>`
|   |  |   |  |

```c
#define CLOCKS_PER_SEC /* implementation-defined */
```
|   |   |   |   |

|  |  |  |  |

Expands to an expression (not necessarily a compile-time constant) of type clock_t equal to the number of clock ticks per second, as returned by clock().
展開為型別 clock_t 的表示式（不一定是編譯期常量），等於每秒的時鐘滴答數，即 clock() 傳回的值。

### Notes

POSIX defines `CLOCKS_PER_SEC` as `1'000'000`, regardless of the actual precision of clock.
POSIX 將 CLOCKS_PER_SEC 定義為 1'000'000 ，而不管 clock 的實際精度。
Until standardized as `CLOCKS_PER_SEC` in C89, this macro was sometimes known by its IEEE std 1003.1-1988 name `CLK_TCK`: that name was not included in C89 and was removed from POSIX itself in 1996 over ambiguity with `_SC_CLK_TCK`, which gives number of clocks per second for the function `times`).
在 C89 中被標準化為 CLOCKS_PER_SEC 之前，該宏有時以其 IEEE std 1003.1-1988 名稱 CLK_TCK 聞名：該名稱未包含在 C89 中，並於 1996 年從 POSIX 本身中移除，因為與 _SC_CLK_TCK 存在歧義，後者給出函式 times 的每秒時鐘數）。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.27.1/2 Components of time (p: TBD)
7.27.1/2 時間的組成（頁碼：待定）
7.27.1/2 時間的組成（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.27.1/2 Components of time (p: 284)
7.27.1/2 時間的組成（頁碼：284）
7.27.1/2 時間的組成（頁碼：284）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.27.1/2 Components of time (p: 388)
7.27.1/2 時間的組成（頁碼：388）
7.27.1/2 時間的組成（頁碼：388）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.23.1/2 Components of time (p: 338)
7.23.1/2 時間的組成（頁碼：338）
7.23.1/2 時間的組成（頁碼：338）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.12.1 Components of time
4.12.1 時間的組成部分
4.12.1 時間的組成部分

### See also

clock
|   | returns raw processor clock time since the program is started
(function)   |

clock_t
|   | processor time since era type
(typedef)   |

C++ documentation for CLOCKS_PER_SEC

---
來源頁路徑：`en.cppreference.com/c/chrono/CLOCKS_PER_SEC.html`
