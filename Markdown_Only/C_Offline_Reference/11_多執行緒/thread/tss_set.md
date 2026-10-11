# tss_set

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int tss_set( tss_t tss_id, void *val );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Sets the value of the thread-specific storage identified by `tss_id` for the current thread to `val`. Different threads may set different values to the same key.
將目前執行緒中由 tss_id 標識的執行緒專有儲存的值設定為 val 。不同的執行緒可以為同一個鍵設定不同的值。
The destructor, if available, is not invoked.
如果存在解構函式，也不會被呼叫。

### Parameters

| tss_id  |   | -  |   | thread-specific storage key, obtained from tss_create and not deleted by tss_delete  |

| val  |   | -  |   | value to set thread-specific storage to  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### Notes

The POSIX equivalent of this function is `pthread_setspecific`.
此函式在 POSIX 中的等價物是 pthread_setspecific 。
Typically TSS is used to store pointers to blocks of dynamically allocated memory that have been reserved for use by the calling thread.
通常，TSS 用於儲存指向已保留給呼叫執行緒使用的動態分配記憶體塊的指標。
`tss_set` may be called in the TSS destructor. If the destructor exits with non-NULL value in the TSS storage, it will be retried by thrd_exit up to TSS_DTOR_ITERATIONS times, after which the storage will be lost.
tss_set 可以在 TSS 解構函式中被呼叫。如果解構函式退出時 TSS 儲存中仍為非 NULL 值，thrd_exit 最多會重試 TSS_DTOR_ITERATIONS 次，之後該儲存將被丟棄。

### Example

|  | This section is incomplete
Reason: improve, perhaps look for POSIX examples for inspiration  |

```c
int thread_func(void *arg) {  tss_t key;  if (thrd_success == tss_create(&key, free)) {  tss_set(key, malloc(4)); // stores a pointer on TSS  // ...  } } // calls free() for the pointer stored on TSS
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.6.4 The tss_set function (p: 282-283)
7.26.6.4 tss_set 函式（頁：282-283）
7.26.6.4 tss_set 函式（頁：282-283）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.6.4 The tss_set function (p: 387)
7.26.6.4 tss_set 函式（頁：387）
7.26.6.4 tss_set 函式（頁：387）

### See also

tss_get
(C11)
|   | reads from thread-specific storage
(function)   |

---
來源頁路徑：`en.cppreference.com/c/thread/tss_set.html`
