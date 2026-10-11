# longjmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<setjmp.h>`
|   |  |   |  |

```c
void longjmp( jmp_buf env, int status );
```
|   |   |   | (until C11) |

```c
_Noreturn void longjmp( jmp_buf env, int status );
```
|   |   |   | (since C11)
(until C23) |

```c
[[noreturn]] void longjmp( jmp_buf env, int status );
```
|   |   |   | (since C23) |

|  |  |  |  |

Loads the execution context `env` saved by a previous call to setjmp. This function does not return. Control is transferred to the call site of the macro setjmp that set up `env`. That setjmp then returns the value, passed as the `status`.
載入先前呼叫 setjmp 儲存的執行上下文 env 。此函式不傳回。控制權轉移到設定 env 的 setjmp 宏的呼叫點。然後該 setjmp 傳回作為 status 傳遞的值。
If the function that called setjmp has exited (whether by return or by a different `longjmp` higher up the stack), the behavior is undefined. In other words, only long jumps up the call stack are allowed.
如果呼叫 setjmp 的函式已經退出（無論是透過 return 還是透過呼叫棧更高處的另一個 longjmp ），則行為未定義。換句話說，只允許向呼叫棧上方進行長跳轉。

Jumping across threads (if the function that called `setjmp` was executed by another thread) is also undefined behavior.
|   | (since C11) |

If when setjmp was called, a VLA or another variably-modified type variable was in scope and control left that scope, `longjmp` to that `setjmp` invokes undefined behavior even if control remained within the function.
On the way up the stack, `longjmp` does not deallocate any VLAs, memory leaks may occur if their lifetimes are terminated in this way:

```c
void g(int n) {  int a[n]; // a may remain allocated  h(n); // does not return } void h(int n) {  int b[n]; // b may remain allocated  longjmp(buf, 2); // might cause a memory leak for h's b and g's a }
```
|   | (since C99) |

### Parameters

| env  |   | -  |   | variable referring to the execution state of the program saved by setjmp  |

| status  |   | -  |   | the value to return from setjmp. If it is equal to `0`, `1` is used instead  |

### Notes

`longjmp` is intended for handling unexpected error conditions where the function cannot return meaningfully. This is similar to exception handling in other programming languages.
longjmp 旨在處理函式無法有意義地傳回的意外錯誤情況。這類似於其他程式語言中的異常處理。

### Example

Run this code

```c
#include <setjmp.h> #include <stdio.h> #include <stdnoreturn.h> jmp_buf my_jump_buffer; noreturn void foo(int status) {  printf("foo(%d) called\n", status);  longjmp(my_jump_buffer, status + 1); // will return status+1 out of setjmp } int main(void) {  volatile int count = 0; // modified local vars in setjmp scope must be volatile  if (setjmp(my_jump_buffer) != 5) // compare against constant in an if  foo(++count); }
```

Output:

```c
foo(1) called foo(2) called foo(3) called foo(4) called
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.13.2.1 The longjmp macro (p: 283-284)
7.13.2.1 longjmp 宏（頁碼：283-284）
7.13.2.1 longjmp 宏（頁碼：283-284）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.13.2.1 The longjmp macro (p: 191-192)
7.13.2.1 longjmp 宏（頁碼：191-192）
7.13.2.1 longjmp 宏（頁碼：191-192）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.13.2.1 The longjmp macro (p: 263-264)
7.13.2.1 longjmp 宏（頁碼：263-264）
7.13.2.1 longjmp 宏（頁碼：263-264）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.13.2.1 The longjmp macro (p: 244-245)
7.13.2.1 longjmp 宏（頁碼：244-245）
7.13.2.1 longjmp 宏（頁碼：244-245）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.6.2.1 The longjmp function
4.6.2.1 longjmp 函式
4.6.2.1 longjmp 函式

### See also

setjmp
|   | saves the context
(function macro)   |

C++ documentation for longjmp

---
來源頁路徑：`en.cppreference.com/c/program/longjmp.html`
