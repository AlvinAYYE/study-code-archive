# Standard library header <threads.h> (C11)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header is part of concurrency support library and provides support for threads, mutual exclusion, condition variables, and thread-specific storages.
這個標頭檔屬於並行支援函式庫，提供執行緒、互斥鎖、條件變數及執行緒區域儲存空間的支援。

### Threads

| `**thrd_t**`  |   | implementation-defined complete object type identifying a thread   |

thrd_create
(C11)
|   | creates a thread
(function)   |

thrd_equal
(C11)
|   | checks if two identifiers refer to the same thread
(function)   |

thrd_current
(C11)
|   | obtains the current thread identifier
(function)   |

thrd_sleep
(C11)
|   | suspends execution of the calling thread for the given period of time
(function)   |

thrd_yield
(C11)
|   | yields the current time slice
(function)   |

thrd_exit
(C11)
|   | terminates the calling thread
(function)   |

thrd_detach
(C11)
|   | detaches a thread
(function)   |

thrd_join
(C11)
|   | blocks until a thread terminates
(function)   |

thrd_successthrd_timedoutthrd_busythrd_nomemthrd_error
(C11)
|   | indicates a thread error status
(constant)   |

thrd_start_t
(C11)
|   | a typedef of the function pointer type `int(*)(void*)`, used by `thrd_create`
(typedef)   |

### Mutual exclusion
互斥

| `**mtx_t**`  |   | mutex identifier   |

mtx_init
(C11)
|   | creates a mutex
(function)   |

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

mtx_unlock
(C11)
|   | unlocks a mutex
(function)   |

mtx_destroy
(C11)
|   | destroys a mutex
(function)   |

mtx_plainmtx_recursivemtx_timed
(C11)(C11)(C11)
|   | defines the type of a mutex
(enum)   |

#####  Call once

call_once
(C11)
|   | calls a function exactly once
(function)   |

### Condition variables
條件變數

| `**cnd_t**`  |   | condition variable identifier  |

cnd_init
(C11)
|   | creates a condition variable
(function)   |

cnd_signal
(C11)
|   | unblocks one thread blocked on a condition variable
(function)   |

cnd_broadcast
(C11)
|   | unblocks all threads blocked on a condition variable
(function)   |

cnd_wait
(C11)
|   | blocks on a condition variable
(function)   |

cnd_timedwait
(C11)
|   | blocks on a condition variable, with a timeout
(function)   |

cnd_destroy
(C11)
|   | destroys a condition variable
(function)   |

### Thread-local storage
執行緒區域性儲存

thread_local
(C11)(removed in C23)
|   | convenience macro for storage-class specifier `_Thread_local`
(keyword macro)   |

| `**tss_t**`  |   | thread-specific storage pointer   |

TSS_DTOR_ITERATIONS
(C11)
|   | maximum number of times destructors are called
(macro constant)   |

`**tss_dtor_t**`
(C11)
|   | function pointer type `void(*)(void*)`, used for TSS destructor
(typedef)   |

tss_create
(C11)
|   | creates thread-specific storage pointer with a given destructor
(function)   |

tss_get
(C11)
|   | reads from thread-specific storage
(function)   |

tss_set
(C11)
|   | write to thread-specific storage
(function)   |

tss_delete
(C11)
|   | releases the resources held by a given thread-specific pointer
(function)   |

### Synopsis

```c
#define __STDC_NO_THREADS__ 202311L #define ONCE_FLAG_INIT /* see description */ #define TSS_DTOR_ITERATIONS /* see description */ typedef /* see description */ cnd_t; typedef /* see description */ thrd_t; typedef /* see description */ tss_t; typedef /* see description */ mtx_t; typedef /* see description */ tss_dtor_t; typedef /* see description */ thrd_start_t; #define mtx_plain /* see description */ #define mtx_recursive /* see description */ #define mtx_timed /* see description */ #define once_flag /* see description */ #define thrd_busy /* see description */ #define thrd_error /* see description */ #define thrd_nomem /* see description */ #define thrd_success /* see description */ #define thrd_timedout /* see description */ void call_once(once_flag* flag, void (*func)(void)); int cnd_broadcast(cnd_t* cond); void cnd_destroy(cnd_t* cond); int cnd_init(cnd_t* cond); int cnd_signal(cnd_t* cond); int cnd_timedwait(cnd_t* restrict cond, mtx_t* restrict mtx, const struct timespec* restrict ts); int cnd_wait(cnd_t* cond, mtx_t* mtx); void mtx_destroy(mtx_t* mtx); int mtx_init(mtx_t* mtx, int type); int mtx_lock(mtx_t* mtx); int mtx_timedlock(mtx_t* restrict mtx, const struct timespec* restrict ts); int mtx_trylock(mtx_t* mtx); int mtx_unlock(mtx_t* mtx); int thrd_create(thrd_t* thr, thrd_start_t func, void* arg); thrd_t thrd_current(void); int thrd_detach(thrd_t thr); int thrd_equal(thrd_t thr0, thrd_t thr1); [[noreturn]] void thrd_exit(int res); int thrd_join(thrd_t thr, int* res); int thrd_sleep(const struct timespec* duration, struct timespec* remaining); void thrd_yield(void); int tss_create(tss_t* key, tss_dtor_t dtor); void tss_delete(tss_t key); void* tss_get(tss_t key); int tss_set(tss_t key, void* val);
```

---
來源頁路徑：`en.cppreference.com/c/header/threads.html`
