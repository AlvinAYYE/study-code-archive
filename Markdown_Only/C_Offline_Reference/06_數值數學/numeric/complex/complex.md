# complex

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
#define complex _Complex
```
|   |   |   |  (since C99)  |

|  |  |  |  |

This macro expands to a type specifier used to identify complex types.
此巨集會展開成用來指定複數型別的型別說明符。
A program may undefine and perhaps then redefine the `complex` macro.
程式可以取消定義 complex 巨集，之後也可以重新定義。

### Example

Run this code

```c
#include <complex.h> #include <math.h> #include <stdio.h> void print_complex(const char* note, complex z) {  printf("%s %f%+f*i\n", note, creal(z), cimag(z)); } int main(void) {  double complex z = -1.0 + 2.0*I;  print_complex("z =", z);  print_complex("z\u00B2 =", z * z);  double complex z2 = ccos(2.0 * carg(z)) + csin(2.0 * carg(z))*I;  print_complex("z\u00B2 =", cabs(z) * cabs(z) * z2); }
```

Output:

```c
z = -1.000000+2.000000*i z² = -3.000000-4.000000*i z² = -3.000000-4.000000*i
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.3.1/4 complex (p: TBD)
7.3.1/4 complex (p: TBD)
7.3.1/4 complex (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.3.1/4 complex (p: 136)
7.3.1/4 complex (p: 136)
7.3.1/4 complex (p: 136)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.1/4 complex (p: 188)
7.3.1/4 complex (p: 188)
7.3.1/4 complex (p: 188)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.1/2 complex (p: 170)
7.3.1/2 complex (p: 170)
7.3.1/2 complex (p: 170)

### See also

imaginary
(C99)
|   | imaginary type macro
(keyword macro)   |

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/complex.html`
