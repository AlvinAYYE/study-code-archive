# _Noreturn function specifier (since C11)(deprecated in C23)

> 來源：cppreference C 語言參考文件（離線轉換版）。

Specifies that the function does not return to its point of invocation.
指定該函式不會傳回到其呼叫點。

### Syntax

|   |

| `_Noreturn` function_declaration  |   |   |   | (since C11)(deprecated in C23)  |

|   |

### Explanation

The `**_Noreturn**` keyword appears in a function declaration and specifies that the function does not return by executing the return statement or by reaching the end of the function body (it may return by executing longjmp). If the function declared `_Noreturn` returns, the behavior is undefined. A compiler diagnostic is recommended if this can be detected.
_Noreturn 關鍵字出現在函式宣告中，指定該函式不會透過執行 return 陳述式或到達函式體末尾而傳回（它可以透過執行 longjmp 傳回）。如果宣告為 _Noreturn 的函式傳回了，則行為是未定義行為。如果能夠檢測到這種情況，建議編譯器給出診斷資訊。
The `_Noreturn` specifier may appear more than once in the same function declaration, the behavior is the same as if it appeared once.
_Noreturn 說明符可以在同一函式宣告中出現多次，其行為與只出現一次時相同。
This specifier is typically used through the convenience macro noreturn, which is provided in the header `<stdnoreturn.h>`.
該說明符通常透過便利宏 noreturn 來使用，該宏由標頭檔 <stdnoreturn.h> 提供。

`_Noreturn` function specifier is deprecated. `[[noreturn]]` attribute should be used instead.
The macro `noreturn` is also deprecated.
|   | (since C23) |

### Keywords

_Noreturn

### Standard library
標準函式庫

The following functions are `noreturn` in the standard library:
標準函式庫中的以下函式是 noreturn 的：

- abort()

- exit()

- _Exit()

- quick_exit()

- thrd_exit()

- longjmp()

### Example

Run this code

```c
#include <stdio.h> #include <stdlib.h> #include <stdnoreturn.h> // causes undefined behavior if i <= 0 // exits if i > 0 noreturn void exit_now(int i) // or _Noreturn void exit_now(int i) {  if (i > 0)  exit(i); } int main(void) {  puts("Preparing to exit...");  exit_now(2);  puts("This code is never executed."); }
```

Output:

```c
Preparing to exit...
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.4 Function specifiers (p: TBD)
6.7.4 函式說明符（p: TBD）
6.7.4 函式說明符（p: TBD）

- 7.23 _Noreturn <stdnoreturn.h> (p: TBD)
7.23 _Noreturn <stdnoreturn.h>（p: TBD）
7.23 _Noreturn <stdnoreturn.h>（p: TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.4 Function specifiers (p: 90-91)
6.7.4 函式說明符（p: 90-91）
6.7.4 函式說明符（p: 90-91）

- 7.23 _Noreturn <stdnoreturn.h> (p: 263)
7.23 _Noreturn <stdnoreturn.h>（p: 263）
7.23 _Noreturn <stdnoreturn.h>（p: 263）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.4 Function specifiers (p: 125-127)
6.7.4 函式說明符（p: 125-127）
6.7.4 函式說明符（p: 125-127）

- 7.23 _Noreturn <stdnoreturn.h> (p: 361)
7.23 _Noreturn <stdnoreturn.h>（p: 361）
7.23 _Noreturn <stdnoreturn.h>（p: 361）

### See also

`[[noreturn]]`(C23)`[[_Noreturn]]`(C23)(deprecated)
{{{notes}}}
|   | indicates that the function does not return
(attribute specifier)  |

C++ documentation for `[[noreturn]]`

---
來源頁路徑：`en.cppreference.com/c/language/_Noreturn.html`
