# raise

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<signal.h>`
|   |  |   |  |

```c
int raise( int sig );
```
|   |   |   |   |

|  |  |  |  |

Sends signal sig to the program. The signal handler, specified using signal(), is invoked.
向程式傳送訊號 sig 。呼叫使用 signal() 指定的訊號處理程式。
If the user-defined signal handling strategy is not set using signal() yet, it is implementation-defined whether the signal will be ignored or default handler will be invoked.
如果尚未使用 signal() 設定使用者定義的訊號處理策略，則訊號是被忽略還是呼叫預設處理程式由實現定義。

### Parameters

| sig  |   | -  |   | the signal to be sent. It can be an implementation-defined value or one of the following values:

SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM
|   | defines signal types
(macro constant)   |

### Return value

`0` upon success, non-zero value on failure.
成功時傳回 0，失敗時傳回非零值。

### Example

Run this code

```c
#include <signal.h> #include <stdio.h>   void signal_handler(int signal) {  printf("Received signal %d\n", signal); }   int main(void) {  // Install a signal handler.  signal(SIGTERM, signal_handler);    printf("Sending signal %d\n", SIGTERM);  raise(SIGTERM);  printf("Exit main()\n"); }
```

Output:

```c
Sending signal 15 Received signal 15 Exit main()
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.14.2.1 The raise function (p: 194-195)
7.14.2.1 raise 函式（頁碼：194-195）
7.14.2.1 raise 函式（頁碼：194-195）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.14.2.1 The raise function (p: 267)
7.14.2.1 raise 函式（頁碼：267）
7.14.2.1 raise 函式（頁碼：267）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.14.2.1 The raise function (p: 248)
7.14.2.1 raise 函式（頁碼：248）
7.14.2.1 raise 函式（頁碼：248）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.7.2.1 The raise function
4.7.2.1 raise 函式
4.7.2.1 raise 函式

### See also

signal
|   | sets a signal handler for particular signal
(function)   |

C++ documentation for raise

---
來源頁路徑：`en.cppreference.com/c/program/raise.html`
