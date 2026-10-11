# Expressions

> 來源：cppreference C 語言參考文件（離線轉換版）。

An expression is a sequence of *operators* and their *operands*, that specifies a computation.
表示式是指定一個計算的運運算元及其運算元 的序列。
Expression evaluation may produce a result (e.g., evaluation of `2 + 2` produces the result `4`), may generate side-effects (e.g. evaluation of `printf("%d", 4)` sends the character `'4'` to the standard output stream), and may designate objects or functions.
運算式求值可能產生結果（例如 2 + 2 得到 4），也可能產生副作用（例如 printf ( "%d" , 4 ) 將字元「4」送到標準輸出串流），並可指定物件或函式。

#### General

- value categories (lvalue, non-lvalue object, function designator) classify expressions by their values
值類別（左值、非左值物件、函式指示符）按表示式的值對表示式進行分類

- order of evaluation of arguments and subexpressions specifies the order in which intermediate results are obtained
參數和子表示式的求值順序指定獲得中間結果的順序

### Operators

| Common operators  |

| Assignment  |   | Increment,
decrement  |   | Arithmetic  |   | Logical  |   | Comparison  |   | Member
access  |   | Other  |

```c
a = b a += b a -= b a *= b a /= b a %= b a &= b a |= b a ^= b a <<= b a >>= b
```
|   |
```c
++a --a a++ a--
```
|   |
```c
+a -a a + b a - b a * b a / b a % b ~a a & b a | b a ^ b a << b a >> b
```
|   |
```c
!a a && b a || b
```
|   |
```c
a == b a != b a < b a > b a <= b a >= b
```
|   |
```c
a[b] *a &a a->b a.b
```
|   |
```c
a(...) a, b (type) a a ? b : c sizeof
```

`_Alignof`
(since C11)
(until C23)
`alignof`
(since C23)

- operator precedence defines the order in which operators are bound to their arguments
運運算元優先順序定義運運算元與其運算元繫結的順序

- alternative representations are alternative spellings for some operators
替代表示是某些運運算元的替代拼寫

#### Conversions

- Implicit conversions take place when types of operands do not match the expectations of operators
當運算元型別與運運算元的期望不匹配時，會進行隱式轉換

- Casts may be used to explicitly convert values from one type to another.
強制型別轉換可用於將值從一種型別顯式轉換為另一種型別。

#### Other

- constant expressions can be evaluated at compile time and used in compile-time context (non-VLA(since C99)array sizes, static initializers, etc)
常量表示式可以在編譯時求值並用於編譯期上下文（非 VLA（C99 起）陣列大小、靜態初始化器等）

- generic selections can execute different expressions depending on the types of the arguments
|   | (since C11) |

- Floating-point arithmetic may raise exceptions and report errors as specified in math_errhandling

- The standard #pragmas `FENV_ACCESS`, `FP_CONTRACT`, and `CX_LIMITED_RANGE` as well as the floating-point evaluation precision and rounding direction control the way floating-point arithmetic are executed.
|   | (since C99) |

### Primary expressions
初級表示式

The operands of any operator may be other expressions or they may be *primary expressions* (e.g. in `1 + 2 * 3`, the operands of operator+ are the subexpression `2 * 3` and the primary expression `1`).
運算子的運算元可以是其他運算式，也可以是初級運算式。例如在 1 + 2 * 3 中，加法運算子的運算元是子運算式 2 * 3 和初級運算式 1。
Primary expressions are any of the following:
初級表示式是以下任何一種：

1) Constants and literals (e.g. `2` or `"Hello, world"`)

2) Suitably declared identifiers (e.g. `n` or `printf`)

3) Generic selections
|   | (since C11) |

Any expression in parentheses is also classified as a primary expression: this guarantees that the parentheses have higher precedence than any operator.
括號內的任何表示式也被歸類為初級表示式：這保證了括號具有比任何運運算元更高的優先順序。

#### Constants and literals

Constant values of certain types may be embedded in the source code of a C program using specialized expressions known as literals (for lvalue expressions) and constants (for non-lvalue expressions)
某些型別的常量值可以使用稱為字面量（用於左值表示式）和常量（用於非左值表示式）的專用表示式嵌入 C 程式的原始碼中

- integer constants are decimal, octal, or hexadecimal numbers of integer type.
整數常量是整數型別的十進位制、八進位制或十六進位制數。

- character constants are individual characters of type `int` suitable for conversion to a character type or of type `char8_t`,(since C23) `char16_t`, `char32_t`, or(since C11) `wchar_t`
字元常值可以是單一字元，型別為 int（且可轉換為字元型別）；也可以是單一字元，型別為 char8_t、char16_t、char32_t（C23 起）或 wchar_t（C11 起）。

- floating constants are values of type `float`, `double`, or `long double`
浮點常量是型別為 float 、double 或 long double 的值

- predefined constants `true`/`false` are values of type `bool`

- predefined constant nullptr is a value of type nullptr_t
|   | (since C23) |

- string literals are sequences of characters of type `char[]`, `char8_t[]`(since C23), `char16_t[]`, `char32_t[]`,(since C11) or `wchar_t[]` that represent null-terminated strings
字串常值是字元序列，型別可以是 char[]、char8_t[]（C23 起）、char16_t[]、char32_t[] 或 wchar_t[]（C11 起），表示以空字元結尾的字串。

- compound literals are values of struct, union, or array type directly embedded in program code
|   | (since C99) |

### Unevaluated expressions
未求值表示式

The operands of the `sizeof` operator are expressions that are not evaluated (unless they are VLAs)(since C99). Thus, `size_t n = sizeof(printf("%d", 4));` does not perform console output.
sizeof 的運算元不會被求值（VLA 除外，C99 起）。因此，執行 size_t n = sizeof ( printf ( "%d" , 4 )); 不會輸出任何內容。

The operands of the _Alignof(until C23)alignof(since C23) operator, the controlling expression of a generic selection, and size expressions of VLAs that are operands of `_Alignof`(until C23)`alignof`(since C23) are also expressions that are not evaluated.
|   | (since C11) |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.5 Expressions (p: TBD)
6.5 表示式（p: TBD）
6.5 表示式（p: TBD）

- 6.6 Constant expressions (p: TBD)
6.6 常量表示式（p: TBD）
6.6 常量表示式（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5 Expressions (p: 55-75)
6.5 表示式（p: 55-75）
6.5 表示式（p: 55-75）

- 6.6 Constant expressions (p: 76-77)
6.6 常量表示式（p: 76-77）
6.6 常量表示式（p: 76-77）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5 Expressions (p: 76-105)
6.5 表示式（p: 76-105）
6.5 表示式（p: 76-105）

- 6.6 Constant expressions (p: 106-107)
6.6 常量表示式（p: 106-107）
6.6 常量表示式（p: 106-107）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5 Expressions (p: 67-94)
6.5 表示式（p: 67-94）
6.5 表示式（p: 67-94）

- 6.6 Constant expressions (p: 95-96)
6.6 常量表示式（p: 95-96）
6.6 常量表示式（p: 95-96）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3 EXPRESSIONS
3.3 表示式
3.3 表示式

- 3.4 CONSTANT EXPRESSIONS
3.4 常量表示式
3.4 常量表示式

### See also

C++ documentation for Expressions

---
來源頁路徑：`en.cppreference.com/c/language/expressions.html`
