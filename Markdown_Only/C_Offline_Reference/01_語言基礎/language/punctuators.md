# Punctuation

> 來源：cppreference C 語言參考文件（離線轉換版）。

These are the punctuation symbols in C. The meaning of each symbol is detailed in the linked pages.
這些是 C 中的標點符號。每個符號的含義詳見連結頁面。

### `{` `}`

- In a struct or union definition, delimit the struct-declaration-list.
在 struct 或 union 定義中，界定 struct-declaration-list 。

- In an enum definition, delimit the enumerator list.
在 enum 定義中，界定列舉器列表。

- Delimit a compound statement. The compound statement may be part of a function definition.
界定複合陳述式 。複合陳述式可以是函式定義 的一部分。

- In initialization, delimit the initializers.
在初始化 中，界定初始化器。

### `[` `]`

- Subscript operator.
下標運運算元 。

- Part of array declarator in a declaration or a type-id.
在宣告或 type-id 中作為陣列宣告符的一部分。

- In initialization, introduce a designator for an array element. (since C99)
在初始化 中，引出一個陣列元素的指示符。（C99 起）

- In an attribute specifier, delimit the attributes. (since C23)
在 attribute specifier 中，界定屬性。（C23 起）

### `#`

- Introduce a preprocessing directive.
引出一個預處理指令 。

- The preprocessing operator for stringification.
用於字串化的預處理運運算元 。

### `##`

- The preprocessing operator for token pasting.
用於記號貼上的預處理運運算元 。

### `(` `)`

- In an expression, indicate grouping.
在表示式中，表示分組 。

- Function call operator.
函式呼叫運運算元 。

- In a sizeof, _Alignof(since C11) , typeof or typeof_unqual(since C23) expression, delimit the operand.
在 sizeof 、_Alignof（C11 起）、typeof 或 typeof_unqual（C23 起）表示式中，界定運算元。

- In an explicit cast, delimit the type-id.
在顯式強制型別轉換 中，界定 type-id。

- In a compound literal, delimit the type-id. (since C99)
在複合字面量 中，界定 type-id。（C99 起）

- In a declaration or a type-id, indicate grouping.
在宣告或 type-id 中，表示分組。

- In a function declarator (in a declaration or a type-id), delimit the parameter list.
在函式宣告符中（在宣告或 type-id 中），界定參數列表。

- In an if, switch, while, do-while, or for statement, delimit the controlling clause.
在 if 、switch 、while 、do-while 或 for 陳述式中，界定控制子句。

- In a function-like macro definition, delimit the macro parameters.
在類函式宏定義 中，界定宏參數。

- In a function-like macro invocation, delimit the macro arguments or prevent commas from being interpreted as argument separators.
在類函式宏呼叫 中，界定宏參數，或防止逗號被解釋為參數分隔符。

- Part of a `defined`, `__has_include`, `__has_embed` or `__has_c_attribute`(since C23) preprocessing operator.
作為 defined 、__has_include 、__has_embed 或 __has_c_attribute（C23 起）預處理運運算元的一部分。

- Part of a generic selection expression. (since C11)
作為泛型選擇表示式 的一部分。（C11 起）

- In an _Atomic type specifier, delimit the type-id. (since C11)
在 _Atomic 型別說明符中，界定 type-id。（C11 起）

- In a static assertion declaration, delimit the operands. (since C11)
在 static assertion 宣告 中，界定運算元。（C11 起）

- In an _Alignas specifier, delimit the operand. (since C11)
在 _Alignas 說明符中，界定運算元。（C11 起）

- In an attribute, delimit the attribute arguments. (since C23)
在 attribute 中，界定屬性參數。（C23 起）

- In a bit-precise integer type name (`_BitInt(N)`), delimit the size. (since C23)
在位精確整數型別名（_BitInt(N)）中，界定大小。（C23 起）

- Part of __VA_OPT__ replacement in a variadic macro definition. (since C23)
作為可變參數宏定義中 __VA_OPT__ 替換的一部分。（C23 起）

- In a preprocessor parameter used in `#embed` directives and `__has_embed` preprocessing expressions, delimit the preprocessor parameter clause. (since C23)
在 #embed 指令和 __has_embed 預處理表示式中使用的前處理器參數中，界定前處理器參數子句。（C23 起）

### `;`

- Indicate the end of
表示……的結束

- a statement (including the init-statement of a for statement)
一條陳述式（包括 for 陳述式的 init-statement）

- a declaration or struct-declaration-list
一條宣告或 struct-declaration-list
一條陳述式（包括 for 陳述式的 init-statement） 一條宣告或 struct-declaration-list

- Separate the second and third clauses of a for statement.
分隔 for 陳述式 的第二個和第三個子句。

### `:`

- Part of conditional operator.
作為條件運運算元 的一部分。

- Part of label declaration.
作為標籤宣告 的一部分。

- In a bit-field member declaration, introduce the width.
在位域成員宣告 中，引出寬度。

- Introduce an enum base, which specifies the underlying type of the enum. (since C23)
引出一個 enum 基 ，指定列舉的底層型別。（C23 起）

- In a generic association, delimit the type-id or `default` and the selected expression. (since C11)
在泛型關聯 中，界定 type-id 或 default 以及所選表示式。（C11 起）

### `...`

- In the parameter list of a function declarator, signify a variadic function.
在函式宣告符的參數列表中，表示可變參數函式 。

- In a macro definition, signify a variadic macro. (since C99)
在宏定義 中，表示可變參數宏。（C99 起）

### `?`

- Part of conditional operator.
作為條件運運算元 的一部分。

### `::`

- In an attribute, indicate attribute scope. (since C23)
在 attribute 中，表示屬性作用域。（C23 起）

- In a preprocessor prefixed parameter (used by `#embed` and `__has_embed`), indicate scope. (since C23)
在前處理器字首參數中（由 #embed 和 __has_embed 使用），表示作用域。（C23 起）

### `.`

- Member access operator.
成員訪問運運算元 。

- In initialization, introduce a designator for a struct/union member. (since C99)
在初始化 中，引出 struct/union 成員的指示符。（C99 起）

### `->`

- Member access operator.
成員訪問運運算元 。

### `~`

- Unary complement operator (a.k.a. bitwise not operator).
一元補運運算元（又稱按位取反運運算元）。

### `!`

- Logical not operator.
邏輯非運運算元 。

### `+`

- Unary plus operator.
一元正運運算元 。

- Binary plus operator.
二元加法運運算元 。

### `-`

- Unary minus operator.
一元負運運算元 。

- Binary minus operator.
二元減法運運算元 。

### `*`

- Indirection operator.
間接運運算元 。

- Multiplication operator.
乘法運運算元 。

- Pointer operator operator in a declarator or in a type-id.
在宣告符或 type-id 中的指標運運算元 。

- Placeholder for the length of a variable-length array declarator in a function declaration. (since C99)
在函式宣告 中作為可變長度陣列宣告符長度的佔位符。（C99 起）

### `/`

- Division operator.
除法運運算元 。

### `%`

- Modulo operator.
取模運運算元 。

### `^`

- Bitwise xor operator.
按位異或運運算元 。

### `&`

- Address-of operator.
取位址運運算元 。

- Bitwise and operator.
按位與運運算元 。

### `|`

- Bitwise or operator.
按位或運運算元 。

### `=`

- Simple assignment operator.
簡單賦值運運算元 。

- In initialization, delimit the object and the initializer list.
在初始化 中，界定物件和初始化器列表。

- In an enum definition, introduce the value of enumeration constant.
在 enum 定義 中，引出列舉常量的值。

### `+=`

- Compound assignment operator.
複合賦值運運算元 。

### `-=`

- Compound assignment operator.
複合賦值運運算元 。

### `*=`

- Compound assignment operator.
複合賦值運運算元 。

### `/=`

- Compound assignment operator.
複合賦值運運算元 。

### `%=`

- Compound assignment operator.
複合賦值運運算元 。

### `^=`

- Compound assignment operator.
複合賦值運運算元 。

### `&=`

- Compound assignment operator.
複合賦值運運算元 。

### `|=`

- Compound assignment operator.
複合賦值運運算元 。

### `==`

- Equality operator.
相等運運算元 。

### `!=`

- Inequality operator.
不等運運算元 。

### `<`

- Less-than operator.
小於運運算元 。

- Introduce a header name in
在……中引出一個標頭檔名

- a `#include` directive
一條 #include 指令

- a `__has_include` preprocessing expression (since C23)
一條 __has_include 預處理表示式（C23 起）

- a `#embed` directive (since C23)
一條 #embed 指令（C23 起）

- a `__has_embed` preprocessing expression (since C23)
一條 __has_embed 預處理表示式（C23 起）

- implementation-defined locations within a `#pragma` directive
#pragma 指令內的實現定義位置
一條 #include 指令 一條 __has_include 預處理表示式（C23 起） 一條 #embed 指令（C23 起） 一條 __has_embed 預處理表示式（C23 起） #pragma 指令內的實現定義位置

### `>`

- Greater-than operator.
大於運運算元 。

- Indicate the end of a header name in
表示……中標頭檔名的結束

- a `#include` directive
一條 #include 指令

- a `__has_include` preprocessing expression (since C23)
一條 __has_include 預處理表示式（C23 起）

- a `#embed` directive (since C23)
一條 #embed 指令（C23 起）

- a `__has_embed` preprocessing expression (since C23)
一條 __has_embed 預處理表示式（C23 起）

- implementation-defined locations within a `#pragma` directive
#pragma 指令內的實現定義位置
一條 #include 指令 一條 __has_include 預處理表示式（C23 起） 一條 #embed 指令（C23 起） 一條 __has_embed 預處理表示式（C23 起） #pragma 指令內的實現定義位置

### `<=`

- Less-than-or-equal-to operator.
小於或等於運運算元 。

### `>=`

- Greater-than-or-equal-to operator.
大於或等於運運算元 。

### `&&`

- Logical and operator.
邏輯與運運算元 。

### `||`

- Logical or operator.
邏輯或運運算元 。

### `<<`

- Bitwise shift operator.
按位移位運運算元 。

### `>>`

- Bitwise shift operator.
按位移位運運算元 。

### `<<=`

- Compound assignment operator.
複合賦值運運算元 。

### `>>=`

- Compound assignment operator.
複合賦值運運算元 。

### `++`

- Increment operator.
自增運運算元 。

### `--`

- Decrement operator.
自減運運算元 。

### `,`

- Comma operator.
逗號運運算元 。

- List separator in
在……中的列表分隔符

- the declarator list in a declaration
宣告中的宣告符列表

- initializer list in initialization, including compound literals(since C99)
初始化 中的初始化器列表，包括複合字面量（C99 起）

- the argument list in a function call expression
函式呼叫表示式中的參數列表

- the enumerator list in an enum declaration
enum 宣告中的列舉器列表

- a function parameter list
函式參數列表

- the macro parameter list in a function-like macro definition
類函式宏定義中的宏參數列表

- the macro argument list in a function-like macro invocation, unless found between an inner set of parentheses
類函式宏呼叫 中的宏參數列表，除非位於內層括號之間

- the generic association list in a generic selection expression (since C11)
泛型選擇表示式中的泛型關聯列表（C11 起）

- an attribute list (since C23)
屬性列表（C23 起）
宣告中的宣告符列表 初始化 中的初始化器列表，包括複合字面量（C99 起） 函式呼叫表示式中的參數列表 enum 宣告中的列舉器列表 函式參數列表 類函式宏定義中的宏參數列表 類函式宏呼叫 中的宏參數列表，除非位於內層括號之間 泛型選擇表示式 中的泛型關聯列表（C11 起） 屬性列表（C23 起）

- In a static assertion declaration, separate the arguments. (since C11)
在 static assertion 宣告 中，分隔參數。（C11 起）

- In a generic selection expression, separate the controlling expression and the generic association list. (since C11)
在泛型選擇表示式 中，分隔控制表示式和泛型關聯列表。（C11 起）

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.6 Punctuators (p: 68-69)
6.4.6 標點符號（p: 68-69）
6.4.6 標點符號（p: 68-69）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.4.6 Punctuators (p: 52-53)
6.4.6 標點符號（p: 52-53）
6.4.6 標點符號（p: 52-53）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.4.6 Punctuators (p: 72-73)
6.4.6 標點符號（p: 72-73）
6.4.6 標點符號（p: 72-73）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.4.6 Punctuators (p: 63-64)
6.4.6 標點符號（p: 63-64）
6.4.6 標點符號（p: 63-64）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.6 Punctuators
3.1.6 標點符號
3.1.6 標點符號

### See also

|  Alternative representations (C95)  |   | alternative spellings for certain operators  |

C++ documentation for Punctuation

---
來源頁路徑：`en.cppreference.com/c/language/punctuators.html`
