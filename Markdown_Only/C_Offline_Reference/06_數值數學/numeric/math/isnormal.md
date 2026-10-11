# isnormal

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define isnormal(arg) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the given floating-point number `arg` is normal, i.e. is neither zero, subnormal, infinite, nor `NaN`. The macro returns an integral value.
判斷浮點數 arg 是否為正規值，也就是既非零、非正規數、無窮大，也不是 NaN。此巨集會回傳整數。
FLT_EVAL_METHOD is ignored: even if the argument is evaluated with more range and precision than its type, it is first converted to its semantic type, and the classification is based on that.
此處會忽略 FLT_EVAL_METHOD：即使參數以比其型別更大的範圍或精度求值，也會先轉換成其語意型別，再依該型別分類。

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

Nonzero integral value if `arg` is normal, `0` otherwise.
若 arg 是正規值，回傳非零整數；否則回傳 0。

### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h>   int main(void) {  printf("isnormal(NAN) = %d\n", isnormal(NAN));  printf("isnormal(INFINITY) = %d\n", isnormal(INFINITY));  printf("isnormal(0.0) = %d\n", isnormal(0.0));  printf("isnormal(DBL_MIN/2.0) = %d\n", isnormal(DBL_MIN / 2.0));  printf("isnormal(1.0) = %d\n", isnormal(1.0)); }
```

Output:

```c
isnormal(NAN) = 0 isnormal(INFINITY) = 0 isnormal(0.0) = 0 isnormal(DBL_MIN/2.0) = 0 isnormal(1.0) = 1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.3.5 The isnormal macro (p: TBD)
7.12.3.5 isnormal 宏（p: TBD）
7.12.3.5 isnormal 宏（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.3.5 The isnormal macro (p: TBD)
7.12.3.5 isnormal 宏（p: TBD）
7.12.3.5 isnormal 宏（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.3.5 The isnormal macro (p: 237)
7.12.3.5 isnormal 宏（p: 237）
7.12.3.5 isnormal 宏（p: 237）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.3.5 The isnormal macro (p: 217-218)
7.12.3.5 isnormal 宏（p: 217-218）
7.12.3.5 isnormal 宏（p: 217-218）

### See also

fpclassify
(C99)
|   | classifies the given floating-point value
(function macro)   |

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

C++ documentation for isnormal

---
來源頁路徑：`en.cppreference.com/c/numeric/math/isnormal.html`
