# Objects and alignment

> 來源：cppreference C 語言參考文件（離線轉換版）。

C programs create, destroy, access, and manipulate objects.
C 程式建立、銷燬、訪問和操作物件。
An object in C is a region of data storage in the execution environment, the contents of which can represent *values* (a value is the meaning of the contents of an object, when interpreted as having a specific type).
C 中的物件是執行環境中的一個資料儲存區域，其內容可以表示值（值是在解釋為具有特定型別時物件內容的含義）。
Every object has
每個物件都有

- size (can be determined with sizeof)
大小（可以用 sizeof 確定）

- alignment requirement(can be determined by _Alignof(until C23)alignof(since C23))(since C11)
對齊要求（可以由 _Alignof （C23 之前）alignof （C23 起）確定）（C11 起）

- storage duration (automatic, static, allocated, thread-local)
儲存期（自動、靜態、分配、執行緒區域性）

- lifetime (equal to storage duration or temporary)
生命週期（等於儲存期或臨時）

- effective type (see below)
有效型別（見下文）

- value (which may be indeterminate)
值（可能是不確定的）

- optionally, an identifier that denotes this object.
可選地，一個表示該物件的識別符號。

Objects are created by declarations, allocation functions, string literals, compound literals, and by non-lvalue expressions that return structures or unions with array members.
物件由宣告、分配函式、字串字面量、複合字面量以及傳回帶有陣列成員的結構或聯合的非左值表示式建立。

### Object representation
物件表示

Except for bit-fields, objects are composed of contiguous sequences of one or more bytes, each consisting of CHAR_BIT bits, and can be copied with memcpy into an object of type `unsigned char[n]`, where `n` is the size of the object. The contents of the resulting array are known as *object representation*.
除了位元欄位以外，物件由一段連續的位元組序列組成，每個位元組含有 CHAR_BIT 個位元。物件可用 memcpy 複製到型別為 unsigned char [ n ] 的物件中，其中 n 是原物件的大小；複製後陣列中的內容稱為物件表示。
If two objects have the same object representation, they compare equal (except if they are floating-point NaNs). The reverse is not true: two objects that compare equal may have different object representations because not every bit of the object representation needs to participate in the value. Such bits may be used for padding to satisfy alignment requirement, for parity checks, to indicate trap representations, etc.
兩個物件若具有相同的物件表示，通常會比較相等（浮點數 NaN 除外）。反過來則不一定成立：比較相等的物件可能有不同的物件表示，因為表示中的每個位元不一定都用來表示值；有些位元可能用於對齊填補、同位檢查或標示陷阱表示等。
If an object representation does not represent any value of the object type, it is known as *trap representation*. Accessing a trap representation in any way other than reading it through an lvalue expression of character type is undefined behavior. The value of a structure or union is never a trap representation even if any particular member is one.
若物件表示不代表該物件型別的任何值，就稱為陷阱表示。除透過字元型別的左值運算式讀取外，以任何方式存取陷阱表示都會造成未定義行為。結構或聯合本身的值不會是陷阱表示，即使其中某個成員是陷阱表示也一樣。
For the objects of type `char`, `signed char`, and `unsigned char`, every bit of the object representation is required to participate in the value representation and each possible bit pattern represents a distinct value (no padding, trap bits, or multiple representations allowed).
對於 char 、 signed char 和 unsigned char 型別的物件，物件表示的每一位都必須參與值表示，並且每個可能的位模式表示一個不同的值（不允許填充、陷阱位或多重表示）。
When objects of integer types (`short`, `int`, `long`, `long long`) occupy multiple bytes, the use of those bytes is implementation-defined, but the two dominant implementations are *big-endian* (POWER, Sparc, Itanium) and *little-endian* (x86, x86_64): a big-endian platform stores the most significant byte at the lowest address of the region of storage occupied by the integer, a little-endian platform stores the least significant byte at the lowest address. See Endianness for detail. See also example below.
當整數型別（ short 、 int 、 long 、 long long ）的物件佔用多個位元組時，這些位元組的使用是實現定義的，但兩種主流實現是大端序（POWER、Sparc、Itanium）和小端序（x86、x86_64）：大端序平臺將最高有效位元組儲存在該整數所佔儲存區域的最低位址，小端序平臺將最低有效位元組儲存在最低位址。詳見 Endianness 。另見下文示例。
Although most implementations do not allow trap representations, padding bits, or multiple representations for integer types, there are exceptions; for example a value of an integer type on Itanium may be a trap representation.
儘管大多數實現不允許整數型別有陷阱表示、填充位或多重表示，但也有例外；例如 Itanium 上整數型別的值可能是陷阱表示。

### Effective type

Every object has an *effective type*, which determines which lvalue accesses are valid and which violate the strict aliasing rules.
每個物件都有一個有效型別，它決定哪些左值訪問是有效的，哪些違反了嚴格別名規則。
If the object was created by a declaration, the declared type of that object is the object's *effective type*.
如果物件是由宣告建立的，該物件的宣告型別就是該物件的有效型別。
If the object was created by an allocation function (including realloc), it has no declared type. Such object acquires an effective type as follows:
如果物件是由分配函式（包括 realloc ）建立的，則它沒有宣告型別。該物件按如下方式獲得有效型別：

- The first write to that object through an lvalue that has a type other than character type, at which time the type of that lvalue becomes this object's *effective type* for that write and all subsequent reads.
透過具有非字元型別的左值對該物件的第一次寫入，此時該左值的型別成為該物件在此次寫入及所有後續讀取中的有效型別。

- memcpy or memmove copy another object into that object, or copy another object into that object as an array of character type, at which time the effective type of the source object (if it had one) becomes the effective type of this object for that write and all subsequent reads.
memcpy 或 memmove 將另一個物件複製到該物件中，或將另一個物件作為字元型別陣列複製到該物件中，此時源物件的有效型別（如果有）成為該物件在此次寫入及所有後續讀取中的有效型別。

- Any other access to the object with no declared type, the effective type is the type of the lvalue used for the access.
對沒有宣告型別的物件的任何其他訪問，其有效型別是用於訪問的左值的型別。

### Strict aliasing
嚴格別名

Given an object with *effective type* T1, using an lvalue expression (typically, dereferencing a pointer) of a different type T2 is undefined behavior, unless:
給定一個有效型別為 T1 的物件，使用型別為 T2 的左值表示式（通常為解引用指標）是未定義行為，除非：

- T2 and T1 are compatible types.
T2 和 T1 是相容型別。

- T2 is cvr-qualified version of a type that is compatible with T1.
T2 是與 T1 相容型別的 cvr 限定版本。

- T2 is a signed or unsigned version of a type that is compatible with T1.
T2 是與 T1 相容型別的帶符號或無符號版本。

- T2 is an aggregate type or union type type that includes one of the aforementioned types among its members (including, recursively, a member of a subaggregate or contained union).
T2 是聚合型別或聯合型別，其成員中包含上述型別之一（包括遞迴地，子聚合的成員或包含的聯合）。

- T2 is a character type (`char`, `signed char`, or `unsigned char`).
T2 是字元型別（ char 、 signed char 或 unsigned char ）。

```c
int i = 7; char* pc = (char*)(&i); if (pc[0] == '\x7') // aliasing through char is OK  puts("This system is little-endian"); else  puts("This system is big-endian"); float* pf = (float*)(&i); float d = *pf; // UB: float lvalue *p cannot be used to access int
```

These rules control whether when compiling a function that receives two pointers, the compiler must emit code that re-reads one after writing through another:
這些規則控制在編譯一個接收兩個指標的函式時，編譯器是否必須發出在透過一個指標寫入後重新讀取另一個指標的程式碼：

```c
// int* and double* cannot alias void f1(int* pi, double* pd, double d) {  // the read from *pi can be done only once, before the loop  for (int i = 0; i < *pi; i++)  *pd++ = d; }
```

```c
struct S { int a, b; }; // int* and struct S* may alias because S is an aggregate type with a member of type int void f2(int* pi, struct S* ps, struct S s) {  // read from *pi must take place after every write through *ps  for (int i = 0; i < *pi; i++)  *ps++ = s; }
```

Note that restrict qualifier can be used to indicate that two pointers do not alias even if the rules above permit them to be.
注意 restrict 限定符可用於表示兩個指標不別名，即使上述規則允許它們別名。
Note that type-punning may also be performed through the inactive member of a union.
注意 type-punning 也可以透過聯合的非活躍成員進行。

### Alignment

Every complete object type has a property called *alignment requirement*, which is an integer value of type size_t representing the number of bytes between successive addresses at which objects of this type can be allocated. The valid alignment values are non-negative integral powers of two.
每種完整物件型別都有對齊要求，這是 size_t 型別的整數，表示配置該型別物件時位址間隔所需的位元組數。有效的對齊值是 2 的非負整數次方。

The alignment requirement of a type can be queried with _Alignof(until C23)alignof(since C23).
|   | (since C11) |

In order to satisfy alignment requirements of all members of a struct, padding may be inserted after some of its members.
為了滿足 struct 所有成員的對齊要求，可能會在某些成員之後插入填充。

Run this code

```c
#include <stdalign.h> #include <stdio.h> // objects of struct S can be allocated at any address // because both S.a and S.b can be allocated at any address struct S {  char a; // size: 1, alignment: 1  char b; // size: 1, alignment: 1 }; // size: 2, alignment: 1 // objects of struct X must be allocated at 4-byte boundaries // because X.n must be allocated at 4-byte boundaries // because int's alignment requirement is (usually) 4 struct X {  int n; // size: 4, alignment: 4  char c; // size: 1, alignment: 1  // three bytes padding }; // size: 8, alignment: 4 int main(void) {  printf("sizeof(struct S) = %zu\n", sizeof(struct S));  printf("alignof(struct S) = %zu\n", alignof(struct S));  printf("sizeof(struct X) = %zu\n", sizeof(struct X));  printf("alignof(struct X) = %zu\n", alignof(struct X)); }
```

Possible output:
可能的輸出：

```c
sizeof(struct S) = 2 alignof(struct S) = 1 sizeof(struct X) = 8 alignof(struct X) = 4
```

Each object type imposes its alignment requirement on every object of that type. The weakest (smallest) alignment is the alignment of the types `char`, `signed char`, and `unsigned char`, and equals `1`. The strictest (largest) *fundamental alignment* of any type is implementation-definedand equal to the alignment of max_align_t(since C11).
每個物件型別將其對齊要求施加於該型別的每個物件。最弱（最小）的對齊是 char 、 signed char 和 unsigned char 型別的對齊，等於 1 。任何型別的最嚴格（最大）基本對齊是實現定義的，等於 max_align_t （C11 起）的對齊。
Fundamental alignments are supported for objects of all kinds of storage durations.
所有種類儲存期的物件都支援基本對齊。

If an object's alignment is made stricter (larger) than max_align_t using _Alignof(until C23)alignof(since C23), it has *extended alignment requirement*. A struct or union type whose member has extended alignment is an *over-aligned type*. It is implementation-defined if over-aligned types are supported, and their support may be different in each kind of storage duration.
If a struct or union type `S` does not have any member of an over-aligned type or declared with an alignment specifier that specifies an extended alignment, `S` has a fundamental alignment.
The atomic version of every arithmetic or pointer type has a fundamental alignment.
|   | (since C11) |

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 445  |   | C11  |   | a type might have extended alignment without `_Alignas` involved  |   | it must have fundamental alignment  |

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 3.15 object (p: 5)
3.15 物件 (p: 5)
3.15 物件 (p: 5)

- 6.2.6 Representations of types (p: 33-35)
6.2.6 型別的表示 (p: 33-35)
6.2.6 型別的表示 (p: 33-35)

- 6.2.8 Alignment of objects (p: 36-37)
6.2.8 物件的對齊 (p: 36-37)
6.2.8 物件的對齊 (p: 36-37)

- 6.5/6-7 Expressions (p: 55-56)
6.5/6-7 表示式 (p: 55-56)
6.5/6-7 表示式 (p: 55-56)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 3.15 object (p: 6)
3.15 物件 (p: 6)
3.15 物件 (p: 6)

- 6.2.6 Representations of types (p: 44-46)
6.2.6 型別的表示（p: 44-46）
6.2.6 型別的表示（p: 44-46）

- 6.2.8 Alignment of objects (p: 48-49)
6.2.8 物件的對齊 (p: 48-49)
6.2.8 物件的對齊 (p: 48-49)

- 6.5/6-7 Expressions (p: 77)
6.5/6-7 表示式 (p: 77)
6.5/6-7 表示式 (p: 77)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 3.2 alignment (p: 3)
3.2 對齊 (p: 3)
3.2 對齊 (p: 3)

- 3.14 object (p: 5)
3.14 物件 (p: 5)
3.14 物件 (p: 5)

- 6.2.6 Representations of types (p: 37-39)
6.2.6 型別的表示 (p: 37-39)
6.2.6 型別的表示 (p: 37-39)

- 6.5/6-7 Expressions (p: 67-68)
6.5/6-7 表示式 (p: 67-68)
6.5/6-7 表示式 (p: 67-68)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 1.6 Definitions of terms
1.6 術語定義
1.6 術語定義

### See also

C++ documentation for Object

---
來源頁路徑：`en.cppreference.com/c/language/object.html`
