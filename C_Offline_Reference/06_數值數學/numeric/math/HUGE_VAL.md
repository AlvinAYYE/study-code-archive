# HUGE_VALF, HUGE_VAL, HUGE_VALL

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define HUGE_VALF /*implementation defined*/
```
|   |   |   |  (since C99)  |

```c
#define HUGE_VAL /*implementation defined*/
```
|   |   |   |   |

```c
#define HUGE_VALL /*implementation defined*/
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The `HUGE_VALF`, `HUGE_VAL` and `HUGE_VALL` macros expand to positive floating-point constant expressions which compare equal to the values returned by floating-point functions and operators in case of overflow (see math_errhandling).
HUGE_VALF、HUGE_VAL 和 HUGE_VALL 宏展開為正浮點常量表示式，其比較結果等於浮點函式和運運算元在溢位情況下傳回的值（參見 math_errhandling）。

| Constant  |   | Explanation  |

| `HUGE_VALF`  |   | Expands to positive `float` expression that indicates overflow  |

| `HUGE_VAL`  |   | Expands to positive `double` expression that indicates overflow, not necessarily representable as a `float`  |

| `HUGE_VALL`  |   | Expands to positive `long double` expression that indicates overflow, not necessarily representable as a `float` or `double`  |

On implementations that support floating-point infinities, these macros always expand to the positive infinities of `float`, `double`, and `long double`, respectively.
在支援浮點無窮大的實現上，這些宏分別展開為 float、double 和 long double 的正無窮大。

### Example

Run this code

```c
#include <math.h> #include <stdio.h> int main(void) {  const double result = 1.0 / 0.0;  printf("1.0/0.0 == %f\n", result);  if (result == HUGE_VAL)  puts("1.0/0.0 == HUGE_VAL"); }
```

Possible output:
可能的輸出：

```c
1.0/0.0 == inf 1.0/0.0 == HUGE_VAL
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)

- F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)

- F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)
F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 231)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 231)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 231)

- F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 517)
F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 517)
F.10/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 517)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 212)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 212)
7.12/3 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 212)

- F.9/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 454)
F.9/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 454)
F.9/2 HUGE_VAL, HUGE_VALF, HUGE_VALL (p: 454)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.5 HUGE_VAL

### See also

INFINITY
(C99)
|   | evaluates to positive infinity (if exists)
(macro constant)   |

C++ documentation for HUGE_VAL

---
來源頁路徑：`en.cppreference.com/c/numeric/math/HUGE_VAL.html`
