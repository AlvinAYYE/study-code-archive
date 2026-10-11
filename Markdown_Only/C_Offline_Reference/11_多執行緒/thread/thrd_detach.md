# thrd_detach

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int thrd_detach( thrd_t thr );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Detaches the thread identified by `thr` from the current environment. The resources held by the thread will be freed automatically once the thread exits.
將 thr 所識別的執行緒分離。該執行緒結束後，其佔用的資源會自動釋放。

### Parameters

| thr  |   | -  |   | identifier of the thread to detach  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.5.3 The thrd_detach function (p: 280)
7.26.5.3 thrd_detach 函式（頁：280）
7.26.5.3 thrd_detach 函式（頁：280）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.5.3 The thrd_detach function (p: 383-384)
7.26.5.3 thrd_detach 函式（頁：383-384）
7.26.5.3 thrd_detach 函式（頁：383-384）

### See also

thrd_join
(C11)
|   | blocks until a thread terminates
(function)   |

C++ documentation for detach

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_detach.html`
