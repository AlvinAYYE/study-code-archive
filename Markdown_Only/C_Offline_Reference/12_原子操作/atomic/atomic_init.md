# atomic_init

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
void atomic_init( volatile A* obj, C desired );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Initializes the default-constructed atomic object `obj` with the value `desired`. The function is not atomic: concurrent access from another thread, even through an atomic operation, is a data race.
以 desired 初始化預設建構的原子物件 obj。此函式本身不是原子操作；若其他執行緒同時存取 obj（即使使用原子操作），仍會造成資料競爭。
This is a generic function defined for all atomic object types `A`. The argument is pointer to a volatile atomic type to accept addresses of both non-volatile and volatile (e.g. memory-mapped I/O) atomic objects, and volatile semantic is preserved when applying this operation to volatile atomic objects. `C` is the non-atomic type corresponding to `A`.
這是一個為所有原子物件型別 A 定義的泛型函式。參數是指向 volatile 原子型別的指標，用於接受非 volatile 和 volatile（例如記憶體對映 I/O）原子物件的位址，將該操作應用於 volatile 原子物件時會保留 volatile 語意。C 是對應於 A 的非原子型別。
It is unspecified whether the name of a generic function is a macro or an identifier declared with external linkage. If a macro definition is suppressed in order to access an actual function (e.g. parenthesized like `(atomic_init)(...)`), or a program defines an external identifier with the name of a generic function, the behavior is undefined.
泛型函式的名稱是宏還是具有外部連結的識別符號，這是未指定的。如果為了訪問實際函式而抑制了宏定義（例如用括號括起來如 ( atomic_init )(...)），或者程式用泛型函式的名稱定義了一個外部識別符號，則行為未定義。

### Parameters

| obj  |   | -  |   | pointer to an atomic object to initialize  |

| desired  |   | -  |   | the value to initialize atomic object with  |

### Return value

(none)

### Notes

`atomic_init` is the only way to initialize dynamically-allocated atomic objects. For example:
atomic_init 是初始化動態分配原子物件的唯一方法。例如：

```c
_Atomic int *p = malloc(sizeof(_Atomic int)); atomic_init(p, 42);
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.17.2.2 The atomic_init generic function (p: TBD)
7.17.2.2 atomic_init 泛型函式 (p: TBD)
7.17.2.2 atomic_init 泛型函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.2.2 The atomic_init generic function (p: 201)
7.17.2.2 atomic_init 泛型函式 (p: 201)
7.17.2.2 atomic_init 泛型函式 (p: 201)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.2.2 The atomic_init generic function (p: 274-275)
7.17.2.2 atomic_init 泛型函式 (p: 274-275)
7.17.2.2 atomic_init 泛型函式 (p: 274-275)

### See also

ATOMIC_VAR_INIT
(C11)(deprecated in C17)(removed in C23)
|   | initializes a new atomic object
(function macro)   |

C++ documentation for atomic_init

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_init.html`
