# Variadic arguments

> 來源：cppreference C 語言參考文件（離線轉換版）。

Variadic functions are functions that may be called with different number of arguments.
可變參數函式是可以用不同數量參數呼叫的函式。
Only prototyped function declarations may be variadic. This is indicated by the parameter of the form `...` which must appear last in the parameter list and must follow at least one named parameter(until C23). The ellipsis parameter and the proceeding parameter must be delimited by `,`.
只有帶原型的函式宣告才能是可變參數的。這由形式為 ... 的參數列示，該參數必須出現在參數列表的最後，並且必須跟在至少一個命名參數之後（直到 C23）。省略號參數與其前面的參數必須以 , 分隔。

```c
// Prototyped declaration int printx(const char* fmt, ...); // function declared this way printx("hello world"); // may be called with one printx("a=%d b=%d", a, b); // or more arguments int printz(...); // OK since C23 and in C++ // Error until C23: ... must follow at least one named parameter // int printy(..., const char* fmt); // Error: ... must be the last // int printa(const char* fmt...); // Error in C: ',' is required; OK in C++
```

At the function call, each argument that is a part of the variable argument list undergoes special implicit conversions known as default argument promotions.
在函式呼叫中，屬於可變參數列表的每個參數都要經過稱為預設參數提升的特殊隱式轉換。
Within the body of a function that uses variadic arguments, the values of these arguments may be accessed using the `<stdarg.h>` library facilities:
在使用可變參數的函式體內，可以使用 <stdarg.h> 庫設施訪問這些參數的值：

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

va_list
|   | holds the information needed by va_start, va_arg, va_end, and va_copy
(typedef)   |

### Notes

Although old-style (prototype-less) function declarations allow the subsequent function calls to use any number of arguments, they are not allowed to be variadic (as of C89). The definition of such function must specify a fixed number of parameters and cannot use the `stdarg.h` macros.
雖然舊式（無原型）函式宣告允許隨後的函式呼叫使用任意數量的參數，但它們不允許是可變參數的（截至 C89）。這種函式的定義必須指定固定數量的參數，並且不能使用 stdarg.h 宏。

```c
// old-style declaration, removed in C23 int printx(); // function declared this way printx("hello world"); // may be called with one printx("a=%d b=%d", a, b); // or more arguments // the behavior of at least one of these calls is undefined, depending on // the number of parameters the function is defined to take
```

### Example

Run this code

```c
#include <stdio.h> #include <time.h> #include <stdarg.h> void tlog(const char* fmt,...) {  char msg[50];  strftime(msg, sizeof msg, "%T", localtime(&(time_t){time(NULL)}));  printf("[%s] ", msg);  va_list args;  va_start(args, fmt);  vprintf(fmt, args);  va_end(args); } int main(void) {  tlog("logging %d %d %d...\n", 1, 2, 3); }
```

Output:

```c
[10:21:38] logging 1 2 3...
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.6.3/9 Function declarators (including prototypes) (p: 96)
6.7.6.3/9 函式宣告符（包括原型） (p: 96)
6.7.6.3/9 函式宣告符（包括原型） (p: 96)

- 7.16 Variable arguments <stdarg.h> (p: 197-199)
7.16 可變參數 <stdarg.h> (p: 197-199)
7.16 可變參數 <stdarg.h> (p: 197-199)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.6.3/9 Function declarators (including prototypes) (p: 133)
6.7.6.3/9 函式宣告符（包括原型） (p: 133)
6.7.6.3/9 函式宣告符（包括原型） (p: 133)

- 7.16 Variable arguments <stdarg.h> (p: 269-272)
7.16 可變參數 <stdarg.h> (p: 269-272)
7.16 可變參數 <stdarg.h> (p: 269-272)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.5.3/9 Function declarators (including prototypes) (p: 119)
6.7.5.3/9 函式宣告符（包括原型） (p: 119)
6.7.5.3/9 函式宣告符（包括原型） (p: 119)

- 7.15 Variable arguments <stdarg.h> (p: 249-252)
7.15 可變參數 <stdarg.h> (p: 249-252)
7.15 可變參數 <stdarg.h> (p: 249-252)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.4.3/5 Function declarators (including prototypes)
3.5.4.3/5 函式宣告符（包括原型）
3.5.4.3/5 函式宣告符（包括原型）

- 4.8 VARIABLE ARGUMENTS <stdarg.h>
4.8 可變參數 <stdarg.h>
4.8 可變參數 <stdarg.h>

### See also

C++ documentation for Variadic arguments

---
來源頁路徑：`en.cppreference.com/c/language/variadic.html`
