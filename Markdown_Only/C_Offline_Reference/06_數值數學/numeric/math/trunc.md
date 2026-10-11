# trunc, truncf, truncl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float truncf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double trunc( double arg );
```
|   |  (2)  |   |  (since C99)  |

```c
long double truncl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define trunc( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the nearest integer not greater in magnitude than `arg`.

4) Type-generic macro: If `arg` has type `long double`, `truncl` is called. Otherwise, if `arg` has integer type or the type `double`, `trunc` is called. Otherwise, `truncf` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the nearest integer value not greater in magnitude than `arg` (in other words, `arg` rounded towards zero), is returned.
若沒有發生錯誤，回傳絕對值不大於 arg 的最接近整數；也就是將 arg 朝零的方向捨入。

Return value

Argument

### Error handling

Errors are reported as specified in math_errhandling.
錯誤會依照 math_errhandling 的規定回報。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- The current rounding mode has no effect.
目前的捨入模式不會影響結果。

- If `arg` is ±∞, it is returned, unmodified.
若 arg 為 ±∞，則原樣回傳。

- If `arg` is ±0, it is returned, unmodified.
若 arg 為 ±0，則原樣回傳。

- If `arg` is NaN, NaN is returned.
如果 arg 為 NaN，則傳回 NaN。

### Notes

FE_INEXACT may be (but isn't required to be) raised when truncating a non-integer finite value.
在截斷非整數有限值時可能會引發 FE_INEXACT（但不要求必須引發）。
The largest representable floating-point values are exact integers in all standard floating-point formats, so this function never overflows on its own; however the result may overflow any integer type (including intmax_t), when stored in an integer variable.
在所有標準浮點格式中，可表示的最大浮點值都是精確整數，因此此函式本身絕不會上溢；但當結果存入整數變數時，可能會超出任何整數型別（包括 intmax_t ）的範圍。
The implicit conversion from floating-point to integral types also rounds towards zero, but is limited to the values that can be represented by the target type.
從浮點型別到整數型別的隱式轉換同樣向零舍入，但僅限於目標型別可表示的值。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  printf("trunc(+2.7) = %+.1f\n", trunc(+2.7));  printf("trunc(-2.7) = %+.1f\n", trunc(-2.7));  printf("trunc(-0.0) = %+.1f\n", trunc(-0.0));  printf("trunc(-Inf) = %+f\n", trunc(-INFINITY)); }
```

Possible output:
可能的輸出：

```c
trunc(+2.7) = +2.0 trunc(-2.7) = -2.0 trunc(-0.0) = -0.0 trunc(-Inf) = -inf
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.9.8 The trunc functions (p: TBD)
7.12.9.8 trunc 函式（p: TBD）
7.12.9.8 trunc 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.8 The trunc functions (p: TBD)
F.10.6.8 trunc 函式（p: TBD）
F.10.6.8 trunc 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.9.8 The trunc functions (p: TBD)
7.12.9.8 trunc 函式（p: TBD）
7.12.9.8 trunc 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.8 The trunc functions (p: TBD)
F.10.6.8 trunc 函式（p: TBD）
F.10.6.8 trunc 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.9.8 The trunc functions (p: 253-254)
7.12.9.8 trunc 函式（p: 253-254）
7.12.9.8 trunc 函式（p: 253-254）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.6.8 The trunc functions (p: 528)
F.10.6.8 trunc 函式（p: 528）
F.10.6.8 trunc 函式（p: 528）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.9.8 The trunc functions (p: 234)
7.12.9.8 trunc 函式（p: 234）
7.12.9.8 trunc 函式（p: 234）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.6.8 The trunc functions (p: 464)
F.9.6.8 trunc 函式（p: 464）
F.9.6.8 trunc 函式（p: 464）

### See also

floorfloorffloorl
(C99)(C99)
|   | computes largest integer not greater than the given value
(function)   |

ceilceilfceill
(C99)(C99)
|   | computes smallest integer not less than the given value
(function)   |

roundroundfroundllroundlroundflroundlllroundllroundfllroundl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to nearest integer, rounding away from zero in halfway cases
(function)   |

C++ documentation for trunc

---
來源頁路徑：`en.cppreference.com/c/numeric/math/trunc.html`
