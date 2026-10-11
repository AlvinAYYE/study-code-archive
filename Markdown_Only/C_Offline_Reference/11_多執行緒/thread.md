# 並行處理支援函式庫

> 來源：cppreference C 語言參考文件（離線轉換版）。

C includes built-in support for threads, atomic operations, mutual exclusion, condition variables, and thread-specific storages.
C 標準函式庫提供執行緒、原子操作、互斥鎖、條件變數與執行緒區域儲存等功能；實作可以選擇不提供：

- if the macro constant `__STDC_NO_THREADS__` is defined by the compiler, the header <threads.h> and all of the names provided in it are not provided;
若編譯器定義了巨集常數 __STDC_NO_THREADS__，就不會提供 <threads.h> 標頭檔及其中的名稱；

- if the macro constant `__STDC_NO_ATOMICS__` is defined by the compiler, the header <stdatomic.h> and all of the names provided in it are not provided.
若編譯器定義了巨集常數 __STDC_NO_ATOMICS__，就不會提供 <stdatomic.h> 標頭檔及其中的名稱。

See also `**_Atomic**` type specifier and qualifier.
另見 _Atomic 型別說明符和限定符。

### Threads

Defined in header `<threads.h>`

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

### Atomic operations
原子操作

Defined in header `<stdatomic.h>`

#####  Operations on atomic types

ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR8_T_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE
(C11)(C11)(C23)(C11)(C11)(C11)(C11)(C11)(C11)(C11)(C11)
|   | 表示指定的原子型別是否免鎖（lock-free）
(macro constant)   |

atomic_is_lock_free
(C11)
|   | 查詢指定的原子物件是否免鎖（lock-free）
(function)   |

atomic_storeatomic_store_explicit
(C11)
|   | 將值寫入原子物件
(function)   |

atomic_loadatomic_load_explicit
(C11)
|   | 從原子物件讀取值
(function)   |

atomic_exchangeatomic_exchange_explicit
(C11)
|   | 以新值取代原子物件中的值，並傳回舊值
(function)   |

atomic_compare_exchange_strongatomic_compare_exchange_strong_explicitatomic_compare_exchange_weakatomic_compare_exchange_weak_explicit
(C11)
|   | 若原子物件目前的值符合預期值，就寫入新值；否則讀取目前值
(function)   |

atomic_fetch_addatomic_fetch_add_explicit
(C11)
|   | 將指定值加到原子物件，並傳回運算前的值
(function)   |

atomic_fetch_subatomic_fetch_sub_explicit
(C11)
|   | 從原子物件扣除指定值，並傳回運算前的值
(function)   |

atomic_fetch_oratomic_fetch_or_explicit
(C11)
|   | 對原子物件執行位元 OR，並傳回運算前的值
(function)   |

atomic_fetch_xoratomic_fetch_xor_explicit
(C11)
|   | 對原子物件執行位元 XOR，並傳回運算前的值
(function)   |

atomic_fetch_andatomic_fetch_and_explicit
(C11)
|   | 對原子物件執行位元 AND，並傳回運算前的值
(function)   |

#####  Flag type and operations

atomic_flag
(C11)
|   | lock-free atomic boolean flag
(struct)  |

atomic_flag_test_and_setatomic_flag_test_and_set_explicit
(C11)
|   | sets an atomic_flag to true and returns the old value
(function)   |

atomic_flag_clearatomic_flag_clear_explicit
(C11)
|   | sets an atomic_flag to false
(function)   |

#####  Initialization

atomic_init
(C11)
|   | initializes an existing atomic object
(function)   |

ATOMIC_VAR_INIT
(C11)(deprecated in C17)(removed in C23)
|   | initializes a new atomic object
(function macro)   |

ATOMIC_FLAG_INIT
(C11)
|   | initializes a new `atomic_flag`
(macro constant)   |

#####  Memory synchronization ordering

memory_order
(C11)
|   | defines memory ordering constraints
(enum)   |

kill_dependency
(C11)
|   | breaks a dependency chain for `memory_order_consume`
(function macro)   |

atomic_thread_fence
(C11)
|   | 依記憶體順序限制周圍的記憶體操作；搭配原子操作時可建立執行緒間同步
(function)   |

atomic_signal_fence
(C11)
|   | 在執行緒與同一執行緒中的訊號處理常式之間建立屏障
(function)   |

#####  Convenience type aliases

| Typedef name  |   | Full type name  |

| `atomic_bool` (C11)  |   | `_Atomic _Bool`(until C23)`_Atomic bool`(since C23)  |

| `atomic_char` (C11)  |   | `_Atomic char`  |

| `atomic_schar` (C11)  |   | `_Atomic signed char`  |

| `atomic_uchar` (C11)  |   | `_Atomic unsigned char`  |

| `atomic_short` (C11)  |   | `_Atomic short`  |

| `atomic_ushort` (C11)  |   | `_Atomic unsigned short`  |

| `atomic_int` (C11)  |   | `_Atomic int`  |

| `atomic_uint` (C11)  |   | `_Atomic unsigned int`  |

| `atomic_long` (C11)  |   | `_Atomic long`  |

| `atomic_ulong` (C11)  |   | `_Atomic unsigned long`  |

| `atomic_llong` (C11)  |   | `_Atomic long long`  |

| `atomic_ullong` (C11)  |   | `_Atomic unsigned long long`  |

| `atomic_char8_t` (C23)  |   | `_Atomic char8_t`  |

| `atomic_char16_t` (C11)  |   | `_Atomic char16_t`  |

| `atomic_char32_t` (C11)  |   | `_Atomic char32_t`  |

| `atomic_wchar_t` (C11)  |   | `_Atomic wchar_t`  |

| `atomic_int_least8_t` (C11)  |   | `_Atomic int_least8_t`  |

| `atomic_uint_least8_t` (C11)  |   | `_Atomic uint_least8_t`  |

| `atomic_int_least16_t` (C11)  |   | `_Atomic int_least16_t`  |

| `atomic_uint_least16_t` (C11)  |   | `_Atomic uint_least16_t`  |

| `atomic_int_least32_t` (C11)  |   | `_Atomic int_least32_t`  |

| `atomic_uint_least32_t` (C11)  |   | `_Atomic uint_least32_t`  |

| `atomic_int_least64_t` (C11)  |   | `_Atomic int_least64_t`  |

| `atomic_uint_least64_t` (C11)  |   | `_Atomic uint_least64_t`  |

| `atomic_int_fast8_t` (C11)  |   | `_Atomic int_fast8_t`  |

| `atomic_uint_fast8_t` (C11)  |   | `_Atomic uint_fast8_t`  |

| `atomic_int_fast16_t` (C11)  |   | `_Atomic int_fast16_t`  |

| `atomic_uint_fast16_t` (C11)  |   | `_Atomic uint_fast16_t`  |

| `atomic_int_fast32_t` (C11)  |   | `_Atomic int_fast32_t`  |

| `atomic_uint_fast32_t` (C11)  |   | `_Atomic uint_fast32_t`  |

| `atomic_int_fast64_t` (C11)  |   | `_Atomic int_fast64_t`  |

| `atomic_uint_fast64_t` (C11)  |   | `_Atomic uint_fast64_t`  |

| `atomic_intptr_t` (C11)  |   | `_Atomic intptr_t`  |

| `atomic_uintptr_t` (C11)  |   | `_Atomic uintptr_t`  |

| `atomic_size_t` (C11)  |   | `_Atomic size_t`  |

| `atomic_ptrdiff_t` (C11)  |   | `_Atomic ptrdiff_t`  |

| `atomic_intmax_t` (C11)  |   | `_Atomic intmax_t`  |

| `atomic_uintmax_t` (C11)  |   | `_Atomic uintmax_t`  |

### Mutual exclusion
互斥

Defined in header `<threads.h>`

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

Defined in header `<threads.h>`

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

Defined in header `<threads.h>`

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

### Reserved identifiers
保留識別符號

In future revisions of the C standard:
在 C 標準的未來修訂版中：

- function names, type names, and enumeration constants that begin with either `cnd_`, `mtx_`, `thrd_`, or `tss_`, and a lowercase letter may be added to the declarations in the `<threads.h>` header;
以 cnd_ 、 mtx_ 、 thrd_ 或 tss_ 開頭並後跟小寫字母的函式名、型別名和列舉常量可能會被新增到 <threads.h> 標頭檔的宣告中；

- macros that begin with `ATOMIC_` and an uppercase letter may be added to the macros defined in the <stdatomic.h> header;
以 ATOMIC_ 開頭並後跟大寫字母的宏可能會被新增到 <stdatomic.h> 標頭檔定義的宏中；

- typedef names that begin with either `atomic_` or `memory_`, and a lowercase letter may be added to the declarations in the <stdatomic.h> header;
以 atomic_ 或 memory_ 開頭並後跟小寫字母的 typedef 名稱可能會被新增到 <stdatomic.h> 標頭檔的宣告中；

- enumeration constants that begin with `memory_order_` and a lowercase letter may be added to the definition of the memory_order type in the <stdatomic.h> header;
以 memory_order_ 開頭並後跟小寫字母的列舉常量可能會被新增到 <stdatomic.h> 標頭檔中 memory_order 型別的定義中；

- function names that begin with `atomic_` and a lowercase letter may be added to the declarations in the <stdatomic.h> header.
以 atomic_ 開頭並後跟小寫字母的函式名可能會被新增到 <stdatomic.h> 標頭檔的宣告中。

Identifiers reserved for functions names are always potentially(since C23) reserved for use as identifiers with external linkage, while other identifiers list here are potentially(since C23) reserved when <stdatomic.h> is included.
為函式名保留的識別符號始終（自 C23 起）潛在地保留用作具有外部連結的識別符號，而此處列出的其他識別符號在包含 <stdatomic.h> 時（自 C23 起）潛在地被保留。
Declaring, defining, or `#undef`ing such an identifier results in undefined behavior if it is provided by the standard or implementation(since C23). Portable programs should not use those identifiers.
如果此類識別符號由標準或實現提供，則宣告、定義或對其執行 #undef 會導致未定義行為（自 C23 起）。可移植的程式不應使用這些識別符號。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.17 Atomics <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)

- 7.26 Threads <threads.h> (p: TBD)
7.26 執行緒 <threads.h>（頁：TBD）
7.26 執行緒 <threads.h>（頁：TBD）

- 7.31.8 Atomics <stdatomic.h> (p: TBD)
7.31.8 原子操作 <stdatomic.h> （頁碼：待定）
7.31.8 原子操作 <stdatomic.h> （頁碼：待定）

- 7.31.15 Threads <threads.h> (p: TBD)
7.31.15 執行緒 <threads.h>（頁：TBD）
7.31.15 執行緒 <threads.h>（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17 Atomics <stdatomic.h> (p: 200-209)
7.17 原子操作 <stdatomic.h> (p: 200-209)
7.17 原子操作 <stdatomic.h> (p: 200-209)

- 7.26 Threads <threads.h> (p: 274-283)
7.26 執行緒 <threads.h>（頁：274-283）
7.26 執行緒 <threads.h>（頁：274-283）

- 7.31.8 Atomics <stdatomic.h> (p: 332)
7.31.8 原子操作 <stdatomic.h>（頁：332）
7.31.8 原子操作 <stdatomic.h>（頁：332）

- 7.31.15 Threads <threads.h> (p: 333)
7.31.15 執行緒 <threads.h>（頁：333）
7.31.15 執行緒 <threads.h>（頁：333）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17 Atomics <stdatomic.h> (p: 273-286)
7.17 原子操作 <stdatomic.h> (p: 273-286)
7.17 原子操作 <stdatomic.h> (p: 273-286)

- 7.26 Threads <threads.h> (p: 376-387)
7.26 執行緒 <threads.h>（頁：376-387）
7.26 執行緒 <threads.h>（頁：376-387）

- 7.31.8 Atomics <stdatomic.h> (p: 455-456)
7.31.8 原子操作 <stdatomic.h> （頁碼：455-456）
7.31.8 原子操作 <stdatomic.h> （頁碼：455-456）

- 7.31.15 Threads <threads.h> (p: 456)
7.31.15 執行緒 <threads.h>（頁：456）
7.31.15 執行緒 <threads.h>（頁：456）

### See also

C++ documentation for Concurrency support library

### External links

| GNU GCC Libc Manual: ISO C Mutexes  |

---
來源頁路徑：`en.cppreference.com/c/thread.html`
