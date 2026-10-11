# Array initialization

> 來源：cppreference C 語言參考文件（離線轉換版）。

When initializing an object of array type, the initializer must be either a string literal (optionally enclosed in braces) or be a brace-enclosed list of initialized for array members:
初始化陣列型別物件時，初始化器必須是字串字面量（可以選擇包含在大括號中），或者是用於陣列成員的大括號括起來的初始化器列表：

|   |

| `**=**` string-literal  |   | (1)  |   |   |

|   |

| `**=**` `**{**` expression `**,**` `**...**` `**}**`  |   | (2)  |   | (until C99)  |

|   |

| `**=**` `**{**` designator(optional) expression `**,**` `**...**` `**}**`  |   | (2)  |   | (since C99)  |

|   |

| `**=**` `**{**` `**}**`  |   | (3)  |   | (since C23)  |

|   |

1) string literal initializer for character and wide character arrays

2) comma-separated list of constant(until C99) expressions that are initializers for array elements, optionally using array designators of the form `**[**` constant-expression `**]**` `**=**` (since C99)

3) empty initializer empty-initializes every element of the array

Arrays of known size and arrays of unknown size may be initialized, but not VLAs(since C99)(until C23). A VLA can only be empty-initialized.(since C23)
已知大小的陣列和未知大小的陣列可以初始化，但 VLA 不可以（C99 起）（C23 之前）。VLA 只能進行空初始化。（C23 起）
All array elements that are not initialized explicitly are empty-initialized.
所有未顯式初始化的陣列元素都會進行空初始化。

### Initialization from strings
從字串初始化

String literal (optionally enclosed in braces) may be used as the initializer for an array of matching type:
字串字面量（可以選擇包含在大括號中）可用作匹配型別陣列的初始化器：

- ordinary string literals and UTF-8 string literals(since C11) can initialize arrays of any character type (`char`, `signed char`, `unsigned char`)
普通字串字面量和 UTF-8 字串字面量（C11 起）可以初始化任何字元型別（char、signed char、unsigned char）的陣列

- L-prefixed wide string literals can be used to initialize arrays of any type compatible with (ignoring cv-qualifications) wchar_t
L 字首寬字串字面量可用於初始化任何與 wchar_t 相容（忽略 cv 限定）的陣列

- u-prefixed wide string literals can be used to initialize arrays of any type compatible with (ignoring cv-qualifications) char16_t

- U-prefixed wide string literals can be used to initialize arrays of any type compatible with (ignoring cv-qualifications) char32_t
|   | (since C11) |

Successive bytes of the string literal or wide characters of the wide string literal, including the terminating null byte/character, initialize the elements of the array:
字串字面量的連續位元組或寬字串字面量的寬字元（包括終止空位元組/字元）初始化陣列的元素：

```c
char str[] = "abc"; // str has type char[4] and holds 'a', 'b', 'c', '\0' wchar_t wstr[4] = L"猫"; // str has type wchar_t[4] and holds L'猫', '\0', '\0', '\0'
```

If the size of the array is known, it may be one less than the size of the string literal, in which case the terminating null character is ignored:
如果陣列大小已知，它可以比字串字面量的大小少一，此時終止空字元被忽略：

```c
char str[3] = "abc"; // str has type char[3] and holds 'a', 'b', 'c'
```

Note that the contents of such array are modifiable, unlike when accessing a string literal directly with `char* str = "abc";`.
注意，這種陣列的內容是可修改的，這與直接用 char * str = "abc" ; 訪問字串字面量不同。

### Initialization from brace-enclosed lists
從大括號列表初始化

When an array is initialized with a brace-enclosed list of initializers, the first initializer in the list initializes the array element at index zero (unless a designator is specified)(since C99), and each subsequent initializer without a designator (since C99)initializes the array element at index one greater than the one initialized by the previous initializer.
當陣列用大括號括起來的初始化器列表初始化時，列表中的第一個初始化器初始化索引為零的陣列元素（除非指定了設計符）（C99 起），每個後續沒有設計符的初始化器（C99 起）初始化比前一個初始化器所初始化元素索引大一的陣列元素。

```c
int x[] = {1,2,3}; // x has type int[3] and holds 1,2,3 int y[5] = {1,2,3}; // y has type int[5] and holds 1,2,3,0,0 int z[4] = {1}; // z has type int[4] and holds 1,0,0,0 int w[3] = {0}; // w has type int[3] and holds all zeroes
```

It's an error to provide more initializers than elements when initializing an array of known size (except when initializing character arrays from string literals).
初始化已知大小的陣列時，提供的初始化器數量多於元素數量是錯誤的（從字串字面量初始化字元陣列除外）。

A designator causes the following initializer to initialize of the array element described by the designator. Initialization then continues forward in order, beginning with the next element after the one described by the designator.

```c
int n[5] = {[4]=5,[0]=1,2,3,4}; // holds 1,2,3,4,5 int a[MAX] = { // starts initializing a[0] = 1, a[1] = 3, ...  1, 3, 5, 7, 9, [MAX-5] = 8, 6, 4, 2, 0 }; // for MAX=6, array holds 1,8,6,4,2,0 // for MAX=13, array holds 1,3,5,7,9,0,0,0,8,6,4,2,0 ("sparse array")
```
|   | (since C99) |

When initializing an array of unknown size, the largest subscript for which an initializer is specified determines the size of the array being declared.
初始化未知大小的陣列時，指定了初始化器的最大下標決定所宣告陣列的大小。

### Nested arrays

If the elements of an array are arrays, structs, or unions, the corresponding initializers in the brace-enclosed list of initializers are any initializers that are valid for those members, except that their braces may be omitted as follows:
如果陣列的元素是陣列、struct 或 union，則大括號初始化器列表中相應的初始化器是適用於這些成員的任何初始化器，但可以省略其花括號如下：
If the nested initializer begins with an opening brace, the entire nested initializer up to its closing brace initializes the corresponding array element:
如果巢狀初始化器以左花括號開頭，則直到其右花括號的整個巢狀初始化器初始化相應的陣列元素：

```c
int y[4][3] = { // array of 4 arrays of 3 ints each (4x3 matrix)  { 1 }, // row 0 initialized to {1, 0, 0}  { 0, 1 }, // row 1 initialized to {0, 1, 0}  { [2]=1 }, // row 2 initialized to {0, 0, 1} }; // row 3 initialized to {0, 0, 0}
```

If the nested initializer does not begin with an opening brace, only enough initializers from the list are taken to account for the elements or members of the sub-array, struct or union; any remaining initializers are left to initialize the next array element:
如果巢狀初始化器不以左花括號開頭，則只從列表中取出足夠的初始化器，用於初始化子陣列、結構體或聯合體的元素或成員；剩餘的初始化器將留給下一個陣列元素進行初始化：

```c
int y[4][3] = { // array of 4 arrays of 3 ints each (4x3 matrix) 1, 3, 5, 2, 4, 6, 3, 5, 7 // row 0 initialized to {1, 3, 5} }; // row 1 initialized to {2, 4, 6}  // row 2 initialized to {3, 5, 7}  // row 3 initialized to {0, 0, 0} struct { int a[3], b; } w[] = { { 1 }, 2 }; // array of structs  // { 1 } is taken to be a fully-braced initializer for element #0 of the array  // that element is initialized to { {1, 0, 0}, 0}  // 2 is taken to be the first initialized for element #1 of the array  // that element is initialized { {2, 0, 0}, 0}
```

Array designators may be nested; the bracketed constant expression for nested arrays follows the bracketed constant expression for the outer array:

```c
int y[4][3] = {[0][0]=1, [1][1]=1, [2][0]=1}; // row 0 initialized to {1, 0, 0}  // row 1 initialized to {0, 1, 0}  // row 2 initialized to {1, 0, 0}  // row 3 initialized to {0, 0, 0}
```
|   | (since C99) |

### Notes

The order of evaluation of subexpressions in an array initializer is indeterminately sequenced in C (but not in C++ since C++11):
在 C 中，陣列初始化器中子表示式的求值順序是未確定序列的（但在 C++ 中，自 C++11 起並非如此）：

```c
int n = 1; int a[2] = {n++, n++}; // unspecified, but well-defined behavior,  // n is incremented twice (in arbitrary order)  // a initialized to {1, 2} and to {2, 1} are both valid puts((char[4]){'0'+n} + n++); // undefined behavior:  // increment and read from n are unsequenced
```

In C, the braced list of an initializer cannot be empty. C++ allows empty list:
|   | (until C23) |

An empty initializer can be used to initialize an array:
|   | (since C23) |

```c
int a[3] = {0}; // valid C and C++ way to zero-out a block-scope array int a[3] = {}; // valid C++ way to zero-out a block-scope array; valid in C since C23
```

As with all other initialization, every expression in the initializer list must be a constant expression when initializing arrays of static or thread-local storage duration:
與所有其他初始化一樣，當初始化具有靜態儲存期或執行緒區域性儲存期的陣列時，初始化器列表中的每個表示式都必須是常量表示式：

```c
static char* p[2] = {malloc(1), malloc(2)}; // error
```

### Example

Run this code

```c
int main(void) {  // The following four array declarations are the same  short q1[4][3][2] = {  { 1 },  { 2, 3 },  { 4, 5, 6 }  };  short q2[4][3][2] = {1, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 4, 5, 6};  short q3[4][3][2] = {  {  { 1 },  },  {  { 2, 3 },  },  {  { 4, 5 },  { 6 },  }  };  short q4[4][3][2] = {1, [1]=2, 3, [2]=4, 5, 6};  // Character names can be associated with enumeration constants  // using arrays with designators:  enum { RED, GREEN, BLUE };  const char *nm[] = {  [RED] = "red",  [GREEN] = "green",  [BLUE] = "blue",  }; }
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

---
來源頁路徑：`en.cppreference.com/c/language/array_initialization.html`
