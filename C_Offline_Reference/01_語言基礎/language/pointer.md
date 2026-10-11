# Pointer declaration

> 來源：cppreference C 語言參考文件（離線轉換版）。

Pointer is a type of an object that refers to a function or an object of another type, possibly adding qualifiers. Pointer may also refer to nothing, which is indicated by the special null pointer value.
指標是一種物件型別，用來指向函式或其他型別的物件，也可以帶有限定詞。指標也可以不指向任何內容，這種情況以特殊的空指標值表示。

### Syntax

In the declaration grammar of a pointer declaration, the type-specifier sequence designates the pointed-to type (which may be function or object type and may be incomplete), and the declarator has the form:
在指標宣告的宣告語法中，型別說明符序列指定被指向的型別（可以是函式型別或物件型別，可以是不完整型別），宣告符具有以下形式：

|   |

| `*****` attr-spec-seq ﻿(optional) qualifiers ﻿(optional) declarator  |   |   |   |   |

|   |

where declarator may be the identifier that names the pointer being declared, including another pointer declarator (which would indicate a pointer to a pointer):
其中 declarator 可以是命名所宣告指標的識別符號，包括另一個指標宣告符（表示指向指標的指標）：

```c
float *p, **pp; // p is a pointer to float  // pp is a pointer to a pointer to float int (*fp)(int); // fp is a pointer to function with type int(int)
```

The qualifiers that appear between `*****` and the identifier (or other nested declarator) qualify the type of the pointer that is being declared:
出現在 * 和識別符號（或其他巢狀宣告符）之間的限定符限定所宣告指標的型別：

```c
int n; const int * pc = &n; // pc is a non-const pointer to a const int // *pc = 2; // Error: n cannot be changed through pc without a cast pc = NULL; // OK: pc itself can be changed int * const cp = &n; // cp is a const pointer to a non-const int *cp = 2; // OK to change n through cp // cp = NULL; // Error: cp itself cannot be changed int * const * pcp = &cp; // non-const pointer to const pointer to non-const int
```

The attr-spec-seq(C23) is an optional list of attributes, applied to the declared pointer.
attr-spec-seq（C23）是應用於所宣告指標的可選屬性列表。

### Explanation

Pointers are used for indirection, which is a ubiquitous programming technique; they can be used to implement pass-by-reference semantics, to access objects with dynamic storage duration, to implement "optional" types (using the null pointer value), aggregation relationship between structs, callbacks (using pointers to functions), generic interfaces (using pointers to void), and much more.
指標可用來間接存取資料，是程式設計中常見的技巧。它們可用於實作傳參考語意、存取動態儲存期的物件、以空指標表示選用值、建立 struct 間的聚合關係、使用函式指標作為回呼，以及透過 void 指標建立泛型介面等。

#### Pointers to objects

A pointer to object can be initialized with the result of the address-of operator applied to an expression of object type (which may be incomplete):
指向物件的指標可以用對物件型別表示式（可以是不完整型別）應用取位址運運算元的結果來初始化：

```c
int n; int *np = &n; // pointer to int int *const *npp = &np; // non-const pointer to const pointer to non-const int int a[2]; int (*ap)[2] = &a; // pointer to array of int struct S { int n; } s = {1} int* sp = &s.n; // pointer to the int that is a member of s
```

Pointers may appear as operands to the indirection operator (unary `*****`), which returns the lvalue identifying the pointed-to object:
指標可以作為間接訪問運運算元（一元 *）的運算元，該運運算元傳回標識被指向物件的左值：

```c
int n; int* p = &n; // pointer p is pointing to n *p = 7; // stores 7 in n printf("%d\n", *p); // lvalue-to-rvalue conversion reads the value from n
```

Pointers to objects of struct and union type may also appear as the left-hand operands of the member access through pointer operator `**->**`.
指向 struct 和 union 型別物件的指標也可以作為透過指標訪問成員運運算元 -> 的左運算元。
Because of the array-to-pointer implicit conversion, pointer to the first element of an array can be initialized with an expression of array type:
由於陣列到指標的隱式轉換，指向陣列第一個元素的指標可以用陣列型別的表示式初始化：

```c
int a[2]; int *p = a; // pointer to a[0] int b[3][3]; int (*row)[3] = b; // pointer to b[0]
```

Certain addition, subtraction, compound assignment, increment, and decrement operators are defined for pointers to elements of arrays.
某些加法、減法、複合賦值、自增和自減運運算元對指向陣列元素的指標有定義。
Comparison operators are defined for pointers to objects in some situations: two pointers that represent the same address compare equal, two null pointer values compare equal, pointers to elements of the same array compare the same as the array indices of those elements, and pointers to struct members compare in order of declaration of those members.
在某些情況下，指向物件的指標定義了比較運運算元：表示同一位址的兩個指標比較相等，兩個空指標值比較相等，指向同一陣列元素的指標的比較與這些元素的陣列索引相同，指向 struct 成員的指標按這些成員的宣告順序比較。
Many implementations also provide strict total ordering of pointers of random origin, e.g. if they are implemented as addresses within continuous ("flat") virtual address space.
許多實現還為隨機來源的指標提供嚴格的全序，例如當它們被實現為連續（"flat"）虛擬位址空間內的位址時。

#### Pointers to functions

A pointer to function can be initialized with an address of a function. Because of the function-to-pointer conversion, the address-of operator is optional:
指向函式的指標可以用函式的位址初始化。由於函式到指標的轉換，取位址運運算元是可選的：

```c
void f(int); void (*pf1)(int) = &f; void (*pf2)(int) = f; // same as &f
```

Unlike functions, pointers to functions are objects and thus can be stored in arrays, copied, assigned, passed to other functions as arguments, etc.
與函式不同，指向函式的指標是物件，因此可以儲存在陣列中、複製、賦值、作為參數傳遞給其他函式等。
A pointer to function can be used on the left-hand side of the function call operator; this invokes the pointed-to function:
指向函式的指標可以用在函式呼叫運運算元的左側；這將呼叫所指向的函式：

```c
#include <stdio.h> int f(int n) {  printf("%d\n", n);  return n * n; } int main(void) {  int (*p)(int) = f;  int x = p(7); }
```

Dereferencing a function pointer yields the function designator for the pointed-to function:
解引用函式指標得到所指向函式的函式指示符：

```c
int f(); int (*p)() = f; // pointer p is pointing to f (*p)(); // function f invoked through the function designator p(); // function f invoked directly through the pointer
```

Equality comparison operators are defined for pointers to functions (they compare equal if pointing to the same function).
相等比較運運算元對指向函式的指標有定義（如果指向同一函式則比較相等）。
Because compatibility of function types ignores top-level qualifiers of the function parameters, pointers to functions whose parameters only differ in their top-level qualifiers are interchangeable:
由於函式型別的相容性忽略函式參數的頂層限定符，參數僅在頂層限定符上不同的指向函式的指標是可互換的：

```c
int f(int), fc(const int); int (*pc)(const int) = f; // OK int (*p)(int) = fc; // OK pc = p; // OK
```

#### Pointers to void

Pointer to object of any type can be implicitly converted to pointer to `void` (optionally const or volatile-qualified), and vice versa:
指向任意型別物件的指標可以隱式轉換為指向 void 的指標（可選擇 const 或 volatile 限定），反之亦然：

```c
int n=1, *p=&n; void* pv = p; // int* to void* int* p2 = pv; // void* to int* printf("%d\n", *p2); // prints 1
```

Pointers to void are used to pass objects of unknown type, which is common in generic interfaces: malloc returns `void*`, qsort expects a user-provided callback that accepts two `const void*` arguments. pthread_create expects a user-provided callback that accepts and returns `void*`. In all cases, it is the caller's responsibility to convert the pointer to the correct type before use.
void 指標可用來傳遞型別未知的物件，常見於泛型介面。例如 malloc 回傳 void *；qsort 要求使用者提供一個接收兩個 const void * 參數的回呼函式；pthread_create 則要求回呼函式接收並回傳 void *。使用前都必須由呼叫端將指標轉成正確型別。

### Null pointers

Pointers of every type have a special value known as *null pointer value* of that type. A pointer whose value is null does not point to an object or a function (dereferencing a null pointer is undefined behavior), and compares equal to all pointers of the same type whose value is also *null*.
每種指標型別都有一個特殊值，稱為該型別的空指標值。空指標不指向任何物件或函式；解參考空指標會造成未定義行為。同型別的空指標彼此比較相等。
To initialize a pointer to null or to assign the null value to an existing pointer, a null pointer constant (NULL, or any other integer constant with the value zero) may be used. static initialization also initializes pointers to their null values.
要將指標初始化為空或將空值賦給現有指標，可以使用空指標常量（NULL，或任何其他值為零的整數常量）。靜態初始化也將指標初始化為其空值。
Null pointers can indicate the absence of an object or can be used to indicate other types of error conditions. In general, a function that receives a pointer argument almost always needs to check if the value is null and handle that case differently (for example, free does nothing when a null pointer is passed).
空指標可表示物件不存在，也可表示其他錯誤狀況。接收指標參數的函式通常應檢查指標是否為空，並妥善處理；例如 free 收到空指標時不會做任何事。

### Notes

Although any pointer to object can be cast to pointer to object of a different type, dereferencing a pointer to the type different from the declared type of the object is almost always undefined behavior. See strict aliasing for details.
雖然任何指向物件的指標都可以轉換為指向不同型別物件的指標，但解引用與物件宣告型別不同的指標幾乎總是未定義行為。詳見 strict aliasing。

It is possible to indicate to a function that accesses objects through pointers that those pointers do not alias. See restrict for details.
|   | (since C99) |

lvalue expressions of array type, when used in most contexts, undergo an implicit conversion to the pointer to the first element of the array. See array for details.
陣列型別的左值表示式在大多數上下文中使用時，會經歷到指向陣列第一個元素的指標的隱式轉換。詳見 array。

```c
char *str = "abc"; // "abc" is a char[4] array, str is a pointer to 'a'
```

Pointers to char are often used to represent strings. To represent a valid byte string, a pointer must be pointing at a char that is an element of an array of char, and there must be a char with the value zero at some index greater or equal to the index of the element referenced by the pointer.
char 指標常用來表示字串。若要表示有效的位元組字串，指標必須指向 char 陣列中的 char 元素，而且從該元素開始往後，必須有一個值為零的 char。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.6.1 Pointer declarators (p: TBD)
6.7.6.1 指標宣告符 (p: TBD)
6.7.6.1 指標宣告符 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.6.1 Pointer declarators (p: 93-94)
6.7.6.1 指標宣告符 (p: 93-94)
6.7.6.1 指標宣告符 (p: 93-94)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.6.1 Pointer declarators (p: 130)
6.7.6.1 指標宣告符 (p: 130)
6.7.6.1 指標宣告符 (p: 130)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.5.1 Pointer declarators (p: 115-116)
6.7.5.1 指標宣告符 (p: 115-116)
6.7.5.1 指標宣告符 (p: 115-116)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.4.1 Pointer declarators
3.5.4.1 指標宣告符
3.5.4.1 指標宣告符

### See also

C++ documentation for Pointer declaration

---
來源頁路徑：`en.cppreference.com/c/language/pointer.html`
