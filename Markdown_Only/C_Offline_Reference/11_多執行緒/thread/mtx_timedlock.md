# mtx_timedlock

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int mtx_timedlock( mtx_t *restrict mutex,  const struct timespec *restrict time_point );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Blocks the current thread until the mutex pointed to by `mutex` is locked or until the `TIME_UTC` based absolute calendar time point pointed to by `time_point` has been reached.
目前的執行緒會等待，直到 mutex 指向的互斥鎖可供鎖定，或到達 time_point 指定的 TIME_UTC 絕對時間。
Since this function takes an absolute time, if a duration is required, the calendar time point must be calculated manually.
由於此函式接受的是絕對時間，如果需要的是一段時長，則必須手動計算日曆時間點。
The behavior is undefined if the current thread has already locked the mutex and the mutex is not recursive.
如果目前執行緒已經鎖定了該互斥量且該互斥量不是遞迴的，則屬於未定義行為。
The behavior is undefined if the mutex does not support timeout.
如果該互斥量不支援超時，則屬於未定義行為。
Prior calls to mtx_unlock on the same mutex *synchronize-with* this operation (if this operation succeeds), and all lock/unlock operations on any given mutex form a single total order (similar to the modification order of an atomic)
之前對同一互斥量呼叫的 mtx_unlock 與該操作同步（如果該操作成功），且對任何給定互斥量的所有加鎖/解鎖操作構成一個單一的全序（類似於原子操作的修改順序）

### Parameters

| mutex  |   | -  |   | pointer to the mutex to lock  |

| time_point  |   | -  |   | pointer to the absolute calendar time until which to wait for the timeout  |

### Return value

thrd_success if successful, `thrd_timedout` if the timeout time has been reached before the mutex is locked, thrd_error if an error occurs.
成功則傳回 thrd_success ，如果在鎖定互斥量之前已達到超時時間則傳回 thrd_timedout ，如果發生錯誤則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.4.4 The mtx_timedlock function (p: 278)
7.26.4.4 mtx_timedlock 函式（頁：278）
7.26.4.4 mtx_timedlock 函式（頁：278）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.4.4 The mtx_timedlock function (p: 381-382)
7.26.4.4 mtx_timedlock 函式（頁：381-382）
7.26.4.4 mtx_timedlock 函式（頁：381-382）

### See also

timespec
(C11)
|   | time in seconds and nanoseconds
(struct)  |

mtx_lock
(C11)
|   | blocks until locks a mutex
(function)   |

mtx_trylock
(C11)
|   | locks a mutex or returns without blocking if already locked
(function)   |

mtx_unlock
(C11)
|   | unlocks a mutex
(function)   |

C++ documentation for timed_mutex::try_lock_until

C++ documentation for recursive_timed_mutex::try_lock_until

### External links

| GNU GCC Libc Manual: ISO-C-Mutexes  |

---
來源頁路徑：`en.cppreference.com/c/thread/mtx_timedlock.html`
