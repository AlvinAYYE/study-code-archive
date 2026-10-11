# isgreater

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define isgreater(x, y) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the floating-point number `x` is greater than the floating-point number (`y`), without setting floating-point exceptions.
在不設定浮點異常的情況下，確定浮點數 x 是否大於浮點數（ y ）。

### Parameters

| x  |   | -  |   | floating-point value  |

| y  |   | -  |   | floating-point value  |

### Return value

Nonzero integral value if `x > y`, `0` otherwise.
如果 x > y 則傳回非零整數值，否則傳回 0。

### Notes

The built-in `operator>` for floating-point numbers may set FE_INVALID if one or both of the arguments is NaN. This function is a "quiet" version of `operator>`.
浮點數的內建運運算元 > 在一個或兩個參數為 NaN 時可能會設定 FE_INVALID 。此函式是運運算元 > 的“靜默”版本。

### Example

Run this code

```c
#include <math.h> #include <stdio.h>   int main(void) {  printf("isgreater(2.0,1.0) = %d\n", isgreater(2.0, 1.0));  printf("isgreater(1.0,2.0) = %d\n", isgreater(1.0, 2.0));  printf("isgreater(INFINITY,1.0) = %d\n", isgreater(INFINITY, 1.0));  printf("isgreater(1.0,NAN) = %d\n", isgreater(1.0, NAN));    return 0; }
```

Possible output:
可能的輸出：

```c
isgreater(2.0,1.0) = 1 isgreater(1.0,2.0) = 0 isgreater(INFINITY,1.0) = 1 isgreater(1.0,NAN) = 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.14.1 The isgreater macro (p: TBD)
7.12.14.1 isgreater 宏（p: TBD）
7.12.14.1 isgreater 宏（p: TBD）

- F.10.11 Comparison macros (p: TBD)
F.10.11 比較宏（p: TBD）
F.10.11 比較宏（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.14.1 The isgreater macro (p: 189)
7.12.14.1 isgreater 宏（p: 189）
7.12.14.1 isgreater 宏（p: 189）

- F.10.11 Comparison macros (p: 386-387)
F.10.11 比較宏（p: 386-387）
F.10.11 比較宏（p: 386-387）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.14.1 The isgreater macro (p: 259)
7.12.14.1 isgreater 宏（p: 259）
7.12.14.1 isgreater 宏（p: 259）

- F.10.11 Comparison macros (p: 531)
F.10.11 比較宏（p: 531）
F.10.11 比較宏（p: 531）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.14.1 The isgreater macro (p: 240)
7.12.14.1 isgreater 宏（p: 240）
7.12.14.1 isgreater 宏（p: 240）

### See also

isless
(C99)
|   | checks if the first floating-point argument is less than the second
(function macro)   |

C++ documentation for isgreater

---
來源頁路徑：`en.cppreference.com/c/numeric/math/isgreater.html`
