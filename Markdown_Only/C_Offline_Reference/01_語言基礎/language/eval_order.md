# Order of evaluation

> 來源：cppreference C 語言參考文件（離線轉換版）。

Order of evaluation of the operands of any C operator, including the order of evaluation of function arguments in a function-call expression, and the order of evaluation of the subexpressions within any expression is unspecified (except where noted below). The compiler will evaluate them in any order, and may choose another order when the same expression is evaluated again.
任何 C 運運算元的運算元的求值順序，包括函式呼叫表示式中函式實參的求值順序，以及任何表示式內部子表示式的求值順序，都是未指定的（除非下文另有說明）。編譯器可以按任意順序對它們求值，並且在同一表示式再次被求值時可能選擇另一種順序。
There is no concept of left-to-right or right-to-left evaluation in C, which is not to be confused with left-to-right and right-to-left associativity of operators: the expression `f1() + f2() + f3()` is parsed as `(f1() + f2()) + f3()` due to left-to-right associativity of `operator+`, but the function call to `f3()` may be evaluated first, last, or between `f1()` or `f2()` at run time.
C 中沒有從左到右或從右到左求值的概念，這不應與運運算元的從左到右和從右到左結合性混淆：表示式 f1 () + f2 () + f3 () 由於運運算元 + 的從左到右結合性而被解析為 ( f1 () + f2 ()) + f3 ()，但在執行時對 f3 () 的函式呼叫可能最先求值、最後求值，或者在 f1 () 與 f2 () 之間求值。

### Definitions

#### Evaluations

There are two kinds of evaluations performed by the compiler for each expression or subexpression (both of which are optional):
編譯器為每個表示式或子表示式執行兩類求值（兩者都是可選的）：

- *value computation ﻿*: calculation of the value that is returned by the expression. This may involve determination of the identity of the object (lvalue evaluation) or reading the value previously assigned to an object (rvalue evaluation).
值計算：計算表示式所傳回的值。這可能涉及確定物件的標識（左值求值）或讀取先前賦給物件的值（右值求值）。

- *side effect ﻿*: access (read or write) to an object designated by a volatile lvalue, modification (writing) to an object, atomic synchronization(since C11), modifying a file, modifying the floating-point environment (if supported), or calling a function that does any of those operations.
副作用：對由 volatile 左值所指定物件的訪問（讀或寫）、對物件的修改（寫入）、原子同步（自 C11 起）、修改檔案、修改浮點環境（如果支援），或呼叫會執行上述任一操作的函式。

If no side effects are produced by an expression and the compiler can determine that the value is not used, the expression may not be evaluated.
如果表示式不產生副作用，並且編譯器能夠確定其值未被使用，則該表示式可能不會被求值。

#### Ordering

*Sequenced-before* is an asymmetric, transitive, pair-wise relationship between evaluations within the same thread (it may extend across threads if atomic types and memory barriers are involved).
先於序列是同一執行緒內各求值之間的一種非對稱、可傳遞的成對關係（如果涉及原子型別和記憶體屏障，它可以跨執行緒延伸）。

- If a sequence point is present between the subexpressions `E1` and `E2`, then both value computation and side effects of `E1` are *sequenced-before* every value computation and side effect of `E2`.
如果子表示式 E1 和 E2 之間存在序列點，則 E1 的值計算和所有副作用均先於序列於 E2 的每一個值計算和每一個副作用。

- If evaluation A is sequenced before evaluation B, then evaluation of A will be complete before evaluation of B begins.

- If A is not sequenced before B and B is sequenced before A, then evaluation of B will be complete before evaluation of A begins.

- If A is not sequenced before B and B is not sequenced before A, then two possibilities exist:
- evaluations of A and B are unsequenced: they may be performed in any order and may overlap (within a single thread of execution, the compiler may interleave the CPU instructions that comprise A and B)

- evaluations of A and B are indeterminably-sequenced: they may be performed in any order but may not overlap: either A will be complete before B, or B will be complete before A. The order may be the opposite the next time the same expression is evaluated.
|   | (since C11) |

### Rules

1) There is a sequence point after the evaluation of all function arguments and of the function designator, and before the actual function call.

2) There is a sequence point after evaluation of the first (left) operand and before evaluation of the second (right) operand of the following binary operators: `&&` (logical AND), `||` (logical OR), and `,` (comma).

3) There is a sequence point after evaluation of the first (left) operand and before evaluation of the second or third operand (whichever is evaluated) of the conditional operator `?:`

4) There is a sequence point after the evaluation of a full expression (an expression that is not a subexpression: typically something that ends with a semicolon or a controlling statement of `if`/`switch`/`while`/`do`) and before the next full expression.

5) There is a sequence point at the end of a full declarator.

6) There is a sequence point immediately before the return of a library function.

7) There is a sequence point after the action associated with each conversion specifier in formatted I/O (in particular, it is well-formed for scanf to write different fields into the same variable and for printf to read and modify or modify the same variable more than once using `%n`)

8) There are sequence points before and immediately after each call to a comparison function made by the library functions qsort and bsearch, as well as between any call to the comparison function and the movement of the associated objects made by qsort
|   | (since C99) |

9) The value computations (but not the side-effects) of the operands to any operator are sequenced before the value computation of the result of the operator (but not its side-effects).

10) The side effect (modification of the left argument) of the direct assignment operator and of all compound assignment operators is sequenced after the value computation (but not the side effects) of both left and right arguments.

11) The value computation of the post-increment and post-decrement operators is sequenced before its side-effect.

12) A function call that is not sequenced before or sequenced after another function call is indeterminately sequenced (CPU instructions that constitute different function calls cannot be interleaved, even if the functions are inlined)

13) In initialization list expressions, all evaluations are indeterminately sequenced

14) With respect to an indeterminately-sequenced function call, the operation of compound assignment operators, and both prefix and postfix forms of increment and decrement operators are single evaluations.
|   | (since C11) |

### Undefined behavior
未定義行為

1) If a side effect on a scalar object is unsequenced relative to another side effect on the same scalar object, the behavior is undefined.
```c
i = ++i + i++; // undefined behavior i = i++ + 1; // undefined behavior f(++i, ++i); // undefined behavior f(i = -1, i = -1); // undefined behavior
```

2) If a side effect on a scalar object is unsequenced relative to a value computation using the value of the same scalar object, the behavior is undefined.
```c
f(i, i++); // undefined behavior a[i] = i++; // undefined behavior
```

3) The above rules apply as long as at least one allowable ordering of subexpressions permits such an unsequenced side-effect.

### See also

Operator precedence which defines how expressions are built from their source code representation.
運運算元優先順序，它定義瞭如何由原始碼表示來構建表示式。

C++ documentation for Order of evaluation

---
來源頁路徑：`en.cppreference.com/c/language/eval_order.html`
