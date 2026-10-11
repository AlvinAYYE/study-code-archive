# ATOMIC_FLAG_INIT

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdatomic.h>`
|   |  |   |  |

```c
#define ATOMIC_FLAG_INIT /* unspecified */
```
|   |   |   |  (since C11)  |

|  |  |  |  |

Expands to an initializer that can be used to initialize atomic_flag type to the clear state. The value of an `atomic_flag` that is not initialized using this macro is indeterminate.
展開為一個初始化器，可用於將 atomic_flag 型別初始化為清除狀態。未使用該宏初始化的 atomic_flag 的值是不確定的。

### Example

```c
#include <stdatomic.h> atomic_flag flag = ATOMIC_FLAG_INIT;
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.17.1/3 ATOMIC_FLAG_INIT (p: 200)
7.17.1/3 ATOMIC_FLAG_INIT (p: 200)
7.17.1/3 ATOMIC_FLAG_INIT (p: 200)

- 7.17.8/4 ATOMIC_FLAG_INIT (p: 208)
7.17.1/3 ATOMIC_FLAG_INIT (p: 208)
7.17.1/3 ATOMIC_FLAG_INIT (p: 208)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.17.1/3 ATOMIC_FLAG_INIT (p: 273)
7.17.1/3 ATOMIC_FLAG_INIT (p: 273)
7.17.1/3 ATOMIC_FLAG_INIT (p: 273)

- 7.17.8/4 ATOMIC_FLAG_INIT (p: 285)
7.17.8/4 ATOMIC_FLAG_INIT (p: 285)
7.17.8/4 ATOMIC_FLAG_INIT (p: 285)

### See also

ATOMIC_VAR_INIT
(C11)(deprecated in C17)(removed in C23)
|   | initializes a new atomic object
(function macro)   |

atomic_flag
(C11)
|   | lock-free atomic boolean flag
(struct)  |

C++ documentation for ATOMIC_FLAG_INIT

---
來源頁路徑：`en.cppreference.com/c/atomic/ATOMIC_FLAG_INIT.html`
