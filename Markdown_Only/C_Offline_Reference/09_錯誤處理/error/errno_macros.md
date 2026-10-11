# Error numbers

> 來源：cppreference C 語言參考文件（離線轉換版）。

Each of the macros defined in <errno.h> expands to an integer constant expression with type `int` and with a unique positive value. The following constants are defined by ISO C. The implementation may define more, as long as they begin with `'E'` followed by digits or uppercase letters.
<errno.h> 中定義的每個宏都展開為一個型別為 int 且具有唯一正值的整數常量表示式。以下常量由 ISO C 定義。實現可以定義更多，只要它們以 E 開頭、後跟數字或大寫字母即可。

Defined in header `<errno.h>`

EDOM
|   | Mathematics argument out of domain of function
(macro constant)  |

EILSEQ
(C95)
|   | Illegal byte sequence
(macro constant)  |

ERANGE
|   | Result too large
(macro constant)  |

### Notes

Many additional errno constants are defined by POSIX and by the C++ standard library, and individual implementations may define even more, e.g. `errno(3)` on Linux or `intro(2)` on BSD and OS X.
POSIX 和 C++ 標準函式庫還定義了許多額外的 errno 常量，各個實現可能定義更多，例如 Linux 上的 errno ( 3 ) 或 BSD 和 OS X 上的 intro ( 2 )。

### Example

Run this code

```c
#include <errno.h> #include <math.h> #include <stdio.h> #include <string.h> int main(void) {  errno = 0;  printf("log(-1.0) = %f\n", log(-1.0));  printf("%s\n\n", strerror(errno));    errno = 0;  printf("log(0.0) = %f\n", log(0.0));  printf("%s\n", strerror(errno)); }
```

Possible output:
可能的輸出：

```c
log(-1.0) = nan Numerical argument out of domain log(0.0) = -inf Numerical result out of range
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.5/2 Errors <errno.h> (p: TBD)
7.5/2 錯誤 <errno.h>（頁：TBD）
7.5/2 錯誤 <errno.h>（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.5/2 Errors <errno.h> (p: TBD)
7.5/2 錯誤 <errno.h>（頁：TBD）
7.5/2 錯誤 <errno.h>（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.5/2 Errors <errno.h> (p: 205)
7.5/2 錯誤 <errno.h>（頁：205）
7.5/2 錯誤 <errno.h>（頁：205）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.5/2 Errors <errno.h> (p: 186)
7.5/2 錯誤 <errno.h>（頁：186）
7.5/2 錯誤 <errno.h>（頁：186）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.1.3 Errors <errno.h>
4.1.3 錯誤 <errno.h>
4.1.3 錯誤 <errno.h>

### See also

errno
|   | macro which expands to POSIX-compatible thread-local error number variable
(macro variable)   |

perror
|   | displays a character string corresponding of the current error to stderr
(function)   |

strerrorstrerror_sstrerrorlen_s
(C11)(C11)
|   | returns a text version of a given error code
(function)   |

C++ documentation for Error numbers

---
來源頁路徑：`en.cppreference.com/c/error/errno_macros.html`
