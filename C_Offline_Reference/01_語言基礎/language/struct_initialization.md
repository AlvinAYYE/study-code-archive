# Struct and union initialization

> 來源：cppreference C 語言參考文件（離線轉換版）。

When initializing an object of struct or union type, the initializer must be a non-empty,(until C23) brace-enclosed, comma-separated list of initializers for the members:
初始化 struct 或 union 型別的物件時，初始化器必須是成員初始化器的非空、（C23 之前）花括號括起來的、逗號分隔的列表：

|   |

| `**=**` `**{**` expression `**,**` `**...**` `**}**`  |   | (1)  |   | (until C99)  |

|   |

| `**=**` `**{**` designator(optional) expression `**,**` `**...**` `**}**`  |   | (2)  |   | (since C99)  |

|   |

| `**=**` `**{**` `**}**`  |   | (3)  |   | (since C23)  |

|   |

where the designator is a sequence (whitespace-separated or adjacent) of individual member designators of the form `**.**` member and array designators of the form `**[**` index `**]**`.
其中指定符是 . member 形式的各個成員指定符和 [ index ] 形式的陣列指定符的序列（以空白分隔或相鄰）。
All members that are not initialized explicitly are empty-initialized.
所有未顯式初始化的成員都進行空初始化。

### Explanation

When initializing a union, the initializer list must have only one member, which initializes the first member of the union unless a designated initializer is used(since C99).
初始化 union 時，初始化器列表只能有一個成員，該成員初始化 union 的第一個成員，除非使用指定初始化器（C99 起）。

```c
union { int x; char c[4]; }  u = {1}, // makes u.x active with value 1  u2 = { .c={'\1'} }; // makes u2.c active with value {'\1','\0','\0','\0'}
```

When initializing a struct, the first initializer in the list initializes the first declared member (unless a designator is specified)(since C99), and all subsequent initializers without designators (since C99)initialize the struct members declared after the one initialized by the previous expression.
初始化 struct 時，列表中的第一個初始化器初始化第一個宣告的成員（除非指定了指定符）（C99 起），所有後續無指定符的初始化器（C99 起）初始化在前一個表示式初始化的成員之後宣告的 struct 成員。

```c
struct point {double x,y,z;} p = {1.2, 1.3}; // p.x=1.2, p.y=1.3, p.z=0.0 div_t answer = {.quot = 2, .rem = -1 }; // order of elements in div_t may vary
```

A designator causes the following initializer to initialize the struct member described by the designator. Initialization then continues forward in order of declaration, beginning with the next element declared after the one described by the designator.

```c
struct {int sec,min,hour,day,mon,year;} z  = {.day=31,12,2014,.sec=30,15,17}; // initializes z to {30,15,17,31,12,2014}
```
|   | (since C99) |

It's an error to provide more initializers than members.
提供的初始化器多於成員數是錯誤的。

### Nested initialization
巢狀初始化

If the members of the struct or union are arrays, structs, or unions, the corresponding initializers in the brace-enclosed list of initializers are any initializers that are valid for those members, except that their braces may be omitted as follows:
如果 struct 或 union 的成員是陣列、struct 或 union，則花括號括起來的初始化器列表中相應的初始化器是對這些成員有效的任何初始化器，但其花括號可以按如下方式省略：
If the nested initializer begins with an opening brace, the entire nested initializer up to its closing brace initializes the corresponding member object. Each left opening brace establishes a new *current object*. The members of the current object are initialized in their natural order, unless designators are used(since C99): array elements in subscript order, struct members in declaration order, only the first declared member of any union. The subobjects within the current object that are not explicitly initialized by the closing brace are empty-initialized.
如果巢狀初始化器以左花括號開始，則從開始到右花括號的整個巢狀初始化器初始化相應的成員物件。每個左花括號建立一個新的目前物件。目前物件的成員按其自然順序初始化，除非使用指定符（C99 起）：陣列元素按下標順序，struct 成員按宣告順序，union 僅第一個宣告的成員。目前物件中未由右花括號顯式初始化的子物件進行空初始化。

```c
struct example {  struct addr_t {  uint32_t port;  } addr;  union {  uint8_t a8[4];  uint16_t a16[2];  } in_u; }; struct example ex = { // start of initializer list for struct example  { // start of initializer list for ex.addr  80 // initialized struct's only member  }, // end of initializer list for ex.addr  { // start of initializer-list for ex.in_u  {127,0,0,1} // initializes first element of the union  } };
```

If the nested initializer does not begin with an opening brace, only enough initializers from the list are taken to account for the elements or members of the member array, struct or union; any remaining initializers are left to initialize the next struct member:
如果巢狀初始化器不以左花括號開始，則只從列表中取出足夠數量的初始化器來解釋成員陣列、struct 或 union 的元素或成員；其餘初始化器留給下一個 struct 成員初始化：

```c
struct example ex = {80, 127, 0, 0, 1}; // 80 initializes ex.addr.port  // 127 initializes ex.in_u.a8[0]  // 0 initializes ex.in_u.a8[1]  // 0 initializes ex.in_u.a8[2]  // 1 initializes ex.in_u.a8[3]
```

When designators are nested, the designators for the members follow the designators for the enclosing structs/unions/arrays. Within any nested bracketed initializer list, the outermost designator refers to the *current object* and selects the subobject to be initialized within the *current object* only.

```c
struct example ex2 = { // current object is ex2, designators are for members of example  .in_u.a8[0]=127, 0, 0, 1, .addr=80};  struct example ex3 = {80, .in_u={ // changes current object to the union ex.in_u  127,  .a8[2]=1 // this designator refers to the member of in_u  } };
```

If any subobject is explicitly initialized twice (which may happen when designators are used), the initializer that appears later in the list is the one used (the earlier initializer may not be evaluated):

```c
struct {int n;} s = {printf("a\n"), // this may be printed or skipped  .n=printf("b\n")}; // always printed
```

Although any non-initialized subobjects are initialized implicitly, implicit initialization of a subobject never overrides explicit initialization of the same subobject if it appeared earlier in the initializer list:

Run this code

```c
#include <stdio.h> typedef struct { int k; int l; int a[2]; } T; typedef struct { int i; T t; } S; T x = {.l = 43, .k = 42, .a[1] = 19, .a[0] = 18 };  // x initialized to {42, 43, {18, 19} } int main(void) {  S l = { 1, // initializes l.i to 1  .t = x, // initializes l.t to {42, 43, {18, 19} }  .t.l = 41, // changes l.t to {42, 41, {18, 19} }  .t.a[1] = 17 // changes l.t to {42, 41, {18, 17} }  };  printf("l.t.k is %d\n", l.t.k); // .t = x sets l.t.k to 42 explicitly  // .t.l = 41 would zero out l.t.k implicitly }
```

Output:

```c
l.t.k is 42
```

However, when an initializer begins with a left open brace, its *current object* is fully re-initialized and any prior explicit initializers for any of its subobjects are ignored:

```c
struct fred { char s[4]; int n; }; struct fred x[ ] = { { { "abc" }, 1 }, // inits x[0] to { {'a','b','c','\0'}, 1 }  [0].s[0] = 'q' // changes x[0] to { {'q','b','c','\0'}, 1 }  }; struct fred y[ ] = { { { "abc" }, 1 }, // inits y[0] to { {'a','b','c','\0'}, 1 }  [0] = { // current object is now the entire y[0] object  .s[0] = 'q'   } // replaces y[0] with { {'q','\0','\0','\0'}, 0 }  };
```
|   | (since C99) |

### Notes

The initializer list may have a trailing comma, which is ignored.
初始化器列表可以有尾隨逗號，它會被忽略。

```c
struct {double x,y;} p = {1.0,  2.0, // trailing comma OK  };
```

In C, the braced list of initializers cannot be empty (note that C++ allows empty lists, and also note that a struct in C cannot be empty):
|   | (until C23) |

The initializer list can be empty in C as in C++:
|   | (since C23) |

```c
struct {int n;} s = {0}; // OK struct {int n;} s = {}; // Error until C23: initializer-list cannot be empty  // OK since C23: s.n is initialized to 0 struct {} s = {}; // Error: struct cannot be empty
```

Every expression in the initializer list must be a constant expression when initializing aggregates of any storage duration.
|   | (until C99) |

As with all other initialization, every expression in the initializer list must be a constant expression when initializing aggregates of static or thread-local(since C11) storage duration:

```c
static struct {char* p} s = {malloc(1)}; // error
```

The order of evaluation of the subexpressions in any initializer is indeterminately sequenced (but not in C++ since C++11):

```c
int n = 1; struct {int x,y;} p = {n++, n++}; // unspecified, but well-defined behavior:  // n is incremented twice in arbitrary order  // p equal {1,2} and {2,1} are both valid
```
|   | (since C99) |

### Example

|  | This section is incomplete
Reason: more practical examples, perhaps initialize some socket structs  |

Run this code

```c
#include <stdio.h> #include <time.h> int main(void) {  char buff[70];  // designated initializers simplify the use of structs whose  // order of members is unspecified  struct tm my_time = { .tm_year=2012-1900, .tm_mon=9, .tm_mday=9,  .tm_hour=8, .tm_min=10, .tm_sec=20 };  strftime(buff, sizeof buff, "%A %c", &my_time);  puts(buff); }
```

Possible output:
可能的輸出：

```c
Sunday Sun Oct 9 08:10:20 2012
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.9/12-39 Initialization (p: 101-105)
6.7.9/12-39 初始化（p: 101-105）
6.7.9/12-39 初始化（p: 101-105）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.9/12-38 Initialization (p: 140-144)
6.7.9/12-38 初始化（p: 140-144）
6.7.9/12-38 初始化（p: 140-144）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.8/12-38 Initialization (p: 126-130)
6.7.8/12-38 初始化（p: 126-130）
6.7.8/12-38 初始化（p: 126-130）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 6.5.7 Initialization
6.5.7 初始化
6.5.7 初始化

### See also

C++ documentation for Aggregate initialization

---
來源頁路徑：`en.cppreference.com/c/language/struct_initialization.html`
