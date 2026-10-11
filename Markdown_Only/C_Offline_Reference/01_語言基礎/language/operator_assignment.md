# Assignment operators

> 來源：cppreference C 語言參考文件（離線轉換版）。

Assignment and compound assignment operators are binary operators that modify the variable to their left using the value to their right.
賦值和複合賦值運運算元是二元運運算元，它們用右側的值來修改左側的變數。

| Operator  |   | Operator name  |   | Example  |   | Description  |   | Equivalent of  |

| `=`  |   | basic assignment  |   | `a = b`  |   | **a** becomes equal to **b**  |   | N/A  |

| `+=`  |   | addition assignment  |   | `a += b`  |   | **a** becomes equal to the addition of **a** and **b**  |   | `a = a + b`  |

| `-=`  |   | subtraction assignment  |   | `a -= b`  |   | **a** becomes equal to the subtraction of **b** from **a**  |   | `a = a - b`  |

| `*=`  |   | multiplication assignment  |   | `a *= b`  |   | **a** becomes equal to the product of **a** and **b**  |   | `a = a * b`  |

| `/=`  |   | division assignment  |   | `a /= b`  |   | **a** becomes equal to the division of **a** by **b**  |   | `a = a / b`  |

| `%=`  |   | modulo assignment  |   | `a %= b`  |   | **a** becomes equal to the remainder of **a** divided by **b**  |   | `a = a % b`  |

| `&=`  |   | bitwise AND assignment  |   | `a &= b`  |   | **a** becomes equal to the bitwise AND of **a** and **b**  |   | `a = a & b`  |

| `|=`  |   | bitwise OR assignment  |   | `a |= b`  |   | **a** becomes equal to the bitwise OR of **a** and **b**  |   | `a = a | b`  |

| `^=`  |   | bitwise XOR assignment  |   | `a ^= b`  |   | **a** becomes equal to the bitwise XOR of **a** and **b**  |   | `a = a ^ b`  |

| `<<=`  |   | bitwise left shift assignment  |   | `a <<= b`  |   | **a** becomes equal to **a** left shifted by **b**  |   | `a = a << b`  |

| `>>=`  |   | bitwise right shift assignment  |   | `a >>= b`  |   | **a** becomes equal to **a** right shifted by **b**  |   | `a = a >> b`  |

### Simple assignment
簡單賦值

The simple assignment operator expressions have the form
簡單賦值運運算元表示式具有如下形式

|   |

| lhs `**=**` rhs  |   |   |   |   |

|   |

where

| lhs  |   | -  |   | modifiable lvalue expression of any complete object type  |

| rhs  |   | -  |   | expression of any type implicitly convertible to lhs or compatible with lhs  |

Assignment performs implicit conversion from the value of rhs to the type of lhs and then replaces the value in the object designated by lhs with the converted value of rhs.
賦值先對 rhs 的值到 lhs 的型別執行隱式轉換，然後用轉換後的 rhs 值替換 lhs 所指定物件中的值。
Assignment also returns the same value as what was stored in `lhs` (so that expressions such as `a = b = c` are possible). The value category of the assignment operator is non-lvalue (so that expressions such as `(a=b)=c` are invalid).
賦值還傳回與儲存在 lhs 中的值相同的值（從而使 a = b = c 這樣的表示式成為可能）。賦值運運算元的值類別是非左值（從而使 ( a = b ) = c 這樣的表示式無效）。
rhs and lhs must satisfy one of the following:
rhs 和 lhs 必須滿足以下條件之一：

- both lhs and rhs have compatible struct or union type, or..
lhs 和 rhs 都具有相容的結構體或聯合體型別，或者……

- rhs must be implicitly convertible to lhs, which implies
rhs 必須能隱式轉換為 lhs，這意味著

- both lhs and rhs have arithmetic types, in which case lhs may be volatile-qualified or atomic(since C11)
lhs 和 rhs 都具有算術型別，在這種情況下 lhs 可以是 volatile 限定的或原子的（自 C11 起）

- both lhs and rhs have pointer to compatible (ignoring qualifiers) types, or one of the pointers is a pointer to void, and the conversion would not add qualifiers to the pointed-to type. lhs may be volatile or restrict(since C99)-qualified or atomic(since C11).
lhs 和 rhs 都是指向相容型別（忽略限定符）的指標，或者其中一個指標是指向 void 的指標，並且該轉換不會為被指向的型別新增限定符。lhs 可以是 volatile 或 restrict（自 C99 起）限定的，或是原子的（自 C11 起）。

- lhs is a (possibly qualified or atomic(since C11)) pointer and rhs is a null pointer constant such as NULL or a nullptr_t value(since C23)
lhs 是（可能帶限定或原子（自 C11 起）的）指標，而 rhs 是空指標常量，例如 NULL 或 nullptr_t 值（自 C23 起）
lhs 和 rhs 都具有算術型別，在這種情況下 lhs 可以是 volatile 限定的或原子的（自 C11 起）；lhs 和 rhs 都是指向相容型別（忽略限定符）的指標，或者其中一個指標是指向 void 的指標，並且該轉換不會為被指向的型別新增限定符，此時 lhs 可以是 volatile 或 restrict（自 C99 起）限定的，或是原子的（自 C11 起）；lhs 是（可能帶限定或原子（自 C11 起）的）指標，而 rhs 是空指標常量，例如 NULL 或 nullptr_t 值（自 C23 起）

- lhs has type (possibly qualified or atomic(since C11)) `_Bool` and rhs is a pointer or a nullptr_t value(since C23)
|   | (since C99) |

- lhs has type (possibly qualified or atomic) nullptr_t and rhs has type nullptr_t
|   | (since C23) |

#### Notes

If rhs and lhs overlap in memory (e.g. they are members of the same union), the behavior is undefined unless the overlap is exact and the types are compatible.
如果 rhs 和 lhs 在記憶體中重疊（例如它們是同一聯合體的成員），則行為是未定義行為，除非這種重疊完全一致且型別相容。
Although arrays are not assignable, an array wrapped in a struct is assignable to another object of the same (or compatible) struct type.
雖然陣列不可賦值，但包裹在結構體中的陣列可以賦值給相同（或相容）結構體型別的另一個物件。
The side effect of updating lhs is sequenced after the value computations, but not the side effects of lhs and rhs themselves and the evaluations of the operands are, as usual, unsequenced relative to each other (so the expressions such as `i=++i`; are undefined)
更新 lhs 的副作用序列在值計算之後，而 lhs 和 rhs 本身的副作用則不是這樣；並且各運算元的求值照常彼此之間沒有序列關係（因此 i =++ i ; 這樣的表示式是未定義的）
Assignment strips extra range and precision from floating-point expressions (see FLT_EVAL_METHOD).
賦值會去除浮點表示式中多餘的範圍和精度（見 FLT_EVAL_METHOD）。
In C++, assignment operators are lvalue expressions, not so in C.
在 C++ 中，賦值運運算元是左值表示式，而在 C 中則不是。

Run this code

```c
#include <stdio.h> int main(void) {  // integers  int i = 1, j = 2, k = 3; // initialization, not assignment  i = j = k; // values of i and j are now 3 // (i = j) = k; // Error: lvalue required  printf("%d %d %d\n", i, j, k);  // pointers  const char c = 'A'; // initialization; not assignment  const char *p = &c; // initialization; not assignment  const char **cpp = &p; // initialization; not assignment // cpp = &p; // Error: char** is not convertible to const char**  *cpp = &c; // OK, char* is convertible to const char*  printf("%c \n", **cpp);  cpp = 0; // OK, null pointer constant is convertible to any pointer  // arrays  int arr1[2] = {1,2}, arr2[2] = {3, 4}; // arr1 = arr2; // Error: cannot assign to an array  printf("arr1[0]=%d arr1[1]=%d arr2[0]=%d arr2[1]=%d\n",  arr1[0], arr1[1], arr2[0], arr2[1]);  struct { int arr[2]; } sam1 = { {5, 6} }, sam2 = { {7, 8} };  sam1 = sam2; // OK: can assign arrays wrapped in structs  printf("%d %d \n", sam1.arr[0], sam1.arr[1]); }
```

Output:

```c
3 3 3 A arr1[0]=1 arr1[1]=2 arr2[0]=3 arr2[1]=4 7 8
```

### Compound assignment
複合賦值

The compound assignment operator expressions have the form
複合賦值運運算元表示式具有如下形式

|   |

| lhs op rhs  |   |   |   |   |

|   |

where

| op  |   | -  |   | one of `*=`, `/=` `%=`, `+=` `-=`, `<<=`, `>>=`, `&=`, `^=`, `|=`  |

| lhs, rhs  |   | -  |   | expressions with arithmetic types (where lhs may be qualified or atomic), except when op is `+=` or `-=`, which also accept pointer types with the same restrictions as + and -  |

The expression lhs @= rhs is exactly the same as lhs `**=**` lhs @ `**(**` rhs `**)**`, except that lhs is evaluated only once.
表示式 lhs @= rhs 與 lhs = lhs @ ( rhs ) 完全相同，只是 lhs 只被求值一次。

If lhs has atomic type, the operation behaves as a single atomic read-modify-write operation with memory order memory_order_seq_cst.
For integer atomic types, the compound assignment `@=` is equivalent to:

```c
T1* addr = &lhs; T2 val = rhs; T1 old = *addr; T1 new; do { new = old @ val } while (!atomic_compare_exchange_strong(addr, &old, new);
```
|   | (since C11) |

Run this code

```c
#include <stdio.h> int main(void) {  int x = 10;   int hundred = 100;   int ten = 10;   int fifty = 50;   printf("%d %d %d %d\n", x, hundred, ten, fifty);  hundred *= x;   ten /= x;   fifty %= x;   printf("%d %d %d %d\n", x, hundred, ten, fifty);  return 0; }
```

Output:

```c
10 100 10 50 10 1000 1 0
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.16 Assignment operators (p: 72-73)
6.5.16 賦值運運算元（p: 72-73）
6.5.16 賦值運運算元（p: 72-73）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.16 Assignment operators (p: 101-104)
6.5.16 賦值運運算元（p: 101-104）
6.5.16 賦值運運算元（p: 101-104）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.16 Assignment operators (p: 91-93)
6.5.16 賦值運運算元（p: 91-93）
6.5.16 賦值運運算元（p: 91-93）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.16 Assignment operators
3.3.16 賦值運運算元
3.3.16 賦值運運算元

### See Also

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

### See also

C++ documentation for Assignment operators

---
來源頁路徑：`en.cppreference.com/c/language/operator_assignment.html`
