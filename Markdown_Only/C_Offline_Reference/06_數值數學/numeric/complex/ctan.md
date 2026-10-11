# ctanf, ctan, ctanl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex ctanf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex ctan( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex ctanl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define tan( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex tangent of `z`.

4) Type-generic macro: If `z` has type `long double complex`, `ctanl` is called. if `z` has type `double complex`, `ctan` is called, if `z` has type `float complex`, `ctanf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`tanf`, `tan`, `tanl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function tanh, implementing the formula tan(iy) = i tanh(y), and the return type is imaginary.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, the complex tangent of `z` is returned.
若沒有發生錯誤，回傳 z 的複數正切。
Errors and special cases are handled as if the operation is implemented by `-i * ctanh(i*z)`, where `i` is the imaginary unit.
錯誤與特殊情況的處理方式，等同於以 -i * ctanh(i * z) 實作此運算，其中 i 是虛數單位。

### Notes

Tangent is an analytical function on the complex plain and has no branch cuts. It is periodic with respect to the real component, with period πi, and has poles of the first order along the real line, at coordinates (π(1/2 + n), 0). However no common floating-point representation is able to represent π/2 exactly, thus there is no value of the argument for which a pole error occurs.
正切在複平面上是解析函式，沒有分支切割。它以實部為週期變數，週期為 π；在實軸上的 (π(1/2 + n), 0) 有一階極點。不過，常見的浮點格式都無法精確表示 π/2，因此沒有任何引數會觸發極點錯誤。
Mathematical definition of the tangent is
正切的數學定義如下：
tan z =
i(e-iz
-eiz
) |
e-iz
+eiz

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = ctan(1); // behaves like real tangent along the real line  printf("tan(1+0i) = %f%+fi ( tan(1)=%f)\n", creal(z), cimag(z), tan(1));  double complex z2 = ctan(I); // behaves like tanh along the imaginary line   printf("tan(0+1i) = %f%+fi (tanh(1)=%f)\n", creal(z2), cimag(z2), tanh(1)); }
```

Output:

```c
tan(1+0i) = 1.557408+0.000000i ( tan(1)=1.557408) tan(0+1i) = 0.000000+0.761594i (tanh(1)=0.761594)
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.5.6 The ctan functions (p: 192)
7.3.5.6 ctan 函式 (p: 192)
7.3.5.6 ctan 函式 (p: 192)

- 7.25 Type-generic complex <tgmath.h> (p: 373-375)
7.25 型別通用複數 <tgmath.h> (p: 373-375)
7.25 型別通用複數 <tgmath.h> (p: 373-375)

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.5.6 The ctan functions (p: 174)
7.3.5.6 ctan 函式 (p: 174)
7.3.5.6 ctan 函式 (p: 174)

- 7.22 Type-generic complex <tgcomplex.h> (p: 335-337)
7.22 型別通用複數 <tgcomplex.h> (p: 335-337)
7.22 型別通用複數 <tgcomplex.h> (p: 335-337)

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

ctanhctanhfctanhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic tangent
(function)   |

csincsinfcsinl
(C99)(C99)(C99)
|   | computes the complex sine
(function)   |

ccosccosfccosl
(C99)(C99)(C99)
|   | computes the complex cosine
(function)   |

catancatanfcatanl
(C99)(C99)(C99)
|   | computes the complex arc tangent
(function)   |

tantanftanl
(C99)(C99)
|   | computes tangent (tanxtan⁡xtan(x))
(function)   |

C++ documentation for tan

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/ctan.html`
