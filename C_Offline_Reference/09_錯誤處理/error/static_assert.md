# static_assert

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<assert.h>`
|   |  |   |  |

```c
#define static_assert _Static_assert
```
|   |   |   |  (since C11)
(removed in C23)  |

|  |  |  |  |

This convenience macro expands to the keyword _Static_assert.
此便捷宏展開為關鍵字 _Static_assert 。

### Example

Run this code

```c
#include <assert.h> int main(void) {  static_assert(2 + 2 == 4, "2+2 isn't 4"); // well-formed  static_assert(sizeof(int) < sizeof(char), // compile-time error  "this program requires that int is less than char"); }
```

### Notes

Since C23, static_assert is itself a keyword, which may also be a predefined macro, so <assert.h> no longer provides it.
自 C23 起，static_assert 本身是一個關鍵字，它也可能是一個預定義宏，因此 <assert.h> 不再提供它。

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.2/3 Diagnostics <assert.h> (p: TBD)
7.2/3 診斷 <assert.h>（頁：TBD）
7.2/3 診斷 <assert.h>（頁：TBD）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.2/3 Diagnostics <assert.h> (p: 135)
7.2/3 診斷 <assert.h>（頁：135）
7.2/3 診斷 <assert.h>（頁：135）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.2/3 Diagnostics <assert.h> (p: 186)
7.2/3 診斷 <assert.h>（頁：186）
7.2/3 診斷 <assert.h>（頁：186）

### See also

C++ documentation for Static Assertion

---
來源頁路徑：`en.cppreference.com/c/error/static_assert.html`
