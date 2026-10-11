# mtx_trylock

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int mtx_trylock( mtx_t *mutex );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Tries to lock the mutex pointed to by `mutex` without blocking. Returns immediately if the mutex is already locked.
嘗試鎖定 mutex 指向的互斥鎖，不會等待；若互斥鎖已被鎖定，便立即傳回。
Prior calls to mtx_unlock on the same mutex *synchronize-with* this operation (if this operation succeeds), and all lock/unlock operations on any given mutex form a single total order (similar to the modification order of an atomic)
之前對同一互斥量呼叫的 mtx_unlock 與該操作同步（如果該操作成功），且對任何給定互斥量的所有加鎖/解鎖操作構成一個單一的全序（類似於原子操作的修改順序）

### Parameters

| mutex  |   | -  |   | pointer to the mutex to lock  |

### Return value

thrd_success if successful, thrd_busy if the mutex has already been locked or due to a spurious failure to acquire an available mutex, thrd_error if an error occurs.
成功則傳回 thrd_success ，如果互斥量已被鎖定或因虛假失敗而未能獲取可用的互斥量則傳回 thrd_busy ，如果發生錯誤則傳回 thrd_error 。

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 470  |   | C11  |   | `mtx_trylock` was not allowed to fail spuriously  |   | allowed  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.4.5 The mtx_trylock function (p: 278-279)
7.26.4.5 mtx_trylock 函式（頁：278-279）
7.26.4.5 mtx_trylock 函式（頁：278-279）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.4.5 The mtx_trylock function (p: 382)
7.26.4.5 mtx_trylock 函式（頁：382）
7.26.4.5 mtx_trylock 函式（頁：382）

### See also

mtx_lock
(C11)
|   | blocks until locks a mutex
(function)   |

mtx_timedlock
(C11)
|   | blocks until locks a mutex or times out
(function)   |

mtx_unlock
(C11)
|   | unlocks a mutex
(function)   |

C++ documentation for mutex::try_lock

C++ documentation for timed_mutex::try_lock

C++ documentation for recursive_mutex::try_lock

C++ documentation for recursive_timed_mutex::try_lock

---
來源頁路徑：`en.cppreference.com/c/thread/mtx_trylock.html`
