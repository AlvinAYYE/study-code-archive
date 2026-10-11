# tss_create

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int tss_create( tss_t* tss_key, tss_dtor_t destructor );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Creates new thread-specific storage key and stores it in the object pointed to by `tss_key`. Although the same key value may be used by different threads, the values bound to the key by tss_set are maintained on a per-thread basis and persist for the life of the calling thread.
建立新的執行緒專有儲存鍵並將其存入 tss_key 所指向的物件中。雖然不同的執行緒可以使用相同的鍵值，但由 tss_set 繫結到該鍵的值是按執行緒分別維護的，並在呼叫執行緒的生存期內持續存在。
The value NULL is associated with the newly created key in all existing threads, and upon thread creation, the values associated with all TSS keys is initialized to NULL.
在所有現有執行緒中，值 NULL 與新建立的鍵相關聯；線上程建立時，與所有 TSS 鍵關聯的值都被初始化為 NULL 。
If `destructor` is not a null pointer, then also associates the destructor which is called when the storage is released by thrd_exit (but not by tss_delete and not at program termination by exit).
如果 destructor 不是空指標，則還會關聯該解構函式，它在儲存由 thrd_exit 釋放時被呼叫（但不會在 tss_delete 時呼叫，也不會在程式因 exit 終止時呼叫）。
A call to `tss_create` from within a thread-specific storage destructor results in undefined behavior.
線上程專有儲存解構函式內呼叫 tss_create 會導致未定義行為。

### Parameters

| tss_key  |   | -  |   | pointer to memory location to store the new thread-specific storage key  |

| destructor  |   | -  |   | pointer to a function to call at thread exit  |

### Notes

The POSIX equivalent of this function is `pthread_key_create`.
此函式在 POSIX 中的等價物是 pthread_key_create 。

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### Example

|  | This section is incomplete
Reason: improve, perhaps look for POSIX examples for inspiration  |

```c
int thread_func(void *arg) {  tss_t key;  if (thrd_success == tss_create(&key, free)) {  tss_set(key, malloc(4)); // stores a pointer on TSS  // ...  } } // calls free() for the pointer stored on TSS
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.6.1 The tss_create function (p: 281-282)
7.26.6.1 tss_create 函式（頁：281-282）
7.26.6.1 tss_create 函式（頁：281-282）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.6.1 The tss_create function (p: 386)
7.26.6.1 tss_create 函式（頁：386）
7.26.6.1 tss_create 函式（頁：386）

---
來源頁路徑：`en.cppreference.com/c/thread/tss_create.html`
