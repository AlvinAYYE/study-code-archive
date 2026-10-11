# Type

> 來源：cppreference C 語言參考文件（離線轉換版）。

(See also arithmetic types for the details on most built-in types and the list of type-related utilities that are provided by the C library.)
（另請參閱「算術型別」，了解大多數內建型別的細節，以及 C 標準函式庫提供的型別相關工具。）
Objects, functions, and expressions have a property called *type*, which determines the interpretation of the binary value stored in an object or evaluated by the expression.
物件、函式和運算式都有型別。型別決定如何解讀物件中儲存的值，以及運算式求得的值。

### Type classification
型別分類

The C type system consists of the following types:
C 型別系統由以下型別組成：

- the type `void`
`void` 型別

- basic types
基本型別

- the type `char`
`char` 型別

- signed integer types
有符號整數型別

- standard: `signed char`, `short`, `int`, `long`, `long long`(since C99)
標準：signed char、short、int、long、long long（自 C99 起）

- bit-precise: `_BitInt(N)` where N is an integer constant expression that specifies the number of bits that are used to represent the type, including the sign bit. Each value of N designates a distinct type.
位元精確型別：`_BitInt(N)`。`N` 是整數常數運算式，指定表示此型別所用的位元數（包含符號位元）；不同的 `N` 代表不同型別。
|   | (since C23) |

- extended: implementation defined, e.g. `__int128`
擴充型別：由實作決定，例如 `__int128`。
|   | (since C99) |

- unsigned integer types
無符號整數型別

- standard: `_Bool`,(since C99) `unsigned char`, `unsigned short`, `unsigned int`, `unsigned long`, `unsigned long long`(since C99)
標準：_Bool（自 C99 起）、unsigned char、unsigned short、unsigned int、unsigned long、unsigned long long（自 C99 起）

- bit-precise: `unsigned _BitInt(N)` where `N` is an integer constant expression that specifies the number of bits that are used to represent the type. Each value of `N` designates a distinct type. This category includes the type `unsigned _BitInt(1)` which does not have a corresponding bit-precise signed integer type.
位元精確型別：`unsigned _BitInt(N)`。`N` 是整數常數運算式，指定表示此型別所用的位元數；不同的 `N` 代表不同型別。此類型也包括 `unsigned _BitInt(1)`，但它沒有相對應的位元精確有號整數型別。
|   | (since C23) |

- extended: implementation-defined, e.g. `__uint128`
擴充型別：由實作決定，例如 `__uint128`。
|   | (since C99) |

- floating-point types
浮點型別

- real floating-point types: `float`, `double`, `long double`
實數浮點型別：`float`、`double`、`long double`

- decimal real floating-point types: `_Decimal32`, `_Decimal64`, `_Decimal128`
十進位實數浮點型別：`_Decimal32`、`_Decimal64`、`_Decimal128`
|   | (since C23) |

- complex types: `float _Complex`, `double _Complex`, `long double _Complex`
複數型別：`float _Complex`、`double _Complex`、`long double _Complex`

- imaginary types: `float _Imaginary`, `double _Imaginary`, `long double _Imaginary`
虛數型別：`float _Imaginary`、`double _Imaginary`、`long double _Imaginary`
|   | (since C99) |

- enumerated types
列舉型別

- derived types
衍生型別

- array types
陣列型別

- structure types
結構體型別

- union types
聯合型別

- function types
函式型別

- pointer types
指標型別

- atomic types
原子型別
|   | (since C11) |

For every type listed above several qualified versions of its type may exist, corresponding to the combinations of one, two, or all three of the const, volatile, and restrict qualifiers (where allowed by the qualifier's semantics).
上述型別可能各自有多種限定版本：在語意允許的情況下，可套用 `const`、`volatile`、`restrict` 中一種、兩種或全部三種限定詞。

#### Type groups

- *object types*: all types that aren't function types
物件型別：所有不是函式型別的型別

- *character types*: `char`, `signed char`, `unsigned char`
字元型別：char、signed char、unsigned char

- *integer types*: `char`, signed integer types, unsigned integer types, enumerated types
整數型別：char、有符號整數型別、無符號整數型別、列舉型別

- *real types*: integer types and real floating types
實型別：整數型別和實浮點型別

- arithmetic types: integer types and floating types
算術型別：整數型別和浮點型別

- *scalar types*: arithmetic types, pointer types, and nullptr_t(since C23)
標量型別：算術型別、指標型別和 nullptr_t（自 C23 起）

- *aggregate types*: array types and structure types
聚合型別：陣列型別和結構體型別

- *derived declarator types*: array types, function types, and pointer types
派生宣告器型別：陣列型別、函式型別和指標型別

Constructing a complete object type such that the number of bytes in its object representation is not representable in the type size_t (i.e. the result type of sizeof operator), including forming such a VLA type at runtime,(since C99) is undefined behavior.
如果完整物件型別的物件表示大小超出 `size_t` 可表示的範圍，建立這種型別的行為便未定義；C99 起，執行期間建立大小超出範圍的 VLA 型別也一樣。

### Compatible types
相容型別

In a C program, the declarations referring to the same object or function in *different translation units* do not have to use the same type. They only have to use sufficiently similar types, formally known as *compatible types*. Same applies to function calls and lvalue accesses; argument types must be *compatible* with parameter types and lvalue expression type must be *compatible* with the object type that is accessed.
在 C 程式中，不同翻譯單元對同一物件或函式的宣告不必寫成完全相同的型別，但型別必須符合標準所說的「相容型別」規則。函式呼叫也遵循這項規則：引數型別須與參數型別相容；透過左值運算式存取物件時，運算式型別也須與該物件型別相容。
The types `T` and `U` are compatible, if
以下情況會使型別 `T` 和 `U` 相容：

- they are the same type (same name or aliases introduced by a typedef)
它們是同一型別（相同的名稱或由 typedef 引入的別名）

- they are identically cvr-qualified versions of compatible unqualified types
它們是相容的非限定型別，而且套用的 `const`、`volatile`、`restrict` 限定完全相同。

- they are pointer types and are pointing to compatible types
它們是指標型別並且指向相容的型別

- they are array types, and
它們是陣列型別，並且

- their element types are compatible, and
它們的元素型別相容，並且

- if both have constant size, that size is the same. Note: arrays of unknown bound are compatible with any array of compatible element type. VLA is compatible with any array of compatible element type.(since C99)
如果兩者都具有常量大小，則該大小相同。注意：未知界陣列與任何具有相容元素型別的陣列相容。VLA 與任何具有相容元素型別的陣列相容。（自 C99 起）
它們的元素型別相容，並且如果兩者都具有常量大小，則該大小相同。注意：未知界陣列與任何具有相容元素型別的陣列相容。VLA 與任何具有相容元素型別的陣列相容。（自 C99 起）

- they are both structure/union/enumeration types, and
它們都是結構體/聯合體/列舉型別，並且

- (C99)if one is declared with a tag, the other must also be declared with the same tag.
(C99) 如果其中一個用標籤宣告，則另一個也必須用相同的標籤宣告。

- if both are completed types, their members must correspond exactly in number, be declared with compatible types, and have matching names.
如果兩者都是完整型別，則它們的成員在數量上必須完全對應，以相容的型別宣告，並且名稱相匹配。

- additionally, if they are enumerations, corresponding members must also have the same values.
此外，如果它們是列舉，則對應的成員還必須具有相同的值。

- additionally, if they are structures or unions,
此外，如果它們是結構體或聯合體，

- Corresponding members must be declared in the same order (structures only)
對應的成員必須以相同的順序宣告（僅限結構體）

- Corresponding bit-fields must have the same widths.
對應的位域必須具有相同的寬度。
對應的成員必須以相同的順序宣告（僅限結構體），對應的位域必須具有相同的寬度。
(C99) 如果其中一個用標籤宣告，則另一個也必須用相同的標籤宣告。如果兩者都是完整型別，則它們的成員在數量上必須完全對應，以相容的型別宣告，並且名稱相匹配。此外，如果它們是列舉，則對應的成員還必須具有相同的值。此外，如果它們是結構體或聯合體，對應的成員必須以相同的順序宣告（僅限結構體），對應的位域必須具有相同的寬度。

- one is an enumerated type and the other is that enumeration's underlying type
一個是列舉型別，另一個是該列舉的底層型別

- they are function types, and
它們是函式型別，並且

- their return types are compatible
它們的傳回型別相容

- they both use parameter lists, the number of parameters (including the use of the ellipsis) is the same, and the corresponding parameter, after applying array-to-pointer and function-to-pointer type adjustments and after stripping top-level qualifiers, have compatible types
兩者都使用參數列表，參數數量（包括省略號的使用）相同，並且對應參數在應用陣列到指標和函式到指標的型別調整並去除頂層限定符之後具有相容的型別
它們的傳回型別相容；兩者都使用參數列表，參數數量（包括省略號的使用）相同，並且對應參數在應用陣列到指標和函式到指標的型別調整並去除頂層限定符之後具有相容的型別

- one is an old-style (parameter-less) definition, the other has a parameter list, the parameter list does not use an ellipsis and each parameter is compatible (after function parameter type adjustment) with the corresponding old-style parameter after default argument promotions

- one is an old-style (parameter-less) declaration, the other has a parameter list, the parameter list does not use an ellipsis, and all parameters (after function parameter type adjustment) are unaffected by default argument promotions
|   | (until C23) |

The type `char` is not compatible with `signed char` and not compatible with `unsigned char`.
型別 char 與 signed char 不相容，與 unsigned char 也不相容。
If two declarations refer to the same object or function and do not use compatible types, the behavior of the program is undefined.
如果兩個宣告引用同一物件或函式但未使用相容型別，則程式的行為是未定義行為。

```c
// Translation Unit 1 struct S { int a; }; extern struct S *x; // compatible with TU2's x, but not with TU3's x // Translation Unit 2 struct S; extern struct S *x; // compatible with both x's // Translation Unit 3 struct S { float a; }; extern struct S *x; // compatible with TU2's x, but not with TU1's x // the behavior is undefined
```

```c
// Translation Unit 1 #include <stdio.h> struct s { int i; }; // compatible with TU3's s, but not TU2's extern struct s x = {0}; // compatible with TU3's x extern void f(void); // compatible with TU2's f int main() {  f();  return x.i; } // Translation Unit 2 struct s { float f; }; // compatible with TU4's s, but not TU1's s extern struct s y = {3.14}; // compatible with TU4's y void f() // compatible with TU1's f {  return; } // Translation Unit 3 struct s { int i; }; // compatible with TU1's s, but not TU2's s extern struct s x; // compatible with TU1's x // Translation Unit 4 struct s { float f; }; // compatible with TU2's s, but not TU1's s extern struct s y; // compatible with TU2's y // the behavior is well-defined: only multiple declarations // of objects and functions must have compatible types, not the types themselves
```

Note: C++ has no concept of compatible types. A C program that declares two types that are compatible but not identical in different translation units is not a valid C++ program.
注意：C++ 沒有相容型別的概念。在不同翻譯單元中宣告兩個相容但不相同的型別的 C 程式不是有效的 C++ 程式。

### Composite types
複合型別

A composite type can be constructed from two types that are compatible; it is a type that is compatible with both of the two types and satisfies the following conditions:
複合型別可以從兩個相互相容的型別構造得出；它是與這兩個型別都相容 並滿足以下條件的型別：

- If both types are array types, the following rules are applied:
如果兩個型別都是陣列型別，則適用以下規則：

- If one type is an array of known constant size, the composite type is an array of that size.
如果其中一個型別是已知常量大小的陣列，則複合型別是該大小的陣列。
如果其中一個型別是已知常量大小的陣列，則複合型別是該大小的陣列。

- Otherwise, if one type is a VLA whose size is specified by an expression that is not evaluated, a program necessitating the composite type of both types has undefined behavior.

- Otherwise, if one type is a VLA whose size is specified, the composite type is a VLA of that size.

- Otherwise, if one type is a VLA of unspecified size, the composite type is a VLA of unspecified size.
|   | (since C99) |

- Otherwise, both types are arrays of unknown size and the composite type is an array of unknown size.
否則，兩個型別都是大小未知的陣列，複合型別是大小未知的陣列。

The element type of the composite type is the composite type of the two element types.
複合型別的元素型別是兩個元素型別的複合型別。
否則，兩個型別都是大小未知的陣列，複合型別是大小未知的陣列。複合型別的元素型別是兩個元素型別的複合型別。

- If only one type is a function type with a parameter type list (a function prototype), the composite type is a function prototype with the parameter type list.
|   | (until C23) |

- If both types are function types with parameter type lists, the type of each parameter in the composite parameter type list is the composite type of the corresponding parameters.
如果兩個型別都是帶參數型別列表的函式型別，則複合參數型別列表中每個參數的型別是相應參數的複合型別。

These rules apply recursively to the types from which the two types are derived.
這些規則遞迴地應用於派生出這兩個型別的那個型別。

```c
// Given the following two file scope declarations: int f(int (*)(), double (*)[3]); int f(int (*)(char *), double (*)[]); // C23: Error: conflicting types for 'f' // The resulting composite type for the function is: int f(int (*)(char *), double (*)[3]);
```

For an identifier with internal or external linkage declared in a scope in which a prior declaration of that identifier is visible, if the prior declaration specifies internal or external linkage, the type of the identifier at the later declaration becomes the composite type.
對於在該識別符號的先前宣告可見的作用域中所宣告的、具有內部或外部連結的識別符號，如果先前的宣告指定了內部或外部連結，則在後一個宣告處該識別符號的型別成為複合型別。

### Incomplete types
不完整型別

An incomplete type is an object type that lacks sufficient information to determine the size of the objects of that type. An incomplete type may be completed at some point in the translation unit.
不完整型別是缺乏足夠資訊以確定該型別物件大小的物件型別。不完整型別可以在翻譯單元中的某個時刻被補全。
The following types are incomplete:
以下型別是不完整的：

- the type `void`. This type cannot be completed.
型別 void。該型別無法被補全。

- array type of unknown size. It can be completed by a later declaration that specifies the size.
大小未知的陣列型別。它可以透過指定其大小的後續宣告被補全。

```c
extern char a[]; // the type of a is incomplete (this typically appears in a header) char a[10]; // the type of a is now complete (this typically appears in a source file)
```

- structure or union type of unknown content. It can be completed by a declaration of the same structure or union that defines its content later in the same scope.
內容未知的結構體或聯合體型別。它可以透過在同一作用域中稍後定義其內容的同一結構體或聯合體的宣告被補全。

```c
struct node {  struct node* next; // struct node is incomplete at this point }; // struct node is complete at this point
```

### Type names

A type may have to be named in context other than the declaration. In these situations, *type name* is used, which is, grammatically, exactly the same as a list of *type-specifiers* and *type-qualifiers*, followed by the *declarator* (see declarations) as would be used to declare a single object or function of this type, except that the identifier is omitted:
型別可能必須在宣告以外的上下文中被命名。在這些情況下會使用型別名，它在語法上與用於宣告該型別的單個物件或函式的型別說明符和型別限定符列表後跟宣告器（見宣告）完全相同，只是省略了識別符號：

```c
int n; // declaration of an int sizeof(int); // use of type name int *a[3]; // declaration of an array of 3 pointers to int sizeof(int *[3]); // use of type name int (*p)[3]; // declaration of a pointer to array of 3 int sizeof(int (*)[3]); // use of type name int (*a)[*] // declaration of pointer to VLA (in a function parameter) sizeof(int (*)[*]) // use of type name (in a function parameter) int *f(void); // declaration of function sizeof(int *(void)); // use of type name int (*p)(void); // declaration of pointer to function sizeof(int (*)(void)); // use of type name int (*const a[])(unsigned int, ...) = {0}; // array of pointers to functions sizeof(int (*const [])(unsigned int, ...)); // use of type name
```

Except the redundant parentheses around the identifier are meaningful in a type-name and represent "function with no parameter specification":
只是識別符號周圍多餘的圓括號在型別名中是有意義的，表示“沒有參數說明的函式”：

```c
int (n); // declares n of type int sizeof(int ()); // uses type "function returning int"
```

Type names are used in the following situations:
型別名用於以下情況：

- cast

- sizeof

- compound literal
|   | (since C99) |

- generic selection

- _Alignof(until C23)alignof(since C23)

- _Alignas(until C23)alignas(since C23)

- _Atomic (when used as a type specifier)
|   | (since C11) |

A type name may introduce a new type:
型別名可以引入一個新型別：

```c
void* p = (void*)(struct X { int i; } *)0; // type name "struct X {int i;}*" used in the cast expression // introduces the new type "struct X" struct X x = {1}; // struct X is now in scope
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.2.5 Types (p: TBD)
6.2.5 型別（p: TBD）
6.2.5 型別（p: TBD）

- 6.2.6 Representations of types (p: TBD)
6.2.6 型別的表示（p: TBD）
6.2.6 型別的表示（p: TBD）

- 6.2.7 Compatible type and composite type (p: TBD)
6.2.7 相容型別與複合型別（p: TBD）
6.2.7 相容型別與複合型別（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.2.5 Types (p: 31-33)
6.2.5 型別（p: 31-33）
6.2.5 型別（p: 31-33）

- 6.2.6 Representations of types (p: 31-35)
6.2.6 型別的表示（p: 31-35）
6.2.6 型別的表示（p: 31-35）

- 6.2.7 Compatible type and composite type (p: 35-36)
6.2.7 相容型別與複合型別（p: 35-36）
6.2.7 相容型別與複合型別（p: 35-36）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.2.5 Types (p: 39-43)
6.2.5 型別（p: 39-43）
6.2.5 型別（p: 39-43）

- 6.2.6 Representations of types (p: 44-46)
6.2.6 型別的表示（p: 44-46）
6.2.6 型別的表示（p: 44-46）

- 6.2.7 Compatible type and composite type (p: 47-48)
6.2.7 相容型別與複合型別（p: 47-48）
6.2.7 相容型別與複合型別（p: 47-48）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.2.5 Types (p: 33-37)
6.2.5 型別（p: 33-37）
6.2.5 型別（p: 33-37）

- 6.2.6 Representations of types (p: 37-40)
6.2.6 型別的表示（p: 37-40）
6.2.6 型別的表示（p: 37-40）

- 6.2.7 Compatible type and composite type (p: 40-41)
6.2.7 相容型別與複合型別（p: 40-41）
6.2.7 相容型別與複合型別（p: 40-41）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.2.5 Types

- 3.1.2.6 Compatible type and composite type
3.1.2.6 相容型別與複合型別
3.1.2.6 相容型別與複合型別

### See also

C++ documentation for Type

---
來源頁路徑：`en.cppreference.com/c/language/type.html`
