# C Operator Precedence

> 來源：cppreference C 語言參考文件（離線轉換版）。

The following table lists the precedence and associativity of C operators. Operators are listed top to bottom, in descending precedence.
下表列出了 C 運運算元的優先順序和結合性。運運算元按優先順序降序從上到下列出。

| Precedence  |   | Operator  |   | Description  |   | Associativity  |

| 1  |   | `++` `--`  |   | Suffix/postfix increment and decrement  |   | Left-to-right  |

| `()`  |   | Function call  |

| `[]`  |   | Array subscripting  |

| `.`  |   | Structure and union member access  |

| `->`  |   | Structure and union member access through pointer  |

| `(*type*){*list*}`  |   | Compound literal(C99)  |

| 2  |   | `++` `--`  |   | Prefix increment and decrement  |   | Right-to-left  |

| `+` `-`  |   | Unary plus and minus  |

| `!` `~`  |   | Logical NOT and bitwise NOT  |

| `(*type*)`  |   | Cast  |

| `*`  |   | Indirection (dereference)  |

| `&`  |   | Address-of  |

| `sizeof`  |   | Size-of  |

| `_Alignof`  |   | Alignment requirement(C11)  |

| 3  |   | `*` `/` `%`  |   | Multiplication, division, and remainder  |   | Left-to-right  |

| 4  |   | `+` `-`  |   | Addition and subtraction  |

| 5  |   | `<<` `>>`  |   | Bitwise left shift and right shift  |

| 6  |   | `<` `<=`  |   | For relational operators < and ≤ respectively  |

| `>` `>=`  |   | For relational operators > and ≥ respectively  |

| 7  |   | `==` `!=`  |   | For relational = and ≠ respectively  |

| 8  |   | `&`  |   | Bitwise AND  |

| 9  |   | `^`  |   | Bitwise XOR (exclusive or)  |

| 10  |   | `|`  |   | Bitwise OR (inclusive or)  |

| 11  |   | `&&`  |   | Logical AND  |

| 12  |   | `||`  |   | Logical OR  |

| 13  |   | `?:`  |   | Ternary conditional  |   | Right-to-left  |

| 14  |   | `=`  |   | Simple assignment  |

| `+=` `-=`  |   | Assignment by sum and difference  |

| `*=` `/=` `%=`  |   | Assignment by product, quotient, and remainder  |

| `<<=` `>>=`  |   | Assignment by bitwise left shift and right shift  |

| `&=` `^=` `|=`  |   | Assignment by bitwise AND, XOR, and OR  |

| 15  |   | `,`  |   | Comma  |   | Left-to-right  |

- ↑ The operand of prefix `++` and `--` can't be a type cast. This rule grammatically forbids some expressions that would be semantically invalid anyway. Some compilers ignore this rule and detect the invalidity semantically.
↑ 字首 ++ 和 -- 的運算元不能是型別轉換。此規則在語法上禁止一些在語意上本來也無效的表示式。一些編譯器忽略此規則並在語意上檢測無效性。

- ↑ The operand of `sizeof` can't be a type cast: the expression `sizeof (int) * p` is unambiguously interpreted as `(sizeof(int)) * p`, but not `sizeof((int)*p)`.
↑ sizeof 的運算元不能是型別轉換：表示式 sizeof ( int ) * p 明確地解釋為 ( sizeof ( int )) * p ，而不是 sizeof (( int ) * p ) 。

- ↑ The expression in the middle of the conditional operator (between `**?**` and `**:**`) is parsed as if parenthesized: its precedence relative to `?:` is ignored.
↑ 條件運運算元中間（在 ? 和 : 之間）的表示式按加括號方式解析：其相對於 ?: 的優先順序被忽略。

- ↑ Assignment operators' left operands must be unary (level-2 non-cast) expressions. This rule grammatically forbids some expressions that would be semantically invalid anyway. Many compilers ignore this rule and detect the invalidity semantically. For example, `e = a < d ? a++ : a = d` is an expression that cannot be parsed because of this rule. However, many compilers ignore this rule and parse it as `e = ( ((a < d) ? (a++) : a) = d )`, and then give an error because it is semantically invalid.
↑ 賦值運運算元的左運算元必須是一元（第 2 級非轉換）表示式。此規則在語法上禁止一些在語意上本來也無效的表示式。許多編譯器忽略此規則並在語意上檢測無效性。例如，e = a < d ? a ++ : a = d 是一個由於此規則而無法解析的表示式。然而，許多編譯器忽略此規則並將其解析為 e = ( (( a < d ) ? ( a ++ ) : a ) = d ) ，然後因為它在語意上無效而報錯。

When parsing an expression, an operator which is listed on some row will be bound tighter (as if by parentheses) to its arguments than any operator that is listed on a row further below it. For example, the expression `*p++` is parsed as `*(p++)`, and not as `(*p)++`.
解析表示式時，列在某行的運運算元與其運算元的繫結（如同加括號）比列在更下面行的任何運運算元更緊密。例如，表示式 * p ++ 被解析為 * ( p ++ ) ，而不是 ( * p ) ++ 。
Operators that are in the same cell (there may be several rows of operators listed in a cell) are evaluated with the same precedence, in the given direction. For example, the expression `a = b = c` is parsed as `a = (b = c)`, and not as `(a = b) = c` because of right-to-left associativity.
位於同一單元格中的運運算元（一個單元格中可能列出幾行運運算元）以相同的優先順序、按給定方向求值。例如，表示式 a = b = c 被解析為 a = ( b = c ) ，而不是 ( a = b ) = c，因為結合性是從右到左。

### Notes

Precedence and associativity are independent from order of evaluation.
優先順序和結合性與求值順序無關。
The standard itself doesn't specify precedence levels. They are derived from the grammar.
標準本身沒有指定優先順序級別。它們是從語法推匯出來的。
In C++, the conditional operator has the same precedence as assignment operators, and prefix `++` and `--` and assignment operators don't have the restrictions about their operands.
在 C++ 中，條件運運算元與賦值運運算元具有相同的優先順序，字首 ++ 和 -- 以及賦值運運算元對其運算元沒有限制。
Associativity specification is redundant for unary operators and is only shown for completeness: unary prefix operators always associate right-to-left (`sizeof ++*p` is `sizeof(++(*p))`) and unary postfix operators always associate left-to-right (`a[1][2]++` is `((a[1])[2])++`). Note that the associativity is meaningful for member access operators, even though they are grouped with unary postfix operators: `a.b++` is parsed `(a.b)++` and not `a.(b++)`.
結合性說明對於一元運運算元是冗餘的，僅為完整性而展示：一元字首運運算元總是從右到左結合（sizeof ++* p 是 sizeof ( ++ ( * p )) ），一元后綴運運算元總是從左到右結合（a [ 1 ][ 2 ] ++ 是 (( a [ 1 ])[ 2 ]) ++ ）。注意，結合性對於成員訪問運運算元是有意義的，即使它們與一元后綴運運算元分組在一起：a . b ++ 被解析為 ( a . b ) ++ 而不是 a .( b ++ ) 。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- A.3.1 Expressions
A.3.1 表示式
A.3.1 表示式

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- A.2.1 Expressions
A.2.1 表示式
A.2.1 表示式

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- A.2.1 Expressions
A.2.1 表示式
A.2.1 表示式

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- A.2.1 Expressions
A.2.1 表示式
A.2.1 表示式

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- A.1.2.1 Expressions
A.1.2.1 表示式
A.1.2.1 表示式

### See also

Order of evaluation of operator arguments at run time.
執行時運運算元運算元的求值順序。

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

C++ documentation for C++ operator precedence

---
來源頁路徑：`en.cppreference.com/c/language/operator_precedence.html`
