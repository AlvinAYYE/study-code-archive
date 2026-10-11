# if statement

> 來源：cppreference C 語言參考文件（離線轉換版）。

Conditionally executes code.
有條件地執行程式碼。
Used where code needs to be executed only if some condition is true.
用於僅在某個條件為真時才需要執行程式碼的場合。

### Syntax

|   |

| attr-spec-seq(optional) `**if (**` expression `**)**` statement-true  |   | (1)  |   |   |

|   |

| attr-spec-seq(optional) `**if (**` expression `**)**` statement-true `**else**` statement-false  |   | (2)  |   |   |

|   |

| attr-spec-seq  |   | -  |   | (C23)optional list of attributes, applied to the `if` statement  |

| expression  |   | -  |   | an expression of any scalar type  |

| statement-true  |   | -  |   | any statement (often a compound statement), which is executed if expression compares not equal to `0`  |

| statement-false  |   | -  |   | any statement (often a compound statement), which is executed if expression compares equal to `0`  |

### Explanation

expression must be an expression of any scalar type.
expression 必須是任何標量型別的表示式。
If expression compares not equal to the integer zero, statement-true is executed.
如果 expression 與整數零比較不相等，則執行 statement-true。
In the form (2), if expression compares equal to the integer zero, statement_false is executed.
在形式 (2) 中，如果 expression 與整數零比較相等，則執行 statement_false。

As with all other selection and iteration statements, the entire if-statement has its own block scope:

```c
enum {a, b}; int different(void) {  if (sizeof(enum {b, a}) != sizeof(int))  return a; // a == 1  return b; // b == 0 in C89, b == 1 in C99 }
```
|   | (since C99) |

### Notes

The `else` is always associated with the closest preceding `if` (in other words, if statement-true is also an if statement, then that inner if statement must contain an `else` part as well):
else 總是與最近的前一個 if 關聯（換句話說，如果 statement-true 也是一個 if 陳述式，那麼該內層 if 陳述式也必須包含 else 部分）：

```c
int j = 1; if (i > 1)  if(j > 2)  printf("%d > 1 and %d > 2\n", i, j);  else // this else is part of if(j>2), not part of if(i>1)   printf("%d > 1 and %d <= 2\n", i, j);
```

If statement-true is entered through a goto, statement-false is not executed.
如果透過 goto 進入 statement-true，則不執行 statement-false。

### Keywords

if, else

### Example

Run this code

```c
#include <stdio.h>   int main(void) {  int i = 2;  if (i > 2) {  printf("first is true\n");  } else {  printf("first is false\n");  }    i = 3;  if (i == 3) printf("i == 3\n");    if (i != 3) printf("i != 3 is true\n");  else printf("i != 3 is false\n"); }
```

Output:

```c
first is false i == 3 i != 3 is false
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8.4.1 The if statement (p: 108-109)
6.8.4.1 if 陳述式 (p: 108-109)
6.8.4.1 if 陳述式 (p: 108-109)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8.4.1 The if statement (p: 148-149)
6.8.4.1 if 陳述式 (p: 148-149)
6.8.4.1 if 陳述式 (p: 148-149)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8.4.1 The if statement (p: 133-134)
6.8.4.1 if 陳述式 (p: 133-134)
6.8.4.1 if 陳述式 (p: 133-134)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6.4.1 The if statement
3.6.4.1 if 陳述式
3.6.4.1 if 陳述式

### See also

C++ documentation for `if` statement

---
來源頁路徑：`en.cppreference.com/c/language/if.html`
