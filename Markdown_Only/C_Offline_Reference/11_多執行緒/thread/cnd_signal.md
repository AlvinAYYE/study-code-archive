# cnd_signal

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int cnd_signal( cnd_t *cond );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Unblocks one thread that currently waits on condition variable pointed to by `cond`. If no threads are blocked, does nothing and returns `thrd_success`.
喚醒一個正在 cond 指向的條件變數上等待的執行緒。若沒有執行緒在等待，函式不會做任何事，並傳回 thrd_success。

### Parameters

| cond  |   | -  |   | pointer to a condition variable  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.3.4 The cnd_signal function (p: 276)
7.26.3.4 cnd_signal 函式（頁：276）
7.26.3.4 cnd_signal 函式（頁：276）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.3.4 The cnd_signal function (p: 379)
7.26.3.4 cnd_signal 函式（頁：379）
7.26.3.4 cnd_signal 函式（頁：379）

### See also

cnd_broadcast
(C11)
|   | unblocks all threads blocked on a condition variable
(function)   |

C++ documentation for condition_variable::notify_one

C++ documentation for condition_variable_any::notify_one

---
來源頁路徑：`en.cppreference.com/c/thread/cnd_signal.html`
