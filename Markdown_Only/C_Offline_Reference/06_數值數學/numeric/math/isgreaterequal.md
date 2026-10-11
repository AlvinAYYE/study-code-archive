# isgreaterequal

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define isgreaterequal(x, y) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the floating-point number `x` is greater than or equal to the floating-point number `y`, without setting floating-point exceptions.
在不設定浮點異常的情況下，確定浮點數 x 是否大於或等於浮點數 y。

### Parameters

| x  |   | -  |   | floating-point value  |

| y  |   | -  |   | floating-point value  |

### Return value

Nonzero integral value if `x >= y`, `0` otherwise.
若 x >= y 則傳回非零整數值，否則傳回 0。

### Notes

The built-in `operator>=` for floating-point numbers may raise FE_INVALID if one or both of the arguments is NaN. This function is a "quiet" version of `operator>=`.
浮點數的內建運運算元 >= 在其中一個或兩個參數為 NaN 時可能引發 FE_INVALID。本函式是運運算元 >= 的“靜默”版本。

### Example

Run this code

```c
#include <math.h> #include <stdio.h>   int main(void) {  printf("isgreaterequal(2.0,1.0) = %d\n", isgreaterequal(2.0, 1.0));  printf("isgreaterequal(1.0,2.0) = %d\n", isgreaterequal(1.0, 2.0));  printf("isgreaterequal(1.0,1.0) = %d\n", isgreaterequal(1.0, 1.0));  printf("isgreaterequal(INFINITY,1.0) = %d\n", isgreaterequal(INFINITY, 1.0));  printf("isgreaterequal(1.0,NAN) = %d\n", isgreaterequal(1.0, NAN));    return 0; }
```

Possible output:
可能的輸出：

```c
isgreaterequal(2.0,1.0) = 1 isgreaterequal(1.0,2.0) = 0 isgreaterequal(1.0,1.0) = 1 isgreaterequal(INFINITY,1.0) = 1 isgreaterequal(1.0,NAN) = 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.14.2 The isgreaterequal macro (p: TBD)
7.12.14.2 isgreaterequal 宏 (p: TBD)
7.12.14.2 isgreaterequal 宏 (p: TBD)

- F.10.11 Comparison macros (p: TBD)
F.10.11 比較宏（p: TBD）
F.10.11 比較宏（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.14.2 The isgreaterequal macro (p: TBD)
7.12.14.2 isgreaterequal 宏 (p: TBD)
7.12.14.2 isgreaterequal 宏 (p: TBD)

- F.10.11 Comparison macros (p: TBD)
F.10.11 比較宏（p: TBD）
F.10.11 比較宏（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.14.2 The isgreaterequal macro (p: 259-260)
7.12.14.2 isgreaterequal 宏 (p: 259-260)
7.12.14.2 isgreaterequal 宏 (p: 259-260)

- F.10.11 Comparison macros (p: 531)
F.10.11 比較宏（p: 531）
F.10.11 比較宏（p: 531）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.14.2 The isgreaterequal macro (p: 240-241)
7.12.14.2 isgreaterequal 宏 (p: 240-241)
7.12.14.2 isgreaterequal 宏 (p: 240-241)

### See also

islessequal
(C99)
|   | checks if the first floating-point argument is less or equal than the second
(function macro)   |

C++ documentation for isgreaterequal

---
來源頁路徑：`en.cppreference.com/c/numeric/math/isgreaterequal.html`
