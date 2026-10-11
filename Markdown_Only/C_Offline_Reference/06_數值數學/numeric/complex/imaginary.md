# imaginary

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
#define imaginary _Imaginary
```
|   |   |   |  (since C99)  |

|  |  |  |  |

This macro expands to the keyword _Imaginary.
此巨集會展開成關鍵字 _Imaginary。
This is a convenience macro that makes it possible to use `float imaginary`, `double imaginary`, and `long double imaginary` as an alternative way to write the three pure imaginary C types `float _Imaginary`, `double _Imaginary`, and `long double _Imaginary`
這個便利巨集讓你可以寫成 float imaginary、double imaginary 和 long double imaginary，取代 C 的純虛數型別 float _Imaginary、double _Imaginary 和 long double _Imaginary。
As with any pure imaginary number support in C, this macro is only defined if the imaginary numbers are supported.
和 C 語言的其他純虛數功能一樣，只有在實作支援虛數時才會定義此巨集。

A compiler that defines `__STDC_IEC_559_COMPLEX__` is not required to support imaginary numbers. POSIX recommends checking if the macro `_Imaginary_I` is defined to identify imaginary number support.
|   | (since C99)
(until C11) |

Imaginary numbers are supported if `__STDC_IEC_559_COMPLEX__` is defined.
|   | (since C11) |

### Notes

Programs are allowed to undefine and perhaps redefine the `imaginary` macro.
程式可以取消定義 imaginary 巨集，之後也可以重新定義。
To date, only Oracle C compiler is known to have implemented imaginary types.
目前已知只有 Oracle C 編譯器實作了虛數型別。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {  double imaginary i = -2.0*I; // pure imaginary  double f = 1.0; // pure real  double complex z = f + i; // complex number  printf("z = %.1f%+.1fi\n", creal(z), cimag(z)); }
```

Output:

```c
z = 1.0-2.0i
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.3.1/5 imaginary (p: 136)
7.3.1/5 imaginary (p: 136)
7.3.1/5 imaginary (p: 136)

- G.6/1 imaginary (p: 391-392)
G.6/1 imaginary (p: 391-392)
G.6/1 imaginary (p: 391-392)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.1/5 imaginary (p: 188)
7.3.1/5 imaginary (p: 188)
7.3.1/5 imaginary (p: 188)

- G.6/1 imaginary (p: 537)
G.6/1 imaginary (p: 537)
G.6/1 imaginary (p: 537)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.1/3 imaginary (p: 170)
7.3.1/3 imaginary (p: 170)
7.3.1/3 imaginary (p: 170)

- G.6/1 imaginary (p: 472)
G.6/1 imaginary (p: 472)
G.6/1 imaginary (p: 472)

### See also

complex
(C99)
|   | complex type macro
(keyword macro)   |

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/imaginary.html`
