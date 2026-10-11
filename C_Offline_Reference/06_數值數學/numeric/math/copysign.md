# copysign, copysignf, copysignl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float copysignf( float x, float y );
```
|   |  (1)  |   |  (since C99)  |

```c
double copysign( double x, double y );
```
|   |  (2)  |   |  (since C99)  |

```c
long double copysignl( long double x, long double y );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define copysign(x, y)
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Composes a floating-point value with the magnitude of `x` and the sign of `y`.

4) Type-generic macro: If any argument has type `long double`, `copysignl` is called. Otherwise, if any argument has integer type or has type `double`, `copysign` is called. Otherwise, `copysignf` is called.

### Parameters

| x, y  |   | -  |   | floating-point values  |

### Return value

If no errors occur, the floating-point value with the magnitude of `x` and the sign of `y` is returned.
若未發生錯誤，則傳回絕對值與 x 相同、符號與 y 相同的浮點值。
If `x` is NaN, then NaN with the sign of `y` is returned.
如果 x 為 NaN，則傳回帶 y 符號的 NaN。
If `y` is -0, the result is only negative if the implementation supports the signed zero consistently in arithmetic operations.
如果 y 為 -0，則只有當實現在算術運算中一致支援帶符號零時，結果才為負數。

### Error handling

This function is not subject to any errors specified in math_errhandling.
本函式不受 math_errhandling 中指定的任何錯誤影響。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- The returned value is exact (FE_INEXACT is never raised) and independent of the current rounding mode.
傳回值是精確的（從不引發 FE_INEXACT），且與目前舍入模式無關。

### Notes

`copysign` is the only portable way to manipulate the sign of a NaN value (to examine the sign of a NaN, signbit may also be used).
copysign 是操作 NaN 值符號的唯一可移植方式（要檢查 NaN 的符號，也可以使用 signbit）。

### Example

Run this code

```c
#include <math.h> #include <stdio.h>   int main(void) {  printf("copysign(1.0,+2.0) = %+.1f\n", copysign(1.0,+2.0));  printf("copysign(1.0,-2.0) = %+.1f\n", copysign(1.0,-2.0));  printf("copysign(INFINITY,-2.0) = %f\n", copysign(INFINITY,-2.0));  printf("copysign(NAN,-2.0) = %f\n", copysign(NAN,-2.0)); }
```

Possible output:
可能的輸出：

```c
copysign(1.0,+2.0) = +1.0 copysign(1.0,-2.0) = -1.0 copysign(INFINITY,-2.0) = -inf copysign(NAN,-2.0) = -nan
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.11.1 The copysign functions (p: TBD)
7.12.11.1 copysign 函式 (p: TBD)
7.12.11.1 copysign 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.8.1 The copysign functions (p: TBD)
F.10.8.1 copysign 函式 (p: TBD)
F.10.8.1 copysign 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.11.1 The copysign functions (p: TBD)
7.12.11.1 copysign 函式 (p: TBD)
7.12.11.1 copysign 函式 (p: TBD)

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.8.1 The copysign functions (p: TBD)
F.10.8.1 copysign 函式 (p: TBD)
F.10.8.1 copysign 函式 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.11.1 The copysign functions (p: 255)
7.12.11.1 copysign 函式 (p: 255)
7.12.11.1 copysign 函式 (p: 255)

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.8.1 The copysign functions (p: 529)
F.10.8.1 copysign 函式 (p: 529)
F.10.8.1 copysign 函式 (p: 529)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.11.1 The copysign functions (p: 236)
7.12.11.1 copysign 函式 (p: 236)
7.12.11.1 copysign 函式 (p: 236)

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.8.1 The copysign functions (p: 465)
F.9.8.1 copysign 函式 (p: 465)
F.9.8.1 copysign 函式 (p: 465)

### See also

fabsfabsffabsl
(C99)(C99)
|   | computes absolute value of a floating-point value (|x||x||x|)
(function)   |

signbit
(C99)
|   | checks if the given number is negative
(function macro)   |

C++ documentation for copysign

---
來源頁路徑：`en.cppreference.com/c/numeric/math/copysign.html`
