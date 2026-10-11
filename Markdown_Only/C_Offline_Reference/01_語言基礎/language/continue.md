# continue statement

> 來源：cppreference C 語言參考文件（離線轉換版）。

Causes the remaining portion of the enclosing for, while or  do-while loop body to be skipped.
導致跳過外層 for、while 或 do-while 迴圈體中剩餘的部分。
Used when it is otherwise awkward to ignore the remaining portion of the loop using conditional statements.
當使用條件陳述式忽略迴圈剩餘部分很不方便時使用。

### Syntax

|   |

| attr-spec-seq(optional) `**continue**` `**;**`  |   |   |   |   |

|   |

| attr-spec-seq  |   | -  |   | (C23)optional list of attributes, applied to the `continue` statement  |

### Explanation

The `continue` statement causes a jump, as if by goto, to the end of the loop body (it may only appear within the loop body of for, while, and do-while loops).
continue 陳述式導致跳轉，就好像透過 goto 跳到迴圈體末尾（它只能出現在 for、while 和 do-while 迴圈的迴圈體內）。
For while loop, it acts as
對於 while 迴圈，它相當於

```c
while (/* ... */) {  // ...   continue; // acts as goto contin;  // ...   contin:; }
```

For do-while loop, it acts as:
對於 do-while 迴圈，它相當於：

```c
do {  // ...   continue; // acts as goto contin;  // ...   contin:; } while (/* ... */);
```

For for loop, it acts as:
對於 for 迴圈，它相當於：

```c
for (/* ... */) {  // ...   continue; // acts as goto contin;  // ...   contin:; }
```

### Keywords

continue

### Example

Run this code

```c
#include <stdio.h>   int main(void)  {  for (int i = 0; i < 10; i++) {  if (i != 5) continue;  printf("%d ", i); // this statement is skipped each time i != 5  }    printf("\n");    for (int j = 0; j < 2; j++) {  for (int k = 0; k < 5; k++) { // only this loop is affected by continue  if (k == 3) continue;  printf("%d%d ", j, k); // this statement is skipped each time k == 3  }  } }
```

Output:

```c
5 00 01 02 04 10 11 12 14
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8.6.2 The continue statement (p: 111)
6.8.6.2 continue 陳述式 (p: 111)
6.8.6.2 continue 陳述式 (p: 111)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8.6.2 The continue statement (p: 153)
6.8.6.2 continue 陳述式 (p: 153)
6.8.6.2 continue 陳述式 (p: 153)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8.6.2 The continue statement (p: 138)
6.8.6.2 continue 陳述式 (p: 138)
6.8.6.2 continue 陳述式 (p: 138)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6.6.2 The continue statement
3.6.6.2 continue 陳述式
3.6.6.2 continue 陳述式

### See also

C++ documentation for `continue` statement

---
來源頁路徑：`en.cppreference.com/c/language/continue.html`
