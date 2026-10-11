# Scope

> 來源：cppreference C 語言參考文件（離線轉換版）。

Each identifier that appears in a C program is *visible* (that is, may be used) only in some possibly discontiguous portion of the source code called its *scope*.
在 C 程式中出現的每個識別符號只在原始碼的某個可能不連續的部分中可見（即可以使用），該部分稱為其作用域。
Within a scope, an identifier may designate more than one entity only if the entities are in different name spaces.
在一個作用域內，識別符號可以指定多個實體，僅當這些實體位於不同的名字空間時。
C has four kinds of scopes:
C 有四種作用域：

- block scope

- file scope

- function scope

- function prototype scope
函式原型作用域
塊作用域 檔案作用域 函式作用域 函式原型作用域

### Nested scopes

If two different entities named by the same identifier are in scope at the same time, and they belong to the same name space, the scopes are nested (no other form of scope overlap is allowed), and the declaration that appears in the inner scope hides the declaration that appears in the outer scope:
如果由同一識別符號命名的兩個不同實體同時處於作用域內，並且它們屬於同一名字空間，則這些作用域是巢狀的（不允許其他形式的作用域重疊），並且出現在內層作用域中的宣告隱藏出現在外層作用域中的宣告：

```c
// The name space here is ordinary identifiers. int a; // file scope of name a begins here void f(void) {  int a = 1; // the block scope of the name a begins here; hides file-scope a  {  int a = 2; // the scope of the inner a begins here, outer a is hidden  printf("%d\n", a); // inner a is in scope, prints 2  } // the block scope of the inner a ends here  printf("%d\n", a); // the outer a is in scope, prints 1 } // the scope of the outer a ends here void g(int a); // name a has function prototype scope; hides file-scope a
```

### Block scope

The scope of any identifier declared inside a compound statement, including function bodies, or in any expression, declaration, or statement appearing in if, switch, for, while, or do-while statement(since C99), or within the parameter list of a function definition begins at the point of declaration and ends at the end of the block or statement in which it was declared.
在複合陳述式（包括函式體）內宣告的任何識別符號，或在 if、switch、for、while 或 do-while 陳述式（自 C99 起）中出現的任何表示式、宣告或陳述式中宣告的識別符號，或在函式定義的參數列表內宣告的識別符號，其作用域從宣告點開始，到宣告所在的塊或陳述式的末尾結束。

```c
void f(int n) // scope of the function parameter 'n' begins { // the body of the function begins  ++n; // 'n' is in scope and refers to the function parameter // int n = 2; // error: cannot redeclare identifier in the same scope  for(int n = 0; n<10; ++n) { // scope of loop-local 'n' begins  printf("%d\n", n); // prints 0 1 2 3 4 5 6 7 8 9  } // scope of the loop-local 'n' ends  // the function parameter 'n' is back in scope  printf("%d\n", n); // prints the value of the parameter } // scope of function parameter 'n' ends int a = n; // Error: name 'n' is not in scope
```

Until C99, selection and iteration statements did not establish their own block scopes (although if a compound statement was used in the statement, it had its usual block scope):

```c
enum {a, b}; int different(void) {  if (sizeof(enum {b, a}) != sizeof(int))  return a; // a == 1  return b; // b == 0 in C89, b == 1 in C99 }
```
|   | (since C99) |

Block-scope variables have no linkage and automatic storage duration by default. Note that storage duration for non-VLA local variables begins when the block is entered, but until the declaration is seen, the variable is not in scope and cannot be accessed.
塊作用域變數預設沒有連結且具有自動儲存持續時間。注意，非 VLA 區域性變數的儲存持續時間在進入塊時開始，但在看到宣告之前， 變數不在作用域內，不能被訪問。

### File scope

The scope of any identifier declared outside of any block or parameter list begins at the point of declaration and ends at the end of the translation unit.
在任何塊或參數列表之外宣告的任何識別符號，其作用域從宣告點開始，到翻譯單元的末尾結束。

```c
int i; // scope of i begins static int g(int a) { return a; } // scope of g begins (note, "a" has block scope) int main(void) {  i = g(2); // i and g are in scope }
```

File-scope identifiers have external linkage and static storage duration by default.
檔案作用域識別符號預設具有外部連結和靜態儲存持續時間。

### Function scope

A label (and only a label) declared inside a function is in scope everywhere in that function, in all nested blocks, before and after its own declaration. Note: a label is declared implicitly, by using an otherwise unused identifier before the colon character before any statement.
在函式內宣告的標籤（且只有標籤）在該函式的所有巢狀塊中、其自身宣告之前和之後的任何地方都在作用域內。注意：標籤是隱式宣告的，透過在冒號字元之前、任何陳述式之前使用一個未在其他地方使用的識別符號。

```c
void f() {  {   goto label; // label in scope even though declared later label:;  }  goto label; // label ignores block scope } void g() {  goto label; // error: label not in scope in g() }
```

### Function prototype scope
函式原型作用域

The scope of a name introduced in the parameter list of a function declaration that is not a definition ends at the end of the function declarator.
在不是定義的函式宣告中，參數列表中引入的名稱的作用域在函式宣告器的末尾結束。

```c
int f(int n,  int a[n]); // n is in scope and refers to the first parameter
```

Note that if there are multiple or nested declarators in the declaration, the scope ends at the end of the nearest enclosing function declarator:
注意，如果宣告中有多個或巢狀的宣告器，則作用域在最近的外圍函式宣告器的末尾結束：

```c
void f ( // function name 'f' is at file scope  long double f, // the identifier 'f' is now in scope, file-scope 'f' is hidden  char (**a)[10 * sizeof f] // 'f' refers to the first parameter, which is in scope ); enum{ n = 3 }; int (*(*g)(int n))[n]; // the scope of the function parameter 'n'  // ends at the end of its function declarator  // in the array declarator, global n is in scope // (this declares a pointer to function returning a pointer to an array of 3 int)
```

### Point of declaration
宣告點

The scope of structure, union, and enumeration tags begins immediately after the appearance of the tag in a type specifier that declares the tag.
結構體、聯合體和列舉標籤的作用域從宣告該標籤的型別說明符中標籤出現之後立即開始。

```c
struct Node {  struct Node* next; // Node is in scope and refers to this struct };
```

The scope of enumeration constant begins immediately after the appearance of its defining enumerator in an enumerator list.
列舉常量的作用域從列舉列表中其定義列舉項出現之後立即開始。

```c
enum { x = 12 }; {  enum { x = x + 1, // new x is not in scope until the comma, x is initialized to 13  y = x + 1 // the new enumerator x is now in scope, y is initialized to 14  }; }
```

The scope of any other identifier begins just after the end of its declarator and before the initializer, if any:
任何其他識別符號的作用域從其宣告器結束之後、初始化器（如果有）之前開始：

```c
int x = 2; // scope of the first 'x' begins {  int x[x]; // scope of the newly declared x begins after the declarator (x[x]).  // Within the declarator, the outer 'x' is still in scope.  // This declares a VLA array of 2 int. }
```

```c
unsigned char x = 32; // scope of the outer 'x' begins {  unsigned char x = x;  // scope of the inner 'x' begins before the initializer (= x)  // this does not initialize the inner 'x' with the value 32,   // this initializes the inner 'x' with its own, indeterminate, value } unsigned long factorial(unsigned long n) // declarator ends, 'factorial' is in scope from this point {  return n<2 ? 1 : n*factorial(n-1); // recursive call }
```

As a special case, the scope of a type name that is not a declaration of an identifier is considered to begin just after the place within the type name where the identifier would appear were it not omitted.
作為特例，不是識別符號宣告的型別名，其作用域被認為從型別名中該識別符號（如果未省略）本應出現的位置之後立即開始。

### Notes

Prior to C89, identifiers with external linkage had file scope even when introduced within a block, and because of that, a C89 compiler is not required to diagnose the use of an extern identifier that has gone out of scope (such use is undefined behavior).
在 C89 之前，具有外部連結的識別符號即使在塊內引入也具有檔案作用域，因此，C89 編譯器不要求診斷已經離開作用域的 extern 識別符號的使用（這種使用是未定義行為）。
Local variables within a loop body can hide variables declared in the init clause of a for loop in C (their scope is nested), but cannot do that in C++.
與 C++ 不同，C 中迴圈體內的區域性變數可以隱藏 for 迴圈 init 子句中宣告的變數（它們的作用域是巢狀的），但在 C++ 中不能這樣做。
Unlike C++, C has no struct scope: names declared within a struct/union/enum declaration are in the same scope as the struct declaration (except that data members are in their own member name space):
與 C++ 不同，C 沒有結構體作用域：在結構體/聯合體/列舉宣告中宣告的名稱與結構體宣告處於同一作用域中（除了資料成員位於它們自己的成員名字空間中）：

```c
struct foo {  struct baz {};  enum color {RED, BLUE}; }; struct baz b; // baz is in scope enum color x = RED; // color and RED are in scope
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.2.1 Scopes of identifiers, type names, and compound literals (p: TBD)
6.2.1 識別符號、型別名和複合字面量的作用域 (p: TBD)
6.2.1 識別符號、型別名和複合字面量的作用域 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.2.1 Scopes of identifiers (p: 28-29)
6.2.1 識別符號的作用域 (p: 28-29)
6.2.1 識別符號的作用域 (p: 28-29)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.2.1 Scopes of identifiers (p: 35-36)
6.2.1 識別符號的作用域 (p: 35-36)
6.2.1 識別符號的作用域 (p: 35-36)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.2.1 Scopes of identifiers (p: 29-30)
6.2.1 識別符號的作用域 (p: 29-30)
6.2.1 識別符號的作用域 (p: 29-30)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.2.1 Scopes of identifiers
3.1.2.1 識別符號的作用域
3.1.2.1 識別符號的作用域

### See also

C++ documentation for Scope

---
來源頁路徑：`en.cppreference.com/c/language/scope.html`
