# max_align_t

> 來源：cppreference C 語言參考文件（離線轉換版）。

Defined in header `<stddef.h>`
|   |  |   |  |

```c
typedef /*implementation-defined*/ max_align_t;
```
|   |   |   |  (since C11)  |

|  |  |  |  |

`max_align_t` is a type whose alignment requirement is at least as strict (as large) as that of every scalar type.
max_align_t 的對齊要求至少與所有純量型別一樣嚴格（即對齊值一樣大）。

### Notes

Pointers returned by allocation functions such as malloc are suitably aligned for any object, which means they are aligned at least as strictly as `max_align_t`.
由 malloc 等分配函式傳回的指標對任何物件都適當對齊，這意味著它們的對齊至少與 max_align_t 一樣嚴格。

### Example

Run this code

```c
#include <inttypes.h> #include <stdalign.h> #include <stddef.h> #include <stdint.h> #include <stdio.h> #include <stdlib.h>   int main(void) {  size_t a = alignof(max_align_t);  printf("Alignment of max_align_t is %zu (%#zx)\n", a, a);  void *p = malloc(123);  printf("The address obtained from malloc(123) is %#" PRIxPTR"\n",  (uintptr_t)p);  free(p); }
```

Possible output:
可能的輸出：

```c
Alignment of max_align_t is 16 (0x10) The address obtained from malloc(123) is 0x1fa67010
```

### References

- C23 standard (ISO/IEC 9899:2024):
C23 標準（ISO/IEC 9899:2024）：

- 7.19 Common definitions <stddef.h> (p: TBD)
7.19 通用定義 <stddef.h>（頁碼：待定）
7.19 通用定義 <stddef.h>（頁碼：待定）

- C17 standard (ISO/IEC 9899:2018):
C17 標準（ISO/IEC 9899:2018）：

- 7.19 Common definitions <stddef.h> (p: 211)
7.19 通用定義 <stddef.h>（頁碼：211）
7.19 通用定義 <stddef.h>（頁碼：211）

- C11 standard (ISO/IEC 9899:2011):
C11 標準（ISO/IEC 9899:2011）：

- 7.19 Common definitions <stddef.h> (p: 288)
7.19 通用定義 <stddef.h>（頁碼：288）
7.19 通用定義 <stddef.h>（頁碼：288）

### See also

C++ documentation for max_align_t

---
來源頁路徑：`en.cppreference.com/c/types/max_align_t.html`
