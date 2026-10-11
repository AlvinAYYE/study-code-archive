# ctanhf, ctanh, ctanhl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex ctanhf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex ctanh( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex ctanhl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define tanh( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex hyperbolic tangent of `z`.

4) Type-generic macro: If `z` has type `long double complex`, `ctanhl` is called. if `z` has type `double complex`, `ctanh` is called, if `z` has type `float complex`, `ctanhf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`tanhf`, `tanh`, `tanhl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function tan, implementing the formula tanh(iy) = i tan(y), and the return type is imaginary.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, complex hyperbolic tangent of `z` is returned
若沒有發生錯誤，回傳 z 的複數雙曲正切。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
若實作支援 IEEE 浮點運算：

- `ctanh(conj(z)) == conj(ctanh(z))`
ctanh(conj(z)) == conj(ctanh(z))

- `ctanh(-z) == -ctanh(z)`
ctanh(-z) == -ctanh(z)

- If `z` is `+0+0i`, the result is `+0+0i`
如果 z 是 +0+0i，結果是 +0+0i

- If `z` is `x+∞i` (for any finite x), the result is `NaN+NaNi` and FE_INVALID is raised
如果 z 是 x+∞i（x 為任意 [ 1 ] 有限值），結果是 NaN+NaNi 並引發 FE_INVALID

- If `z` is `x+NaN` (for any finite x), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 x+NaN（x 為任意 [ 2 ] 有限值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `+∞+yi` (for any finite positive y), the result is `1+0i`
如果 z 是 +∞+yi（y 為任意有限正值），結果是 1+0i

- If `z` is `+∞+∞i`, the result is `1±0i` (the sign of the imaginary part is unspecified)
如果 z 是 +∞+∞i，結果是 1±0i（虛部的符號未指定）

- If `z` is `+∞+NaNi`, the result is `1±0i` (the sign of the imaginary part is unspecified)
如果 z 是 +∞+NaNi，結果是 1±0i（虛部的符號未指定）

- If `z` is `NaN+0i`, the result is `NaN+0i`
如果 z 是 NaN+0i，結果是 NaN+0i

- If `z` is `NaN+yi` (for any non-zero y), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi（y 為任意非零值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

- ↑ per DR471, this only holds for non-zero x. If `z` is `0+∞i`, the result should be `0+NaNi`
↑ 根據 DR471，這僅對非零 x 成立。如果 z 是 0+∞i，結果應為 0+NaNi

- ↑ per DR471, this only holds for non-zero x. If `z` is `0+NaNi`, the result should be `0+NaNi`
↑ 根據 DR471，這僅對非零 x 成立。如果 z 是 0+NaNi，結果應為 0+NaNi

### Notes
Mathematical definition of hyperbolic tangent is
雙曲正切的數學定義如下：
tanh z =
ez
-e-z

ez
+e-z

Hyperbolic tangent is an analytical function on the complex plane and has no branch cuts. It is periodic with respect to the imaginary component, with period πi, and has poles of the first order along the imaginary line, at coordinates (0, π(1/2 + n)). However no common floating-point representation is able to represent π/2 exactly, thus there is no value of the argument for which a pole error occurs.
雙曲正切在複平面上是解析函式，沒有分支切割；它以虛部為週期變數，週期為 πi。在虛軸上的 (0, π(1/2 + n)) 有一階極點。不過，常見的浮點格式都無法精確表示 π/2，因此沒有任何引數會觸發極點錯誤。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = ctanh(1); // behaves like real tanh along the real line  printf("tanh(1+0i) = %f%+fi (tanh(1)=%f)\n", creal(z), cimag(z), tanh(1));  double complex z2 = ctanh(I); // behaves like tangent along the imaginary line  printf("tanh(0+1i) = %f%+fi ( tan(1)=%f)\n", creal(z2), cimag(z2), tan(1)); }
```

Output:

```c
tanh(1+0i) = 0.761594+0.000000i (tanh(1)=0.761594) tanh(0+1i) = 0.000000+1.557408i ( tan(1)=1.557408)
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.6.6 The ctanh functions (p: 194)
7.3.6.6 ctanh 函式（頁：194）
7.3.6.6 ctanh 函式（頁：194）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.2.6 The ctanh functions (p: 542)
G.6.2.6 ctanh 函式（頁：542）
G.6.2.6 ctanh 函式（頁：542）

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.6.6 The ctanh functions (p: 176)
7.3.6.6 ctanh 函式（頁：176）
7.3.6.6 ctanh 函式（頁：176）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.2.6 The ctanh functions (p: 477)
G.6.2.6 ctanh 函式（頁：477）
G.6.2.6 ctanh 函式（頁：477）

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

csinhcsinhfcsinhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic sine
(function)   |

ccoshccoshfccoshl
(C99)(C99)(C99)
|   | computes the complex hyperbolic cosine
(function)   |

catanhcatanhfcatanhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic tangent
(function)   |

tanhtanhftanhl
(C99)(C99)
|   | computes hyperbolic tangent (tanhxtanh⁡xtanh(x))
(function)   |

C++ documentation for tanh

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/ctanh.html`
