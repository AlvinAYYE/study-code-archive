# while loop

> 來源：cppreference C 語言參考文件（離線轉換版）。

Executes a statement repeatedly, until the value of expression becomes equal to zero. The test takes place before each iteration.
重複執行陳述式，直到 expression 的值變為等於零。測試在每次迭代之前進行。

### Syntax

|   |

| attr-spec-seq(optional) `**while (**` expression `**)**` statement  |   |   |   |   |

|   |

| expression  |   | -  |   | any expression of scalar type. This expression is evaluated before each iteration, and if it compares equal to zero, the loop is exited.  |

| statement  |   | -  |   | any statement, typically a compound statement, which serves as the body of the loop  |

| attr-spec-seq  |   | -  |   | (C23)optional list of attributes, applied to the loop statement  |

### Explanation

A `while` statement causes the statement (also called *the loop body*) to be executed repeatedly until the expression (also called *controlling expression*) compares equal to zero. The repetition occurs regardless of whether the loop body is entered normally or by a goto into the middle of statement.
while 陳述式使陳述式（也稱為迴圈體）重複執行，直到表示式（也稱為控制表示式）與零相等為止。無論迴圈體是正常進入還是透過 goto 進入陳述式中間，都會發生重複。
The evaluation of expression takes place before each execution of statement (unless entered by a goto). If the controlling expression needs to be evaluated after the loop body, the do-while loop may be used.
expression 的求值在每次執行 statement 之前進行（除非透過 goto 進入）。如果控制表示式需要在迴圈體之後求值，則可以使用 do-while 迴圈。
If the execution of the loop needs to be terminated at some point,  break statement can be used as a terminating statement.
如果需要在某一點終止迴圈的執行，可以使用 break 陳述式作為終止陳述式。
If the execution of the loop needs to be continued at the end of the loop body,  continue statement can be used as a shortcut.
如果需要在迴圈體末尾繼續迴圈的執行，可以使用 continue 陳述式作為快捷方式。
A program with an endless loop has undefined behavior if the loop has no observable behavior (I/O, volatile accesses, atomic or synchronization operation) in any part of its statement or expression. This allows the compilers to optimize out all unobservable loops without proving that they terminate. The only exceptions are the loops where expression is a constant expression; `while(true)` is always an endless loop.
如果程式中的無限迴圈在其陳述式或表示式的任何部分都沒有可觀察行為（I/O、volatile 訪問、原子或同步操作），則該程式具有未定義行為。這允許編譯器在不證明迴圈會終止的情況下最佳化掉所有不可觀察的迴圈。唯一的例外是 expression 為常量表示式的迴圈；while(true) 始終是無限迴圈。

As with all other selection and iteration statements, the while statement establishes block scope: any identifier introduced in the expression goes out of scope after the statement.
|   | (since C99) |

### Notes

Boolean and pointer expressions are often used as loop controlling expressions. The boolean value `false` and the null pointer value of any pointer type compare equal to zero.
布林表示式和指標表示式常用作迴圈控制表示式。布林值 false 和任何指標型別的空指標值與零相等。

### Keywords

while

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> #include <string.h> enum { SIZE = 8 }; int main(void) {  // trivial example  int array[SIZE], n = 0;  while(n < SIZE) array[n++] = rand() % 2;  puts("Array filled!");  n = 0;  while(n < SIZE) printf("%d ", array[n++]);  printf("\n");  // classic strcpy() implementation  // (copies a null-terminated string from src to dst)  char src[] = "Hello, world", dst[sizeof src], *p = dst, *q = src;  while((*p++ = *q++)) // double parentheses (that are not strictly necessary)  // used to suppress warnings, ensuring that this is an  // assignment (as opposed to a comparison) by intention,  // whose result is used as a truth value  ; // null statement  puts(dst); }
```

Output:

```c
Array filled! 1 0 1 1 1 1 0 0 Hello, world
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8.5.1 The while statement (p: 109)
6.8.5.1 while 陳述式（第 109 頁）
6.8.5.1 while 陳述式（第 109 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8.5.1 The while statement (p: 151)
6.8.5.1 while 陳述式（第 151 頁）
6.8.5.1 while 陳述式（第 151 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8.5.1 The while statement (p: 136)
6.8.5.1 while 陳述式（第 136 頁）
6.8.5.1 while 陳述式（第 136 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6.5.1 The while statement
3.6.5.1 while 陳述式
3.6.5.1 while 陳述式

### See also

C++ documentation for `while` loop

---
來源頁路徑：`en.cppreference.com/c/language/while.html`
