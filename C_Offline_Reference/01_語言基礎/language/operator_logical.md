# Logical operators

> 來源：cppreference C 語言參考文件（離線轉換版）。

Logical operators apply standard boolean algebra operations to their operands.
邏輯運運算元對其運算元應用標準布林代數運算。

| Operator  |   | Operator name  |   | Example  |   | Result  |

| `!`  |   | logical NOT  |   | `!a`  |   | the logical negation of **a**  |

| `&&`  |   | logical AND  |   | `a && b`  |   | the logical AND of **a** and **b**  |

| `||`  |   | logical OR  |   | `a || b`  |   | the logical OR of **a** and **b**  |

### Logical NOT

The logical NOT expression has the form
邏輯 NOT 表示式具有如下形式

|   |

| `**!**` expression  |   |   |   |   |

|   |

where

| expression  |   | -  |   | an expression of any scalar type  |

The logical NOT operator has type `int`. Its value is `0` if expression evaluates to a value that compares unequal to zero. Its value is `1` if expression evaluates to a value that compares equal to zero. (So, `!E` is the same as `(0 == E)`).
邏輯 NOT 運運算元的型別為 int。如果 expression 求值得到與零不相等的值，則其值為 0。如果 expression 求值得到與零相等的值，則其值為 1。（因此，!E 與 (0 == E) 相同。）

Run this code

```c
#include <ctype.h> #include <stdbool.h> #include <stdio.h> int main(void) {  bool b = !(2 + 2 == 4); // not true  printf("!(2+2==4) = %s\n", b ? "true" : "false");  int n = isspace('a'); // non-zero if 'a' is a space, zero otherwise  int x = !!n; // "bang-bang", common C idiom for mapping integers to [0,1]  // (all non-zero values become 1)  char *a[2] = {"non-space", "space"};  puts(a[x]); // now x can be safely used as an index to array of 2 strings }
```

Output:

```c
!(2+2==4) = false non-space
```

### Logical AND

The logical AND expression has the form
邏輯 AND 表示式具有如下形式

|   |

| lhs `**&&**` rhs  |   |   |   |   |

|   |

where

| lhs  |   | -  |   | an expression of any scalar type  |

| rhs  |   | -  |   | an expression of any scalar type, which is only evaluated if lhs does not compare equal to `0`  |

The logical-AND operator has type `int` and the value `1` if both lhs and rhs compare unequal to zero. It has the value `0` otherwise (if either lhs or rhs or both compare equal to zero).
邏輯 AND 運運算元的型別為 int，如果 lhs 和 rhs 都與零不相等，則值為 1。否則（如果 lhs 或 rhs 或兩者與零相等）值為 0。
There is a sequence point after the evaluation of lhs. If the result of lhs compares equal to zero, then rhs is not evaluated at all (so-called *short-circuit evaluation*).
在 lhs 求值之後有一個序列點。如果 lhs 的結果與零相等，則 rhs 完全不會被求值（所謂短路求值）。

Run this code

```c
#include <stdbool.h> #include <stdio.h> int main(void) {  bool b = 2 + 2 == 4 && 2 * 2 == 4; // b == true  1 > 2 && puts("this won't print");  char *p = "abc";  if (p && *p) // common C idiom: if p is not null  // AND if p does not point at the end of the string  { // (note that thanks to short-circuit evaluation, this  // will not attempt to dereference a null pointer)  // ... // ... then do some string processing  } }
```

### Logical OR

The logical OR expression has the form
邏輯 OR 表示式具有如下形式

|   |

| lhs `**||**` rhs  |   |   |   |   |

|   |

where

| lhs  |   | -  |   | an expression of any scalar type  |

| rhs  |   | -  |   | an expression of any scalar type, which is only evaluated if lhs compares equal to `0`  |

The logical-OR operator has type `int` and the value `1` if either lhs or rhs compare unequal to zero. It has value `0` otherwise (if both lhs and rhs compare equal to zero).
邏輯 OR 運運算元的型別為 int，如果 lhs 或 rhs 與零不相等，則值為 1。否則（如果 lhs 和 rhs 都與零相等）值為 0。
There is a sequence point after the evaluation of lhs. If the result of lhs compares unequal to zero, then rhs is not evaluated at all (so-called *short-circuit evaluation*).
在 lhs 求值之後有一個序列點。如果 lhs 的結果與零不相等，則 rhs 完全不會被求值（所謂短路求值）。

Run this code

```c
#include <errno.h> #include <stdbool.h> #include <stdio.h> #include <string.h> int main(void) {  bool b = 2 + 2 == 4 || 2 + 2 == 5; // true  printf("true or false = %s\n", b ? "true" : "false");  // Logical OR can be used similarly to Perl's “or die”, as long as rhs has scalar type  fopen("test.txt", "r") || printf("could not open test.txt: %s\n", strerror(errno)); }
```

Possible output:
可能的輸出：

```c
true or false = true could not open test.txt: No such file or directory
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.5.3.3 Unary arithmetic operators (p: TBD)
6.5.3.3 一元算術運運算元（第 TBD 頁）
6.5.3.3 一元算術運運算元（第 TBD 頁）

- 6.5.13 Logical AND operator (p: TBD)
6.5.13 邏輯 AND 運運算元（第 TBD 頁）
6.5.13 邏輯 AND 運運算元（第 TBD 頁）

- 6.5.14 Logical OR operator (p: TBD)
6.5.14 邏輯 OR 運運算元（第 TBD 頁）
6.5.14 邏輯 OR 運運算元（第 TBD 頁）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.3.3 Unary arithmetic operators (p: TBD)
6.5.3.3 一元算術運運算元（第 TBD 頁）
6.5.3.3 一元算術運運算元（第 TBD 頁）

- 6.5.13 Logical AND operator (p: TBD)
6.5.13 邏輯 AND 運運算元（第 TBD 頁）
6.5.13 邏輯 AND 運運算元（第 TBD 頁）

- 6.5.14 Logical OR operator (p: TBD)
6.5.14 邏輯 OR 運運算元（第 TBD 頁）
6.5.14 邏輯 OR 運運算元（第 TBD 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.3.3 Unary arithmetic operators (p: 89)
6.5.3.3 一元算術運運算元 (p: 89)
6.5.3.3 一元算術運運算元 (p: 89)

- 6.5.13 Logical AND operator (p: 99)
6.5.13 邏輯 AND 運運算元（第 99 頁）
6.5.13 邏輯 AND 運運算元（第 99 頁）

- 6.5.14 Logical OR operator (p: 99)
6.5.14 邏輯 OR 運運算元（第 99 頁）
6.5.14 邏輯 OR 運運算元（第 99 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.3.3 Unary arithmetic operators (p: 79)
6.5.3.3 一元算術運運算元 (p: 79)
6.5.3.3 一元算術運運算元 (p: 79)

- 6.5.13 Logical AND operator (p: 89)
6.5.13 邏輯 AND 運運算元（第 89 頁）
6.5.13 邏輯 AND 運運算元（第 89 頁）

- 6.5.14 Logical OR operator (p: 89)
6.5.14 邏輯 OR 運運算元（第 89 頁）
6.5.14 邏輯 OR 運運算元（第 89 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.3.3 Unary arithmetic operators
3.3.3.3 一元算術運運算元
3.3.3.3 一元算術運運算元

- 3.3.13 Logical AND operator
3.3.13 邏輯 AND 運運算元
3.3.13 邏輯 AND 運運算元

- 3.3.14 Logical OR operator
3.3.14 邏輯 OR 運運算元
3.3.14 邏輯 OR 運運算元

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

C++ documentation for Logical operators

---
來源頁路徑：`en.cppreference.com/c/language/operator_logical.html`
