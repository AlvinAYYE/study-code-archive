# Standard library header <stdatomic.h> (C11)

> 來源：cppreference C 語言參考文件（離線轉換版）。

This header provides atomic operations, in particular, it's a part of the concurrency support library.
該標頭檔提供原子操作，特別是它是併發支援庫的一部分。

### Atomic operations
原子操作

#####  Operations on atomic types

ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR8_T_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE
(C11)(C11)(C23)(C11)(C11)(C11)(C11)(C11)(C11)(C11)(C11)
|   | indicates that the given atomic type is lock-free
(macro constant)   |

atomic_is_lock_free
(C11)
|   | indicates whether the atomic object is lock-free
(function)   |

atomic_storeatomic_store_explicit
(C11)
|   | stores a value in an atomic object
(function)   |

atomic_loadatomic_load_explicit
(C11)
|   | reads a value from an atomic object
(function)   |

atomic_exchangeatomic_exchange_explicit
(C11)
|   | swaps a value with the value of an atomic object
(function)   |

atomic_compare_exchange_strongatomic_compare_exchange_strong_explicitatomic_compare_exchange_weakatomic_compare_exchange_weak_explicit
(C11)
|   | swaps a value with an atomic object if the old value is what is expected, otherwise reads the old value
(function)   |

atomic_fetch_addatomic_fetch_add_explicit
(C11)
|   | atomic addition
(function)   |

atomic_fetch_subatomic_fetch_sub_explicit
(C11)
|   | atomic subtraction
(function)   |

atomic_fetch_oratomic_fetch_or_explicit
(C11)
|   | atomic bitwise OR
(function)   |

atomic_fetch_xoratomic_fetch_xor_explicit
(C11)
|   | atomic bitwise exclusive OR
(function)   |

atomic_fetch_andatomic_fetch_and_explicit
(C11)
|   | atomic bitwise AND
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
|   | generic memory order-dependent fence synchronization primitive
(function)   |

atomic_signal_fence
(C11)
|   | fence between a thread and a signal handler executed in the same thread
(function)   |

#####  Convenience type aliases

| Typedef name  |   | Full type name  |

| `atomic_bool` (C11)  |   | `_Atomic _Bool`  |

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

### Synopsis

|  | This section is incomplete
Reason: add more from 7.17 Atomics <stdatomic.h> and B.16 Atomics <stdatomic.h>  |

```c
#define __STDC_VERSION_STDATOMIC_H__ 202311L void atomic_init(volatile A* obj, /*C*/ value); /*type*/ kill_dependency(/*type*/ y); void atomic_thread_fence(memory_order order); void atomic_signal_fence(memory_order order); bool atomic_is_lock_free(const volatile A* obj); void atomic_store(volatile A* object, /*C*/ desired); void atomic_store_explicit(volatile A* object, /*C*/ desired, memory_order order); /*C*/ atomic_load(const volatile A* object); /*C*/ atomic_load_explicit(const volatile A* object, memory_order order); /*C*/ atomic_exchange(volatile A* object, /*C*/ desired); /*C*/ atomic_exchange_explicit(volatile A* object, /*C*/ desired, memory_order order); bool atomic_compare_exchange_strong(volatile A* object, /*C*/* expected, /*C*/ desired); bool atomic_compare_exchange_strong_explicit(volatile A* object, /*C*/* expected, /*C*/ desired, memory_order success, memory_order failure); bool atomic_compare_exchange_weak(volatile A* object, /*C*/* expected, /*C*/ desired); bool atomic_compare_exchange_weak_explicit(volatile A* object, /*C*/* expected, /*C*/ desired, memory_order success, memory_order failure); /*C*/ /*atomic_fetch_key*/(volatile A* object, M operand); /*C*/ /*atomic_fetch_key_explicit*/(volatile A* object, M operand, memory_order order); bool atomic_flag_test_and_set(volatile atomic_flag* object); bool atomic_flag_test_and_set_explicit(volatile atomic_flag* object,  memory_order order); void atomic_flag_clear(volatile atomic_flag* object); void atomic_flag_clear_explicit(volatile atomic_flag* object,  memory_order order);
```

---
來源頁路徑：`en.cppreference.com/c/header/stdatomic.html`
