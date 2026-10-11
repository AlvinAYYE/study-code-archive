# mtx_unlock

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int mtx_unlock( mtx_t *mutex );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Unlocks the mutex pointed to by `mutex`.
解除 mutex 指向的互斥鎖。
The behavior is undefined if the mutex is not locked by the calling thread.
如果該互斥量未被呼叫執行緒鎖定，則屬於未定義行為。
This function *synchronizes-with* subsequent mtx_lock, mtx_trylock, or mtx_timedlock on the same mutex. All lock/unlock operations on any given mutex form a single total order (similar to the modification order of an atomic).
此函式與隨後對同一互斥量的 mtx_lock 、 mtx_trylock 或 mtx_timedlock 同步。對任何給定互斥量的所有加鎖/解鎖操作構成一個單一的全序（類似於原子操作的修改順序）。

### Parameters

| mutex  |   | -  |   | pointer to the mutex to unlock  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.4.6 The mtx_unlock function (p: 279)
7.26.4.6 mtx_unlock 函式（頁：279）
7.26.4.6 mtx_unlock 函式（頁：279）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.4.6 The mtx_unlock function (p: 382)
7.26.4.6 mtx_unlock 函式（頁：382）
7.26.4.6 mtx_unlock 函式（頁：382）

### See also

mtx_lock
(C11)
|   | blocks until locks a mutex
(function)   |

mtx_timedlock
(C11)
|   | blocks until locks a mutex or times out
(function)   |

mtx_trylock
(C11)
|   | locks a mutex or returns without blocking if already locked
(function)   |

C++ documentation for mutex::unlock

C++ documentation for timed_mutex::unlock

C++ documentation for recursive_mutex::unlock

C++ documentation for recursive_timed_mutex::unlock

---
來源頁路徑：`en.cppreference.com/c/thread/mtx_unlock.html`
