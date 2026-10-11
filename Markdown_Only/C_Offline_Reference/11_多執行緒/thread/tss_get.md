# tss_get

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
void *tss_get( tss_t tss_key );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Returns the value held in thread-specific storage for the current thread identified by `tss_key`. Different threads may get different values identified by the same key.
傳回由 tss_key 標識的目前執行緒線上程專有儲存中儲存的值。不同的執行緒可能透過相同的鍵獲得不同的值。
On thread startup (see thrd_create), the values associated with all TSS keys are NULL. Different value may be placed in the thread-specific storage with tss_set.
線上程啟動時（參見 thrd_create ），與所有 TSS 鍵關聯的值都是 NULL。可以使用 tss_set 線上程專有儲存中放入不同的值。

### Parameters

| tss_key  |   | -  |   | thread-specific storage key, obtained from tss_create and not deleted by tss_delete  |

### Return value

The value on success, NULL on failure.
成功時傳回該值，失敗時傳回 NULL 。

### Notes

The POSIX equivalent for this function is `pthread_getspecific`.
此函式在 POSIX 中的等價物是 pthread_getspecific 。

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.6.3 The tss_get function (p: 282)
7.26.6.3 tss_get 函式（頁：282）
7.26.6.3 tss_get 函式（頁：282）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.6.3 The tss_get function (p: 386)
7.26.6.3 tss_get 函式（頁：386）
7.26.6.3 tss_get 函式（頁：386）

### See also

tss_set
(C11)
|   | write to thread-specific storage
(function)   |

---
來源頁路徑：`en.cppreference.com/c/thread/tss_get.html`
