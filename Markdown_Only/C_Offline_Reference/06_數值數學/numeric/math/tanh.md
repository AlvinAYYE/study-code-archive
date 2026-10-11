# tanh, tanhf, tanhl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float tanhf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double tanh( double arg );
```
|   |  (2)  |   |   |

```c
long double tanhl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define tanh( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the hyperbolic tangent of `arg`.

4) Type-generic macro: If the argument has type `long double`, `tanhl` is called. Otherwise, if the argument has integer type or the type `double`, `tanh` is called. Otherwise, `tanhf` is called. If the argument is complex, then the macro invokes the corresponding complex function (`ctanhf`, `ctanh`, `ctanhl`).

### Parameters

| arg  |   | -  |   | floating-point value representing a hyperbolic angle  |

### Return value
If no errors occur, the hyperbolic tangent of `arg` (tanh(arg), or
如果未發生錯誤，則傳回 arg 的雙曲正切（ tanh(arg) ，或
earg
-e-arg

earg
+e-arg

) is returned.
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, ±0 is returned.
如果參數為 ±0，則傳回 ±0。

- If the argument is ±∞, ±1 is returned.
如果參數為 ±∞，則傳回 ±1。

- If the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Notes

POSIX specifies that in case of underflow, `arg` is returned unmodified, and if that is not supported, an implementation-defined value no greater than DBL_MIN, FLT_MIN, and LDBL_MIN is returned.
POSIX 規定，在發生下溢的情況下原樣傳回 arg ；如果不支援此行為，則傳回一個不大於 DBL_MIN 、 FLT_MIN 和 LDBL_MIN 的由實現定義的值。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  printf("tanh(1) = %f\ntanh(-1) = %f\n", tanh(1), tanh(-1));  printf("tanh(0.1)*sinh(0.2)-cosh(0.2) = %f\n", tanh(0.1) * sinh(0.2) - cosh(0.2));  // special values  printf("tanh(+0) = %f\ntanh(-0) = %f\n", tanh(0.0), tanh(-0.0)); }
```

Output:

```c
tanh(1) = 0.761594 tanh(-1) = -0.761594 tanh(0.1)*sinh(0.2)-cosh(0.2) = -1.000000 tanh(+0) = 0.000000 tanh(-0) = -0.000000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.5.6 The tanh functions (p: TBD)
7.12.5.6 tanh 函式（p: TBD）
7.12.5.6 tanh 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.2.6 The tanh functions (p: TBD)
F.10.2.6 tanh 函式（p: TBD）
F.10.2.6 tanh 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.5.6 The tanh functions (p: TBD)
7.12.5.6 tanh 函式（p: TBD）
7.12.5.6 tanh 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.2.6 The tanh functions (p: TBD)
F.10.2.6 tanh 函式（p: TBD）
F.10.2.6 tanh 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.5.6 The tanh functions (p: 242)
7.12.5.6 tanh 函式（p: 242）
7.12.5.6 tanh 函式（p: 242）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.2.6 The tanh functions (p: 520)
F.10.2.6 tanh 函式（p: 520）
F.10.2.6 tanh 函式（p: 520）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.5.6 The tanh functions (p: 222-223)
7.12.5.6 tanh 函式（p: 222-223）
7.12.5.6 tanh 函式（p: 222-223）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.2.6 The tanh functions (p: 457)
F.9.2.6 tanh 函式（p: 457）
F.9.2.6 tanh 函式（p: 457）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.3.3 The tanh function
4.5.3.3 tanh 函式
4.5.3.3 tanh 函式

### See also

sinhsinhfsinhl
(C99)(C99)
|   | computes hyperbolic sine (sinhxsinh⁡xsinh(x))
(function)   |

coshcoshfcoshl
(C99)(C99)
|   | computes hyperbolic cosine (coshxcosh⁡xcosh(x))
(function)   |

atanhatanhfatanhl
(C99)(C99)(C99)
|   | computes inverse hyperbolic tangent (artanhxartanh⁡xartanh(x))
(function)   |

ctanhctanhfctanhl
(C99)(C99)(C99)
|   | computes the complex hyperbolic tangent
(function)   |

C++ documentation for tanh

---
來源頁路徑：`en.cppreference.com/c/numeric/math/tanh.html`
