# Declarations

> 來源：cppreference C 語言參考文件（離線轉換版）。

A *declaration* is a C language construct that introduces one or more identifiers into the program and specifies their meaning and properties.
宣告是一種 C 語言結構，它將一個或多個識別符號引入程式並指定其含義和屬性。
Declarations may appear in any scope. Each declaration ends with a semicolon (just like a statement) and consists of two(until C23)three(since C23) distinct parts:
宣告可以出現在任何作用域中。每個宣告以分號結尾（與陳述式相同），由兩個（C23 之前）三個（C23 起）不同的部分組成：

|   |

| specifiers-and-qualifiers declarators-and-initializers ﻿(optional) `**;**`  |   | (1)  |   |   |

|   |

| attr-spec-seq specifiers-and-qualifiers declarators-and-initializers `**;**`  |   | (2)  |   | (since C23)  |

|   |

| attr-spec-seq `**;**`  |   | (3)  |   | (since C23)  |

|   |

where

| specifiers-and-qualifiers  |   | -  |   | whitespace-separated list of, in any order,
- type specifiers:

- `void`

- the name of an arithmetic type

- the name of an atomic type

- a name earlier introduced by a typedef declaration

- struct, union, or enum specifier

- a typeof specifier (since C23)

- zero or one storage-class specifiers: typedef, constexpr, auto, `register`, `static`, `extern`, `_Thread_local`

- zero or more type qualifiers: const, volatile, restrict, _Atomic

- (only when declaring functions), zero or more function specifiers: inline, _Noreturn

- zero or more alignment specifiers: _Alignas(since C11)(until C23)alignas(since C23)

| declarators-and-initializers  |   | -  |   | comma-separated list of declarators (each declarator provides additional type information and/or the identifier to declare). Declarators may be accompanied by initializers. The enum, struct, and union declarations may omit declarators, in which case they only introduce the enumeration constants and/or tags.  |

| attr-spec-seq  |   | -  |   | (C23)optional list of attributes, applied to the declared entities, or forms an attribute declaration if appears alone.  |

1,2) Simple declaration. Introduces one or more identifiers which denotes objects, functions, struct/union/enum tags, typedefs, or enumeration constants.

3) Attribute declaration. Does not declares any identifier, and has implementation-defined meaning if the meaning is not specified by the standard.

For example,

```c
int a, *b=NULL; // "int" is the type specifier,  // "a" is a declarator  // "*b" is a declarator and NULL is its initializer const int *f(void); // "int" is the type specifier  // "const" is the type qualifier  // "*f(void)" is the declarator enum COLOR {RED, GREEN, BLUE} c; // "enum COLOR {RED, GREEN, BLUE}" is the type specifier  // "c" is the declarator
```

The type of each identifier introduced in a declaration is determined by a combination of the type specified by the type specifier and the type modifications applied by its declarator. The type of a variable might also be inferred if `auto` specifier is used.(since C23)
宣告所引入之識別字的型別，由型別說明符指定的型別與宣告子套用的型別修飾共同決定。使用 auto 說明符時，也可以推導變數型別。（C23 起）
Attributes(since C23) may appear in specifiers-and-qualifiers, in which case they apply to the type determined by the preceding specifiers.
屬性（C23 起）可以出現在 specifiers-and-qualifiers 中，在這種情況下它們適用於由前面說明符確定的型別。

### Declarators

Each declarator is one of the following:
每個宣告符是以下之一：

|   |

| identifier attr-spec-seq ﻿(optional)  |   | (1)  |   |   |

|   |

| `**(**` declarator `**)**`  |   | (2)  |   |   |

|   |

| `*****` attr-spec-seq ﻿(optional) qualifiers ﻿(optional) declarator  |   | (3)  |   |   |

|   |

| noptr-declarator `**[**` `**static**`(optional) qualifiers ﻿(optional) expression `**]**`
noptr-declarator `**[**` qualifiers ﻿(optional) `*****` `**]**`
|   | (4)  |   |   |

|   |

| noptr-declarator `**(**` parameters-or-identifiers `**)**`  |   | (5)  |   |   |

|   |

1) the identifier that this declarator introduces.

2) any declarator may be enclosed in parentheses; this is required to introduce pointers to arrays and pointers to functions.

3) pointer declarator: the declaration `S * cvr D`; declares `D` as a cvr-qualified pointer to the type determined by `S`.

4) array declarator: the declaration `S D[N]` declares `D` as an array of `N` objects of the type determined by `S`. noptr-declarator is any other declarator except unparenthesized pointer declarator.

5) function declarator: the declaration `S D(params)` declared `D` as a function taking the parameters `params` and returning `S`. noptr-declarator is any other declarator except unparenthesized pointer declarator.

The reasoning behind this syntax is that when the identifier declared by the declarator appears in an expression of the same form as the declarator, it would have the type specified by the type specifier sequence.
這種語法背後的原理是，當宣告符宣告的識別符號出現在與宣告符形式相同的表示式中時，它將具有型別說明符序列指定的型別。

```c
struct C {  int member; // "int" is the type specifier  // "member" is the declarator } obj, *pObj = &obj; // "struct C { int member; }" is the type specifier // declarator "obj" defines an object of type struct C // declarator "*pObj" declares a pointer to C, // initializer "= &obj" provides the initial value for that pointer   int a = 1, *p = NULL, f(void), (*pf)(double); // the type specifier is "int" // declarator "a" defines an object of type int // initializer "=1" provides its initial value // declarator "*p" defines an object of type pointer to int // initializer "=NULL" provides its initial value // declarator "f(void)" declares a function taking void and returning int // declarator "(*pf)(double)" defines an object of type pointer // to function taking double and returning int   int (*(*foo)(double))[3] = NULL; // the type specifier is int // 1. declarator "(*(*foo)(double))[3]" is an array declarator: // the type declared is "/nested declarator/ array of 3 int" // 2. the nested declarator is "*(*foo)(double))", which is a pointer declarator // the type declared is "/nested declarator/ pointer to array of 3 int" // 3. the nested declarator is "(*foo)(double)", which is a function declarator // the type declared is "/nested declarator/ function taking double and returning // pointer to array of 3 int" // 4. the nested declarator is "(*foo)" which is a (parenthesized, as required by // function declarator syntax) pointer declarator. // the type declared is "/nested declarator/ pointer to function taking double // and returning pointer to array of 3 int" // 5. the nested declarator is "foo", which is an identifier. // The declaration introduces the identifier "foo" to refer to an object of type // "pointer to function taking double and returning pointer to array of 3 int" // The initializer "= NULL" provides the initial value of this pointer. // If "foo" is used in an expression of the form of the declarator, its type would be // int. int x = (*(*foo)(1.2))[0];
```

The end of every declarator that is not part of another declarator is a sequence point.
每個不屬於另一個宣告符的宣告符的結尾是一個順序點。
In all cases, attr-spec-seq is an optional sequence of attributes(since C23). When appearing immediately after the identifier, it applies to the object or function being declared.
在所有情況下，attr-spec-seq 是屬性的可選序列（C23 起）。當緊跟在識別符號之後出現時，它適用於正在宣告的物件或函式。

### Definitions

A *definition* is a declaration that provides all information about the identifiers it declares.
定義是一個提供其所宣告識別符號所有資訊的宣告。
Every declaration of an enum or a typedef is a definition.
enum 或 typedef 的每個宣告都是定義。
For functions, a declaration that includes the function body is a function definition:
對於函式，包含函式體的宣告是函式定義：

```c
int foo(double); // declaration int foo(double x) { return x; } // definition
```

For objects, a declaration that allocates storage (automatic or static, but not extern) is a definition, while a declaration that does not allocate storage (external declaration) is not.
對於物件，分配儲存的宣告（automatic 或 static，但不是 extern）是定義，而不分配儲存的宣告（外部宣告）不是。

```c
extern int n; // declaration int n = 10; // definition
```

For structs and unions, declarations that specify the list of members are definitions:
對於 struct 和 union，指定成員列表的宣告是定義：

```c
struct X; // declaration struct X { int n; }; // definition
```

### Redeclaration

A declaration cannot introduce an identifier if another declaration for the same identifier in the same scope appears earlier, except that
如果同一作用域中較早出現同一識別符號的另一個宣告，則宣告不能引入該識別符號，但以下情況除外：

- Declarations of objects with linkage (external or internal) can be repeated:
具有連結（外部或內部）的物件的宣告可以重複：

```c
extern int x; int x = 10; // OK extern int x; // OK static int n; static int n = 10; // OK static int n; // OK
```

- Non-VLA typedef can be repeated as long as it names the same type:
非 VLA 的 typedef 可以重複，只要它命名相同的型別：

```c
typedef int int_t; typedef int int_t; // OK
```

- struct and union declarations can be repeated:
struct 和 union 宣告可以重複：

```c
struct X; struct X { int n; }; struct X;
```

These rules simplify the use of header files.
這些規則簡化了標頭檔的使用。

### Notes

In C89, declarations within any compound statement (block scope) must appear in the beginning of the block, before any statements.
Also, in C89, functions returning `int` may be implicitly declared by the function call operator and function parameters of type `int` do not have to be declared when using old-style function definitions.
|   | (until C99) |

Empty declarators are prohibited; a simple declaration must have at least one declarator or declare at least one struct/union/enum tag, or introduce at least one enumeration constant.
禁止空宣告符；簡單宣告必須至少有一個宣告符，或至少宣告一個 struct/union/enum 標籤，或引入至少一個列舉常量。

If any part of a declarator is a variable-length array (VLA) declarator, the entire declarator's type is known as "variably-modified type". Types defined from variably-modified types are also variably modified (VM).
Declarations of any variably-modified types may appear only at block scope or function prototype scope and cannot be members of structs or unions. Although VLA can only have automatic or allocated storage duration, a VM type such as a pointer to a VLA may be static. There are other restrictions on the use of VM types, see goto, switch. longjmp
|   | (since C99) |

static_asserts are considered to be declarations from the point of view of the C grammar (so that they may appear anywhere a declaration may appear), but they do not introduce any identifiers and do not follow the declaration syntax.
|   | (since C11) |

Attribute declarations are also considered to be declarations (so that they may appear anywhere a declaration may appear), but they do not introduce any identifiers. A single `**;**` without attr-spec-seq is not an attribute declaration, but a statement.
|   | (since C23) |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7 Declarations (p: TBD)
6.7 宣告（第 TBD 頁）
6.7 宣告（第 TBD 頁）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7 Declarations (p: 78-105)
6.7 宣告（第 78-105 頁）
6.7 宣告（第 78-105 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7 Declarations (p: 108-145)
6.7 宣告（第 108-145 頁）
6.7 宣告（第 108-145 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7 Declarations (p: 97-130)
6.7 宣告（第 97-130 頁）
6.7 宣告（第 97-130 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5 Declarations
3.5 宣告
3.5 宣告

### See also

C++ documentation for Declarations

---
來源頁路徑：`en.cppreference.com/c/language/declarations.html`
