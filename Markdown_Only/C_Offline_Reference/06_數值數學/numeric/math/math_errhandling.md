# MATH_ERRNO, MATH_ERREXCEPT, math_errhandling

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define MATH_ERRNO 1
```
|   |   |   |  (since C99)  |

```c
#define MATH_ERREXCEPT 2
```
|   |   |   |  (since C99)  |

```c
#define math_errhandling /*implementation defined*/
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The macro constant `math_errhandling` expands to an expression of type `int` that is either equal to `MATH_ERRNO`, or equal to `MATH_ERREXCEPT`, or equal to their bitwise OR (`MATH_ERRNO | MATH_ERREXCEPT`).
宏常量 math_errhandling 展開為一個型別為 int 的表示式，其值等於 MATH_ERRNO ，或等於 MATH_ERREXCEPT ，或等於兩者的按位或（ MATH_ERRNO | MATH_ERREXCEPT ）。
The value of `math_errhandling` indicates the type of error handling that is performed by the floating-point operators and functions:
math_errhandling 的值指示浮點運運算元和函式所執行的錯誤處理型別：

| Constant  |   | Explanation  |

| `MATH_ERREXCEPT`  |   | indicates that floating-point exceptions are used: at least FE_DIVBYZERO, FE_INVALID, and FE_OVERFLOW are defined in `<fenv.h>`.  |

| `MATH_ERRNO`  |   | indicates that floating-point operations use the variable errno to report errors.  |

If the implementation supports IEEE floating-point arithmetic (IEC 60559), `math_errhandling & MATH_ERREXCEPT` is required to be non-zero.
如果實現支援 IEEE 浮點算術（IEC 60559），則要求 math_errhandling & MATH_ERREXCEPT 非零。
The following floating-point error conditions are recognized:
識別以下浮點錯誤條件：

| Condition |   | Explanation |   | errno |   | floating-point exception |   | Example  |

| Domain error  |   | the argument is outside the range in which the operation is mathematically defined (the description of each function lists the required domain errors)  |   | EDOM  |   | FE_INVALID  |   | `acos(2)`  |

| Pole error  |   | the mathematical result of the function is exactly infinite or undefined  |   | ERANGE  |   | FE_DIVBYZERO  |   | `log(0.0)`, `1.0/0.0`  |

| Range error due to overflow  |   | the mathematical result is finite, but becomes infinite after rounding, or becomes the largest representable finite value after rounding down  |   | ERANGE  |   | FE_OVERFLOW  |   | `pow(DBL_MAX,2)`  |

| Range error due to underflow  |   | the result is non-zero, but becomes zero after rounding, or becomes subnormal with a loss of precision  |   | ERANGE or unchanged (implementation-defined)  |   | FE_UNDERFLOW or nothing (implementation-defined)  |   | `DBL_TRUE_MIN/2`  |

| Inexact result  |   | the result has to be rounded to fit in the destination type  |   | unchanged  |   | FE_INEXACT or nothing (unspecified)  |   | `sqrt(2)`, `1.0/10.0`  |

### Notes

Whether FE_INEXACT is raised by the mathematical library functions is unspecified in general, but may be explicitly specified in the description of the function (e.g. rint vs nearbyint).
數學庫函式是否引發 FE_INEXACT 通常是未指定的，但可能在函式的說明中明確指定（例如 rint 與 nearbyint ）。
Before C99, floating-point exceptions were not specified, `EDOM` was required for any domain error, `ERANGE` was required for overflows and implementation-defined for underflows.
在 C99 之前，浮點異常未作規定，任何定義域錯誤都要求設定 EDOM ，上溢要求設定 ERANGE ，而下溢則由實現定義。

### Example

Run this code

```c
#include <stdio.h> #include <fenv.h> #include <math.h> #include <errno.h> #pragma STDC FENV_ACCESS ON int main(void) {  printf("MATH_ERRNO is %s\n", math_errhandling & MATH_ERRNO ? "set" : "not set");  printf("MATH_ERREXCEPT is %s\n",  math_errhandling & MATH_ERREXCEPT ? "set" : "not set");  feclearexcept(FE_ALL_EXCEPT);  errno = 0;  printf("log(0) = %f\n", log(0));  if(errno == ERANGE)  perror("errno == ERANGE");  if(fetestexcept(FE_DIVBYZERO))  puts("FE_DIVBYZERO (pole error) reported"); }
```

Possible output:
可能的輸出：

```c
MATH_ERRNO is set MATH_ERREXCEPT is set log(0) = -inf errno = ERANGE: Numerical result out of range FE_DIVBYZERO (pole error) reported
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling (p: 170)
7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling（p: 170）
7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling（p: 170）

- F.10/4 MATH_ERREXCEPT, math_errhandling (p: 377)
F.10/4 MATH_ERREXCEPT, math_errhandling（p: 377）
F.10/4 MATH_ERREXCEPT, math_errhandling（p: 377）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling (p: 233)
7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling（p: 233）
7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling（p: 233）

- F.10/4 MATH_ERREXCEPT, math_errhandling (p: 517)
F.10/4 MATH_ERREXCEPT, math_errhandling（p: 517）
F.10/4 MATH_ERREXCEPT, math_errhandling（p: 517）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling (p: 214)
7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling（p: 214）
7.12/9 MATH_ERRNO, MATH_ERREXCEPT, math_errhandling（p: 214）

- F.9/4 MATH_ERREXCEPT, math_errhandling> (p: 454)
F.9/4 MATH_ERREXCEPT, math_errhandling>（p: 454）
F.9/4 MATH_ERREXCEPT, math_errhandling>（p: 454）

### See also

FE_ALL_EXCEPTFE_DIVBYZEROFE_INEXACTFE_INVALIDFE_OVERFLOWFE_UNDERFLOW
(C99)
|   | floating-point exceptions
(macro constant)   |

errno
|   | macro which expands to POSIX-compatible thread-local error number variable
(macro variable)   |

C++ documentation for math_errhandling

---
來源頁路徑：`en.cppreference.com/c/numeric/math/math_errhandling.html`
