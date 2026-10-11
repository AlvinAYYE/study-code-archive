# Statements

> 來源：cppreference C 語言參考文件（離線轉換版）。

Statements are fragments of the C program that are executed in sequence. The body of any function is a compound statement, which, in turn is a sequence of statements and declarations:
陳述式是按順序執行的 C 程式片段。任何函式的主體都是複合陳述式，它反過來又是陳述式和宣告的序列：

```c
int main(void) { // start of a compound statement  int n = 1; // declaration (not a statement)  n = n+1; // expression statement  printf("n = %d\n", n); // expression statement  return 0; // return statement } // end of compound statement, end of function body
```

There are five types of statements:
陳述式有五種型別：

1) compound statements

2) expression statements

3) selection statements

4) iteration statements

5) jump statements

An attribute specifier sequence (attr-spec-seq) can be applied to an unlabeled statement, in which case (except for an expression statement) the attributes are applied to the respective statement.
|   | (since C23) |

### Labels

Any statement can be *labeled*, by providing a name followed by a colon before the statement itself.
任何陳述式都可以透過在陳述式本身之前提供一個名稱加冒號來擁有標籤。

|   |

| attr-spec-seq(optional)(since C23) identifier `**:**`  |   | (1)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**case**` constant-expression `**:**`  |   | (2)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**default**` `**:**`  |   | (3)  |   |   |

|   |

1) Target for goto.

2) Case label in a switch statement.

3) Default label in a switch statement.

Any statement (but not a declaration) may be preceded by any number of *labels*, each of which declares identifier to be a label name, which must be unique within the enclosing function (in other words, label names have function scope).
任何陳述式（但不是宣告）前面可以有任意數量的標籤，每個標籤將 identifier 宣告為標籤名，標籤名必須在其所在函式內唯一（換句話說，標籤名具有函式作用域）。
Label declaration has no effect on its own, does not alter the flow of control, or modify the behavior of the statement that follows in any way.
標籤宣告本身沒有效果，不會改變控制流，也不會以任何方式修改其後陳述式的行為。

A label shall be followed by a statement.
|   | (until C23) |

A label can appear without its following statement. If a label appears alone in a block, it behaves as if it is followed by a null statement.
The optional attr-spec-seq is applied to the label.
|   | (since C23) |

### Compound statements
複合陳述式

A compound statement, or *block*, is a brace-enclosed sequence of statements and declarations.
複合陳述式（block）是由花括號括起來的陳述式和宣告的序列。

|   |

| `**{**` statement `|` declaration...(optional) `**} **`  |   |   |   | (until C23)  |

|   |

| attr-spec-seq(optional) `**{**` unlabeled-statement `|` label `|` declaration...(optional) `**} **`  |   |   |   | (since C23)  |

|   |

The compound statement allows a set of declarations and statements to be grouped into one unit that can be used anywhere a single statement is expected (for example, in an if statement or an iteration statement):
複合陳述式允許將一組宣告和陳述式分組為一個單元，可以在任何期望單個陳述式的地方使用（例如，在 if 陳述式或迭代陳述式中）：

```c
if (expr) // start of if-statement { // start of block  int n = 1; // declaration  printf("%d\n", n); // expression statement } // end of block, end of if-statement
```

Each compound statement introduces its own block scope.
每個複合陳述式引入其自己的塊作用域。
The initializers of the variables with automatic storage duration declared inside a block and the VLA declarators are executed when flow of control passes over these declarations in order, as if they were statements:
在塊內宣告的自動儲存期變數的初始化器和 VLA 宣告符在控制流按順序經過這些宣告時執行，就好像它們是陳述式一樣：

```c
int main(void) { // start of block  { // start of block  puts("hello"); // expression statement  int n = printf("abc\n"); // declaration, prints "abc", stores 4 in n  int a[n*printf("1\n")]; // declaration, prints "1", allocates 8*sizeof(int)  printf("%zu\n", sizeof(a)); // expression statement  } // end of block, scope of n and a ends  int n = 7; // n can be reused }
```

### Expression statements
表示式陳述式

An expression followed by a semicolon is a statement.
表示式後跟一個分號就是一條陳述式。

|   |

| expression(optional) `**;**`  |   | (1)  |   |   |

|   |

| attr-spec-seq expression `**;**`  |   | (2)  |   | (since C23)  |

|   |

Most statements in a typical C program are expression statements, such as assignments or function calls.
典型 C 程式中的大多數陳述式都是表示式陳述式，如賦值或函式呼叫。
An expression statement without an expression is called a *null statement*. It is often used to provide an empty body to a for or while loop. It can also be used to carry a label in the end of a compound statement or before a declaration:
沒有表示式的表示式陳述式稱為空陳述式。它常用於為 for 或 while 迴圈提供空主體。它也可用於在複合陳述式末尾或宣告之前攜帶標籤：

```c
puts("hello"); // expression statement char *s; while (*s++ != '\0')  ; // null statement
```

The optional attr-spec-seq is applied to the expression.
An attr-spec-seq followed by `**;**` does not form an expression statement. It forms an attribute declaration instead.
|   | (since C23) |

### Selection statements
選擇陳述式

The selection statements choose between one of several statements depending on the value of an expression.
選擇陳述式根據表示式的值在若干陳述式中選擇一個。

|   |

| attr-spec-seq(optional)(since C23) `**if**` `**(**` expression `**)**` statement  |   | (1)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**if**` `**(**` expression `**)**` statement `**else**` statement  |   | (2)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**switch**` `**(**` expression `**)**` statement  |   | (3)  |   |   |

|   |

1) if statement

2) if statement with an else clause

3) switch statement

### Iteration statements
迭代陳述式

The iteration statements repeatedly execute a statement.
迭代陳述式重複執行一條陳述式。

|   |

| attr-spec-seq(optional)(since C23) `**while**` `**(**` expression `**)**` statement  |   | (1)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**do**` statement `**while**` `**(**` expression `**)**` `**;**`  |   | (2)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**for**` `**(**` init-clause `**;**` expression(optional) `**;**` expression(optional) `**)**` statement  |   | (3)  |   |   |

|   |

1) while loop

2) do-while loop

3) for loop

### Jump statements
跳轉陳述式

The jump statements unconditionally transfer flow control.
跳轉陳述式無條件轉移控制流。

|   |

| attr-spec-seq(optional)(since C23) `**break**` `**;**`  |   | (1)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**continue**` `**;**`  |   | (2)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**return**` expression(optional) `**;**`  |   | (3)  |   |   |

|   |

| attr-spec-seq(optional)(since C23) `**goto**` identifier `**;**`  |   | (4)  |   |   |

|   |

1) break statement

2) continue statement

3) return statement with an optional expression

4) goto statement

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.8 Statements and blocks (p: TBD)
6.8 陳述式和塊 (p: TBD)
6.8 陳述式和塊 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.8 Statements and blocks (p: 106-112)
6.8 陳述式和塊 (p: 106-112)
6.8 陳述式和塊 (p: 106-112)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.8 Statements and blocks (p: 146-154)
6.8 陳述式和塊 (p: 146-154)
6.8 陳述式和塊 (p: 146-154)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.8 Statements and blocks (p: 131-139)
6.8 陳述式和塊 (p: 131-139)
6.8 陳述式和塊 (p: 131-139)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.6 STATEMENTS

### See also

C++ documentation for Statements

---
來源頁路徑：`en.cppreference.com/c/language/statements.html`
