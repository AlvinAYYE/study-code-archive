# cast operator

> 來源：cppreference C 語言參考文件（離線轉換版）。

Performs explicit type conversion
執行顯式型別轉換

### Syntax

|   |

| `**(**` type-name `**)**` expression  |   |   |   |   |

|   |

where

| type-name  |   | -  |   | either the type `void` or any scalar type  |

| expression  |   | -  |   | any expression of scalar type (unless type-name is void, in which case it can be anything)  |

### Explanation

If type-name is `void`, then expression is evaluated for its side-effects and its returned value is discarded, same as when expression is used on its own, as an expression statement.
如果 type-name 為 void，則計算 expression 以獲得其副作用，其傳回值被丟棄，與 expression 單獨作為表示式陳述式使用時相同。
Otherwise, if type-name is exactly the type of expression, nothing is done (except that if expression has floating type and is represented with greater range and precision than its type indicates -- see below)
否則，如果 type-name 恰好是 expression 的型別，則不做任何操作（除非 expression 具有浮點型別，且其表示的範圍和精度超出其型別所表明的程度——見下文）
Otherwise, the value of expression is converted to the type named by type-name, as follows:
否則，expression 的值按如下方式轉換為 type-name 所命名的型別：
Every implicit conversion as if by assignment is allowed.
所有如同賦值的隱式轉換都是允許的。
In addition to the implicit conversions, the following conversions are allowed:
除隱式轉換外，還允許以下轉換：

- Any integer can be cast to any pointer type. Except for the null pointer constants such as NULL (which doesn't need a cast), the result is implementation-defined, may not be correctly aligned, may not point to an object of the referenced type, and may be a trap representation.
任何整數都可以轉換為任何指標型別。除 NULL 等空指標常量（不需要 cast）外，結果是實現定義的，可能未正確對齊，可能不指向被引用型別的物件，並且可能是陷阱表示。

- Any pointer type can be cast to any integer type. The result is implementation-defined, even for null pointer values (they do not necessarily result in the value zero). If the result cannot be represented in the target type, the behavior is undefined (unsigned integers do not implement modulo arithmetic on a cast from pointer)
任何指標型別都可以轉換為任何整數型別。結果是實現定義的，即使對於空指標值也是如此（它們不一定產生值零）。如果結果無法在目標型別中表示，則行為是未定義的（無符號整數在從指標轉換時不實現模運算）

- Any pointer to object can be cast to any other pointer to object. If the value is not correctly aligned for the target type, the behavior is undefined. Otherwise, if the value is converted back to the original type, it compares equal to the original value. If a pointer to object is cast to pointer to any character type, the result points at the lowest byte of the object and may be incremented up to sizeof the target type (in other words, can be used to examine object representation or to make a copy via memcpy or memmove).
任何指向物件的指標都可以轉換為任何其他指向物件的指標。如果該值對於目標型別未正確對齊，則行為是未定義的。否則，如果該值轉換回原始型別，則與原始值比較相等。如果指向物件的指標被轉換為指向任何字元型別的指標，結果指向物件的最低位元組，並且可以遞增直到目標型別的 sizeof（換句話說，可用於檢查物件表示或透過 memcpy 或 memmove 複製）。

- Any pointer to function can be cast to a pointer to any other function type. If the resulting pointer is converted back to the original type, it compares equal to the original value. If the converted pointer is used to make a function call, the behavior is undefined (unless the function types are compatible)
任何指向函式的指標都可以轉換為指向任何其他函式型別的指標。如果結果指標轉換回原始型別，則與原始值比較相等。如果轉換後的指標用於進行函式呼叫，則行為是未定義的（除非函式型別相容）

- When casting between pointers (either object or function), if the original value is a null pointer value of its type, the result is the correct null pointer value for the target type.
在指標之間轉換（物件指標或函式指標）時，如果原始值是其型別的空指標值，則結果是目標型別的正確空指標值。

In any case (both when executing an implicit conversion and in the same-type cast), if expression and type-name are floating types and expression is represented with greater range and precision than its type indicates (see FLT_EVAL_METHOD), the range and precision are stripped off to match the target type.
在任何情況下（無論是執行隱式轉換還是同型別轉換），如果 expression 和 type-name 是浮點型別，且 expression 表示的範圍和精度超出其型別所表明的程度（見 FLT_EVAL_METHOD），則範圍和精度會被剝離以匹配目標型別。
The value category of the cast expression is always non-lvalue.
cast 表示式的值類別始終是非左值。

### Notes

Because const, volatile, restrict, and _Atomic qualifiers have effect on lvalues only, a cast to a cvr-qualified or atomic type is exactly equivalent to the cast to the corresponding unqualified type.
由於 const、volatile、restrict 和 _Atomic 限定符僅作用於左值，轉換為 cvr 限定型別或原子型別與轉換為對應的無限定型別完全等價。
The cast to `void` is sometimes useful to silence compiler warnings about unused results.
轉換為 void 有時用於消除編譯器關於未使用結果的警告。
The conversions not listed here are not allowed. In particular,
未在此列出的轉換是不允許的。特別是，

- there are no conversions between pointers and floating types
指標與浮點型別之間沒有轉換

- there are no conversions between pointers to functions and pointers to objects (including `void*`)
函式指標與物件指標之間沒有轉換（包括 void *）

If the implementation provides intptr_t and/or uintptr_t, then a cast from a pointer to an object type (including *cv* `void`) to these types is always well-defined. However, this is not guaranteed for a function pointer.
|   | (since C99) |

Note that conversions between function pointers and object pointers are accepted as extensions by many compilers, and expected by some usages of POSIX `dlsym()` function.
注意，函式指標與物件指標之間的轉換被許多編譯器作為擴充套件接受，並且 POSIX dlsym() 函式的某些用法預期如此。

### Example

Run this code

```c
#include <stdio.h> int main(void) {  // examining object representation is a legitimate use of cast  double d = 3.14;  printf("The double %.2f (%a) is: ", d, d);  for (size_t n = 0; n < sizeof d; ++n)  printf("0x%02x ", ((unsigned char*)&d)[n]);  // edge cases  struct S { int x; } s; // (struct S)s; // error; not a scalar type  // even though casting to the same type does nothing  (void)s; // okay to cast any type to void }
```

Possible output:
可能的輸出：

```c
The double 3.14 (0x1.91eb851eb851fp+1) is: 0x1f 0x85 0xeb 0x51 0xb8 0x1e 0x09 0x40
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.5.4 Cast operators (p: TBD)
6.5.4 強制型別轉換運運算元 (p: TBD)
6.5.4 強制型別轉換運運算元 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.4 Cast operators (p: 65-66)
6.5.4 強制型別轉換運運算元 (p: 65-66)
6.5.4 強制型別轉換運運算元 (p: 65-66)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.4 Cast operators (p: 91)
6.5.4 強制型別轉換運運算元 (p: 91)
6.5.4 強制型別轉換運運算元 (p: 91)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.5.4 Cast operators (p: 81)
6.5.4 強制型別轉換運運算元 (p: 81)
6.5.4 強制型別轉換運運算元 (p: 81)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.3.4 Cast operators
3.3.4 強制型別轉換運運算元
3.3.4 強制型別轉換運運算元

### See also

C++ documentation for explicit type conversion

---
來源頁路徑：`en.cppreference.com/c/language/cast.html`
