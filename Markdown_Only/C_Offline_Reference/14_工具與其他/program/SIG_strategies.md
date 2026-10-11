# SIG_DFL, SIG_IGN

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<signal.h>`
|   |  |   |  |

```c
#define SIG_DFL /*implementation defined*/
```
|   |   |   |   |

```c
#define SIG_IGN /*implementation defined*/
```
|   |   |   |   |

|  |  |  |  |

The SIG_DFL and SIG_IGN macros expand into integral expressions that are not equal to an address of any function. The macros define signal handling strategies for `signal()` function.
SIG_DFL 和 SIG_IGN 宏展開為不等於任何函式位址的整數表示式。這些宏為 signal () 函式定義訊號處理策略。

| Constant  |   | Explanation  |

| `SIG_DFL`  |   | default signal handling  |

| `SIG_IGN`  |   | signal is ignored  |

### Example

Run this code

```c
#include <signal.h> #include <stdio.h>   int main(void) {  /* using the default signal handler */  raise(SIGTERM);  printf("Exit main()\n"); /* never reached */ }
```

Output:

```c
(none)
```

### Example

Run this code

```c
#include <signal.h> #include <stdio.h>   int main(void) {  /* ignoring the signal */  signal(SIGTERM, SIG_IGN);  raise(SIGTERM);  printf("Exit main()\n"); }
```

Output:

```c
Exit main()
```

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

C++ documentation for SIG_DFL, SIG_IGN

---
來源頁路徑：`en.cppreference.com/c/program/SIG_strategies.html`
