# acos, acosf, acosl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float acosf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double acos( double arg );
```
|   |  (2)  |   |   |

```c
long double acosl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

```c
_Decimal32 acosd32( _Decimal32 arg );
```
|   |  (4)  |   |  (since C23)  |

```c
_Decimal64 acosd64( _Decimal64 arg );
```
|   |  (5)  |   |  (since C23)  |

```c
_Decimal128 acosd128( _Decimal128 arg );
```
|   |  (6)  |   |  (since C23)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define acos( arg )
```
|   |  (7)  |   |  (since C99)  |

|  |  |  |  |

1-6) Computes the principal value of the arc cosine of `arg`.

7) Type-generic macro: If the argument has type `long double`, (3) (`acosl`) is called. Otherwise, if the argument has integer type or the type `double`, (2) (`acos`) is called. Otherwise, (1) (`acosf`) is called. If the argument is complex, then the macro invokes the corresponding complex function (cacosf, cacos, cacosl).

The functions (4-6) are declared if and only if the implementation predefines `__STDC_IEC_60559_DFP__` (i.e. the implementation supports decimal floating-point numbers).
|   | (since C23) |

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the arc cosine of `arg` (arccos(arg)) in the range [0 ; π], is returned.
若未發生錯誤，則傳回 arg 的反餘弦（ arccos(arg) ），其取值範圍為 [0 ; π] 。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a range error occurs due to underflow, the correct result (after rounding) is returned.
若因浮點下溢而發生值域錯誤，回傳正確結果（經捨入後）。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error occurs if `arg` is outside the range `[-1.0; 1.0]`.
如果 arg 超出範圍 [-1.0; 1.0]，則發生定義域錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is +1, the value `+0` is returned;
若參數為 +1，則傳回 +0；

- If |arg| > 1, a domain error occurs and NaN is returned;
若 |arg| > 1，則發生定義域錯誤並傳回 NaN；

- if the argument is NaN, NaN is returned.
若參數為 NaN，回傳 NaN。

### Example

Run this code

```c
#include <errno.h> #include <fenv.h> #include <math.h> #include <stdio.h> #include <string.h> #ifndef __GNUC__ #pragma STDC FENV_ACCESS ON #endif int main(void) {  printf("acos(-1) = %f\n", acos(-1));  printf("acos(0.0) = %f 2*acos(0.0) = %f\n", acos(0), 2 * acos(0));  printf("acos(0.5) = %f 3*acos(0.5) = %f\n", acos(0.5), 3 * acos(0.5));  printf("acos(1) = %f\n", acos(1));  // error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("acos(1.1) = %f\n", acos(1.1));  if (errno == EDOM)  perror(" errno == EDOM");  if (fetestexcept(FE_INVALID))  puts(" FE_INVALID raised"); }
```

Possible output:
可能的輸出：

```c
acos(-1) = 3.141593 acos(0.0) = 1.570796 2*acos(0.0) = 3.141593 acos(0.5) = 1.047198 3*acos(0.5) = 3.141593 acos(1) = 0.000000 acos(1.1) = nan errno == EDOM: Numerical argument out of domain FE_INVALID raised
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.4.1 The acos functions (p: TBD)
7.12.4.1 acos 函式（p: TBD）
7.12.4.1 acos 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.1.1 The acos functions (p: TBD)
F.10.1.1 acos 函式（p: TBD）
F.10.1.1 acos 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.4.1 The acos functions (p: 173)
7.12.4.1 acos 函式（p: 173）
7.12.4.1 acos 函式（p: 173）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.1.1 The acos functions (p: 378)
F.10.1.1 acos 函式（p: 378）
F.10.1.1 acos 函式（p: 378）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.4.1 The acos functions (p: 238)
7.12.4.1 acos 函式（p: 238）
7.12.4.1 acos 函式（p: 238）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.1.1 The acos functions (p: 518)
F.10.1.1 acos 函式（p: 518）
F.10.1.1 acos 函式（p: 518）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.4.1 The acos functions (p: 218)
7.12.4.1 acos 函式（p: 218）
7.12.4.1 acos 函式（p: 218）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.1.1 The acos functions (p: 455)
F.9.1.1 acos 函式（p: 455）
F.9.1.1 acos 函式（p: 455）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.2.1 The acos function
4.5.2.1 acos 函式
4.5.2.1 acos 函式

### See also

asinasinfasinl
(C99)(C99)
|   | computes arc sine (arcsinxarcsin⁡xarcsin(x))
(function)   |

atanatanfatanl
(C99)(C99)
|   | computes arc tangent (arctanxarctan⁡xarctan(x))
(function)   |

atan2atan2fatan2l
(C99)(C99)
|   | computes arc tangent, using signs to determine quadrants
(function)   |

coscosfcosl
(C99)(C99)
|   | computes cosine (cosxcos⁡xcos(x))
(function)   |

cacoscacosfcacosl
(C99)(C99)(C99)
|   | computes the complex arc cosine
(function)   |

C++ documentation for acos

---
來源頁路徑：`en.cppreference.com/c/numeric/math/acos.html`
