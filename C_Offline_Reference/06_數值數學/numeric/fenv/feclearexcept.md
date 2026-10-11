# feclearexcept

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<fenv.h>`
|   |  |   |  |

```c
int feclearexcept( int excepts );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Attempts to clear the floating-point exceptions that are listed in the bitmask argument `excepts`, which is a bitwise OR of the floating-point exception macros.
嘗試清除 excepts 指定的浮點例外旗標。excepts 是多個浮點例外巨集的位元 OR 結果。

### Parameters

| excepts  |   | -  |   | bitmask listing the exception flags to clear  |

### Return value

`0` if all indicated exceptions were successfully cleared or if `excepts` is zero. Returns a non-zero value on error.
若所有指定的例外旗標都成功清除，或 excepts 為零，便回傳 0；否則回傳非零值。

### Example

Run this code

```c
#include <fenv.h> #include <stdio.h> #include <math.h> #include <float.h> /*  * A possible implementation of hypot which makes use of many advanced  * floating-point features.  */ double hypot_demo(double a, double b) {  const int range_problem = FE_OVERFLOW | FE_UNDERFLOW;  feclearexcept(range_problem);  // try a fast algorithm  double result = sqrt(a * a + b * b);  if (!fetestexcept(range_problem)) // no overflow or underflow  return result; // return the fast result  // do a more complicated calculation to avoid overflow or underflow  int a_exponent,b_exponent;  frexp(a, &a_exponent);  frexp(b, &b_exponent);  if (a_exponent - b_exponent > DBL_MAX_EXP)  return fabs(a) + fabs(b); // we can ignore the smaller value  // scale so that fabs(a) is near 1  double a_scaled = scalbn(a, -a_exponent);  double b_scaled = scalbn(b, -a_exponent);  // overflow and underflow is now impossible   result = sqrt(a_scaled * a_scaled + b_scaled * b_scaled);  // undo scaling  return scalbn(result, a_exponent); } int main(void) {  // Normal case takes the fast route  printf("hypot(%f, %f) = %f\n", 3.0, 4.0, hypot_demo(3.0, 4.0));  // Extreme case takes the slow but more accurate route  printf("hypot(%e, %e) = %e\n", DBL_MAX / 2.0,   DBL_MAX / 2.0,   hypot_demo(DBL_MAX / 2.0, DBL_MAX / 2.0));  return 0; }
```

Output:

```c
hypot(3.000000, 4.000000) = 5.000000 hypot(8.988466e+307, 8.988466e+307) = 1.271161e+308
```

### References

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.6.2.1 The feclearexcept function (p: 209)
7.6.2.1 feclearexcept 函式 (p: 209)
7.6.2.1 feclearexcept 函式 (p: 209)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.6.2.1 The feclearexcept function (p: 190)
7.6.2.1 feclearexcept 函式 (p: 190)
7.6.2.1 feclearexcept 函式 (p: 190)

### See also

fetestexcept
(C99)
|   | determines which of the specified floating-point status flags are set
(function)   |

C++ documentation for feclearexcept

---
來源頁路徑：`en.cppreference.com/c/numeric/fenv/feclearexcept.html`
