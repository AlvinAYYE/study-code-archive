# atomic_store, atomic_store_explicit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
void atomic_store( volatile A* obj , C desired );
```
|   |  (1)  |   |  (since C11)  |

```c
void atomic_store_explicit( volatile A* obj, C desired, memory_order order );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

Atomically replaces the value of the atomic variable pointed to by `obj` with `desired`. The operation is atomic write operation.
以原子方式將 obj 指向的原子變數設為 desired。這是原子寫入操作。
The first version orders memory accesses according to memory_order_seq_cst, the second version orders memory accesses according to `order`. `order` must be one of memory_order_relaxed, memory_order_release or memory_order_seq_cst. Otherwise the behavior is undefined.
第一個版本使用 memory_order_seq_cst 排序記憶體存取；第二個版本則依 order 指定的順序處理。order 必須是 memory_order_relaxed、memory_order_release 或 memory_order_seq_cst，否則行為未定義。
This is a generic function defined for all atomic object types `A`. The argument is pointer to a volatile atomic type to accept addresses of both non-volatile and volatile (e.g. memory-mapped I/O) atomic objects, and volatile semantic is preserved when applying this operation to volatile atomic objects. `C` is the non-atomic type corresponding to `A`.
這是一個為所有原子物件型別 A 定義的泛型函式。參數是指向 volatile 原子型別的指標，用於接受非 volatile 和 volatile（例如記憶體對映 I/O）原子物件的位址，將該操作應用於 volatile 原子物件時會保留 volatile 語意。C 是對應於 A 的非原子型別。
It is unspecified whether the name of a generic function is a macro or an identifier declared with external linkage. If a macro definition is suppressed in order to access an actual function (e.g. parenthesized like `(atomic_store)(...)`), or a program defines an external identifier with the name of a generic function, the behavior is undefined.
泛型函式的名稱是宏還是具有外部連結的識別符號，這是未指定的。如果為了訪問實際函式而抑制了宏定義（例如用括號括起來如 ( atomic_store )(...)），或者程式用泛型函式的名稱定義了一個外部識別符號，則行為未定義。

### Parameters

| obj  |   | -  |   | pointer to the atomic object to modify  |

| order  |   | -  |   | the memory synchronization ordering for this operation  |

### Return value

(none)

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.7.1 The atomic_store generic functions (p: 206)
7.17.7.1 atomic_store 泛型函式 (p: 206)
7.17.7.1 atomic_store 泛型函式 (p: 206)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.7.1 The atomic_store generic functions (p: 282)
7.17.7.1 atomic_store 泛型函式 (p: 282)
7.17.7.1 atomic_store 泛型函式 (p: 282)

### See also

atomic_loadatomic_load_explicit
(C11)
|   | reads a value from an atomic object
(function)   |

C++ documentation for atomic_store, atomic_store_explicit

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_store.html`
