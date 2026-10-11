# Scalar initialization

> 來源：cppreference C 語言參考文件（離線轉換版）。

When initializing an object of scalar type, the initializer must be a single expression
初始化標量型別物件時，初始化器必須是單個表示式
The initializer for a scalar (an object of integer type including booleans and enumerated types, floating type including complex and imaginary, and pointer type including pointer to function) must be a single expression, optionally enclosed in braces, or an empty initializer(since C23):
標量（整數型別物件，包括布林和列舉型別；浮點型別，包括複數和虛數；以及指標型別，包括指向函式的指標）的初始化器必須是單個表示式，可選地用花括號括起，或者是空初始化器（自 C23 起）：

|   |

| `**=**` expression  |   | (1)  |   |   |

|   |

| `**=**` `**{**` expression `**}**`  |   | (2)  |   |   |

|   |

| `**=**` `**{**` `**}**`  |   | (3)  |   | (since C23)  |

|   |

1,2) The expression is evaluated, and its value, after conversion as if by assignment to the type of the object, becomes the initial value of the object being initialized.

3) The object is empty-initialized, i.e. initialized to numeric zero for an object of an arithmetic or enumeration type, or null pointer value for an object of a pointer type.

### Notes

Because of the rules that apply to conversions as if by assignment, const and volatile qualifiers on the declared type are ignored when determining which type to convert the expression to.
由於適用於如同賦值的轉換的規則，在確定將表示式轉換為哪種型別時，會忽略宣告型別上的 const 和 volatile 限定符。
See initialization for the rules that apply when no initializer is used.
當未使用初始化器時，適用規則見 initialization。
As with all other initializations, expression must be a constant expression when initializing objects of static or thread-local storage duration.
與所有其他初始化一樣，初始化靜態或執行緒區域性儲存期物件時，expression 必須是常量表示式。
The expression cannot be a comma operator (unless parenthesized) because the comma at the top level would be interpreted as the beginning of the next declarator.
expression 不能是逗號運運算元（除非加括號），因為頂層的逗號會被解釋為下一個宣告符的開始。
When initializing objects of floating-point type, all computations for the objects with automatic storage duration are done as-if at execution time and are affected by the current rounding; floating-point errors are reported as specified in math_errhandling. For objects of static and thread-local storage duration, computations are done as-if at compile time, and no exceptions are raised:
初始化浮點型別物件時，具有自動儲存期的物件的所有計算在執行時進行，並受目前舍入影響；浮點錯誤按 math_errhandling 中的規定報告。對於具有靜態和執行緒區域性儲存期的物件，計算在編譯時進行，並且不引發異常：

```c
void f(void) { #pragma STDC FENV_ACCESS ON  static float v = 1.1e75; // does not raise exceptions: static init  float u[] = { 1.1e75 }; // raises FE_INEXACT  float w = 1.1e75; // raises FE_INEXACT  double x = 1.1e75; // may raise FE_INEXACT (depends on FLT_EVAL_METHOD)  float y = 1.1e75f; // may raise FE_INEXACT (depends on FLT_EVAL_METHOD)  long double z = 1.1e75; // does not raise exceptions (conversion is exact) }
```

### Example

Run this code

```c
#include <stdbool.h> int main(void) {  bool b = true;  const double d = 3.14;  int k = 3.15; // conversion from double to int  int n = {12}, // optional braces  *p = &n, // non-constant expression OK for automatic variable  (*fp)(void) = main;  enum {RED, BLUE} e = RED; // enumerations are scalar types as well }
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.9/11 Initialization (p: 101)
6.7.9/11 初始化（第 101 頁）
6.7.9/11 初始化（第 101 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.9/11 Initialization (p: 140)
6.7.9/11 初始化（第 140 頁）
6.7.9/11 初始化（第 140 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.8/11 Initialization (p: 126)
6.7.8/11 初始化（第 126 頁）
6.7.8/11 初始化（第 126 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 6.5.7 Initialization
6.5.7 初始化
6.5.7 初始化

---
來源頁路徑：`en.cppreference.com/c/language/scalar_initialization.html`
