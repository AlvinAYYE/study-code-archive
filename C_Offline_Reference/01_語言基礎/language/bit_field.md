# Bit-fields

> 來源：cppreference C 語言參考文件（離線轉換版）。

Declares a member with explicit width, in bits. Adjacent bit-field members may be packed to share and straddle the individual bytes.
宣告一個以位為單位的顯式寬度成員。相鄰的位域成員可以被填充以共享並跨越單個位元組。
A bit-field declaration is a struct or union member declaration which uses the following declarator:
位域宣告是使用以下宣告器的結構體或聯合體成員宣告：

|   |

| identifier ﻿(optional) `**:**` width  |   |   |   |   |

|   |

| identifier  |   | -  |   | a name of the bit-field that is being declared. The name is optional: nameless bit-fields introduce the specified number of bits of padding  |

| width  |   | -  |   | an integer constant expression with a value greater or equal to zero and less or equal the number of bits in the underlying type. When greater than zero, this is the number of bits that this bit-field will occupy. The value zero is only allowed for nameless bit-fields and has special meaning: it specifies that the next bit-field in the class definition will begin at an allocation unit's boundary.  |

### Explanation

Bit-fields can have only one of the following (possibly const or volatile qualified) types:
位域只能具有以下（可能帶 const 或 volatile 限定的）型別之一：

- `unsigned int`, for unsigned bit-fields (e.g. `unsigned int b : 3;` has the range `[``0``, ``7``]`)
unsigned int，用於無符號位域（例如 unsigned int b : 3 ; 的範圍是 [ 0 , 7 ]）

- `signed int`, for signed bit-fields (`signed int b : 3;` has the range `[``-4``, ``3``]`)
signed int，用於有符號位域（signed int b : 3 ; 的範圍是 [ -4 , 3 ]）

- `int`, for bit-fields with implementation-defined signedness (note that this differs from the meaning of the keyword `int` everywhere else, where it means "signed int"). For example, `int b : 3;` may have the range of values `[``0``, ``7``]` or `[``-4``, ``3``]`.
int，用於符號性為實現定義的位域（注意，這與關鍵字 int 在其他所有地方的含義不同，在其他地方它表示 "signed int"）。例如，int b : 3 ; 的值範圍可以是 [ 0 , 7 ] 或 [ -4 , 3 ]。

- `_Bool`, for single-bit bit-fields (e.g. `bool x : 1;`) has the range `[``0``, ``1``]` and implicit conversions to and from it follow the boolean conversion rules.
|   | (since C99) |

- bit-precise integer types (e.g. `_BitInt(5) : 4;` has the range `[``-8``, ``7``]` and `unsigned _BitInt(5) : 4;` has the range `[``0``, ``15``]`).
|   | (since C23) |

Additional implementation-defined types may be acceptable. It is also implementation-defined whether a bit-field may have atomic type.(since C11) The number of bits in a bit-field (width) sets the limit to the range of values it can hold:
可以接受額外的實現定義型別。位域是否可以為原子型別也是實現定義的。（自 C11 起）位域中的位數（寬度）設定了它可以容納的值範圍的限制：

Run this code

```c
#include <stdio.h> struct S {  // three-bit unsigned field,  // allowed values are 0...7  unsigned int b : 3; }; int main(void) {  struct S s = {7};  ++s.b; // unsigned overflow  printf("%d\n", s.b); // output: 0 }
```

Multiple adjacent bit-fields are permitted to be (and usually are) packed together:
多個相鄰位域允許（並且通常）被填充在一起：

Run this code

```c
#include <stdio.h> struct S {  // will usually occupy 4 bytes:  // 5 bits: value of b1  // 11 bits: unused  // 6 bits: value of b2  // 2 bits: value of b3  // 8 bits: unused  unsigned b1 : 5, : 11, b2 : 6, b3 : 2; }; int main(void) {  printf("%zu\n", sizeof(struct S)); // usually prints 4 }
```

The special *unnamed bit-field* of width zero breaks up padding: it specifies that the next bit-field begins at the beginning of the next allocation unit:
寬度為零的特殊未命名位域用於打斷填充：它指定下一個位域從下一個分配單元的開始處開始：

Run this code

```c
#include <stdio.h> struct S {  // will usually occupy 8 bytes:  // 5 bits: value of b1  // 27 bits: unused  // 6 bits: value of b2  // 15 bits: value of b3  // 11 bits: unused  unsigned b1 : 5;  unsigned : 0; // starts a new unsigned int  unsigned b2 : 6;  unsigned b3 : 15; }; int main(void) {  printf("%zu\n", sizeof(struct S)); // usually prints 8 }
```

Because bit-fields do not necessarily begin at the beginning of a byte, address of a bit-field cannot be taken. Pointers to bit-fields are not possible. Bit-fields cannot be used with sizeof and _Alignas(since C11)(until C23)alignas(since C23)(since C11).
由於位域不一定從位元組的開始處開始，因此不能取位域的位址。不存在指向位域的指標。位域不能與 sizeof 和 _Alignas（自 C11 起）（至 C23 止）alignas（自 C23 起）（自 C11 起）一起使用。

### Notes

The following usages of bit-fields causes *undefined behavior*:
以下位域的用法會導致未定義行為：

- Calling offsetof on a bit-field.
對位域呼叫 offsetof。

The following properties of bit-fields are *unspecified*:
位域的以下屬性是未指定的：

- Alignment of the allocation unit that holds a bit-field.
容納位域的分配單元的對齊。

The following properties of bit-fields are *implementation-defined*:
位域的以下屬性是實現定義的：

- Whether bit-fields of type `int` are treated as signed or unsigned.
int 型別的位域被視為有符號還是無符號。

- Whether types other than `int`, `signed int`, `unsigned int`, `_Bool`(since C99), and (possibly `unsigned`) `_BitInt(N)`(since C23) are permitted.
是否允許 int、signed int、unsigned int、_Bool（自 C99 起）以及（可能是無符號的）_BitInt(N)（自 C23 起）之外的型別。

- Whether atomic types are permitted.
|   | (since C11) |

- Whether a bit-field can straddle an allocation unit boundary.
位域是否可以跨越分配單元邊界。

- The order of bit-fields within an allocation unit (on some platforms, bit-fields are packed left-to-right, on others right-to-left).
分配單元內位域的順序（在某些平臺上，位域從左到右填充，在其他平臺上從右到左填充）。

Even though the number of bits in the object representation of `_Bool` is at least CHAR_BIT, the width of the bit-field of type `_Bool` cannot be greater than `1`.
|   | (since C99) |

In the C++ programming language, the width of a bit-field can exceed the width of the underlying type (but the extra bits are padding bits), and bit-fields of type `int` are always signed.
在 C++ 程式語言中，位域的寬度可以超過底層型別的寬度（但額外的位是填充位），並且 int 型別的位域始終是有符號的。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.2.1 Structure and union specifiers
6.7.2.1 結構體和聯合體說明符
6.7.2.1 結構體和聯合體說明符

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.2.1 Structure and union specifiers
6.7.2.1 結構體和聯合體說明符
6.7.2.1 結構體和聯合體說明符

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.2.1 Structure and union specifiers
6.7.2.1 結構體和聯合體說明符
6.7.2.1 結構體和聯合體說明符

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.7.2.1 Structure and union specifiers
6.7.2.1 結構體和聯合體說明符
6.7.2.1 結構體和聯合體說明符

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.5.2.1 Structure and union specifiers
3.5.2.1 結構體和聯合體說明符
3.5.2.1 結構體和聯合體說明符

### See also

C++ documentation for Bit-field

---
來源頁路徑：`en.cppreference.com/c/language/bit_field.html`
