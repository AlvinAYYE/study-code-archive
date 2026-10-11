# Conformance

> 來源：cppreference C 語言參考文件（離線轉換版）。

*Conformance* has a three-fold definition:
一致性有三重定義：

- *strictly conforming program* - uses only well-defined language constructs, that is constructs with a single behavior. It excludes unspecified, undefined, or implementation-defined behavior, and does not exceed any minimum implementation limit.
嚴格一致的程式 —— 只使用定義良好的語言構造，即只有一種行為的構造。它不包含未指定的、未定義的或由實現定義的行為，並且不超過任何最低實現限制。

- *conforming program* - acceptable to a conforming implementation.
一致的程式 —— 可被一致的實現所接受。

- *conforming implementation* -
- A conforming hosted implementation shall accept any strictly conforming program.
一致的宿主實現應當接受任何嚴格一致的程式。

- A conforming freestanding implementation shall accept any strictly conforming program in which the use of the features specified in the library clause (clause 7) is confined to the contents of the freestanding standard library headers (see below).
一致的獨立實現應當接受任何嚴格一致的程式，其中對庫條款（第 7 條）所規定特性的使用僅限於獨立標準函式庫標頭檔的內容（見下文）。

- A conforming implementation may have extensions (including additional library functions), provided they do not alter the behavior of any strictly conforming program.
一致的實現可以帶有擴充套件（包括額外的庫函式），只要它們不改變任何嚴格一致的程式的行為。
一致的實現 —— 一致的宿主實現應當接受任何嚴格一致的程式。一致的獨立實現應當接受任何嚴格一致的程式，其中對庫條款（第 7 條）所規定特性的使用僅限於獨立標準函式庫標頭檔的內容（見下文）。一致的實現可以帶有擴充套件（包括額外的庫函式），只要它們不改變任何嚴格一致的程式的行為。

### Explanation

The standard does not define any minimum implementation limit on translation units. A hosted environment has an operating system; a freestanding environment does not. A program running in a hosted environment may use all features described in the library clause (clause 7); a program running in a freestanding environment may use a subset of library features required by clause 4.
標準未對翻譯單元定義任何最低實現限制。宿主環境具有作業系統；獨立環境則沒有。執行在宿主環境中的程式可以使用庫條款（第 7 條）中描述的所有特性；執行在獨立環境中的程式可以使用第 4 條所要求的庫特性的子集。

#### Freestanding standard library headers

All standard library features in every fully freestanding header are required to be provided by a freestanding implementation.
每個完全獨立的標頭檔中的所有標準函式庫特性都要求由獨立實現提供。

Some standard library headers are conditionally freestanding.

- If the implementation predefines the macro `__STDC_IEC_60559_BFP__` or `__STDC_IEC_60559_DFP__`, then <math.h> and <fenv.h> are fully freestanding headers. However, the behavior of functions in these headers is required to be well-defined in a freestanding environment only if a program does not set the state of the FENV_ACCESS pragma to `ON`.

Some standard library headers are partially freestanding.

- In <stdlib.h>, memalignment is freestanding. Additionally, when `__STDC_IEC_60559_BFP__` or `__STDC_IEC_60559_DFP__` are predefined, numeric conversion functions (`ato*X*`, `strto*X*`, and `strfrom*X*`) are also freestanding, while their behavior is required to be well-defined in a freestanding environment only if a program does not set the state of the FENV_ACCESS pragma to `ON`. No other component in <stdlib.h> is required to be to be provided by a freestanding implementation.

- In <string.h>, strdup, strndup, strcoll, strxfrm, strtok, and strerror are not required to be provided by a freestanding implementation.
|   | (since C23) |

#####  Fully freestanding standard library headers

| <float.h>  |   | Limits of floating-point types  |

| <iso646.h> (since C95)  |   | Alternative operator spellings  |

| <limits.h>  |   | Ranges of integer types  |

| <stdalign.h> (since C11)  |   | `alignas` and `alignof` convenience macros  |

| <stdarg.h>  |   | Variable arguments  |

| <stdbool.h> (since C99)  |   | Macros for boolean type  |

| <stddef.h>  |   | Common macro definitions  |

| <stdint.h> (since C99)  |   | Fixed-width integer types  |

| <stdnoreturn.h> (since C11)  |   | noreturn convenience macro  |

| <stdbit.h> (since C23)  |   | Macros to work with the byte and bit representations of types  |

#####  Conditionally fully freestanding standard library headers

| <fenv.h> (since C23)  |   | Floating-point environment  |

| <math.h> (since C23)  |   | Common mathematics functions  |

#####  Partially freestanding standard library headers

| <stdlib.h> (since C23)  |   | General utilities: memory management, program utilities, string conversions, random numbers, algorithms  |

| <string.h> (since C23)  |   | String handling  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 4 Conformance (p: 9-10)
4 一致性（p: 9-10）
4 一致性（p: 9-10）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 4 Conformance (p: 4)
4 一致性（p: 4）
4 一致性（p: 4）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 4 Conformance (p: 8-9)
4 一致性（p: 8-9）
4 一致性（p: 8-9）

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 4 Conformance (p: 7-8)
4 一致性（p: 7-8）
4 一致性（p: 7-8）

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 1.7 Compliance

### See also

C++ documentation for Freestanding and hosted implementation

---
來源頁路徑：`en.cppreference.com/c/language/conformance.html`
