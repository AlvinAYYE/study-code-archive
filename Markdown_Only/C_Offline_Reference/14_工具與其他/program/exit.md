# exit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void exit( int exit_code );
```
|   |   |   | (until C11) |

```c
_Noreturn void exit( int exit_code );
```
|   |   |   | (since C11)
(until C23) |

```c
[[noreturn]] void exit( int exit_code );
```
|   |   |   | (since C23) |

|  |  |  |  |

Causes normal program termination to occur.
導致程式正常終止。
Several cleanup steps are performed:
執行幾個清理步驟：

- functions passed to atexit are called, in reverse order of registration
傳遞給 atexit 的函式按註冊順序的逆序被呼叫

- all C streams are flushed and closed
所有 C 流被重新整理並關閉

- files created by tmpfile are removed
由 tmpfile 建立的檔案被刪除

- control is returned to the host environment. If `exit_code` is zero or EXIT_SUCCESS, an implementation-defined status indicating successful termination is returned. If `exit_code` is EXIT_FAILURE, an implementation-defined status indicating unsuccessful termination is returned. In other cases implementation-defined status value is returned.
控制權會返回宿主環境。若 exit_code 為 0 或 EXIT_SUCCESS，會回傳由實作定義、表示正常結束的狀態；若為 EXIT_FAILURE，則回傳表示異常結束的狀態。其他值的回傳狀態也由實作決定。

### Notes

The functions registered with at_quick_exit are not called.
用 at_quick_exit 註冊的函式不會被呼叫。
The behavior is undefined if a program calls `exit` more than once, or if it calls `exit` and quick_exit
如果程式多次呼叫 exit ，或同時呼叫 exit 和 quick_exit ，則行為未定義
The behavior is undefined if during a call to a function registered with atexit, the function exits with longjmp.
如果在呼叫用 atexit 註冊的函式期間，該函式透過 longjmp 退出，則行為未定義。
Returning from the the main function, either by a `return` statement or by reaching the end of the function, executes `exit()`, passing the argument of the return statement (or `0` if implicit return was used) as `exit_code`.
從 main 函式返回時（無論執行 return，或執行到函式結尾），都會呼叫 exit()。return 的引數會作為 exit_code 傳入；若隱含返回，則傳入 0。

### Parameters

| exit_code  |   | -  |   | exit status of the program  |

### Return value

(none)

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  FILE *fp = fopen("data.txt","r");  if (fp == NULL)  {  fprintf(stderr, "error opening file data.txt in function main()\n");  exit( EXIT_FAILURE );  }  fclose(fp);  printf("Normal Return\n");  return EXIT_SUCCESS ; }
```

Possible output:
可能的輸出：

```c
error opening file data.txt in function main()
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.4.4 The exit function (p: 256)
7.22.4.4 exit 函式（頁碼：256）
7.22.4.4 exit 函式（頁碼：256）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.4.4 The exit function (p: 351-352)
7.22.4.4 exit 函式（頁碼：351-352）
7.22.4.4 exit 函式（頁碼：351-352）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.4.3 The exit function (p: 315-316)
7.20.4.3 exit 函式（頁碼：315-316）
7.20.4.3 exit 函式（頁碼：315-316）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.4.3 The exit function
4.10.4.3 exit 函式
4.10.4.3 exit 函式

### See also

abort
|   | causes abnormal program termination (without cleaning up)
(function)   |

atexit
|   | registers a function to be called on exit() invocation
(function)   |

quick_exit
(C11)
|   | causes normal program termination without completely cleaning up
(function)   |

C++ documentation for exit

---
來源頁路徑：`en.cppreference.com/c/program/exit.html`
