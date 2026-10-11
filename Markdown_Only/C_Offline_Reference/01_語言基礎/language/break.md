# break statement

> 來源：cppreference C 語言參考文件（離線轉換版）。

Causes the enclosing for, while or do-while loop or switch statement to terminate.
使包含它的 for 、while 或 do-while 迴圈或 switch 陳述式終止。
Used when it is otherwise awkward to terminate the loop using the condition expression and conditional statements.
當使用條件表示式和條件陳述式終止迴圈很不方便時使用。

### Syntax

|   |

| attr-spec-seq ﻿(optional) `**break**` `**;**`  |   |   |   |   |

|   |

| attr-spec-seq  |   | -  |   | (C23) optional list of attributes, applied to the `break` statement  |

Appears only within the statement of a loop body (while, do-while, for) or within the statement of a switch.
只出現在迴圈體（while 、do-while 、for ）的陳述式內或 switch 的陳述式內。

### Explanation

After this statement the control is transferred to the statement or declaration immediately following the enclosing loop or switch, as if by goto.
在該陳述式之後，控制權轉移到緊隨包含它的迴圈或 switch 之後的陳述式或宣告，如同透過 goto 一樣。

### Keywords

break

### Notes

A break statement cannot be used to break out of multiple nested loops. The `goto` statement may be used for this purpose.
break 陳述式不能用於跳出多個巢狀迴圈。goto 陳述式可用於此目的。

### Example

Run this code

```c
#include <stdio.h> int main(void) {  int i = 2;  switch (i)  {  case 1: printf("1");  case 2: printf("2"); // i==2, so execution starts at this case label  case 3: printf("3");  case 4:  case 5: printf("45");  break; // execution of subsequent cases is terminated  case 6: printf("6");  }  printf("\n");    // Compare outputs from these two nested for loops.  for (int j = 0; j < 2; j++)  for (int k = 0; k < 5; k++)  printf("%d%d ", j,k);  printf("\n");  for (int j = 0; j < 2; j++)  {  for (int k = 0; k < 5; k++) // only this loop is exited by break  {  if (k == 2)  break;  printf("%d%d ", j,k);  }  } }
```

Possible output:
可能的輸出：

```c
2345 00 01 02 03 04 10 11 12 13 14 00 01 10 11
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8.6.3 The break statement (p: 111)
6.8.6.3 break 陳述式（p: 111）
6.8.6.3 break 陳述式（p: 111）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8.6.3 The break statement (p: 153)
6.8.6.3 break 陳述式（p: 153）
6.8.6.3 break 陳述式（p: 153）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8.6.3 The break statement (p: 138)
6.8.6.3 break 陳述式（p: 138）
6.8.6.3 break 陳述式（p: 138）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6.6.3 The break statement
3.6.6.3 break 陳述式
3.6.6.3 break 陳述式

### See also

`[[fallthrough]]`
(C23)
|   | indicates that the fall through from the previous case label is intentional and should not be diagnosed by a compiler that warns on fall-through
(attribute specifier)  |

C++ documentation for `break` statement

---
來源頁路徑：`en.cppreference.com/c/language/break.html`
