# _Imaginary_I

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
#define _Imaginary_I /* unspecified */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The `_Imaginary_I` macro expands to a value of type `const float _Imaginary` with the value of the imaginary unit.
_Imaginary_I 會展開成 const float _Imaginary 型別的虛數單位值。
As with any pure imaginary number support in C, this macro is only defined if the imaginary numbers are supported.
和 C 語言的其他純虛數功能一樣，只有在實作支援虛數時才會定義此巨集。

A compiler that defines `__STDC_IEC_559_COMPLEX__` is not required to support imaginary numbers. POSIX recommends checking if the macro `_Imaginary_I` is defined to identify imaginary number support.
|   | (since C99)
(until C11) |

Imaginary numbers are supported if `__STDC_IEC_559_COMPLEX__` is defined.
|   | (since C11) |

### Notes

This macro allows for the precise way to assemble a complex number from its real and imaginary components, e.g. with `(double complex)((double)x + _Imaginary_I * (double)y)`. This pattern was standardized in C11 as the macro `CMPLX`. Note that if `_Complex_I` is used instead, this expression is allowed to convert negative zero to positive zero in the imaginary position.
此巨集可用來精確組合複數的實部和虛部，例如 (double complex)((double)x + _Imaginary_I * (double)y)。C11 將這種寫法標準化為 CMPLX 巨集。注意，若改用 _Complex_I，運算式可能會把虛部的負零轉成正零。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> #include <math.h> int main(void) {  double complex z1 = 0.0 + INFINITY * _Imaginary_I;  printf("z1 = %.1f%+.1fi\n", creal(z1), cimag(z1));  double complex z2 = 0.0 + INFINITY * _Complex_I;  printf("z2 = %.1f%+.1fi\n", creal(z2), cimag(z2)); }
```

Output:

```c
z1 = 0.0+Infi z2 = NaN+Infi
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.1/5 _Imaginary_I (p: 188)
7.3.1/5 _Imaginary_I (p: 188)
7.3.1/5 _Imaginary_I (p: 188)

- G.6/1 _Imaginary_I (p: 537)
G.6/1 _Imaginary_I (p: 537)
G.6/1 _Imaginary_I (p: 537)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.1/3 _Imaginary_I (p: 170)
7.3.1/3 _Imaginary_I (p: 170)
7.3.1/3 _Imaginary_I (p: 170)

- G.6/1 _Imaginary_I (p: 472)
G.6/1 _Imaginary_I (p: 472)
G.6/1 _Imaginary_I (p: 472)

### See also

_Complex_I
(C99)
|   | the complex unit constant i
(macro constant)   |

I
(C99)
|   | the complex or imaginary unit constant i
(macro constant)   |

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/Imaginary_I.html`
