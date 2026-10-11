# cnd_timedwait

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int cnd_timedwait( cnd_t* restrict cond, mtx_t* restrict mutex,  const struct timespec* restrict time_point );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Atomically unlocks the mutex pointed to by `mutex` and blocks on the condition variable pointed to by `cond` until the thread is signalled by cnd_signal or cnd_broadcast, or until the `TIME_UTC` based time point pointed to by `time_point` has been reached, or until a spurious wake-up occurs. The mutex is locked again before the function returns.
以不可分割的方式解鎖 mutex 指向的互斥鎖，並在 cond 指向的條件變數上等待，直到收到 cnd_signal 或 cnd_broadcast 的通知、到達 time_point 指定的 TIME_UTC 時間點，或發生虛假喚醒。函式傳回前會重新鎖定該互斥鎖。
The behavior is undefined if the mutex is not already locked by the calling thread.
如果該互斥量尚未被呼叫執行緒鎖定，則屬於未定義行為。

### Parameters

| cond  |   | -  |   | pointer to the condition variable to block on  |

| mutex  |   | -  |   | pointer to the mutex to unlock for the duration of the block  |

| time_point  |   | -  |   | pointer to an object specifying timeout time to wait until  |

### Return value

thrd_success if successful, `thrd_timedout` if the timeout time has been reached before the mutex is locked, or thrd_error if an error occurred.
成功時傳回 thrd_success；若重新鎖定互斥鎖前已逾時，傳回 thrd_timedout；若發生錯誤，則傳回 thrd_error。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.3.5 The cnd_timedwait function (p: 276-277)
7.26.3.5 cnd_timedwait 函式（頁：276-277）
7.26.3.5 cnd_timedwait 函式（頁：276-277）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.3.5 The cnd_timedwait function (p: 379-380)
7.26.3.5 cnd_timedwait 函式（頁：379-380）
7.26.3.5 cnd_timedwait 函式（頁：379-380）

### See also

cnd_wait
(C11)
|   | blocks on a condition variable
(function)   |

C++ documentation for condition_variable::wait_until

C++ documentation for condition_variable_any::wait_until

---
來源頁路徑：`en.cppreference.com/c/thread/cnd_timedwait.html`
