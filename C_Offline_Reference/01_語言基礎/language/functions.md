# Functions

> 來源：cppreference C 語言參考文件（離線轉換版）。

A function is a C language construct that associates a compound statement (the function body) with an identifier (the function name). Every C program begins execution from the main function, which either terminates, or invokes other, user-defined or library functions.
函式是 C 語言的一種構造，它將複合陳述式（函式體）與一個識別符號（函式名）關聯起來。每個 C 程式都從 main 函式開始執行，該函式要麼終止，要麼呼叫其他使用者定義的函式或庫函式。

```c
// function definition. // defines a function with the name "sum" and with the body "{ return x+y; }" int sum(int x, int y)  {  return x + y; }
```

A function is introduced by a function declaration or a function definition.
函式由函式宣告或函式定義引入。
Functions may accept zero or more *parameters*, which are initialized from the *arguments* of a function call operator, and may return a value to its caller by means of the return statement.
函式可以接受零個或多個參數，這些參數由函式呼叫運運算元的實參初始化，並且可以透過 return 陳述式向呼叫者傳回一個值。

```c
int n = sum(1, 2); // parameters x and y are initialized with the arguments 1 and 2
```

The body of a function is provided in a function definition. Each non-inline(since C99) function that is used in an expression (unless unevaluated) must be defined only once in a program.
函式體在函式定義中提供。表示式中使用的每一個非 inline（自 C99 起）函式（除非未被求值）在程式中必須只被定義一次。
There are no nested functions (except where allowed through non-standard compiler extensions): each function definition must appear at file scope, and functions have no access to the local variables from the caller:
不存在巢狀函式（除非透過非標準編譯器擴充套件允許）：每個函式定義都必須出現在檔案作用域中，並且函式無法訪問呼叫者的區域性變數：

```c
int main(void) // the main function definition {  int sum(int, int); // function declaration (may appear at any scope)  int x = 1; // local variable in main  sum(1, 2); // function call // int sum(int a, int b) // error: no nested functions // { // return a + b;  // } } int sum(int a, int b) // function definition { // return x + a + b; // error: main's x is not accessible within sum  return a + b; }
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.7.4 Function declarators (including prototypes) (p: TBD)
6.7.7.4 函式宣告器（包括原型）（p: TBD）
6.7.7.4 函式宣告器（包括原型）（p: TBD）

- 6.9.2 Function definitions (p: TBD)
6.9.2 函式定義（p: TBD）
6.9.2 函式定義（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.6.3 Function declarators (including prototypes) (p: 96-98)
6.7.6.3 函式宣告器（包括原型）（p: 96-98）
6.7.6.3 函式宣告器（包括原型）（p: 96-98）

- 6.9.1 Function definitions (p: 113-115)
6.9.1 函式定義（p: 113-115）
6.9.1 函式定義（p: 113-115）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.6.3 Function declarators (including prototypes) (p: 133-136)
6.7.6.3 函式宣告器（包括原型）（p: 133-136）
6.7.6.3 函式宣告器（包括原型）（p: 133-136）

- 6.9.1 Function definitions (p: 156-158)
6.9.1 函式定義（p: 156-158）
6.9.1 函式定義（p: 156-158）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.5.3 Function declarators (including prototypes) (p: 118-121)
6.7.5.3 函式宣告器（包括原型）（p: 118-121）
6.7.5.3 函式宣告器（包括原型）（p: 118-121）

- 6.9.1 Function definitions (p: 141-143)
6.9.1 函式定義（p: 141-143）
6.9.1 函式定義（p: 141-143）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.4.3 Function declarators (including prototypes)
3.5.4.3 函式宣告器（包括原型）
3.5.4.3 函式宣告器（包括原型）

- 3.7.1 Function definitions
3.7.1 函式定義
3.7.1 函式定義

### See also

C++ documentation for Declaring functions

---
來源頁路徑：`en.cppreference.com/c/language/functions.html`
