# ATOMIC_*_LOCK_FREE

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
#define ATOMIC_BOOL_LOCK_FREE /* implementation-defined */ #define ATOMIC_CHAR_LOCK_FREE /* implementation-defined */ #define ATOMIC_CHAR16_T_LOCK_FREE /* implementation-defined */ #define ATOMIC_CHAR32_T_LOCK_FREE /* implementation-defined */ #define ATOMIC_WCHAR_T_LOCK_FREE /* implementation-defined */ #define ATOMIC_SHORT_LOCK_FREE /* implementation-defined */ #define ATOMIC_INT_LOCK_FREE /* implementation-defined */ #define ATOMIC_LONG_LOCK_FREE /* implementation-defined */ #define ATOMIC_LLONG_LOCK_FREE /* implementation-defined */ #define ATOMIC_POINTER_LOCK_FREE /* implementation-defined */
```
|   |   |   |  (since C11)  |

```c
#define ATOMIC_CHAR8_T_LOCK_FREE /* implementation-defined */
```
|   |   |   |  (since C23)  |

|  |  |  |  |

Expands to preprocessor constant expressions that evaluate to either `0`, `1`, or `2` which indicate the lock-free property of the corresponding atomic types (both signed and unsigned).
展開為求值為 0、1 或 2 的預處理常量表示式，指示相應原子型別（有符號和無符號）的無鎖屬性。

| Value  |   | Explanation  |

| `0`  |   | The atomic type is never lock-free  |

| `1`  |   | The atomic type is sometimes lock-free  |

| `2`  |   | The atomic type is always lock-free  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.1/3 atomic lock-free macros (p: 200)
7.17.1/3 原子無鎖宏（頁：200）
7.17.1/3 原子無鎖宏（頁：200）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.1/3 atomic lock-free macros (p: 273)
7.17.1/3 原子無鎖宏（頁：273）
7.17.1/3 原子無鎖宏（頁：273）

---
來源頁路徑：`en.cppreference.com/c/atomic/ATOMIC_LOCK_FREE_consts.html`
