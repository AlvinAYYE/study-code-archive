# kill_dependency

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
A kill_dependency( A y );
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Informs the compiler that the dependency tree started by an memory_order_consume atomic load operation does not extend past the return value of `kill_dependency`; that is, the argument does not carry a dependency into the return value.
告知編譯器，由 memory_order_consume 原子載入操作開始的依賴樹不會延伸到 kill_dependency 的傳回值之外；也就是說，參數不會將依賴帶入傳回值。
The function is implemented as a macro. `A` is the type of `y`.
該函式實現為宏。A 是 y 的型別。

### Parameters

| y  |   | -  |   | the expression whose return value is to be removed from a dependency tree  |

### Return value

Returns `y`, no longer a part of a dependency tree.
傳回 y，不再是依賴樹的一部分。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.17.3.1 The kill_dependency macro (p: TBD)
7.17.3.1 kill_dependency 宏 (p: TBD)
7.17.3.1 kill_dependency 宏 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.3.1 The kill_dependency macro (p: 203-204)
7.17.3.1 kill_dependency 宏 (p: 203-204)
7.17.3.1 kill_dependency 宏 (p: 203-204)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.3.1 The kill_dependency macro (p: 278)
7.17.3.1 kill_dependency 宏 (p: 278)
7.17.3.1 kill_dependency 宏 (p: 278)

### See also

C++ documentation for kill_dependency

---
來源頁路徑：`en.cppreference.com/c/atomic/kill_dependency.html`
