# Function declarations

> 來源：cppreference C 語言參考文件（離線轉換版）。

A function declaration introduces an identifier that designates a function and, optionally, specifies the types of the function parameters (the *prototype*). Function declarations (unlike definitions) may appear at block scope as well as file scope.
函式宣告引入一個指示函式的識別符號，並可選擇地指定函式參數的型別（原型）。函式宣告（與定義不同）可以出現在塊作用域以及檔案作用域。

### Syntax

In the declaration grammar of a function declaration, the type-specifier sequence, possibly modified by the declarator, designates the *return type* (which may be any type other than array or function type), and the declarator has one of three forms:
函式宣告的語法中，型別說明符序列決定函式的傳回型別；這個型別可由宣告子調整，除了陣列或函式型別之外皆可。宣告子有以下三種形式：

|   |

| noptr-declarator `**(**` parameter-list `**)**` attr-spec-seq(optional)  |   | (1)  |   |   |

|   |

| noptr-declarator `**(**` identifier-list `**)**` attr-spec-seq(optional)  |   | (2)  |   | (until C23)  |

|   |

| noptr-declarator `**(**` `**)**` attr-spec-seq(optional)  |   | (3)  |   |   |

|   |

where

| noptr-declarator  |   | -  |   | any declarator except unparenthesized pointer declarator. The identifier that is contained in this declarator is the identifier that becomes the function designator.  |

| parameter-list  |   | -  |   | either the single keyword `void` or a comma-separated list of *parameters*, which may end with an ellipsis parameter  |

| identifier-list  |   | -  |   | comma-separated list of identifiers, only possible if this declarator is used as part of old-style function definition  |

| attr-spec-seq  |   | -  |   | (C23)an optional list of attributes, applied to the function type  |

1) New-style (C89) function declaration. This declaration both introduces the function designator itself and also serves as a function prototype for any future function call expressions, forcing conversions from argument expressions to the declared parameter types and compile-time checks for the number of arguments.
```c
int max(int a, int b); // declaration int n = max(12.01, 3.14); // OK, conversion from double to int
```

2) (until C23) Old-style (K&R) function definition. This declaration does not introduce a prototype and any future function call expressions will perform default argument promotions and will invoke undefined behavior if the number of arguments doesn't match the number of parameters.
```c
int max(a, b)   int a, b; // definition expects ints; the second call is undefined {  return a > b ? a : b; } int n = max(true, (char)'a'); // calls max with two int args (after promotions) int n = max(12.01f, 3.14); // calls max with two double args (after promotions)
```

3) Non-prototype function declaration. This declaration does not introduce a prototype(until C23). A new style function declaration equivalent to the parameter-list `void`(since C23).

### Explanation

The return type of the function, determined by the type specifier in specifiers-and-qualifiers and possibly modified by the declarator as usual in declarations, must be a non-array object type or the type `void`. If the function declaration is not a definition, the return type can be incomplete. The return type cannot be cvr-qualified: any qualified return type is adjusted to its unqualified version for the purpose of constructing the function type.
函式的傳回型別由 specifiers-and-qualifiers 中的型別說明符決定，也可能依宣告規則由宣告子調整。傳回型別必須是非陣列物件型別或 void；若這只是函式宣告而非定義，傳回型別可以是不完整型別。傳回型別不可帶有 cvr 限定符；建構函式型別時，任何限定版本都會調整為未限定版本。

```c
void f(char *s); // return type is void int sum(int a, int b); // return type of sum is int. int (*foo(const void *p))[3]; // return type is pointer to array of 3 int double const bar(void); // declares function of type double(void) double (*barp)(void) = bar; // OK: barp is a pointer to double(void) double const (*barpc)(void) = barp; // OK: barpc is also a pointer to double(void)
```

Function declarators can be combined with other declarators as long as they can share their type specifiers and qualifiers
函式宣告符可以與其他宣告符組合，只要它們可以共享型別說明符和限定符

```c
int f(void), *fip(), (*pfi)(), *ap[3]; // declares two functions and two objects inline int g(int), n; // Error: inline qualifier is for functions only typedef int array_t[3]; array_t a, h(); // Error: array type cannot be a return type for a function
```

If a function declaration appears outside of any function, the identifier it introduces has file scope and external linkage, unless `static` is used or an earlier static declaration is visible. If the declaration occurs inside another function, the identifier has block scope (and also either internal or external linkage).
函式宣告若位於所有函式之外，引入的識別字具有檔案作用域與外部連結；若使用 static，或可見的先前宣告使用了 static，則例外。宣告若位於另一個函式內，識別字具有區塊作用域，並可具有內部或外部連結。

```c
int main(void) {  int f(int); // external linkage, block scope  f(1); // definition needs to be available somewhere in the program }
```

The parameters in a declaration that is not part of a function definition(until C23) do not need to be named:
不屬於函式定義的宣告中的參數（至 C23 止）不需要命名：

```c
int f(int, int); // declaration // int f(int, int) { return 7; } // Error: parameters must be named in definitions // This definition is allowed since C23
```

Each parameter in a parameter-list is a declaration that introduced a single variable, with the following additional properties:
參數列表中的每個參數都是一個引入單個變數的宣告，具有以下附加屬性：

- the identifier in the declarator is optional (except if this function declaration is part of a function definition)(until C23)
宣告符中的識別符號是可選的（除非該函式宣告是函式定義的一部分）（至 C23 止）

```c
int f(int, double); // OK int g(int a, double b); // also OK // int f(int, double) { return 1; } // Error: definition must name parameters // This definition is allowed since C23
```

- the only storage class specifier allowed for parameters is `register`, and it is ignored in function declarations that are not definitions
參數唯一允許的儲存類說明符是 register，並且在不是定義的函式宣告中會被忽略

```c
int f(static int x); // Error int f(int [static 10]); // OK (array index static is not a storage class specifier)
```

- any parameter of array type is adjusted to the corresponding pointer type, which may be qualified if there are qualifiers between the square brackets of the array declarator(since C99)
任何陣列型別的參數都會被調整為相應的指標型別，如果陣列宣告符的方括號之間有限定符，則該指標型別可以被限定（自 C99 起）

```c
int f(int[]); // declares int f(int*) int g(const int[10]); // declares int g(const int*) int h(int[const volatile]); // declares int h(int * const volatile) int x(int[*]); // declares int x(int*)
```

- any parameter of function type is adjusted to the corresponding pointer type
任何函式型別的參數都會被調整為相應的指標型別

```c
int f(char g(double)); // declares int f(char (*g)(double)) int h(int(void)); // declares int h(int (*)(void))
```

- the parameter list may terminate with `**, ...**` or be `**...**`(since C23), see variadic functions for details.
參數列表可以以 , ... 結尾或為 ...（自 C23 起），詳見可變參數函式。

```c
int f(int, ...);
```

- parameters cannot have type `void` (but can have type pointer to void). The special parameter list that consists entirely of the keyword `void` is used to declare functions that take no parameters.
參數不可是 void 型別，但可以是 void 指標。若參數列表只有 void，表示函式不接受任何參數。

```c
int f(void); // OK int g(void x); // Error
```

- any identifier that appears in a parameter list that could be treated as a typedef name or as a parameter name is treated as a typedef name: `int f(size_t, uintptr_t)` is parsed as a new-style declarator for a function taking two unnamed parameters of type size_t and uintptr_t, not an old-style declarator that begins the definition of a function taking two parameters named "size_t" and "uintptr_t"
在參數列表中，若某個識別字既可能是 typedef 名稱，也可能是參數名稱，會優先視為 typedef 名稱。例如 int f(size_t, uintptr_t) 會解析為新式宣告，表示函式接受兩個未命名參數，型別分別是 size_t 和 uintptr_t；不會解析成舊式宣告，開始定義一個參數名稱為 "size_t" 和 "uintptr_t" 的函式。

- parameters may have incomplete type and may use the VLA notation [*](since C99) (except that in a function definition, the parameter types after array-to-pointer and function-to-pointer adjustment must be complete)
參數可以具有不完整型別，並可以使用 VLA 表示法 [*]（自 C99 起）（但在函式定義中，經過陣列到指標和函式到指標調整後的參數型別必須是完整的）

Attribute specifier sequences can also applied to function parameters.
|   | (since C23) |

See function call operator for other details on the mechanics of a function call and return for returning from functions.
關於函式呼叫機制的其他細節見函式呼叫運運算元，關於從函式傳回的 return 見 return。

### Notes

Unlike in C++, the declarators `f()` and `f(void)` have different meaning: the declarator `f(void)` is a new-style (prototype) declarator that declares a function that takes no parameters. The declarator `f()` is a declarator that declares a function that takes *unspecified* number of parameters (unless used in a function definition)

```c
int f(void); // declaration: takes no parameters int g(); // declaration: takes unknown parameters int main(void) {  f(1); // compile-time error  g(2); // undefined behavior } int f(void) { return 1; } // actual definition int g(a,b,c,d) int a,b,c,d; { return 2; } // actual definition
```
|   | (until C23) |

Unlike in a function definition, the parameter list may be inherited from a typedef
與函式定義不同，參數列表可以從 typedef 繼承

```c
typedef int p(int q, int r); // p is a function type int(int, int) p f; // declares int f(int, int)
```

In C89, specifiers-and-qualifiers was optional, and if omitted, the return type of the function defaulted to `int` (possibly amended by the declarator).

```c
*f() { // function returning int*  return NULL; }
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

- 6.7.6.3 Function declarators (including prototypes) (p: 96-98)
6.7.6.3 函式宣告器（包括原型）（p: 96-98）
6.7.6.3 函式宣告器（包括原型）（p: 96-98）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.6.3 Function declarators (including prototypes) (p: 133-136)
6.7.6.3 函式宣告器（包括原型）（p: 133-136）
6.7.6.3 函式宣告器（包括原型）（p: 133-136）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.5.3 Function declarators (including prototypes) (p: 118-121)
6.7.5.3 函式宣告器（包括原型）（p: 118-121）
6.7.5.3 函式宣告器（包括原型）（p: 118-121）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.4.3 Function declarators (including prototypes)
3.5.4.3 函式宣告器（包括原型）
3.5.4.3 函式宣告器（包括原型）

### See also

C++ documentation for Function declaration

---
來源頁路徑：`en.cppreference.com/c/language/function_declaration.html`
