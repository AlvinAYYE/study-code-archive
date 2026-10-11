# _Alignas (since C11)(deprecated in C23), alignas (since C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Appears in the declaration syntax as one of the type specifiers to modify the alignment requirement of the object being declared.
作為型別說明符之一出現在宣告語法中，用於修改所宣告物件的對齊要求。

### Syntax

|   |

| `**_Alignas**` `**(**` expression `**)**`  |   | (1)  |   | (since C11)  |

|   |

| `**alignas**` `**(**` expression `**)**`  |   | (2)  |   | (since C23)  |

|   |

| `**_Alignas**` `**(**` type `**)**`  |   | (3)  |   | (since C11)  |

|   |

| `**alignas**` `**(**` type `**)**`  |   | (4)  |   | (since C23)  |

|   |

| expression  |   | -  |   | any integer constant expression whose value is a valid alignment or zero  |

| type  |   | -  |   | any type name  |

The keyword `_Alignas` is also available as convenience macro alignas, available in the header <stdalign.h>.
|   | (until C23) |

### Explanation

The `_Alignas`(until C23)`alignas`(since C23) specifier can only be used when declaring objects that are not bit-fields, and don't have the register storage class. It cannot be used in function parameter declarations, and cannot be used in a typedef.
_Alignas（至 C23 止）alignas（自 C23 起）說明符只能在宣告非位域且不具有 register 儲存類的物件時使用。它不能用於函式參數宣告，也不能用於 typedef。
When used in a declaration, the declared object will have its alignment requirement set to
在宣告中使用時，所宣告物件的對齊要求將被設定為

1,2) the result of the expression, unless it is zero

3,4) the alignment requirement of type, that is, to `_Alignof(type)`(until C23)`alignof(type)`(since C23)

except when this would weaken the alignment the type would have had naturally.
除非這會削弱該型別本應具有的對齊。
If expression evaluates to zero, this specifier has no effect.
如果表示式的值為零，則此說明符沒有效果。
When multiple `_Alignas`(until C23)`alignas`(since C23) specifiers appear in the same declaration, the strictest one is used.
當同一宣告中出現多個 _Alignas（至 C23 止）alignas（自 C23 起）說明符時，使用最嚴格的一個。
`_Alignas`(until C23)`alignas`(since C23) specifier only needs to appear on the definition of an object, but if any declaration uses `_Alignas`(until C23)`alignas`(since C23), it must specify the same alignment as the `_Alignas`(until C23)`alignas`(since C23) on the definition. The behavior is undefined if different translation units specify different alignments for the same object.
_Alignas（至 C23 止）alignas（自 C23 起）說明符只需出現在物件的定義上，但如果任何宣告使用了 _Alignas（至 C23 止）alignas（自 C23 起），它必須指定與定義上的 _Alignas（至 C23 止）alignas（自 C23 起）相同的對齊。如果不同的翻譯單元為同一物件指定不同的對齊，則行為是未定義的。

### Notes

In C++, the `alignas` specifier may also be applied to the declarations of class/struct/union types and enumerations. This is not supported in C, but the alignment of a struct type can be controlled by using `_Alignas`(until C23)`alignas`(since C23) in a member declaration.
在 C++ 中，alignas 說明符也可以應用於類/結構體/聯合體型別和列舉的宣告。C 不支援此用法，但結構體型別的對齊可以透過在成員宣告中使用 _Alignas（至 C23 止）alignas（自 C23 起）來控制。

### Keywords

alignas, _Alignas
alignas, _Alignas

### Example

Run this code

```c
#include <stdalign.h> #include <stdio.h> // every object of type struct sse_t will be aligned to 16-byte boundary // (note: needs support for DR 444) struct sse_t {  alignas(16) float sse_data[4]; }; // every object of type struct data will be aligned to 128-byte boundary struct data {  char x;  alignas(128) char cacheline[128]; // over-aligned array of char,  // not array of over-aligned chars }; int main(void) {  printf("sizeof(data) = %zu (1 byte + 127 bytes padding + 128-byte array)\n",  sizeof(struct data));  printf("alignment of sse_t is %zu\n", alignof(struct sse_t));  alignas(2048) struct data d; // this instance of data is aligned even stricter  (void)d; // suppresses "maybe unused" warning }
```

Output:

```c
sizeof(data) = 256 (1 byte + 127 bytes padding + 128-byte array) alignment of sse_t is 16
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 444  |   | C11  |   | `_Alignas` was not allowed in struct and union members  |   | allowed  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.5 Alignment specifier (p: TBD)
6.7.5 對齊說明符 (p: TBD)
6.7.5 對齊說明符 (p: TBD)

- 6.2.8 Alignment of objects (p: TBD)
6.2.8 物件對齊 (p: TBD)
6.2.8 物件對齊 (p: TBD)

- 7.15 Alignment <stdalign.h> (p: TBD)
7.15 對齊 <stdalign.h> (p: TBD)
7.15 對齊 <stdalign.h> (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.5 Alignment specifier (p: 92)
6.7.5 對齊說明符 (p: 92)
6.7.5 對齊說明符 (p: 92)

- 6.2.8 Alignment of objects (p: 36-37)
6.2.8 物件的對齊 (p: 36-37)
6.2.8 物件的對齊 (p: 36-37)

- 7.15 Alignment <stdalign.h> (p: 196)
7.15 對齊 <stdalign.h> (p: 196)
7.15 對齊 <stdalign.h> (p: 196)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.5 Alignment specifier (p: 127-128)
6.7.5 對齊說明符 (p: 127-128)
6.7.5 對齊說明符 (p: 127-128)

- 6.2.8 Alignment of objects (p: 48-49)
6.2.8 物件的對齊 (p: 48-49)
6.2.8 物件的對齊 (p: 48-49)

- 7.15 Alignment <stdalign.h> (p: 268)
7.15 對齊 <stdalign.h> (p: 268)
7.15 對齊 <stdalign.h> (p: 268)

### See also

max_align_t
(C11)
|   | a type with alignment requirement as great as any other scalar type
(typedef)   |

| _Alignof(until C23)alignof(since C23)  |   | queries alignment requirements of an object
(operator)  |

C++ documentation for `alignas` specifier

---
來源頁路徑：`en.cppreference.com/c/language/alignas.html`
