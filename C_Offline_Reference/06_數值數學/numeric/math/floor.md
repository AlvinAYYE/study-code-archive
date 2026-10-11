# floor, floorf, floorl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float floorf( float arg );
```
|   |  (1)  |   |  (since C99)  |

```c
double floor( double arg );
```
|   |  (2)  |   |   |

```c
long double floorl( long double arg );
```
|   |  (3)  |   |  (since C99)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define floor( arg )
```
|   |  (4)  |   |  (since C99)  |

|  |  |  |  |

1-3) Computes the largest integer value not greater than `arg`.

4) Type-generic macro: If `arg` has type `long double`, `floorl` is called. Otherwise, if `arg` has integer type or the type `double`, `floor` is called. Otherwise, `floorf` is called.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the largest integer value not greater than `arg`, that is ⌊arg⌋, is returned.
若沒有發生錯誤，回傳不大於 arg 的最大整數，也就是 ⌊arg⌋。

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
若 arg 為 NaN，回傳 NaN。

### Notes

FE_INEXACT may be (but isn't required to be) raised when rounding a non-integer finite value.
將有限的非整數捨入時，可能會引發 FE_INEXACT，但標準不要求一定引發。
The largest representable floating-point values are exact integers in all standard floating-point formats, so this function never overflows on its own; however the result may overflow any integer type (including intmax_t), when stored in an integer variable.
在所有標準浮點格式中，可表示的最大浮點值都是精確整數，因此此函式本身不會溢位；但若將結果存入整數變數，仍可能超出任何整數型別（包括 intmax_t）的範圍。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  printf("floor(+2.7) = %+.1f\n", floor(2.7));  printf("floor(-2.7) = %+.1f\n", floor(-2.7));  printf("floor(-0.0) = %+.1f\n", floor(-0.0));  printf("floor(-Inf) = %+f\n", floor(-INFINITY)); }
```

Possible output:
可能的輸出：

```c
floor(+2.7) = +2.0 floor(-2.7) = -3.0 floor(-0.0) = -0.0 floor(-Inf) = -inf
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.9.2 The floor functions (p: TBD)
7.12.9.2 floor 函式（p: TBD）
7.12.9.2 floor 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.2 The floor functions (p: TBD)
F.10.6.2 floor 函式（p: TBD）
F.10.6.2 floor 函式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.9.2 The floor functions (p: TBD)
7.12.9.2 floor 函式（p: TBD）
7.12.9.2 floor 函式（p: TBD）

- 7.25 Type-generic math <tgmath.h> (p: TBD)
7.25 型別泛型數學 <tgmath.h>（p: TBD）
7.25 型別泛型數學 <tgmath.h>（p: TBD）

- F.10.6.2 The floor functions (p: TBD)
F.10.6.2 floor 函式（p: TBD）
F.10.6.2 floor 函式（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.9.2 The floor functions (p: 251)
7.12.9.2 floor 函式（p: 251）
7.12.9.2 floor 函式（p: 251）

- 7.25 Type-generic math <tgmath.h> (p: 373-375)
7.25 泛型數學 <tgmath.h>（頁：373-375）
7.25 泛型數學 <tgmath.h>（頁：373-375）

- F.10.6.2 The floor functions (p: 526)
F.10.6.2 floor 函式（p: 526）
F.10.6.2 floor 函式（p: 526）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.9.2 The floor functions (p: 232)
7.12.9.2 floor 函式（p: 232）
7.12.9.2 floor 函式（p: 232）

- 7.22 Type-generic math <tgmath.h> (p: 335-337)
7.22 泛型數學 <tgmath.h>（頁：335-337）
7.22 泛型數學 <tgmath.h>（頁：335-337）

- F.9.6.2 The floor functions (p: 463)
F.9.6.2 floor 函式（p: 463）
F.9.6.2 floor 函式（p: 463）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.6.3 The floor function
4.5.6.3 floor 函式
4.5.6.3 floor 函式

### See also

ceilceilfceill
(C99)(C99)
|   | computes smallest integer not less than the given value
(function)   |

trunctruncftruncl
(C99)(C99)(C99)
|   | rounds to nearest integer not greater in magnitude than the given value
(function)   |

roundroundfroundllroundlroundflroundlllroundllroundfllroundl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to nearest integer, rounding away from zero in halfway cases
(function)   |

C++ documentation for floor

---
來源頁路徑：`en.cppreference.com/c/numeric/math/floor.html`
