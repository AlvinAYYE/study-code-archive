# SIG_ERR

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<signal.h>`
|   |  |   |  |

```c
#define SIG_ERR /* implementation defined */
```
|   |   |   |   |

|  |  |  |  |

A value of type `void (*)(int)`. When returned by signal, indicates that an error has occurred.
一個型別為 void (*)(int) 的值。當由 signal 傳回時，表示發生了錯誤。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> #include <signal.h>   void signal_handler(int sig) {  printf("Received signal: %d\n", sig); }   int main(void) {  /* Install a signal handler. */  if (signal(SIGTERM, signal_handler) == SIG_ERR)  {  printf("Error while installing a signal handler.\n");  exit(EXIT_FAILURE);  }    printf("Sending signal: %d\n", SIGTERM);  if (raise(SIGTERM) != 0)  {  printf("Error while raising the SIGTERM signal.\n");  exit(EXIT_FAILURE);  }    printf("Exit main()\n");  return EXIT_SUCCESS; }
```

Output:

```c
Sending signal: 15 Received signal: 15 Exit main()
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.14/3 Signal handling <signal.h> (p: 194)
7.14/3 訊號處理 <signal.h> （頁碼：194）
7.14/3 訊號處理 <signal.h> （頁碼：194）

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

C++ documentation for SIG_ERR

---
來源頁路徑：`en.cppreference.com/c/program/SIG_ERR.html`
