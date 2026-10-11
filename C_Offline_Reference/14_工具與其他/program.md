# 程式支援工具

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Program termination
程式終止

The following functions manage program termination and resources cleanup.
以下函式用來結束程式並清理資源。

Defined in header `<stdlib.h>`

abort
|   | 異常終止程式，不執行一般的清理程序
(function)   |

exit
|   | 正常終止程式，並執行已登記的清理程序
(function)   |

quick_exit
(C11)
|   | 正常終止程式，但不執行完整的清理程序
(function)   |

_Exit
(C99)
|   | 正常終止程式，不執行清理程序
(function)   |

atexit
|   | 登記一個在呼叫 `exit` 時執行的函式
(function)   |

at_quick_exit
(C11)
|   | 登記一個在呼叫 `quick_exit` 時執行的函式
(function)   |

EXIT_SUCCESSEXIT_FAILURE
|   | 表示程式執行成功或失敗
(macro constant)   |

### Unreachable control flow
不可達控制流

Defined in header `<stddef.h>`

unreachable
(C23)
|   | 標示程式不應執行到的位置
(function macro)   |

### Communicating with the environment
與環境通訊

Defined in header `<stdlib.h>`

system
|   | 呼叫主機環境的命令處理器
(function)   |

getenvgetenv_s
(C11)
|   | 存取環境變數
(function)   |

### Memory alignment query
記憶體對齊查詢

Defined in header `<stdlib.h>`

memalignment
(C23)
|   | 查詢指標值所指物件的對齊需求
(function)   |

### Signals

本標頭檔提供數個訊號處理函式與巨集常數。

Defined in header `<signal.h>`

signal
|   | 為指定訊號設定處理常式
(function)   |

raise
|   | 對指定訊號呼叫處理常式
(function)   |

sig_atomic_t
|   | 可在非同步訊號處理常式中以原子方式存取的整數型別
(typedef)  |

SIG_DFLSIG_IGN
|   | 指定訊號處理方式
(macro constant)   |

SIG_ERR
|   | 表示發生錯誤
(macro constant)   |

#####  Signal types

SIGABRTSIGFPESIGILLSIGINTSIGSEGVSIGTERM
|   | 列出訊號種類
(macro constant)   |

### Non-local jumps
非區域性跳轉

Defined in header `<setjmp.h>`

setjmp
|   | 儲存目前的執行環境
(function macro)   |

longjmp
|   | 跳回先前儲存的執行位置
(function)   |

#####  Types

jmp_buf
|   | 儲存執行環境所用的型別
(typedef)   |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.13 Non-local jumps <setjmp.h> (p: 283-284)
7.13 非區域性跳轉 <setjmp.h> （頁碼：283-284）
7.13 非區域性跳轉 <setjmp.h> （頁碼：283-284）

- 7.14 Signal handling <signal.h> (p: 285-287)
7.14 訊號處理 <signal.h> （頁碼：285-287）
7.14 訊號處理 <signal.h> （頁碼：285-287）

- 7.24 General utilities <stdlib.h> (p: 356-374)
7.24 通用工具 <stdlib.h> （頁碼：356-374）
7.24 通用工具 <stdlib.h> （頁碼：356-374）

- 7.33.9 Signal handling <signal.h> (p: 458)
7.33.9 訊號處理 <signal.h> （頁碼：458）
7.33.9 訊號處理 <signal.h> （頁碼：458）

- 7.33.16 General utilities <stdlib.h> (p: 458)
7.33.16 通用工具 <stdlib.h> （頁碼：458）
7.33.16 通用工具 <stdlib.h> （頁碼：458）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.13 Nonlocal jumps <setjmp.h> (p: 191-192)
7.13 非區域性跳轉 <setjmp.h> （頁碼：191-192）
7.13 非區域性跳轉 <setjmp.h> （頁碼：191-192）

- 7.14 Signal handling <signal.h> (p: 193-195)
7.14 訊號處理 <signal.h> （頁碼：193-195）
7.14 訊號處理 <signal.h> （頁碼：193-195）

- 7.22 General utilities <stdlib.h> (p: 248-262)
7.22 通用工具 <stdlib.h> （頁碼：248-262）
7.22 通用工具 <stdlib.h> （頁碼：248-262）

- 7.31.7 Signal handling <signal.h> (p: 332)
7.31.7 訊號處理 <signal.h> （頁碼：332）
7.31.7 訊號處理 <signal.h> （頁碼：332）

- 7.31.12 General utilities <stdlib.h> (p: 333)
7.31.12 通用工具 <stdlib.h> （頁碼：333）
7.31.12 通用工具 <stdlib.h> （頁碼：333）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.13 Nonlocal jumps <setjmp.h> (p: 262-264)
7.13 非區域性跳轉 <setjmp.h> （頁碼：262-264）
7.13 非區域性跳轉 <setjmp.h> （頁碼：262-264）

- 7.14 Signal handling <signal.h> (p: 265-267)
7.14 訊號處理 <signal.h> （頁碼：265-267）
7.14 訊號處理 <signal.h> （頁碼：265-267）

- 7.22 General utilities <stdlib.h> (p: 340-360)
7.22 通用工具 <stdlib.h> （頁碼：340-360）
7.22 通用工具 <stdlib.h> （頁碼：340-360）

- 7.31.7 Signal handling <signal.h> (p: 455)
7.31.7 訊號處理 <signal.h> （頁碼：455）
7.31.7 訊號處理 <signal.h> （頁碼：455）

- 7.31.12 General utilities <stdlib.h> (p: 456)
7.31.12 通用工具 <stdlib.h> （頁碼：456）
7.31.12 通用工具 <stdlib.h> （頁碼：456）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.13 Nonlocal jumps <setjmp.h> (p: 243-245)
7.13 非區域性跳轉 <setjmp.h> （頁碼：243-245）
7.13 非區域性跳轉 <setjmp.h> （頁碼：243-245）

- 7.14 Signal handling <signal.h> (p: 246-248)
7.14 訊號處理 <signal.h> （頁碼：246-248）
7.14 訊號處理 <signal.h> （頁碼：246-248）

- 7.20 General utilities <stdlib.h> (p: 306-324)
7.20 通用工具 <stdlib.h> （頁碼：306-324）
7.20 通用工具 <stdlib.h> （頁碼：306-324）

- 7.26.6 Signal handling <signal.h> (p: 401)
7.26.6 訊號處理 <signal.h> （頁碼：401）
7.26.6 訊號處理 <signal.h> （頁碼：401）

- 7.26.10 General utilities <stdlib.h> (p: 402)
7.26.10 通用工具 <stdlib.h> （頁碼：402）
7.26.10 通用工具 <stdlib.h> （頁碼：402）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.6 NON-LOCAL JUMPS <setjmp.h>
4.6 非區域性跳轉 <setjmp.h>
4.6 非區域性跳轉 <setjmp.h>

- 4.7 SIGNAL HANDLING <signal.h>
4.7 訊號處理 <signal.h>
4.7 訊號處理 <signal.h>

- 4.10 GENERAL UTILITIES <stdlib.h>
4.10 通用工具 <stdlib.h>
4.10 通用工具 <stdlib.h>

- 4.13.5 Signal handling <signal.h>
4.13.5 訊號處理 <signal.h>
4.13.5 訊號處理 <signal.h>

- 7.13.7 General utilities <stdlib.h>
7.13.7 通用工具 <stdlib.h>
7.13.7 通用工具 <stdlib.h>

### See also

C++ documentation for Program support utilities

---
來源頁路徑：`en.cppreference.com/c/program.html`
