# roundeven, roundevenf, roundevenl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float roundevenf( float arg );
```
|   |  (1)  |   |  (since C23)  |

```c
double roundeven( double arg );
```
|   |  (2)  |   |  (since C23)  |

```c
long double roundevenl( long double arg );
```
|   |  (3)  |   |  (since C23)  |

Defined in header `<tgmath.h>`
|   |  |   |  |

```c
#define roundeven( arg )
```
|   |  (4)  |   |  (since C23)  |

|  |  |  |  |

1-3) Computes the nearest integer value to `arg` (in floating-point format), rounding halfway cases to nearest even integer, regardless of the current rounding mode.

4) Type-generic macro: If `arg` has type `long double`, `roundevenl` is called. Otherwise, if `arg` has integer type or the type `double`, `roundeven` is called. Otherwise, `roundevenf` is called, respectively.

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

If no errors occur, the nearest integer value to `arg`, rounding halfway cases to nearest even integer, is returned.
若未發生錯誤，則傳回最接近 arg 的整數值，恰好位於中間的值舍入到最接近的偶數。

### Error handling

This function is not subject to any of the errors specified in math_errhandling.
此函式不受 math_errhandling 中規定的任何錯誤影響。
If the implementation supports IEEE floating-point arithmetic (IEC 60559):
若實作支援 IEEE 浮點運算（IEC 60559）：

- FE_INEXACT is never raised.
從不引發 FE_INEXACT 。

- If `arg` is ±∞, it is returned, unmodified.
若 arg 為 ±∞，則原樣回傳。

- If `arg` is ±0, it is returned, unmodified.
若 arg 為 ±0，則原樣回傳。

- If `arg` is NaN, NaN is returned.
如果 arg 為 NaN，則傳回 NaN。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  printf("roundeven(+2.4) = %+.1f\n", roundeven(2.4));  printf("roundeven(-2.4) = %+.1f\n", roundeven(-2.4));  printf("roundeven(+2.5) = %+.1f\n", roundeven(2.5));  printf("roundeven(-2.5) = %+.1f\n", roundeven(-2.5));  printf("roundeven(+2.6) = %+.1f\n", roundeven(2.6));  printf("roundeven(-2.6) = %+.1f\n", roundeven(-2.6));  printf("roundeven(+3.5) = %+.1f\n", roundeven(3.5));  printf("roundeven(-3.5) = %+.1f\n", roundeven(-3.5));  printf("roundeven(-0.0) = %+.1f\n", roundeven(-0.0));  printf("roundeven(-Inf) = %+f\n", roundeven(-INFINITY)); }
```

Possible output:
可能的輸出：

```c
roundeven(+2.4) = +2.0 roundeven(-2.4) = -2.0 roundeven(+2.5) = +2.0 roundeven(-2.5) = -2.0 roundeven(+2.6) = +3.0 roundeven(-2.6) = -3.0 roundeven(+3.5) = +4.0 roundeven(-3.5) = -4.0 roundeven(-0.0) = -0.0 roundeven(-Inf) = -inf
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.9.8 The roundeven functions (p: 265-266)
7.12.9.8 roundeven 函式（p: 265-266）
7.12.9.8 roundeven 函式（p: 265-266）

- 7.27 Type-generic math <tgmath.h> (p: 386-390)
7.27 型別泛型數學 <tgmath.h>（p: 386-390）
7.27 型別泛型數學 <tgmath.h>（p: 386-390）

- F.10.6.8 The roundeven functions (p: 532)
F.10.6.8 roundeven 函式（p: 532）
F.10.6.8 roundeven 函式（p: 532）

### See also

rintrintfrintllrintlrintflrintlllrintllrintfllrintl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to an integer using current rounding mode with
exception if the result differs
(function)   |

roundroundfroundllroundlroundflroundlllroundllroundfllroundl
(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)(C99)
|   | rounds to nearest integer, rounding away from zero in halfway cases
(function)   |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/roundeven.html`
