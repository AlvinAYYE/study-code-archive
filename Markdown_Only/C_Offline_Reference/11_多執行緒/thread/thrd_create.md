# thrd_create

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int thrd_create( thrd_t *thr, thrd_start_t func, void *arg );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Creates a new thread executing the function `func`. The function is invoked as `func(arg)`.
建立新的執行緒來執行函式 func，並以 func(arg) 的方式呼叫它。
If successful, the object pointed to by `thr` is set to the identifier of the new thread.
如果成功，thr 所指向的物件會被設定為新執行緒的識別符號。
The completion of this function *synchronizes-with* the beginning of the thread.
此函式的完成與執行緒的開始同步。

### Parameters

| thr  |   | -  |   | pointer to memory location to put the identifier of the new thread  |

| func  |   | -  |   | function to execute  |

| arg  |   | -  |   | argument to pass to the function  |

### Return value

thrd_success if the creation of the new thread was successful. Otherwise returns thrd_nomem if there was insufficient amount of memory or thrd_error if another error occurred.
成功建立執行緒時傳回 thrd_success；若記憶體不足，傳回 thrd_nomem；若發生其他錯誤，則傳回 thrd_error。

### Notes

The thread identifiers may be reused for new threads once the thread has finished and joined or detached.
一旦執行緒執行完畢並被連線或分離，其執行緒識別符號就可以被新執行緒重複使用。
The type thrd_start_t is a typedef of `int(*)(void*)`, which differs from the POSIX equivalent `void*(*)(void*)`
型別 thrd_start_t 是 int ( * )( void * ) 的 typedef ，這與 POSIX 中等價的 void * ( * )( void * ) 不同
All thread-specific storage values (see tss_create) are initialized to NULL.
所有執行緒專有儲存值（參見 tss_create ）都被初始化為 NULL 。
Return from the function `func` is equivalent to calling thrd_exit with the argument equal to the return value of `func`.
從函式 func 傳回等同於以等於 func 傳回值的參數呼叫 thrd_exit 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.5.1 The thrd_create function (p: 279)
7.26.5.1 thrd_create 函式（頁：279）
7.26.5.1 thrd_create 函式（頁：279）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.5.1 The thrd_create function (p: 383)
7.26.5.1 thrd_create 函式（頁：383）
7.26.5.1 thrd_create 函式（頁：383）

### See also

thrd_detach
(C11)
|   | detaches a thread
(function)   |

thrd_join
(C11)
|   | blocks until a thread terminates
(function)   |

C++ documentation for thread

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_create.html`
