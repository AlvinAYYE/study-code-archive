# cimagf, cimag, cimagl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float cimagf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double cimag( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double cimagl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define cimag( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Returns the imaginary part of `z`.

4) Type-generic macro: if `z` has type `long double complex`, `long double imaginary`, or `long double`, `cimagl` is called. If `z` has type `float complex`, `float imaginary`, or `float`, `cimagf` is called. If `z` has type `double complex`, `double imaginary`, `double`, or any integer type, `cimag` is called.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

The imaginary part of `z`.
z 的虛部。
This function is fully specified for all possible inputs and is not subject to any errors described in math_errhandling
此函式對所有可能的輸入都有明確定義，不受 math_errhandling 所述錯誤狀況影響。

### Notes

For any complex variable `z`, `z == creal(z) + I*cimag(z)`.
對任何複數變數 z，都有 z == creal(z) + I * cimag(z)。

### Example

Run this code

```c
#include <stdio.h> #include <complex.h> int main(void) {   double complex z = 1.0 + 2.0*I;  printf("%f%+fi\n", creal(z), cimag(z)); }
```

Output:

```c
1.000000+2.000000i
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.9.2 The cimag functions (p: 197)
7.3.9.2 cimag 函式（頁：197）
7.3.9.2 cimag 函式（頁：197）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.9.2 The cimag functions (p: 178-179)
7.3.9.2 cimag 函式（頁：178-179）
7.3.9.2 cimag 函式（頁：178-179）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

crealcrealfcreall
(C99)(C99)(C99)
|   | computes the real part of a complex number
(function)   |

C++ documentation for imag

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/cimag.html`
