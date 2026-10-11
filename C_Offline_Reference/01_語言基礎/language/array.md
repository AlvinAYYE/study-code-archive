# Array declaration

> 來源：cppreference C 語言參考文件（離線轉換版）。

Array is a type consisting of a contiguously allocated nonempty sequence of objects with a particular *element type*. The number of those objects (the array size) never changes during the array lifetime.
陣列是一種型別，代表一段連續配置的物件序列；序列中的每個物件都具有相同的元素型別，而且至少有一個元素。陣列的元素數量在其生命期內不會改變。

### Syntax

In the declaration grammar of an array declaration, the *type-specifier* sequence designates the *element type* (which must be a complete object type), and the *declarator* has the form:
在陣列宣告的宣告語法中，型別說明符序列指定元素型別（必須是完整物件型別），並且宣告符具有以下形式：

|   |

| `**[**` `**static**`(optional) qualifiers ﻿(optional) expression ﻿(optional) `**]**` attr-spec-seq ﻿(optional)  |   | (1)  |   |   |

|   |

| `**[**` qualifiers ﻿(optional) `**static**`(optional) expression ﻿(optional) `**]**` attr-spec-seq ﻿(optional)  |   | (2)  |   |   |

|   |

| `**[**` qualifiers ﻿(optional) `*****` `**]**` attr-spec-seq ﻿(optional)  |   | (3)  |   |   |

|   |

1、2）一般陣列宣告子的寫法。

3）宣告大小未指定的 VLA（只能出現在函式原型作用域）。其中：

| expression  |   | -  |   | 除逗號運算子外的任意運算式；其值指定陣列的元素數量。  |

| qualifiers  |   | -  |   | `const`、`restrict`、`volatile` 的任意組合；只可用在函式參數中，並限定陣列參數轉換成的指標型別。  |

| attr-spec-seq  |   | -  |   | （C23）可選的屬性清單，套用到所宣告的陣列。  |

```c
float fa[11], *afp[17]; // fa is an array of 11 floats  // afp is an array of 17 pointers to floats
```

### Explanation

There are several variations of array types: arrays of known constant size, variable-length arrays, and arrays of unknown size.
陣列型別有幾種變體：已知常量大小的陣列、可變長度陣列和未知大小的陣列。

#### Arrays of constant known size

If expression in an array declarator is an integer constant expression with a value greater than zero and the element type is a type with a known constant size (that is, elements are not VLA)(since C99), then the declarator declares an array of constant known size:
若陣列宣告子中的運算式是值大於 0 的整數常數運算式，且元素型別具有已知的常數大小（也就是元素不是 VLA，C99 起），則此宣告子會宣告一個大小已知的陣列：

```c
int n[10]; // integer constants are constant expressions char o[sizeof(double)]; // sizeof is a constant expression enum { MAX_SZ=100 }; int n[MAX_SZ]; // enum constants are constant expressions
```

Arrays of constant known size can use array initializers to provide their initial values:
已知常量大小的陣列可以使用陣列初始化器來提供其初始值：

```c
int a[5] = {1,2,3}; // declares int[5] initialized to 1,2,3,0,0 char str[] = "abc"; // declares char[4] initialized to 'a','b','c','\0'
```

In function parameter lists, additional syntax elements are allowed within the array declarators: the keyword `**static**` and qualifiers, which may appear in any order before the size expression (they may also appear even when the size expression is omitted).
在函式參數中，陣列宣告子還能包含 `static` 關鍵字和型別限定詞。它們可按任意順序寫在大小運算式之前；即使省略大小運算式，也可以使用限定詞。
In each function call to a function where an array parameter uses the keyword `**static**` between `**[**` and `**]**`, the value of the actual parameter must be a valid pointer to the first element of an array with at least as many elements as specified by expression:
如果函式的陣列參數在方括號內使用 `static`，每次呼叫時，實際引數都必須是有效指標，指向至少有指定元素數量的陣列首元素：

```c
void fadd(double a[static 10], const double b[static 10]) {  for (int i = 0; i < 10; i++)  {  if (a[i] < 0.0) return;  a[i] += b[i];  } } // a call to fadd may perform compile-time bounds checking // and also permits optimizations such as prefetching 10 doubles int main(void) {  double a[10] = {0}, b[20] = {0};  fadd(a, b); // OK  double x[5] = {0};  fadd(x, b); // undefined behavior: array argument is too small }
```

If qualifiers are present, they qualify the pointer type to which the array parameter type is transformed:

```c
int f(const int a[20]) {  // in this function, a has type const int* (pointer to const int) } int g(const int a[const 20]) {  // in this function, a has type const int* const (const pointer to const int) }
```

This is commonly used with the restrict type qualifier:

```c
void fadd(double a[static restrict 10],  const double b[static restrict 10]) {  for (int i = 0; i < 10; i++) // loop can be unrolled and reordered  {  if (a[i] < 0.0)  break;  a[i] += b[i];  } }
```

#### Variable-length arrays

If expression is not an integer constant expression, the declarator is for an array of variable size.
如果大小運算式不是整數常數運算式，這就是可變長度陣列（VLA）的宣告。
Each time the flow of control passes over the declaration, expression is evaluated (and it must always evaluate to a value greater than zero), and the array is allocated (correspondingly, lifetime of a VLA ends when the declaration goes out of scope). The size of each VLA instance does not change during its lifetime, but on another pass over the same code, it may be allocated with a different size.
每次程式執行流程走到這個宣告時，都會重新計算大小運算式；結果必須大於 0，並依此配置陣列。離開宣告所在的作用域時，該 VLA 的生命期結束。同一個 VLA 在自己的生命期內大小固定，但程式再次走到這裡時，可以配置成不同大小。

Run this code

```c
#include <stdio.h> int main(void) {  int n = 1; label:;  int a[n]; // re-allocated 10 times, each with a different size  printf("The array has %zu elements\n", sizeof a / sizeof *a);  if (n++ < 10)  goto label; // leaving the scope of a VLA ends its lifetime }
```

如果大小寫成 `*`，這是大小未指定的 VLA 宣告，只能出現在函式原型作用域，而且宣告出的陣列型別是完整型別。事實上，函式原型作用域內所有 VLA 宣告都會按大小寫成 `*` 來處理。

```c
void foo(size_t x, int a[*]); void foo(size_t x, int a[x]) {  printf("%zu\n", sizeof a); // same as sizeof(int*) }
```

可變長度陣列，以及由它衍生的型別（例如指向 VLA 的指標），統稱為「可變修改型別」（variably-modified type，VM）。VM 型別的物件只能在區塊作用域或函式原型作用域中宣告。

```c
extern int n; int A[n]; // Error: file scope VLA extern int (*p2)[n]; // Error: file scope VM int B[100]; // OK: file-scope array of constant known size void fvla(int m, int C[m][m]); // OK: prototype-scope VLA
```

VLA 本身只能具有自動儲存期或配置儲存期；指向 VLA 的指標則也可以具有靜態儲存期。VM 型別不能具有連結。

```c
void fvla(int m, int C[m][m]) // OK: block scope/auto duration pointer to VLA {  typedef int VLA[m][m]; // OK: block scope VLA  int D[m]; // OK: block scope/auto duration VLA // static int E[m]; // Error: static duration VLA // extern int F[m]; // Error: VLA with linkage  int (*s)[m]; // OK: block scope/auto duration VM  s = malloc(m * sizeof(int)); // OK: s points to VLA in allocated storage // extern int (*r)[m]; // Error: VM with linkage  static int (*q)[m] = &B; // OK: block scope/static duration VM} }
```

可變修改型別不能作為結構或聯合的成員。

```c
struct tag {  int z[n]; // Error: VLA struct member  int (*y)[n]; // Error: VM struct member };
```
|   | (since C99) |

If the compiler defines the macro constant `__STDC_NO_VLA__` to integer constant `1`, then VLA and VM types are not supported.
如果編譯器將巨集常數 `__STDC_NO_VLA__` 定義為整數常數 `1`，表示它不支援 VLA 和 VM 型別。
|   | (since C11)
(until C23) |

If the compiler defines the macro constant `__STDC_NO_VLA__` to integer constant `1`, then VLA objects with automatic storage duration are not supported.
The support for VM types and VLAs with allocated storage durations is mandated.
從 C23 起，若編譯器將 `__STDC_NO_VLA__` 定義為 `1`，只表示不支援具有自動儲存期的 VLA 物件；VM 型別與具有配置儲存期的 VLA 仍必須支援。
|   | (since C23) |

#### Arrays of unknown size

If expression in an array declarator is omitted, it declares an array of unknown size. Except in function parameter lists (where such arrays are transformed to pointers) and when an initializer is available, such type is an incomplete type (note that VLA of unspecified size, declared with `*****` as the size, is a complete type)(since C99):
如果陣列宣告器中的表示式被省略，則宣告一個未知大小的陣列。除了在函式參數列表中（此類陣列會被轉換為指標）以及在有初始化器可用時，此型別別是不完整型別（注意，以 * 作為大小宣告的未指定大小的 VLA 是完整型別）（自 C99 起）：

```c
extern int x[]; // the type of x is "array of unknown bound of int" int a[] = {1,2,3}; // the type of a is "array of 3 int"
```

Within a struct definition, an array of unknown size may appear as the last member (as long as there is at least one other named member), in which case it is a special case known as *flexible array member*. See struct for details:

```c
struct s { int n; double d[]; }; // s.d is a flexible array member struct s *s1 = malloc(sizeof (struct s) + (sizeof (double) * 8)); // as if d was double d[8]
```

|   | (since C99) |

#### Qualifiers

If an array type is declared with a const, volatile, or restrict(since C99) qualifier (which is possible through the use of typedef), the array type is not qualified, but its element type is:
在 C23 之前，若透過 `typedef` 替陣列型別加上 `const`、`volatile` 或（C99 起）`restrict` 限定，實際上被限定的是元素型別，陣列型別本身不帶限定：
|   | (until C23) |

An array type and its element type are always considered to be identically qualified, except that an array type is never considered to be _Atomic-qualified.
從 C23 起，陣列型別與其元素型別一律視為帶有相同的限定詞；但陣列型別不會被視為帶有 `_Atomic` 限定。
|   | (since C23) |

```c
typedef int A[2][3]; const A a = {{4, 5, 6}, {7, 8, 9}}; // array of array of const int int* pi = a[0]; // Error: a[0] has type const int* void* unqual_ptr = a; // OK until C23; error since C23 // Notes: clang applies the rule in C++/C23 even in C89-C17 modes
```

_Atomic is not allowed to be applied to an array type, although an array of atomic type is allowed.
不能直接對陣列型別使用 `_Atomic`，但可以宣告元素為原子型別的陣列。

```c
typedef int A[2]; // _Atomic A a0 = {0}; // Error // _Atomic(A) a1 = {0}; // Error _Atomic int a2[2] = {0}; // OK _Atomic(int) a3[2] = {0}; // OK
```
|   | (since C11) |

#### Assignment

Objects of array type are not modifiable lvalues, and although their address may be taken, they cannot appear on the left hand side of an assignment operator. However, structs with array members are modifiable lvalues and can be assigned:
陣列型別的物件不是可修改左值，儘管可以取其位址，但它們不能出現在賦值運運算元的左側。然而，帶有陣列成員的結構體是可修改左值，可以被賦值：

```c
int a[3] = {1,2,3}, b[3] = {4,5,6}; int (*p)[3] = &a; // okay, address of a can be taken // a = b; // error, a is an array struct { int c[3]; } s1, s2 = {3,4,5}; s1 = s2; // okay: can assign structs holding array members
```

#### Array to pointer conversion

Any lvalue expression of array type, when used in any context other than
任何陣列型別的左值表示式，在用於以下情況之外的任何上下文時：

- as the operand of the address-of operator
作為取位址運運算元的運算元

- as the operand of sizeof
作為 sizeof 的運算元

- as the operand of typeof and typeof_unqual (since C23)
作為 typeof 和 typeof_unqual 的運算元（自 C23 起）

- as the string literal used for array initialization
作為用於陣列初始化的字串字面量

- as the operand of _Alignof(since C11)(until C23)alignof(since C23)
|   | (since C11) |

undergoes an implicit conversion to the pointer to its first element. The result is not an lvalue.
會進行到其首元素的指標的隱式轉換。結果不是左值。
If the array was declared register, the behavior of the program that attempts such conversion is undefined.
如果陣列被宣告為 register，則嘗試此類轉換的程式行為是未定義的。

```c
int a[3] = {1,2,3}; int* p = a; printf("%zu\n", sizeof a); // prints size of array printf("%zu\n", sizeof p); // prints size of a pointer
```

When an array type is used in a function parameter list, it is transformed to the corresponding pointer type: `int f(int a[2])` and `int f(int* a)` declare the same function. Since the function's actual parameter type is pointer type, a function call with an array argument performs array-to-pointer conversion; the size of the argument array is not available to the called function and must be passed explicitly:
陣列型別用於函式參數列表時，會轉換成相應的指標型別：int f ( int a [ 2 ]) 和 int f ( int * a ) 宣告的是同一個函式。由於實際參數型別是指標，呼叫函式時會進行陣列到指標的轉換；被呼叫的函式無法得知陣列大小，必須另外傳入：

Run this code

```c
#include <stdio.h> void f(int a[], int sz) // actually declares void f(int* a, int sz) {  for (int i = 0; i < sz; ++i)  printf("%d\n", a[i]); } void g(int (*a)[10]) // pointer to array parameter is not transformed {  for (int i = 0; i < 10; ++i)  printf("%d\n", (*a)[i]); } int main(void) {  int a[10] = {0};  f(a, 10); // converts a to int*, passes the pointer  g(&a); // passes a pointer to the array (no need to pass the size) }
```

#### Multidimensional arrays

When the element type of an array is another array, it is said that the array is multidimensional:
當陣列的元素型別是另一個陣列時，稱該陣列為多維陣列：

```c
// array of 2 arrays of 3 ints each int a[2][3] = {{1,2,3}, // can be viewed as a 2x3 matrix  {4,5,6}}; // with row-major layout
```

Note that when array-to-pointer conversion is applied, a multidimensional array is converted to a pointer to its first element, e.g., pointer to the first row:
注意，當應用陣列到指標轉換時，多維陣列會轉換為其首元素的指標，例如指向第一行的指標：

```c
int a[2][3]; // 2x3 matrix int (*p1)[3] = a; // pointer to the first 3-element row int b[3][3][3]; // 3x3x3 cube int (*p2)[3][3] = b; // pointer to the first 3x3 plane
```

Multidimensional arrays may be variably modified in every dimension if VLAs are supported(since C11):

```c
int n = 10; int a[n][2*n];
```
|   | (since C99) |

### Notes

Zero-length array declarations are not allowed, even though some compilers offer them as extensions (typically as a pre-C99 implementation of flexible array members).
不允許零長度陣列宣告，儘管某些編譯器將其作為擴充套件提供（通常作為柔性陣列成員的 C99 前實現）。
If the size expression of a VLA has side effects, they are guaranteed to be produced except when it is a part of a sizeof expression whose result doesn't depend on it:
如果 VLA 的大小表示式有副作用，則保證會產生這些副作用，除非它是 sizeof 表示式的一部分，且該 sizeof 表示式的結果不依賴於它：

```c
int n = 5, m = 5; size_t sz = sizeof(int (*[n++])[m++]); // n is incremented, m may or may not be incremented
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.6.2 Array declarators (p: TBD)
6.7.6.2 陣列宣告器 (p: TBD)
6.7.6.2 陣列宣告器 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.6.2 Array declarators (p: 94-96)
6.7.6.2 陣列宣告器 (p: 94-96)
6.7.6.2 陣列宣告器 (p: 94-96)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.6.2 Array declarators (p: 130-132)
6.7.6.2 陣列宣告器 (p: 130-132)
6.7.6.2 陣列宣告器 (p: 130-132)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.5.2 Array declarators (p: 116-118)
6.7.5.2 陣列宣告器 (p: 116-118)
6.7.5.2 陣列宣告器 (p: 116-118)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.4.2 Array declarators
3.5.4.2 陣列宣告器
3.5.4.2 陣列宣告器

### See also

C++ documentation for Array declaration

---
來源頁路徑：`en.cppreference.com/c/language/array.html`
