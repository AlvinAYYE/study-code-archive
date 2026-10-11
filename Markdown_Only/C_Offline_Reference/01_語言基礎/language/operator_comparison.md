# Comparison operators

> 來源：cppreference C 語言參考文件（離線轉換版）。

Comparison operators are binary operators that test a condition and return **1** if that condition is logically **true** and **0** if that condition is **false**.
比較運運算元是測試一個條件的二元運運算元，如果該條件邏輯上為真則傳回 1，為假則傳回 0。

| Operator  |   | Operator name  |   | Example  |   | Description  |

| `==`  |   | equal to  |   | `a == b`  |   | **a** is equal to **b**  |

| `!=`  |   | not equal to  |   | `a != b`  |   | **a** is not equal to **b**  |

| `<`  |   | less than  |   | `a < b`  |   | **a** is less than **b**  |

| `>`  |   | greater than  |   | `a > b`  |   | **a** is greater than **b**  |

| `<=`  |   | less than or equal to  |   | `a <= b`  |   | **a** is less than or equal to **b**  |

| `>=`  |   | greater than or equal to  |   | `a >= b`  |   | **a** is greater than or equal to **b**  |

### Relational operators
關係運運算元

The relational operator expressions have the form
關係運運算元表示式具有以下形式

|   |

| lhs `**<**` rhs  |   | (1)  |   |   |

|   |

| lhs `**>**` rhs  |   | (2)  |   |   |

|   |

| lhs `**<=**` rhs  |   | (3)  |   |   |

|   |

| lhs `**>=**` rhs  |   | (4)  |   |   |

|   |

1) less-than expression

2) greater-than expression

3) less or equal expression

4) greater or equal expression
where

| lhs, rhs  |   | -  |   | expressions that both have real type or both have pointer to object type  |

The type of any relational operator expression is `int`, and its value (which is not an lvalue) is `1` when the specified relationship holds true and `0` when the specified relationship does not hold.
任何關係運運算元表示式的型別都是 int，其值（不是左值）在指定關係成立時為 1，不成立時為 0。
If lhs and rhs are expressions of any real type, then
如果 lhs 和 rhs 是任意實數型別的表示式，則

- usual arithmetic conversions are performed
執行通常算術轉換

- the values of the operands after conversion are compared in the usual mathematical sense (except that positive and negative zeroes compare equal and any comparison involving a NaN value returns zero)
轉換後的運算元值按通常的數學意義進行比較（正零和負零比較相等，涉及 NaN 值的任何比較都傳回零）

Note that complex and imaginary numbers cannot be compared with these operators.
注意，複數和虛數不能用這些運運算元比較。
If lhs and rhs are expressions of pointer type, they must be both pointers to objects of compatible types, except that qualifications of the pointed-to objects are ignored.
如果 lhs 和 rhs 是指標型別的表示式，它們必須都是指向相容型別物件的指標，但被指向物件的限定符會被忽略。

- a pointer to an object that is not an element of an array is treated as if it were pointing to an element of an array with one element
指向並非陣列元素的物件的指標，被視為指向只有一個元素的陣列的元素

- if two pointers point to the same object, or both point one past the end of the same array, they compare equal
如果兩個指標指向同一物件，或者都指向同一陣列末尾之後一個位置，則它們比較相等

- if two pointers point to different elements of the same array, the one pointing at the element with the larger index compares greater.
如果兩個指標指向同一陣列的不同元素，則指向較大索引元素的指標比較大。

- if one pointer points to the element of an array and the other pointer points one past the end of the same array, the one-past-the-end pointer compares greater
如果一個指標指向陣列的元素，另一個指標指向同一陣列末尾之後一個位置，則指向末尾之後的指標比較大

- if the two pointers point to members of the same struct, the pointer to the member declared later in the struct definition compares greater than then pointer to the member declared earlier.
如果兩個指標指向同一 struct 的成員，則指向 struct 定義中後宣告成員的指標，大於指向先宣告成員的指標。

- pointers to members of the same union compare equal
指向同一 union 成員的指標比較相等

- all other pointer comparisons invoke undefined behavior
所有其他指標比較都會引發未定義行為

Run this code

```c
#include <assert.h> int main(void) {  assert(1 < 2);  assert(2+2 <= 4.0); // int converts to double, two 4.0's compare equal  struct { int x,y; } s;  assert(&s.x < &s.y); // struct members compare in order of declaration  double d = 0.0/0.0; // NaN  assert( !(d < d) );  assert( !(d > d) );  assert( !(d <= d) );  assert( !(d >= d) );  assert( !(d == d) );  float f = 0.1; // f = 0.100000001490116119384765625  double g = 0.1; // g = 0.1000000000000000055511151231257827021181583404541015625  assert(f > g); // different values }
```

### Equality operators
相等運運算元

The equality operator expressions have the form
相等運運算元表示式具有以下形式

|   |

| lhs `**==**` rhs  |   | (1)  |   |   |

|   |

| lhs `**!=**` rhs  |   | (2)  |   |   |

|   |

1) equal-to expression

2) not equal to expression
where

| lhs, rhs  |   | -  |   | expressions that
- both have any arithmetic types (including complex and imaginary)

- both have type nullptr_t

- one has type nullptr_t and the other is a null pointer constant
|   | (since C23) |

- both are pointers to objects or functions of compatible types, ignoring qualifiers of the pointed-to types

- one is a pointer to object and the other is a pointer to (possibly qualified) `void`

- one is a pointer to object or function and the other is a null pointer constant such as NULL or `nullptr`(since C23)

The type of any equality operator expression is `int`, and its value (which is not an lvalue) is `1` when the specified relationship holds true and `0` when the specified relationship does not hold.
任何相等運運算元表示式的型別都是 int，其值（不是左值）在指定關係成立時為 1，不成立時為 0。

- if both operands have arithmetic types, usual arithmetic conversions are performed and the resulting values are compared in the usual mathematical sense (except that positive and negative zeroes compare equal and any comparison involving a NaN value, including equality with itself, returns zero). In particular, values of complex type are equal if their real parts compare equal and their imaginary parts compare equal.
如果兩個運算元都具有算術型別，則執行通常算術轉換，並在通常的數學意義上比較結果值（正零和負零比較相等，涉及 NaN 值的任何比較（包括與自身相等）都傳回零）。特別地，複數型別的值在其虛部比較相等且實部比較相等時相等。

- two nullptr_t value or one nullptr_t value and a null pointer constant compare equal
|   | (since C23) |

- if one operand is a pointer and the other is a null pointer constant, the null pointer constant is first converted to the type of the pointer (which gives a null pointer value), and the two pointers are compared as described below
如果一個運算元是指標，另一個是空指標常量，則空指標常量首先被轉換為指標的型別（得到空指標值），然後按如下所述比較兩個指標

- if one operand is a pointer and the other is a pointer to void, the non-void pointer is converted to the pointer to void and the two pointers are compared as described below
如果一個運算元是指標，另一個是指向 void 的指標，則非 void 指標被轉換為指向 void 的指標，然後按如下所述比較兩個指標

- two pointers compare equal if any of the following is true:
在以下任一情況下，兩個指標比較相等：

- they are both null pointer values of their type
它們都是其型別的空指標值

- they are both pointers to the same object or function
它們都是指向同一物件或函式的指標

- one pointer is to a struct/union/array object and the other is to its first member/any member/first element
一個指標指向 struct/union/array 物件，另一個指向其第一個成員/任意成員/第一個元素

- they are both pointing one past the last element of the same array
它們都指向同一陣列最後一個元素之後一個位置

- one is one past the end of an array, and the other is at the start of a different array (of the same type) that follows the first in a larger array or in a struct with no padding
一個指向陣列末尾之後一個位置，另一個位於同一型別不同陣列的起始處，該陣列在更大陣列中或在沒有填充的 struct 中緊隨第一個陣列
它們都是其型別的空指標值；它們都是指向同一物件或函式的指標；一個指標指向 struct/union/array 物件，另一個指向其第一個成員/任意成員/第一個元素；它們都指向同一陣列最後一個元素之後一個位置；一個指向陣列末尾之後一個位置，另一個位於同一型別不同陣列的起始處，該陣列在更大陣列中或在沒有填充的 struct 中緊隨第一個陣列

(as with relational operators, pointers to objects that aren't elements of any array behave as pointers to elements of arrays of size 1)
（與關係運運算元一樣，指向並非任何陣列元素的物件的指標，表現為指向大小為 1 的陣列元素的指標）

#### Notes

Objects of struct type do not compare equal automatically, and comparing them with memcmp is not reliable because the padding bytes may have any values.
struct 型別的物件不會自動比較相等，用 memcmp 比較它們也不可靠，因為填充位元組可以是任何值。
Because pointer comparison works with pointers to void, the macro NULL may be defined as `(void*)0` in C, although that would be invalid in C++ where void pointers do not implicitly convert to typed pointers
由於指標比較適用於指向 void 的指標，宏 NULL 在 C 中可以定義為 ( void * ) 0，儘管在 C++ 中這是無效的，因為 void 指標不會隱式轉換為有型別的指標
Care must be taken when comparing floating-point values for equality, because the results of many operations cannot be represented exactly and must be rounded. In practice, floating-point numbers are usually compared allowing for the difference of one or more units of the last place.
比較浮點值是否相等時必須小心，因為許多操作的結果無法精確表示，必須舍入。實際上，浮點數通常比較時允許一個或更多最低位單位的差異。

Run this code

```c
#include <assert.h> int main(void) {  assert(2+2 == 4.0); // int converts to double, two 4.0's compare equal  int n[2][3] = {1,2,3,4,5,6};  int* p1 = &n[0][2]; // last element in the first row  int* p2 = &n[1][0]; // start of second row  assert(p1+1 == p2); // compare equal  double d = 0.0/0.0; // NaN  assert( d != d ); // NaN does not equal itself  float f = 0.1; // f = 0.100000001490116119384765625  double g = 0.1; // g = 0.1000000000000000055511151231257827021181583404541015625  assert(f != g); // different values }
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.8 Relational operators (p: 68-69)
6.5.8 關係運運算元 (p: 68-69)
6.5.8 關係運運算元 (p: 68-69)

- 6.5.9 Equality operators (p: 69-70)
6.5.9 相等運運算元 (p: 69-70)
6.5.9 相等運運算元 (p: 69-70)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.8 Relational operators (p: 95-96)
6.5.8 關係運運算元 (p: 95-96)
6.5.8 關係運運算元 (p: 95-96)

- 6.5.9 Equality operators (p: 96-97)
6.5.9 相等運運算元 (p: 96-97)
6.5.9 相等運運算元 (p: 96-97)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.8 Relational operators (p: 85-86)
6.5.8 關係運運算元 (p: 85-86)
6.5.8 關係運運算元 (p: 85-86)

- 6.5.9 Equality operators (p: 86-87)
6.5.9 相等運運算元 (p: 86-87)
6.5.9 相等運運算元 (p: 86-87)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.8 Relational operators
3.3.8 關係運運算元
3.3.8 關係運運算元

- 3.3.9 Equality operators
3.3.9 相等運運算元
3.3.9 相等運運算元

### See also

Operator precedence
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

C++ documentation for Comparison operators

---
來源頁路徑：`en.cppreference.com/c/language/operator_comparison.html`
