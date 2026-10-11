# modf, modff, modfl

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
float modff( float arg, float* iptr );
```
|   |  (1)  |   |  (since C99)  |

```c
double modf( double arg, double* iptr );
```
|   |  (2)  |   |   |

```c
long double modfl( long double arg, long double* iptr );
```
|   |  (3)  |   |  (since C99)  |

|  |  |  |  |

1-3) Decomposes given floating-point value `arg` into integral and fractional parts, each having the same type and sign as `arg`. The integral part (in floating-point format) is stored in the object pointed to by `iptr`.

### Parameters

| arg  |   | -  |   | floating-point value  |

| iptr  |   | -  |   | pointer to floating-point value to store the integral part to  |

### Return value

If no errors occur, returns the fractional part of `arg` with the same sign as `arg`. The integral part is put into the value pointed to by `iptr`.
若未發生錯誤，傳回與 arg 符號相同的小數部分。整數部分被存入 iptr 所指向的值中。
The sum of the returned value and the value stored in `*iptr` gives `arg` (allowing for rounding).
傳回值與儲存在 * iptr 中的值之和等於 arg（允許舍入誤差）。

### Error handling

This function is not subject to any errors specified in math_errhandling.
本函式不受 math_errhandling 中指定的任何錯誤影響。
If the implementation supports IEEE floating-point arithmetic (IEC 60559),
若實作支援 IEEE 浮點運算（IEC 60559）：

- If `arg` is ±0, ±0 is returned, and ±0 is stored in `*iptr`.
如果 arg 為 ±0，則傳回 ±0，並將 ±0 存入 * iptr。

- If `arg` is ±∞, ±0 is returned, and ±∞ is stored in `*iptr`.
如果 arg 為 ±∞，則傳回 ±0，並將 ±∞ 存入 * iptr。

- If `arg` is NaN, NaN is returned, and NaN is stored in `*iptr`.
如果 arg 為 NaN，則傳回 NaN，並將 NaN 存入 * iptr。

- The returned value is exact, the current rounding mode is ignored.
傳回值是精確的，忽略目前舍入模式。

### Notes

This function behaves as if implemented as follows:
本函式的行為如同按如下方式實現：

```c
double modf(double value, double *iptr) { #pragma STDC FENV_ACCESS ON  int save_round = fegetround();  fesetround(FE_TOWARDZERO);  *iptr = std::nearbyint(value);  fesetround(save_round);  return copysign(isinf(value) ? 0.0 : value - (*iptr), value); }
```

### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h> int main(void) {  double f = 123.45;  printf("Given the number %.2f or %a in hex,\n", f, f);  double f3;  double f2 = modf(f, &f3);  printf("modf() makes %.2f + %.2f\n", f3, f2);  int i;  f2 = frexp(f, &i);  printf("frexp() makes %f * 2^%d\n", f2, i);  i = ilogb(f);  printf("logb()/ilogb() make %f * %d^%d\n", f / scalbn(1.0, i), FLT_RADIX, i);  // special values  f2 = modf(-0.0, &f3);  printf("modf(-0) makes %.2f + %.2f\n", f3, f2);  f2 = modf(-INFINITY, &f3);  printf("modf(-Inf) makes %.2f + %.2f\n", f3, f2); }
```

Possible output:
可能的輸出：

```c
Given the number 123.45 or 0x1.edccccccccccdp+6 in hex, modf() makes 123.00 + 0.45 frexp() makes 0.964453 * 2^7 logb()/ilogb() make 1.92891 * 2^6 modf(-0) makes -0.00 + -0.00 modf(-Inf) makes -INF + -0.00
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.6.12 The modf functions (p: TBD)
7.12.6.12 modf 函式 (p: TBD)
7.12.6.12 modf 函式 (p: TBD)

- F.10.3.12 The modf functions (p: TBD)
F.10.3.12 modf 函式 (p: TBD)
F.10.3.12 modf 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.6.12 The modf functions (p: TBD)
7.12.6.12 modf 函式 (p: TBD)
7.12.6.12 modf 函式 (p: TBD)

- F.10.3.12 The modf functions (p: TBD)
F.10.3.12 modf 函式 (p: TBD)
F.10.3.12 modf 函式 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.6.12 The modf functions (p: 246-247)
7.12.6.12 modf 函式 (p: 246-247)
7.12.6.12 modf 函式 (p: 246-247)

- F.10.3.12 The modf functions (p: 523)
F.10.3.12 modf 函式 (p: 523)
F.10.3.12 modf 函式 (p: 523)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.6.12 The modf functions (p: 227)
7.12.6.12 modf 函式 (p: 227)
7.12.6.12 modf 函式 (p: 227)

- F.9.3.12 The modf functions (p: 460)
F.9.3.12 modf 函式 (p: 460)
F.9.3.12 modf 函式 (p: 460)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5.4.6 The modf function
4.5.4.6 modf 函式
4.5.4.6 modf 函式

### See also

trunctruncftruncl
(C99)(C99)(C99)
|   | rounds to nearest integer not greater in magnitude than the given value
(function)   |

C++ documentation for modf

---
來源頁路徑：`en.cppreference.com/c/numeric/math/modf.html`
