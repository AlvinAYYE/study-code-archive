# _Exit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
void _Exit( int exit_code );
```
|   |   |   | (since C99)
(until C11) |

```c
_Noreturn void _Exit( int exit_code );
```
|   |   |   | (since C11)
(until C23) |

```c
[[noreturn]] void _Exit( int exit_code );
```
|   |   |   | (since C23) |

|  |  |  |  |

Causes normal program termination to occur without completely cleaning the resources.
導致程式正常終止，但不完全清理資源。
Functions passed to at_quick_exit() or atexit() are not called. Whether open streams with unwritten buffered data are flushed, open streams are closed, or temporary files are removed is implementation-defined.
傳遞給 at_quick_exit() 或 atexit() 的函式不會被呼叫。是否重新整理含有未寫入緩衝資料的開啟流、是否關閉開啟流、是否刪除臨時檔案由實現定義。
If `exit_code` is 0 or EXIT_SUCCESS, an implementation-defined status indicating successful termination is returned to the host environment. If `exit_code` is EXIT_FAILURE, an implementation-defined status, indicating *unsuccessful* termination, is returned. In other cases an implementation-defined status value is returned.
如果 exit_code 為 0 或 EXIT_SUCCESS ，則向宿主環境傳回一個表示成功終止的實現定義狀態。如果 exit_code 為 EXIT_FAILURE ，則傳回一個表示不成功終止的實現定義狀態。其他情況下傳回實現定義的狀態值。

### Parameters

| exit_code  |   | -  |   | exit status of the program  |

### Return value

(none)

### Example

Run this code

```c
#include <stdlib.h> #include <stdio.h> /* _Exit does not call functions registered with atexit. */ void f1(void) {  puts("pushed first"); }   void f2(void) {  puts("pushed second"); }   int main(void) {  printf("Enter main()\n");  atexit(f1);  atexit(f2);  fflush(stdout); /* _Exit may not flush unwritten buffered data */  _Exit(0); }
```

Output:

```c
Enter main()
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.22.4.5 The _Exit function (p: 256)
7.22.4.5 _Exit 函式（頁碼：256）
7.22.4.5 _Exit 函式（頁碼：256）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.22.4.5 The _Exit function (p: 352)
7.22.4.5 _Exit 函式（頁碼：352）
7.22.4.5 _Exit 函式（頁碼：352）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.20.4.4 The _Exit function (p: 316)
7.20.4.4 _Exit 函式（頁碼：316）
7.20.4.4 _Exit 函式（頁碼：316）

### See also

abort
|   | causes abnormal program termination (without cleaning up)
(function)   |

exit
|   | causes normal program termination with cleaning up
(function)   |

C++ documentation for _Exit

---
來源頁路徑：`en.cppreference.com/c/program/_Exit.html`
