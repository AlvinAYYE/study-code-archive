# frexp, frexpf, frexpl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float frexpf( float arg, int* exp );
```
|   |  (1)  |   |  (since C99)  |

```c
double frexp( double arg, int* exp );
```
|   |  (2)  |   |   |

```c
long double frexpl( long double arg, int* exp );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define frexp( arg, exp )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Decomposes given floating-point value `x` into a normalized fraction and an integral power of two.

4) Type-generic macro: If `arg` has type `long double`, `frexpl` is called. Otherwise, if `arg` has integer type or the type `double`, `frexp` is called. Otherwise, `frexpf` is called, respectively.

### Parameters

| arg  |   | -  |   | floating-point value  |

| exp  |   | -  |   | pointer to integer value to store the exponent to  |

### Return value

If `arg` is zero, returns zero and stores zero in `*exp`.
若 arg 為零，回傳零，並在 *exp 中存入零。
Otherwise (if `arg` is not zero), if no errors occur, returns the value `x` in the range `(-1;-0.5], [0.5; 1)` and stores an integer value in `*exp` such that x×2(*exp)
=arg.
若 arg 非零且沒有發生錯誤，回傳 x，其中 x 的範圍為 (-1, -0.5] 或 [0.5, 1)，並將整數指數存入 *exp，使 x × 2^(*exp) = arg。
If the value to be stored in `*exp` is outside the range of `int`, the behavior is unspecified.
若要存入 *exp 的值超出 int 可表示範圍，行為未指定。
If `arg` is not a floating-point number, the behavior is unspecified.
若 arg 不是浮點數，行為未指定。

### Error handling

This function is not subject to any errors specified in math_errhandling.
此函式不受 math_errhandling 所列任何錯誤狀況影響。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If `arg` is ±0, it is returned, unmodified, and `0` is stored in `*exp`.
若 arg 為 ±0，原樣回傳，並在 *exp 中存入 0。

- If `arg` is ±∞, it is returned, and an unspecified value is stored in `*exp`.
若 arg 為 ±∞，回傳該值，並在 *exp 中存入未指定的值。

- If `arg` is NaN, NaN is returned, and an unspecified value is stored in `*exp`.
若 arg 為 NaN，回傳 NaN，並在 *exp 中存入未指定的值。

- No floating-point exceptions are raised.
不會引發任何浮點例外。

- If FLT_RADIX is `2` (or a power of 2), the returned value is exact, the current rounding mode is ignored.
若 FLT_RADIX 為 2（或 2 的冪次），回傳值是精確值，且不受目前捨入模式影響。

### Notes

On a binary system (where FLT_RADIX is `2`), `frexp` may be implemented as
在二進位系統（FLT_RADIX 為 2）中，frexp 可實作如下：

```c
{  *exp = (value == 0) ? 0 : (int)(1 + logb(value));  return scalbn(value, -(*exp)); }
```

The function `frexp`, together with its dual, ldexp, can be used to manipulate the representation of a floating-point number without direct bit manipulations.
frexp 和與它互補的 ldexp 可用來操作浮點數表示法，不必直接處理位元。

### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h> int main(void) {  double f = 123.45;  printf("Given the number %.2f or %a in hex,\n", f, f);  double f3;  double f2 = modf(f, &f3);  printf("modf() makes %.0f + %.2f\n", f3, f2);  int i;  f2 = frexp(f, &i);  printf("frexp() makes %f * 2^%d\n", f2, i);  i = ilogb(f);  printf("logb()/ilogb() make %f * %d^%d\n", f/scalbn(1.0, i), FLT_RADIX, i); }
```

Possible output:
可能的輸出：

```c
Given the number 123.45 or 0x1.edccccccccccdp+6 in hex, modf() makes 123 + 0.45 frexp() makes 0.964453 * 2^7 logb()/ilogb() make 1.92891 * 2^6
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.4 The frexp functions (p: TBD)
7.12.6.4 frexp 函式 (p: TBD)
7.12.6.4 frexp 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.4 The frexp functions (p: TBD)
F.10.3.4 frexp 函式 (p: TBD)
F.10.3.4 frexp 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.4 The frexp functions (p: TBD)
7.12.6.4 frexp 函式 (p: TBD)
7.12.6.4 frexp 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.3.4 The frexp functions (p: TBD)
F.10.3.4 frexp 函式 (p: TBD)
F.10.3.4 frexp 函式 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.4 The frexp functions (p: 243)
7.12.6.4 frexp 函式 (p: 243)
7.12.6.4 frexp 函式 (p: 243)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.4 The frexp functions (p: 521)
F.10.3.4 frexp 函式 (p: 521)
F.10.3.4 frexp 函式 (p: 521)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.4 The frexp functions (p: 224)
7.12.6.4 frexp 函式 (p: 224)
7.12.6.4 frexp 函式 (p: 224)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.4 The frexp functions (p: 458)
F.9.3.4 frexp 函式 (p: 458)
F.9.3.4 frexp 函式 (p: 458)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.4.2 The frexp function
4.5.4.2 frexp 函式
4.5.4.2 frexp 函式

### See also

ldexpldexpfldexpl
(C99)(C99)
|   | multiplies a number by 2 raised to a power
(function)   |

logblogbflogbl
(C99)(C99)(C99)
|   | extracts exponent of the given number
(function)   |

ilogbilogbfilogbl
(C99)(C99)(C99)
|   | extracts exponent of the given number
(function)   |

modfmodffmodfl
(C99)(C99)
|   | breaks a number into integer and fractional parts
(function)   |

C++ documentation for frexp

---
來源頁路徑：`en.cppreference.com/c/numeric/math/frexp.html`
