# INFINITY

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |
(deprecated in C23)

Defined in header `<float.h>`
|   |  |   |
(since C23)

```c
#define INFINITY /* implementation-defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

If the implementation supports an infinity for the type `float`, the macro `INFINITY` expands to constant expression of type `float` which evaluates to positive or unsigned infinity.
如果實現為型別 float 支援無窮大，則宏 INFINITY 展開為型別為 float 的常量表示式，其求值結果為正無窮大或無符號無窮大。

Otherwise, the macro `INFINITY` expands to a positive value that is guaranteed to overflow a `float` at compile time, and the use of this macro generates a compiler warning.
|   | (until C23) |

Otherwise, the macro `INFINITY` is not defined.
|   | (since C23) |

### Example

Show style used to print an infinity and IEEE format.
顯示用於列印無窮大的樣式和 IEEE 格式。
Run this code

```c
#include <float.h> // since C23 #include <inttypes.h> #include <math.h> #include <stdio.h> #include <stdint.h> #include <string.h> int main(void) {  double f = INFINITY;  uint64_t fn;  memcpy(&fn, &f, sizeof f);  printf("INFINITY: %f %" PRIx64 "\n", f, fn); }
```

Possible output:
可能的輸出：

```c
INFINITY: inf 7ff0000000000000
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12/4 INFINITY (p: 231-232)
7.12/4 INFINITY（p: 231-232）
7.12/4 INFINITY（p: 231-232）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12/4 INFINITY (p: 212-213)
7.12/4 INFINITY（p: 212-213）
7.12/4 INFINITY（p: 212-213）

### See also

isinf
(C99)
|   | checks if the given number is infinite
(function macro)   |

HUGE_VALFHUGE_VALHUGE_VALL
(C99)(C99)
|   | indicates value too big to be representable (infinity) by `float`, `double` and `long double` respectively
(macro constant)   |

C++ documentation for INFINITY

---
來源頁路徑：`en.cppreference.com/c/numeric/math/INFINITY.html`
