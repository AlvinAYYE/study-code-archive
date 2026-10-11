# log2, log2f, log2l

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float log2f( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double log2( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double log2l( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define log2( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the base `2` logarithm of `arg`.

4) Type-generic macro: If `arg` has type `long double`, `log2l` is called. Otherwise, if `arg` has integer type or the type `double`, `log2` is called. Otherwise, `log2f` is called.

### Parameters

| arg  |   | -  |   | floating point value  |

### Return value

If no errors occur, the base-*2* logarithm of `arg` (log2(arg) or lb(arg)) is returned.
如果未發生錯誤，則傳回 arg 的以 2 為底的對數（ log 2 (arg) 或 lb(arg) ）。
If a domain error occurs, an implementation-defined value is returned (NaN where supported).
若發生定義域錯誤，回傳由實作定義的值（若支援則回傳 NaN）。
If a pole error occurs, -HUGE_VAL, `-HUGE_VALF`, or `-HUGE_VALL` is returned.
若發生極點錯誤，回傳 -HUGE_VAL、-HUGE_VALF 或 -HUGE_VALL。

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
Domain error occurs if `arg` is less than zero.
若 arg 小於零，會發生定義域錯誤。
Pole error may occur if `arg` is zero.
若 arg 為零，可能會發生極點錯誤。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If the argument is ±0, -∞ is returned and FE_DIVBYZERO is raised.
如果參數為 ±0，則傳回 -∞ 並引發 FE_DIVBYZERO 。

- If the argument is 1, +0 is returned
如果參數為 1，則傳回 +0

- If the argument is negative, NaN is returned and FE_INVALID is raised.
如果參數為負數，則傳回 NaN 並引發 FE_INVALID 。

- If the argument is +∞, +∞ is returned
如果參數為 +∞，則傳回 +∞

- If the argument is NaN, NaN is returned
如果參數為 NaN，則傳回 NaN

### Notes

For integer `arg`, the binary logarithm can be interpreted as the zero-based index of the most significant 1 bit in the input.
對於整數 arg ，二進位制對數可解釋為輸入中最高有效 1 位的從零開始的索引。

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <float.h> #include <errno.h> #include <fenv.h> // #pragma STDC FENV_ACCESS ON int main(void) {  printf("log2(65536) = %f\n", log2(65536));  printf("log2(0.125) = %f\n", log2(0.125));  printf("log2(0x020f) = %f (highest set bit is in position 9)\n", log2(0x020f));  printf("base-5 logarithm of 125 = %f\n", log2(125)/log2(5));  // special values  printf("log2(1) = %f\n", log2(1));  printf("log2(+Inf) = %f\n", log2(INFINITY));  //error handling  errno = 0; feclearexcept(FE_ALL_EXCEPT);  printf("log2(0) = %f\n", log2(0));  if(errno == ERANGE) perror(" errno == ERANGE");  if(fetestexcept(FE_DIVBYZERO)) puts(" FE_DIVBYZERO raised"); }
```

Possible output:
可能的輸出：

```c
log2(65536) = 16.000000 log2(0.125) = -3.000000 log2(0x020f) = 9.041659 (highest set bit is in position 9) base-5 logarithm of 125 = 3.000000 log2(1) = 0.000000 log2(+Inf) = inf log2(0) = -inf errno == ERANGE: Numerical result out of range FE_DIVBYZERO raised
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.10 The log2 functions (p: 179)
7.12.6.10 log2 函式（p: 179）
7.12.6.10 log2 函式（p: 179）

- 7.25 Type-generic math <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)
7.25 型別通用數學 <tgmath.h> (p: 272-273)

- F.10.3.10 The log2 functions (p: 381)
F.10.3.10 log2 函式（p: 381）
F.10.3.10 log2 函式（p: 381）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.10 The log2 functions (p: 246)
7.12.6.10 log2 函式（p: 246）
7.12.6.10 log2 函式（p: 246）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.3.10 The log2 functions (p: 522)
F.10.3.10 log2 函式（p: 522）
F.10.3.10 log2 函式（p: 522）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.10 The log2 functions (p: 226)
7.12.6.10 log2 函式（p: 226）
7.12.6.10 log2 函式（p: 226）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.3.10 The log2 functions (p: 459)
F.9.3.10 log2 函式（p: 459）
F.9.3.10 log2 函式（p: 459）

### See also

loglogflogl
(C99)(C99)
|   | computes natural (base-*e*) logarithm (lnxln⁡xln(x))
(function)   |

log10log10flog10l
(C99)(C99)
|   | computes common (base-*10*) logarithm (log10xlog10⁡xlog10(x))
(function)   |

log1plog1pflog1pl
(C99)(C99)(C99)
|   | computes natural (base-*e*) logarithm of 1 plus the given number (ln(1+x)ln⁡(1+x)ln(1+x))
(function)   |

exp2exp2fexp2l
(C99)(C99)(C99)
|   | computes *2* raised to the given power (2x2x2)
(function)   |

C++ documentation for log2

---
來源頁路徑：`en.cppreference.com/c/numeric/math/log2.html`
