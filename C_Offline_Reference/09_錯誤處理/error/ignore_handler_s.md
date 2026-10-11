# ignore_handler_s

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void ignore_handler_s( const char * restrict msg,  void * restrict ptr,  errno_t error  );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

The function simply returns to the caller without performing any other action.
該函式只是傳回到呼叫者，不執行任何其他操作。
A pointer to this function can be passed to set_constraint_handler_s to establish a runtime constraints violation handler that does nothing.
可以將指向此函式的指標傳遞給 set_constraint_handler_s ，以建立一個不做任何事的執行時約束違規處理函式。

As with all bounds-checked functions, `ignore_handler_s` is only guaranteed to be available if `__STDC_LIB_EXT1__` is defined by the implementation and if the user defines `__STDC_WANT_LIB_EXT1__` to the integer constant `1` before including `<stdlib.h>`.
與所有邊界檢查函式一樣，只有當實現定義了 __STDC_LIB_EXT1__ ，且使用者在包含 <stdlib.h> 之前將 __STDC_WANT_LIB_EXT1__ 定義為整數常量 1 時，才保證 ignore_handler_s 可用。

### Parameters

| msg  |   | -  |   | pointer to character string that describes the error  |

| ptr  |   | -  |   | pointer to an implementation-defined object or a null pointer. Examples of implementation-defined objects are objects that give the name of the function that detected the violation and the line number when the violation was detected  |

| error  |   | -  |   | the error about to be returned by the calling function, if it happens to be one of the functions that return errno_t  |

### Return value

(none)

### Notes

If `ignore_handler_s` is used as a the runtime constraints handler, the violations may be detected by examining the results of the bounds-checked function calls, which may be different for different functions (non-zero errno_t, null character written to the first byte of the output string, etc)
如果 ignore_handler_s 被用作執行時約束處理函式，則可以透過檢查邊界檢查函式呼叫的結果來檢測違規，不同函式的結果可能不同（非零的 errno_t 、寫入輸出字串首位元組的空字元等）
If `set_constraint_handler_s` is never called, the default handler is implementation-defined: it may be abort_handler_s, ignore_handler_s, or some other implementation-defined handler.
如果從未呼叫 set_constraint_handler_s ，預設處理函式由實現定義：它可能是 abort_handler_s 、 ignore_handler_s 或其他由實現定義的處理函式。

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

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- K.3.6.1.3 The ignore_handler_s function (p: 606)
K.3.6.1.3 ignore_handler_s 函式（頁：606）
K.3.6.1.3 ignore_handler_s 函式（頁：606）

### See also

abort_handler_s
(C11)
|   | abort callback for the bounds-checked functions
(function)   |

set_constraint_handler_s
(C11)
|   | set the error callback for bounds-checked functions
(function)   |

---
來源頁路徑：`en.cppreference.com/c/error/ignore_handler_s.html`
