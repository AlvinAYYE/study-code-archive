# Standard library header <stddef.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of types support library, in particular, it provides additional basic types and convenience macros.
該標頭檔是型別支援庫的一部分，特別是它提供了額外的基本型別和便捷宏。

### Types

ptrdiff_t
|   | signed integer type returned when subtracting two pointers
(typedef)   |

nullptr_t
(C23)
|   | the type of the predefined null pointer constant nullptr
(typedef)   |

max_align_t
(C11)
|   | a type with alignment requirement as great as any other scalar type
(typedef)   |

size_t
|   | unsigned integer type returned by the sizeof operator
(typedef)   |

### Constants

NULL
|   | implementation-defined null pointer constant
(macro constant)   |

### Macros

offsetof
|   | byte offset from the beginning of a struct type to specified member
(function macro)   |

### Synopsis

```c
#define __STDC_VERSION_STDDEF_H__ 202311L typedef /* see description */ ptrdiff_t; typedef /* see description */ nullptr_t; typedef /* see description */ max_align_t; typedef /* see description */ wchar_t; typedef /* see description */ size_t; #define NULL /* see description */ #define unreachable() /* see description */ #define offsetof(P, D) /* see description */
```

Only if the implementation defines `__STDC_LIB_EXT1__` and additionally the user code defines `__STDC_WANT_LIB_EXT1__` before any inclusion of `<stddef.h>`:
僅當實現定義 __STDC_LIB_EXT1__ ，且此外使用者程式碼 在包含 <stddef.h> 之前的任何位置定義 __STDC_WANT_LIB_EXT1__ ：

```c
#if defined(__STDC_WANT_LIB_EXT1__) typedef /* see description */ rsize_t; #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/stddef.html`
