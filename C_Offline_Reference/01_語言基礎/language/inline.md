# inline function specifier

> 來源：cppreference C 語言參考文件（離線轉換版）。

Declares an inline function.
宣告一個行內函式。

### Syntax

|   |

| `inline` function_declaration  |   |   |   | (since C99)  |

|   |

### Explanation

The intent of the `**inline**` specifier is to serve as a hint for the compiler to perform optimizations, such as function inlining, which usually require the definition of a function to be visible at the call site. The compilers can (and usually do) ignore presence or absence of the `inline` specifier for the purpose of optimization.
inline 說明符的意圖是作為編譯器執行最佳化的提示，例如函式內聯，這通常需要函式定義在呼叫點可見。編譯器可以（並且通常會）為了最佳化目的忽略 inline 說明符的存在或缺失。
If the compiler performs function inlining, it replaces a call of that function with its body, avoiding the overhead of a function call (placing data on stack and retrieving the result), which may result in a larger executable as the code for the function has to be repeated multiple times. The result is similar to function-like macros, except that identifiers and macros used in the function refer to the definitions visible at the point of definition, not at the point of call.
如果編譯器執行函式內聯，它會用函式體替換對該函式的呼叫，避免函式呼叫的開銷（將資料放在棧上並取回結果），這可能導致可執行檔案變大，因為函式的程式碼必須重複多次。結果類似於類似函式的宏，只不過函式中使用的識別符號和宏引用的是定義點可見的定義，而不是呼叫點可見的定義。
Regardless of whether inlining takes place, the following semantics of inline functions are guaranteed:
無論是否發生內聯，行內函式的以下語意得到保證：
Any function with internal linkage may be declared `static inline` with no other restrictions.
任何具有內部連結的函式都可以宣告為 static inline，沒有其他限制。
A non-static inline function cannot define a non-const function-local static and cannot refer to a file-scope static.
非 static 行內函式不能定義非 const 函式區域性靜態變數，也不能引用檔案作用域靜態變數。

```c
static int x; inline void f(void) {  static int n = 1; // error: non-const static in a non-static inline function  int k = x; // error: non-static inline function accesses a static variable }
```

If a non-static function is declared `inline`, then it must be defined in the same translation unit. The inline definition that does not use `extern` is not externally visible and does not prevent other translation units from defining the same function. This makes the `**inline**` keyword an alternative to `static` for defining functions inside header files, which may be included in multiple translation units of the same program.
如果非 static 函式被宣告為 inline，則必須在同一翻譯單元中定義。不使用 extern 的內聯定義不是外部可見的，也不阻止其他翻譯單元定義同一函式。這使得 inline 關鍵字成為在標頭檔中定義函式的 static 的替代方案，標頭檔可能包含在程式的多個翻譯單元中。
If a function is declared `inline` in some translation units, it does not need to be declared `inline` everywhere: at most one translation unit may also provide a regular, non-inline non-static function, or a function declared `extern inline`. This one translation unit is said to provide the *external definition*. In order to avoid undefined behavior, one external definition must exist in the program if the name of the function with external linkage is used in an expression, see one definition rule.
如果函式在某些翻譯單元中被宣告為 inline，則不需要在所有地方都宣告為 inline：最多一個翻譯單元也可以提供常規的、非 inline 非 static 函式，或宣告為 extern inline 的函式。該翻譯單元被稱為提供外部定義。為了避免未定義行為，如果外部連結的函式名在表示式中使用，則程式中必須存在一個外部定義，參見單一定義規則。
The address of an inline function with external linkage is always the address of the external definition, but when this address is used to make a function call, it's unspecified whether the *inline definition* (if present in the translation unit) or the *external definition* is called. The static objects defined within an inline definition are distinct from the static objects defined within the external definition:
具有外部連結的行內函式的位址始終是外部定義的位址，但當使用該位址進行函式呼叫時，呼叫的是內聯定義（如果存在於翻譯單元中）還是外部定義則是未指定的。內聯定義中定義的靜態變數與外部定義中定義的靜態變數是不同的：

```c
inline const char *saddr(void) // the inline definition for use in this file {  static const char name[] = "saddr";  return name; } int compare_name(void) {  return saddr() == saddr(); // unspecified behavior, one call could be external } extern const char *saddr(void); // an external definition is generated, too
```

A C program should not depend on whether the inline version or the external version of a function is called, otherwise the behavior is unspecified.
C 程式不應依賴函式呼叫的是內聯版本還是外部版本，否則行為是未指定的。

### Keywords

inline

### Notes

The `inline` keyword was adopted from C++, but in C++, if a function is declared `inline`, it must be declared `inline` in every translation unit, and also every definition of an inline function must be exactly the same (in C, the definitions may be different, and depending on the differences only results in unspecified behavior). On the other hand, C++ allows non-const function-local statics and all function-local statics from different definitions of an inline function are the same in C++ but distinct in C.
inline 關鍵字取自 C++，但在 C++ 中，如果函式被宣告為 inline，則必須在每個翻譯單元中宣告為 inline，而且行內函式的每個定義必須完全相同（在 C 中，定義可以不同，並且根據差異僅導致未指定行為）。另一方面，C++ 允許非 const 函式區域性靜態變數，並且行內函式的不同定義中的所有函式區域性靜態變數在 C++ 中是相同的，但在 C 中是不同的。

### Example

Header file "test.h"

```c
#ifndef TEST_H_INCLUDED #define TEST_H_INCLUDED inline int sum(int a, int b) {  return a + b; } #endif
```

Source file "sum.c"

```c
#include "test.h" extern inline int sum(int a, int b); // provides external definition
```

Source file "test1.c"

```c
#include <stdio.h> #include "test.h" extern int f(void); int main(void) {  printf("%d\n", sum(1, 2) + f()); }
```

Source file "test2.c"

```c
#include "test.h" int f(void) {  return sum(3, 4); }
```

Output

```c
10
```
|   |  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.4 Function specifiers (p: TBD)
6.7.4 函式說明符（p: TBD）
6.7.4 函式說明符（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.4 Function specifiers (p: TBD)
6.7.4 函式說明符（p: TBD）
6.7.4 函式說明符（p: TBD）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.4 Function specifiers (p: 125-127)
6.7.4 函式說明符（p: 125-127）
6.7.4 函式說明符（p: 125-127）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.4 Function specifiers (p: 112-113)
6.7.4 函式說明符 (p: 112-113)
6.7.4 函式說明符 (p: 112-113)

### See also

C++ documentation for `inline` specifier

---
來源頁路徑：`en.cppreference.com/c/language/inline.html`
