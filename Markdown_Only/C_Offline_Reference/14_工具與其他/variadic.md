# Variadic functions

> 來源：cppreference C 語言參考文件（離線轉換版）。

Variadic functions are functions (e.g. printf) which take a variable number of arguments.
可變參數函式是接受可變數量參數的函式（例如 printf ）。
The declaration of a variadic function uses an ellipsis as the last parameter, e.g. `int printf(const char* format, ...);`. See variadic arguments for additional detail on the syntax and automatic argument conversions.
可變參數函式的宣告以省略號作為最後一個參數，例如 int printf ( const char * format , ...); 。有關語法和自動參數轉換的更多細節，請參見可變參數。
Accessing the variadic arguments from the function body uses the following library facilities:
從函式體中訪問可變參數需要使用以下庫設施：

#####  Types

va_list
|   | holds the information needed by va_start, va_arg, va_end, and va_copy
(typedef)   |

#####  Macros

Defined in header `<stdarg.h>`

va_start
|   | enables access to variadic function arguments
(function macro)   |

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

### Example

Print values of different types.
列印不同型別的值。
Run this code

```c
#include <stdarg.h> #include <stdio.h> void simple_printf(const char* fmt, ...) {  va_list args;  for (va_start(args, fmt); *fmt != '\0'; ++fmt)  {  switch(*fmt)  {  case 'd':  {  int i = va_arg(args, int);  printf("%d\n", i);  break;  }  case 'c':  {  // A 'char' variable will be promoted to 'int'  // A character literal in C is already 'int' by itself  int c = va_arg(args, int);  printf("%c\n", c);  break;  }  case 'f':  {  double d = va_arg(args, double);  printf("%f\n", d);  break;  }  default:  puts("Unknown formatter!");  goto END;  }  } END:  va_end(args); } int main(void) {  simple_printf("dcff", 3, 'a', 1.969, 42.5); }
```

Output:

```c
3 a 1.969000 42.50000
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.16 Variable arguments <stdarg.h> (p: TBD)
7.16 變長參數 <stdarg.h> (p: TBD)
7.16 變長參數 <stdarg.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.16 Variable arguments <stdarg.h> (p: TBD)
7.16 變長參數 <stdarg.h> (p: TBD)
7.16 變長參數 <stdarg.h> (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.16 Variable arguments <stdarg.h> (p: 269-272)
7.16 可變參數 <stdarg.h> (p: 269-272)
7.16 可變參數 <stdarg.h> (p: 269-272)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.15 Variable arguments <stdarg.h> (p: 249-252)
7.15 可變參數 <stdarg.h> (p: 249-252)
7.15 可變參數 <stdarg.h> (p: 249-252)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.8 VARIABLE ARGUMENTS <stdarg.h>
4.8 可變參數 <stdarg.h>
4.8 可變參數 <stdarg.h>

### See also

C++ documentation for Variadic functions

---
來源頁路徑：`en.cppreference.com/c/variadic.html`
