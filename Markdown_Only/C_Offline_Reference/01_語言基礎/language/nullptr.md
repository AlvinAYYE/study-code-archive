# Predefined null pointer constant (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Syntax

|   |

| `**nullptr**`  |   |   |   | (since C23)  |

|   |

### Explanation

The keyword `nullptr` denotes a predefined null pointer constant. It is a non-lvalue of type nullptr_t. `nullptr` can be converted to a pointer types or `bool`, where the result is the null pointer value of that type or `false` respectively.
關鍵字 nullptr 表示一個預定義的空指標常量。它是 nullptr_t 型別的非左值。 nullptr 可以轉換為指標型別或 bool ，結果分別是該型別的空指標值或 false 。

### Keywords

nullptr

### Example

Demonstrates that a copy of `nullptr` can also be used as a null pointer constant.
演示 nullptr 的副本也可以用作空指標常量。
Run this code

```c
#include <stddef.h> #include <stdio.h> void g(int*) {  puts("Function g called"); } #define DETECT_NULL_POINTER_CONSTANT(e) \  _Generic(e, \  void* : puts("void*"), \  nullptr_t : puts("nullptr_t"), \  default : puts("integer") \  ) int main() {  g(nullptr); // OK  g(NULL); // OK  g(0); // OK  auto cloned_nullptr = nullptr;  g(cloned_nullptr); // OK  [[maybe_unused]] auto cloned_NULL = NULL; // g(cloned_NULL); // implementation-defined: maybe OK  [[maybe_unused]] auto cloned_zero = 0; // g(cloned_zero); // Error  DETECT_NULL_POINTER_CONSTANT(((void*)0));  DETECT_NULL_POINTER_CONSTANT(0);  DETECT_NULL_POINTER_CONSTANT(nullptr);  DETECT_NULL_POINTER_CONSTANT(NULL); // implementation-defined }
```

Possible output:
可能的輸出：

```c
Function g called Function g called Function g called Function g called void* integer nullptr_t void*
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.4.6 Predefined constants (p: 66)
6.4.4.6 預定義常量 (p: 66)
6.4.4.6 預定義常量 (p: 66)

### See also

NULL
|   | implementation-defined null pointer constant
(macro constant)   |

nullptr_t
(C23)
|   | the type of the predefined null pointer constant nullptr
(typedef)   |

C++ documentation for nullptr

---
來源頁路徑：`en.cppreference.com/c/language/nullptr.html`
