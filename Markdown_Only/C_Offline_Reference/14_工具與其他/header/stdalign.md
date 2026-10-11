# Standard library header <stdalign.h> (C11)(deprecated in C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the types support library.
該標頭檔是型別支援庫的一部分。

### Macros

alignas
(C11)(removed in C23)
|   | convenience macro, expands to keyword _Alignas
(keyword macro)  |

alignof
(C11)(removed in C23)
|   | convenience macro, expands to keyword _Alignof
(keyword macro)  |

### Constants

__alignas_is_defined
(C11)(removed in C23)
|   | expands to integer constant `1`
(macro constant)  |

__alignof_is_defined
(C11)(removed in C23)
|   | expands to integer constant `1`
(macro constant)  |

### Synopsis

```c
#if __STDC_VERSION__ < 202311L #define alignas _Alignas #define alignof _Alignof #define __alignas_is_defined 1 #define __alignof_is_defined 1 #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/stdalign.html`
