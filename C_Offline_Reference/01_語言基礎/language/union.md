# Union declaration

> 來源：cppreference C 語言參考文件（離線轉換版）。

A union is a type consisting of a sequence of members whose storage overlaps (as opposed to struct, which is a type consisting of a sequence of members whose storage is allocated in an ordered sequence). The value of at most one of the members can be stored in a union at any one time.
union 是一種由一系列成員組成的型別，這些成員的儲存空間相互重疊（與 struct 相對，struct 是一種由一系列成員組成的型別，其儲存空間按順序分配）。在任何時刻，union 中最多隻能儲存其中一個成員的值。
The type specifier for a union is identical to the struct type specifier except for the keyword used:
union 的型別說明符與 struct 型別說明符相同，只是所使用的關鍵字不同：

### Syntax

|   |

| `**union**` attr-spec-seq ﻿(optional) name ﻿(optional) `**{**` struct-declaration-list `**}**`  |   | (1)  |   |   |

|   |

| `**union**` attr-spec-seq ﻿(optional) name  |   | (2)  |   |   |

|   |

| name  |   | -  |   | the name of the union that's being defined  |

| struct-declaration-list  |   | -  |   | any number of variable declarations, bit-field declarations, and static assert declarations. Members of incomplete type and members of function type are not allowed.  |

| attr-spec-seq  |   | -  |   | (C23)optional list of attributes, applied to the union type, not allowed for (2) if such form is not followed by a `**;**` (i.e. not a forward declaration).  |

### Explanation

The union is only as big as necessary to hold its largest member (additional unnamed trailing padding may also be added). The other members are allocated in the same bytes as part of that largest member.
union 的大小僅以容納其最大成員所需的大小為限（也可能新增額外的未命名尾部填充）。其他成員被分配在與該最大成員相同的位元組中。
A pointer to a union can be cast to a pointer to each of its members (if a union has bit-field members, the pointer to a union can be cast to the pointer to the bit-field's underlying type). Likewise, a pointer to any member of a union can be cast to a pointer to the enclosing union.
指向 union 的指標可以轉換為指向其每個成員的指標（如果 union 具有位域成員，則指向 union 的指標可以轉換為指向該位域底層型別的指標）。類似地，指向 union 任意成員的指標可以轉換為指向外層 union 的指標。

If the member used to access the contents of a union is not the same as the member last used to store a value, the object representation of the value that was stored is reinterpreted as an object representation of the new type (this is known as *type punning*). If the size of the new type is larger than the size of the last-written type, the contents of the excess bytes are unspecified (and may be a trap representation). Before C99 TC3 (DR 283) this behavior was undefined, but commonly implemented this way.
|   | (since C99) |

Similar to struct, an unnamed member of a union whose type is a union without name is known as *anonymous union*. Every member of an anonymous union is considered to be a member of the enclosing struct or union keeping their union layout. This applies recursively if the enclosing struct or union is also anonymous.

```c
struct v {  union // anonymous union  {  struct { int i, j; }; // anonymous structure  struct { long k, l; } w;  };  int m; } v1; v1.i = 2; // valid v1.k = 3; // invalid: inner structure is not anonymous v1.w.k = 5; // valid
```

Similar to struct, the behavior of the program is undefined if union is defined without any named members (including those obtained via anonymous nested structs or unions).
|   | (since C11) |

### Keywords

union

### Notes

See struct initialization for the rules about initialization of structs and unions.
有關結構體和聯合體初始化規則，請參見 struct 初始化。

### Example

Run this code

```c
#include <assert.h> #include <stdint.h> #include <stdio.h> int main(void) {  union S  {  uint32_t u32;  uint16_t u16[2];  uint8_t u8;  } s = {0x12345678}; // s.u32 is now the active member  printf("Union S has size %zu and holds %x\n", sizeof s, s.u32);  s.u16[0] = 0x0011; // s.u16 is now the active member  // reading from s.u32 or from s.u8 reinterprets the object representation // printf("s.u8 is now %x\n", s.u8); // unspecified, typically 11 or 00 // printf("s.u32 is now %x\n", s.u32); // unspecified, typically 12340011 or 00115678  // pointers to all members of a union compare equal to themselves and the union  assert((uint8_t*)&s == &s.u8);  // this union has 3 bytes of trailing padding  union pad  {  char c[5]; // occupies 5 bytes  float f; // occupies 4 bytes, imposes alignment 4  } p = { .f = 1.23 }; // the size is 8 to satisfy float's alignment  printf("size of union of char[5] and float is %zu\n", sizeof p); }
```

Possible output:
可能的輸出：

```c
Union S has size 4 and holds 12345678 size of union of char[5] and float is 8
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 499  |   | C11  |   | members of anonymous structs/unions were considered members of the enclosing struct/union  |   | they retain their memory layout  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.2.1 Structure and union specifiers (p: TBD)
6.7.2.1 結構體和聯合體說明符 (p: TBD)
6.7.2.1 結構體和聯合體說明符 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.2.1 Structure and union specifiers (p: 81-84)
6.7.2.1 結構體和聯合體說明符 (p: 81-84)
6.7.2.1 結構體和聯合體說明符 (p: 81-84)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.2.1 Structure and union specifiers (p: 112-117)
6.7.2.1 結構體和聯合體說明符 (p: 112-117)
6.7.2.1 結構體和聯合體說明符 (p: 112-117)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.2.1 Structure and union specifiers (p: 101-104)
6.7.2.1 結構體和聯合體說明符 (p: 101-104)
6.7.2.1 結構體和聯合體說明符 (p: 101-104)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.2.1 Structure and union specifiers
3.5.2.1 結構體和聯合體說明符
3.5.2.1 結構體和聯合體說明符

### See also

C++ documentation for Union declaration

---
來源頁路徑：`en.cppreference.com/c/language/union.html`
