# errno

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<errno.h>`
|   |  |   |  |

```c
#define errno /* implementation-defined */
```
|   |   |   |   |

|  |  |  |  |

`errno` is a preprocessor macro (but see note below) that expands to a thread-local(since C11) modifiable lvalue of type `int`. Several standard library functions indicate errors by writing positive integers to `errno`. Typically, the value of `errno` is set to one of the error codes listed in <errno.h> as macro constants beginning with the letter `E` followed by uppercase letters or digits.
errno 是前處理巨集（但請參閱下方註解），會展開為可修改的 int 左值；自 C11 起，它具有執行緒區域儲存期。部分標準函式庫函式會將正整數寫入 errno 來表示錯誤。errno 通常會設為 <errno.h> 中定義的錯誤碼之一，這些巨集常數以 E 開頭，後接大寫字母或數字。
The value of `errno` is `0` at program startup, and although library functions are allowed to write positive integers to `errno` whether or not an error occurred, library functions never store `0` in `errno`.
程式啟動時 errno 為 0。函式庫函式無論是否發生錯誤，都可以將正整數寫入 errno，但絕不會將 0 寫入 errno。
Library functions perror and strerror can be used to obtain textual descriptions of the error conditions that correspond to the current `errno` value.
庫函式 perror 和 strerror 可用於獲取與目前 errno 值相對應的錯誤條件的文字描述。
Note: Until C11, the C standards had contradictory requirements, in that they said that `errno` is a macro but *also* that "it is unspecified whether `errno` is a macro or an identifier declared with external linkage". C11 fixes this, requiring that it be defined as a macro (see also WG14 N1338).
注：在 C11 之前，C 標準存在相互矛盾的要求：它們一方面說 errno 是一個宏，另一方面又說“errno 是一個宏還是一個具有外部連結的識別符號並未指定”。C11 修正了這一點，要求它必須被定義為一個宏（另見 WG14 N1338 ）。

### Example

Run this code

```c
#include <errno.h> #include <math.h> #include <stdio.h> void show_errno(void) {  const char *err_info = "unknown error";  switch (errno)  {  case EDOM:  err_info = "domain error";  break;  case EILSEQ:  err_info = "illegal sequence";  break;  case ERANGE:  err_info = "pole or range error";  break;  case 0:  err_info = "no error";  }  fputs(err_info, stdout);  puts(" occurred"); }   int main(void) {  fputs("MATH_ERRNO is ", stdout);  puts(math_errhandling & MATH_ERRNO ? "set" : "not set");  errno = 0;  (void)(1.0 / 0.0);  show_errno();  errno = 0;  (void)acos(+1.1);  show_errno();  errno = 0;  (void)log(0.0);  show_errno();  errno = 0;  (void)sin(0.0);  show_errno(); }
```

Possible output:
可能的輸出：

```c
MATH_ERRNO is set no error occurred domain error occurred pole or range error occurred no error occurred
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.5 Errors <errno.h> (p: TBD)
7.5 錯誤 <errno.h>（頁：TBD）
7.5 錯誤 <errno.h>（頁：TBD）

- K.3.1.3 Use of errno (p: TBD)
K.3.1.3 errno 的使用（頁：TBD）
K.3.1.3 errno 的使用（頁：TBD）

- K.3.2 Errors <errno.h> (p: TBD)
K.3.2 錯誤 <errno.h>（頁：TBD）
K.3.2 錯誤 <errno.h>（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.5 Errors <errno.h> (p: TBD)
7.5 錯誤 <errno.h>（頁：TBD）
7.5 錯誤 <errno.h>（頁：TBD）

- K.3.1.3 Use of errno (p: TBD)
K.3.1.3 errno 的使用（頁：TBD）
K.3.1.3 errno 的使用（頁：TBD）

- K.3.2 Errors <errno.h> (p: TBD)
K.3.2 錯誤 <errno.h>（頁：TBD）
K.3.2 錯誤 <errno.h>（頁：TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.5 Errors <errno.h> (p: 205)
7.5 錯誤 <errno.h>（頁：205）
7.5 錯誤 <errno.h>（頁：205）

- K.3.1.3 Use of errno (p: 584)
K.3.1.3 errno 的使用（頁：584）
K.3.1.3 errno 的使用（頁：584）

- K.3.2 Errors <errno.h> (p: 585)
K.3.2 錯誤 <errno.h>（頁：585）
K.3.2 錯誤 <errno.h>（頁：585）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.5 Errors <errno.h> (p: 186)
7.5 錯誤 <errno.h>（頁：186）
7.5 錯誤 <errno.h>（頁：186）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.1.3 Errors <errno.h>
4.1.3 錯誤 <errno.h>
4.1.3 錯誤 <errno.h>

### See also

E2BIG, EACCES, ..., EXDEV
|   | macros for standard POSIX-compatible error conditions
(macro constant)   |

perror
|   | displays a character string corresponding of the current error to stderr
(function)   |

strerrorstrerror_sstrerrorlen_s
(C11)(C11)
|   | returns a text version of a given error code
(function)   |

math_errhandlingMATH_ERRNOMATH_ERREXCEPT
(C99)(C99)(C99)
|   | defines the error handling mechanism used by the common mathematical functions
(macro constant)   |

C++ documentation for errno

---
來源頁路徑：`en.cppreference.com/c/error/errno.html`
