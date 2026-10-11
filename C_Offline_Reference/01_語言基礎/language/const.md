# const type qualifier

> 來源：cppreference C 語言參考文件（離線轉換版）。

Each individual type in the C type system has several *qualified* versions of that type, corresponding to one, two, or all three of the `const`, volatile, and, for pointers to object types, restrict qualifiers. This page describes the effects of the `const` qualifier.
C 型別系統中的每個單獨型別都有該型別的幾個限定版本，分別對應 const、volatile 以及（對於指向物件型別的指標）restrict 這一個、兩個或全部三個限定符。本頁描述 const 限定符的效果。
Objects declared with const-qualified types may be placed in read-only memory by the compiler, and if the address of a const object is never taken in a program, it may not be stored at all.
用 const 限定型別宣告的物件可以被編譯器放置在只讀記憶體中；如果程式中從未取 const 物件的位址，則該物件可能根本不被儲存。
Any attempt to modify an object whose type is const-qualified results in undefined behavior.
任何修改 const 限定型別物件的嘗試都會導致未定義行為。

```c
const int n = 1; // object of const-qualified type int* p = (int*)&n; *p = 2; // undefined behavior
```

`const` semantics apply to lvalue expressions only; whenever a const lvalue expression is used in context that does not require an lvalue, its `const` qualifier is lost (note that volatile qualifier, if present, isn't lost).
const 語意僅適用於左值表示式；每當 const 左值表示式在不需要左值的上下文中使用時，其 const 限定符會丟失（注意，volatile 限定符（如果存在）不會丟失）。
The lvalue expressions that designate objects of const-qualified type and the lvalue expressions that designate objects of struct or union type with at least one member of const-qualified type (including members of recursively contained aggregates or unions), are not *modifiable lvalues*. In particular, they are not assignable:
指向 const 限定型別物件的左值表示式，以及指向至少有一個 const 限定型別成員的 struct 或 union 型別物件的左值表示式（包括遞迴包含的聚合或 union 的成員），不是可修改的左值。特別是，它們不可賦值：

```c
const int n = 1; // object of const type n = 2; // error: the type of n is const-qualified int x = 2; // object of unqualified type const int* p = &x; *p = 3; // error: the type of the lvalue *p is const-qualified   struct {int a; const int b; } s1 = {.b=1}, s2 = {.b=2}; s1 = s2; // error: the type of s1 is unqualified, but it has a const member
```

A member of a const-qualified structure or union type acquires the qualification of the type it belongs to (both when accessed using the `**.**` operator or the `**->**` operator).
const 限定的 structure 或 union 型別的成員會獲得其所屬型別的限定（無論使用 . 運運算元還是 -> 運運算元訪問都是如此）。

```c
struct s { int i; const int ci; } s; // the type of s.i is int, the type of s.ci is const int const struct s cs; // the types of cs.i and cs.ci are both const int
```

If an array type is declared with the const type qualifier (through the use of typedef), the array type is not const-qualified, but its element type is.
|   | (until C23) |

An array type and its element type are always considered to be identically const-qualified.
|   | (since C23) |

```c
typedef int A[2][3]; const A a = {{4, 5, 6}, {7, 8, 9}}; // array of array of const int int* pi = a[0]; // Error: a[0] has type const int* void *unqual_ptr = a; // OK until C23; error since C23 // Notes: clang applies the rule in C++/C23 even in C89-C17 modes
```

If a function type is declared with the const type qualifier (through the use of typedef), the behavior is undefined.
如果函式型別用 const 型別限定符宣告（透過使用 typedef），則行為未定義。

In a function declaration, the keyword `const` may appear inside the square brackets that are used to declare an array type of a function parameter. It qualifies the pointer type to which the array type is transformed.
The following two declarations declare the same function:

```c
void f(double x[const], const double y[const]); void f(double * const x, const double * const y);
```
|   | (since C99) |

const-qualified compound literals do not necessarily designate distinct objects; they may share storage with other compound literals and with string literals that happen to have the same or overlapping representation.

```c
const int* p1 = (const int[]){1, 2, 3}; const int* p2 = (const int[]){2, 3, 4}; // the value of p2 may equal p1+1 _Bool b = "foobar" + 3 == (const char[]){"bar"}; // the value of b may be 1
```
|   | (since C99) |

A pointer to a non-const type can be implicitly converted to a pointer to const-qualified version of the same or compatible type. The reverse conversion requires a cast expression.
指向非 const 型別的指標可以隱式轉換為指向相同或相容型別的 const 限定版本的指標。反向轉換需要強制轉換表示式。

```c
int* p = 0; const int* cp = p; // OK: adds qualifiers (int to const int) p = cp; // Error: discards qualifiers (const int to int) p = (int*)cp; // OK: cast
```

Note that pointer to pointer to `T` is not convertible to pointer to pointer to `const T`; for two types to be compatible, their qualifications must be identical.
注意，指向 T 的指標的指標不能轉換為指向 const T 的指標的指標；兩個型別要相容，它們的限定必須相同。

```c
char *p = 0; const char **cpp = &p; // Error: char* and const char* are not compatible types char * const *pcp = &p; // OK, adds qualifiers (char* to char*const)
```

### Keywords

const

### Notes

C adopted the *const* qualifier from C++, but unlike in C++, expressions of const-qualified type in C are not constant expressions; they may not be used as case labels or to initialize static and thread storage duration objects, enumerators, or bit-field sizes. When they are used as array sizes, the resulting arrays are VLAs.
C 從 C++ 借鑑了 const 限定符，但與 C++ 不同的是，C 中 const 限定型別的表示式不是常量表示式；它們不能用作 case 標籤，也不能用於初始化靜態和執行緒儲存期物件、列舉器或位域大小。當它們用作陣列大小時，得到的陣列是 VLA。

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.3 Type qualifiers (p: 87-90)
6.7.3 型別限定符（p: 87-90）
6.7.3 型別限定符（p: 87-90）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.3 Type qualifiers (p: 121-123)
6.7.3 型別限定符（p: 121-123）
6.7.3 型別限定符（p: 121-123）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.3 Type qualifiers (p: 108-110)
6.7.3 型別限定符（p: 108-110）
6.7.3 型別限定符（p: 108-110）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 6.5.3 Type qualifiers
6.5.3 型別限定符
6.5.3 型別限定符

### See also

C++ documentation for cv (`const` and `volatile`) type qualifiers

---
來源頁路徑：`en.cppreference.com/c/language/const.html`
