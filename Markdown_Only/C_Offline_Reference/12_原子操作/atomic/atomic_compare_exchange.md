# atomic_compare_exchange_weak, atomic_compare_exchange_strong, atomic_compare_exchange_weak_explicit, atomic_compare_exchange_strong_explicit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
_Bool atomic_compare_exchange_strong( volatile A* obj,  C* expected, C desired );
```
|   |  (1)  |   |  (since C11)  |

```c
_Bool atomic_compare_exchange_weak( volatile A *obj,   C* expected, C desired );
```
|   |  (2)  |   |  (since C11)  |

```c
_Bool atomic_compare_exchange_strong_explicit( volatile A* obj,   C* expected, C desired,  memory_order succ,   memory_order fail );
```
|   |  (3)  |   |  (since C11)  |

```c
_Bool atomic_compare_exchange_weak_explicit( volatile A *obj,   C* expected, C desired,  memory_order succ,   memory_order fail );
```
|   |  (4)  |   |  (since C11)  |

|  |  |  |  |

Atomically compares the contents of memory pointed to by `obj` with the contents of memory pointed to by `expected`, and if those are bitwise equal, replaces the former with `desired` (performs read-modify-write operation). Otherwise, loads the actual contents of memory pointed to by `obj` into `*expected` (performs load operation).
以原子方式比較 obj 與 expected 指向的值。若兩者的位元完全相同，就以 desired 取代 obj 指向的值（讀取－修改－寫入操作）；否則，將 obj 的實際值載入 *expected（載入操作）。
The memory models for the read-modify-write and load operations are `succ` and `fail` respectively. The (1-2) versions use memory_order_seq_cst by default.
讀取－修改－寫入操作與載入操作分別採用 succ 和 fail 指定的記憶體順序。(1-2) 版本預設使用 memory_order_seq_cst。
The weak forms ((2) and (4)) of the functions are allowed to fail spuriously, that is, act as if `*obj != *expected` even if they are equal. When a compare-and-exchange is in a loop, the weak version will yield better performance on some platforms. When a weak compare-and-exchange would require a loop and a strong one would not, the strong one is preferable.
這些函式的弱形式（(2) 和 (4)）允許偽失敗，即即使 *obj 與 *expected 相等，也表現得像不相等。當比較並交換在迴圈中時，弱版本在某些平臺上效能更好。當弱比較並交換需要迴圈而強比較並交換不需要時，應優先使用強版本。
This is a generic function defined for all atomic object types `A`. The argument is pointer to a volatile atomic type to accept addresses of both non-volatile and volatile (e.g. memory-mapped I/O) atomic objects, and volatile semantic is preserved when applying this operation to volatile atomic objects. `C` is the non-atomic type corresponding to `A`.
這是一個為所有原子物件型別 A 定義的泛型函式。參數是指向 volatile 原子型別的指標，用於接受非 volatile 和 volatile（例如記憶體對映 I/O）原子物件的位址，將該操作應用於 volatile 原子物件時會保留 volatile 語意。C 是對應於 A 的非原子型別。
It is unspecified whether the name of a generic function is a macro or an identifier declared with external linkage. If a macro definition is suppressed in order to access an actual function (e.g. parenthesized like `(atomic_compare_exchange)(...)`), or a program defines an external identifier with the name of a generic function, the behavior is undefined.
泛型函式的名稱是宏還是具有外部連結的識別符號，這是未指定的。如果為了訪問實際函式而抑制了宏定義（例如用括號括起來如 ( atomic_compare_exchange )(...)），或者程式用泛型函式的名稱定義了一個外部識別符號，則行為未定義。

### Parameters

| obj  |   | -  |   | pointer to the atomic object to test and modify  |

| expected  |   | -  |   | pointer to the value expected to be found in the atomic object  |

| desired  |   | -  |   | the value to store in the atomic object if it is as expected  |

| succ  |   | -  |   | the memory synchronization ordering for the read-modify-write operation if the comparison succeeds. All values are permitted.  |

| fail  |   | -  |   | the memory synchronization ordering for the load operation if the comparison fails. Cannot be memory_order_release or memory_order_acq_rel and cannot specify stronger ordering than `succ`  |

### Return value

The result of the comparison: `true` if `*obj` was equal to `*exp`, `false` otherwise.
比較的結果：如果 *obj 等於 *exp 則為 true，否則為 false。

### Notes

The behavior of `atomic_compare_exchange_*` family is as if the following was executed atomically:
atomic_compare_exchange_* 系列的行為就好像以下操作被原子地執行：

```c
if (memcmp(obj, expected, sizeof *obj) == 0) {  memcpy(obj, &desired, sizeof *obj);  return true; } else {  memcpy(expected, obj, sizeof *obj);  return false; }
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.7.4 The atomic_compare_exchange generic functions (p: 207)
7.17.7.4 atomic_compare_exchange 泛型函式 (p: 207)
7.17.7.4 atomic_compare_exchange 泛型函式 (p: 207)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.7.4 The atomic_compare_exchange generic functions (p: 283-284)
7.17.7.4 atomic_compare_exchange 泛型函式 (p: 283-284)
7.17.7.4 atomic_compare_exchange 泛型函式 (p: 283-284)

### See also

atomic_exchangeatomic_exchange_explicit
(C11)
|   | swaps a value with the value of an atomic object
(function)   |

C++ documentation for atomic_compare_exchange_weak, atomic_compare_exchange_strong, atomic_compare_exchange_weak_explicit, atomic_compare_exchange_strong_explicit

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_compare_exchange.html`
