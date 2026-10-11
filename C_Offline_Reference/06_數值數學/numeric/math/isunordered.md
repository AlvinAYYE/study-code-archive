# isunordered

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<math.h>`
|   |  |   |  |

```c
#define isunordered(x, y) /* implementation defined */
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Determines if the floating point numbers `x` and `y` are unordered, that is, one or both are NaN and thus cannot be meaningfully compared with each other.
判定浮點數 x 和 y 是否不可排序，即其中一個或兩個為 NaN，因而無法彼此進行有意義的比較。

### Parameters

| x  |   | -  |   | floating point value  |

| y  |   | -  |   | floating point value  |

### Return value

Nonzero integral value if either `x` or `y` is NaN, `0` otherwise.
如果 x 或 y 中任意一個為 NaN，則傳回非零整數值，否則傳回 0。

### Example

Run this code

```c
#include <math.h> #include <stdio.h>   int main(void) {  printf("isunordered(NAN,1.0) = %d\n", isunordered(NAN, 1.0));  printf("isunordered(1.0,NAN) = %d\n", isunordered(1.0, NAN));  printf("isunordered(NAN,NAN) = %d\n", isunordered(NAN, NAN));  printf("isunordered(1.0,0.0) = %d\n", isunordered(1.0, 0.0));    return 0; }
```

Possible output:
可能的輸出：

```c
isunordered(NAN,1.0) = 1 isunordered(1.0,NAN) = 1 isunordered(NAN,NAN) = 1 isunordered(1.0,0.0) = 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.12.14.6 The isunordered macro (p: TBD)
7.12.14.6 isunordered 宏（p: TBD）
7.12.14.6 isunordered 宏（p: TBD）

- F.10.11 Comparison macros (p: TBD)
F.10.11 比較宏（p: TBD）
F.10.11 比較宏（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.12.14.6 The isunordered macro (p: TBD)
7.12.14.6 isunordered 宏（p: TBD）
7.12.14.6 isunordered 宏（p: TBD）

- F.10.11 Comparison macros (p: TBD)
F.10.11 比較宏（p: TBD）
F.10.11 比較宏（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.12.14.6 The isunordered macro (p: 261)
7.12.14.6 isunordered 宏（p: 261）
7.12.14.6 isunordered 宏（p: 261）

- F.10.11 Comparison macros (p: 531)
F.10.11 比較宏（p: 531）
F.10.11 比較宏（p: 531）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.12.14.6 The isunordered macro (p: 242)
7.12.14.6 isunordered 宏（p: 242）
7.12.14.6 isunordered 宏（p: 242）

### See also

fpclassify
(C99)
|   | classifies the given floating-point value
(function macro)   |

isnan
(C99)
|   | checks if the given number is NaN
(function macro)   |

C++ documentation for isunordered

---
來源頁路徑：`en.cppreference.com/c/numeric/math/isunordered.html`
