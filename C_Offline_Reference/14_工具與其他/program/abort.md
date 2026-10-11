# abort

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void abort(void);
```
|   |   |   | (until C11) |

```c
_Noreturn void abort(void);
```
|   |   |   | (since C11)
(until C23) |

```c
[[noreturn]] void abort(void);
```
|   |   |   | (since C23) |

|  |  |  |  |

Causes abnormal program termination unless SIGABRT is being caught by a signal handler passed to signal and the handler does not return.
導致程式異常終止，除非 SIGABRT 被傳遞給 signal 的訊號處理程式捕獲且該處理程式不傳回。
Functions passed to atexit() are not called. Whether open resources such as files are closed is implementation defined. An implementation defined status is returned to the host environment that indicates unsuccessful execution.
傳遞給 atexit() 的函式不會被呼叫。是否關閉檔案等開啟的資源由實現定義。向宿主環境傳回一個表示執行不成功的實現定義狀態。

### Parameters

(none)

### Return value

(none)

### Notes

POSIX specifies that the `abort()` function overrides blocking or ignoring the `SIGABRT` signal.
POSIX 規定 abort() 函式會覆蓋對 SIGABRT 訊號的阻塞或忽略。
Some compiler intrinsics, e.g. `__builtin_trap` (gcc, clang, and icc) or `__fastfail`/`__debugbreak` (msvc), can be used to terminate the program as fast as possible.
部分編譯器內建函式也能快速終止程式，例如 gcc、clang 和 icc 的 __builtin_trap，以及 msvc 的 __fastfail / __debugbreak。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  FILE *fp = fopen("data.txt","r");  if (fp == NULL)  {  fprintf(stderr, "error opening file data.txt in function main()\n");  abort();  }  /* Normal processing continues here. */  fclose(fp);  printf("Normal Return\n");  return 0; }
```

Output:

```c
error opening file data.txt in function main()
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.4.1 The abort function (p: 255)
7.22.4.1 abort 函式（頁碼：255）
7.22.4.1 abort 函式（頁碼：255）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.4.1 The abort function (p: 350)
7.22.4.1 abort 函式（頁碼：350）
7.22.4.1 abort 函式（頁碼：350）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.4.1 The abort function (p: 315)
7.20.4.1 abort 函式（頁碼：315）
7.20.4.1 abort 函式（頁碼：315）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.4.1 The abort function
4.10.4.1 abort 函式
4.10.4.1 abort 函式

### See also

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

C++ documentation for abort

---
來源頁路徑：`en.cppreference.com/c/program/abort.html`
