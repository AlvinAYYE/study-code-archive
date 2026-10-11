# va_arg

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdarg.h>`
|   |  |   |  |

```c
T va_arg( va_list ap, T );
```
|   |   |   |   |

|  |  |  |  |

The `va_arg` macro expands to an expression of type `T` that corresponds to the next parameter from the va_list `ap`.
va_arg 巨集會展開成型別為 T 的運算式，代表 va_list ap 中的下一個參數。
Prior to calling `va_arg`, `ap` must be initialized by a call to either va_start or va_copy, with no intervening call to va_end. Each invocation of the `va_arg` macro modifies `ap` to point to the next variable argument.
呼叫 va_arg 前，必須先透過 va_start 或 va_copy 初始化 ap，期間不得呼叫 va_end。每次呼叫 va_arg 都會修改 ap，讓它指向下一個可變參數。
If the type of the next argument in `ap` (after promotions) is not compatible with `T`, the behavior is undefined, unless:
如果 ap 中下一個參數的型別（在提升之後）與 T 不相容，則行為未定義，除非：

- one type is a signed integer type, the other type is the corresponding unsigned integer type, and the value is representable in both types; or
一種型別是有符號整數型別，另一種型別是對應的無符號整數型別，且該值在兩種型別中都可表示；或

- one type is pointer to `void` and the other is a pointer to a character type.
一種型別是指向 void 的指標，另一種型別是指向字元型別的指標。

If `va_arg` is called when there are no more arguments in `ap`, the behavior is undefined.
當 ap 中不再有參數時呼叫 va_arg ，行為未定義。

### Parameters

| ap  |   | -  |   | an instance of the va_list type  |

| T  |   | -  |   | the type of the next parameter in `ap`  |

### Expanded value

the next variable parameter in `ap`
ap 中的下一個可變參數

### Example

Run this code

```c
#include <math.h> #include <stdarg.h> #include <stdio.h> double stddev(int count, ...) {  double sum = 0;  double sum_sq = 0;  va_list args;  va_start(args, count);  for (int i = 0; i < count; ++i)  {  double num = va_arg(args, double);  sum += num;  sum_sq += num*num;  }  va_end(args);  return sqrt(sum_sq / count - (sum / count) * (sum / count)); } int main(void) {  printf("%f\n", stddev(4, 25.0, 27.3, 26.9, 25.7)); }
```

Output:

```c
0.920258
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.16.2.2 The va_arg macro (p: TBD)
7.16.2.2 va_arg 宏（頁碼：待定）
7.16.2.2 va_arg 宏（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.16.1.1 The va_arg macro (p: TBD)
7.16.1.1 va_arg 宏（頁碼：待定）
7.16.1.1 va_arg 宏（頁碼：待定）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.16.1.1 The va_arg macro (p: 269-270)
7.16.1.1 va_arg 宏（頁碼：269-270）
7.16.1.1 va_arg 宏（頁碼：269-270）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.15.1.1 The va_arg macro (p: 249-250)
7.15.1.1 va_arg 宏（頁碼：249-250）
7.15.1.1 va_arg 宏（頁碼：249-250）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.8.1.2 The va_arg macro
4.8.1.2 va_arg 宏
4.8.1.2 va_arg 宏

### See also

va_copy
(C99)
|   | makes a copy of the variadic function arguments
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

C++ documentation for va_arg

---
來源頁路徑：`en.cppreference.com/c/variadic/va_arg.html`
