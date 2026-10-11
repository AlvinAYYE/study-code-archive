# ATOMIC_VAR_INIT

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
#define ATOMIC_VAR_INIT(value) /* unspecified */
```
|   |   |   |  (since C11)
(deprecated in C17)
(removed in C23)  |

|  |  |  |  |

Expands to an expression that can be used to initialize an atomic variable of the same type as `value`.
展開為一個表示式，可用於初始化與 value 相同型別的原子變數。
The initial value of atomic object of automatic storage duration that is not explicitly initialized is indeterminate. The default (zero) initialization of static and thread-local variables produces a valid value however.
未顯式初始化的自動儲存期原子物件的初始值是不確定的。然而，靜態和執行緒區域性變數的預設（零）初始化會產生一個有效值。
When initializing an atomic variable, any concurrent access, even through an atomic operation, is a data race (it may happen if the address is immediately passed to another thread with a memory_order_relaxed operation).
初始化原子變數時，任何併發訪問（即使透過原子操作）都是資料競爭（如果位址透過 memory_order_relaxed 操作立即傳遞給另一個執行緒，就可能發生）。

### Notes

This macro was a part of early draft design for C11 atomic types. It is not needed in C11, and is deprecated in C17 and removed in C23.
該宏是 C11 原子型別早期草案設計的一部分。在 C11 中不再需要，在 C17 中已棄用，在 C23 中已移除。

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 485  |   | C11  |   | the specification was redundant and contradictory to the core language  |   | fixed  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.2.1 The ATOMIC_VAR_INIT macro (p: 201)
7.17.2.1 ATOMIC_VAR_INIT 宏 (p: 201)
7.17.2.1 ATOMIC_VAR_INIT 宏 (p: 201)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.2.1 The ATOMIC_VAR_INIT macro (p: 274)
7.17.2.1 ATOMIC_VAR_INIT 宏 (p: 274)
7.17.2.1 ATOMIC_VAR_INIT 宏 (p: 274)

### See also

ATOMIC_FLAG_INIT
(C11)
|   | initializes a new `atomic_flag`
(macro constant)   |

C++ documentation for ATOMIC_VAR_INIT

---
來源頁路徑：`en.cppreference.com/c/atomic/ATOMIC_VAR_INIT.html`
