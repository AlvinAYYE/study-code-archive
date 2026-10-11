# SIGTERM, SIGSEGV, SIGINT, SIGILL, SIGABRT, SIGFPE

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<signal.h>`
|   |  |   |  |

```c
#define SIGTERM /*implementation defined*/
```
|   |   |   |   |

```c
#define SIGSEGV /*implementation defined*/
```
|   |   |   |   |

```c
#define SIGINT /*implementation defined*/
```
|   |   |   |   |

```c
#define SIGILL /*implementation defined*/
```
|   |   |   |   |

```c
#define SIGABRT /*implementation defined*/
```
|   |   |   |   |

```c
#define SIGFPE /*implementation defined*/
```
|   |   |   |   |

|  |  |  |  |

Each of the above macro constants expands to an integer constant expression with distinct values, which represent different signals sent to the program.
上述每個宏常量展開為具有不同值的整數常量表示式，代表傳送給程式的不同訊號。

| Constant  |   | Explanation  |

| `SIGTERM`  |   | termination request, sent to the program  |

| `SIGSEGV`  |   | invalid memory access (segmentation fault)  |

| `SIGINT`  |   | external interrupt, usually initiated by the user  |

| `SIGILL`  |   | invalid program image, such as invalid instruction  |

| `SIGABRT`  |   | abnormal termination condition, as is e.g. initiated by abort()  |

| `SIGFPE`  |   | erroneous arithmetic operation such as divide by zero  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.14/3 Signal handling <signal.h> (p: 193)
7.14/3 訊號處理 <signal.h> （頁碼：193）
7.14/3 訊號處理 <signal.h> （頁碼：193）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.14/3 Signal handling <signal.h> (p: 265)
7.14/3 訊號處理 <signal.h> （頁碼：265）
7.14/3 訊號處理 <signal.h> （頁碼：265）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.14/3 Signal handling <signal.h> (p: 246)
7.14/3 訊號處理 <signal.h> （頁碼：246）
7.14/3 訊號處理 <signal.h> （頁碼：246）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.7 SIGNAL HANDLING <signal.h>
4.7 訊號處理 <signal.h>
4.7 訊號處理 <signal.h>

### See also

signal
|   | sets a signal handler for particular signal
(function)   |

raise
|   | runs the signal handler for particular signal
(function)   |

C++ documentation for signal types

---
來源頁路徑：`en.cppreference.com/c/program/SIG_types.html`
