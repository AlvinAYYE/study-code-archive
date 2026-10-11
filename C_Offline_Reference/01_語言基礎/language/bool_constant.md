# Predefined Boolean constants (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Syntax

|   |

| `**true**`  |   | (1)  |   | (since C23)  |

|   |

| `**false**`  |   | (2)  |   | (since C23)  |

|   |

### Explanation

Keywords `true` and `false` represent predefined constants. They are non-lvalues of type bool.
關鍵字 true 和 false 表示預定義常量。它們是型別為 bool 的非左值。

### Notes

See integral conversions for implicit conversions from `bool` to other types and boolean conversions for the implicit conversions from other types to `bool`.
從 bool 到其他型別的隱式轉換見整數轉換，從其他型別到 bool 的隱式轉換見布林轉換。
Until C23, `true` and `false` were implemented as macros provided in <stdbool.h>. An implementation may also define `bool`, `true`, and `false` as predefined macros in C23 for compatibility.
在 C23 之前，true 和 false 是由 <stdbool.h> 提供的宏實現的。為了相容，實現也可以在 C23 中將 bool 、 true 和 false 定義為預定義宏。

### Example

Run this code

```c
#include <assert.h> int main() {  assert(true == 1 && 0 == false); }
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.4.6 Predefined constants (p: 66)
6.4.4.6 預定義常量 (p: 66)
6.4.4.6 預定義常量 (p: 66)

### See also

C++ documentation for Boolean literals

---
來源頁路徑：`en.cppreference.com/c/language/bool_constant.html`
