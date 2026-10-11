# va_copy

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdarg.h>`
|   |  |   |  |

```c
void va_copy( va_list dest, va_list src );
```
|   |   |   |  (since C99)  |

|  |  |  |  |

The `va_copy` macro copies `src` to `dest`.
va_copy 宏將 src 複製到 dest 。
va_end should be called on `dest` before the function returns or any subsequent re-initialization of `dest` (via calls to va_start or va_copy).
應在函式傳回或對 dest 的任何後續重新初始化（透過呼叫 va_start 或 va_copy ）之前對 dest 呼叫 va_end 。

### Parameters

| dest  |   | -  |   | an instance of the va_list type to initialize  |

| src  |   | -  |   | the source va_list that will be used to initialize `dest`  |

### Expanded value

(none)

### Example

Run this code

```c
#include <math.h> #include <stdarg.h> #include <stdio.h> double sample_stddev(int count, ...) {  /* Compute the mean with args1. */  double sum = 0;  va_list args1;  va_start(args1, count);  va_list args2;  va_copy(args2, args1); /* copy va_list object */  for (int i = 0; i < count; ++i)  {  double num = va_arg(args1, double);  sum += num;  }  va_end(args1);  double mean = sum / count;  /* Compute standard deviation with args2 and mean. */  double sum_sq_diff = 0;  for (int i = 0; i < count; ++i)  {  double num = va_arg(args2, double);  sum_sq_diff += (num - mean) * (num - mean);  }  va_end(args2);  return sqrt(sum_sq_diff / count); } int main(void) {  printf("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7)); }
```

Possible output:
可能的輸出：

```c
0.920258
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.16.1.2 The va_copy macro (p: TBD)
7.16.1.2 va_copy 宏（頁碼：待定）
7.16.1.2 va_copy 宏（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.16.1.2 The va_copy macro (p: TBD)
7.16.1.2 va_copy 宏（頁碼：待定）
7.16.1.2 va_copy 宏（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.16.1.2 The va_copy macro (p: 270)
7.16.1.2 va_copy 宏（頁碼：270）
7.16.1.2 va_copy 宏（頁碼：270）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.15.1.2 The va_copy macro (p: 250)
7.15.1.2 va_copy 宏（頁碼：250）
7.15.1.2 va_copy 宏（頁碼：250）

### See also

va_arg
|   | accesses the next variadic function argument
(function macro)   |

va_end
|   | ends traversal of the variadic function arguments
(function macro)   |

va_list
|   | holds the information needed by va_start, va_arg, va_end, and va_copy
(typedef)   |

va_start
|   | enables access to variadic function arguments
(function macro)   |

C++ documentation for va_copy

---
來源頁路徑：`en.cppreference.com/c/variadic/va_copy.html`
