# va_start

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stdarg.h>`
|   |  |   |  |

```c
void va_start( va_list ap, parmN );
```
|   |   |   | (until C23) |

```c
void va_start( va_list ap, ... );
```
|   |   |   | (since C23) |

|  |  |  |  |

The `va_start` macro enables access to the variable argumentsfollowing the named argument `parmN`(until C23).
（截至 C23）va_start 巨集可用來存取命名參數 parmN 之後的可變參數。
`va_start` shall be invoked with an instance to a valid va_list object `ap` before any calls to va_arg.
va_start 應在對 va_arg 的任何呼叫之前，使用有效的 va_list 物件 ap 的例項來呼叫。

If `parmN` is declared with `register` storage class specifier, with an array type, with a function type, or with a type not compatible with the type that results from default argument promotions, the behavior is undefined.
|   | (until C23) |

If more than one argument is present for `va_start`, the preprocessing tokens comprising the second and subsequent arguments are discarded. If any of those arguments expands to include unbalanced parentheses, or a preprocessing token that does not convert to a token, the behavior is undefined.
|   | (since C23) |

### Parameters

| ap  |   | -  |   | an instance of the va_list type  |

| parmN  |   | -  |   | the named parameter preceding the first variable parameter  |

### Expanded value

(none)

### Example

Run this code

```c
#include <stdarg.h> #include <stdio.h> int add_nums_C99(int count, ...) {  int result = 0;  va_list args;  va_start(args, count); // count can be omitted since C23    for (int i = 0; i < count; ++i)  result += va_arg(args, int);    va_end(args);  return result; } #if __STDC_VERSION__ > 201710L // Same as above, valid since C23 int add_nums_C23(...) {  int result = 0;  va_list args;  va_start(args);    int count = va_arg(args, int);  for (int i = 0; i < count; ++i)  result += va_arg(args, int);    va_end(args);  return result; } #endif int main(void) {  printf("%d\n", add_nums_C99(4, 25, 25, 50, 50)); #if __STDC_VERSION__ > 201710L  printf("%d\n", add_nums_C23(4, 25, 25, 50, 50)); #endif }
```

Possible output:
可能的輸出：

```c
150 150
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.16.1.4 The va_start macro (p: 290-292)
7.16.1.4 va_start 宏（頁碼：290-292）
7.16.1.4 va_start 宏（頁碼：290-292）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.16.1.4 The va_start macro (p: 198-199)
7.16.1.4 va_start 宏（頁碼：198-199）
7.16.1.4 va_start 宏（頁碼：198-199）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.16.1.4 The va_start macro (p: 271-272)
7.16.1.4 va_start 宏（頁碼：271-272）
7.16.1.4 va_start 宏（頁碼：271-272）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.15.1.4 The va_start macro (p: 251-252)
7.15.1.4 va_start 宏（頁碼：251-252）
7.15.1.4 va_start 宏（頁碼：251-252）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.8.1.1 The va_start macro
4.8.1.1 va_start 宏
4.8.1.1 va_start 宏

### See also

va_arg
|   | accesses the next variadic function argument
(function macro)   |

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

C++ documentation for va_start

---
來源頁路徑：`en.cppreference.com/c/variadic/va_start.html`
