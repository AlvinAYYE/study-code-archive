# Initialization

> 來源：cppreference C 語言參考文件（離線轉換版）。

A declaration of an object may provide its initial value through the process known as *initialization*.
物件的宣告可以透過稱為初始化的過程提供其初始值。
For each declarator, the initializer, if not omitted, may be one of the following:
對於每個宣告符，如果不省略初始化器，則可以是以下之一：

|   |

| `**=**` expression  |   | (1)  |   |   |

|   |

| `**=**` `**{**` initializer-list `**}**`  |   | (2)  |   |   |

|   |

| `**=**` `**{**` `**}**`  |   | (3)  |   | (since C23)  |

|   |

where initializer-list is a non-empty comma-separated list of initializer ﻿s (with an optional trailing comma), where each initializer has one of three possible forms:
initializer-list 是非空的初始化器清單，各項以逗號分隔，最後可選擇加上逗號。每個初始化器可採用以下三種形式之一：

|   |

| expression  |   | (1)  |   |   |

|   |

| `**{**` initializer-list `**}**`  |   | (2)  |   |   |

|   |

| `**{**` `**}**`  |   | (3)  |   | (since C23)  |

|   |

| designator-list `**=**` initializer  |   | (4)  |   | (since C99)  |

|   |

where designator-list is a list of either array designators of the form `**[**` constant-expression `**]**` or struct/union member designators of the form `**.**` identifier ﻿; see array initialization and struct initialization.
Note: besides initializers, brace-enclosed initializer-list may appear in compound literals, which are expressions of the form:

|   |

| `**(**` type `**)**` `**{**` initializer-list `**}**`  |   |   |   |   |

|   |

| `**(**` type `**)**` `**{**` `**}**`  |   |   |   | (since C23)  |

|   |
|   | (since C99) |

### Explanation

The initializer specifies the initial value stored in an object.
初始化器指定儲存在物件中的初始值。

#### Explicit initialization

If an initializer is provided, see
如果提供了初始化器，請參閱

- scalar initialization for the initialization of scalar types
用於標量型別初始化的標量初始化

- array initialization for the initialization of array types
用於陣列型別初始化的陣列初始化

- struct initialization for the initialization of struct and union types.
用於 struct 和 union 型別初始化的 struct 初始化。

#### Implicit initialization

If an initializer is not provided:
如果未提供初始化器：

- objects with automatic storage duration are initialized to indeterminate values (which may be trap representations)
具有自動儲存期的物件被初始化為不確定值（可能是陷阱表示）

- objects with static and thread-local storage duration are empty-initialized
具有靜態和執行緒區域性儲存期的物件被空初始化

#### Empty initialization

An object is empty-initialized if it is explicitly initialized from initializer `= {}`.
|   | (since C23) |

In some cases, an object is empty-initialized if it is not initialized explicitly, that is:
在某些情況下，如果物件未顯式初始化，則對其進行空初始化，即：

- pointers are initialized to null pointer values of their types
指標被初始化為其型別的空指標值

- objects of integral types are initialized to unsigned zero
整數型別物件被初始化為無符號零

- objects of floating types are initialized to positive zero
浮點型別物件被初始化為正零

- all elements of arrays, all members of structs, and the first members of unions are empty-initialized, recursively, plus all padding bits are initialized to zero
陣列的所有元素、struct 的所有成員和 union 的第一個成員被遞迴地空初始化，此外所有填充位被初始化為零

(on platforms where null pointer values and floating zeroes have all-bit-zero representations, this form of initialization for statics is normally implemented by allocating them in the .bss section of the program image)
（在空指標值和浮點零值為全零表示的平臺上，靜態物件的這種初始化形式通常透過將其分配在程式映像的 .bss 段中來實現）

### Notes

When initializing an object of static or thread-local storage duration, every expression in the initializer must be a constant expression or string literal.
初始化具有靜態或執行緒區域性儲存期的物件時，初始化器中的每個表示式都必須是常量表示式或字串字面量。
Initializers cannot be used in declarations of objects of incomplete type, VLAs, and block-scope objects with linkage.
初始化器不能用於不完全型別物件、VLAs 和具有連結的塊作用域物件的宣告中。
The initial values of function parameters are established as if by assignment from the arguments of a function call, rather than by initialization.
函式參數的初始值是透過函式呼叫參數的賦值方式確定的，而不是透過初始化。
If an indeterminate value is used as an argument to any standard library call, the behavior is undefined. Otherwise, the result of any expression involving indeterminate values is an indeterminate value (e.g. `int n;`, `n` may not compare equal to itself and it may appear to change its value on subsequent reads)
若將不確定值作為標準函式庫函式的引數，行為未定義。其他情況下，任何涉及不確定值的運算式，其結果仍是不確定值。例如 int n; 中的 n 可能不等於自身，而且每次讀取時看起來都可能不同。

There is no special construct in C corresponding to value initialization in C++; however, `= {0}` (or `(T){0}` in compound literals)(since C99) can be used instead, as the C standard does not allow empty structs, empty unions, or arrays of zero length.
|   | (until C23) |

The empty initializer `= {}` (or `(T){}` in compound literals) can be used to achieve the same semantics as value initialization in C++.
|   | (since C23) |

### Example

Run this code

```c
#include <stdlib.h> int a[2]; // initializes a to {0, 0} int main(void) {  int i; // initializes i to an indeterminate value  static int j; // initializes j to 0  int k = 1; // initializes k to 1  // initializes int x[3] to 1,3,5  // initializes int* p to &x[0]  int x[] = { 1, 3, 5 }, *p = x;  // initializes w (an array of two structs) to  // { { {1,0,0}, 0}, { {2,0,0}, 0} }  struct {int a[3], b;} w[] = {[0].a = {1}, [1].a[0] = 2};  // function call expression can be used for a local variable  char* ptr = malloc(10);  free(ptr); // Error: objects with static storage duration require constant initializers // static char* ptr = malloc(10); // Error: VLA cannot be initialized // int vla[n] = {0}; }
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.9 Initialization (p: 100-105)
6.7.9 初始化（第 100-105 頁）
6.7.9 初始化（第 100-105 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.9 Initialization (p: 139-144)
6.7.9 初始化（第 139-144 頁）
6.7.9 初始化（第 139-144 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.8 Initialization (p: 125-130)
6.7.8 初始化（第 125-130 頁）
6.7.8 初始化（第 125-130 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 6.5.7 Initialization
6.5.7 初始化
6.5.7 初始化

### See also

C++ documentation for Initialization

---
來源頁路徑：`en.cppreference.com/c/language/initialization.html`
