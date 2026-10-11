# islessgreater

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define islessgreater(x, y) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the floating-point number `x` is less than or greater than the floating-point number `y`, without setting floating-point exceptions.
確定浮點數 x 是否小於或大於浮點數 y，且不設定浮點異常。

### Parameters

| x  |   | -  |   | floating-point value  |

| y  |   | -  |   | floating-point value  |

### Return value

Nonzero integral value if `x < y || x > y`, `0` otherwise.
若 x < y || x > y 則傳回非零整數值，否則傳回 0。

### Notes

The built-in `operator<` and `operator>` for floating-point numbers may raise FE_INVALID if one or both of the arguments is NaN. This function is a "quiet" version of the expression `x < y || x > y`. The macro does not evaluate x and y twice.
對於浮點數，內建的 operator < 和 operator > 在一個或兩個參數為 NaN 時可能引發 FE_INVALID。本函式是表示式 x < y || x > y 的“安靜”版本。該宏不會對 x 和 y 求值兩次。

### Example

Run this code

```c
#include <math.h> #include <stdio.h>   int main(void) {  printf("islessgreater(2.0,1.0) = %d\n", islessgreater(2.0, 1.0));  printf("islessgreater(1.0,2.0) = %d\n", islessgreater(1.0, 2.0));  printf("islessgreater(1.0,1.0) = %d\n", islessgreater(1.0, 1.0));  printf("islessgreater(INFINITY,1.0) = %d\n", islessgreater(INFINITY, 1.0));  printf("islessgreater(1.0,NAN) = %d\n", islessgreater(1.0, NAN));    return 0; }
```

Possible output:
可能的輸出：

```c
islessgreater(2.0,1.0) = 1 islessgreater(1.0,2.0) = 1 islessgreater(1.0,1.0) = 0 islessgreater(INFINITY,1.0) = 1 islessgreater(1.0,NAN) = 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.14.5 The islessgreater macro (p: TBD)
7.12.14.5 islessgreater 宏（p: TBD）
7.12.14.5 islessgreater 宏（p: TBD）

- F.10.11 Comparison macros (p: TBD)
F.10.11 比較宏（p: TBD）
F.10.11 比較宏（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.14.5 The islessgreater macro (p: TBD)
7.12.14.5 islessgreater 宏（p: TBD）
7.12.14.5 islessgreater 宏（p: TBD）

- F.10.11 Comparison macros (p: TBD)
F.10.11 比較宏（p: TBD）
F.10.11 比較宏（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.14.5 The islessgreater macro (p: 261)
7.12.14.5 islessgreater 宏（p: 261）
7.12.14.5 islessgreater 宏（p: 261）

- F.10.11 Comparison macros (p: 531)
F.10.11 比較宏（p: 531）
F.10.11 比較宏（p: 531）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.14.5 The islessgreater macro (p: 241-242)
7.12.14.5 islessgreater 宏（p: 241-242）
7.12.14.5 islessgreater 宏（p: 241-242）

### See also

isless
(C99)
|   | checks if the first floating-point argument is less than the second
(function macro)   |

isgreater
(C99)
|   | checks if the first floating-point argument is greater than the second
(function macro)   |

C++ documentation for islessgreater

---
來源頁路徑：`en.cppreference.com/c/numeric/math/islessgreater.html`
