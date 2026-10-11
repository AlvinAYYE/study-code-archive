# atomic_flag_clear, atomic_flag_clear_explicit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
void atomic_flag_clear( volatile atomic_flag* obj );
```
|   |  (1)  |   |  (since C11)  |

```c
void atomic_flag_clear_explicit( volatile atomic_flag* obj, memory_order order );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

Atomically changes the state of a `atomic_flag` pointed to by `obj` to clear (`false`). The first version orders memory accesses according to memory_order_seq_cst, the second version orders memory accesses according to `order`.
以原子方式將 obj 指向的 atomic_flag 清除（設為 false）。第一個版本使用 memory_order_seq_cst 排序記憶體存取；第二個版本則依 order 指定的順序處理。
The argument is pointer to a volatile atomic flag to accept addresses of both non-volatile and volatile (e.g. memory-mapped I/O) atomic flags.
參數是指向 volatile 原子標誌的指標，用於接受非 volatile 和 volatile（例如記憶體對映 I/O）原子標誌的位址。

### Parameters

| obj  |   | -  |   | pointer to the atomic flag object to modify  |

| order  |   | -  |   | the memory synchronization ordering for this operation: all values are permitted  |

### Return value

(none)

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.8.2 The atomic_flag_clear functions (p: 209)
7.17.8.2 atomic_flag_clear 函式 (p: 209)
7.17.8.2 atomic_flag_clear 函式 (p: 209)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.8.2 The atomic_flag_clear functions (p: 286)
7.17.8.2 atomic_flag_clear 函式 (p: 286)
7.17.8.2 atomic_flag_clear 函式 (p: 286)

### See also

atomic_flag_test_and_setatomic_flag_test_and_set_explicit
(C11)
|   | sets an atomic_flag to true and returns the old value
(function)   |

C++ documentation for atomic_flag_clear, atomic_flag_clear_explicit

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_flag_clear.html`
