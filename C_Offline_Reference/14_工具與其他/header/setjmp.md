# Standard library header <setjmp.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the program support utilities library.
該標頭檔是程式支援實用工具庫的一部分。

### Types

jmp_buf
|   | execution context type
(typedef)   |

### Macros

setjmp
|   | saves the context
(function macro)   |

### Functions

longjmp
|   | jumps to specified location
(function)   |

### Synopsis

```c
#define __STDC_VERSION_SETJMP_H__ 202311L typedef /* unspecified */ jmp_buf;   int setjmp(jmp_buf env); [[noreturn]] void longjmp(jmp_buf env, int val);
```

---
來源頁路徑：`en.cppreference.com/c/header/setjmp.html`
