# Standard library header <stdbool.h> (C99)(deprecated in C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header provides macros for boolean type.
該標頭檔為布林型別提供宏。

### Macros

bool
(C99)(removed in C23)
|   | convenience macro, expands to _Bool
(keyword macro)  |

### Macro constants

true
(C99)(removed in C23)
|   | expands to integer constant `1`
(macro constant)  |

false
(C99)(removed in C23)
|   | expands to integer constant `0`
(macro constant)  |

__bool_true_false_are_defined
(C99)(deprecated in C23)
|   | expands to integer constant `1`
(macro constant)  |

### Synopsis

```c
#if __STDC_VERSION__ < 202311l #define bool _Bool #define true 1 #define false 0 #endif #define __bool_true_false_are_defined 1
```

---
來源頁路徑：`en.cppreference.com/c/header/stdbool.html`
