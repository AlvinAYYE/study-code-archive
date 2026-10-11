# signbit

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define signbit( arg ) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the given floating-point number `arg` is negative. The macro returns an integral value.
判定給定的浮點數 arg 是否為負。該宏傳回一個整數值。

### Parameters

| arg  |   | -  |   | floating-point value  |

### Return value

Nonzero integral value if `arg` is negative, `0` otherwise.
如果 arg 為負，則傳回非零整數值，否則傳回 0。

### Notes

This macro detects the sign bit of zeroes, infinities, and NaNs. Along with copysign, this macro is one of the only two portable ways to examine the sign of a NaN.
該宏檢測零、無窮大和 NaN 的符號位。與 copysign 一起，該宏是僅有的兩種可移植地檢查 NaN 符號的方式之一。

### Example

Run this code

```c
#include <math.h> #include <stdio.h>   int main(void) {  printf("signbit(+0.0) = %d\n", signbit(+0.0));  printf("signbit(-0.0) = %d\n", signbit(-0.0)); }
```

Possible output:
可能的輸出：

```c
signbit(+0.0) = 0 signbit(-0.0) = 128
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.3.6 The signbit macro (p: TBD)
7.12.3.6 signbit 宏 (p: TBD)
7.12.3.6 signbit 宏 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.3.6 The signbit macro (p: TBD)
7.12.3.6 signbit 宏 (p: TBD)
7.12.3.6 signbit 宏 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.3.6 The signbit macro (p: 237)
7.12.3.6 signbit 宏 (p: 237)
7.12.3.6 signbit 宏 (p: 237)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.3.6 The signbit macro (p: 218)
7.12.3.6 signbit 宏 (p: 218)
7.12.3.6 signbit 宏 (p: 218)

### See also

fabsfabsffabsl
(C99)(C99)
|   | computes absolute value of a floating-point value (|x||x||x|)
(function)   |

copysigncopysignfcopysignl
(C99)(C99)(C99)
|   | produces a value with the magnitude of a given value and the sign of another given value
(function)   |

C++ documentation for signbit

---
來源頁路徑：`en.cppreference.com/c/numeric/math/signbit.html`
