# Filename and line information

> 來源：cppreference C 語言參考文件（離線轉換版）。

Changes the current line number and file name in the preprocessor.
變更前處理器記錄的目前行號與檔名。

### Syntax

|   |

| `**#line**` lineno  |   | (1)  |   |   |

|   |

| `**#line**` lineno `**"**`filename`**"**`  |   | (2)  |   |   |

|   |

### Explanation

1) Changes the current preprocessor line number to lineno. Occurrences of the macro __LINE__ beyond this point will expand to lineno plus the number of actual source code lines encountered since.

2) Also changes the current preprocessor file name to filename. Occurrences of the macro __FILE__ beyond this point will produce filename.

Any preprocessing tokens (macro constants or expressions) are permitted as arguments to `#line` as long as they expand to a valid decimal integer optionally following a valid character string.
只要展開後是有效的十進位整數，後面還可選擇性接一個有效字串，任何預處理記號（巨集常數或運算式）都能做為 #line 的參數。
lineno must be a sequence of at least one decimal digit (the program is ill-formed, otherwise) and is always interpreted as decimal (even if it starts with `0`).
lineno 必須由至少一個十進位數字組成，否則程式格式錯誤；即使以 0 開頭，也一律視為十進位數。
If lineno is `0` or greater than `32767`(until C99)`2147483647`(since C99), the behavior is undefined.
若 lineno 為 0，或大於 32767（C99 之前）／2147483647（C99 起），行為未定義。

### Notes

This directive is used by some automatic code generation tools which produce C source files from a file written in another language. In that case, `#line` directives may be inserted in the generated C file referencing line numbers and the file name of the original (human-editable) source file.
有些自動程式碼產生工具會從其他語言的檔案產生 C 原始碼。這類工具可在產生的 C 檔中插入 #line 指令，標示原始（可供人工編輯）檔案的行號與檔名。
The line number following the directive `#line __LINE__` is unspecified (there are two possible values that __LINE__ can expand to in this case: number of endlines seen so far, or number of endlines seen so far plus the endline that ends the `#line` directive). This is the result of DR 464, which applies retroactively.
指令 #line __LINE__ 之後的行號是未指定的（在這種情況下 __LINE__ 可以展開為兩個可能的值：到目前為止見到的換行符數目，或到目前為止見到的換行符數目加上結束 #line 指令的那個換行符）。這是 DR 464 的結果，該結果可追溯適用。

### Example

Run this code

```c
#include <assert.h> #define FNAME "test.c" int main(void) { #line 777 FNAME  assert(2+2 == 5); }
```

Possible output:
輸出範例：

```c
test: test.c:777: int main(): Assertion `2+2 == 5' failed.
```

### References

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.10.4 Line control (p: 126)
6.10.4 行控制 (p: 126)
6.10.4 行控制 (p: 126)

- J.1 Unspecified behavior
J.1 未指定行為
J.1 未指定行為

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.10.4 Line control (p: 173)
6.10.4 行控制 (p: 173)
6.10.4 行控制 (p: 173)

- C99 standard (ISO/IEC 9899:1999):
C99 標準（ISO/IEC 9899:1999）：

- 6.10.4 Line control (p: 158)
6.10.4 行控制 (p: 158)
6.10.4 行控制 (p: 158)

- C89/C90 standard (ISO/IEC 9899:1990):
C89/C90 標準（ISO/IEC 9899:1990）：

- 3.8.4 Line control
3.8.4 行控制
3.8.4 行控制

### See also

C++ documentation for Filename and line information

---
來源頁路徑：`en.cppreference.com/c/preprocessor/line.html`
