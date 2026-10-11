# Generic selection (since C11)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Provides a way to choose one of several expressions at compile time, based on a type of a controlling expression
提供一種在編譯時根據控制表示式的型別選擇多個表示式之一的方法

### Syntax

|   |

| `**_Generic**` `**(**` controlling-expression `**,**` association-list `**)**`  |   |   |   | (since C11)  |

|   |

where association-list is a comma-separated list of associations, each of which has the syntax
其中 association-list 是關聯的逗號分隔列表，每個關聯具有以下語法

|   |

| type-name `**:**` expression  |   |   |   |   |

|   |

| `**default**` `**:**` expression  |   |   |   |   |

|   |

where

| type-name  |   | -  |   | any complete object type that isn't variably-modified (that is, not VLA or pointer to VLA).  |

| controlling-expression  |   | -  |   | any expression (except for the comma operator) whose type must be compatible with one of the type-names if the `default` association is not used  |

| expression  |   | -  |   | any expression (except for the comma operator) of any type and value category  |

No two type-names in the association-list may specify compatible types. There may be only one association that uses the keyword `default`. If `default` is not used and none of the type-names are compatible with the type of the controlling expression, the program will not compile.
association-list 中沒有兩個 type-name 可以指定相容型別。只能有一個使用關鍵字 default 的關聯。如果未使用 default 且沒有 type-name 與控制表示式的型別相容，則程式無法編譯。

### Explanation

First, the type of controlling-expression undergoes lvalue conversions. The conversion is performed in type domain only: it discards the top-level cvr-qualifiers and atomicity and applies array-to-pointer/function-to-pointer transformations to the type of the controlling expression, without initiating any side-effects or calculating any values.
首先，控制表示式的型別進行左值轉換。該轉換僅在型別域中執行：它丟棄頂層 cvr 限定符和原子性，並對控制表示式的型別應用陣列到指標/函式到指標轉換，不產生任何副作用或計算任何值。
The type after conversion is compared with type-names from the list of associations.
轉換後的型別與關聯列表中的 type-name 進行比較。
If the type is compatible with the type-name of one of the associations, then the type, value, and value category of the generic selection are the type, value, and value category of the expression that appears after the colon for that type-name.
如果該型別與某個關聯的 type-name 相容，則泛型選擇的型別、值和值類別是冒號後出現在該 type-name 對應的表示式的型別、值和值類別。
If none of the type-names are compatible with the type of the controlling-expression, and the `default` association is provided, then the type, value, and value category of the generic selection are the type, value, and value category of the expression after the `default :` label.
如果沒有 type-name 與控制表示式的型別相容，並且提供了 default 關聯，則泛型選擇的型別、值和值類別是 default: 標籤之後表示式的型別、值和值類別。

### Notes

The controlling-expression and the expressions of the selections that are not chosen are never evaluated.
控制表示式和未被選擇的表示式永遠不會被求值。
Because of the lvalue conversions, `"abc"` matches `char*` and not `char[4]` and `(int const){0}` matches `int`, and not `const int`.
由於左值轉換，"abc" 匹配 char* 而不是 char[4]，(int const){0} 匹配 int 而不是 const int。
All value categories, including function designators and void expressions, are allowed as expressions in a generic selection, and if selected, the generic selection itself has the same value category.
所有值類別，包括函式指示符和 void 表示式，都允許作為泛型選擇中的表示式，如果被選中，泛型選擇本身具有相同的值類別。
The type-generic math macros from <tgmath.h>, introduced in C99, were implemented in compiler-specific manner. Generic selections, introduced in C11, gave the programmers the ability to write similar type-dependent code.
C99 引入的 <tgmath.h> 中的泛型數學宏以特定於編譯器的方式實現。C11 引入的泛型選擇使程式設計師能夠編寫類似的依賴於型別的程式碼。
Generic selection is similar to overloading in C++ (where one of several functions is chosen at compile time based on the types of the arguments), except that it makes the selection between arbitrary expressions.
泛型選擇類似於 C++ 中的過載（根據參數型別在編譯時從多個函式中選擇一個），只不過它是在任意表示式之間進行選擇。

### Keywords

_Generic, default
_Generic ，default

### Example

Run this code

```c
#include <math.h> #include <stdio.h> // Possible implementation of the tgmath.h macro cbrt #define cbrt(X) _Generic((X), \  long double: cbrtl, \  default: cbrt, \  float: cbrtf \  )(X) int main(void) {  double x = 8.0;  const float y = 3.375;  printf("cbrt(8.0) = %f\n", cbrt(x)); // selects the default cbrt  printf("cbrtf(3.375) = %f\n", cbrt(y)); // converts const float to float,  // then selects cbrtf }
```

Output:

```c
cbrt(8.0) = 2.000000 cbrtf(3.375) = 1.500000
```

### Defect reports

The following behavior-changing defect reports were applied retroactively to previously published C standards.
以下更改行為的缺陷報告已追溯應用於先前釋出的 C 標準。

| DR  |   | Applied to  |   | Behavior as published  |   | Correct behavior  |

| DR 481  |   | C11  |   | it was underspecified if the controlling expression undergoes lvalue conversions  |   | it undergoes  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.5.1.1 Generic selection (p: TBD)
6.5.1.1 泛型選擇（p: TBD）
6.5.1.1 泛型選擇（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.5.1.1 Generic selection (p: 56-57)
6.5.1.1 泛型選擇（p: 56-57）
6.5.1.1 泛型選擇（p: 56-57）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.5.1.1 Generic selection (p: 78-79)
6.5.1.1 泛型選擇（p: 78-79）
6.5.1.1 泛型選擇（p: 78-79）

### See also

C++ documentation for Templates

---
來源頁路徑：`en.cppreference.com/c/language/generic.html`
