# quick_exit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
_Noreturn void quick_exit( int exit_code );
```
|   |   |   | (since C11)
(until C23) |

```c
[[noreturn]] void quick_exit( int exit_code );
```
|   |   |   | (since C23) |

|  |  |  |  |

Causes normal program termination to occur without completely cleaning the resources.
導致程式正常終止，但不完全清理資源。
Functions passed to at_quick_exit are called in reverse order of their registration. After calling the registered functions, calls `_Exit(exit_code)`.
傳遞給 at_quick_exit 的函式按其註冊順序的逆序被呼叫。呼叫完已註冊的函式後，呼叫 _Exit ( exit_code ) 。
Functions passed to atexit or signal handlers passed to signal are not called.
傳遞給 atexit 的函式或傳遞給 signal 的訊號處理程式不會被呼叫。

### Parameters

| exit_code  |   | -  |   | exit status of the program  |

### Return value

(none)

### Example

Run this code

```c
#include <stdlib.h> #include <stdio.h>   void f1(void) {  puts("pushed first");  fflush(stdout); }   void f2(void) {  puts("pushed second"); } void f3(void) {  puts("won't be called"); }   int main(void) {  at_quick_exit(f1);  at_quick_exit(f2);  atexit(f3);  quick_exit(0); }
```

Output:

```c
pushed second pushed first
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.4.7 The quick_exit function (p: 257)
7.22.4.7 quick_exit 函式（頁碼：257）
7.22.4.7 quick_exit 函式（頁碼：257）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.4.7 The quick_exit function (p: 353)
7.22.4.7 quick_exit 函式（頁碼：353）
7.22.4.7 quick_exit 函式（頁碼：353）

### See also

abort
|   | causes abnormal program termination (without cleaning up)
(function)   |

atexit
|   | registers a function to be called on exit() invocation
(function)   |

at_quick_exit
(C11)
|   | registers a function to be called on quick_exit invocation
(function)   |

C++ documentation for quick_exit

---
來源頁路徑：`en.cppreference.com/c/program/quick_exit.html`
