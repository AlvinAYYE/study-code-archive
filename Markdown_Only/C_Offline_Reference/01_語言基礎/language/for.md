# for loop

> 來源：cppreference C 語言參考文件（離線轉換版）。

Executes a loop.
執行一個迴圈。
Used as a shorter equivalent of while loop.
用作 while 迴圈的較短等價形式。

### Syntax

|   |

| attr-spec-seq(since C23)(optional) `**for**` `**(**` init-clause `**;**` cond-expression `**;**` iteration-expression `**)**` loop-statement  |   |   |   |   |

|   |

### Explanation

Behaves as follows:
行為如下：

- init-clause may be an expression or a declaration(since C99).
init-clause 可以是表示式或宣告（自 C99 起）。

- An init-clause, which is an expression, is evaluated once, before the first evaluation of cond-expression and its result is discarded.
作為表示式的 init-clause 會被求值一次，在 cond-expression 的第一次求值之前，其結果被丟棄。
作為表示式的 init-clause 會被求值一次，在 cond-expression 的第一次求值之前，其結果被丟棄。

- An init-clause, which is a declaration, is in scope in the entire loop body, including the remainder of init-clause, the entire cond-expression, the entire iteration-expression and the entire loop-statement. Only `auto` and `register` storage class specifiers are allowed for the variables declared in this declaration.
|   | (since C99) |

- cond-expression is evaluated before the loop body. If the result of the expression is zero, the loop statement is exited immediately.
cond-expression 在迴圈體之前求值。如果表示式的結果為零，則立即退出迴圈陳述式。

- iteration-expression is evaluated after the loop body and its result is discarded. After evaluating iteration-expression, control is transferred to cond-expression.
iteration-expression 在迴圈體之後求值，其結果被丟棄。求值 iteration-expression 之後，控制轉移到 cond-expression。

init-clause, cond-expression, and iteration-expression are all optional. If cond-expression is omitted, it is replaced with a non-zero integer constant, which makes the loop endless:
init-clause、cond-expression 和 iteration-expression 都是可選的。如果省略 cond-expression，則用一個非零整數常量代替，這將使迴圈無限進行：

```c
for(;;) {  printf("endless loop!"); }
```

loop-statement is not optional, but it may be a null statement:
loop-statement 不是可選的，但它可以是空陳述式：

```c
for(int n = 0; n < 10; ++n, printf("%d\n", n))  ; // null statement
```

If the execution of the loop needs to be terminated at some point, a  break statement can be used anywhere within the loop-statement.
如果需要在某一點終止迴圈的執行，可以在 loop-statement 內的任何位置使用 break 陳述式。
The  continue statement used anywhere within the loop-statement transfers control to iteration-expression.
在 loop-statement 內任何位置使用的 continue 陳述式將控制轉移到 iteration-expression。
A program with an endless loop has undefined behavior if the loop has no observable behavior (I/O, volatile accesses, atomic or synchronization operation) in any part of its cond-expression, iteration-expression or loop-statement. This allows the compilers to optimize out all unobservable loops without proving that they terminate. The only exceptions are the loops where cond-expression is omitted or is a constant expression; `for(;;)` is always an endless loop.
如果無限迴圈在其 cond-expression、iteration-expression 或 loop-statement 的任何部分都沒有可觀察行為（I/O、volatile 訪問、原子或同步操作），則包含該無限迴圈的程式具有未定義行為。這允許編譯器在不證明迴圈會終止的情況下最佳化掉所有不可觀察的迴圈。唯一的例外是省略 cond-expression 或其為常量表示式的迴圈；for(;;) 總是無限迴圈。

As with all other selection and iteration statements, the for statement establishes block scope: any identifier introduced in the init-clause, cond-expression, or iteration-expression goes out of scope after the loop-statement.
|   | (since C99) |

attr-spec-seq is an optional list of attributes, applied to the `for` statement.
|   | (since C23) |

### Keywords

for

### Notes

The expression statement used as loop-statement establishes its own block scope, distinct from the scope of init-clause, unlike in C++:
與 C++ 不同，用作 loop-statement 的表示式陳述式建立自己的塊作用域，與 init-clause 的作用域不同：

```c
for (int i = 0; ; ) {  long i = 1; // valid C, invalid C++  // ... }
```

It is possible to enter the body of a loop using goto. When entering a loop in this manner, init-clause and cond-expression are not executed. (If control then reaches the end of the loop body, repetition may occur including execution of cond-expression.)
可以使用 goto 進入迴圈體。以這種方式進入迴圈時，init-clause 和 cond-expression 不執行。（如果隨後控制到達迴圈體的末尾，則可能發生重複，包括執行 cond-expression。）

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> enum { SIZE = 8 }; int main(void) {  int array[SIZE];  for(size_t i = 0 ; i < SIZE; ++i)  array [i] = rand() % 2;  printf("Array filled!\n");  for (size_t i = 0; i < SIZE; ++i)  printf("%d ", array[i]);  putchar('\n'); }
```

Possible output:
可能的輸出：

```c
Array filled! 1 0 1 1 1 1 0 0
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8.5.3 The for statement (p: 110)
6.8.5.3 for 陳述式 (p: 110)
6.8.5.3 for 陳述式 (p: 110)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8.5.3 The for statement (p: 151)
6.8.5.3 for 陳述式 (p: 151)
6.8.5.3 for 陳述式 (p: 151)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8.5.3 The for statement (p: 136)
6.8.5.3 for 陳述式 (p: 136)
6.8.5.3 for 陳述式 (p: 136)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6.5.3 The for statement
3.6.5.3 for 陳述式
3.6.5.3 for 陳述式

### See also

C++ documentation for `for` loop

---
來源頁路徑：`en.cppreference.com/c/language/for.html`
