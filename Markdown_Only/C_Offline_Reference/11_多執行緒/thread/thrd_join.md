# thrd_join

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
int thrd_join( thrd_t thr, int *res );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Blocks the current thread until the thread identified by `thr` finishes execution.
目前的執行緒會等待，直到 thr 所識別的執行緒執行完畢。
If `res` is not a null pointer, the result code of the thread is put to the location pointed to by `res`.
如果 res 不是空指標，則執行緒的結果碼會被存入 res 所指向的位置。
The termination of the thread *synchronizes-with* the completion of this function.
執行緒的終止與此函式的完成同步。
The behavior is undefined if the thread was previously detached or joined by another thread.
如果該執行緒先前已被分離或已被其他執行緒連線，則屬於未定義行為。

### Parameters

| thr  |   | -  |   | identifier of the thread to join  |

| res  |   | -  |   | location to put the result code to  |

### Return value

thrd_success if successful, thrd_error otherwise.
成功則傳回 thrd_success ，否則傳回 thrd_error 。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.5.6 The thrd_join function (p: 280-281)
7.26.5.6 thrd_join 函式（頁：280-281）
7.26.5.6 thrd_join 函式（頁：280-281）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.5.6 The thrd_join function (p: 384-385)
7.26.5.6 thrd_join 函式（頁：384-385）
7.26.5.6 thrd_join 函式（頁：384-385）

### See also

thrd_detach
(C11)
|   | detaches a thread
(function)   |

thrd_exit
(C11)
|   | terminates the calling thread
(function)   |

C++ documentation for join

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_join.html`
