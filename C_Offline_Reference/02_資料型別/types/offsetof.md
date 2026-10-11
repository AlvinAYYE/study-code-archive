# offsetof

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stddef.h>`
|   |  |   |  |

```c
#define offsetof(type, member) /*implementation-defined*/
```
|   |   |   |   |

|  |  |  |  |

The macro offsetof expands to an integer constant expression of type size_t, the value of which is the offset, in bytes, from the beginning of an object of specified type to its specified subobject, including padding if any.
宏 offsetof 展開為型別為 size_t 的整數常量表示式，其值為以位元組為單位的偏移量，從指定型別物件的起始處到其指定的子物件，包括任何填充（如有）。
Given an object `o` of type `type` with static storage duration, `&(o.member)` shall be an address constant expression and point to a subobject of `o`. Otherwise, the behavior is undefined.
給定一個具有靜態儲存期的 type 型別物件 o，& (o.member) 應為位址常量表示式並指向 o 的一個子物件。否則，行為未定義。

If the type name specified in `type` contains a comma not between matching parentheses, the behavior is undefined.
如果 `type` 中的型別名稱含有不在成對括號內的逗號，行為未定義。
|   | (since C23) |

### Notes

If `offsetof` is applied to a bit-field member, the behavior is undefined, because the address of a bit-field cannot be taken.
如果 offsetof 應用於位域成員，則行為未定義，因為不能取位域的位址。
`member` is not restricted to a direct member. It can denote a subobject of a given member, such as an element of an array member.
member 不限於直接成員。它可以表示給定成員的子物件，例如陣列成員的元素。
Even though it is specified in C23 that specifying a new type containing an unparenthesized comma in `offsetof` is undefined behavior, such usage is generally not supported even in earlier modes: `offsetof(struct Foo { int a, b; }, a)` generally fails to compile.
儘管 C23 規定在 offsetof 中指定包含未加括號逗號的新型別是未定義行為，但此類用法即使在早期模式下通常也不受支援：offsetof ( struct Foo { int a , b ; }, a ) 一般無法編譯。

typeof can be used to avoid the bad effect of commas in the definition of a new type, e.g. `offsetof(typeof(struct { int i, j; }), i)` is well-defined.
從 C23 起，可用 `typeof` 把新型別包起來，避免型別定義中的逗號被誤認為 `offsetof` 的參數分隔符。例如，`offsetof(typeof(struct { int i, j; }), i)` 的行為有明確定義。
|   | (since C23) |

### Example

Run this code

```c
#include <stdio.h> #include <stddef.h> struct S {  char c;  double d; }; int main(void) {  printf("the first element is at offset %zu\n", offsetof(struct S, c));  printf("the double is at offset %zu\n", offsetof(struct S, d)); }
```

Possible output:
可能的輸出：

```c
the first element is at offset 0 the double is at offset 8
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 496  |   | C89  |   | only structs and struct members were mentioned  |   | unions and other subobjects are also supported  |

### See also

size_t
|   | unsigned integer type returned by the sizeof operator
(typedef)   |

C++ documentation for offsetof

---
來源頁路徑：`en.cppreference.com/c/types/offsetof.html`
