# abs, labs, llabs, imaxabs

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdlib.h>`
|   |  |   |  |

```c
int abs( int n );
```
|   |   |   |   |

```c
long labs( long n );
```
|   |   |   |   |

```c
long long llabs( long long n );
```
|   |   |   |  (since C99)  |

Defined in header `<inttypes.h>`
|   |  |   |  |

```c
intmax_t imaxabs( intmax_t n );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

Computes the absolute value of an integer number. The behavior is undefined if the result cannot be represented by the return type.
計算整數的絕對值。若結果無法以回傳型別表示，行為未定義。

### Parameters

| n  |   | -  |   | integer value  |

### Return value

The absolute value of `n` (i.e. `|n|`), if it is representable.
回傳 n 的絕對值 |n|（前提是結果可表示）。

### Notes

In 2's complement systems, the absolute value of the most-negative value is out of range, e.g. for 32-bit 2's complement type `int`, INT_MIN is `-2147483648`, but the would-be result `2147483648` is greater than INT_MAX, which is `2147483647`.
在二補數系統中，最小負值的絕對值會超出可表示範圍。例如，32 位元 int 的 INT_MIN 是 -2147483648，但其絕對值 2147483648 大於 INT_MAX（2147483647）。

### Example

Run this code

```c
#include <limits.h> #include <stdio.h> #include <stdlib.h> int main(void) {  printf("abs(+3) = %d\n", abs(+3));  printf("abs(-3) = %d\n", abs(-3)); // printf("%+d\n", abs(INT_MIN)); // undefined behavior on 2's complement systems }
```

Output:

```c
abs(+3) = 3 abs(-3) = 3
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.8.2.1 The imaxabs function (p: TBD)
7.8.2.1 imaxabs 函式 (p: TBD)
7.8.2.1 imaxabs 函式 (p: TBD)

- 7.22.6.1 The abs, labs and llabs functions (p: TBD)
7.22.6.1 abs、labs 和 llabs 函式 (p: TBD)
7.22.6.1 abs、labs 和 llabs 函式 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.8.2.1 The imaxabs function (p: 159)
7.8.2.1 imaxabs 函式 (p: 159)
7.8.2.1 imaxabs 函式 (p: 159)

- 7.22.6.1 The abs, labs and llabs functions (p: 259)
7.22.6.1 abs、labs 和 llabs 函式 (p: 259)
7.22.6.1 abs、labs 和 llabs 函式 (p: 259)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.8.2.1 The imaxabs function (p: 218)
7.8.2.1 imaxabs 函式 (p: 218)
7.8.2.1 imaxabs 函式 (p: 218)

- 7.22.6.1 The abs, labs and llabs functions (p: 356)
7.22.6.1 abs、labs 和 llabs 函式 (p: 356)
7.22.6.1 abs、labs 和 llabs 函式 (p: 356)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.8.2.1 The imaxabs function (p: 199-200)
7.8.2.1 imaxabs 函式 (p: 199-200)
7.8.2.1 imaxabs 函式 (p: 199-200)

- 7.20.6.1 The abs, labs and llabs functions (p: 320)
7.20.6.1 abs、labs 和 llabs 函式 (p: 320)
7.20.6.1 abs、labs 和 llabs 函式 (p: 320)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.10.6.1 The abs function
4.10.6.1 abs 函式
4.10.6.1 abs 函式

- 4.10.6.3 The labs function
4.10.6.3 labs 函式
4.10.6.3 labs 函式

### See also

fabsfabsffabsl
(C99)(C99)
|   | computes absolute value of a floating-point value (|x||x||x|)
(function)   |

cabscabsfcabsl
(C99)(C99)(C99)
|   | computes the magnitude of a complex number
(function)   |

C++ documentation for abs

---
來源頁路徑：`en.cppreference.com/c/numeric/math/abs.html`
