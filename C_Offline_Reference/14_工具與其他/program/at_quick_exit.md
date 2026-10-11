# at_quick_exit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int at_quick_exit( void (*func)(void) );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Registers the function pointed to by `func` to be called on quick program termination (via quick_exit).
註冊 func 指向的函式，以便在程式快速終止時呼叫（透過 quick_exit ）。
Calling the function from several threads does not induce a data race. The implementation is guaranteed to support the registration of at least 32 functions. The exact limit is implementation-defined.
從多個執行緒呼叫該函式不會引發資料競爭。保證實現支援至少註冊 32 個函式。確切限制由實現定義。
The registered functions will not be called on normal program termination. If a function need to be called in that case, atexit must be used.
已註冊的函式在程式正常終止時不會被呼叫。如果在那種情況下需要呼叫某個函式，必須使用 atexit 。

### Parameters

| func  |   | -  |   | pointer to a function to be called on quick program termination  |

### Return value

`0` if the registration succeeds, nonzero value otherwise.
如果註冊成功則傳回 0，否則傳回非零值。

### Example

Run this code

```c
#include <stdlib.h> #include <stdio.h>   void f1(void) {  puts("pushed first");  fflush(stdout); }   void f2(void) {  puts("pushed second"); }   int main(void) {  at_quick_exit(f1);  at_quick_exit(f2);  quick_exit(0); }
```

Output:

```c
pushed second pushed first
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.4.3 The at_quick_exit function (p: 255)
7.22.4.3 at_quick_exit 函式（頁碼：255）
7.22.4.3 at_quick_exit 函式（頁碼：255）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.4.3 The at_quick_exit function (p: 351)
7.22.4.3 at_quick_exit 函式（頁碼：351）
7.22.4.3 at_quick_exit 函式（頁碼：351）

### See also

abort
|   | causes abnormal program termination (without cleaning up)
(function)   |

exit
|   | causes normal program termination with cleaning up
(function)   |

atexit
|   | registers a function to be called on exit() invocation
(function)   |

quick_exit
(C11)
|   | causes normal program termination without completely cleaning up
(function)   |

C++ documentation for at_quick_exit

---
來源頁路徑：`en.cppreference.com/c/program/at_quick_exit.html`
