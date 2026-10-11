# Constant expressions

> 來源：cppreference C 語言參考文件（離線轉換版）。

Several varieties of expressions are known as *constant expressions*
有幾種表示式被稱為常量表示式

### Preprocessor constant expression
預處理常量表示式

The expression following `#if` or `#elif` must expand to
跟隨 #if 或 #elif 的表示式必須展開為

- operators other than assignment, increment, decrement, function-call, or comma whose arguments are preprocessor constant expressions
其運算元為預處理常量表示式的、除賦值 、自增、自減 、函式呼叫 或逗號 之外的運運算元

- integer constants
整數常量

- character constants
字元常量

- the special preprocessor operator `defined`
特殊預處理運運算元 defined

Character constants, when evaluated in `#if`-expressions, may be interpreted in the source character set, the execution character set, or some other implementation-defined character set.
字元常量在 #if -表示式中求值時，可以按源 字符集、執行字符集或其他實現定義字符集進行解釋。

Integer arithmetic in `#if`-expressions is performed using the semantics of intmax_t for signed types and uintmax_t for unsigned types.
|   | (since C99) |

### Integer constant expression
整數常量表示式

An integer constant expression is an expression that consists only of
整數常量表示式是僅由以下各項組成的表示式

- operators other than assignment, increment, decrement, function-call, or comma, except that cast operators can only cast arithmetic types to integer types unless they are part of an operand to a sizeof , _Alignof(since C11)(until C23), alignas(since C23) or typeof/typeof_unqual(since C23) operator.
除賦值 、自增、自減 、函式呼叫 或逗號 之外的運運算元，但強制型別轉換運運算元只能將算術型別轉換為整數型別，除非它們是 sizeof 、_Alignof （C11 起）（C23 止）、alignas （C23 起）或 typeof/typeof_unqual （C23 起）運運算元的運算元的一部分。

- integer constants
整數常量

- enumeration constants
列舉常量

- character constants
字元常量

- floating constants, but only if they are immediately used as operands of casts to integer type
浮點常量，但僅限於立即用作轉換為整數型別的強制型別轉換的運算元

- sizeof operators whose operands are not VLA(since C99)
運算元不是 VLA 的 sizeof 運運算元（C99 起）

- _Alignof(until C23)alignof(since C23) operators
|   | (since C11) |

- named and compound literal constants that are of integer type or that are of arithmetic type and are the immediate operands of casts
|   | (since C23) |

Integer constant expressions are evaluated at compile time. The following contexts require expressions that are known as *integer constant expressions*:
整數常量表示式在編譯時求值。以下上下文需要稱為整數常量表示式 的表示式：

- The size of a bit-field.
位域的大小。

- The value of an enumeration constant
列舉常量的值

- The `case` label of a switch statement
switch 陳述式的 case 標籤

- The size of a non-VLA(since C99) array
非 VLA（C99 起）陣列的大小

- Integer to pointer implicit conversion.
整數到指標的隱式轉換。

- The index in an array designator
|   | (since C99) |

- The first argument of _Static_assert

- The integer argument of _Alignof(until C23)alignof(since C23)
|   | (since C11) |

- The number of bits N of a bit-precise integer type (`_BitInt(N)`)
|   | (since C23) |

### Static initializer
靜態初始化器

Expressions that are used in the initializers of objects with static and thread_local storage duration or declared with the constexpr storage-class specifier(since C23) must be either string literals or expressions that may be one of the following
用於具有 static 和 thread_local 儲存期的物件的初始化器，或以 constexpr 儲存類說明符（C23 起）宣告的物件初始化器中的表示式，必須是字串字面量，或者是以下之一的表示式

1) *arithmetic constant expression*, which is an expression of any arithmetic type that consists of
- operators other than assignment, increment, decrement, function-call, or comma, except that cast operators must be converting arithmetic types to other arithmetic types unless they are part of an operand to a sizeof , _Alignof(since C11)(until C23), alignof(since C23) or typeof/typeof_unqual(since C23) operator
除賦值 、自增、自減 、函式呼叫 或逗號 之外的運運算元，但強制型別轉換運運算元必須將算術型別轉換為其他算術型別，除非它們是 sizeof 、_Alignof （C11 起）（C23 止）、alignof （C23 起）或 typeof/typeof_unqual （C23 起）運運算元的運算元的一部分

- integer constants
整數常量

- floating constants
浮點常量

- enumeration constants
列舉常量

- character constants
字元常量

- sizeof operators whose operands are not VLA(since C99)
運算元不是 VLA 的 sizeof 運運算元（C99 起）
除賦值 、自增、自減 、函式呼叫 或逗號 之外的運運算元，但強制型別轉換運運算元必須將算術型別轉換為其他算術型別，除非它們是 sizeof 、_Alignof （C11 起）（C23 止）、alignof （C23 起）或 typeof/typeof_unqual （C23 起）運運算元的運算元的一部分 整數常量 浮點常量 列舉常量 字元常量 運算元不是 VLA 的 sizeof 運運算元（C99 起）

- _Alignof(until C23)alignof(since C23) operators
|   | (since C11) |

- named or compound literal constants of arithmetic type
|   | (since C23) |

2) a null pointer constant (e.g. NULL)

3) *address constant expression*, which is
- a null pointer

- lvalue designating an object of static storage duration or a function designator, converted to a pointer either
指定 static 儲存期物件的左值或函式指示符，轉換為指標的方式為

- by using the unary address-of operator
使用一元取位址運運算元

- by casting an integer constant to a pointer
將整數常量強制轉換為指標

- by array-to-pointer or function-to-pointer implicit conversion
透過陣列到指標或函式到指標的隱式轉換
使用一元取位址運運算元 將整數常量強制轉換為指標 透過陣列到指標或函式到指標的隱式轉換
一個指定 static 儲存期物件的空指標左值或函式指示符，透過以下方式之一轉換為指標：使用一元取位址運運算元、將整數常量強制轉換為指標、透過陣列到指標或函式到指標的隱式轉換

4) *address constant expression* of some complete object type, plus or minus an *integer constant expression*

5) a *named constant* which is, an identifier that is
- an enumeration constant

- a predefined constant (one of true, false or nullptr)

- declared with storage-class specifier constexpr and has an object type
or a postfix expression that applies the `**.**` member access operator to a named constant of structure or union type, even recursively.

6) a *compound literal constant*, which is
- a compound literal with storage-class specifier constexpr

- a postfix expression that applies the `**.**` member access operator to a compound literal constant of structure or union type, even recursively.

A *structure or union constant* is a named constant or compound literal constant with structure or union type, respectively. If the member-access operator `**.**` accesses a member of a union constant, the accessed member shall be the same as the member that is initialized by the union constant’s initializer.
|   | (since C23) |

7) constant expression of one of the other forms accepted by the implementation.

Unlike with integer constant expressions, static initializer expressions are not required to be evaluated at compile time; the compiler is at liberty to turn such initializers into executable code which is invoked prior to program startup.
與整數常量表示式不同，靜態初始化器表示式不要求在編譯時求值；編譯器可以自由地將此類初始化器轉換為在程式啟動之前呼叫的可執行程式碼。

```c
static int i = 2 || 1 / 0; // initializes i to value 1
```

|  | This section is incomplete
Reason: other mini-examples  |

The value of a floating-point static initializer is never less accurate than the value of the same expression executed at run time, but it may be better.
浮點靜態初始化器的值從不比在執行時執行的相同表示式的值精度低，但可能更精確。

### Floating-point constant expressions
浮點常量表示式

Arithmetic constant expressions of floating-point types that are not used in static initializers are always evaluated as-if during run-time and are affected by the current rounding (if FENV_ACCESS is on) and report errors as specified in math_errhandling.
未用於靜態初始化器的浮點型別算術常量表示式總是在執行時按如同求值的方式求值，受目前舍入方式影響（如果 FENV_ACCESS 開啟），並按 math_errhandling 中的規定報告錯誤。

```c
void f(void) { #pragma STDC FENV_ACCESS ON  static float x = 0.0 / 0.0; // static initializer: does not raise an exception  float w[] = { 0.0 / 0.0 }; // raises an exception  float y = 0.0 / 0.0; // raises an exception  double z = 0.0 / 0.0; // raises an exception }
```

### Notes

If an expression evaluates to a value that is not representable by its type, it cannot be used as a constant expression.
如果表示式求值得到的值無法由其型別表示，則它不能用作常量表示式。
Implementations may accept other forms of constant expressions. However, these constant expressions are not considered as integer constant expressions, arithmetic constant expressions, or address constant expressions, and thus cannot be used in the contexts requiring these kinds of constant expressions. For example, `int arr[(int)+1.0];` declares a VLA.
實現可以接受其他形式的常量表示式。然而，這些常量表示式不被視為整數常量表示式、算術常量表示式或位址常量表示式，因此不能用於需要這些型別常量表示式的上下文。例如，int arr [( int ) + 1.0 ]; 宣告一個 VLA。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.6 Constant expressions (p: 95-96)
6.6 常量表示式（p: 95-96）
6.6 常量表示式（p: 95-96）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.6 Constant expressions (p: 76-77)
6.6 常量表示式（p: 76-77）
6.6 常量表示式（p: 76-77）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.6 Constant expressions (p: 106-107)
6.6 常量表示式（p: 106-107）
6.6 常量表示式（p: 106-107）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.6 Constant expressions (p: 95-96)
6.6 常量表示式（p: 95-96）
6.6 常量表示式（p: 95-96）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.4 CONSTANT EXPRESSIONS
3.4 常量表示式
3.4 常量表示式

### See also

C++ documentation for Constant expressions

---
來源頁路徑：`en.cppreference.com/c/language/constant_expression.html`
