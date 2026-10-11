# set_constraint_handler_s, constraint_handler_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
constraint_handler_t set_constraint_handler_s( constraint_handler_t handler );
```
|   |  (1)  |   |  (since C11)  |

```c
typedef void (*constraint_handler_t)( const char* restrict msg,  void* restrict ptr,  errno_t error );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

1) Configures the handler to be called by all bounds-checked functions on a runtime constraint violation or restores the default handler (if `handler` is a null pointer).

2) The pointer to a handler that will be called on a runtime constraint violation.

If `set_constraint_handler_s` is never called, the default handler is implementation-defined: it may be abort_handler_s, ignore_handler_s, or some other implementation-defined handler.
如果從未呼叫 set_constraint_handler_s ，預設處理函式由實現定義：它可能是 abort_handler_s 、 ignore_handler_s 或其他由實現定義的處理函式。
As with all bounds-checked functions, `set_constraint_handler_s` and `constraint_handler_t` are only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including <stdlib.h>.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ ，且使用者在包含 <stdlib.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 set_constraint_handler_s 和 constraint_handler_t 可用。

### Parameters

| handler  |   | -  |   | pointer to function of type `constraint_handler_t` or a null pointer  |

| msg  |   | -  |   | pointer to character string that describes the error  |

| ptr  |   | -  |   | pointer to an implementation-defined object or a null pointer. Examples of implementation-defined objects are objects that give the name of the function that detected the violation and the line number when the violation was detected  |

| error  |   | -  |   | the error about to be returned by the calling function, if it happens to be one of the functions that return `errno_t`  |

### Return value

A pointer to the previously-installed runtime constraints handler. (Note: this pointer is never a null pointer because calling `set_constraint_handler_s(NULL)` sets up the system default handler).
指向先前安裝的執行時約束處理函式的指標。（注意：該指標絕不會是空指標，因為呼叫 set_constraint_handler_s ( NULL ) 會建立系統預設處理函式）。

### Example

Run this code

```c
#define __STDC_WANT_LIB_EXT1__ 1 #include <string.h> #include <stdio.h> #include <stdlib.h> int main(void) { #ifdef __STDC_LIB_EXT1__  char dst[2];  set_constraint_handler_s(ignore_handler_s);  int r = strcpy_s(dst, sizeof dst, "Too long!");  printf("dst = \"%s\", r = %d\n", dst, r);  set_constraint_handler_s(abort_handler_s);  r = strcpy_s(dst, sizeof dst, "Too long!");  printf("dst = \"%s\", r = %d\n", dst, r); #endif }
```

Possible output:
可能的輸出：

```c
dst = "", r = 22 abort_handler_s was called in response to a runtime-constraint violation. The runtime-constraint violation was caused by the following expression in strcpy_s: (s1max <= (s2_len=strnlen_s(s2, s1max)) ) (in string_s.c:62) Note to end users: This program was terminated as a result of a bug present in the software. Please reach out to your software's vendor to get more help. Aborted
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- K.3.6/2 constraint_handler_t (p: TBD)
K.3.6/2 constraint_handler_t（頁：TBD）
K.3.6/2 constraint_handler_t（頁：TBD）

- K.3.6.1.1 The set_constraint_handler_s function (p: TBD)
K.3.6.1.1 set_constraint_handler_s 函式（頁：TBD）
K.3.6.1.1 set_constraint_handler_s 函式（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- K.3.6/2 constraint_handler_t (p: TBD)
K.3.6/2 constraint_handler_t（頁：TBD）
K.3.6/2 constraint_handler_t（頁：TBD）

- K.3.6.1.1 The set_constraint_handler_s function (p: TBD)
K.3.6.1.1 set_constraint_handler_s 函式（頁：TBD）
K.3.6.1.1 set_constraint_handler_s 函式（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- K.3.6/2 constraint_handler_t (p: 604)
K.3.6/2 constraint_handler_t（頁：604）
K.3.6/2 constraint_handler_t（頁：604）

- K.3.6.1.1 The set_constraint_handler_s function (p: 604-605)
K.3.6.1.1 set_constraint_handler_s 函式（頁：604-605）
K.3.6.1.1 set_constraint_handler_s 函式（頁：604-605）

### See also

abort_handler_s
(C11)
|   | abort callback for the bounds-checked functions
(function)   |

ignore_handler_s
(C11)
|   | ignore callback for the bounds-checked functions
(function)   |

---
來源頁路徑：`en.cppreference.com/c/error/set_constraint_handler_s.html`
