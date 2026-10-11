# fpclassify

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define fpclassify(arg) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Categorizes floating-point value `arg` into the following categories: zero, subnormal, normal, infinite, NAN, or implementation-defined category. The macro returns an integral value.
把浮點值 arg 歸入以下類別之一：零、次正規、正規、無窮大、NAN 或實現定義的類別。該宏傳回一個整數值。
FLT_EVAL_METHOD is ignored: even if the argument is evaluated with more range and precision than its type, it is first converted to its semantic type, and the classification is based on that: a normal long double value might become subnormal when converted to double and zero when converted to `float`.
FLT_EVAL_METHOD 被忽略：即使參數求值所用的值域和精度高於其型別，它也會先被轉換為其語意型別，分類基於該型別進行：一個正常的 long double 值在轉換為 double 時可能變為次正規值，而在轉換為 float 時可能變為零。

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

One of FP_INFINITE, FP_NAN, FP_NORMAL, FP_SUBNORMAL, FP_ZERO or implementation-defined type, specifying the category of `arg`.
FP_INFINITE、FP_NAN、FP_NORMAL、FP_SUBNORMAL、FP_ZERO 或實現定義的型別之一，用於指明 arg 的類別。

### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h> const char* show_classification(double x) {  switch(fpclassify(x))  {  case FP_INFINITE: return "Inf";  case FP_NAN: return "NaN";  case FP_NORMAL: return "normal";  case FP_SUBNORMAL: return "subnormal";  case FP_ZERO: return "zero";  default: return "unknown";  } } int main(void) {  printf("1.0/0.0 is %s\n", show_classification(1 / 0.0));  printf("0.0/0.0 is %s\n", show_classification(0.0 / 0.0));  printf("DBL_MIN/2 is %s\n", show_classification(DBL_MIN / 2));  printf("-0.0 is %s\n", show_classification(-0.0));  printf("1.0 is %s\n", show_classification(1.0)); }
```

Output:

```c
1.0/0.0 is Inf 0.0/0.0 is NaN DBL_MIN/2 is subnormal -0.0 is zero 1.0 is normal
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.3.1 The fpclassify macro (p: TBD)
7.12.3.1 fpclassify 宏 (p: TBD)
7.12.3.1 fpclassify 宏 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.3.1 The fpclassify macro (p: TBD)
7.12.3.1 fpclassify 宏 (p: TBD)
7.12.3.1 fpclassify 宏 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.3.1 The fpclassify macro (p: 235)
7.12.3.1 fpclassify 宏 (p: 235)
7.12.3.1 fpclassify 宏 (p: 235)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.3.1 The fpclassify macro (p: 216)
7.12.3.1 fpclassify 宏 (p: 216)
7.12.3.1 fpclassify 宏 (p: 216)

### See also

isfinite
(C99)
|   | checks if the given number has finite value
(function macro)   |

isinf
(C99)
|   | checks if the given number is infinite
(function macro)   |

isnan
(C99)
|   | checks if the given number is NaN
(function macro)   |

isnormal
(C99)
|   | checks if the given number is normal
(function macro)   |

C++ documentation for fpclassify

---
來源頁路徑：`en.cppreference.com/c/numeric/math/fpclassify.html`
