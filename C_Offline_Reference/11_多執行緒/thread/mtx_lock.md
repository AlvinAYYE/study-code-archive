# mtx_lock

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int mtx_lock( mtx_t* mutex );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Blocks the current thread until the mutex pointed to by `mutex` is locked.
目前的執行緒會等待，直到 mutex 指向的互斥鎖可供鎖定。
The behavior is undefined if the current thread has already locked the mutex and the mutex is not recursive.
如果目前執行緒已經鎖定了該互斥量且該互斥量不是遞迴的，則屬於未定義行為。
Prior calls to mtx_unlock on the same mutex *synchronize-with* this operation, and all lock/unlock operations on any given mutex form a single total order (similar to the modification order of an atomic)
之前對同一互斥量呼叫的 mtx_unlock 與該操作同步，且對任何給定互斥量的所有加鎖/解鎖操作構成一個單一的全序（類似於原子操作的修改順序）

### Parameters

| mutex  |   | -  |   | pointer to the mutex to lock  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.4.3 The mtx_lock function (p: 278)
7.26.4.3 mtx_lock 函式（頁：278）
7.26.4.3 mtx_lock 函式（頁：278）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.4.3 The mtx_lock function (p: 381)
7.26.4.3 mtx_lock 函式（頁：381）
7.26.4.3 mtx_lock 函式（頁：381）

### See also

mtx_timedlock
(C11)
|   | blocks until locks a mutex or times out
(function)   |

mtx_trylock
(C11)
|   | locks a mutex or returns without blocking if already locked
(function)   |

mtx_unlock
(C11)
|   | unlocks a mutex
(function)   |

C++ documentation for mutex::lock

C++ documentation for timed_mutex::lock

C++ documentation for recursive_mutex::lock

C++ documentation for recursive_timed_mutex::lock

---
來源頁路徑：`en.cppreference.com/c/thread/mtx_lock.html`
