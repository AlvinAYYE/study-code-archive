# Increment/decrement operators

> 來源：cppreference C 語言參考文件（離線轉換版）。

Increment/decrement operators are unary operators that increment/decrement the value of a variable by 1.
遞增/遞減運運算元是一元運運算元，用於將變數的值遞增/遞減 1。
They can have postfix form:
它們可以有字尾形式：

|   |

| expr `**++**`  |   |   |   |   |

|   |

| expr `**--**`  |   |   |   |   |

|   |

As well as the prefix form:
以及字首形式：

|   |

| `**++**` expr  |   |   |   |   |

|   |

| `**--**` expr  |   |   |   |   |

|   |

The operand expr of both prefix and postfix increment or decrement must be a modifiable lvalue of integer type (including `_Bool` and enums), real floating type, or a pointer type. It may be cvr-qualified, unqualified, or atomic.
字首和字尾遞增或遞減的運算物件 expr 必須是整數型別（包括 _Bool 和列舉）、實浮點型別或指標型別的可修改左值。它可以是 cvr 限定的、非限定的或原子的。
The result of the postfix increment and decrement operators is the value of expr.
字尾遞增和遞減運運算元的結果是 expr 的值。
The result of the prefix increment operator is the result of adding the value `1` to the value of expr: the expression `++e` is equivalent to `e += 1`. The result of the prefix decrement operator is the result of subtracting the value `1` from the value of expr: the expression `--e` is equivalent to `e -= 1`.
字首遞增運運算元的結果是將值 1 加到 expr 的值上的結果：表示式 ++e 等價於 e += 1。字首遞減運運算元的結果是將 expr 的值減去值 1 的結果：表示式 --e 等價於 e -= 1。
Increment operators initiate the side-effect of adding the value `1` of appropriate type to the operand. Decrement operators initiate the side-effect of subtracting the value `1` of appropriate type from the operand. As with any other side-effects, these operations complete at or before the next sequence point.
遞增運運算元啟動將適當型別的值 1 加到運算物件上的副作用。遞減運運算元啟動從運算物件減去適當型別的值 1 的副作用。與任何其他副作用一樣，這些操作在下一個順序點或之前完成。

```c
int a = 1; int b = a++; // stores 1+a (which is 2) to a  // returns the old value of a (which is 1)  // After this line, b == 1 and a == 2 a = 1; int c = ++a; // stores 1+a (which is 2) to a  // returns 1+a (which is 2)  // after this line, c == 2 and a == 2
```

Post-increment or post-decrement on any atomic variable is an atomic read-modify-write operation with memory order memory_order_seq_cst.
|   | (since C11) |

See arithmetic operators for limitations on pointer arithmetic, as well as for implicit conversions applied to the operands.
有關指標算術的限制以及對運算物件應用的隱式轉換，請參見算術運運算元。

### Notes

Because of the side-effects involved, increment and decrement operators must be used with care to avoid undefined behavior due to violations of sequencing rules.
由於涉及副作用，使用遞增和遞減運運算元時必須小心，以避免因違反順序規則而導致未定義行為。
Increment/decrement operators are not defined for complex or imaginary types: the usual definition of adding/subtracting the real number 1 would have no effect on imaginary types, and making it add/subtract `i` for imaginaries but `1` for complex numbers would have made it handle `0+yi` different from `yi`.
遞增/遞減運運算元對複數或虛數型別未定義：加上/減去實數 1 的常規定義對虛數型別沒有影響，而使其對虛數加減 i、但對複數加減 1 的做法，會使它對 0+yi 的處理不同於 yi。
Unlike C++ (and some implementations of C), the increment/decrement expressions are never themselves lvalues: `&++a` is invalid.
與 C++（以及 C 的某些實現）不同，遞增/遞減表示式本身從來不是左值：&++a 是無效的。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> int main(void) {  int a = 1;  int b = 1;  printf("original values: a == %d, b == %d\n", a, b);  printf("result of postfix operators: a++ == %d, b-- == %d\n", a++, b--);  printf("after postfix operators applied: a == %d, b == %d\n", a, b);  printf("\n");  // Reset a and b.  a = 1;  b = 1;  printf("original values: a == %d, b == %d\n", a, b);  printf("result of prefix operators: ++a == %d, --b == %d\n", ++a, --b);  printf("after prefix operators applied: a == %d, b == %d\n", a, b); }
```

Output:

```c
original values: a == 1, b == 1 result of postfix operators: a++ == 1, b-- == 1 after postfix operators applied: a == 2, b == 0 original values: a == 1, b == 1 result of prefix operators: ++a == 2, --b == 0 after prefix operators applied: a == 2, b == 0
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.5.2.4 Postfix increment and decrement operators (p: TBD)
6.5.2.4 字尾遞增和遞減運運算元 (p: TBD)
6.5.2.4 字尾遞增和遞減運運算元 (p: TBD)

- 6.5.3.1 Prefix increment and decrement operators (p: TBD)
6.5.3.1 字首遞增和遞減運運算元 (p: TBD)
6.5.3.1 字首遞增和遞減運運算元 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.2.4 Postfix increment and decrement operators (p: TBD)
6.5.2.4 字尾遞增和遞減運運算元 (p: TBD)
6.5.2.4 字尾遞增和遞減運運算元 (p: TBD)

- 6.5.3.1 Prefix increment and decrement operators (p: TBD)
6.5.3.1 字首遞增和遞減運運算元 (p: TBD)
6.5.3.1 字首遞增和遞減運運算元 (p: TBD)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.2.4 Postfix increment and decrement operators (p: 85)
6.5.2.4 字尾遞增和遞減運運算元 (p: 85)
6.5.2.4 字尾遞增和遞減運運算元 (p: 85)

- 6.5.3.1 Prefix increment and decrement operators (p: 88)
6.5.3.1 字首遞增和遞減運運算元 (p: 88)
6.5.3.1 字首遞增和遞減運運算元 (p: 88)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.2.4 Postfix increment and decrement operators (p: 75)
6.5.2.4 字尾遞增和遞減運運算元 (p: 75)
6.5.2.4 字尾遞增和遞減運運算元 (p: 75)

- 6.5.3.1 Prefix increment and decrement operators (p: 78)
6.5.3.1 字首遞增和遞減運運算元 (p: 78)
6.5.3.1 字首遞增和遞減運運算元 (p: 78)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.2.4 Postfix increment and decrement operators
3.3.2.4 字尾遞增和遞減運運算元
3.3.2.4 字尾遞增和遞減運運算元

- 3.3.3.1 Prefix increment and decrement operators
3.3.3.1 字首遞增和遞減運運算元
3.3.3.1 字首遞增和遞減運運算元

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

C++ documentation for Increment/decrement operators

---
來源頁路徑：`en.cppreference.com/c/language/operator_incdec.html`
