# setjmp

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<setjmp.h>`
|   |  |   |  |

```c
#define setjmp(env) /* implementation-defined */
```
|   |   |   |   |

|  |  |  |  |

Saves the current execution context into a variable `env` of type jmp_buf. This variable can later be used to restore the current execution context by longjmp function. That is, when a call to longjmp function is made, the execution continues at the particular call site that constructed the jmp_buf variable passed to longjmp. In that case `setjmp` returns the value passed to longjmp.
將目前的執行環境儲存到 jmp_buf 型別的變數 env 中，之後可透過 longjmp 函式使用該變數恢復執行環境。呼叫 longjmp 時，程式會從先前以該 jmp_buf 呼叫 setjmp 的位置繼續執行；此時 setjmp 會回傳傳給 longjmp 的值。
The invocation of `setjmp` must appear only in one of the following contexts:
setjmp 的呼叫必須僅出現在以下上下文之一：

- The entire controlling expression of if, switch, while, do-while, for.
```c
switch(setjmp(env)) { // ...
```
if 、 switch 、 while 、 do-while 、 for 的完整控制表示式。 switch ( setjmp ( env )) { // ...

- One operand of a relational or equality operator with the other operand an integer constant expression, with the resulting expression being the entire controlling expression of if, switch, while, do-while, for.
```c
if(setjmp(env) > 10) { // ...
```
關係或相等運運算元的一個運算元，另一個運算元為整數常量表示式，所得表示式為 if 、 switch 、 while 、 do-while 、 for 的完整控制表示式。 if ( setjmp ( env ) > 10 ) { // ...

- The operand of a unary ! operator with the resulting expression being the entire controlling expression of if, switch, while, do-while, for.
```c
while(!setjmp(env)) { // ...
```
一元 ! 運運算元的運算元，所得表示式為 if 、 switch 、 while 、 do-while 、 for 的完整控制表示式。 while ( ! setjmp ( env )) { // ...

- The entire expression of an expression statement (possibly cast to `void`).
```c
setjmp(env);
```
表示式陳述式的完整表示式（可能強制轉換為 void ）。 setjmp ( env );

If `setjmp` appears in any other context, the behavior is undefined.
如果 setjmp 出現在任何其他上下文中，則行為未定義。
Upon return to the scope of `setjmp`:
傳回到 setjmp 的作用域時：

- all accessible objects, floating-point status flags, and other components of the abstract machine have the same values as they had when longjmp was executed,
所有可訪問物件、浮點狀態標誌和抽象機器的其他元件具有與執行 longjmp 時相同的值，

- except for the non-volatile local variables in the function containing the invocation of `setjmp`, whose values are indeterminate if they have been changed since the `setjmp` invocation.
除了包含 setjmp 呼叫的函式中的非 volatile 區域性變數，如果它們在 setjmp 呼叫之後被更改，則其值不確定。

### Parameters

| env  |   | -  |   | variable to save the execution state of the program to.  |

### Return value

`0` if the macro was called by the original code and the execution context was saved to `env`.
如果宏由原始程式碼呼叫且執行上下文已儲存到 env ，則傳回 0。
Non-zero value if a non-local jump was just performed. The return value is the same as passed to longjmp.
如果剛剛執行了非區域性跳轉，則傳回非零值。傳回值與傳遞給 longjmp 的值相同。

### Notes

Above requirements forbid using return value of `setjmp` in data flow (e.g. to initialize or assign an object with it). The return value can only be either used in control flow or discarded.
上述要求禁止在資料流中使用 setjmp 的傳回值（例如用它初始化或賦值物件）。傳回值只能用於控制流或被丟棄。

### Example

Run this code

```c
#include <stdio.h> #include <setjmp.h> #include <stdnoreturn.h> jmp_buf my_jump_buffer; noreturn void foo(int status)  {  printf("foo(%d) called\n", status);  longjmp(my_jump_buffer, status + 1); // will return status+1 out of setjmp } int main(void) {  volatile int count = 0; // modified local vars in setjmp scope must be volatile  if (setjmp(my_jump_buffer) != 5) // compare against constant in an if  foo(++count); }
```

Output:

```c
foo(1) called foo(2) called foo(3) called foo(4) called
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.13.1.1 The setjmp macro (p: 191)
7.13.1.1 setjmp 宏（頁碼：191）
7.13.1.1 setjmp 宏（頁碼：191）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.13.1.1 The setjmp macro (p: 262-263)
7.13.1.1 setjmp 宏（頁碼：262-263）
7.13.1.1 setjmp 宏（頁碼：262-263）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.13.1.1 The setjmp macro (p: 243-244)
7.13.1.1 setjmp 宏（頁碼：243-244）
7.13.1.1 setjmp 宏（頁碼：243-244）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.6.1 The setjmp macro
4.6.1 setjmp 宏
4.6.1 setjmp 宏

### See also

longjmp
|   | jumps to specified location
(function)   |

C++ documentation for setjmp

---
來源頁路徑：`en.cppreference.com/c/program/setjmp.html`
