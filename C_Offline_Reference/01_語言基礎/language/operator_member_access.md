# Member access operators

> 來源：cppreference C 語言參考文件（離線轉換版）。

Member access operators allow access to the members of their operands.
成員訪問運運算元允許訪問其運算元的成員。

| Operator  |   | Operator name  |   | Example  |   | Description  |

| `[]`  |   | array subscript  |   | `a[b]`  |   | access the **b**th element of array **a**  |

| `*`  |   | pointer dereference  |   | `*a`  |   | dereference the pointer **a** to access the object or function it refers to  |

| `&`  |   | address of  |   | `&a`  |   | create a pointer that refers to the object or function **a**  |

| `.`  |   | member access  |   | `a.b`  |   | access member **b** of struct or union **a**  |

| `->`  |   | member access through pointer  |   | `a->b`  |   | access member **b** of struct or union pointed to by **a**  |

### Subscript

The array subscript expression has the form
陣列下標表示式具有以下形式

|   |

| pointer-expression `**[**` integer-expression `**]**`  |   | (1)  |   |   |

|   |

| integer-expression `**[**` pointer-expression `**]**`  |   | (2)  |   |   |

|   |

where

| pointer-expression  |   | -  |   | an expression of type pointer to complete object  |

| integer-expression  |   | -  |   | an expression of integer type  |

The subscript operator expression is an lvalue expression whose type is the type of the object pointed to by pointer-expression.
下標運運算元表示式是一個左值表示式，其型別是 pointer-expression 指向的物件的型別。
By definition, the subscript operator `E1[E2]` is exactly identical to `*((E1)+(E2))`. If pointer-expression is an array expression, it undergoes lvalue-to-rvalue conversion and becomes a pointer to the first element of the array.
根據定義，下標運運算元 E1 [ E2 ] 與 * (( E1 ) + ( E2 )) 完全相同。如果 pointer-expression 是陣列表示式，則它經過左值到右值轉換，併成為指向陣列第一個元素的指標。
Due to the definition of the addition between a pointer and an integer, the result is the element of the array with the index equal to the result of integer-expression (or, if pointer-expression was pointing at ith element of some array, the index of the result is i plus the result of integer-expression)
由於指標與整數之間加法的定義，結果是陣列中索引等於 integer-expression 結果的元素（或者，如果 pointer-expression 指向某個陣列的第 i 個元素，則結果的索引為 i 加上 integer-expression 的結果）。
Note: see array for the details on multidimensional arrays.
注意：有關多維陣列的詳細資訊，請參閱 array。

Run this code

```c
#include <stdio.h> int main(void) {  int a[3] = {1,2,3};  printf("%d %d\n", a[2], // n == 3  2[a]); // same, n == 3  a[2] = 7; // subscripts are lvalues  int n[2][3] = {{1,2,3},{4,5,6}};  int (*p)[3] = &n[1]; // elements of n are arrays  printf("%d %d %d\n", (*p)[0], p[0][1], p[0][2]); // access n[1][] via p  int x = n[1][2]; // applying [] again to the array n[1]  printf("%d\n", x);  printf("%c %c\n", "abc"[2], 2["abc"]); // string literals are arrays too }
```

Output:

```c
3 3 4 5 6 6 c c
```

### Dereference

The *dereference* or *indirection* expression has the form
解引用或間接表示式具有以下形式

|   |

| `*****` pointer-expression  |   |   |   |   |

|   |

where

| pointer-expression  |   | -  |   | an expression of any pointer type  |

If pointer-expression is a pointer to function, the result of the dereference operator is a function designator for that function.
如果 pointer-expression 是指向函式的指標，則解引用運運算元的結果是該函式的函式指示符。
If pointer-expression is a pointer to object, the result is an lvalue expression that designates the pointed-to object.
如果 pointer-expression 是指向物件的指標，則結果是指定被指向物件的左值表示式。
Dereferencing a null pointer, a pointer to an object outside of its lifetime (a dangling pointer), a misaligned pointer, or a pointer with indeterminate value is undefined behavior, except when the dereference operator is nullified by applying the address-of operator to its result, as in `&*E`.
解引用空指標、指向其生存期之外物件的指標（懸垂指標）、未對齊指標或具有不確定值的指標是未定義行為，除非透過對解引用運運算元的結果應用取位址運運算元使解引用失效，如 &* E 。

Run this code

```c
#include <stdio.h> int main(void) {  int n = 1;  int* p = &n;  printf("*p = %d\n", *p); // the value of *p is what's stored in n  *p = 7; // *p is lvalue  printf("*p = %d\n", *p); }
```

Output:

```c
*p = 1 *p = 7
```

### Address of

The address-of expression has the form
取位址表示式具有以下形式

|   |

| `**&**` function  |   | (1)  |   |   |

|   |

| `**&**` lvalue-expression  |   | (2)  |   |   |

|   |

| `**&**` `*****` expression  |   | (3)  |   |   |

|   |

| `**&**` expression `**[**` expression `**]**`  |   | (4)  |   |   |

|   |

1) address of a function

2) address of an object

3) special case: `&` and `*` cancel each other, neither one is evaluated

4) special case: `&` and the `*` that is implied in `[]` cancel each other, only the addition implied in `[]` is evaluated.

where

| lvalue-expression  |   | -  |   | an lvalue expression of any type that is not a bit-field and does not have register storage class  |

The address-of operator produces the non-lvalue address of its operand, suitable for initializing a pointer to the type of the operand. If the operand is a function designator (1), the result is a pointer to function. If the operand is an object (2), the result is a pointer to object.
取位址運運算元產生其運算元的非左值位址，適用於初始化指向運算元型別的指標。如果運算元是函式指示符 (1)，結果是指向函式的指標。如果運算元是物件 (2)，結果是指向物件的指標。
If the operand is the dereference operator, no action is taken (so it's okay to apply &* to a null pointer), except that the result is not an lvalue.
如果運算元是解引用運運算元，則不採取任何操作（因此可以對空指標應用 &*），除了結果不是左值。
If the operand is an array index expression, no action is taken other than the array-to-pointer conversion and the addition, so &a[N] is valid for an array of size N (obtaining a pointer one past the end is okay, dereferencing it is not, but dereference cancels out in this expression).
如果運算元是陣列索引表示式，則除了陣列到指標轉換和加法之外不採取任何操作，因此 &a[N] 對於大小為 N 的陣列是有效的（獲取指向末尾後一個位置的指標是可以的，解引用它則不行，但解引用在此表示式中相互抵消）。

Run this code

```c
int f(char c) { return c;} int main(void) {  int n = 1;  int *p = &n; // address of object n  int (*fp)(char) = &f; // address of function f  int a[3] = {1,2,3};  int *beg=a, *end=&a[3]; // same as end = a+3 }
```

### Member access

The member access expression has the form
成員訪問表示式具有以下形式

|   |

| expression `**.**` member-name  |   |   |   |   |

|   |

where

| expression  |   | -  |   | an expression of struct or union type  |

| member-name  |   | -  |   | an identifier that names a member of the struct or union designated by expression  |

The member access expression designates the named member of the struct or union designated by its left operand. It has the same value category as its left operand.
成員訪問表示式指定其左運算元指定的 struct 或 union 的命名成員。它與其左運算元具有相同的值類別。
If the left operand is const or volatile qualified, the result is also qualified. If the left operand is atomic, the behavior is undefined.
如果左運算元具有 const 或 volatile 限定，則結果也具有限定。如果左運算元是 atomic ，則行為未定義。
Note: besides identifiers that name objects of struct or union type, the following expressions may have struct or union types: assignment, function call, comma operator, conditional operator, and compound literal.
注意：除了命名 struct 或 union 型別物件的識別符號外，以下表示式可能具有 struct 或 union 型別：賦值、函式呼叫、逗號運運算元、條件運運算元和複合字面量。

Run this code

```c
#include <stdio.h> struct s {int x;}; struct s f(void) { return (struct s){1}; } int main(void) {  struct s s;  s.x = 1; // ok, changes the member of s  int n = f().x; // f() is an expression of type struct s // f().x = 1; // Error: this member access expression is not an lvalue  const struct s sc; // sc.x = 3; // Error: sc.x is const, can't be assigned  union { int x; double d; } u = {1};  u.d = 0.1; // changes the active member of the union }
```

### Member access through pointer
透過指標訪問成員

The member access expression has the form
成員訪問表示式具有以下形式

|   |

| expression `**->**` member-name  |   |   |   |   |

|   |

where

| expression  |   | -  |   | an expression of type pointer to struct or union  |

| member-name  |   | -  |   | an identifier that names a member of the struct or union pointed by expression  |

The member access through pointer expression designates the named member of the struct or union type pointed to by its left operand. Its value category is always lvalue
透過指標訪問成員表示式指定其左運算元指向的 struct 或 union 型別的命名成員。其值類別始終是左值
If the type pointed to by the left operand is const or volatile qualified, the result is also qualified. If the type pointed to by the left operand is atomic, the behavior is undefined.
如果左運算元指向的型別具有 const 或 volatile 限定，則結果也具有限定。如果左運算元指向的型別是 atomic ，則行為未定義。

Run this code

```c
#include <stdio.h> struct s {int x;}; int main(void) {  struct s s={1}, *p = &s;  p->x = 7; // changes the value of s.x through the pointer  printf("%d\n", p->x); // prints 7 }
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 076  |   | C89  |   | unnessary indirection could not be cancelled by `&`  |   | made cancellable  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.2.1 Array subscripting (p: 57-58)
6.5.2.1 陣列下標（第 57-58 頁）
6.5.2.1 陣列下標（第 57-58 頁）

- 6.5.2.3 Structure and union members (p: 58-59)
6.5.2.3 結構和聯合成員（第 58-59 頁）
6.5.2.3 結構和聯合成員（第 58-59 頁）

- 6.5.3.2 Address and indirection operators (p: 59-61)
6.5.3.2 位址與間接運運算元（第 59-61 頁）
6.5.3.2 位址與間接運運算元（第 59-61 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.2.1 Array subscripting (p: 80)
6.5.2.1 陣列下標（第 80 頁）
6.5.2.1 陣列下標（第 80 頁）

- 6.5.2.3 Structure and union members (p: 82-84)
6.5.2.3 結構和聯合成員（第 82-84 頁）
6.5.2.3 結構和聯合成員（第 82-84 頁）

- 6.5.3.2 Address and indirection operators (p: 88-89)
6.5.3.2 位址與間接運運算元（第 88-89 頁）
6.5.3.2 位址與間接運運算元（第 88-89 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.2.1 Array subscripting (p: 70)
6.5.2.1 陣列下標（第 70 頁）
6.5.2.1 陣列下標（第 70 頁）

- 6.5.2.3 Structure and union members (p: 72-74)
6.5.2.3 結構和聯合成員 (p: 72-74)
6.5.2.3 結構和聯合成員 (p: 72-74)

- 6.5.3.2 Address and indirection operators (p: 78-79)
6.5.3.2 取位址和間接運運算元 (p: 78-79)
6.5.3.2 取位址和間接運運算元 (p: 78-79)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.2.1 Array subscripting
3.3.2.1 陣列下標
3.3.2.1 陣列下標

- 3.3.2.3 Structure and union members
3.3.2.3 結構和聯合成員
3.3.2.3 結構和聯合成員

- 3.3.3.2 Address and indirection operators
3.3.3.2 取位址和間接運運算元
3.3.3.2 取位址和間接運運算元

### See also

- Operator precedence
運運算元優先順序

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

C++ documentation for Member access operators

---
來源頁路徑：`en.cppreference.com/c/language/operator_member_access.html`
