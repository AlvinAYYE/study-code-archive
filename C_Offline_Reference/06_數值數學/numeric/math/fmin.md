# fmin, fminf, fminl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float fminf( float x, float y );
```
|   |  (1)  |   |  (since C99)  |

```c
double fmin( double x, double y );
```
|   |  (2)  |   |  (since C99)  |

```c
long double fminl( long double x, long double y );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define fmin( x, y )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Returns the smaller of two floating-point arguments, treating NaNs as missing data (between a NaN and a numeric value, the numeric value is chosen).

4) Type-generic macro: If any argument has type `long double`, `fminl` is called. Otherwise, if any argument has integer type or has type `double`, `fmin` is called. Otherwise, `fminf` is called.

### Parameters

| x, y  |   | -  |   | floating-point values  |

### Return value

If successful, returns the smaller of two floating-point values. The value returned is exact and does not depend on any rounding modes.
成功時傳回兩個浮點值中較小的一個。傳回的值是精確的，不依賴於任何舍入模式。

### Error handling

This function is not subject to any of the error conditions specified in math_errhandling.
本函式不受 math_errhandling 中指定的任何錯誤條件影響。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If one of the two arguments is NaN, the value of the other argument is returned
若兩個參數中有一個為 NaN，則傳回另一個參數的值

- Only if both arguments are NaN, NaN is returned
只有當兩個參數均為 NaN 時，才傳回 NaN

### Notes

This function is not required to be sensitive to the sign of zero, although some implementations additionally enforce that if one argument is +0 and the other is -0, then -0 is returned.
本函式不要求對零的符號敏感，不過有些實現額外規定：若一個參數為 +0 而另一個為 -0，則傳回 -0。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  printf("fmin(2,1) = %f\n", fmin(2, 1));  printf("fmin(-Inf,0) = %f\n", fmin(-INFINITY, 0));  printf("fmin(NaN,-1) = %f\n", fmin(NAN, -1)); }
```

Possible output:
可能的輸出：

```c
fmin(2,1) = 1.000000 fmin(-Inf,0) = -inf fmin(NaN,-1) = -1.000000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.12.3 The fmin functions (p: TBD)
7.12.12.3 fmin 函式（p: TBD）
7.12.12.3 fmin 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.9.3 The fmin functions (p: TBD)
F.10.9.3 fmin 函式（p: TBD）
F.10.9.3 fmin 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.12.3 The fmin functions (p: TBD)
7.12.12.3 fmin 函式（p: TBD）
7.12.12.3 fmin 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.9.3 The fmin functions (p: TBD)
F.10.9.3 fmin 函式（p: TBD）
F.10.9.3 fmin 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.12.3 The fmin functions (p: 258)
7.12.12.3 fmin 函式（p: 258）
7.12.12.3 fmin 函式（p: 258）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.9.3 The fmin functions (p: 530)
F.10.9.3 fmin 函式（p: 530）
F.10.9.3 fmin 函式（p: 530）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.12.3 The fmin functions (p: 239)
7.12.12.3 fmin 函式（p: 239）
7.12.12.3 fmin 函式（p: 239）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.9.3 The fmin functions (p: 466)
F.9.9.3 fmin 函式（p: 466）
F.9.9.3 fmin 函式（p: 466）

### See also

isless
(C99)
|   | checks if the first floating-point argument is less than the second
(function macro)   |

fmaxfmaxffmaxl
(C99)(C99)(C99)
|   | determines larger of two floating-point values
(function)   |

C++ documentation for fmin

---
來源頁路徑：`en.cppreference.com/c/numeric/math/fmin.html`
