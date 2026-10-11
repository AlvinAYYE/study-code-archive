# Storage-class specifiers

> 來源：cppreference C 語言參考文件（離線轉換版）。

Specify *storage duration* and *linkage* of objects and functions:
指定物件和函式的儲存期和連結：

- `**auto**` - automatic duration and no linkage
auto - 自動儲存期，無連結

- `**register**` - automatic duration and no linkage; address of this variable cannot be taken
register - 自動儲存期，無連結；不能取該變數的位址

- `**static**` - static duration and internal linkage (unless at block scope)
static - 靜態儲存期，內部連結（除非在塊作用域中）

- `**extern**` - static duration and external linkage (unless already declared internal)
extern - 靜態儲存期，外部連結（除非已被宣告為內部連結）
auto - 自動儲存期，無連結 register - 自動儲存期，無連結；不能獲取該變數的位址 static - 靜態儲存期，內部連結（除非在塊作用域中） extern - 靜態儲存期，外部連結（除非已宣告為內部連結）

- `**_Thread_local**`(until C23)`**thread_local**`(since C23) - thread storage duration
|   | (since C11) |

### Explanation

Storage-class specifiers appear in declarations and compound literal expressions(since C23). At most one specifier may be used, except that `_Thread_local`(until C23)`thread_local`(since C23) may be combined with `static` or `extern` to adjust linkage(since C11). The storage-class specifiers determine two independent properties of the names they declare: *storage duration* and *linkage*.
儲存類別說明符可用於宣告及複合常值運算式（C23 起）。每個宣告最多使用一個說明符；但 _Thread_local（C23 前）或 thread_local（C23 起）可與 static 或 extern 合用以調整連結性（C11 起）。儲存類別說明符會分別決定名稱的儲存期與連結性。

1) The `auto` specifier is only allowed for objects declared at block scope (except function parameter lists). It indicates automatic storage duration and no linkage, which are the defaults for these kinds of declarations.

2) The `register` specifier is only allowed for objects declared at block scope, including function parameter lists. It indicates automatic storage duration and no linkage (which is the default for these kinds of declarations), but additionally hints the optimizer to store the value of this variable in a CPU register if possible. Regardless of whether this optimization takes place or not, variables declared `register` cannot be used as arguments to the address-of operator, cannot use _Alignas(until C23)alignas(since C23)(since C11), and `register` arrays are not convertible to pointers.

3) The `static` specifier specifies both static storage duration (unless combined with `_Thread_local`)(since C11) and internal linkage (unless used at block scope). It can be used with functions at file scope and with variables at both file and block scope, but not in function parameter lists.

4) The `extern` specifier specifies static storage duration (unless combined with `_Thread_local`(until C23)`thread_local`(since C23))(since C11) and external linkage. It can be used with function and object declarations in both file and block scope (excluding function parameter lists). If `extern` appears on a redeclaration of an identifier that was already declared with internal linkage, the linkage remains internal. Otherwise (if the prior declaration was external, no-linkage, or is not in scope), the linkage is external.

5) `_Thread_local`(until C23)`thread_local`(since C23) indicates *thread storage duration*. It cannot be used with function declarations. If it is used on a declaration of an object, it must be present on every declaration of the same object. If it is used on a block-scope declaration, it must be combined with either `static` or `extern` to decide linkage.
|   | (since C11) |

If no storage-class specifier is provided, the defaults are:
如果未提供儲存類說明符，則預設值為：

`extern` for all functions
所有函式為 extern
`extern` for objects at file scope
檔案作用域物件為 extern
`auto` for objects at block scope
塊作用域物件為 auto

For any struct or union declared with a storage-class specifier, the storage duration (but not linkage) applies to their members, recursively.
對於以任何儲存類說明符宣告的 struct 或 union，其儲存期（而非連結）遞迴地適用於其成員。
Function declarations at block scope can use `extern` or none at all. Function declarations at file scope can use `extern` or `static`.
塊作用域中的函式宣告可以使用 extern 或完全不用說明符。檔案作用域中的函式宣告可以使用 extern 或 static 。
Function parameters cannot use any storage-class specifiers other than `register`. Note that `static` has special meaning in function parameters of array type.
函式參數不能使用 register 以外的任何儲存類說明符。注意，static 在陣列型別的函式參數中具有特殊含義。

### Storage duration
儲存期

Every object has a property called *storage duration*, which limits the object lifetime. There are four kinds of storage duration in C:
每個物件都有一個稱為儲存期的屬性，它限制物件的生存期。C 中有四種儲存期：

- ***automatic*** storage duration. The storage is allocated when the block in which the object was declared is entered and deallocated when it is exited by any means (goto, return, reaching the end). One exception is the VLAs; their storage is allocated when the declaration is executed, not on block entry, and deallocated when the declaration goes out of scope, not when the block is exited(since C99). If the block is entered recursively, a new allocation is performed for every recursion level. All function parameters and non-`static` block-scope objects have this storage duration, as well as compound literals used at block scope(until C23)
自動儲存期：進入宣告該物件的區塊時配置儲存空間，離開區塊時（無論是執行 goto、return 或到達區塊結尾）釋放。VLA 是例外：在執行宣告時配置，離開其作用域時釋放（C99 起）。每次遞迴進入區塊都會重新配置。函式參數、非 static 的區塊作用域物件，以及在區塊作用域使用的複合常值（C23 前）都具有自動儲存期。

- ***static*** storage duration. The storage duration is the entire execution of the program, and the value stored in the object is initialized only once, prior to main function. All objects declared `static` and all objects with either internal or external linkage that aren't declared `_Thread_local`(until C23)`thread_local`(since C23)(since C11) have this storage duration.
靜態儲存期：物件在整個程式執行期間都存在，並在 main 函式開始前初始化一次。所有宣告為 static 的物件，以及具有內部或外部連結且未宣告為 _Thread_local（C23 前）或 thread_local（C23 起；C11 起）的物件，都具有靜態儲存期。
自動儲存期。儲存在進入宣告該物件的塊時分配，並在以任何方式退出該塊（goto、return、到達末尾）時釋放。一個例外是 VLAs；其儲存在執行宣告時分配，而不是在進入塊時分配，並在宣告離開作用域時釋放，而不是在退出塊時釋放（C99 起）。如果遞迴進入塊，則對每個遞迴層級執行新的分配。所有函式參數和非 static 塊作用域物件都具有此儲存期，以及在塊作用域使用的複合字面量（C23 之前）靜態儲存期。儲存期是程式的整個執行過程，物件中儲存的值僅初始化一次，在 main 函式之前。所有宣告為 static 的物件以及所有具有內部或外部連結且未宣告為 _Thread_local（C23 之前）thread_local（C23 起）（C11 起）的物件都具有此儲存期。

- ***thread*** storage duration. The storage duration is the entire execution of the thread in which it was created, and the value stored in the object is initialized when the thread is started. Each thread has its own, distinct, object. If the thread that executes the expression that accesses this object is not the thread that executed its initialization, the behavior is implementation-defined. All objects declared `_Thread_local`(until C23)`thread_local`(since C23) have this storage duration.
|   | (since C11) |

- ***allocated*** storage duration. The storage is allocated and deallocated on request, using dynamic memory allocation functions.
動態分配儲存期。儲存根據請求使用動態記憶體分配函式進行分配和釋放。
動態分配儲存期。儲存根據請求使用動態記憶體分配函式進行分配和釋放。

#### Linkage

Linkage refers to the ability of an identifier (variable or function) to be referred to in other scopes. If a variable or function with the same identifier is declared in several scopes, but cannot be referred to from all of them, then several instances of the variable are generated. The following linkages are recognized:
連結性表示識別字（變數或函式）能否在其他作用域中被引用。同一識別字若在多個作用域宣告，卻無法從所有作用域引用，可能會代表不同的實體。標準定義以下幾種連結性：

- ***no linkage***. The variable or function can be referred to only from the scope it is in (block scope). All block scope variables that are not declared `extern` have this linkage, as well as all function parameters and all identifiers that aren't functions or variables.
無連結。變數或函式只能從其所在的作用域（塊作用域）引用。所有未宣告為 extern 的塊作用域變數，以及所有函式參數和所有不是函式或變數的識別符號都具有此連結。
無連結。變數或函式只能從其所在的作用域（塊作用域）引用。所有未宣告為 extern 的塊作用域變數，以及所有函式參數和所有不是函式或變數的識別符號都具有此連結。

- ***internal linkage***. The variable or function can be referred to from all scopes in the current translation unit. All file scope variables which are declared `static` or `constexpr`(since C23) have this linkage, and all file scope functions declared `static` (static function declarations are only allowed at file scope).
內部連結。變數或函式可以從目前翻譯單元的所有作用域引用。所有宣告為 static 或 constexpr（C23 起）的檔案作用域變數具有此連結，以及所有宣告為 static 的檔案作用域函式（static 函式宣告僅允許在檔案作用域中）。
內部連結。變數或函式可以從目前翻譯單元的所有作用域引用。所有宣告為 static 或 constexpr（C23 起）的檔案作用域變數具有此連結，以及所有宣告為 static 的檔案作用域函式（static 函式宣告僅允許在檔案作用域中）。

- ***external linkage***. The variable or function can be referred to from any other translation units in the entire program. All file scope variables which are not declared `static` or `constexpr`(since C23) have this linkage, all file scope function declarations which are not declared `static`, all block scope function declarations, and, additionally, all variables or functions declared `extern` have this linkage unless a prior declaration with internal linkage is visible at that point.
外部連結。變數或函式可以從整個程式中的任何其他翻譯單元引用。所有未宣告為 static 或 constexpr（C23 起）的檔案作用域變數、所有未宣告為 static 的檔案作用域函式宣告、所有塊作用域函式宣告都具有此連結；此外，所有宣告為 extern 的變數或函式都具有此連結，除非在該點可見的先前宣告具有內部連結。
外部連結。變數或函式可以從整個程式中的任何其他翻譯單元引用。所有未宣告為 static 或 constexpr（C23 起）的檔案作用域變數、所有未宣告為 static 的檔案作用域函式宣告、所有塊作用域函式宣告都具有此連結；此外，所有宣告為 extern 的變數或函式都具有此連結，除非在該點可見的先前宣告具有內部連結。

If the same identifier appears with both internal and external linkage in the same translation unit, the behavior is undefined. This is possible when tentative definitions are used.
如果同一識別符號在同一翻譯單元中同時以內部連結和外部連結出現，則行為未定義。當使用試探定義時可能出現這種情況。

#### Linkage and libraries

|  | This section is incomplete
Reason: should this be a separate top-level entry in c/language under Miscellaneous?  |

Declarations with external linkage are commonly made available in header files so that all translation units that #include the file may refer to the same identifier that are defined elsewhere.
具有外部連結的宣告通常在標頭檔中提供，以便 #include 該檔案的所有翻譯單元都可以引用在其他地方定義的同一識別符號。
Any declaration with internal linkage that appears in a header file results in a separate and distinct object in each translation unit that includes that file.
任何出現在標頭檔中的內部連結宣告都會在包含該檔案的每個翻譯單元中產生一個獨立且不同的物件。

Library interface, header file "flib.h":

```c
#ifndef FLIB_H #define FLIB_H void f(void); // function declaration with external linkage extern int state; // variable declaration with external linkage static const int size = 5; // definition of a read-only variable with internal linkage enum { MAX = 10 }; // constant definition inline int sum (int a, int b) { return a + b; } // inline function definition #endif // FLIB_H
```

Library implementation, source file "flib.c":

```c
#include "flib.h" static void local_f(int s) {} // definition with internal linkage (only used in this file) static int local_state; // definition with internal linkage (only used in this file) int state; // definition with external linkage (used by main.c) void f(void) { local_f(state); } // definition with external linkage (used by main.c)
```

Application code, source file "main.c":

```c
#include "flib.h" int main(void) {  int x[MAX] = {size}; // uses the constant and the read-only variable  state = 7; // modifies state in flib.c  f(); // calls f() in flib.c }
```
|   |  |

### Keywords

auto, register, static, extern, _Thread_local thread_local
auto , register , static , extern , _Thread_local thread_local

### Notes

The keyword `_Thread_local` is usually used through the convenience macro thread_local, defined in the header <threads.h>.
|   | (until C23) |

The typedef and constexpr(since C23) specifiers are formally listed as storage-class specifiers in the C language grammar, but do not specify storage.
typedef 和 constexpr（C23 起）說明符在 C 語言語法中被正式列為儲存類說明符，但並不指定儲存。

The auto specifier is also used for type inference.
|   | (since C23) |

Names at file scope that are `const` and not `extern` have external linkage in C (as the default for all file-scope declarations), but internal linkage in C++.
在檔案作用域中 const 且非 extern 的名稱在 C 中具有外部連結（作為所有檔案作用域宣告的預設值），但在 C++ 中具有內部連結。

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h>   // static storage duration int A;   int main(void) {  printf("&A = %p\n", (void*)&A);    // automatic storage duration  int A = 1; // hides global A  printf("&A = %p\n", (void*)&A);  // allocated storage duration  int* ptr_1 = malloc(sizeof(int)); // start allocated storage duration  printf("address of int in allocated memory = %p\n", (void*)ptr_1);  free(ptr_1); // stop allocated storage duration }
```

Possible output:
可能的輸出：

```c
&A = 0x600ae4 &A = 0x7ffefb064f5c address of int in allocated memory = 0x1f28c30
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.2.2 Linkages of identifiers (p: 35-36)
6.2.2 識別符號的連結（第 35-36 頁）
6.2.2 識別符號的連結（第 35-36 頁）

- 6.2.4 Storage durations of objects (p: 36-37)
6.2.4 物件的儲存期（第 36-37 頁）
6.2.4 物件的儲存期（第 36-37 頁）

- 6.7.1 Storage-class specifiers (p: 97-100)
6.7.1 儲存類說明符（第 97-100 頁）
6.7.1 儲存類說明符（第 97-100 頁）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.2.2 Linkages of identifiers (p: 29-30)
6.2.2 識別符號的連結（第 29-30 頁）
6.2.2 識別符號的連結（第 29-30 頁）

- 6.2.4 Storage durations of objects (p: 30)
6.2.4 物件的儲存期（p: 30）
6.2.4 物件的儲存期（p: 30）

- 6.7.1 Storage-class specifiers (p: 79)
6.7.1 儲存類說明符（第 79 頁）
6.7.1 儲存類說明符（第 79 頁）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.2.2 Linkages of identifiers (p: 36-37)
6.2.2 識別符號的連結（第 36-37 頁）
6.2.2 識別符號的連結（第 36-37 頁）

- 6.2.4 Storage durations of objects (p: 38-39)
6.2.4 物件的儲存期（p: 38-39）
6.2.4 物件的儲存期（p: 38-39）

- 6.7.1 Storage-class specifiers (p: 109-110)
6.7.1 儲存類說明符（第 109-110 頁）
6.7.1 儲存類說明符（第 109-110 頁）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.2.2 Linkages of identifiers (p: 30-31)
6.2.2 識別符號的連結（第 30-31 頁）
6.2.2 識別符號的連結（第 30-31 頁）

- 6.2.4 Storage durations of objects (p: 32)
6.2.4 物件的儲存期（p: 32）
6.2.4 物件的儲存期（p: 32）

- 6.7.1 Storage-class specifiers (p: 98-99)
6.7.1 儲存類說明符（第 98-99 頁）
6.7.1 儲存類說明符（第 98-99 頁）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.1.2.2 Linkages of identifiers
3.1.2.2 識別符號的連結
3.1.2.2 識別符號的連結

- 3.1.2.4 Storage durations of objects
3.1.2.4 物件的儲存期
3.1.2.4 物件的儲存期

- 3.5.1 Storage-class specifiers
3.5.1 儲存類說明符
3.5.1 儲存類說明符

### See also

C++ documentation for Storage class specifiers

---
來源頁路徑：`en.cppreference.com/c/language/storage_duration.html`
