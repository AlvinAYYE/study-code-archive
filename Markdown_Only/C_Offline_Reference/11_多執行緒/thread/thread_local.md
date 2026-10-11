# thread_local

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
#define thread_local _Thread_local
```
|   |   |   |  (since C11)
(removed in C23)  |

|  |  |  |  |

Convenience macro which can be used to specify that an object has thread-local storage duration.
可用於指定物件具有執行緒區域性儲存生存期的便捷宏。

### Notes

Since C23, `thread_local` is itself a keyword, which may also be a predefined macro, so `<threads.h>` no longer provides it.
自 C23 起，thread_local 本身是一個關鍵字，它也可能是一個預定義宏，因此 <threads.h> 不再提供它。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.1/3 thread_local (p: 274)
7.26.1/3 thread_local（頁：274）
7.26.1/3 thread_local（頁：274）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.1/3 thread_local (p: 376)
7.26.1/3 thread_local（頁：376）
7.26.1/3 thread_local（頁：376）

### See also

C++ documentation for thread_local

---
來源頁路徑：`en.cppreference.com/c/thread/thread_local.html`
