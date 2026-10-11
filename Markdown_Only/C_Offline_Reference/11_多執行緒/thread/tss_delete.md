# tss_delete

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
void tss_delete( tss_t tss_id );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Destroys the thread-specific storage identified by `tss_id`.
銷燬由 tss_id 標識的執行緒專有儲存。
The destructor, if one was registered by tss_create, is not called (they are only called at thread exit, either by thrd_exit or by returning from the thread function), it is the responsibility of the programmer to ensure that every thread that is aware of `tss_id` performed all necessary cleanup, before the call to `tss_delete` is made.
如果 tss_create 註冊瞭解構函式，它也不會被呼叫（解構函式只線上程退出時被呼叫，無論是透過 thrd_exit 還是透過從執行緒函式傳回）。程式設計師有責任確保每個知曉 tss_id 的執行緒在呼叫 tss_delete 之前完成所有必要的清理工作。
If `tss_delete` is called while another thread is executing destructors for `tss_id`, it's unspecified whether this changes the number of invocations to the associated destructor.
如果在另一個執行緒正在執行 tss_id 的解構函式時呼叫 tss_delete，則這是否會改變關聯解構函式的呼叫次數是未指定的。
If `tss_delete` is called while the calling thread is executing destructors, then the destructor associated with `tss_id` will not be executed again on this thread.
如果在呼叫執行緒正在執行解構函式期間呼叫 tss_delete ，則與 tss_id 關聯的解構函式將不會在該執行緒上再次執行。

### Parameters

| tss_id  |   | -  |   | thread-specific storage key previously returned by tss_create and not yet deleted by tss_delete  |

### Return value

(none)

### Notes

The POSIX equivalent of this function is `pthread_key_delete`.
此函式在 POSIX 中的等價物是 pthread_key_delete 。
The reason `tss_delete` never calls destructors is that the destructors (called at thread exit) are normally intended to be executed by the same thread that originally set the value (via tss_set) that the destructor will be dealing with, and may even rely on the values of that or other thread-specific data as seen by that thread. The thread executing `tss_delete` has no access to other threads' TSS. Even if it were possible to call the destructor for each thread's own value associated with `tss_id`, `tss_delete` would have to synchronize with every thread if only to examine whether the value of this TSS in that thread is null (destructors are only called against non-null values).
tss_delete 從不呼叫解構函式的原因在於：解構函式（線上程退出時被呼叫）通常打算由最初設定該解構函式將要處理的值（透過 tss_set ）的同一個執行緒來執行，甚至可能依賴於該執行緒所看到的該值或其他執行緒專有資料的值。執行 tss_delete 的執行緒無法訪問其他執行緒的 TSS。即使可以為每個執行緒自身與 tss_id 關聯的值呼叫解構函式，tss_delete 也必須與每個執行緒同步，哪怕只是為了檢查該執行緒中此 TSS 的值是否為空（解構函式只針對非空值呼叫）。

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.6.2 The tss_delete function (p: 282)
7.26.6.2 tss_delete 函式（頁：282）
7.26.6.2 tss_delete 函式（頁：282）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.6.2 The tss_delete function (p: 386)
7.26.6.2 tss_delete 函式（頁：386）
7.26.6.2 tss_delete 函式（頁：386）

---
來源頁路徑：`en.cppreference.com/c/thread/tss_delete.html`
