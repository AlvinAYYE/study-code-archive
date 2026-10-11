# Standard library header <assert.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the error handling library.
該標頭檔是錯誤處理庫的一部分。

### Macros

assert
|   | aborts the program if the user-specified condition is not `true`. May be disabled for release builds
(function macro)   |

### Synopsis

```c
#if __STDC_VERSION__ >= 202311L # define __STDC_VERSION_ASSERT_H__ 202311L # ifdef NDEBUG # define assert(...) ((void)0) # else # define assert(...) /* implementation-defined */ # endif #else # ifdef NDEBUG # define assert(condition) ((void)0) # else # define assert(condition) /* implementation-defined */ # endif #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/assert.html`
