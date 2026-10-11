# thrd_success, thrd_timedout, thrd_busy, thrd_nomem, thrd_error

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
enum {  thrd_success = /* unspecified */,  thrd_nomem = /* unspecified */,  thrd_timedout = /* unspecified */,  thrd_busy = /* unspecified */,  thrd_error = /* unspecified */ };
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Identifiers for thread states and errors.
執行緒狀態和錯誤的識別符號。

| Constant  |   | Explanation  |

| `thrd_success`  |   | indicates successful return value  |

| `thrd_nomem`  |   | indicates unsuccessful return value due to out of memory condition  |

| `thrd_timedout`  |   | indicates timed out return value  |

| `thrd_busy`  |   | indicates unsuccessful return value due to resource temporary unavailable  |

| `thrd_error`  |   | indicates unsuccessful return value  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.1/5 thrd_success, thrd_timedout, ... (p: 275)
7.26.1/5 thrd_success、thrd_timedout、...（頁：275）
7.26.1/5 thrd_success、thrd_timedout、...（頁：275）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.1/5 thrd_success, thrd_timedout, ... (p: 377)
7.26.1/5 thrd_success、thrd_timedout、...（頁：377）
7.26.1/5 thrd_success、thrd_timedout、...（頁：377）

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_errors.html`
