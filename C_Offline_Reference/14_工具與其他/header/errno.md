# Standard library header <errno.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the error handling library.
該標頭檔是錯誤處理庫的一部分。

### Error numbers

errno
|   | macro which expands to POSIX-compatible thread-local error number variable
(macro variable)   |

E2BIG, EACCES, ..., EXDEV
|   | macros for standard POSIX-compatible error conditions
(macro constant)   |

### Synopsis

```c
#define EDOM /* implementation-defined */ #define EILSEQ /* implementation-defined */ #define ERANGE /* implementation-defined */ #define errno /* implementation-defined */ // Only if the implementation defines __STDC_LIB_EXT1__ and additionally the user code // defines __STDC_WANT_LIB_EXT1__ before any inclusion of <errno.h>: #ifdef __STDC_WANT_LIB_EXT1__ #define __STDC_LIB_EXT1__ /* implementation-defined */ #define errno_t /* implementation-defined */ #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/errno.html`
