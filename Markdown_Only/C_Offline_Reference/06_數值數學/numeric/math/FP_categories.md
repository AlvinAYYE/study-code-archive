# FP_NORMAL, FP_SUBNORMAL, FP_ZERO, FP_INFINITE, FP_NAN

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define FP_NORMAL /*implementation defined*/
```
|   |   |   |  (since C99)  |

```c
#define FP_SUBNORMAL /*implementation defined*/
```
|   |   |   |  (since C99)  |

```c
#define FP_ZERO /*implementation defined*/
```
|   |   |   |  (since C99)  |

```c
#define FP_INFINITE /*implementation defined*/
```
|   |   |   |  (since C99)  |

```c
#define FP_NAN /*implementation defined*/
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The `FP_NORMAL`, `FP_SUBNORMAL`, `FP_ZERO`, `FP_INFINITE`, `FP_NAN` macros each represent a distinct category of floating-point numbers. They all expand to an integer constant expression.
FP_NORMAL、FP_SUBNORMAL、FP_ZERO、FP_INFINITE、FP_NAN 宏各自表示一個不同的浮點數類別。它們都展開為一個整數常量表示式。

| Constant  |   | Explanation  |

| `FP_NORMAL`  |   | indicates that the value is *normal*, i.e. not an infinity, subnormal, not-a-number or zero  |

| `FP_SUBNORMAL`  |   | indicates that the value is *subnormal*  |

| `FP_ZERO`  |   | indicates that the value is positive or negative zero  |

| `FP_INFINITE`  |   | indicates that the value is not representable by the underlying type (positive or negative infinity)  |

| `FP_NAN`  |   | indicates that the value is not-a-number (NaN)  |

### Example

Run this code

```c
#include <stdio.h> #include <math.h> #include <float.h> const char *show_classification(double x) {  switch(fpclassify(x)) {  case FP_INFINITE: return "Inf";  case FP_NAN: return "NaN";  case FP_NORMAL: return "normal";  case FP_SUBNORMAL: return "subnormal";  case FP_ZERO: return "zero";  default: return "unknown";  } } int main(void) {  printf("1.0/0.0 is %s\n", show_classification(1/0.0));  printf("0.0/0.0 is %s\n", show_classification(0.0/0.0));  printf("DBL_MIN/2 is %s\n", show_classification(DBL_MIN/2));  printf("-0.0 is %s\n", show_classification(-0.0));  printf(" 1.0 is %s\n", show_classification(1.0)); }
```

Output:

```c
1.0/0.0 is Inf 0.0/0.0 is NaN DBL_MIN/2 is subnormal -0.0 is zero 1.0 is normal
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12/6 FP_NORMAL, ... (p: 169-170)
7.12/6 FP_NORMAL, ... (p: 169-170)
7.12/6 FP_NORMAL, ... (p: 169-170)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12/6 FP_NORMAL, ... (p: 232)
7.12/6 FP_NORMAL, ... (p: 232)
7.12/6 FP_NORMAL, ... (p: 232)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12/6 FP_NORMAL, ... (p: 213)
7.12/6 FP_NORMAL, ... (p: 213)
7.12/6 FP_NORMAL, ... (p: 213)

### See also

fpclassify
(C99)
|   | classifies the given floating-point value
(function macro)   |

C++ documentation for FP_categories

---
來源頁路徑：`en.cppreference.com/c/numeric/math/FP_categories.html`
