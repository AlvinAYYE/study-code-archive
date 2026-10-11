# 原子操作函式庫

> 來源：cppreference C 語言參考文件（離線轉換版）。

If the macro constant `__STDC_NO_ATOMICS__`(C11) is defined by the compiler, the header `<stdatomic.h>`, the keyword `_Atomic`, and all of the names listed here are not provided.
若編譯器定義了巨集常數 __STDC_NO_ATOMICS__（C11 起），就不會提供 <stdatomic.h> 標頭檔、_Atomic 關鍵字，以及本頁列出的所有名稱。

### Types

Defined in header `<stdatomic.h>`

memory_order
(C11)
|   | 定義原子操作前後記憶體存取的排序限制
(enum)   |

atomic_flag
(C11)
|   | 免鎖的原子布林旗標
(struct)  |

### Macros

Defined in header `<stdatomic.h>`

ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR8_T_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE
(C11)(C11)(C23)(C11)(C11)(C11)(C11)(C11)(C11)(C11)(C11)
|   | 表示指定的原子型別是否免鎖（lock-free）
(macro constant)   |

ATOMIC_FLAG_INIT
(C11)
|   | 初始化新的 `atomic_flag`
(macro constant)   |

ATOMIC_VAR_INIT
(C11)(deprecated in C17)(removed in C23)
|   | 初始化新的原子物件
(function macro)   |

kill_dependency
(C11)
|   | 中斷 `memory_order_consume` 所依賴的相依鏈
(function macro)   |

### Functions

Defined in header `<stdatomic.h>`

atomic_flag_test_and_setatomic_flag_test_and_set_explicit
(C11)
|   | 將 `atomic_flag` 設為 true，並傳回原本的值
(function)   |

atomic_flag_clearatomic_flag_clear_explicit
(C11)
|   | 將 `atomic_flag` 設為 false
(function)   |

atomic_init
(C11)
|   | 初始化既有的原子物件
(function)   |

atomic_is_lock_free
(C11)
|   | 查詢原子物件是否免鎖（lock-free）
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

atomic_thread_fence
(C11)
|   | 依記憶體順序限制周圍的記憶體操作；搭配原子操作時可建立執行緒間同步
(function)   |

atomic_signal_fence
(C11)
|   | 在執行緒與同一執行緒中的訊號處理常式之間建立屏障
(function)   |

### Types

The standard library offers convenience typedefs for the core language atomic types.
標準函式庫也為 C 語言內建的原子型別提供方便使用的 typedef。

| Typedef name  |   | Full type name  |

| `atomic_bool`  |   | `_Atomic _Bool`  |

| `atomic_char`  |   | `_Atomic char`  |

| `atomic_schar`  |   | `_Atomic signed char`  |

| `atomic_uchar`  |   | `_Atomic unsigned char`  |

| `atomic_short`  |   | `_Atomic short`  |

| `atomic_ushort`  |   | `_Atomic unsigned short`  |

| `atomic_int`  |   | `_Atomic int`  |

| `atomic_uint`  |   | `_Atomic unsigned int`  |

| `atomic_long`  |   | `_Atomic long`  |

| `atomic_ulong`  |   | `_Atomic unsigned long`  |

| `atomic_llong`  |   | `_Atomic long long`  |

| `atomic_ullong`  |   | `_Atomic unsigned long long`  |

| `atomic_char8_t` (C23)  |   | `_Atomic char8_t`  |

| `atomic_char16_t`  |   | `_Atomic char16_t`  |

| `atomic_char32_t`  |   | `_Atomic char32_t`  |

| `atomic_wchar_t`  |   | `_Atomic wchar_t`  |

| `atomic_int_least8_t`  |   | `_Atomic int_least8_t`  |

| `atomic_uint_least8_t`  |   | `_Atomic uint_least8_t`  |

| `atomic_int_least16_t`  |   | `_Atomic int_least16_t`  |

| `atomic_uint_least16_t`  |   | `_Atomic uint_least16_t`  |

| `atomic_int_least32_t`  |   | `_Atomic int_least32_t`  |

| `atomic_uint_least32_t`  |   | `_Atomic uint_least32_t`  |

| `atomic_int_least64_t`  |   | `_Atomic int_least64_t`  |

| `atomic_uint_least64_t`  |   | `_Atomic uint_least64_t`  |

| `atomic_int_fast8_t`  |   | `_Atomic int_fast8_t`  |

| `atomic_uint_fast8_t`  |   | `_Atomic uint_fast8_t`  |

| `atomic_int_fast16_t`  |   | `_Atomic int_fast16_t`  |

| `atomic_uint_fast16_t`  |   | `_Atomic uint_fast16_t`  |

| `atomic_int_fast32_t`  |   | `_Atomic int_fast32_t`  |

| `atomic_uint_fast32_t`  |   | `_Atomic uint_fast32_t`  |

| `atomic_int_fast64_t`  |   | `_Atomic int_fast64_t`  |

| `atomic_uint_fast64_t`  |   | `_Atomic uint_fast64_t`  |

| `atomic_intptr_t`  |   | `_Atomic intptr_t`  |

| `atomic_uintptr_t`  |   | `_Atomic uintptr_t`  |

| `atomic_size_t`  |   | `_Atomic size_t`  |

| `atomic_ptrdiff_t`  |   | `_Atomic ptrdiff_t`  |

| `atomic_intmax_t`  |   | `_Atomic intmax_t`  |

| `atomic_uintmax_t`  |   | `_Atomic uintmax_t`  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.17 Atomics <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)

- 7.31.8 Atomics <stdatomic.h> (p: TBD)
7.31.8 原子操作 <stdatomic.h> （頁碼：待定）
7.31.8 原子操作 <stdatomic.h> （頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17 Atomics <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)
7.17 原子操作 <stdatomic.h> (p: TBD)

- 7.31.8 Atomics <stdatomic.h> (p: TBD)
7.31.8 原子操作 <stdatomic.h> （頁碼：待定）
7.31.8 原子操作 <stdatomic.h> （頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17 Atomics <stdatomic.h> (p: 273-286)
7.17 原子操作 <stdatomic.h> (p: 273-286)
7.17 原子操作 <stdatomic.h> (p: 273-286)

- 7.31.8 Atomics <stdatomic.h> (p: 455-456)
7.31.8 原子操作 <stdatomic.h> （頁碼：455-456）
7.31.8 原子操作 <stdatomic.h> （頁碼：455-456）

### See also

C++ documentation for Atomic operations library

---
來源頁路徑：`en.cppreference.com/c/atomic.html`
