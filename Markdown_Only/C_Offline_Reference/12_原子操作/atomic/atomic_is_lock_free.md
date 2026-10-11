# atomic_is_lock_free

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
_Bool atomic_is_lock_free( const volatile A* obj );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Determines if the atomic operations on all objects of the type `A` (the type of the object pointed to by `obj`) are lock-free. In any given program execution, the result of calling `atomic_is_lock_free` is the same for all pointers of the same type.
判斷型別 A（即 obj 指向的物件型別）的原子操作是否不需使用鎖定。在同一次程式執行中，對所有指向相同型別物件的指標呼叫 atomic_is_lock_free，結果都相同。
This is a generic function defined for all atomic object types `A`. The argument is pointer to a volatile atomic type to accept addresses of both non-volatile and volatile (e.g. memory-mapped I/O) atomic objects, and volatile semantic is preserved when applying this operation to volatile atomic objects.
這是一個為所有原子物件型別 A 定義的泛型函式。參數是指向 volatile 原子型別的指標，用於接受非 volatile 和 volatile（例如記憶體對映 I/O）原子物件的位址，將該操作應用於 volatile 原子物件時會保留 volatile 語意。
It is unspecified whether the name of a generic function is a macro or an identifier declared with external linkage. If a macro definition is suppressed in order to access an actual function (e.g. parenthesized like `(atomic_is_lock_free)(...)`), or a program defines an external identifier with the name of a generic function, the behavior is undefined.
泛型函式的名稱是宏還是具有外部連結的識別符號，這是未指定的。如果為了訪問實際函式而抑制了宏定義（例如用括號括起來如 ( atomic_is_lock_free )(...)），或者程式用泛型函式的名稱定義了一個外部識別符號，則行為未定義。

### Parameters

| obj  |   | -  |   | pointer to the atomic object to inspect  |

### Return value

`true` if the operations on all objects of the type `A` are lock-free, `false` otherwise.
如果型別 A 的所有物件上的操作都是無鎖的，則為 true，否則為 false。

### Example

Run this code

```c
#include <stdio.h> #include <stdatomic.h>   _Atomic struct A { int a[100]; } a; _Atomic struct B { int x, y; } b; int main(void) {  printf("_Atomic struct A is lock free? %s\n",   atomic_is_lock_free(&a) ? "true" : "false");  printf("_Atomic struct B is lock free? %s\n",   atomic_is_lock_free(&b) ? "true" : "false"); }
```

Possible output:
可能的輸出：

```c
_Atomic struct A is lock free? false _Atomic struct B is lock free? true
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 465  |   | C11  |   | this function was per-object  |   | this functions is per-type  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.5.1 The atomic_is_lock_free generic function (p: 205)
7.17.5.1 atomic_is_lock_free 泛型函式 (p: 205)
7.17.5.1 atomic_is_lock_free 泛型函式 (p: 205)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.5.1 The atomic_is_lock_free generic function (p: 280)
7.17.5.1 atomic_is_lock_free 泛型函式 (p: 280)
7.17.5.1 atomic_is_lock_free 泛型函式 (p: 280)

### See also

ATOMIC_BOOL_LOCK_FREEATOMIC_CHAR_LOCK_FREEATOMIC_CHAR8_T_LOCK_FREEATOMIC_CHAR16_T_LOCK_FREEATOMIC_CHAR32_T_LOCK_FREEATOMIC_WCHAR_T_LOCK_FREEATOMIC_SHORT_LOCK_FREEATOMIC_INT_LOCK_FREEATOMIC_LONG_LOCK_FREEATOMIC_LLONG_LOCK_FREEATOMIC_POINTER_LOCK_FREE
(C11)(C11)(C23)(C11)(C11)(C11)(C11)(C11)(C11)(C11)(C11)
|   | indicates that the given atomic type is lock-free
(macro constant)   |

C++ documentation for atomic_is_lock_free

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_is_lock_free.html`
