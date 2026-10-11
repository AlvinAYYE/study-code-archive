# Source file inclusion

> 來源：cppreference C 語言參考文件（離線轉換版）。

Includes another source file into the current source file at the line immediately after the directive.
在指令後方的下一行，將另一個原始碼檔案納入目前的原始碼檔案。

### Syntax

|   |

| `**#include <**` h-char-sequence `**>**` new-line  |   | (1)  |   |   |

|   |

| `**#include "**` q-char-sequence `**"**` new-line  |   | (2)  |   |   |

|   |

| `**#include**` pp-tokens new-line  |   | (3)  |   |   |

|   |

| `**__has_include**` `**(**` `**"**` q-char-sequence `**"**` `**)**`
`**__has_include**` `**(**` `**<**` h-char-sequence `**>**` `**)**`  |   | (4)  |   | (since C23)  |

|   |

| `**__has_include**` `**(**` string-literal `**)**`
`**__has_include**` `**(**` `**<**` h-pp-tokens `**>**` `**)**`  |   | (5)  |   | (since C23)  |

|   |

1) Searches for a header identified uniquely by h-char-sequence and replaces the directive by the entire contents of the header.

2) Searches for a source file identified by q-char-sequence and replaces the directive by the entire contents of the source file. It may fallback to (1) and treat q-char-sequence as a header identifier.

3) If neither (1) nor (2) is matched, pp-tokens will undergo macro replacement. The directive after replacement will be tried to match with (1) or (2) again.

4) Checks whether a header or source file is available for inclusion.

5) If (4) is not matched, h-pp-tokens will undergo macro replacement. The directive after replacement will be tried to match with (4) again.

| new-line  |   | -  |   | The new-line character  |

| h-char-sequence  |   | -  |   | A sequence of one or more h-chars, where the appearance of any of the following causes undefined behavior:
- the character `'`

- the character `"`

- the character `\`

- the character sequence `//`

- the character sequence `/*`

| h-char  |   | -  |   | Any member of the source character set except new-line and `>`  |

| q-char-sequence  |   | -  |   | A sequence of one or more q-chars, where the appearance of any of the following causes undefined behavior:
- the character `'`

- the character `\`

- the character sequence `//`

- the character sequence `/*`

| q-char  |   | -  |   | Any member of the source character set except new-line and `"`  |

| pp-tokens  |   | -  |   | A sequence of one or more preprocessing tokens  |

| string-literal  |   | -  |   | A string literal  |

| h-pp-tokens  |   | -  |   | A sequence of one or more preprocessing tokens except `>`  |

### Explanation

1) Searches for the file identified by h-char-sequence in implementation-defined manner. The intent of this syntax is to search for the files under control of the implementation. Typical implementations search only standard include directories. The standard C library is implicitly included in these standard include directories. The standard include directories usually can be controlled by the user through compiler options.

2) Searches for the file identified by q-char-sequence in implementation-defined manner. The intent of this syntax is to search for the files that are not controlled by the implementation. Typical implementations first search the directory where the current file resides and, only if the file is not found, search the standard include directories as with (1).

3) The preprocessing tokens after `**include**` in the directive are processed just as in normal text (i.e., each identifier currently defined as a macro name is replaced by its replacement list of preprocessing tokens). The directive resulting after all replacements shall match one of the two previous forms. The method by which a sequence of preprocessing tokens between `<` and `>` preprocessing token pair or a pair of `"` characters is combined into a single header name preprocessing token is implementation-defined.

4) The header or source file identified by h-char-sequence or q-char-sequence is searched for as if that preprocessing token sequence were the pp-tokens in syntax (3), except that no further macro expansion is performed. If such a directive would not satisfy the syntactic requirements of an `#include` directive, the program is ill-formed. The `__has_include` expression evaluates to `1` if the search for the source file succeeds, and to `0` if the search fails.

5) This form is considered only if syntax (4) does not match, in which case the preprocessing tokens are processed just as in normal text.

In the case the file is not found, the program is ill-formed.
若找不到該檔案，程式即為格式錯誤（ill-formed）。

`__has_include` can be expanded in the expression of  #if and  #elif. It is treated as a defined macro by  #ifdef,  #ifndef,  #elifdef,  #elifndef and defined but cannot be used anywhere else.
|   | (since C23) |

### Notes

Typical implementations search only standard include directories for syntax (1). The standard C library is implicitly included in these standard include directories. The standard include directories usually can be controlled by the user through compiler options.
一般而言，實作只會依語法 (1) 搜尋標準標頭檔目錄。標準 C 函式庫會隱含在這些目錄中；使用者通常可透過編譯器選項指定目錄。
The intent of syntax (2) is to search for the files that are not controlled by the implementation. Typical implementations first search the directory where the current file resides then falls back to (1).
語法 (2) 用來搜尋不由實作管理的檔案。一般而言，實作會先搜尋目前檔案所在的目錄，找不到時再依語法 (1) 搜尋。
When a file is included, it is processed by translation phases 1-4, which may include, recursively, expansion of the nested `#include` directives, up to an implementation-defined nesting limit. To avoid repeated inclusion of the same file and endless recursion when a file includes itself, perhaps transitively, *header guards* are commonly used: the entire header is wrapped in
納入檔案時，該檔案會經過翻譯階段 1 到 4；其中可能遞迴展開巢狀的 #include 指令，直到達到實作定義的巢狀層數上限。為避免重複納入同一檔案，或因檔案直接、間接納入自身而無限遞迴，通常會使用標頭檔保護巨集，將整個標頭檔包在：

```c
#ifndef FOO_H_INCLUDED /* any name uniquely mapped to file name */ #define FOO_H_INCLUDED // contents of the file are here #endif
```

Many compilers also implement the non-standard pragma `#pragma once` with similar effects: it disables processing of a file if the same file (where file identity is determined in OS-specific way) has already been included.
許多編譯器也支援非標準的 pragma #pragma once，效果類似：若同一檔案（依作業系統特定方式判定）已納入過，就不再處理它。
A `__has_include` result of `1` only means that a header or source file with the specified name exists. It does not mean that the header or source file, when included, would not cause an error or would contain anything useful.
__has_include 的結果為 1，只表示指定名稱的標頭檔或原始碼檔案存在；不代表納入時不會出錯，也不保證檔案內含有可用內容。

### Example

|  | This section is incomplete
Reason: no example  |

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.4.7 Header names (p: 69)
6.4.7 標頭檔名 (p: 69)
6.4.7 標頭檔名 (p: 69)

- 6.10.1 Conditional inclusion (p: 165-169)
6.10.1 條件包含 (p: 165-169)
6.10.1 條件包含 (p: 165-169)

- 6.10.2 Source file inclusion (p: 169-170)
6.10.2 原始檔包含 (p: 169-170)
6.10.2 原始檔包含 (p: 169-170)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.10.2 Source file inclusion (p: 119-120)
6.10.2 原始檔包含 (p: 119-120)
6.10.2 原始檔包含 (p: 119-120)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.10.2 Source file inclusion (p: 164-166)
6.10.2 原始檔包含 (p: 164-166)
6.10.2 原始檔包含 (p: 164-166)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.10.2 Source file inclusion (p: 149-151)
6.10.2 原始檔包含 (p: 149-151)
6.10.2 原始檔包含 (p: 149-151)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.8.2 Source file inclusion
3.8.2 原始檔包含
3.8.2 原始檔包含

### See also

| A list of C Standard Library header files  |

C++ documentation for Source file inclusion

---
來源頁路徑：`en.cppreference.com/c/preprocessor/include.html`
