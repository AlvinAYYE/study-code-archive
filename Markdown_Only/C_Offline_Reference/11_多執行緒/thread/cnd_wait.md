# cnd_wait

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int cnd_wait( cnd_t* cond, mtx_t* mutex );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Atomically unlocks the mutex pointed to by `mutex` and blocks on the condition variable pointed to by `cond` until the thread is signalled by cnd_signal or cnd_broadcast, or until a spurious wake-up occurs. The mutex is locked again before the function returns.
以不可分割的方式解鎖 mutex 指向的互斥鎖，並在 cond 指向的條件變數上等待，直到收到 cnd_signal 或 cnd_broadcast 的通知，或發生虛假喚醒。函式傳回前會重新鎖定該互斥鎖。
The behavior is undefined if the mutex is not already locked by the calling thread.
如果該互斥量尚未被呼叫執行緒鎖定，則屬於未定義行為。

### Parameters

| cond  |   | -  |   | pointer to the condition variable to block on  |

| mutex  |   | -  |   | pointer to the mutex to unlock for the duration of the block  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.3.6 The cnd_wait function (p: 277)
7.26.3.6 cnd_wait 函式（頁：277）
7.26.3.6 cnd_wait 函式（頁：277）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.3.6 The cnd_wait function (p: 380)
7.26.3.6 cnd_wait 函式（頁：380）
7.26.3.6 cnd_wait 函式（頁：380）

### See also

cnd_timedwait
(C11)
|   | blocks on a condition variable, with a timeout
(function)   |

C++ documentation for condition_variable::wait

C++ documentation for condition_variable_any::wait

---
來源頁路徑：`en.cppreference.com/c/thread/cnd_wait.html`
