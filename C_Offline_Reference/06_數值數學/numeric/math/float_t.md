# float_t, double_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
typedef /* implementation-defined */ float_t
```
|   |   |   |  (since C99)  |

```c
typedef /* implementation-defined */ double_t
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The types `float_t` and `double_t` are floating types at least as wide as `float` and `double`, respectively, and such that `double_t` is at least as wide as `float_t`. The value of FLT_EVAL_METHOD determines the types of `float_t` and `double_t`.
型別 float_t 和 double_t 分別是至少與 float 和 double 一樣寬的浮點型別，並且 double_t 至少與 float_t 一樣寬。FLT_EVAL_METHOD 的值決定了 float_t 和 double_t 的型別。

| `FLT_EVAL_METHOD`  |   | Explanation  |

| `0`  |   | `float_t` and `double_t` are equivalent to `float` and `double`, respectively  |

| `1`  |   | both `float_t` and `double_t` are equivalent to `double`  |

| `2`  |   | both `float_t` and `double_t` are equivalent to `long double`  |

| `other`  |   | both `float_t` and `double_t` are implementation defined  |

### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h> #define SHOW(expr) printf("%s = %d\n", #expr, (int)(expr)) int main() {  SHOW(FLT_EVAL_METHOD);  SHOW(sizeof(float));  SHOW(sizeof(float_t));  SHOW(sizeof(double));  SHOW(sizeof(double_t)); }
```

Possible output:
可能的輸出：

```c
FLT_EVAL_METHOD = 1 sizeof(float) = 4 sizeof(float_t) = 8 sizeof(double) = 8 sizeof(double_t) = 8
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12 Mathematics <math.h> (p: TBD)
7.12 數學 <math.h>（p: TBD）
7.12 數學 <math.h>（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12 Mathematics <math.h> (p: TBD)
7.12 數學 <math.h>（p: TBD）
7.12 數學 <math.h>（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12 Mathematics <math.h> (p: 231)
7.12 數學 <math.h>（p: 231）
7.12 數學 <math.h>（p: 231）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12 Mathematics <math.h> (p: 212)
7.12 數學 <math.h>（p: 212）
7.12 數學 <math.h>（p: 212）

### See also

FLT_EVAL_METHOD
(C99)
|   | specifies in what precision all arithmetic operations are done
(macro constant)  |

---
來源頁路徑：`en.cppreference.com/c/numeric/math/float_t.html`
