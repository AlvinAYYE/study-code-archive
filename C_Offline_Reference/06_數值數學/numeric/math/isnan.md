# isnan

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define isnan(arg) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the given floating-point number `arg` is a not-a-number (NaN) value. The macro returns an integral value.
判斷浮點數 arg 是否為非數值（NaN）。此巨集會回傳整數。
FLT_EVAL_METHOD is ignored: even if the argument is evaluated with more range and precision than its type, it is first converted to its semantic type, and the classification is based on that (this matters if the evaluation type supports NaNs, while the semantic type does not).
此處會忽略 FLT_EVAL_METHOD：即使參數以比其型別更大的範圍或精度求值，也會先轉換成其語意型別，再依該型別分類。當求值型別支援 NaN、但語意型別不支援時，這點尤其重要。

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

Nonzero integral value if `arg` is a NaN, `0` otherwise.
若 arg 是 NaN，回傳非零整數；否則回傳 0。

### Notes

There are many different NaN values with different sign bits and payloads, see nan.
NaN 有許多不同的值，符號位和有效負載也可能不同；請參見 nan。
NaN values never compare equal to themselves or to other NaN values. Copying a NaN may change its bit pattern.
NaN 永遠不會等於自身或其他 NaN。複製 NaN 時，其位元表示也可能改變。
Another way to test if a floating-point value is NaN is to compare it with itself: `bool is_nan(double x) { return x != x; }`
也可以將浮點值與自身比較，判斷它是否為 NaN：bool is_nan ( double x ) { return x != x ; }

### Example

Run this code

```c
#include <float.h> #include <math.h> #include <stdio.h>   int main(void) {  printf("isnan(NAN) = %d\n", isnan(NAN));  printf("isnan(INFINITY) = %d\n", isnan(INFINITY));  printf("isnan(0.0) = %d\n", isnan(0.0));  printf("isnan(DBL_MIN/2.0) = %d\n", isnan(DBL_MIN / 2.0));  printf("isnan(0.0 / 0.0) = %d\n", isnan(0.0 / 0.0));  printf("isnan(Inf - Inf) = %d\n", isnan(INFINITY - INFINITY)); }
```

Possible output:
可能的輸出：

```c
isnan(NAN) = 1 isnan(INFINITY) = 0 isnan(0.0) = 0 isnan(DBL_MIN/2.0) = 0 isnan(0.0 / 0.0) = 1 isnan(Inf - Inf) = 1
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.3.4 The isnan macro (p: TBD)
7.12.3.4 isnan 宏 (p: TBD)
7.12.3.4 isnan 宏 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.3.4 The isnan macro (p: TBD)
7.12.3.4 isnan 宏 (p: TBD)
7.12.3.4 isnan 宏 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.3.4 The isnan macro (p: 236-237)
7.12.3.4 isnan 宏 (p: 236-237)
7.12.3.4 isnan 宏 (p: 236-237)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.3.4 The isnan macro (p: 217)
7.12.3.4 isnan 宏 (p: 217)
7.12.3.4 isnan 宏 (p: 217)

### See also

nannanfnanl
(C99)(C99)(C99)
|   | returns a NaN (not-a-number)
(function)   |

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

isnormal
(C99)
|   | checks if the given number is normal
(function macro)   |

isunordered
(C99)
|   | checks if two floating-point values are unordered
(function macro)   |

C++ documentation for isnan

---
來源頁路徑：`en.cppreference.com/c/numeric/math/isnan.html`
