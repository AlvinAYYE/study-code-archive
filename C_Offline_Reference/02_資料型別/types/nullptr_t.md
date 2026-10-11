# nullptr_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stddef.h>`
|   |  |   |  |

```c
typedef typeof(nullptr) nullptr_t;
```
|   |   |   |  (since C23)  |

|  |  |  |  |

`nullptr_t` is the type of the predefined null pointer constant, nullptr. It is a distinct type that is not itself a pointer type. It can be implicitly converted to any pointer type or `bool`, and the result is the null pointer value of that type or `false` respectively. No type other than `nullptr_t` itself can be converted or explicitly cast to `nullptr_t`.
nullptr_t 是預定義空指標常量 nullptr 的型別。它是一個獨立型別，本身並不是指標型別。它可以被隱式轉換為任何指標型別或 bool，結果分別為該型別的空指標值或 false。除 nullptr_t 本身外，沒有任何型別可以被轉換或顯式轉換為 nullptr_t。
`sizeof(nullptr_t)` and `alignof(nullptr_t)` are equal to `sizeof(void*)` and `alignof(void*)` respectively.
`sizeof(nullptr_t)` 和 `alignof(nullptr_t)` 分別等於 `sizeof(void*)` 和 `alignof(void*)`。
sizeof ( nullptr_t ) 和 alignof ( nullptr_t ) 分別等於 sizeof ( void * ) 和 alignof ( void * )。
`nullptr_t` has only one valid value, i.e., `nullptr`. The object representation of `nullptr` is same as that of `(void*)0`. If an lvalue conversion produces a `nullptr_t` value with a different object representation, the behavior is undefined.
nullptr_t 只有一個有效值，即 nullptr。nullptr 的物件表示與 ( void * ) 0 的物件表示相同。如果左值轉換產生具有不同物件表示的 nullptr_t 值，則行為是未定義的。

### Example

Demonstrate that `nullptr_t` is a distinct type.
演示 nullptr_t 是一個獨立型別。
Run this code

```c
#include <stddef.h> #include <stdio.h> #define DETECT_NULL_POINTER_CONSTANT(e) \  _Generic(e, \  void* : puts("void*"), \  nullptr_t : puts("nullptr_t"), \  default : puts("other") \  ) int main() {  DETECT_NULL_POINTER_CONSTANT(((void*)0));  DETECT_NULL_POINTER_CONSTANT(0);  DETECT_NULL_POINTER_CONSTANT(nullptr); }
```

Output:

```c
void* other nullptr_t
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.21.2 The nullptr_t type (p: 315-316)
7.21.2 nullptr_t 型別 (p: 315-316)
7.21.2 nullptr_t 型別 (p: 315-316)

### See also

NULL
|   | implementation-defined null pointer constant
(macro constant)   |

C++ documentation for nullptr_t

---
來源頁路徑：`en.cppreference.com/c/types/nullptr_t.html`
