# isfinite

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define isfinite(arg) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the given floating-point number `arg` has finite value i.e. it is normal, subnormal or zero, but not infinite or NaN. The macro returns an integral value.
判斷浮點數 arg 是否為有限值，也就是正規化數、非正規化數或零，而不是無窮大或 NaN。此巨集會回傳整數。
FLT_EVAL_METHOD is ignored: even if the argument is evaluated with more range and precision than its type, it is first converted to its semantic type, and the classification is based on that.
此處會忽略 FLT_EVAL_METHOD：即使參數以比其型別更大的範圍或精度求值，也會先轉換成其語意型別，再依該型別分類。

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

Nonzero integral value if `arg` has finite value, `0` otherwise.
若 arg 是有限值，回傳非零整數；否則回傳 0。

### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h>   int main(void) {  printf("isfinite(NAN) = %d\n", isfinite(NAN));  printf("isfinite(INFINITY) = %d\n", isfinite(INFINITY));  printf("isfinite(0.0) = %d\n", isfinite(0.0));  printf("isfinite(DBL_MIN/2.0) = %d\n", isfinite(DBL_MIN / 2.0));  printf("isfinite(1.0) = %d\n", isfinite(1.0));  printf("isfinite(exp(800)) = %d\n", isfinite(exp(800))); }
```

Possible output:
可能的輸出：

```c
isfinite(NAN) = 0 isfinite(INFINITY) = 0 isfinite(0.0) = 1 isfinite(DBL_MIN/2.0) = 1 isfinite(1.0) = 1 isfinite(exp(800)) = 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.3.2 The isfinite macro (p: TBD)
7.12.3.2 isfinite 宏（p: TBD）
7.12.3.2 isfinite 宏（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.3.2 The isfinite macro (p: TBD)
7.12.3.2 isfinite 宏（p: TBD）
7.12.3.2 isfinite 宏（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.3.2 The isfinite macro (p: 236)
7.12.3.2 isfinite 宏（p: 236）
7.12.3.2 isfinite 宏（p: 236）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.3.2 The isfinite macro (p: 216-217)
7.12.3.2 isfinite 宏（p: 216-217）
7.12.3.2 isfinite 宏（p: 216-217）

### See also

fpclassify
(C99)
|   | classifies the given floating-point value
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

C++ documentation for isfinite

---
來源頁路徑：`en.cppreference.com/c/numeric/math/isfinite.html`
