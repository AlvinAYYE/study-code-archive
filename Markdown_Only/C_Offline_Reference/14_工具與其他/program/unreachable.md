# unreachable

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stddef.h>`
|   |  |   |  |

```c
#define unreachable() /* see below */
```
|   |   |   |  (since C23)  |

|  |  |  |  |

The function-like macro `unreachable` expands to a `void` expression. Executing `unreachable()` results in undefined behavior.
類函式宏 unreachable 展開為 void 表示式。執行 unreachable () 會導致未定義行為。
An implementation may use this to optimize impossible code branches away (typically, in optimized builds) or to trap them to prevent further execution (typically, in debug builds).
實現可以使用它來最佳化掉不可能的程式碼分支（通常在最佳化構建中），或捕獲它們以阻止進一步執行（通常在除錯構建中）。

### Possible implementation
可能的實現

```c
// Uses compiler specific extensions if possible. #ifdef __GNUC__ // GCC, Clang, ICC #define unreachable() (__builtin_unreachable()) #elifdef _MSC_VER // MSVC #define unreachable() (__assume(false)) #else // Even if no extension is used, undefined behavior is still raised by // the empty function body and the noreturn attribute. // The external definition of unreachable_impl must be emitted in a separated TU // due to the rule for inline functions in C. [[noreturn]] inline void unreachable_impl() {} #define unreachable() (unreachable_impl()) #endif
```

### Example

Run this code

```c
#include <assert.h> #include <stddef.h> #include <stdint.h> #include <stdlib.h> struct Color { uint8_t r, g, b, a; }; struct ColorSpan { struct Color* data; size_t size; }; // Assume that only restricted set of texture caps is supported. struct ColorSpan allocate_texture(size_t xy) {  switch (xy)  {  case 128: [[fallthrough]];  case 256: [[fallthrough]];  case 512:  {  /* ... */  struct ColorSpan result = {  .data = malloc(xy * xy * sizeof(struct Color)),  .size = xy * xy  };  if (!result.data)  result.size = 0;  return result;  }  default:  unreachable();  } } int main(void) {  struct ColorSpan tex = allocate_texture(128); // OK  assert(tex.size == 128 * 128);  struct ColorSpan badtex = allocate_texture(32); // Undefined behavior  free(badtex.data);  free(tex.data); }
```

Possible output:
可能的輸出：

```c
Segmentation fault
```

### See also

C++ documentation for unreachable

### External Links

| 1.  |   | GCC docs: `__builtin_unreachable`  |

| 2.  |   | Clang docs: `__builtin_unreachable`  |

| 3.  |   | MSVC docs: `__assume`  |

---
來源頁路徑：`en.cppreference.com/c/program/unreachable.html`
