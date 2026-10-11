# atomic_exchange, atomic_exchange_explicit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
C atomic_exchange( volatile A* obj, C desired );
```
|   |  (1)  |   |  (since C11)  |

```c
C atomic_exchange_explicit( volatile A* obj, C desired, memory_order order );
```
|   |  (2)  |   |  (since C11)  |

|  |  |  |  |

Atomically replaces the value pointed by `obj` with `desired` and returns the value `obj` held previously. The operation is read-modify-write operation. The first version orders memory accesses according to memory_order_seq_cst, the second version orders memory accesses according to `order`.
以原子方式將 obj 指向的值換成 desired，並傳回 obj 原本的值。這是讀取－修改－寫入操作。第一個版本使用 memory_order_seq_cst 排序記憶體存取；第二個版本則依 order 指定的順序處理。
This is a generic function defined for all atomic object types `A`. The argument is pointer to a volatile atomic type to accept addresses of both non-volatile and volatile (e.g. memory-mapped I/O) atomic objects, and volatile semantic is preserved when applying this operation to volatile atomic objects. `C` is the non-atomic type corresponding to `A`.
這是一個為所有原子物件型別 A 定義的泛型函式。參數是指向 volatile 原子型別的指標，用於接受非 volatile 和 volatile（例如記憶體對映 I/O）原子物件的位址，將該操作應用於 volatile 原子物件時會保留 volatile 語意。C 是對應於 A 的非原子型別。
It is unspecified whether the name of a generic function is a macro or an identifier declared with external linkage. If a macro definition is suppressed in order to access an actual function (e.g. parenthesized like `(atomic_exchange)(...)`), or a program defines an external identifier with the name of a generic function, the behavior is undefined..
泛型函式的名稱是宏還是具有外部連結的識別符號，這是未指定的。如果為了訪問實際函式而抑制了宏定義（例如用括號括起來如 ( atomic_exchange )(...)），或者程式用泛型函式的名稱定義了一個外部識別符號，則行為未定義。

### Parameters

| obj  |   | -  |   | pointer to the atomic object to modify  |

| desired  |   | -  |   | the value to replace the atomic object with  |

| order  |   | -  |   | the memory synchronization ordering for this operation: all values are permitted  |

### Return value

The value held previously be the atomic object pointed to by `obj`.
obj 所指向的原子物件之前儲存的值。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.7.3 The atomic_exchange generic functions (p: 207)
7.17.7.3 atomic_exchange 泛型函式 (p: 207)
7.17.7.3 atomic_exchange 泛型函式 (p: 207)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.7.3 The atomic_exchange generic functions (p: 283)
7.17.7.3 atomic_exchange 泛型函式 (p: 283)
7.17.7.3 atomic_exchange 泛型函式 (p: 283)

### See also

atomic_compare_exchange_strongatomic_compare_exchange_strong_explicitatomic_compare_exchange_weakatomic_compare_exchange_weak_explicit
(C11)
|   | swaps a value with an atomic object if the old value is what is expected, otherwise reads the old value
(function)   |

C++ documentation for atomic_exchange, atomic_exchange_explicit

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_exchange.html`
