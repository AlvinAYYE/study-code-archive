# sig_atomic_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<signal.h>`
|   |  |   |  |

```c
typedef /* unspecified */ sig_atomic_t;
```
|   |   |   |   |

|  |  |  |  |

An integer type which can be accessed as an atomic entity even in the presence of asynchronous interrupts made by signals.
一種整數型別，即使存在由訊號引起的非同步中斷，也可以作為原子實體訪問。

### Example

Run this code

```c
#include <signal.h> #include <stdio.h> volatile sig_atomic_t gSignalStatus = 0; void signal_handler(int status) {  gSignalStatus = status; } int main(void) {  /* Install a signal handler. */  signal(SIGINT, signal_handler);  printf("SignalValue: %d\n", gSignalStatus);  printf("Sending signal: %d\n", SIGINT);  raise(SIGINT);  printf("SignalValue: %d\n", gSignalStatus); }
```

Possible output:
可能的輸出：

```c
SignalValue: 0 Sending signal: 2 SignalValue: 2
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.14/2 Signal handling <signal.h> (p: 194-195)
7.14/2 訊號處理 <signal.h> （頁碼：194-195）
7.14/2 訊號處理 <signal.h> （頁碼：194-195）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.14/2 Signal handling <signal.h> (p: 265)
7.14/2 訊號處理 <signal.h> （頁碼：265）
7.14/2 訊號處理 <signal.h> （頁碼：265）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.14/2 Signal handling <signal.h> (p: 246)
7.14/2 訊號處理 <signal.h> （頁碼：246）
7.14/2 訊號處理 <signal.h> （頁碼：246）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.7 SIGNAL HANDLING <signal.h>
4.7 訊號處理 <signal.h>
4.7 訊號處理 <signal.h>

### See also

signal
|   | sets a signal handler for particular signal
(function)   |

C++ documentation for sig_atomic_t

---
來源頁路徑：`en.cppreference.com/c/program/sig_atomic_t.html`
