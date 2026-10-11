# cnd_broadcast

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int cnd_broadcast( cnd_t *cond );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Unblocks all threads that are blocked on condition variable `cond` at the time of the call. If no threads are blocked on `cond`, the function does nothing and returns `thrd_success`.
喚醒所有正在 cond 條件變數上等待的執行緒。若沒有執行緒在等待，函式不會做任何事，並傳回 thrd_success。

### Parameters

| cond  |   | -  |   | pointer to a condition variable  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.3.1 The cnd_broadcast function (p: 275-276)
7.26.3.1 cnd_broadcast 函式（頁：275-276）
7.26.3.1 cnd_broadcast 函式（頁：275-276）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.3.1 The cnd_broadcast function (p: 378)
7.26.3.1 cnd_broadcast 函式（頁：378）
7.26.3.1 cnd_broadcast 函式（頁：378）

### See also

cnd_signal
(C11)
|   | unblocks one thread blocked on a condition variable
(function)   |

C++ documentation for condition_variable::notify_all

C++ documentation for condition_variable_any::notify_all

---
來源頁路徑：`en.cppreference.com/c/thread/cnd_broadcast.html`
