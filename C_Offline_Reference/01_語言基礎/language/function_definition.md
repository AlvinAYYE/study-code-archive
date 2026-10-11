# Function definitions

> 來源：cppreference C 語言參考文件（離線轉換版）。

A function definition associates the function body (a sequence of declarations and statements) with the function name and parameter list. Unlike function declaration, function definitions are allowed at file scope only (there are no nested functions).
函式定義將函式體（宣告和陳述式的序列）與函式名和參數列表關聯起來。與函式宣告 不同，函式定義只允許在檔案作用域中（沒有巢狀函式）。
C supports two different forms of function definitions:
C 支援兩種不同形式的函式定義：

|   |

| attr-spec-seq(optional) specifiers-and-qualifiers parameter-list-declarator function-body  |   | (1)  |   |   |

|   |

| specifiers-and-qualifiers identifier-list-declarator declaration-list function-body  |   | (2)  |   | (until C23)  |

|   |

where

| attr-spec-seq  |   | -  |   | (C23)an optional list of attributes, applied to the function  |

| specifiers-and-qualifiers  |   | -  |   | a combination of
- type specifiers that, possibly modified by the declarator, form the *return type*

- storage class specifiers, which determine the linkage of the identifier (`static`, `extern`, or none)

- function specifiers inline, _Noreturn, or none

| parameter-list-declarator  |   | -  |   | a declarator for a function type which uses a parameter list to designate function parameters  |

| identifier-list-declarator  |   | -  |   | a declarator for a function type which uses a identifier list to designate function parameters  |

| declaration-list  |   | -  |   | sequence of declarations that declare every identifier in identifier-list-declarator. These declarations cannot use initializers and the only storage-class specifier allowed is `register`.  |

| function-body  |   | -  |   | a compound statement, that is a brace-enclosed sequence of declarations and statements, that is executed whenever this function is called  |

1) New-style (C89) function definition. This definition both introduces the function itself and serves as a function prototype for any future function call expressions, forcing conversions from argument expressions to the declared parameter types.
```c
int max(int a, int b) {  return a>b?a:b; } double g(void) {  return 0.1; }
```

2) (until C23) Old-style (K&R) function definition. This definition does not behave as a prototype and any future function call expressions will perform default argument promotions.
```c
int max(a, b) int a, b; {  return a>b?a:b; } double g() {  return 0.1; }
```

### Explanation

As with function declarations, the return type of the function, determined by the type specifier in specifiers-and-qualifiers and possibly modified by the declarator as usual in declarations, must be a complete non-array object type or the type `void`. If the return type would be cvr-qualified, it is adjusted to its unqualified version for the purpose of constructing the function type.
和函式宣告一樣，函式定義的傳回型別由 specifiers-and-qualifiers 中的型別說明符決定，也可能依一般宣告規則由宣告子調整。傳回型別必須是完整的非陣列物件型別或 void。若帶有 cvr 限定符，建構函式型別時會調整為未限定版本。

```c
void f(char *s) { puts(s); } // return type is void int sum(int a, int b) { return a+b; } // return type is int int (*foo(const void *p))[3] { // return type is pointer to array of 3 int  return malloc(sizeof(int[3])); }
```

As with function declarations, the types of the parameters are adjusted from functions to pointers and from arrays to pointers for the purpose of constructing the function type and the top-level cvr-qualifiers of all parameter types are ignored for the purpose of determining compatible function type.
和函式宣告一樣，建構函式型別時，函式型別參數會調整為函式指標，陣列參數會調整為指標。判斷函式型別是否相容時，會忽略所有參數型別最外層的 cvr 限定符。

Unlike function declarations, unnamed formal parameters are not allowed (otherwise, there would be conflicts in old-style (K&R) function definitions), they must be named even if they are not used within the function. The only exception is the special parameter list `(void)`.
|   | (until C23) |

Formal parameters may be unnamed in function definitions, because old-style (K&R) function definitions has been removed. Unnamed parameters are inaccessible by name within the function body.
|   | (since C23) |

```c
int f(int, int); // declaration // int f(int, int) { return 7; } // Error until C23, OK since C23 int f(int a, int b) { return 7; } // definition int g(void) { return 8; } // OK: void doesn't declare a parameter
```

Within the function body, every named parameter is an lvalue expression, they have automatic storage duration and block scope. The layout of the parameters in memory (or if they are stored in memory at all) is unspecified: it is a part of the calling convention.
在函式本體中，每個具名參數都是左值運算式，具有自動儲存期與區塊作用域。參數在記憶體中的配置方式（或是否存放於記憶體）未有規定，屬於呼叫慣例的一部分。

```c
int main(int ac, char **av) {  ac = 2; // parameters are lvalues  av = (char *[]){"abc", "def", NULL};  f(ac, av); }
```

See function call operator for other details on the mechanics of a function call and return for returning from functions.
關於函式呼叫機制的其他細節見函式呼叫運運算元，關於從函式傳回的 return 見 return。

### __func__

Within every function-body, the special predefined variable `__func__` with block scope and static storage duration is available, as if defined immediately after the opening brace by

```c
static const char __func__[] = "function name";
```

This special identifier is sometimes used in combination with the predefined macro constants `__FILE__` and `__LINE__`, for example, by assert.
|   | (since C99) |

### Notes

The argument list must be explicitly present in the declarator, it cannot be inherited from a typedef
參數列表必須顯式出現在宣告符中，它不能從 typedef 繼承

```c
typedef int p(int q, int r); // p is a function type int(int, int) p f { return q + r; } // Error
```

In C89, specifiers-and-qualifiers was optional, and if omitted, the return type of the function defaulted to `int` (possibly amended by the declarator).
In addition, old-style definition didn't require a declaration for every parameter in declaration-list. Any parameter whose declaration was missing had type `int`

```c
max(a, b) // a and b have type int, return type is int {  return a>b?a:b; }
```
|   | (until C99) |

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 423  |   | C89  |   | the return type might be qualified  |   | the return type is implicitly disqualified  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.9.1 Function definitions (p: 113-115)
6.9.1 函式定義（p: 113-115）
6.9.1 函式定義（p: 113-115）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.9.1 Function definitions (p: 156-158)
6.9.1 函式定義（p: 156-158）
6.9.1 函式定義（p: 156-158）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.9.1 Function definitions (p: 141-143)
6.9.1 函式定義（p: 141-143）
6.9.1 函式定義（p: 141-143）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.7.1 Function definitions
3.7.1 函式定義
3.7.1 函式定義

### See also

C++ documentation for Function definition

---
來源頁路徑：`en.cppreference.com/c/language/function_definition.html`
