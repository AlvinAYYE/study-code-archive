# atexit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int atexit( void (*func)(void) );
```
|   |   |   |   |

|  |  |  |  |

Registers the function pointed to by `func` to be called on normal program termination (via exit() or returning from `main()`). The functions will be called in reverse order they were registered, i.e. the function registered last will be executed first.
註冊 func 指向的函式，以便在程式正常終止時呼叫（透過 exit() 或從 main() 傳回）。這些函式按註冊順序的逆序被呼叫，即最後註冊的函式最先執行。
The same function may be registered more than once.
同一個函式可以註冊多次。
The implementation is guaranteed to support the registration of at least `32` functions. The exact limit is implementation-defined.
保證實現支援至少註冊 32 個函式。確切限制由實現定義。

### Parameters

| func  |   | -  |   | pointer to a function to be called on normal program termination  |

### Return value

`0` if the registration succeeds, nonzero value otherwise.
如果註冊成功則傳回 0，否則傳回非零值。

### Example

Run this code

```c
#include <stdlib.h> #include <stdio.h> void f1(void) {  puts("f1"); } void f2(void) {  puts("f2"); } int main(void) {  if ( ! atexit(f1) && ! atexit(f2) && ! atexit(f2) )  return EXIT_SUCCESS ;  // atexit registration failed  return EXIT_FAILURE ; } // <- if registration was successful calls f2, f2, f1
```

Output:

```c
f2 f2 f1
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.4.2 The atexit function (p: 255)
7.22.4.2 atexit 函式（頁碼：255）
7.22.4.2 atexit 函式（頁碼：255）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.4.2 The atexit function (p: 350)
7.22.4.2 atexit 函式（頁碼：350）
7.22.4.2 atexit 函式（頁碼：350）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.4.2 The atexit function (p: 315)
7.20.4.2 atexit 函式（頁碼：315）
7.20.4.2 atexit 函式（頁碼：315）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 7.10.4.2 The atexit function (p: 156)
7.10.4.2 atexit 函式（頁碼：156）
7.10.4.2 atexit 函式（頁碼：156）

### See also

at_quick_exit
(C11)
|   | registers a function to be called on quick_exit invocation
(function)   |

C++ documentation for atexit

---
來源頁路徑：`en.cppreference.com/c/program/atexit.html`
