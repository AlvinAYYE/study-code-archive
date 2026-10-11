# thrd_exit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<threads.h>`
|   |  |   |  |

```c
_Noreturn void thrd_exit( int res );
```
|   |   |   | (since C11)
(until C23) |

```c
[[noreturn]] void thrd_exit( int res );
```
|   |   |   | (since C23) |

|  |  |  |  |

First, for every thread-specific storage key which was created with a non-null destructor and for which the associated value is non-null (see tss_create), `thrd_exit` sets the value associated with the key to `NULL` and then invokes the destructor with the previous value of the key. The order in which the destructors are invoked is unspecified.
首先，對於每個以非空解構函式建立且關聯值非空的執行緒專有儲存鍵（參見 tss_create ），thrd_exit 會將與該鍵關聯的值設定為 NULL，然後以該鍵先前的值呼叫解構函式。解構函式的呼叫順序是未指定的。
If, after this, there remain keys with both non-null destructors and values (e.g. if a destructor executed tss_set), the process is repeated up to TSS_DTOR_ITERATIONS times.
如果之後仍存在解構函式和值都非空的鍵（例如某個解構函式執行了 tss_set ），則該過程最多重複 TSS_DTOR_ITERATIONS 次。
Finally, the `thrd_exit` function terminates execution of the calling thread and sets its result code to `res`.
最後，thrd_exit 函式終止呼叫執行緒的執行，並將其結果碼設定為 res 。
If the last thread in the program is terminated with `thrd_exit`, the entire program terminates as if by calling exit with EXIT_SUCCESS as the argument (so the functions registered by atexit are executed in the context of that last thread)
如果程式中的最後一個執行緒透過 thrd_exit 終止，則整個程式會如同以 EXIT_SUCCESS 為參數呼叫 exit 那樣終止（因此由 atexit 註冊的函式會在該最後一個執行緒的上下文中執行）

### Parameters

| res  |   | -  |   | the result value to return  |

### Return value

(none)

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.26.5.5 The thrd_exit function (p: 280)
7.26.5.5 thrd_exit 函式（頁：280）
7.26.5.5 thrd_exit 函式（頁：280）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.26.5.5 The thrd_exit function (p: 384)
7.26.5.5 thrd_exit 函式（頁：384）
7.26.5.5 thrd_exit 函式（頁：384）

### See also

thrd_join
(C11)
|   | blocks until a thread terminates
(function)   |

thrd_detach
(C11)
|   | detaches a thread
(function)   |

---
來源頁路徑：`en.cppreference.com/c/thread/thrd_exit.html`
