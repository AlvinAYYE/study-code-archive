# Type support

> 來源：cppreference C 語言參考文件（離線轉換版）。

See also type system overview and arithmetic types defined by the language.
另請參閱「型別系統概述」與 C 語言定義的「算術型別」。

### Basic types

#### Additional basic types and convenience macros

Defined in header `<stddef.h>`

size_t
|   | `sizeof` 運算子的結果型別，是一種無號整數型別。
(typedef)   |

ptrdiff_t
|   | 兩個指標相減時，結果所使用的有號整數型別。
(typedef)   |

nullptr_t
(C23)
|   | C23 預先定義的空指標常數 `nullptr` 所使用的型別。
(typedef)   |

NULL
|   | 由實作決定表示方式的空指標常數。
(macro constant)   |

max_align_t
(C11)
|   | 對齊需求至少和任何純量型別一樣大的型別。
(typedef)   |

offsetof
|   | 指定成員距離結構起點的位元組數。
(function macro)   |

Defined in header `<stdbool.h>`

bool
(C99)(removed in C23)
|   | 方便使用的巨集，會展開成 `_Bool`。
(keyword macro)  |

true
(C99)(removed in C23)
|   | 會展開成整數常數 `1`。
(macro constant)  |

false
(C99)(removed in C23)
|   | 會展開成整數常數 `0`。
(macro constant)  |

__bool_true_false_are_defined
(C99)(deprecated in C23)
|   | 會展開成整數常數 `1`。
(macro constant)  |

Defined in header `<stdalign.h>`

alignas
(C11)(removed in C23)
|   | 方便使用的巨集，會展開成關鍵字 `_Alignas`。
(keyword macro)  |

alignof
(C11)(removed in C23)
|   | 方便使用的巨集，會展開成關鍵字 `_Alignof`。
(keyword macro)  |

__alignas_is_defined
(C11)(removed in C23)
|   | 會展開成整數常數 `1`。
(macro constant)  |

__alignof_is_defined
(C11)(removed in C23)
|   | 會展開成整數常數 `1`。
(macro constant)  |

Defined in header `<stdnoreturn.h>`

noreturn
(C11)(deprecated in C23)
|   | 方便使用的巨集，會展開成 `_Noreturn`。
(keyword macro)  |

#### Fixed width integer types (since C99)

#### Numeric limits

### Notes

在 C23 之前，`true` 和 `false` 的型別是 `int`，不是 `_Bool`。
程式可以先取消定義 `bool`、`true`、`false` 這些巨集，再視需要重新定義；不過，標準已將這種做法列為淘汰功能。
|   | (since C99)
(until C23) |

從 C23 起，`true` 和 `false` 的型別是 `bool`。標準沒有規定實作是否會把 `bool`、`_Bool`、`true` 或 `false` 中的任何一個定義成預先定義的巨集。
如果實作將 `bool`、`true` 或 `false`（不包括 `_Bool`）定義成預先定義的巨集，程式可以取消定義，並視需要重新定義它。
|   | (since C23) |

### Example

Run this code

```c
#include <stdalign.h> #include <stdbool.h> #include <stdio.h> int main(void) {  printf("%d %d %d\n", true && false, true || false, !false);  printf("%d %d\n", true ^ true, true + true);  printf("%zu\n", alignof(short)); }
```

Possible output:
可能的輸出：

```c
0 1 1 0 2 2
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.15 Alignment <stdalign.h> (p: TBD)
7.15 對齊 <stdalign.h> (p: TBD)
7.15 對齊 <stdalign.h> (p: TBD)

- 7.18 Boolean type and values <stdbool.h> (p: TBD)
7.18 布林型別和值 <stdbool.h> （頁碼：待定）
7.18 布林型別和值 <stdbool.h> （頁碼：待定）

- 7.19 Common definitions <stddef.h> (p: TBD)
7.19 通用定義 <stddef.h>（頁碼：待定）
7.19 通用定義 <stddef.h>（頁碼：待定）

- 7.23 _Noreturn <stdnoreturn.h> (p: TBD)
7.23 _Noreturn <stdnoreturn.h>（p: TBD）
7.23 _Noreturn <stdnoreturn.h>（p: TBD）

- 7.31.9 Boolean type and values <stdbool.h> (p: TBD)
7.31.9 布林型別和值 <stdbool.h> （頁碼：待定）
7.31.9 布林型別和值 <stdbool.h> （頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.15 Alignment <stdalign.h> (p: 196)
7.15 對齊 <stdalign.h> (p: 196)
7.15 對齊 <stdalign.h> (p: 196)

- 7.18 Boolean type and values <stdbool.h> (p: 210)
7.18 布林型別和值 <stdbool.h> （頁碼：210）
7.18 布林型別和值 <stdbool.h> （頁碼：210）

- 7.19 Common definitions <stddef.h> (p: 211)
7.19 通用定義 <stddef.h>（頁碼：211）
7.19 通用定義 <stddef.h>（頁碼：211）

- 7.23 _Noreturn <stdnoreturn.h> (p: 263)
7.23 _Noreturn <stdnoreturn.h>（p: 263）
7.23 _Noreturn <stdnoreturn.h>（p: 263）

- 7.31.9 Boolean type and values <stdbool.h> (p: 332)
7.31.9 布林型別和值 <stdbool.h> （頁碼：332）
7.31.9 布林型別和值 <stdbool.h> （頁碼：332）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.15 Alignment <stdalign.h> (p: 268)
7.15 對齊 <stdalign.h> (p: 268)
7.15 對齊 <stdalign.h> (p: 268)

- 7.18 Boolean type and values <stdbool.h> (p: 287)
7.18 布林型別和值 <stdbool.h> （頁碼：287）
7.18 布林型別和值 <stdbool.h> （頁碼：287）

- 7.19 Common definitions <stddef.h> (p: 288)
7.19 通用定義 <stddef.h>（頁碼：288）
7.19 通用定義 <stddef.h>（頁碼：288）

- 7.23 _Noreturn <stdnoreturn.h> (p: 361)
7.23 _Noreturn <stdnoreturn.h>（p: 361）
7.23 _Noreturn <stdnoreturn.h>（p: 361）

- 7.31.9 Boolean type and values <stdbool.h> (p: 456)
7.31.9 布林型別和值 <stdbool.h> （頁碼：456）
7.31.9 布林型別和值 <stdbool.h> （頁碼：456）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 7.18 Boolean type and values <stdbool.h> (p: 253)
7.18 布林型別和值 <stdbool.h> （頁碼：253）
7.18 布林型別和值 <stdbool.h> （頁碼：253）

- 7.19 Common definitions <stddef.h> (p: 254)
7.19 通用定義 <stddef.h> （頁碼：254）
7.19 通用定義 <stddef.h> （頁碼：254）

- 7.26.7 Boolean type and values <stdbool.h> (p: 401)
7.26.7 布林型別和值 <stdbool.h> （頁碼：401）
7.26.7 布林型別和值 <stdbool.h> （頁碼：401）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 4.1.5 Common definitions <stddef.h>
4.1.5 通用定義 <stddef.h>
4.1.5 通用定義 <stddef.h>

### See also

C++ documentation for Type support library

---
來源頁路徑：`en.cppreference.com/c/types.html`
