# Static assertion (since C11)

> 來源：cppreference C 語言參考文件（離線轉換版）。

### Syntax

|   |

| `**_Static_assert**` `**(**` expression `**,**` message `**)**`  |   |   |   | (since C11)(deprecated in C23)  |

|   |

| `**static_assert**` `**(**` expression `**,**` message `**)**`  |   |   |   | (since C23)  |

|   |

| `**_Static_assert**` `**(**` expression `**)**`  |   |   |   | (since C23)(deprecated in C23)  |

|   |

| `**static_assert**` `**(**` expression `**)**`  |   |   |   | (since C23)  |

|   |

| expression  |   | -  |   | any integer constant expression  |

| message  |   | -  |   | any string literal  |

This keyword is also available as convenience macro static_assert, available in the header <assert.h>.
|   | (until C23) |

Both of `static_assert` and `_Static_assert` have the same effects. `_Static_assert` is a deprecated spelling that is kept for compatibility.
An implementation may also define `static_assert` and/or `_Static_assert` as predefined macros, and `static_assert` is no longer provided by <assert.h>.
|   | (since C23) |

### Explanation

The constant expression is evaluated at compile time and compared to zero. If it compares equal to zero, a compile-time error occurs and the compiler must display message as part of the error message (except that characters not in basic character set are not required to be displayed)(until C23)should display message (if provided) as part of the error message(since C23).
常量表示式在編譯時求值並與零比較。如果比較結果等於零，則發生編譯時錯誤，編譯器必須將訊息作為錯誤訊息的一部分顯示（基本字符集之外的字元不要求顯示）（至 C23 止）應將訊息（如果提供）作為錯誤訊息的一部分顯示（自 C23 起）。
Otherwise, if expression does not equal zero, nothing happens; no code is emitted.
否則，如果表示式不等於零，則什麼都不發生；不生成程式碼。

### Keywords

_Static_assert, static_assert
_Static_assert , static_assert

### Example

Run this code

```c
#include <assert.h> // no longer needed since C23 int main(void) {  // Test if math works, C23:  static_assert((2 + 2) % 3 == 1, "Whoa dude, you knew!");  // Pre-C23 alternative:  _Static_assert(2 + 2 * 2 == 6, "Lucky guess!?");  // This will produce an error at compile time.  // static_assert(sizeof(int) < sizeof(char), "Unmet condition!");  constexpr int _42 = 2 * 3 * 2 * 3 + 2 * 3;  static_assert(_42 == 42); // the message string can be omitted.  // const int _13 = 13;  // Compile time error - not an integer constant expression:  // static_assert(_13 == 13); }
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 6.7.11 Static assertions (p: TBD)
6.7.11 靜態斷言 (p: TBD)
6.7.11 靜態斷言 (p: TBD)

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 6.7.10 Static assertions (p: 105)
6.7.10 靜態斷言 (p: 105)
6.7.10 靜態斷言 (p: 105)

- 7.2 Diagnostics <assert.h> (p: 135)
7.2 診斷 <assert.h> (p: 135)
7.2 診斷 <assert.h> (p: 135)

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 6.7.10 Static assertions (p: 145)
6.7.10 靜態斷言 (p: 145)
6.7.10 靜態斷言 (p: 145)

- 7.2 Diagnostics <assert.h> (p: 186-187)
7.2 診斷 <assert.h> (p: 186-187)
7.2 診斷 <assert.h> (p: 186-187)

### See also

assert
|   | aborts the program if the user-specified condition is not `true`. May be disabled for release builds
(function macro)   |

C++ documentation for `static_assert` declaration

---
來源頁路徑：`en.cppreference.com/c/language/static_assert.html`
