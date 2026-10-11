# _Complex_I

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
#define _Complex_I /* unspecified */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The `_Complex_I` macro expands to a value of type `const float _Complex` with the value of the imaginary unit.
_Complex_I 會展開成 const float _Complex 型別的虛數單位值。

### Notes

This macro may be used when I is not available, such as when it has been undefined by the application.
若 I 無法使用（例如應用程式已將它取消定義），可以改用此巨集。
Unlike _Imaginary_I and CMPLX, use of this macro to construct a complex number may lose the sign of zero on the imaginary part.
與 _Imaginary_I 和 CMPLX 不同，使用此巨集建立複數時，虛部零的正負號可能會遺失。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> #undef I #define J _Complex_I // can be used to redefine I int main(void) {  // can be used to construct a complex number  double complex z = 1.0 + 2.0 * _Complex_I;  printf("1.0 + 2.0 * _Complex_I = %.1f%+.1fi\n", creal(z), cimag(z));    // sign of zero may not be preserved  double complex z2 = 0.0 + -0.0 * _Complex_I;  printf("0.0 + -0.0 * _Complex_I = %.1f%+.1fi\n", creal(z2), cimag(z2)); }
```

Possible output:
可能的輸出：

```c
1.0 + 2.0 * _Complex_I = 1.0+2.0i 0.0 + -0.0 * _Complex_I = 0.0+0.0i
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.3.1/4 _Complex_I (p: TBD)
7.3.1/4 _Complex_I（頁：待定）
7.3.1/4 _Complex_I（頁：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.3.1/4 _Complex_I (p: 136)
7.3.1/4 _Complex_I（頁：136）
7.3.1/4 _Complex_I（頁：136）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.1/4 _Complex_I (p: 188)
7.3.1/4 _Complex_I（頁：188）
7.3.1/4 _Complex_I（頁：188）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.1/2 _Complex_I (p: 170)
7.3.1/2 _Complex_I（頁：170）
7.3.1/2 _Complex_I（頁：170）

### See also

_Imaginary_I
(C99)
|   | the imaginary unit constant i
(macro constant)   |

I
(C99)
|   | the complex or imaginary unit constant i
(macro constant)   |

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/Complex_I.html`
