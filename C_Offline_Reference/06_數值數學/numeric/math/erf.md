# erf, erff, erfl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float erff( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double erf( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double erfl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define erf( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the error function of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `erfl` is called. Otherwise, if `arg` has integer type or the type `double`, `erf` is called. Otherwise, `erff` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value
If no errors occur, value of the error function of `arg`, that is {{mathjax-or|2√π∫arg0e−t2dt2π∫0arge−t2dt|
如果未發生錯誤，則傳回 arg 的誤差函式值，即 {{mathjax-or| 2 √ π ∫ a r g 0 e − t 2 d t 2 π ∫ 0 a r g e − t 2 d t |
2 |
√π |
∫arg
0*e*d*t*}}, is returned. If a range error occurs due to underflow, the correct result (after rounding), that is 2⋅arg√π2⋅argπ
∫ arg 0 e -t 2 d t }}，予以傳回。 如果因下溢發生值域錯誤，則傳回正確結果（舍入後），即 2 ⋅ a r g √ π 2 ⋅ a r g π
2*arg |
√π |
, is returned.
### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, ±0 is returned
若參數為 ±0，回傳 ±0。

- If the argument is ±∞, ±1 is returned
若參數為 ±∞，回傳 ±1。

- If the argument is NaN, NaN is returned
若參數為 NaN，回傳 NaN。

### Notes

Underflow is guaranteed if `|arg| < DBL_MIN*(sqrt(π)/2)`.
若 |arg| < DBL_MIN * (sqrt(π) / 2)，一定會發生下溢。

erf(xσ√2)erf⁡(xσ2)
erf ( x σ √ 2 ) erf ⁡ ( x σ 2 )
erf(
x |
σ√2 |
)
is the probability that a measurement whose errors are subject to a normal distribution with standard deviation σσσ is less than xxx away from the mean value.
是這樣一個機率：其誤差服從標準差為 σ σ σ 的正態分佈的測量值，偏離均值的距離小於 x x x 。
### Example

Run this code

```c
#include <math.h> #include <stdio.h> double phi(double x1, double x2) {  return (erf(x2 / sqrt(2)) - erf(x1 / sqrt(2))) / 2; } int main(void) {  puts("normal variate probabilities:");  for (int n = -4; n < 4; ++n)  printf("[%2d:%2d]: %5.2f%%\n", n, n + 1, 100 * phi(n, n + 1));  puts("special values:");  printf("erf(-0) = %f\n", erf(-0.0));  printf("erf(Inf) = %f\n", erf(INFINITY)); }
```

Output:

```c
normal variate probabilities: [-4:-3]: 0.13% [-3:-2]: 2.14% [-2:-1]: 13.59% [-1: 0]: 34.13% [ 0: 1]: 34.13% [ 1: 2]: 13.59% [ 2: 3]: 2.14% [ 3: 4]: 0.13% special values: erf(-0) = -0.000000 erf(Inf) = 1.000000
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.8.1 The erf functions (p: 249)
7.12.8.1 erf 函式（p: 249）
7.12.8.1 erf 函式（p: 249）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.5.1 The erf functions (p: 525)
F.10.5.1 erf 函式（p: 525）
F.10.5.1 erf 函式（p: 525）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.8.1 The erf functions (p: 230)
7.12.8.1 erf 函式（p: 230）
7.12.8.1 erf 函式（p: 230）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.5.1 The erf functions (p: 462)
F.9.5.1 erf 函式（p: 462）
F.9.5.1 erf 函式（p: 462）

### See also

erfcerfcferfcl
(C99)(C99)(C99)
|   | computes complementary error function
(function)   |

C++ documentation for erf

### External links

| Weisstein, Eric W. "Erf." From MathWorld — A Wolfram Web Resource.  |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/erf.html`
