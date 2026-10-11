# Value categories

> 來源：cppreference C 語言參考文件（離線轉換版）。

Each expression in C (an operator with its arguments, a function call, a constant, a variable name, etc) is characterized by two independent properties: a type and a value category.
C 中的每個表示式（帶其參數的運運算元、函式呼叫、常量、變數名等）都具有兩個獨立的特徵：型別和值類別。
Every expression belongs to one of three value categories: lvalue, non-lvalue object (rvalue), and function designator.
每個表示式屬於三個值類別之一：左值（lvalue）、非左值物件（rvalue）和函式指示符。

### Lvalue expressions
左值表示式

Lvalue expression is any expression with object type other than the type `void`, which potentially designates an object (the behavior is undefined if an lvalue does not actually designate an object when it is evaluated). In other words, lvalue expression evaluates to the *object identity ﻿*. The name of this value category (“left value”) is historic and reflects the use of lvalue expressions as the left-hand operand of the assignment operator in the CPL programming language.
左值表示式是任何具有除 void 型別以外的物件型別的表示式，它可能指示一個物件（如果左值在求值時未實際指示物件，則行為是未定義的）。換句話說，左值表示式求值得到物件標識。該值類別的名稱（“left value”）是歷史性的，反映了左值表示式在 CPL 程式語言中作為賦值運運算元左運算元的用法。
Lvalue expressions can be used in the following *lvalue contexts ﻿*:
左值表示式可用於以下左值上下文：

- as the operand of the address-of operator (except if the lvalue designates a bit-field or was declared register).
作為取位址運運算元的運算元（除非該左值指示位域或被宣告為 register）。

- as the operand of the pre/post increment and decrement operators.
作為前置/後置遞增和遞減運運算元的運算元。

- as the left-hand operand of the member access (dot) operator.
作為成員訪問（點）運運算元的左運算元。

- as the left-hand operand of the assignment and compound assignment operators.
作為賦值和複合賦值運運算元的左運算元。

If an lvalue expression is used in any context other than sizeof, _Alignof, or the operators listed above, non-array lvalues of any complete type undergo lvalue conversion, which models the memory load of the value of the object from its location. Similarly, array lvalues undergo array-to-pointer conversion when used in any context other than `sizeof`, `_Alignof`, address-of operator, or array initialization from a string literal.
如果左值表示式用在 sizeof、_Alignof 或上述運運算元以外的任何上下文中，任何完整型別的非陣列左值都會經歷左值轉換，該轉換模擬了從物件位置對其值的記憶體載入。類似地，陣列左值在用於 sizeof、_Alignof、取位址運運算元或用字串字面量初始化陣列以外的任何上下文時，會經歷陣列到指標轉換。
The semantics of const/volatile/restrict-qualifiers and atomic types apply to lvalues only (lvalue conversion strips the qualifiers and removes atomicity).
const/volatile/restrict 限定符和原子型別的語意僅適用於左值（左值轉換會剝離限定符並移除原子性）。
The following expressions are lvalues:
以下表示式是左值：

- identifiers, including function named parameters, provided they were declared as designating objects (not functions or enumeration constants)
識別符號，包括函式命名參數，前提是它們被宣告為指示物件（而非函式或列舉常量）

- string literals
字串字面量

- (C99) compound literals
（C99）複合字面量

- parenthesized expression if the unparenthesized expression is an lvalue
如果未加括號的表示式是左值，則加括號後的表示式

- the result of a member access (dot) operator if its left-hand argument is lvalue
成員訪問（點）運運算元的結果，如果其左運算元是左值

- the result of a member access through pointer `**->**` operator
透過指標的 -> 運運算元進行成員訪問的結果

- the result of the indirection (unary `*****`) operator applied to a pointer to object
對指向物件的指標應用間接（一元 *）運運算元的結果

- the result of the subscription operator (`**[]**`)
下標運運算元（[]）的結果

#### Modifiable lvalue expressions

A *modifiable lvalue* is any lvalue expression of complete, non-array type which is not const-qualified, and, if it's a struct/union, has no members that are const-qualified, recursively.
可修改左值是任何完整、非陣列型別的左值表示式，它未被 const 限定，並且如果它是 struct/union，則遞迴地沒有任何被 const 限定的成員。
Only modifiable lvalue expressions may be used as arguments to increment/decrement, and as left-hand arguments of assignment and compound assignment operators.
只有可修改左值表示式才能用作遞增/遞減的參數，以及賦值和複合賦值運運算元的左運算元。

### Non-lvalue object expressions
非左值物件表示式

Known as *rvalues ﻿*, non-lvalue object expressions are the expressions of object types that do not designate objects, but rather values that have no object identity or storage location. The address of a non-lvalue object expression cannot be taken.
非左值物件表示式稱為 rvalue，是物件型別的表示式，它們不指示物件，而是指示沒有物件標識或儲存位置的值。無法對非左值物件表示式取位址。
The following expressions are non-lvalue object expressions:
以下表示式是非左值物件表示式：

- integer, character, and floating constants
整數、字元和浮點常量

- all operators not specified to return lvalues, including
所有未指定傳回左值的運運算元，包括

- any function call expression
任何函式呼叫表示式

- any cast expression (note that compound literals, which look similar, are lvalues)
任何 cast 表示式（注意，看起來相似的複合字面量是左值）

- member access operator (dot) applied to a non-lvalue structure/union, `f().x`, `(x, s1).a`, `(s1 = s2).m`
應用於非左值結構體/聯合的成員訪問（點）運運算元，f().x、(x, s1).a、(s1 = s2).m

- results of all arithmetic, relational, logical, and bitwise operators
所有算術、關係、邏輯和位運運算元的結果

- results of increment and decrement operators (note: pre-forms are lvalues in C++)
遞增和遞減運運算元的結果（注意：前置形式在 C++ 中是左值）

- results of assignment operators (note: also lvalues in C++)
賦值運運算元的結果（注意：在 C++ 中也是左值）

- the conditional operator (note: is lvalue in C++ if both the second and third operands are lvalues of the same type)
條件運運算元（注意：在 C++ 中，如果第二和第三運算元都是同型別的左值，則是左值）

- the comma operator (note: is lvalue in C++ if the second operand is)
逗號運運算元（注意：在 C++ 中，如果第二運算元是左值，則是左值）

- the address-of operator, even if neutralized by application to the result of unary `*****` operator
取位址運運算元，即使作用於一元 * 運運算元的結果而被中和
任何函式呼叫表示式 任何 cast 表示式（注意，看起來相似的複合字面量是左值） 應用於非左值結構體/聯合的成員訪問（點）運運算元，f().x、(x, s1).a、(s1 = s2).m 所有算術、關係、邏輯和位運運算元的結果 遞增和遞減運運算元的結果（注意：前置形式在 C++ 中是左值） 賦值運運算元的結果（注意：在 C++ 中也是左值） 條件運運算元（注意：在 C++ 中，如果第二和第三運算元都是同型別的左值，則是左值） 逗號運運算元（注意：在 C++ 中，如果第二運算元是左值，則是左值） 取位址運運算元，即使作用於一元 * 運運算元的結果而被中和

As a special case, expressions of type `void` are assumed to be non-lvalue object expressions that yield a value which has no representation and requires no storage.
作為特殊情況，void 型別的表示式被視為非左值物件表示式，其產生一個沒有表示且不需要儲存的值。

Note that a struct/union rvalue that has a member (possibly nested) of array type does in fact designate an object with temporary lifetime. This object can be accessed through lvalue expressions that form by indexing the array member or by indirection through the pointer obtained by array-to-pointer conversion of the array member.
|   | (since C99) |

### Function designator expression
函式指示符表示式

A function designator (the identifier introduced by a function declaration) is an expression of function type. When used in any context other than the address-of operator, sizeof, and _Alignof (the last two generate compile errors when applied to functions), the function designator is always converted to a non-lvalue pointer to function. Note that the function-call operator is defined for pointers to functions and not for function designators themselves.
函式指示符（由函式宣告引入的識別符號）是函式型別的表示式。在用於取位址運運算元、sizeof 和 _Alignof 以外的任何上下文時（後兩者用於函式時會產生編譯錯誤），函式指示符總是轉換為非左值的指向函式的指標。注意，函式呼叫運運算元是針對指向函式的指標定義的，而不是針對函式指示符本身。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.3.2.1 Lvalues, arrays, and function designators (p: 48-49)
6.3.2.1 左值、陣列和函式指示符（第 48-49 頁）
6.3.2.1 左值、陣列和函式指示符（第 48-49 頁）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.3.2.1 Lvalues, arrays, and function designators (p: 40)
6.3.2.1 左值、陣列和函式指示符（第 40 頁）
6.3.2.1 左值、陣列和函式指示符（第 40 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.3.2.1 Lvalues, arrays, and function designators (p: 54-55)
6.3.2.1 左值、陣列和函式指示符（第 54-55 頁）
6.3.2.1 左值、陣列和函式指示符（第 54-55 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.3.2.1 Lvalues, arrays, and function designators (p: 46)
6.3.2.1 左值、陣列和函式指示符（第 46 頁）
6.3.2.1 左值、陣列和函式指示符（第 46 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.2.2.1 Lvalues and function designators
3.2.2.1 左值和函式指示符
3.2.2.1 左值和函式指示符

### See also

C++ documentation for Value categories

---
來源頁路徑：`en.cppreference.com/c/language/value_category.html`
