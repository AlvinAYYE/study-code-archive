# fdim, fdimf, fdiml

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float fdimf( float x, float y );
```
|   |  (1)  |   |  (since C99)  |

```c
double fdim( double x, double y );
```
|   |  (2)  |   |  (since C99)  |

```c
long double fdiml( long double x, long double y );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define fdim( x, y )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Returns the positive difference between `x` and `y`, that is, if `x>y`, returns `x-y`, otherwise (if `x≤y`), returns +0.

4) Type-generic macro: If any argument has type `long double`, `fdiml` is called. Otherwise, if any argument has integer type or has type `double`, `fdim` is called. Otherwise, `fdimf` is called.

### Parameters

| x, y  |   | -  |   | floating-point value  |

### Return value

If successful, returns the positive difference between `x` and `y`.
成功時傳回 x 與 y 之間的正差值。
If a range error due to overflow occurs, +HUGE_VAL, `+HUGE_VALF`, or `+HUGE_VALL` is returned.
如果因上溢發生值域錯誤，則傳回 +HUGE_VAL 、 +HUGE_VALF 或 +HUGE_VALL 。
If a range error due to underflow occurs, the correct value (after rounding) is returned.
如果因下溢而發生值域錯誤，則傳回正確值（舍入後）。

### Error handling

Errors are reported as specified in Template:rllpt.
錯誤按照 Template:rllpt 中的說明報告。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If either argument is NaN, NaN is returned.
如果任一參數為 NaN，則傳回 NaN。

### Notes

Equivalent to `fmax(x-y, 0)` except for the NaN handling requirements.
除 NaN 處理要求外，等價於 fmax ( x - y , 0 ) 。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <math.h> #include <stdio.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("fdim(4, 1) = %f, fdim(1, 4)=%f\n", fdim(4,1), fdim(1,4));  printf("fdim(4,-1) = %f, fdim(1,-4)=%f\n", fdim(4,-1), fdim(1,-4));  //error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("fdim(1e308, -1e308) = %f\n", fdim(1e308, -1e308));  if (errno == ERANGE)  perror(" errno == ERANGE");  if (fetestexcept(FE_OVERFLOW))  puts(" FE_OVERFLOW raised"); }
```

Possible output:
可能的輸出：

```c
fdim(4, 1) = 3.000000, fdim(1, 4)=0.000000 fdim(4,-1) = 5.000000, fdim(1,-4)=5.000000 fdim(1e308, -1e308) = inf errno == ERANGE: Numerical result out of range FE_OVERFLOW raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.12.1 The fdim functions (p: TBD)
7.12.12.1 fdim 函式（p: TBD）
7.12.12.1 fdim 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.9.1 The fdim functions (p: TBD)
F.10.9.1 fdim 函式（p: TBD）
F.10.9.1 fdim 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.12.1 The fdim functions (p: 187-188)
7.12.12.1 fdim 函式（p: 187-188）
7.12.12.1 fdim 函式（p: 187-188）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.9.1 The fdim functions (p: 386)
F.10.9.1 fdim 函式（p: 386）
F.10.9.1 fdim 函式（p: 386）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.12.1 The fdim functions (p: 257)
7.12.12.1 fdim 函式（p: 257）
7.12.12.1 fdim 函式（p: 257）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.9.1 The fdim functions (p: 530)
F.10.9.1 fdim 函式（p: 530）
F.10.9.1 fdim 函式（p: 530）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.12.1 The fdim functions (p: 238)
7.12.12.1 fdim 函式（p: 238）
7.12.12.1 fdim 函式（p: 238）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.9.1 The fdim functions (p: 466)
F.9.9.1 fdim 函式（p: 466）
F.9.9.1 fdim 函式（p: 466）

### See also

abslabsllabs
(C99)
|   | computes absolute value of an integral value (|x||x||x|)
(function)   |

fmaxfmaxffmaxl
(C99)(C99)(C99)
|   | determines larger of two floating-point values
(function)   |

C++ documentation for fdim

---
來源頁路徑：`en.cppreference.com/c/numeric/math/fdim.html`
