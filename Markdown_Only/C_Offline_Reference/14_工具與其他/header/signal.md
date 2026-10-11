# Standard library header <signal.h>

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of the program support library.
該標頭檔是程式支援庫的一部分。

### Types

sig_atomic_t
|   | the integer type that can be accessed as an atomic entity from an asynchronous signal handler
(typedef)  |

### Macros

SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM
|   | defines signal types
(macro constant)   |

SIG_DFLSIG_IGN
|   | defines signal handling strategies
(macro constant)   |

SIG_ERR
|   | error was encountered
(macro constant)   |

### Functions

signal
|   | sets a signal handler for particular signal
(function)   |

raise
|   | runs the signal handler for particular signal
(function)   |

### Synopsis

```c
typedef sig_atomic_t /* see description */; void (*signal(int sig, void (*func)(int)))(int); int raise(int sig); #define SIG_DFL /* see description */ #define SIG_ERR /* see description */ #define SIG_IGN /* see description */ #define SIGABRT /* see description */ #define SIGFPE /* see description */ #define SIGILL /* see description */ #define SIGINT /* see description */ #define SIGSEGV /* see description */ #define SIGTERM /* see description */
```

---
來源頁路徑：`en.cppreference.com/c/header/signal.html`
