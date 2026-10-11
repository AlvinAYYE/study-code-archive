# goto statement

> 來源：cppreference C 語言參考文件（離線轉換版）。

Transfers control unconditionally to the desired location.
無條件地將控制轉移到所需位置。
Used when it is otherwise impossible to transfer control to the desired location using conventional constructs.
當使用常規結構無法將控制轉移到所需位置時使用。

### Syntax

|   |

| attr-spec-seq(optional) `**goto**` label `**;**`  |   |   |   |   |

|   |

| label  |   | -  |   | target label for the `goto` statement  |

| attr-spec-seq  |   | -  |   | (C23)optional list of attributes, applied to the `goto` statement  |

### Explanation

The `goto` statement causes an unconditional jump (transfer of control) to the statement prefixed by the named label (which must appear in the same function as the goto statement), except when this jump would enter the scope of a variable-length array or another variably-modified type.(since C99)
goto 陳述式導致到帶命名標籤字首的陳述式的無條件跳轉（控制轉移）（該標籤必須出現在與 goto 陳述式相同的函式中），除非該跳轉會進入可變長度陣列或其他可變修改型別的作用域。（自 C99 起）
A label is an identifier followed by a colon (`**:**`) and a statement(until C23). Labels are the only identifiers that have *function scope*: they can be used (in a goto statement) anywhere in the same function in which they appear. There may be multiple labels before any statement.
標籤是後跟冒號（:）和陳述式（至 C23 止）的識別符號。標籤是唯一具有函式作用域的識別符號：它們可以在其出現的同一函式中的任何地方（在 goto 陳述式中）使用。任何陳述式之前可以有多個標籤。

Entering the scope of a non-variably modified variable is permitted:

```c
goto lab1; // OK: going into the scope of a regular variable  int n = 5; lab1:; // Note, n is uninitialized, as if declared by int n; // goto lab2; // Error: going into the scope of two VM types  double a[n]; // a VLA  int (*p)[n]; // a VM pointer lab2:
```

If `goto` leaves the scope of a VLA, it is deallocated (and may be reallocated if its initialization is executed again):

```c
{  int n = 1; label:;  int a[n]; // re-allocated 10 times, each with a different size  if (n++ < 10) goto label; // leaving the scope of a VM }
```
|   | (since C99) |

### Keywords

goto

### Notes

Because declarations are not statements, a label before a declaration must use a null statement (a semicolon immediately after the colon). Same applies to a label before the end of a block.
|   | (until C23) |

C++ imposes additional limitations on the `goto` statement, but allows labels before declarations (which are statements in C++).
C++ 對 goto 陳述式施加了額外的限制，但允許宣告（在 C++ 中宣告是陳述式）之前有標籤。

### Example

Run this code

```c
#include <stdio.h> int main(void) {  // goto can be used to leave a multi-level loop easily  for (int x = 0; x < 3; x++) {  for (int y = 0; y < 3; y++) {  printf("(%d;%d)\n",x,y);  if (x + y >= 3) goto endloop;  }  } endloop:; }
```

Output:

```c
(0;0) (0;1) (0;2) (1;0) (1;1) (1;2)
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8.6.1 The goto statement (p: 110-111)
6.8.6.1 goto 陳述式 (p: 110-111)
6.8.6.1 goto 陳述式 (p: 110-111)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8.6.1 The goto statement (p: 152-153)
6.8.6.1 goto 陳述式 (p: 152-153)
6.8.6.1 goto 陳述式 (p: 152-153)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8.6.1 The goto statement (p: 137-138)
6.8.6.1 goto 陳述式 (p: 137-138)
6.8.6.1 goto 陳述式 (p: 137-138)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6.6.1 The goto statement
3.6.6.1 goto 陳述式
3.6.6.1 goto 陳述式

### See also

C++ documentation for `goto` statement

---
來源頁路徑：`en.cppreference.com/c/language/goto.html`
