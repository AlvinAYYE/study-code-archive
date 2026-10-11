# return statement

> 來源：cppreference C 語言參考文件（離線轉換版）。

Terminates current function and returns specified value to the caller function.
終止目前函式並將指定的值傳回給呼叫函式。

### Syntax

|   |

| attr-spec-seq(optional) `**return**` expression `**;**`  |   | (1)  |   |   |

|   |

| attr-spec-seq(optional) `**return**` `**;**`  |   | (2)  |   |   |

|   |

| expression  |   | -  |   | expression used for initializing the return value of the function  |

| attr-spec-seq  |   | -  |   | (C23)optional list of attributes, applied to the `return` statement  |

### Explanation

1) Evaluates the expression, terminates the current function and returns the result of the expression to the caller (the value returned becomes the value of the function call expression). Only valid if the function return type is not `void`.

2) Terminates the current function. Only valid if the function return type is `void`.

If the type of the expression is different from the return type of the function, its value is converted as if by assignment to an object whose type is the return type of the function, except that overlap between object representations is permitted:
如果表示式的型別與函式的傳回型別不同，則其值的轉換方式如同賦值給一個型別為函式傳回型別的物件，但允許物件表示之間存在重疊：

```c
struct s { double i; } f(void); // function returning struct s union { struct { int f1; struct s f2; } u1;  struct { struct s f3; int f4; } u2; } g; struct s f(void) {  return g.u1.f2; } int main(void) { // g.u2.f3 = g.u1.f2; // undefined behavior (overlap in assignment)  g.u2.f3 = f(); // well-defined }
```

If the return type is a real floating type, the result may be represented in greater range and precision than implied by the new type.
如果傳回型別是實浮點型別，則結果可以用比新型別所暗示的更大範圍和精度表示。
Reaching the end of a function returning `void` is equivalent to `return;`. Reaching the end of any other value-returning function is undefined behavior if the result of the function is used in an expression (it is allowed to discard such return value). For `main`, see `main` function.
到達傳回 void 的函式末尾等價於 return ; 。如果函式的結果在表示式中被使用，到達任何其他有傳回值的函式末尾是未定義行為（允許丟棄此類傳回值）。關於 main ，參見 main 函式 。

Executing the `return` statement in a no-return function is undefined behavior.
|   | (since C11) |

### Keywords

return

### Example

|  | This section is incomplete
Reason: improve  |

Run this code

```c
#include <stdio.h>   void fa(int i) {  if (i == 2)  return;  printf("fa(): %d\n", i); } // implied return;   int fb(int i) {  if (i > 4)  return 4;  printf("fb(): %d\n", i);  return 2; }   int main(void) {  fa(2);  fa(1);  int i = fb(5); // the return value 4 used to initializes i  i = fb(i); // the return value 2 used as rhs of assignment  printf("main(): %d\n", i); }
```

Output:

```c
fa(): 1 fb(): 4 main(): 2
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8.6.4 The return statement (p: 111-112)
6.8.6.4 return 陳述式（p: 111-112）
6.8.6.4 return 陳述式（p: 111-112）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8.6.4 The return statement (p: 154)
6.8.6.4 return 陳述式（p: 154）
6.8.6.4 return 陳述式（p: 154）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8.6.4 The return statement (p: 139)
6.8.6.4 return 陳述式（p: 139）
6.8.6.4 return 陳述式（p: 139）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6.6.4 The return statement
3.6.6.4 return 陳述式
3.6.6.4 return 陳述式

### See also

C++ documentation for `return` statement

---
來源頁路徑：`en.cppreference.com/c/language/return.html`
