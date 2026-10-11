# _Alignof (since C11)(deprecated in C23), alignof (since C23) operator

> 來源：cppreference C 語言參考文件（離線轉換版）。

Queries the alignment requirement of its operand type.
查詢其運算元型別的對齊要求。

### Syntax

|   |

| `**_Alignof(**` type-name `**)**`  |   |   |   | (since C11)(deprecated in C23)  |

|   |

| `**alignof(**` type-name `**)**`  |   |   |   | (since C23)  |

|   |

This operator is typically used through the convenience macro alignof, which is provided in the header <stdalign.h>
|   | (until C23) |

### Explanation

Returns the alignment requirement of the type named by type-name. If type-name is an array type, the result is the alignment requirement of the array element type. The type-name cannot be function type or an incomplete type.
傳回 type-name 所命名型別的對齊要求。如果 type-name 是陣列型別，則結果為陣列元素型別的對齊要求。type-name 不能是函式型別或不完整型別。
The result is an integer constant of type size_t.
結果是型別為 size_t 的整數常量。
The operand is not evaluated (so external identifiers used in the operand do not have to be defined).
運算元不會被求值（因此運算元中使用的外部識別符號不必已定義）。
If type-name is a VLA type, its size expression is not evaluated.
如果 type-name 是 VLA 型別，則其大小表示式不會被求值。

### Notes

The use of `_Alignof`(until C23)`alignof`(since C23) with expressions is allowed by some C compilers as a non-standard extension.
一些 C 編譯器允許將 _Alignof（C23 之前）/ alignof（C23 起）用於表示式，作為非標準擴充套件。

### Keywords

alignof, _Alignof
alignof , _Alignof

### Example

Run this code

```c
#include <stdalign.h> #include <stddef.h> #include <stdio.h> int main(void) {  printf("Alignment of char = %zu\n", alignof(char));  printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));  printf("alignof(float[10]) = %zu\n", alignof(float[10]));  printf("alignof(struct{char c; int n;}) = %zu\n",  alignof(struct {char c; int n;})); }
```

Possible output:
可能的輸出：

```c
Alignment of char = 1 Alignment of max_align_t = 16 alignof(float[10]) = 4 alignof(struct{char c; int n;}) = 4
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 494  |   | C11  |   | whether the size expression in a VLA is evaluated in `_Alignof` was unspecified  |   | it is unevaluated  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.5.3.4 The sizeof and alignof operators (p: TBD)
6.5.3.4 sizeof 和 alignof 運運算元 (p: TBD)
6.5.3.4 sizeof 和 alignof 運運算元 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.3.4 The sizeof and _Alignof operators (p: 64-65)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: 64-65)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: 64-65)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.3.4 The sizeof and _Alignof operators (p: 90-91)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: 90-91)
6.5.3.4 sizeof 和 _Alignof 運運算元 (p: 90-91)

### See also

max_align_t
(C11)
|   | a type with alignment requirement as great as any other scalar type
(typedef)   |

| _Alignas(until C23)alignas(since C23)  |   | sets alignment requirements of an object
(specifier)  |

C++ documentation for `alignof` operator

---
來源頁路徑：`en.cppreference.com/c/language/_Alignof.html`
