# csinhf, csinh, csinhl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<complex.h>`
|   |  |   |  |

```c
float complex csinhf( float complex z );
```
|   |  (1)  |   |  (since C99)  |

```c
double complex csinh( double complex z );
```
|   |  (2)  |   |  (since C99)  |

```c
long double complex csinhl( long double complex z );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define sinh( z )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the complex hyperbolic sine of `z`.

4) Type-generic macro: If `z` has type `long double complex`, `csinhl` is called. if `z` has type `double complex`, `csinh` is called, if `z` has type `float complex`, `csinhf` is called. If `z` is real or integer, then the macro invokes the corresponding real function (`sinhf`, `sinh`, `sinhl`). If `z` is imaginary, then the macro invokes the corresponding real version of the function sin, implementing the formula sinh(iy) = i sin(y), and the return type is imaginary.

### Parameters

| z  |   | -  |   | complex argument  |

### Return value

If no errors occur, complex hyperbolic sine of `z` is returned
若沒有發生錯誤，回傳 z 的複數雙曲正弦。

### Error handling and special values
錯誤處理與特殊值

Errors are reported consistent with math_errhandling
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic,
若實作支援 IEEE 浮點運算：

- `csinh(conj(z)) == conj(csinh(z))`
csinh ( conj ( z )) == conj ( csinh ( z ))

- `csinh(z) == -csinh(-z)`
csinh ( z ) == - csinh ( - z )

- If `z` is `+0+0i`, the result is `+0+0i`
如果 z 是 +0+0i，結果是 +0+0i

- If `z` is `+0+∞i`, the result is `±0+NaNi` (the sign of the real part is unspecified) and FE_INVALID is raised
若 z 為 +0+∞i，結果為 ±0+NaNi（實部的符號未指定）並引發 FE_INVALID

- If `z` is `+0+NaNi`, the result is `±0+NaNi`
若 z 為 +0+NaNi，結果為 ±0+NaNi

- If `z` is `x+∞i` (for any positive finite x), the result is `NaN+NaNi` and FE_INVALID is raised
若 z 為 x+∞i（對任意有限正數 x），結果為 NaN+NaNi 並引發 FE_INVALID

- If `z` is `x+NaNi` (for any positive finite x), the result is `NaN+NaNi` and FE_INVALID may be raised
若 z 為 x+NaNi（對任意有限正數 x），結果為 NaN+NaNi，並且可能引發 FE_INVALID

- If `z` is `+∞+0i`, the result is `+∞+0i`
如果 z 是 +∞+0i，結果是 +∞+0i

- If `z` is `+∞+yi` (for any positive finite y), the result is `+∞cis(y)`
若 z 為 +∞+yi（對任意有限正數 y），結果為 +∞cis(y)

- If `z` is `+∞+∞i`, the result is `±∞+NaNi` (the sign of the real part is unspecified) and FE_INVALID is raised
若 z 為 +∞+∞i，結果為 ±∞+NaNi（實部的符號未指定）並引發 FE_INVALID

- If `z` is `+∞+NaNi`, the result is `±∞+NaNi` (the sign of the real part is unspecified)
若 z 為 +∞+NaNi，結果為 ±∞+NaNi（實部的符號未指定）

- If `z` is `NaN+0i`, the result is `NaN+0i`
如果 z 是 NaN+0i，結果是 NaN+0i

- If `z` is `NaN+yi` (for any finite nonzero y), the result is `NaN+NaNi` and FE_INVALID may be raised
如果 z 是 NaN+yi（y 為任意有限非零值），結果是 NaN+NaNi，並可能引發 FE_INVALID

- If `z` is `NaN+NaNi`, the result is `NaN+NaNi`
如果 z 是 NaN+NaNi，結果是 NaN+NaNi

where cis(y) is cos(y) + i sin(y)
其中 cis(y) = cos(y) + i sin(y)。

### Notes
Mathematical definition of hyperbolic sine is
雙曲正弦的數學定義如下：
sinh z =
ez
-e-z

2 |

Hyperbolic sine is an entire function in the complex plane and has no branch cuts. It is periodic with respect to the imaginary component, with period 2πi
雙曲正弦在複平面上是整函式，沒有分支切割；它以虛部為週期變數，週期為 2πi。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <complex.h> int main(void) {  double complex z = csinh(1); // behaves like real sinh along the real line  printf("sinh(1+0i) = %f%+fi (sinh(1)=%f)\n", creal(z), cimag(z), sinh(1));  double complex z2 = csinh(I); // behaves like sine along the imaginary line  printf("sinh(0+1i) = %f%+fi ( sin(1)=%f)\n", creal(z2), cimag(z2), sin(1)); }
```

Output:

```c
sinh(1+0i) = 1.175201+0.000000i (sinh(1)=1.175201) sinh(0+1i) = 0.000000+0.841471i ( sin(1)=0.841471)
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.3.6.5 The csinh functions (p: 194)
7.3.6.5 csinh 函式 (p: 194)
7.3.6.5 csinh 函式 (p: 194)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- G.6.2.5 The csinh functions (p: 541-542)
G.6.2.5 csinh 函式 (p: 541-542)
G.6.2.5 csinh 函式 (p: 541-542)

- G.7 Type-generic math <tgmath.h> (p: 545)
G.7 泛型數學 <tgmath.h>（頁：545）
G.7 泛型數學 <tgmath.h>（頁：545）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.3.6.5 The csinh functions (p: 175-176)
7.3.6.5 csinh 函式 (p: 175-176)
7.3.6.5 csinh 函式 (p: 175-176)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- G.6.2.5 The csinh functions (p: 476-477)
G.6.2.5 csinh 函式 (p: 476-477)
G.6.2.5 csinh 函式 (p: 476-477)

- G.7 Type-generic math <tgmath.h> (p: 480)
G.7 泛型數學 <tgmath.h>（頁：480）
G.7 泛型數學 <tgmath.h>（頁：480）

### See also

ccoshccoshfccoshl
(C99)(C99)(C99)
|   | computes the complex hyperbolic cosine
(function)   |

ctanhctanhfctanhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic tangent
(function)   |

casinhcasinhfcasinhl
(C99)(C99)(C99)
|   | computes the complex arc hyperbolic sine
(function)   |

sinhsinhfsinhl
(C99)(C99)
|   | computes hyperbolic sine (sinhxsinh⁡xsinh(x))
(function)   |

C++ documentation for sinh

---
來源頁路徑：`en.cppreference.com/c/numeric/complex/csinh.html`
