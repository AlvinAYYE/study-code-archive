# atomic_flag

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
typedef struct /* unspecified */ atomic_flag;
```
|   |   |   |  (since C11)  |

|  |  |  |  |

`atomic_flag` is an atomic boolean type. Unlike other atomic types, it is guaranteed to be lock-free. Unlike atomic_bool, `atomic_flag` does not provide load or store operations.
atomic_flag 是一個原子布林型別。與其他原子型別不同，它保證是無鎖的。與 atomic_bool 不同，atomic_flag 不提供載入或儲存操作。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.17.1/5 atomic_flag (p: 293)
7.17.1/5 atomic_flag (p: 293)
7.17.1/5 atomic_flag (p: 293)

- 7.17.8 Atomic flag type and operations (p: 302-303)
7.17.8 原子標誌型別和操作 (p: 302-303)
7.17.8 原子標誌型別和操作 (p: 302-303)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.1/4 atomic_flag (p: 200)
7.17.1/4 atomic_flag (p: 200)
7.17.1/4 atomic_flag (p: 200)

- 7.17.8 Atomic flag type and operations (p: 208-209)
7.17.8 原子標誌型別和操作 (p: 208-209)
7.17.8 原子標誌型別和操作 (p: 208-209)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.1/4 atomic_flag (p: 273)
7.17.1/4 atomic_flag (p: 273)
7.17.1/4 atomic_flag (p: 273)

- 7.17.8 Atomic flag type and operations (p: 285-286)
7.17.8 原子標誌型別和操作 (p: 285-286)
7.17.8 原子標誌型別和操作 (p: 285-286)

### See also

ATOMIC_FLAG_INIT
(C11)
|   | initializes a new `atomic_flag`
(macro constant)   |

atomic_flag_test_and_setatomic_flag_test_and_set_explicit
(C11)
|   | sets an atomic_flag to true and returns the old value
(function)   |

atomic_flag_clearatomic_flag_clear_explicit
(C11)
|   | sets an atomic_flag to false
(function)   |

C++ documentation for atomic_flag

---
來源頁路徑：`en.cppreference.com/c/atomic/atomic_flag.html`
