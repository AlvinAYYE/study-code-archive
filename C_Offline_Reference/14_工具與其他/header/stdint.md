# Standard library header <stdint.h> (C99)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of types support library, providing fixed width integer types and a part of numeric limits interface.
該標頭檔是型別支援庫的一部分，提供固定寬度整數型別和部分數值極限介面。

|  | This section is incomplete
Reason: K.3.4 RSIZE_MAX  |

### Types

For each of the following typedef names marked (optional), an implementation defines it if and only if the implementation provides a corresponding type.
對於以下標記為（可選）的每個 typedef 名稱，當且僅當實現提供相應型別時，實現才定義它。

int8_tint16_tint32_tint64_tint*N*_t
(optional)(optional)(optional)(optional)(optional)
|   | signed integer type with width of exactly *N* (typically 8, 16, 32 or 64) bits and no padding bits
(typedef)   |

int_fast8_tint_fast16_tint_fast32_tint_fast64_tint_fast*N*_t
(optional)
|   | fastest signed integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(typedef)   |

int_least8_tint_least16_tint_least32_tint_least64_tint_least*N*_t
(optional)
|   | smallest signed integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(if `int*N*_t` is defined, `int_least*N*_t` designates the same type)
(typedef)   |

intmax_t
|   | maximum-width signed integer type other than a bit-precise integer type(since C23)
(typedef)   |

intptr_t
(optional)
|   | signed integer type other than a bit-precise integer type(since C23) capable of holding a pointer to `void`
(typedef)   |

uint8_tuint16_tuint32_tuint64_tuint*N*_t
(optional)(optional)(optional)(optional)(optional)
|   | unsigned integer type with width of exactly *N* (typically 8, 16, 32 or 64) bits and no padding bits
(typedef)   |

uint_fast8_tuint_fast16_tuint_fast32_tuint_fast64_tuint_fast*N*_t
(optional)
|   | fastest unsigned integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(typedef)   |

uint_least8_tuint_least16_tuint_least32_tuint_least64_tuint_least*N*_t
(optional)
|   | smallest unsigned integer type with width of at least *N* (typically 8, 16, 32 or 64) bits
(if `uint*N*_t` is defined, `uint_least*N*_t` designates the same type)
(typedef)   |

uintmax_t
|   | maximum-width unsigned integer type other than a bit-precise integer type(since C23)
(typedef)   |

uintptr_t
(optional)
|   | unsigned integer type other than a bit-precise integer type(since C23) capable of holding a pointer to `void`
(typedef)   |

### Macro constants
宏常量

For each of the following macros marked (conditionally present), an implementation defines it if and only if the implementation defines the corresponding typedef name.
對於以下標記為（有條件存在）的每個宏，當且僅當實現定義了相應的 typedef 名稱時，實現才定義它。

#####  Signed integers : bit width

INT*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `int*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_FAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `int_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_LEAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `int_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INTMAX_WIDTH
(C23)
|   | bit width of `intmax_t`
(macro constant)   |

INTPTR_WIDTH
(C23)(conditionally present)
|   | bit width of `intptr_t`
(macro constant)   |

#####  Signed integers : minimum value

INT*N*_MIN
(conditionally present)
|   | minimum value of `int*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_FAST*N*_MIN
(conditionally present)
|   | minimum value of `int_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_LEAST*N*_MIN
(conditionally present)
|   | minimum value of `int_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INTMAX_MIN
|   | minimum value of `intmax_t`
(macro constant)   |

INTPTR_MIN
(conditionally present)
|   | minimum value of `intptr_t`
(macro constant)   |

#####  Signed integers : maximum value

INT*N*_MAX
(conditionally present)
|   | maximum value of `int*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_FAST*N*_MAX
(conditionally present)
|   | maximum value of `int_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INT_LEAST*N*_MAX
(conditionally present)
|   | maximum value of `int_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

INTMAX_MAX
|   | maximum value of `intmax_t`
(macro constant)   |

INTPTR_MAX
(conditionally present)
|   | maximum value of `intptr_t`
(macro constant)   |

#####  Unsigned integers : bit width

UINT*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `uint*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_FAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `uint_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_LEAST*N*_WIDTH
(C23)(conditionally present)
|   | bit width of `uint_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINTMAX_WIDTH
(C23)
|   | bit width of `uintmax_t`
(macro constant)   |

UINTPTR_WIDTH
(C23)(conditionally present)
|   | bit width of `uintptr_t`
(macro constant)   |

#####  Unsigned integers : maximum value

UINT*N*_MAX
(conditionally present)
|   | maximum value of `uint*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_FAST*N*_MAX
(conditionally present)
|   | maximum value of `uint_fast*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINT_LEAST*N*_MAX
(conditionally present)
|   | maximum value of `uint_least*N*_t` (*N* is typically 8, 16, 32 or 64)
(macro constant)   |

UINTMAX_MAX
|   | maximum value of `uintmax_t`
(macro constant)   |

UINTPTR_MAX
(conditionally present)
|   | maximum value of `uintptr_t`
(macro constant)   |

#####  Characteristics of other integer types

PTRDIFF_WIDTH
(C23)
|   | bit width of ptrdiff_t
(macro constant)   |

PTRDIFF_MIN
|   | minimum value of ptrdiff_t
(macro constant)   |

PTRDIFF_MAX
|   | maximum value of ptrdiff_t
(macro constant)   |

SIZE_WIDTH
(C23)
|   | bit width of size_t
(macro constant)   |

SIZE_MAX
|   | maximum value of size_t
(macro constant)   |

SIG_ATOMIC_WIDTH
(C23)
|   | bit width of sig_atomic_t
(macro constant)   |

SIG_ATOMIC_MIN
|   | minimum value of sig_atomic_t
(macro constant)   |

SIG_ATOMIC_MAX
|   | maximum value of sig_atomic_t
(macro constant)   |

WINT_WIDTH
(C23)
|   | bit width of `wint_t`
(macro constant)   |

WINT_MIN
|   | minimum value of `wint_t`
(macro constant)   |

WINT_MAX
|   | maximum value of `wint_t`
(macro constant)   |

WCHAR_WIDTH
(C23)
|   | bit width of `wchar_t`
(macro constant)   |

WCHAR_MIN
|   | minimum value of `wchar_t`
(macro constant)   |

WCHAR_MAX
|   | maximum value of `wchar_t`
(macro constant)   |

### Function macros
函式宏

For each of the following macros marked (conditionally present), an implementation defines it if and only if the implementation defines the corresponding typedef name.
對於以下標記為（有條件存在）的每個宏，當且僅當實現定義了相應的 typedef 名稱時，實現才定義它。

INT*N*_C
(conditionally present)
|   | expands to an integer constant expression of type `int_least*N*_t`, its value is specified by the argument
(function macro)   |

INTMAX_C
|   | expands to an integer constant expression of type `intmax_t`, its value is specified by the argument
(function macro)   |

UINT*N*_C
(conditionally present)
|   | expands to an integer constant expression of type `uint_least*N*_t`, its value is specified by the argument
(function macro)   |

UINTMAX_C
|   | expands to an integer constant expression of type `uintmax_t`, its value is specified by the argument
(function macro)   |

### Synopsis

```c
#define __STDC_VERSION_STDINT_H__ 202311L // see description of intN_t typedef /* see description */ int8_t; // optional typedef /* see description */ int16_t; // optional typedef /* see description */ int32_t; // optional typedef /* see description */ int64_t; // optional typedef /* see description */ intN_t; // optional // see description of int_fastN_t typedef /* see description */ int_fast8_t; typedef /* see description */ int_fast16_t; typedef /* see description */ int_fast32_t; typedef /* see description */ int_fast64_t; typedef /* see description */ int_fastN_t; // optional // see description of int_leastN_t typedef /* see description */ int_least8_t; typedef /* see description */ int_least16_t; typedef /* see description */ int_least32_t; typedef /* see description */ int_least64_t; typedef /* see description */ int_leastN_t; // optional typedef /* see description */ intmax_t; typedef /* see description */ intptr_t; // optional // see description of uintN_t typedef /* see description */ uint8_t; // optional typedef /* see description */ uint16_t; // optional typedef /* see description */ uint32_t; // optional typedef /* see description */ uint64_t; // optional typedef /* see description */ uintN_t; // optional // see description of uint_fastN_t typedef /* see description */ uint_fast8_t; typedef /* see description */ uint_fast16_t; typedef /* see description */ uint_fast32_t; typedef /* see description */ uint_fast64_t; typedef /* see description */ uint_fastN_t; // optional // see description of uint_leastN_t typedef /* see description */ uint_least8_t; typedef /* see description */ uint_least16_t; typedef /* see description */ uint_least32_t; typedef /* see description */ uint_least64_t; typedef /* see description */ uint_leastN_t; // optional typedef /* see description */ uintmax_t; typedef /* see description */ uintptr_t; // optional #define INTN_MIN /* see description */ #define INTN_MAX /* see description */ #define UINTN_MAX /* see description */ #define INTN_WIDTH /* see description */ #define UINTN_WIDTH /* see description */ #define INT_FASTN_MIN /* see description */ #define INT_FASTN_MAX /* see description */ #define UINT_FASTN_MAX /* see description */ #define INT_FASTN_WIDTH /* see description */ #define UINT_FASTN_WIDTH /* see description */ #define INT_LEASTN_MIN /* see description */ #define INT_LEASTN_MAX /* see description */ #define UINT_LEASTN_MAX /* see description */ #define INT_LEASTN_WIDTH /* see description */ #define UINT_LEASTN_WIDTH /* see description */ #define INTMAX_MIN /* see description */ #define INTMAX_MAX /* see description */ #define UINTMAX_MAX /* see description */ #define INTMAX_WIDTH /* see description */ #define UINTMAX_WIDTH /* see description */ #define INTPTR_MIN /* see description */ // optional #define INTPTR_MAX /* see description */ // optional #define UINTPTR_MAX /* see description */ // optional #define INTPTR_WIDTH /* see description */ // optional #define UINTPTR_WIDTH /* see description */ // optional #define PTRDIFF_MIN /* see description */ #define PTRDIFF_MAX /* see description */ #define PTRDIFF_WIDTH /* see description */ #define SIZE_MAX /* see description */ #define SIZE_WIDTH /* see description */ #define SIG_ATOMIC_MIN /* see description */ #define SIG_ATOMIC_MAX /* see description */ #define SIG_ATOMIC_WIDTH /* see description */ #define WCHAR_MIN /* see description */ #define WCHAR_MAX /* see description */ #define WCHAR_WIDTH /* see description */ #define WINT_MIN /* see description */ #define WINT_MAX /* see description */ #define WINT_WIDTH /* see description */ #define INTN_C(value) /* see description */ #define UINTN_C(value) /* see description */ #define INTMAX_C(value) /* see description */ #define UINTMAX_C(value) /* see description */
```

Only if the implementation defines `__STDC_LIB_EXT1__` and additionally the user code defines `__STDC_WANT_LIB_EXT1__` before any inclusion of `<stdint.h>`:
僅當實現定義 __STDC_LIB_EXT1__ ，且此外使用者 程式碼在包含 <stdint.h> 之前的任何位置定義 __STDC_WANT_LIB_EXT1__ ：

```c
#if defined(__STDC_WANT_LIB_EXT1__) #define RSIZE_MAX /* see description */ #endif
```

---
來源頁路徑：`en.cppreference.com/c/header/stdint.html`
